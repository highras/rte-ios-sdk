


#import <Foundation/Foundation.h>
@class FPNError;
NS_ASSUME_NONNULL_BEGIN

@protocol RTCAudioProtocol <NSObject>

@optional

//语音房间
//某人进入房间
-(void)rtcUserEnterVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time;
//某人离开房间
-(void)rtcUserExitVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time;
//房间关闭
-(void)rtcAudioRoomCloseNotificationWithRoomId:(int64_t)roomId;
//从房间被踢出
-(void)rtcKickOutVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId;
//被邀请进入房间
-(void)rtcInviteIntoVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId;
//被强制拉入房间结果
-(void)rtcForceInviteIntoVoiceRoomNotificationWithRoomId:(int64_t)roomId error:(FPNError * _Nullable)error;
//权限命令通知
-(void)rtcPushVoiceAdminCommand:(NSArray*)uids command:(int)type;
////语音房间自动翻译
-(void)rtcPushTranslateResultWithUserId:(int64_t)uid language:(NSString *)language text:(NSString *)text;


//语音单聊
//接收发送的语音请求
-(void)rtcReceiveP2PVoiceRequestWithUserId:(int64_t)userId;

/// 对应requestP2PVoiceWithUserId接口调用后  接收对方的反馈状态
/// @param userId 对端用户iD
/// @param eventId 1.取消p2p请求(自己调用cancelP2PVoiceWithCallId接口)  2.对端挂断   3.对端已经接请求 4.对端拒绝请求  5.对端无人接听
-(void)rtcReceiveP2PVoiceEventWithUserId:(int64_t)userId eventId:(int64_t)eventId;



//
@end



NS_ASSUME_NONNULL_END
