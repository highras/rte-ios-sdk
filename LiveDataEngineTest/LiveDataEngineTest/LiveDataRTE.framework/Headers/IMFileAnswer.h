//
//  IMFileAnswer.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/3/22.
//

#import <Foundation/Foundation.h>
#import "IMBaseAnswer.h"
NS_ASSUME_NONNULL_BEGIN

@interface IMFileAnswer : IMBaseAnswer
@property(nonatomic,strong)NSString * url;
@property(nonatomic,assign)int size;
@end

NS_ASSUME_NONNULL_END
