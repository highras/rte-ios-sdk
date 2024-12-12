//
//  RTMDelegate.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/2/10.
//

#import <Foundation/Foundation.h>
#import "LDEnum.h"
NS_ASSUME_NONNULL_BEGIN
@class RTMMessage;
@protocol RTMDelegate <NSObject>

-(void)rtmPushMessage:(LDEngine *)engine conversationType:(LDConversationType)conversationType message:(RTMMessage * _Nullable)message;
-(void)rtmPushCMDMessage:(LDEngine *)engine conversationType:(LDConversationType)conversationType message:(RTMMessage * _Nullable)message;
-(void)rtmPushFileMessage:(LDEngine *)engine conversationType:(LDConversationType)conversationType message:(RTMMessage * _Nullable)message;
-(void)rtmPushChatMessage:(LDEngine *)engine conversationType:(LDConversationType)conversationType message:(RTMMessage * _Nullable)message;
-(void)rtmPushKickoutRoom:(LDEngine *)engine roomId:(int64_t)roomId;


@end

NS_ASSUME_NONNULL_END

