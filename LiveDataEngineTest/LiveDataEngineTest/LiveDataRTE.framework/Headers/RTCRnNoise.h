//
//  RTVRNNoise.h
//  Rtm
//
//  Created by zsl on 2021/3/9.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCRnNoise : NSObject
-(short*)handleNoise:(short*)pcmArray channel:(int)channel;
+ (instancetype)sharedManager ;
@end

NS_ASSUME_NONNULL_END
