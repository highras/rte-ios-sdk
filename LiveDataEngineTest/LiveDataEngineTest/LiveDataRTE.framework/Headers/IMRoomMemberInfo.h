//
//  IMRoomMemberInfo.h
//  LiveDataEngine
//
//  Created by zsl on 2023/5/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IMRoomMemberInfo : NSObject
@property(nonatomic,assign)int64_t uid;
@property(nonatomic,assign)int  role;    //(0群组、1管理员、2群众)
@property(nonatomic,assign)BOOL online;  //(1在线，0离线)
@end

NS_ASSUME_NONNULL_END
