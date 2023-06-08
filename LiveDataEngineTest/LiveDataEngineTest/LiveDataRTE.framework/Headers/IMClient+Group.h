//
//  IMClient+Group.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/3/22.
//

#import "IMClient.h"
#import "IMGetGroupApplyList.h"
#import "IMGetGroupInviteList.h"
#import "IMGetGroupRequestList.h"
#import "IMGroupInfo.h"
#import "IMGroupMemberInfo.h"
#import "IMMemberCountAnswer.h"
#import "LDEnum.h"
NS_ASSUME_NONNULL_BEGIN

@interface IMClient (Group)




/// 加入群组
/// - Parameters:
///   - groupId: 群id
///   - extra: 验证内容或密码
///   - attrs: 自定义属性
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)joinGroup:(NSNumber * _Nonnull)groupId
           extra:(NSString * _Nullable)extra
           attrs:(NSString * _Nullable)attrs
         timeout:(int)timeout
         success:(void(^)(void))successCallback
            fail:(IMAnswerFailCallBack)failCallback;






/// 回应加入群组
/// - Parameters:
///   - groupId: 群id
///   - fromId: 申请者uid
///   - agree: 是否同意
///   - attrs: 自定义属性
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)ackjoinGroup:(NSNumber * _Nonnull)groupId
               from:(NSNumber * _Nullable)fromId
              agree:(BOOL)agree
              attrs:(NSString * _Nullable)attrs
            timeout:(int)timeout
            success:(void(^)(void))successCallback
               fail:(IMAnswerFailCallBack)failCallback;






/// 邀请入群
/// - Parameters:
///   - groupId: 群id
///   - uids: 被邀请人id
///   - extra: 验证内容
///   - attrs: 自定义属性
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)inviteGroup:(NSNumber * _Nonnull)groupId
              uids:(NSArray <NSNumber*> * _Nullable)uids
             extra:(NSString * _Nullable)extra
             attrs:(NSString * _Nullable)attrs
            timeout:(int)timeout
            success:(void(^)(void))successCallback
              fail:(IMAnswerFailCallBack)failCallback;





/// 回应邀请入群
/// - Parameters:
///   - groupId: 群id
///   - fromId: 申请者id
///   - agree: 是否同意
///   - attrs: 自定义属性
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)ackinviteGroup:(NSNumber * _Nonnull)groupId
                 from:(NSNumber * _Nullable)fromId
                agree:(BOOL)agree
                attrs:(NSString * _Nullable)attrs
              timeout:(int)timeout
              success:(void(^)(void))successCallback
                 fail:(IMAnswerFailCallBack)failCallback;





/// 获取自己加入的群组
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getGroupList:(int)timeout
            success:(void(^)(NSArray * _Nullable groupArray))successCallback
               fail:(IMAnswerFailCallBack)failCallback;





/// 离开群组
/// - Parameters:
///   - groupId: 群id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)leaveGroup:(NSNumber * _Nonnull)groupId
          timeout:(int)timeout
          success:(void(^)(void))successCallback
             fail:(IMAnswerFailCallBack)failCallback;





/// 解散群组
/// - Parameters:
///   - groupId: 群id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)dismissGroup:(NSNumber * _Nonnull)groupId
            timeout:(int)timeout
            success:(void(^)(void))successCallback
               fail:(IMAnswerFailCallBack)failCallback;





/// 获取申请加入群组请求列表
/// - Parameters:
///   - groupId: 群id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getGroupApplyList:(NSNumber * _Nonnull)groupId
                 timeout:(int)timeout
                 success:(void(^)(NSArray <IMGetGroupApplyList * > * array))successCallback
                    fail:(IMAnswerFailCallBack)failCallback;





/// 获取邀请加入群组请求列表
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getGroupInviteList:(int)timeout
                  success:(void(^)(NSArray <IMGetGroupInviteList * > * array))successCallback
                     fail:(IMAnswerFailCallBack)failCallback;





/// 获取自己发出的申请加入群组请求列表
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getGroupRequestList:(int)timeout
                   success:(void(^)(NSArray <IMGetGroupRequestList * > * array))successCallback
                      fail:(IMAnswerFailCallBack)failCallback;





/// 获取群组信息
/// - Parameters:
///   - groupIds: 群id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getGroupsInfo:(NSArray <NSNumber *> *)groupIds
             timeout:(int)timeout
             success:(void(^)(NSArray <IMGroupInfo*> *))successCallback
                fail:(IMAnswerFailCallBack)failCallback;




/// 获取群组成员
/// - Parameters:
///   - groupId: 群id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getGroupMembers:(NSNumber * _Nonnull)groupId
               timeout:(int)timeout
               success:(void(^)(NSArray <IMGroupMemberInfo*> * array))successCallback
                  fail:(IMAnswerFailCallBack)failCallback;




/// 获取群组成员数量
/// - Parameters:
///   - groupId: 群id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getGroupMemberCount:(NSNumber * _Nonnull)groupId
                   timeout:(int)timeout
                   success:(void(^)(IMMemberCountAnswer * _Nullable memberCountAnswer))successCallback
                      fail:(IMAnswerFailCallBack)failCallback;




/// 移除群成员
/// - Parameters:
///   - groupId: 群id
///   - uids: 用户id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)removeGroupMembers:(NSNumber * _Nonnull)groupId
                     uids:(NSArray <NSNumber*>*)uids
                  timeout:(int)timeout
                  success:(void(^)(void))successCallback
                      fail:(IMAnswerFailCallBack)failCallback;



/// 转移群主
/// - Parameters:
///   - groupId: 群id
///   - toUid: 新群主id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)transferGroup:(NSNumber * _Nonnull)groupId
               toUid:(int64_t)toUid
             timeout:(int)timeout
             success:(void(^)(void))successCallback
                fail:(IMAnswerFailCallBack)failCallback;




/// 添加群管理员
/// - Parameters:
///   - groupId: 群id
///   - uids: 用户id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)addGroupManagers:(NSNumber * _Nonnull)groupId
                   uids:(NSArray <NSNumber*>*)uids
                timeout:(int)timeout
                success:(void(^)(void))successCallback
                   fail:(IMAnswerFailCallBack)failCallback;




/// 移除群管理员
/// - Parameters:
///   - groupId: 群id
///   - uids: 用户id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)removeGroupManagers:(NSNumber * _Nonnull)groupId
                      uids:(NSArray <NSNumber*>*)uids
                   timeout:(int)timeout
                   success:(void(^)(void))successCallback
                      fail:(IMAnswerFailCallBack)failCallback;





@end

NS_ASSUME_NONNULL_END

