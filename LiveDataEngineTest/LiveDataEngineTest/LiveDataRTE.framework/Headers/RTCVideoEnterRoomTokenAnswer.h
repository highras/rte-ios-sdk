//
//  RTMVideoEnterRoomTokenAnswer.h
//  Rtm
//
//  Created by zsl on 2021/5/21.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import "RTCBaseAnswer.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTCVideoEnterRoomTokenAnswer : RTCBaseAnswer
@property(nonatomic,strong)NSString * token;
@end

NS_ASSUME_NONNULL_END
