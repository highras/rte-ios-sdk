//
//  VideoViewController.m
//  SdkTest
//
//  Created by zsl on 2021/7/1.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import "VideoViewController.h"



@interface VideoViewController ()<LDBaseDelegate,RTCVideoProtocol>

@property(nonatomic,strong)LDEngine * mainEngine;

@property(nonatomic,assign)int64_t userId;
@property(nonatomic,assign)int64_t subscribeUserId;
@property(nonatomic,assign)int64_t roomId;
@property(nonatomic,assign)int64_t projectId;
@property(nonatomic,strong)NSString * projectEndpoint;
@property(nonatomic,strong)NSString * projectToken;

@end

@implementation VideoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.projectId = 0;
    self.projectEndpoint = nil;
    self.projectToken = @"";
    
    self.roomId = 666;
    self.userId = 666;
    self.subscribeUserId = 777;
    
    if (self.projectEndpoint == nil) {
        return;
    }
    
    
    [self _setUi];
    
    if (self.mainEngine == nil) {
        self.mainEngine = [LDEngine clientWithEndpoint:self.projectEndpoint
                                             projectId:self.projectId
                                                userId:self.userId
                                          baseDelegate:self
                                                config:nil];
        
        [self.mainEngine setRtcVideoDelegate:self];
    }

    
    [self _login];
    
}
-(void)_login{
    
    [self showLoadHudMessage:@"登录中..."];
    NSDictionary * tokenDic = [LDToken getToken:self.projectToken
                                            pid:[NSString stringWithFormat:@"%lld",self.projectId]
                                            uid:[NSString stringWithFormat:@"%lld",self.userId]];
    
    [self.mainEngine loginWithToken:[tokenDic objectForKey:@"token"]
                                 ts:[[tokenDic objectForKey:@"ts"] longLongValue]
                           language:@"en"
                          attribute:@{@"aaa":@"bbb"}
                            timeout:30
                            success:^{
        
        dispatch_async(dispatch_get_main_queue(), ^{
            
            [self showHudMessage:@"登录成功,请创建房间 或者 加入房间"];
           
        });
        
    } connectFail:^(FPNError * _Nullable error) {
        
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showHudMessage:[NSString stringWithFormat:@"登录失败 %@",error.ex]];
        });
        
    }];
    
}
#pragma mark client代理通知  必须要实现


-(void)_subscribeButtonClick{
    
    
    [self showLoadHudMessage:@"订阅中..."];
    
    NSMutableArray * uids = [NSMutableArray array];
    UIView * uidsItemView = [UIView new];
    uidsItemView.backgroundColor = [UIColor redColor];
    uidsItemView.frame = CGRectMake(200, 450, 120, 160);
    [self.view addSubview:uidsItemView];
    [uidsItemView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.equalTo(self.joinRoomButton);
        make.top.equalTo(self.subscribeUserButton.mas_bottom).offset(80);
        make.width.equalTo(@120);
        make.height.equalTo(@160);
    }];
    [uids addObject:uidsItemView];

    [self.mainEngine.rtcClient subscribeVideoWithRoomId:@(self.roomId)
                                                    uid:@[@(self.subscribeUserId)]
                                         containerViews:uids
                                                timeout:10
                                                success:^{
       
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showHudMessage:@"订阅成功" hideTime:2];
        });
        
        
    } fail:^(FPNError * _Nullable error) {
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showHudMessage:error.ex hideTime:2];
        });
        
        
        
    }];
    
}
-(void)_joinRoomButtonClick{
    
    [self showLoadHudMessage:@"加入中..."];
    [self.mainEngine.rtcClient enterVideoRoomWithRoomId:@(self.roomId)
                                      captureVideoLevel:LDCaptureVideoDefault
                                                timeout:10
                                                success:^(RTCVideoEnterRoomAnswer * _Nonnull answer) {
         
        dispatch_async(dispatch_get_main_queue(), ^{
            
            
            [self showHudMessage:@"加入成功" hideTime:2];
            [self.view addSubview:self.mainEngine.rtcClient.mySelfPreview];
            self.mainEngine.rtcClient.mySelfPreview.backgroundColor = [UIColor orangeColor];
            [self.mainEngine.rtcClient.mySelfPreview mas_makeConstraints:^(MASConstraintMaker *make) {
                make.left.equalTo(self.createRoomButton);
                make.top.equalTo(self.subscribeUserButton.mas_bottom).offset(80);
                make.width.equalTo(@120);
                make.height.equalTo(@160);
            }];
            
            [self.mainEngine.rtcClient updatePreviewFrame];
            [self.mainEngine.rtcClient openCamera];
            
        });
        
        
        
    } fail:^(FPNError * _Nullable error) {
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showHudMessage:error.ex hideTime:2];
        });
        
    }];
    
}
-(void)_createRoomButtonClick{
    
    [self showLoadHudMessage:@"创建中..."];
    [self.mainEngine.rtcClient createVideoRoomWithId:@(self.roomId)
                                   captureVideoLevel:LDCaptureVideoDefault
                                        enableRecord:NO
                                             timeout:10
                                             success:^(RTCVideoCreateRoomAnswer * _Nonnull answer) {
        
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showHudMessage:@"创建成功" hideTime:2];
        });
        
    } fail:^(FPNError * _Nullable error) {
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showHudMessage:error.ex hideTime:2];
        });
    }];
    
}
-(void)_audioButtonClick{
    
    if (self.mainEngine.rtcClient.isOpenVideoRoomVoicePlay) {
        [self.mainEngine.rtcClient closeVideoRoomVoicePlay];
        [self.mainEngine.rtcClient closeVideoRoomVoiceSpeak];
    }else{
        [self.mainEngine.rtcClient openVideoRoomVoicePlay];
        [self.mainEngine.rtcClient openVideoRoomVoiceSpeak];
    }
}
-(UIButton*)createRoomButton{
    if (_createRoomButton == nil) {
        _createRoomButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _createRoomButton.backgroundColor = [UIColor orangeColor];
        [_createRoomButton setTitle:@"1创建房间" forState:UIControlStateNormal];
        [_createRoomButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_createRoomButton addTarget:self action:@selector(_createRoomButtonClick) forControlEvents:UIControlEventTouchUpInside];
    }
    return _createRoomButton;
}
-(UIButton*)joinRoomButton{
    if (_joinRoomButton == nil) {
        _joinRoomButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _joinRoomButton.backgroundColor = [UIColor orangeColor];
        [_joinRoomButton setTitle:@"2加入房间" forState:UIControlStateNormal];
        [_joinRoomButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_joinRoomButton addTarget:self action:@selector(_joinRoomButtonClick) forControlEvents:UIControlEventTouchUpInside];
    }
    return _joinRoomButton;
}
-(UIButton*)subscribeUserButton{
    if (_subscribeUserButton == nil) {
        _subscribeUserButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _subscribeUserButton.backgroundColor = [UIColor orangeColor];
        [_subscribeUserButton setTitle:@"3订阅用户" forState:UIControlStateNormal];
        [_subscribeUserButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_subscribeUserButton addTarget:self action:@selector(_subscribeButtonClick) forControlEvents:UIControlEventTouchUpInside];
    }
    return _subscribeUserButton;
}
-(UIButton*)audioManagerButton{
    if (_audioManagerButton == nil) {
        _audioManagerButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _audioManagerButton.backgroundColor = [UIColor orangeColor];
        [_audioManagerButton setTitle:@"4音频控制" forState:UIControlStateNormal];
        [_audioManagerButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_audioManagerButton addTarget:self action:@selector(_audioButtonClick) forControlEvents:UIControlEventTouchUpInside];
    }
    return _audioManagerButton;
}

- (void)hiddenHud{
    [MBProgressHUD hideHUDForView:self.view animated:YES];
}
- (void)showLoadHudMessage:(NSString*)message{
    [self hiddenHud];
    MBProgressHUD * hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    hud.removeFromSuperViewOnHide = true;
    hud.bezelView.style = MBProgressHUDBackgroundStyleSolidColor;
    hud.bezelView.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.8];
    hud.contentColor = [UIColor whiteColor];
    hud.label.text = message;
    hud.label.textColor = [UIColor whiteColor];
}
- (void)showHudMessage:(NSString*)message hideTime:(int)hideTime{
    [self hiddenHud];
    MBProgressHUD * hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    hud.bezelView.style = MBProgressHUDBackgroundStyleSolidColor;
    hud.bezelView.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.8];
    hud.mode = MBProgressHUDModeText;
    hud.label.text = message;
    hud.label.textColor = [UIColor whiteColor];
    hud.label.numberOfLines = 0;
    hud.removeFromSuperViewOnHide = YES;
    [hud hideAnimated:YES afterDelay:hideTime];
}
@end
