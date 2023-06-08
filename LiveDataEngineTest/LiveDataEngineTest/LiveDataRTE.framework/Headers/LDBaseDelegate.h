//
//  LDBaseDelagate.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/2/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class FPNError,LDEngine;
@protocol LDBaseDelegate <NSObject>


@required

////自动重连只有在登录成功过后才会有效
////重连将要开始  根据返回值是否进行重连
-(BOOL)ldReloginWillStart:(LDEngine *)client reloginCount:(int)reloginCount;
//重连结果
-(void)ldReloginCompleted:(LDEngine *)client reloginCount:(int)reloginCount reloginResult:(BOOL)reloginResult error:(FPNError*)error;
//关闭连接通知  1飞行模式  2主动调用-(BOOL)closeConnect  3被踢或被挤下线  4ldReloginWillStart重连返回NO
-(void)ldConnectClose:(LDEngine *)client;
//被踢下线通知
-(void)ldKickout:(LDEngine *)client;

@end

NS_ASSUME_NONNULL_END
