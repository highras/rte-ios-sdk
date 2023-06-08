//
//  IMGetPushAttrsAnswer.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/4/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IMGetPushAttrsAnswer : NSObject
@property(nonatomic,strong)NSDictionary  <NSString*,NSArray*> * p2p;//@{ userId : @[mtype] }
@property(nonatomic,strong)NSDictionary  <NSString*,NSArray*> * group;//@{ groupId  : @[mtype] }
@end

NS_ASSUME_NONNULL_END
