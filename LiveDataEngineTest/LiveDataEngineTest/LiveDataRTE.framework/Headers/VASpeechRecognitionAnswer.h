//
//  VASpeechRecognitionAnswer.h
//  LiveDataEngine
//
//  Created by zsl on 2023/4/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VASpeechRecognitionAnswer : NSObject
@property(nonatomic,strong)NSString * lang;
@property(nonatomic,strong)NSString * text;
@end

NS_ASSUME_NONNULL_END
