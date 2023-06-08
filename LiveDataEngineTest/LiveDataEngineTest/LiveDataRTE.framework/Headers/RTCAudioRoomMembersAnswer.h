//
//  RTMVoiceRoomMembersAnswer.h
//  Rtm
//
//  Created by zsl on 2021/1/18.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import "RTCBaseAnswer.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTCAudioRoomMembersAnswer : RTCBaseAnswer
@property(nonatomic,strong)NSArray <NSNumber*>* userIds;
@property(nonatomic,strong)NSArray <NSNumber*>* administrators;
@property(nonatomic,assign)int64_t owner;
@end

NS_ASSUME_NONNULL_END
