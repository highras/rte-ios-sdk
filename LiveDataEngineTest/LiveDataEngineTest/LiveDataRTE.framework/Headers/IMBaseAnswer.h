//
//  IMBaseAnswer.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/3/23.
//

#import <Foundation/Foundation.h>
#import <Fpnn/FPNError.h>
NS_ASSUME_NONNULL_BEGIN

@interface IMBaseAnswer : NSObject
@property(nonatomic,strong)FPNError * error;//成功时 error 为 nil
@end

NS_ASSUME_NONNULL_END
