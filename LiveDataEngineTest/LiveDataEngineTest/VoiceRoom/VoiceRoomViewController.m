//
//  VoiceRoomViewController.m
//  LiveDataEngineTest
//
//  Created by zsl on 2023/6/29.
//

#import "VoiceRoomViewController.h"
#import "LDToken.h"
@interface VoiceRoomViewController ()<LDBaseDelegate,LDVoiceRoomDelegate>
@property(nonatomic,assign)int64_t roomId;
@property(nonatomic,assign)int64_t userId;
@property(nonatomic,assign)int64_t projectId;
@property(nonatomic,strong)NSString * projectEndpoint;
@property(nonatomic,strong)NSString * projectToken;
@end

@implementation VoiceRoomViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    
    self.projectId = 0;
    self.projectEndpoint = nil;
    self.projectToken = @"";
    
    self.roomId = 666;
    self.userId = 666;
    
    
    if(self.projectEndpoint == nil){
        return;
    }
    
    [self _setUi];
    
    self.engine = [LDEngine clientWithEndpoint:self.projectEndpoint
                                     projectId:self.projectId
                                        userId:self.userId
                                  baseDelegate:self
                                        config:nil];
    
    //语聊房支持后太聊天需要您配置 相关设置
    //  targets - capabilities - background modes  (勾选 audio,airplay,and picture in picture 和  background processing)
    //  info.plist 添加 required background modes  ( 1.App plays audio or streams audio/video using AirPlay.   2.App processes data in the background)
    

    //  默认开启
    //  self.engine.voiceRoomClient.backgroundSupport = YES;
    
    [self.engine setLDVoiceRoomDelegate:self];
    
    [self _login];
    
    
}
-(void)_login{
    
    [self showLoadHudMessage:@"登录中..."];
    NSDictionary * tokenDic = [LDToken getToken:self.projectToken
                                            pid:[NSString stringWithFormat:@"%lld",self.projectId]
                                            uid:[NSString stringWithFormat:@"%lld",self.userId]];
    
    [self.engine loginWithToken:[tokenDic objectForKey:@"token"]
                             ts:[[tokenDic objectForKey:@"ts"] longLongValue]
                       language:@"en"
                      attribute:@{@"aaa":@"bbb"}
                        timeout:30
                        success:^{
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showLoadHudMessage:@"登录成功,创建加入房间中..."];
            [self _createRoom];
        });
        
    } connectFail:^(FPNError * _Nullable error) {
        
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showHudMessage:[NSString stringWithFormat:@"登录失败 %@",error.ex]];
        });
        
    }];
    
}
-(void)_createRoom{
    
    
    [self.engine.voiceRoomClient createVoiceRoomWithId:@(self.roomId)
                                          enableRecord:NO
                                               timeout:10
                                               success:^(LDVoiceRoomCreateRoomAnswer * _Nonnull an) {
        
        
        dispatch_async(dispatch_get_main_queue(), ^{
            
            [self showHudMessage:@"创建加入房间成功 开始使用"];
            //加入房间后 默认开扬声器 关麦克风
            self.openPlay.selected = YES;
            self.openMicrophone.selected = NO;
            
        });
        
    } fail:^(FPNError * _Nullable error) {
        
        dispatch_async(dispatch_get_main_queue(), ^{
            if (error.code == 700004) {
                //创建房间失败 该房间已经存在
                [self _joinVioceRoom];
            }else{
                [self showHudMessage:[NSString stringWithFormat:@"创建房间失败 %@",error.ex]];
            }
            
        });
    }];
}
-(void)_joinVioceRoom{
    
    
    [self.engine.voiceRoomClient enterVoiceRoomWithRoomId:@(self.roomId)
                                                  timeout:10
                                                  success:^(LDVoiceRoomEnterRoomAnswer * _Nonnull an) {
        
        dispatch_async(dispatch_get_main_queue(), ^{
            
            self.openPlay.selected = YES;
            self.openMicrophone.selected = NO;
            [self showHudMessage:@"加入房间成功 开始使用"];
            
        });
        
    } fail:^(FPNError * _Nullable error) {
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showHudMessage:[NSString stringWithFormat:@"加入房间失败 %@",error.ex]];
        });
        
    }];
}
-(void)_openVoiceRoomMicrophone{
    
    self.openMicrophone.selected = !self.openMicrophone.selected;
    [self.engine.voiceRoomClient openVoiceRoomMicrophone:self.openMicrophone.selected];

}
-(void)_openVoiceRoomSpeaker{
    
    self.openPlay.selected = !self.openPlay.selected;
    
    [self.engine.voiceRoomClient openVoiceRoomSound:self.openPlay.selected];
    
}

-(void)_stopBGMClick{
    
    [self.engine.voiceRoomClient stopBGMMusic];
    [self _cancelGetTime];
    
}

-(void)_pauseBGMClick{
    [self.engine.voiceRoomClient pausePlayBGMMusic];
}

-(void)_resumeBGMClick{
    [self.engine.voiceRoomClient resumePlayBGMMusic];
}

-(void)_playBGMClick{
    
    
    NSString * path = [[NSBundle mainBundle] pathForResource:@"newBgm" ofType:@"mp3"];
    [self.engine.voiceRoomClient playBGMMusic:path loopCount:1 startTime:0 playStart:^(BOOL successPlay, int allTimeSecond) {
      
        
        NSLog(@"successPlay =  %d  time = %d",successPlay,allTimeSecond);
        dispatch_async(dispatch_get_main_queue(), ^{
            
            self.bgmPlaySlider.maximumValue = allTimeSecond;
            self.bgmPlaySlider.minimumValue = 0;
            
            self.volume_time.text = [NSString stringWithFormat:@"当前时间 %d 秒  当前音量 %d",0,(int)self.bgmVolumeSlider.value];
            [self _startGetTime];
            
        });
        
    } playFinish:^{
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showHudMessage:@"BGM播放完成"];
        });
        
    }];
}



-(void)_playSEBGMClick{
    
    NSLog(@"_playSEBGMClick");
    NSString * path = [[NSBundle mainBundle] pathForResource:@"zhangsheng" ofType:@"mp3"];
    [self.engine.voiceRoomClient playSoundEffect:999888  path:path loopCount:2 playStart:^(BOOL successPlay, int allTimeSecond) {
       
        NSLog(@"_playSoundEffectClick successPlay %d",successPlay);
        
    }];
    
//    [self.engine.voiceRoomClient setSoundEffectVolume:self.bgmVolumeSlider.value];
//    [self.engine.voiceRoomClient stopSoundEffect:999888];
//    [self.engine.voiceRoomClient pauseSoundEffect:999888];
//    [self.engine.voiceRoomClient resumeSoundEffect:999888];
//    [self.engine.voiceRoomClient stopAllSoundEffect];
    
}
-(void)_bgmSliderClick{
    
    NSLog(@"_bgmSliderClick");
    [self.engine.voiceRoomClient setBGMCurrentPlayTime:self.bgmPlaySlider.value];
    self.volume_time.text = [NSString stringWithFormat:@"当前时间 %d 秒  当前音量 %d",(int)self.bgmPlaySlider.value,(int)self.bgmVolumeSlider.value];
}

-(void)_bgmVolumeSliderClick{
    
    NSLog(@"_bgmVolumeSliderClick");
    [self.engine.voiceRoomClient setBGMVolume:self.bgmVolumeSlider.value];
    self.volume_time.text = [NSString stringWithFormat:@"当前时间 %d 秒  当前音量 %d",(int)self.bgmPlaySlider.value,(int)self.bgmVolumeSlider.value];
}
-(void)_startGetTime{
    
    if(self.speakTimer == nil){
        uint64_t sendInterval = 1 * NSEC_PER_SEC;
        dispatch_queue_t sendQueue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
        self.speakTimer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, sendQueue);
        dispatch_source_set_timer(self.speakTimer, dispatch_time(DISPATCH_TIME_NOW, 0), sendInterval, 0);
        dispatch_source_set_event_handler(self.speakTimer, ^(){
   
            [self _setCurrentPlayTime];
            
            
        });
        dispatch_resume(self.speakTimer);
    }
    
}
-(void)_cancelGetTime{
    if (self.speakTimer) {
        dispatch_cancel(self.speakTimer);
        self.speakTimer = nil;
    }
}
-(void)_setCurrentPlayTime{
    
    [self.engine.voiceRoomClient getBGMCurrentPlayTime:^(int64_t currentTime) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if(self.bgmPlaySlider.highlighted == NO){
                [self.bgmPlaySlider setValue:currentTime];
            }
            self.volume_time.text = [NSString stringWithFormat:@"当前时间 %lld 秒  当前音量 %d",currentTime,(int)self.bgmVolumeSlider.value];
        });
    }];
}

-(UIScrollView*)backSrcollView{
    if (_backSrcollView == nil) {
        _backSrcollView = [UIScrollView new];
        _backSrcollView.backgroundColor = [[UIColor whiteColor] colorWithAlphaComponent:1];
//        _backSrcollView.alpha = 0.8;
        _backSrcollView.alwaysBounceVertical = YES;
    }
    return _backSrcollView;
}
-(UIButton*)openMicrophone{
    if (_openMicrophone == nil) {
        _openMicrophone = [UIButton buttonWithType:UIButtonTypeCustom];
        [_openMicrophone setTitle:@"已打开麦克风" forState:UIControlStateSelected];
        [_openMicrophone setTitle:@"已关闭麦克风" forState:UIControlStateNormal];
        [_openMicrophone setTitleColor:[UIColor whiteColor] forState:UIControlStateSelected];
        [_openMicrophone setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_openMicrophone setBackgroundImage:[UIImage imageWithColor:RTM_BlueColor] forState:UIControlStateSelected];
        [_openMicrophone setBackgroundImage:[UIImage imageWithColor:[UIColor redColor]] forState:UIControlStateNormal];
        [_openMicrophone addTarget:self action:@selector(_openVoiceRoomMicrophone) forControlEvents:UIControlEventTouchUpInside];
        _openMicrophone.layer.masksToBounds = YES;
        _openMicrophone.layer.cornerRadius = 5;
    }
    return _openMicrophone;
}

-(UIButton*)openPlay{
    if (_openPlay == nil) {
        _openPlay = [UIButton buttonWithType:UIButtonTypeCustom];
        [_openPlay setTitle:@"已打开扬声器" forState:UIControlStateSelected];
        [_openPlay setTitle:@"已关闭扬声器" forState:UIControlStateNormal];
        [_openPlay setTitleColor:[UIColor whiteColor] forState:UIControlStateSelected];
        [_openPlay setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_openPlay setBackgroundImage:[UIImage imageWithColor:RTM_BlueColor] forState:UIControlStateSelected];
        [_openPlay setBackgroundImage:[UIImage imageWithColor:[UIColor redColor]] forState:UIControlStateNormal];
        [_openPlay addTarget:self action:@selector(_openVoiceRoomSpeaker) forControlEvents:UIControlEventTouchUpInside];
        _openPlay.selected = YES;
        _openPlay.layer.masksToBounds = YES;
        _openPlay.layer.cornerRadius = 5;
    }
    return _openPlay;
}
-(UIButton*)playBGM{
    if (_playBGM == nil) {
        _playBGM = [UIButton buttonWithType:UIButtonTypeCustom];
        [_playBGM setTitle:@"播放bgm" forState:UIControlStateNormal];
        [_playBGM setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
        [_playBGM setBackgroundImage:[UIImage imageWithColor:RTM_BlueColor] forState:UIControlStateNormal];
        [_playBGM addTarget:self action:@selector(_playBGMClick) forControlEvents:UIControlEventTouchUpInside];
        _playBGM.layer.masksToBounds = YES;
        _playBGM.layer.cornerRadius = 5;
    }
    return _playBGM;
}
-(UIButton*)stopBGM{
    if (_stopBGM == nil) {
        _stopBGM = [UIButton buttonWithType:UIButtonTypeCustom];
        [_stopBGM setTitle:@"停止bgm" forState:UIControlStateNormal];
        [_stopBGM setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
        [_stopBGM setBackgroundImage:[UIImage imageWithColor:RTM_BlueColor] forState:UIControlStateNormal];
        [_stopBGM addTarget:self action:@selector(_stopBGMClick) forControlEvents:UIControlEventTouchUpInside];
        _stopBGM.layer.masksToBounds = YES;
        _stopBGM.layer.cornerRadius = 5;
    }
    return _stopBGM;
}
-(UIButton*)pauseBGM{
    if (_pauseBGM == nil) {
        _pauseBGM = [UIButton buttonWithType:UIButtonTypeCustom];
        [_pauseBGM setTitle:@"暂停bgm" forState:UIControlStateNormal];
        [_pauseBGM setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
        [_pauseBGM setBackgroundImage:[UIImage imageWithColor:RTM_BlueColor] forState:UIControlStateNormal];
        [_pauseBGM addTarget:self action:@selector(_pauseBGMClick) forControlEvents:UIControlEventTouchUpInside];
        _pauseBGM.layer.masksToBounds = YES;
        _pauseBGM.layer.cornerRadius = 5;
    }
    return _pauseBGM;
}
-(UIButton*)resumeBGM{
    if (_resumeBGM == nil) {
        _resumeBGM = [UIButton buttonWithType:UIButtonTypeCustom];
        [_resumeBGM setTitle:@"恢复bgm" forState:UIControlStateNormal];
        [_resumeBGM setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
        [_resumeBGM setBackgroundImage:[UIImage imageWithColor:RTM_BlueColor] forState:UIControlStateNormal];
        [_resumeBGM addTarget:self action:@selector(_resumeBGMClick) forControlEvents:UIControlEventTouchUpInside];
        _resumeBGM.layer.masksToBounds = YES;
        _resumeBGM.layer.cornerRadius = 5;
    }
    return _resumeBGM;
}
-(UIButton*)playSoundEffect{
    if (_playSoundEffect == nil) {
        _playSoundEffect = [UIButton buttonWithType:UIButtonTypeCustom];
        [_playSoundEffect setTitle:@"播放音效" forState:UIControlStateNormal];
        [_playSoundEffect setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
        [_playSoundEffect setBackgroundImage:[UIImage imageWithColor:RTM_BlueColor] forState:UIControlStateNormal];
        [_playSoundEffect addTarget:self action:@selector(_playSEBGMClick) forControlEvents:UIControlEventTouchUpInside];
        _playSoundEffect.layer.masksToBounds = YES;
        _playSoundEffect.layer.cornerRadius = 5;
    }
    return _playSoundEffect;
}

-(UISlider*)bgmPlaySlider{
    if(_bgmPlaySlider == nil){
        _bgmPlaySlider = [[UISlider alloc] init];
        [_bgmPlaySlider addTarget:self action:@selector(_bgmSliderClick) forControlEvents:UIControlEventTouchUpInside];
        _bgmPlaySlider.minimumTrackTintColor = RTM_BlueColor;
        _bgmPlaySlider.maximumTrackTintColor = RTM_GreenColor;
        _bgmPlaySlider.thumbTintColor = [UIColor redColor];
        
    }
    return _bgmPlaySlider;
}
-(UISlider*)bgmVolumeSlider{
    if(_bgmVolumeSlider == nil){
        _bgmVolumeSlider = [[UISlider alloc] init];
        [_bgmVolumeSlider addTarget:self action:@selector(_bgmVolumeSliderClick) forControlEvents:UIControlEventTouchUpInside];
        _bgmVolumeSlider.maximumValue = 100;
        _bgmVolumeSlider.minimumValue = 0;
        _bgmVolumeSlider.value = 100;
        _bgmVolumeSlider.minimumTrackTintColor = RTM_BlueColor;
        _bgmVolumeSlider.maximumTrackTintColor = RTM_GreenColor;
        _bgmVolumeSlider.thumbTintColor = [UIColor redColor];
        
        
    }
    return _bgmVolumeSlider;
}
-(UILabel*)volume_time{
    if(_volume_time == nil){
        _volume_time = [UILabel new];
        _volume_time.backgroundColor = [UIColor redColor];
        _volume_time.font = [UIFont systemFontOfSize:15];
    }
    return _volume_time;
}
-(UILabel*)usersVolumeShow{
    if(_usersVolumeShow == nil){
        _usersVolumeShow = [UILabel new];
        _usersVolumeShow.backgroundColor = [UIColor redColor];
        _usersVolumeShow.font = [UIFont systemFontOfSize:15];
        _usersVolumeShow.numberOfLines = 0;
    }
    return _usersVolumeShow;
}
@end
