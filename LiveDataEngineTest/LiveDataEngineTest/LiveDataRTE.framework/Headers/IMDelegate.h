//
//  IMDelegate.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/2/10.
//

#import <Foundation/Foundation.h>
#import "LDEnum.h"
NS_ASSUME_NONNULL_BEGIN
@class IMMessage;
@protocol IMDelegate <NSObject>

-(void)imPushChatMessage:(LDEngine *)engine conversationType:(LDConversationType)conversationType message:(IMMessage * _Nullable)message;
-(void)imPushFileMessage:(LDEngine *)engine conversationType:(LDConversationType)conversationType message:(IMMessage * _Nullable)message;


// changeType 0加入 1退出 2群组解散 3被踢
-(void)imGroupChange:(int64_t)groupId changeType:(int)changeType attrs:(NSString*)attrs;


-(void)imGroupAddApply:(int64_t)groupId userId:(int64_t)userId message:(NSString*)message attrs:(NSString*)attrs;
-(void)imGroupAgreeAddApply:(int64_t)groupId userId:(int64_t)userId attrs:(NSString*)attrs;
-(void)imGroupRefuseAddApply:(int64_t)groupId userId:(int64_t)userId attrs:(NSString*)attrs;

-(void)imGroupInvitedAddApply:(int64_t)groupId userId:(int64_t)userId message:(NSString*)message attrs:(NSString*)attrs;
-(void)imGroupAgreeInvitedAddApply:(int64_t)groupId userId:(int64_t)userId attrs:(NSString*)attrs;
-(void)imGroupRefuseInvitedAddApply:(int64_t)groupId userId:(int64_t)userId attrs:(NSString*)attrs;

-(void)imGroupUserAdd:(int64_t)groupId userId:(int64_t)userId;
-(void)imGroupUserQuit:(int64_t)groupId userId:(int64_t)userId;

-(void)imGroupManagerAdd:(int64_t)groupId userIds:(NSArray <NSNumber*> *)userId;
-(void)imGroupManagerDeleted:(int64_t)groupId userIds:(NSArray <NSNumber*> *)userId;

-(void)imGroupOwnerChange:(int64_t)groupId oldOwner:(int64_t)oldOwner newOwner:(int64_t)newOwner;



// changeType 0加入 1退出 2群组解散 3被踢
-(void)imRoomChange:(int64_t)roomId changeType:(int)changeType attrs:(NSString*)attrs;


-(void)imRoomInvitedAddApply:(int64_t)roomId userId:(int64_t)userId message:(NSString*)message attrs:(NSString*)attrs;
-(void)imRoomAgreeInvitedAddApply:(int64_t)roomId userId:(int64_t)userId attrs:(NSString*)attrs;
-(void)imRoomRefuseInvitedAddApply:(int64_t)roomId userId:(int64_t)userId attrs:(NSString*)attrs;

-(void)imRoomUserAdd:(int64_t)roomId userId:(int64_t)userId;
-(void)imRoomUserQuit:(int64_t)roomId userId:(int64_t)userId;

-(void)imRoomManagerAdd:(int64_t)roomId userIds:(NSArray <NSNumber*> *)userId;
-(void)imRoomManagerDeleted:(int64_t)roomId userIds:(NSArray <NSNumber*> *)userId;

-(void)imRoomOwnerChange:(int64_t)roomId oldOwner:(int64_t)oldOwner newOwner:(int64_t)newOwner;




// changeType  0添加、1删除
-(void)imFriendChange:(int64_t)userId changeType:(int)changeType attrs:(NSString * _Nullable)attrs;
-(void)imFriendAddApply:(int64_t)userId message:(NSString* )message attrs:(NSString * _Nullable)attrs;
-(void)imFriendAgreeAddApply:(int64_t)userId attrs:(NSString * _Nullable)attrs;
-(void)imFriendRefuseAddApply:(int64_t)userId attrs:(NSString * _Nullable)attrs;


@end

NS_ASSUME_NONNULL_END
