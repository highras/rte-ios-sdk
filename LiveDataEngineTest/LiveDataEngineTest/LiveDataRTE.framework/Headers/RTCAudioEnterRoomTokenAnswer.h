//
//  RTMVoiceEnterVoiceAnswer.h
//  Rtm
//
//  Created by zsl on 2021/1/5.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import "RTCBaseAnswer.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTCAudioEnterRoomTokenAnswer : RTCBaseAnswer
@property(nonatomic,strong)NSString * token;
@end

NS_ASSUME_NONNULL_END
