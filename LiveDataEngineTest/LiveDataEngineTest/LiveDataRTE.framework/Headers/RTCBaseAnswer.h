//
//  RTCBaseAnswer.h
//  LiveDataEngine
//
//  Created by zsl on 2023/5/26.
//

#import <Foundation/Foundation.h>
#import "FPNError.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTCBaseAnswer : NSObject
@property(nonatomic,strong)FPNError * error;//成功时 error 为 nil
@end

NS_ASSUME_NONNULL_END
