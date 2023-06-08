//
//  RTMClient.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/1/31.
//

#import <Foundation/Foundation.h>
#import "RTMSendAnswer.h"
#import "LDEngine.h"
NS_ASSUME_NONNULL_BEGIN



typedef void (^RTMAnswerSuccessCallBack)(NSDictionary * _Nullable data);
typedef void (^RTMAnswerFailCallBack)(FPNError * _Nullable error);



@interface RTMClient : NSObject


@end

NS_ASSUME_NONNULL_END

