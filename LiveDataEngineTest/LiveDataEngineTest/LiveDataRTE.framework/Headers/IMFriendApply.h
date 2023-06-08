//
//  IMFriendApply.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/4/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IMFriendApply : NSObject
@property(nonatomic,assign)int64_t fromUid;
@property(nonatomic,assign)int64_t status;
@property(nonatomic,strong)NSString * grantExtra;
@property(nonatomic,assign)int64_t createTime;
@property(nonatomic,strong)NSString * attrs;
@end

NS_ASSUME_NONNULL_END
