//
//  VoiceRoomClient.h
//  LiveDataEngine
//
//  Created by zsl on 2023/6/21.
//


#import <Foundation/Foundation.h>
#import "RTMSendAnswer.h"
#import "LDEngine.h"
NS_ASSUME_NONNULL_BEGIN



typedef void (^LDVoiceRoomAnswerSuccessCallBack)(NSDictionary * _Nullable data);
typedef void (^LDVoiceRoomAnswerFailCallBack)(FPNError * _Nullable error);

@interface LDVoiceRoomClient : NSObject

//是否支持后台聊天  默认支持YES
@property(nonatomic,assign)BOOL backgroundSupport;
//targets - capabilities - background modes  (勾选 audio,airplay,and picture in picture 和  background processing)
//info.plist 添加 required background modes  ( 1.App plays audio or streams audio/video using AirPlay.   2.App processes data in the background)

@end

NS_ASSUME_NONNULL_END
