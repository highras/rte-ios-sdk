


#import <Foundation/Foundation.h>
#import "LDEnum.h"
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
//权限命令通知
-(void)rtcPushVoiceAdminCommand:(NSArray*)uids command:(int)type;
//return current volume
-(void)rtcMicrophoneVolume:(int)volume;
//房间用户当前音量反馈 包含自己
-(void)rtcRoomUsersVolume:(NSDictionary *)volumes;//userId : volume(范围0-100)

//自动翻译房间 翻译 + 识别结果
-(void)rtcPushTranslateResultWithUserId:(int64_t)uid
                                 roomId:(int64_t)roomId
                                startTs:(int64_t)startTs
                                  endTs:(int64_t)endTs
                                   text:(NSString *)text
                               language:(NSString *)language
                                   type:(LDTranslateAsrType)type;


//自动翻译房间 TTS 结果  data 为MP3格式
-(void)rtcPushTTSResultWithUserId:(int64_t)uid
                           roomId:(int64_t)roomId
                           taskId:(int64_t)taskId
                        timestamp:(int64_t)timestamp
                             data:(NSData *)data
                         language:(NSString *)language;



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
