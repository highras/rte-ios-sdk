//
//  IMGetRoomRequestList.h
//  LiveDataEngine
//
//  Created by zsl on 2023/5/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IMGetRoomRequestList : NSObject
@property(nonatomic,assign)int64_t targetXid;
@property(nonatomic,assign)int64_t createTime;
@property(nonatomic,strong)NSString * attrs;
@end

NS_ASSUME_NONNULL_END
