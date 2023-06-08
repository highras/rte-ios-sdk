//
//  IMClient+Tools.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/3/22.
//

#import "IMClient.h"
#import "IMGetPushAttrsAnswer.h"
NS_ASSUME_NONNULL_BEGIN

@interface IMClient (Tools)


/// 添加推送设备
/// - Parameters:
///   - deviceToken: token
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)addDeviceWithDeviceToken:(NSString * _Nonnull)deviceToken
                        timeout:(int)timeout
                        success:(void(^)(void))successCallback
                           fail:(IMAnswerFailCallBack)failCallback;


/// 移除推送设备
/// - Parameters:
///   - deviceToken: token
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)removeDevice:(NSString * _Nonnull)deviceToken
            timeout:(int)timeout
            success:(void(^)(void))successCallback
               fail:(IMAnswerFailCallBack)failCallback;



/// 设置设备推送属性(注意此接口是设置个人或群组某个类型的type不推送的设置)
/// - Parameters:
///   - type:  type=0设置某个p2p不推送   type=1设置某个group不推送
///   - xid:   type=0对应userId        type=1对应groupId
///   - mTypes: 为空数组，则所有mtype均不推送;否则表示指定mtype不推送
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)addDevicePushOption:(int)type
                       xid:(int64_t)xid
                    mTypes:(NSArray <NSNumber*>* _Nonnull)mTypes
                   timeout:(int)timeout
                   success:(void(^)(void))successCallback
                      fail:(IMAnswerFailCallBack)failCallback;



/// 取消设备推送属性(和addDevicePushOptionWithType对应)
/// - Parameters:
///   - type:  type=0设置某个p2p不推送   type=1设置某个group不推送
///   - xid:   type=0对应userId        type=1对应groupId
///   - mTypes: 需要取消设置的messagetype数组(如果为空数组表示什么都不做)
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)removeDevicePushOption:(int)type
                          xid:(int64_t)xid
                       mTypes:(NSArray <NSNumber*>* _Nonnull)mTypes
                      timeout:(int)timeout
                      success:(void(^)(void))successCallback
                         fail:(IMAnswerFailCallBack)failCallback;



/// 获取设备推送属性(addDevicePushOptionWithType的结果)
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getDevicePushOption:(int)timeout
                   success:(void(^)(IMGetPushAttrsAnswer *answer))successCallback
                      fail:(IMAnswerFailCallBack)failCallback;
@end

NS_ASSUME_NONNULL_END
