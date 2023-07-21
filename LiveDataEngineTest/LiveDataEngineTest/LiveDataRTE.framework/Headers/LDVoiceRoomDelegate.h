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

@end

NS_ASSUME_NONNULL_END
