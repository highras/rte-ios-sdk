//
//  LDVoiceRoomEnterRoomAnswer.h
//  LiveDataEngine
//
//  Created by zsl on 2023/6/21.
//

#import "RTCBaseAnswer.h"

NS_ASSUME_NONNULL_BEGIN

@interface LDVoiceRoomEnterRoomAnswer : RTCBaseAnswer
@property(nonatomic,assign)BOOL isOpenMicrophone;
@property(nonatomic,assign)int64_t owner;
@property(nonatomic,strong)NSArray * uids;
@property(nonatomic,strong)NSArray * administrators;
@end

NS_ASSUME_NONNULL_END
