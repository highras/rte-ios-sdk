//
//  IMClient+Friend.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/3/22.
//

#import "IMClient.h"
#import "IMFriendApply.h"
#import "IMFriendRequest.h"
NS_ASSUME_NONNULL_BEGIN

@interface IMClient (Friend)



/// 获取自己的好友
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getFriendList:(int)timeout
             success:(void(^)(NSArray * _Nullable uidsArray))successCallback
                fail:(IMAnswerFailCallBack)failCallback;




/// 添加好友
/// - Parameters:
///   - userId: 用户id
///   - extra: 当对方为需要验证时，为添加留言，当对方为需要密码时，为密码
///   - attrs: 自定义属性
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)addFriend:(int64_t)userId
           extra:(NSString * _Nullable)extra
           attrs:(NSString * _Nullable)attrs
         timeout:(int)timeout
         success:(void(^)(void))successCallback
            fail:(IMAnswerFailCallBack)failCallback;




/// 回应添加好友请求
/// - Parameters:
///   - userId: 用户id
///   - agree: 是否同意
///   - attrs: 自定义属性
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)ackAddFriend:(int64_t)userId
              agree:(BOOL)agree
              attrs:(NSString * _Nullable)attrs
            timeout:(int)timeout
            success:(void(^)(void))successCallback
               fail:(IMAnswerFailCallBack)failCallback;




/// 删除好友
/// - Parameters:
///   - friendids: 好友id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)deleteFriends:(NSArray <NSNumber* >* _Nonnull)friendids
             timeout:(int)timeout
             success:(void(^)(void))successCallback
                fail:(IMAnswerFailCallBack)failCallback;




/// 获取别人请求加自己好友请求列表
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getFriendApplyList:(int)timeout
                  success:(void(^)(NSArray <IMFriendApply *> *))successCallback
                     fail:(IMAnswerFailCallBack)failCallback;




/// 获取自己发出的好友请求列表
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getFriendRequestList:(int)timeout
                    success:(void(^)(NSArray <IMFriendRequest*> *))successCallback
                     fail:(IMAnswerFailCallBack)failCallback;




/// 添加黑名单
/// - Parameters:
///   - friendids: 好友id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)addBlacklist:(NSArray <NSNumber* >* _Nonnull)friendids
            timeout:(int)timeout
            success:(void(^)(void))successCallback
               fail:(IMAnswerFailCallBack)failCallback;

   


/// 移除黑名单
/// - Parameters:
///   - friendids: 好友id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)deleteBlacklist:(NSArray <NSNumber* >* _Nonnull)friendids
               timeout:(int)timeout
               success:(void(^)(void))successCallback
                  fail:(IMAnswerFailCallBack)failCallback;




/// 获取自己添加的黑名单
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getBlacklist:(int)timeout
            success:(void(^)(NSArray * _Nullable uidsArray))successCallback
               fail:(IMAnswerFailCallBack)failCallback;

@end


NS_ASSUME_NONNULL_END
