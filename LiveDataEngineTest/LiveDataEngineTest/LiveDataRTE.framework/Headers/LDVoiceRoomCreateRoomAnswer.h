//
//  LDVoiceRoomAnswer.h
//  LiveDataEngine
//
//  Created by zsl on 2023/6/21.
//

#import "RTCBaseAnswer.h"

NS_ASSUME_NONNULL_BEGIN

@interface LDVoiceRoomCreateRoomAnswer : RTCBaseAnswer
@property(nonatomic,assign)int64_t roomId;
//@property(nonatomic,strong)NSString * token;
@end
NS_ASSUME_NONNULL_END
