//
//  VoiceRoomDelegate.h
//  LiveDataEngine
//
//  Created by zsl on 2023/6/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol LDVoiceRoomDelegate <NSObject>

//房间用户当前音量反馈 每秒反馈2次  (NSDictionary <NSNumber*,NSNumber*>*)volumes  对应  userId:volume(范围0-100)
-(void)voiceRoomUsersVolume:(NSDictionary <NSNumber*,NSNumber*>*)volumes;



//某人进入房间
-(void)voiceRoomUserEnterVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time;
//某人离开房间
-(void)voiceRoomUserExitVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time;
//房间关闭
-(void)voiceRoomAudioRoomCloseNotificationWithRoomId:(int64_t)roomId;
//从房间被踢出
-(void)voiceRoomKickOutVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId;
//权限命令通知
-(void)voiceRoomPushVoiceAdminCommand:(NSArray*)uids command:(int)type;


@end

NS_ASSUME_NONNULL_END
