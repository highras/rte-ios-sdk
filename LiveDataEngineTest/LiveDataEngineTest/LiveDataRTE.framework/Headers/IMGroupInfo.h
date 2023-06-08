//
//  IMGroupInfo.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/4/6.
//

#import <Foundation/Foundation.h>
#import "LDEnum.h"
NS_ASSUME_NONNULL_BEGIN

@interface IMGroupInfo : NSObject
@property(nonatomic,assign)int64_t groupId;
@property(nonatomic,strong)NSString * name;
@property(nonatomic,strong)NSString * portraitUrl;
@property(nonatomic,strong)NSString * profile;
@property(nonatomic,strong)NSString * attrs;
@property(nonatomic,assign)LDApplyGrantType applyGrant;
@property(nonatomic,assign)LDInviteGrantType inviteGrant;
@property(nonatomic,assign)int64_t ownerUid;
@property(nonatomic,strong)NSArray <NSNumber *> * managerUids;
@end

NS_ASSUME_NONNULL_END


