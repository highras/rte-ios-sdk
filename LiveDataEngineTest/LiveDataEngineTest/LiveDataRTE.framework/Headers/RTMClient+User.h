//
//  RTMClient+User.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/2/2.
//

#import "RTMClient.h"
#import "RTMInfoAnswer.h"
#import "RTMAttriAnswer.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTMClient (User)


/// 设置用户信息
/// - Parameters:
///   - openInfo: 公开信息
///   - privteInfo: 私有信息
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)setUserInfoWithOpenInfo:(NSString * _Nullable)openInfo
                    privteinfo:(NSString * _Nullable)privteInfo
                       timeout:(int)timeout
                       success:(void(^)(void))successCallback
                          fail:(RTMAnswerFailCallBack)failCallback;


/// 获取用户信息
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getUserInfoWithTimeout:(int)timeout
                      success:(void(^)(RTMInfoAnswer * _Nullable info))successCallback
                         fail:(RTMAnswerFailCallBack)failCallback;



/// 获取用户公开信息
/// - Parameters:
///   - userIds: 用户id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getUserOpenInfo:(NSArray <NSNumber* > * _Nullable)userIds
               timeout:(int)timeout
               success:(void(^)(RTMAttriAnswer * _Nullable info))successCallback
                  fail:(RTMAnswerFailCallBack)failCallback;



/// 获取在线用户
/// - Parameters:
///   - userIds: 用户id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getOnlineUsers:(NSArray <NSNumber* >* _Nonnull)userIds
              timeout:(int)timeout
              success:(void(^)(NSArray * _Nullable uidArray))successCallback
                 fail:(RTMAnswerFailCallBack)failCallback;
@end

NS_ASSUME_NONNULL_END

