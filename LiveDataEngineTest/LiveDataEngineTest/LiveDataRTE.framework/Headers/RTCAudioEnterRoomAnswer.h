//
//  RTCAudioEnterRoomAnswer.h
//  LiveDataEngine
//
//  Created by zsl on 2023/5/26.
//

#import "RTCBaseAnswer.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTCAudioEnterRoomAnswer : RTCBaseAnswer
@property(nonatomic,assign)BOOL isOpenMicrophone;
@property(nonatomic,assign)int64_t owner;
@property(nonatomic,strong)NSArray * uids;
@property(nonatomic,strong)NSArray * administrators;
@end

NS_ASSUME_NONNULL_END
