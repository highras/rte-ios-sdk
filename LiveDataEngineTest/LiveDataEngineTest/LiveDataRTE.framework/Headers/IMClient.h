//
//  IMClient.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/2/2.
//

#import <Foundation/Foundation.h>
#import "IMSendAnswer.h"
#import "LDEngine.h"
#import "FPNError.h"


NS_ASSUME_NONNULL_BEGIN

typedef void (^IMAnswerSuccessCallBack)(NSDictionary * _Nullable data);
typedef void (^IMAnswerFailCallBack)(FPNError * _Nullable error);

@interface IMClient : NSObject

@end

NS_ASSUME_NONNULL_END
