//
//  VAVoiceTranslateAnswer.h
//  LiveDataEngine
//
//  Created by zsl on 2023/4/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VAVoiceTranslateAnswer : NSObject
@property(nonatomic,strong)NSString * source;
@property(nonatomic,strong)NSString * target;
@property(nonatomic,strong)NSString * sourceText;
@property(nonatomic,strong)NSString * targetText;
@end

NS_ASSUME_NONNULL_END
