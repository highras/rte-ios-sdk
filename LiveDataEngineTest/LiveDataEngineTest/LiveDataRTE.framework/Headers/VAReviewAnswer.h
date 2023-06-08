//
//  VAReviewAnswer.h
//  LiveDataEngine
//
//  Created by zsl on 2023/4/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VAReviewAnswer : NSObject
@property(nonatomic,assign)int result;//是否通过 0通过   2不通过
@property(nonatomic,strong)NSArray * tags;//触发的分类，比如涉黄涉政等等，具体见图片审核分类
@end

NS_ASSUME_NONNULL_END
