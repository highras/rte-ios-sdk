//
//  VoiceRoomViewController+Delegate_UI.m
//  LiveDataEngineTest
//
//  Created by zsl on 2023/6/29.
//

#import "VoiceRoomViewController+Delegate_UI.h"

@implementation VoiceRoomViewController (Delegate_UI)

//================================================base=========================================================
////重连只有在登录成功过后才会有效
////重连将要开始  根据返回值是否进行重连
-(BOOL)ldReloginWillStart:(LDEngine *)client reloginCount:(int)reloginCount{
    NSLog(@"%s",__FUNCTION__);
    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        self.openMicrophone.selected = NO;
        self.openPlay.selected = NO;
        [self showLoadHudMessage:@"正在进行断线重连..."];
        
    });
    
    return YES;
    
}
//重连结果
-(void)ldReloginCompleted:(LDEngine *)client reloginCount:(int)reloginCount reloginResult:(BOOL)reloginResult error:(FPNError*)error{
    NSLog(@"ldReloginCompleted %d %d %@",reloginCount,reloginResult,error);
    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        if(reloginResult == YES){
            [self showHudMessage:@"重连成功~~~...请重新加入房间"];
        }else{
            [self showHudMessage:@"重连失败 稍等继续进行重连..."];
        }
        
    });
}
//关闭连接
-(void)ldConnectClose:(LDEngine *)client{
    NSLog(@"%s",__FUNCTION__);
}
//被踢下线
-(void)ldKickout:(LDEngine *)client{
    NSLog(@"%s",__FUNCTION__);
}
//用户音量反馈
-(void)voiceRoomUsersVolume:(NSDictionary<NSNumber *,NSNumber *> *)volumes{
    
    dispatch_async(dispatch_get_main_queue(), ^{     
        self.usersVolumeShow.text = [self dictionaryToJson:volumes];
    });
}
//================================================base=========================================================

- (NSString*)dictionaryToJson:(NSDictionary *)dic{
    if(dic == nil){
        return nil;
    }
    NSError *parseError = nil;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:dic options:NSJSONWritingPrettyPrinted error:&parseError];
    
    return [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
}




- (void)_setUi{
    
    self.view.backgroundColor = [UIColor whiteColor];
    CGFloat sw = [UIScreen mainScreen].bounds.size.width;
    
    [self.view addSubview:self.backSrcollView];
    [self.backSrcollView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.top.bottom.equalTo(self.view);
        make.width.equalTo(@(sw));
    }];
    
    [self.backSrcollView addSubview:self.openMicrophone];
    [self.openMicrophone mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.view).offset(15);
        make.top.equalTo(self.view).offset(80);
        make.width.equalTo(@((sw-45)/2));
        make.height.equalTo(@(40));
    }];
    
    
    [self.backSrcollView addSubview:self.openPlay];
    [self.openPlay mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.openMicrophone.mas_right).offset(15);
        make.top.equalTo(self.openMicrophone);
        make.width.height.equalTo(self.openMicrophone);
    }];
    
    
    [self.backSrcollView addSubview:self.playBGM];
    [self.playBGM mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.view).offset(15);
        make.top.equalTo(self.openPlay.mas_bottom).offset(45);
        make.width.equalTo(@((sw-45)/2));
        make.height.equalTo(@(40));
    }];
    
    [self.backSrcollView addSubview:self.stopBGM];
    [self.stopBGM mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.equalTo(self.openPlay);
        make.top.equalTo(self.openPlay.mas_bottom).offset(45);
        make.width.equalTo(@((sw-45)/2));
        make.height.equalTo(@(40));
    }];
    
    [self.backSrcollView addSubview:self.pauseBGM];
    [self.pauseBGM mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.view).offset(15);
        make.top.equalTo(self.stopBGM.mas_bottom).offset(45);
        make.width.equalTo(@((sw-45)/2));
        make.height.equalTo(@(40));
    }];
    
    [self.backSrcollView addSubview:self.resumeBGM];
    [self.resumeBGM mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.equalTo(self.stopBGM);
        make.top.equalTo(self.stopBGM.mas_bottom).offset(45);
        make.width.equalTo(@((sw-45)/2));
        make.height.equalTo(@(40));
        
    }];
    
    [self.backSrcollView addSubview:self.playSoundEffect];
    [self.playSoundEffect mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.view).offset(15);
        make.top.equalTo(self.resumeBGM.mas_bottom).offset(45);
        make.width.equalTo(@((sw-45)/2));
        make.height.equalTo(@(40));
       
    }];
    
    
    
    [self.backSrcollView addSubview:self.bgmVolumeSlider];
    [self.bgmVolumeSlider mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.backSrcollView).offset(15);
        make.top.equalTo(self.playSoundEffect.mas_bottom).offset(35);
        make.width.equalTo(@(sw-30));
        make.height.equalTo(@(20));
        
    }];
    
    
    [self.backSrcollView addSubview:self.volume_time];
    [self.volume_time mas_makeConstraints:^(MASConstraintMaker *make) {
       
        make.centerX.equalTo(self.view);
        make.top.equalTo(self.bgmVolumeSlider.mas_bottom).offset(20);
        
    }];
    
    [self.backSrcollView addSubview:self.bgmPlaySlider];
    [self.bgmPlaySlider mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.backSrcollView).offset(15);
        make.top.equalTo(self.bgmVolumeSlider.mas_bottom).offset(65);
        make.height.equalTo(@(20));
        make.width.equalTo(@(sw-30));

    }];
    
    [self.backSrcollView addSubview:self.usersVolumeShow];
    [self.usersVolumeShow mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.backSrcollView).offset(15);
        make.right.equalTo(self.resumeBGM);
        make.top.equalTo(self.bgmPlaySlider.mas_bottom).offset(25);
//        make.width.equalTo(@((RTM_ScreenWidth-45)/2));
//        make.height.equalTo(@(40));
//        make.width.equalTo(@(RTM_ScreenWidth-30));
        make.bottom.equalTo(self.backSrcollView).offset(-100);
    }];
    
}

- (void)hiddenHud{
    [MBProgressHUD hideHUDForView:self.view animated:YES];
}
- (void)showHudMessage:(NSString*)message{
    
    [self hiddenHud];
    MBProgressHUD * hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    hud.bezelView.style = MBProgressHUDBackgroundStyleSolidColor;
    hud.bezelView.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.8];
    hud.mode = MBProgressHUDModeText;
    hud.label.text = message;
    hud.label.textColor = [UIColor whiteColor];
    hud.label.numberOfLines = 0;
    hud.removeFromSuperViewOnHide = YES;
    [hud hideAnimated:YES afterDelay:2];
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
@end
