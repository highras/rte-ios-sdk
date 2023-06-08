//
//  IMGetGroupApplyList.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/3/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IMGetGroupApplyList : NSObject
@property(nonatomic,assign)int64_t fromUid;
@property(nonatomic,assign)int64_t status;
@property(nonatomic,assign)int64_t grantExtra;
@property(nonatomic,assign)int64_t createTime;
@property(nonatomic,assign)int64_t inviteUid;
@property(nonatomic,strong)NSString *  attrs;
@end

NS_ASSUME_NONNULL_END
