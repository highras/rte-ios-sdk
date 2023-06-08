//
//  RTCClient.h
//  LiveDataEngine
//
//  Created by zsl on 2023/5/23.
//

#import <Foundation/Foundation.h>
#import "LDEngine.h"

NS_ASSUME_NONNULL_BEGIN


typedef void (^RTCAnswerSuccessCallBack)(NSDictionary * _Nullable data);
typedef void (^RTCAnswerFailCallBack)(FPNError * _Nullable error);

@interface RTCClient : NSObject



@end

NS_ASSUME_NONNULL_END
