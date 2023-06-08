//
//  IMGetRoomApplyList.h
//  LiveDataEngine
//
//  Created by zsl on 2023/5/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IMGetRoomApplyList : NSObject
@property(nonatomic,assign)int64_t fromUid;
@property(nonatomic,assign)int64_t status;
@property(nonatomic,assign)int64_t grantExtra;
@property(nonatomic,assign)int64_t createTime;
@property(nonatomic,assign)int64_t inviteUid;
@property(nonatomic,strong)NSString *  attrs;
@end

NS_ASSUME_NONNULL_END
