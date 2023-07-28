//
//  IMDemoViewController+Delegate.m
//  LiveDataEngineTest
//
//  Created by ld_zsl on 2023/4/12.
//

#import "IMDemoViewController+Delegate.h"

@implementation IMDemoViewController (Delegate)

//================================================base=========================================================
////重连只有在登录成功过后才会有效
///
////重连将要开始  根据返回值是否进行重连
-(BOOL)ldReloginWillStart:(LDEngine *)client reloginCount:(int)reloginCount{
    NSLog(@"%s",__FUNCTION__);
    return YES;
}
//重连结果
-(void)ldReloginCompleted:(LDEngine *)client reloginCount:(int)reloginCount reloginResult:(BOOL)reloginResult error:(FPNError*)error{
    NSLog(@"%s",__FUNCTION__);
}
//关闭连接
-(void)ldConnectClose:(LDEngine *)client{
    NSLog(@"%s",__FUNCTION__);
}
//被踢下线
-(void)ldKickout:(LDEngine *)client{
    NSLog(@"%s",__FUNCTION__);
}



//================================================im  pushmsg ========================================================
-(void)imPushChatMessage:(LDEngine *)engine conversationType:(LDConversationType)conversationType message:(IMMessage * _Nullable)message{
    NSLog(@"%s  ===  %@",__FUNCTION__, message.ld_autoDescription);
}
-(void)imPushFileMessage:(LDEngine *)engine conversationType:(LDConversationType)conversationType message:(IMMessage * _Nullable)message{
    NSLog(@"%s  ===  %@",__FUNCTION__, message.ld_autoDescription);
}
-(void)imPushKickoutRoom:(int64_t)roomId{
    NSLog(@"%s  ===  %lld",__FUNCTION__, roomId);
}



//================================================im  friend ========================================================
-(void)imFriendChange:(int64_t)userId changeType:(int)changeType attrs:(NSString *)attrs{
    NSLog(@"%s  ===  %lld  ===  %d  ===  %@",__FUNCTION__, userId,changeType,attrs);
}
-(void)imFriendAddApply:(int64_t)userId message:(NSString *)message attrs:(NSString *)attrs{
    NSLog(@"%s  ===  %lld  ===  %@  === %@",__FUNCTION__,userId,message,attrs);
}
-(void)imFriendAgreeAddApply:(int64_t)userId attrs:(NSString * _Nullable)attrs{
    NSLog(@"%s  ===  %lld  ===  %@",__FUNCTION__, userId,attrs);
}
-(void)imFriendRefuseAddApply:(int64_t)userId attrs:(NSString * _Nullable)attrs{
    NSLog(@"%s  ===  %lld  ===  %@",__FUNCTION__, userId,attrs);
}



//================================================im  group ========================================================
-(void)imGroupChange:(int64_t)groupId changeType:(int)changeType attrs:(NSString*)attrs{
    NSLog(@"%s  ===  %lld  ===  %d  ===  %@",__FUNCTION__, groupId,changeType,attrs);
}

-(void)imGroupAddApply:(int64_t)groupId userId:(int64_t)userId  message:(NSString*)message attrs:(NSString*)attrs{
    NSLog(@"%s  ===  %lld  ===  %lld  === %@  ===  %@",__FUNCTION__, groupId,userId,message,attrs);
}
-(void)imGroupAgreeAddApply:(int64_t)groupId userId:(int64_t)userId attrs:(NSString*)attrs{
    NSLog(@"%s  ===  %lld  ===  %lld  ===  %@",__FUNCTION__, groupId,userId,attrs);
}
-(void)imGroupRefuseAddApply:(int64_t)groupId userId:(int64_t)userId attrs:(NSString*)attrs{
    NSLog(@"%s  ===  %lld  ===  %lld  ===  %@",__FUNCTION__, groupId,userId,attrs);
}

-(void)imGroupInvitedAddApply:(int64_t)groupId userId:(int64_t)userId message:(NSString*)message attrs:(NSString*)attrs{
    NSLog(@"%s  ===  %lld  ===  %lld === %@  ===  %@",__FUNCTION__, groupId,userId,message,attrs);
}
-(void)imGroupAgreeInvitedAddApply:(int64_t)groupId userId:(int64_t)userId attrs:(NSString*)attrs{
    NSLog(@"%s  ===  %lld  ===  %lld  ===  %@",__FUNCTION__, groupId,userId,attrs);
}
-(void)imGroupRefuseInvitedAddApply:(int64_t)groupId userId:(int64_t)userId attrs:(NSString*)attrs{
    NSLog(@"%s  ===  %lld  ===  %lld  ===  %@",__FUNCTION__, groupId,userId,attrs);
}

-(void)imGroupUserAdd:(int64_t)groupId userId:(int64_t)userId{
    NSLog(@"%s  ===  %lld  ===  %lld " ,__FUNCTION__, groupId,userId);
}
-(void)imGroupUserQuit:(int64_t)groupId userId:(int64_t)userId{
    NSLog(@"%s  ===  %lld  ===  %lld  ",__FUNCTION__, groupId,userId);
}

-(void)imGroupManagerAdd:(int64_t)groupId userIds:(NSArray <NSNumber*> *)userId{
    NSLog(@"%s  ===  %lld  ===  %@",__FUNCTION__, groupId,userId);
}
-(void)imGroupManagerDeleted:(int64_t)groupId userIds:(NSArray <NSNumber*> *)userId{
    NSLog(@"%s  ===  %lld  ===  %@ ",__FUNCTION__, groupId,userId);
}

-(void)imGroupOwnerChange:(int64_t)groupId oldOwner:(int64_t)oldOwner newOwner:(int64_t)newOwner{
    NSLog(@"%s  ===  %lld  ===  %lld  ===  %lld",__FUNCTION__, groupId,oldOwner,newOwner);
}



//================================================im  room ========================================================
-(void)imRoomChange:(int64_t)roomId changeType:(int)changeType attrs:(NSString*)attrs{
    NSLog(@"%s  ===  %lld  ===  %d  ===  %@",__FUNCTION__, roomId,changeType,attrs);
}

-(void)imRoomInvitedAddApply:(int64_t)roomId userId:(int64_t)userId message:(NSString*)message attrs:(NSString*)attrs{
    NSLog(@"%s  ===  %lld  ===  %lld === %@  ===  %@",__FUNCTION__, roomId,userId,message,attrs);
}
-(void)imRoomAgreeInvitedAddApply:(int64_t)roomId userId:(int64_t)userId attrs:(NSString*)attrs{
    NSLog(@"%s  ===  %lld  ===  %lld  ===  %@",__FUNCTION__, roomId,userId,attrs);
}
-(void)imRoomRefuseInvitedAddApply:(int64_t)roomId userId:(int64_t)userId attrs:(NSString*)attrs{
    NSLog(@"%s  ===  %lld  ===  %lld  ===  %@",__FUNCTION__, roomId,userId,attrs);
}

-(void)imRoomUserAdd:(int64_t)roomId userId:(int64_t)userId{
    NSLog(@"%s  ===  %lld  ===  %lld " ,__FUNCTION__, roomId,userId);
}
-(void)imRoomUserQuit:(int64_t)roomId userId:(int64_t)userId{
    NSLog(@"%s  ===  %lld  ===  %lld  ",__FUNCTION__, roomId,userId);
}

-(void)imRoomManagerAdd:(int64_t)roomId userIds:(NSArray <NSNumber*> *)userId{
    NSLog(@"%s  ===  %lld  ===  %@",__FUNCTION__, roomId,userId);
}
-(void)imRoomManagerDeleted:(int64_t)roomId userIds:(NSArray <NSNumber*> *)userId{
    NSLog(@"%s  ===  %lld  ===  %@ ",__FUNCTION__, roomId,userId);
}

-(void)imRoomOwnerChange:(int64_t)roomId oldOwner:(int64_t)oldOwner newOwner:(int64_t)newOwner{
    NSLog(@"%s  ===  %lld  ===  %lld  ===  %lld",__FUNCTION__, roomId,oldOwner,newOwner);
}
@end
