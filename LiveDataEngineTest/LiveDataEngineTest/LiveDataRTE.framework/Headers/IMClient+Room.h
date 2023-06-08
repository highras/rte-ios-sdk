//
//  IMClient+Room.h
//  LiveDataEngine
//
//  Created by zsl on 2023/5/15.
//

#import "IMClient.h"
#import "IMRoomInfo.h"
#import "LDEnum.h"
#import "IMRoomMemberInfo.h"
#import "IMGetRoomApplyList.h"
#import "IMGetRoomInviteList.h"
#import "IMGetRoomRequestList.h"
#import "IMMemberCountAnswer.h"
NS_ASSUME_NONNULL_BEGIN

@interface IMClient (Room)



/// 获取房间信息
/// - Parameters:
///   - roomIds: 房间id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getRoomsInfo:(NSArray <NSNumber *> *)roomIds
            timeout:(int)timeout
            success:(void(^)(NSArray <IMRoomInfo*> *))successCallback
               fail:(IMAnswerFailCallBack)failCallback;




/// 加入房间
/// - Parameters:
///   - roomId: 房间id
///   - extra: 验证内容或密码
///   - attrs: 自定义属性
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)joinRoom:(NSNumber * _Nonnull)roomId
          extra:(NSString * _Nullable)extra
          attrs:(NSString * _Nullable)attrs
        timeout:(int)timeout
        success:(void(^)(void))successCallback
           fail:(IMAnswerFailCallBack)failCallback;




/// 邀请入房间
/// - Parameters:
///   - roomId: 房间id
///   - uids: 被邀请人id
///   - extra: 验证内容
///   - attrs: 自定义属性
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)inviteRoom:(NSNumber * _Nonnull)roomId
             uids:(NSArray <NSNumber*> * _Nullable)uids
            extra:(NSString * _Nullable)extra
            attrs:(NSString * _Nullable)attrs
          timeout:(int)timeout
          success:(void(^)(void))successCallback
             fail:(IMAnswerFailCallBack)failCallback;




/// 回应邀请入房间
/// - Parameters:
///   - roomId: 房间id
///   - fromId: 申请者id
///   - agree: 是否同意
///   - attrs: 自定义属性
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)ackinviteRoom:(NSNumber * _Nonnull)roomId
                 from:(NSNumber * _Nullable)fromId
                agree:(BOOL)agree
                attrs:(NSString * _Nullable)attrs
              timeout:(int)timeout
              success:(void(^)(void))successCallback
                 fail:(IMAnswerFailCallBack)failCallback;





/// 获取自己加入的房间
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getRoomList:(int)timeout
           success:(void(^)(NSArray * _Nullable roomArray))successCallback
              fail:(IMAnswerFailCallBack)failCallback;





/// 解散房间
/// - Parameters:
///   - roomId: id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)dismissRoom:(NSNumber * _Nonnull)roomId
            timeout:(int)timeout
            success:(void(^)(void))successCallback
               fail:(IMAnswerFailCallBack)failCallback;




/// 移除成员
/// - Parameters:
///   - roomId: id
///   - uids: 用户id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)removeRoomMembers:(NSNumber * _Nonnull)roomId
                    uids:(NSArray <NSNumber*>*)uids
                 timeout:(int)timeout
                 success:(void(^)(void))successCallback
                    fail:(IMAnswerFailCallBack)failCallback;




/// 离开房间
/// - Parameters:
///   - roomId: id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)leaveRoom:(NSNumber * _Nonnull)roomId
         timeout:(int)timeout
         success:(void(^)(void))successCallback
            fail:(IMAnswerFailCallBack)failCallback;





/// 转移房主
/// - Parameters:
///   - roomId: id
///   - toUid: 新房主id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)transferRoom:(NSNumber * _Nonnull)roomId
              toUid:(int64_t)toUid
            timeout:(int)timeout
            success:(void(^)(void))successCallback
               fail:(IMAnswerFailCallBack)failCallback;





/// 添加管理员
/// - Parameters:
///   - roomId: id
///   - uids: 用户id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)addRoomManagers:(NSNumber * _Nonnull)roomId
                  uids:(NSArray <NSNumber*>*)uids
               timeout:(int)timeout
               success:(void(^)(void))successCallback
                  fail:(IMAnswerFailCallBack)failCallback;




/// 移除管理员
/// - Parameters:
///   - roomId: id
///   - uids: 用户id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)removeRoomManagers:(NSNumber * _Nonnull)roomId
                     uids:(NSArray <NSNumber*>*)uids
                  timeout:(int)timeout
                  success:(void(^)(void))successCallback
                     fail:(IMAnswerFailCallBack)failCallback;





/// 获取房间成员
/// - Parameters:
///   - roomId: id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getRoomMembers:(NSNumber * _Nonnull)roomId
              timeout:(int)timeout
              success:(void(^)(NSArray <IMRoomMemberInfo*> * array))successCallback
                 fail:(IMAnswerFailCallBack)failCallback;





/// 获取房间成员数量
/// - Parameters:
///   - roomId: id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getRoomMemberCount:(NSNumber * _Nonnull)roomId
                  timeout:(int)timeout
                  success:(void(^)(IMMemberCountAnswer * _Nullable memberCountAnswer))successCallback
                     fail:(IMAnswerFailCallBack)failCallback;






/// 获取邀请加入房间请求列表
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getRoomInviteList:(int)timeout
                 success:(void(^)(NSArray <IMGetRoomInviteList * > * array))successCallback
                    fail:(IMAnswerFailCallBack)failCallback;





@end

NS_ASSUME_NONNULL_END
