//
//  IMRoomInfo.h
//  LiveDataEngine
//
//  Created by zsl on 2023/5/16.
//

#import <Foundation/Foundation.h>
#import "LDEnum.h"
NS_ASSUME_NONNULL_BEGIN

@interface IMRoomInfo : NSObject

@property(nonatomic,assign)int64_t roomId;
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
