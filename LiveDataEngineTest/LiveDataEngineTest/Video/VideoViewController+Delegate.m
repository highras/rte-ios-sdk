//
//  VideoViewController+Delegate.m
//  LiveDataEngineTest
//
//  Created by 张世良 on 2023/8/4.
//

#import "VideoViewController+Delegate.h"

@implementation VideoViewController (Delegate)

//================================================base=========================================================
////重连只有在登录成功过后才会有效
////重连将要开始  根据返回值是否进行重连
-(BOOL)ldReloginWillStart:(LDEngine *)client reloginCount:(int)reloginCount{
    NSLog(@"%s",__FUNCTION__);
    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        [self showLoadHudMessage:@"正在进行断线重连..."];
        
    });
    
    return YES;
    
}
//重连结果
-(void)ldReloginCompleted:(LDEngine *)client reloginCount:(int)reloginCount reloginResult:(BOOL)reloginResult error:(FPNError*)error{
    NSLog(@"ldReloginCompleted %d %d %@",reloginCount,reloginResult,error);
    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        if(reloginResult == YES){
            [self showHudMessage:@"重连成功~~~...请重新加入房间，订阅"];
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


//某人进入房间
-(void)rtcUserEnterVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time{
    NSLog(@"%s",__FUNCTION__);
}
//某人离开房间
-(void)rtcUserExitVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time{
    NSLog(@"%s",__FUNCTION__);
}
//房间关闭
-(void)rtcVideoRoomCloseNotificationWithRoomId:(int64_t)roomId{
    NSLog(@"%s",__FUNCTION__);
}
//从房间被踢出
-(void)rtcKickOutVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId{
    NSLog(@"%s",__FUNCTION__);
}
//被邀请进入房间
-(void)rtcInviteIntoVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId{
    NSLog(@"%s",__FUNCTION__);
}
//权限命令通知
-(void)rtcPushVideoAdminCommand:(NSArray*)uids command:(int)type{
    NSLog(@"%s",__FUNCTION__);
}

//================================================base=========================================================

- (void)_setUi{
    
    [self.view addSubview:self.createRoomButton];
    [self.createRoomButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.view).offset(40);
        make.top.equalTo(self.view).offset(88);
        make.width.equalTo(@100);
        make.height.equalTo(@40);
    }];
    
    
    [self.view addSubview:self.joinRoomButton];
    [self.joinRoomButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.equalTo(self.view).offset(-40);
        make.top.equalTo(self.view).offset(88);
        make.width.equalTo(@100);
        make.height.equalTo(@40);
    }];
    
    [self.view addSubview:self.subscribeUserButton];
    [self.subscribeUserButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.createRoomButton);
        make.top.equalTo(self.createRoomButton.mas_bottom).offset(50);
        make.width.equalTo(@100);
        make.height.equalTo(@40);
    }];
    
    
    [self.view addSubview:self.audioManagerButton];
    [self.audioManagerButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.equalTo(self.joinRoomButton);
        make.top.equalTo(self.createRoomButton.mas_bottom).offset(50);
        make.width.equalTo(@100);
        make.height.equalTo(@40);
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
