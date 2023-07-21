//
//  RTMVideoEnterRoomAnswer.h
//  Rtm
//
//  Created by zsl on 2021/5/21.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import "RTCBaseAnswer.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTCVideoEnterRoomAnswer : RTCBaseAnswer
@property(nonatomic,assign)BOOL isOpenMicrophone;
@property(nonatomic,assign)int64_t owner;
@property(nonatomic,strong)NSArray * uids;
@property(nonatomic,strong)NSArray * administrators;
@end

NS_ASSUME_NONNULL_END
