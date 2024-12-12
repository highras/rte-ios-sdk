//
//  RTMClient+Tools.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/2/2.
//

#import "RTMClient.h"
#import "RTMGetPushAttrsAnswer.h"
#import "RTMInfoAnswer.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTMClient (Tools)


/// 添加推送设备
/// - Parameters:
///   - deviceToken: token
///   - tag 一个rtm项目对应多个推送项目时，所使用的推送项目的 tag
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)addDevice:(NSString * _Nonnull)appType
     deviceToken:(NSString * _Nonnull)deviceToken
             tag:(NSString * _Nullable)tag
         timeout:(int)timeout
         success:(void(^)(void))successCallback
            fail:(RTMAnswerFailCallBack)failCallback;




/// 移除推送设备
/// - Parameters:
///   - deviceToken: token
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)removeDevice:(NSString * _Nonnull)deviceToken
            timeout:(int)timeout
            success:(void(^)(void))successCallback
               fail:(RTMAnswerFailCallBack)failCallback;




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
                      fail:(RTMAnswerFailCallBack)failCallback;




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
                         fail:(RTMAnswerFailCallBack)failCallback;




/// 获取设备推送属性(addDevicePushOptionWithType的结果)
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getDevicePushOption:(int)timeout
                   success:(void(^)(RTMGetPushAttrsAnswer *answer))successCallback
                      fail:(RTMAnswerFailCallBack)failCallback;




/// 设置存储的数据信息
/// - Parameters:
///   - key: 数据信息key
///   - value: 数据信息value
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)dataSet:(NSString * _Nonnull)key
         value:(NSString * _Nonnull)value
       timeout:(int)timeout
       success:(void(^)(void))successCallback
          fail:(RTMAnswerFailCallBack)failCallback;




/// 获取存储的数据信息
/// - Parameters:
///   - key: 数据信息key
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)dataGet:(NSString * _Nullable)key
       timeout:(int)timeout
       success:(void(^)(RTMInfoAnswer * _Nullable valueInfo))successCallback
          fail:(RTMAnswerFailCallBack)failCallback;





/// 删除存储的数据信息
/// - Parameters:
///   - key: 数据信息key
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)dataDelete:(NSString * _Nonnull)key
          timeout:(int)timeout
          success:(void(^)(void))successCallback
             fail:(RTMAnswerFailCallBack)failCallback;

@end

NS_ASSUME_NONNULL_END
