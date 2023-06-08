//
//  LDEngine+Push.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/2/3.
//

#import "LDEngine.h"
#import "LDAnswer.h"
NS_ASSUME_NONNULL_BEGIN

@interface LDEngine (Push)
-(LDAnswer*)handlePush:(NSString*)method data:(NSDictionary*)data;
@end

NS_ASSUME_NONNULL_END
