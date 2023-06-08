//
//  RTCClient+AudioP2p.h
//  LiveDataEngine
//
//  Created by zsl on 2023/5/23.
//

#import "RTCClient.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTCClient (AudioP2p)
/// 发起p2p语音
/// @param userId 用户iD int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)requestP2PVoiceWithUserId:(NSNumber * _Nonnull)userId
                         timeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTCAnswerFailCallBack)failCallback;


/// 发起者取消p2p语音
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)cancelP2PVoiceWithTimeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTCAnswerFailCallBack)failCallback;


/// 关闭p2p语音
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)closeP2PVoiceWithTimeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTCAnswerFailCallBack)failCallback;


/// 接受p2p语音
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)acceptP2PVoiceWithTimeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTCAnswerFailCallBack)failCallback;


/// 拒绝p2p语音
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)refuseP2PVoiceWithTimeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTCAnswerFailCallBack)failCallback;
@end

NS_ASSUME_NONNULL_END
