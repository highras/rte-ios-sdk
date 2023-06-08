//
//  IMTranslatedInfo.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/3/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IMTranslatedInfo : NSObject
@property(nonatomic,copy)NSString * source;
@property(nonatomic,copy)NSString * target;
@property(nonatomic,copy)NSString * sourceText;
@property(nonatomic,copy)NSString * targetText;
@end

NS_ASSUME_NONNULL_END
