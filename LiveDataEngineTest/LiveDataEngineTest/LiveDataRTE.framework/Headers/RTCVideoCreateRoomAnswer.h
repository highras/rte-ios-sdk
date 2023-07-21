//
//  RTMVideoCreateRoomAnswer.h
//  Rtm
//
//  Created by zsl on 2021/5/21.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import "RTCBaseAnswer.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTCVideoCreateRoomAnswer : RTCBaseAnswer
@property(nonatomic,assign)int64_t roomId;
@end

NS_ASSUME_NONNULL_END
