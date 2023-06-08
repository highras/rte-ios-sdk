//
//  ValueAddedServices.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/2/8.
//

#import <Foundation/Foundation.h>
#import "RTMSendAnswer.h"
#import "LDEngine.h"
#import "RTMClient.h"
NS_ASSUME_NONNULL_BEGIN



typedef void (^VAAnswerSuccessCallBack)(NSDictionary * _Nullable data);
typedef void (^VAAnswerFailCallBack)(FPNError * _Nullable error);

@interface VAClient : NSObject

@end

NS_ASSUME_NONNULL_END
