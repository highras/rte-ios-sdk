//
//  RTMClient+Friend.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/2/2.
//

#import "RTMClient.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTMClient (Friend)
/// 添加好友
/// - Parameters:
///   - friendids: 好友id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)addFriends:(NSArray <NSNumber* >* _Nonnull)friendids
          timeout:(int)timeout
          success:(void(^)(void))successCallback
             fail:(RTMAnswerFailCallBack)failCallback;



/// 删除好友
/// - Parameters:
///   - friendids: 好友id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)deleteFriends:(NSArray <NSNumber* >* _Nonnull)friendids
             timeout:(int)timeout
             success:(void(^)(void))successCallback
                fail:(RTMAnswerFailCallBack)failCallback;



/// 获取自己的好友
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getFriends:(int)timeout
          success:(void(^)(NSArray * _Nullable uidsArray))successCallback
             fail:(RTMAnswerFailCallBack)failCallback;



/// 添加黑名单
/// - Parameters:
///   - friendids: 好友id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)addBlacklist:(NSArray <NSNumber* >* _Nonnull)friendids
            timeout:(int)timeout
            success:(void(^)(void))successCallback
               fail:(RTMAnswerFailCallBack)failCallback;

   


/// 删除黑名单
/// - Parameters:
///   - friendids: 好友id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)deleteBlacklist:(NSArray <NSNumber* >* _Nonnull)friendids
               timeout:(int)timeout
               success:(void(^)(void))successCallback
                  fail:(RTMAnswerFailCallBack)failCallback;




/// 获取黑名单
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getBlacklist:(int)timeout
            success:(void(^)(NSArray * _Nullable uidsArray))successCallback
               fail:(RTMAnswerFailCallBack)failCallback;
@end

NS_ASSUME_NONNULL_END

