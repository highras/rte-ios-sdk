//
//  VATranslatedInfo.h
//  LiveDataEngine
//
//  Created by zsl on 2023/4/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VATranslatedInfo : NSObject
@property(nonatomic,copy)NSString * source;
@property(nonatomic,copy)NSString * target;
@property(nonatomic,copy)NSString * sourceText;
@property(nonatomic,copy)NSString * targetText;
@end

NS_ASSUME_NONNULL_END
