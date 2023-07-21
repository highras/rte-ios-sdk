//
//  RTCVideoProtocol.h
//  LiveDataEngine
//
//  Created by zsl on 2023/6/2.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@protocol RTCVideoProtocol <NSObject>

@optional


//视频房间
//某人进入房间
-(void)rtcUserEnterVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time;
//某人离开房间
-(void)rtcUserExitVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time;
//房间关闭
-(void)rtcVideoRoomCloseNotificationWithRoomId:(int64_t)roomId;
//从房间被踢出
-(void)rtcKickOutVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId;
//被邀请进入房间
-(void)rtcInviteIntoVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId;
//权限命令通知
-(void)rtcPushVideoAdminCommand:(NSArray*)uids command:(int)type;




//视频单聊
//接收发送的语音请求
-(void)rtcReceiveP2PVideoRequestWithUserId:(int64_t)userId;



/// 对应requestP2PVideoWithUserId接口调用后  接收对方的反馈状态
/// @param userId 对端用户iD
/// @param eventId 1.取消p2p请求(自己调用cancelP2PVoiceWithCallId接口)  2.对端挂断   3.对端已经接请求(返回UIView 对面图像渲染背景，其他eventId返回nil)  4.对端拒绝请求  5.对端无人接听
-(UIView * _Nullable)rtcReceiveP2PVideoEventWithUserId:(int64_t)userId eventId:(int64_t)eventId;

@end

NS_ASSUME_NONNULL_END
