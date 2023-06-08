//
//  IMGetGroupInviteList.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/3/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IMGetGroupInviteList : NSObject
@property(nonatomic,assign)int64_t targetXid;
@property(nonatomic,assign)int64_t createTime;
@property(nonatomic,assign)int64_t fromUid;
@property(nonatomic,strong)NSString * attrs;

@end

NS_ASSUME_NONNULL_END

