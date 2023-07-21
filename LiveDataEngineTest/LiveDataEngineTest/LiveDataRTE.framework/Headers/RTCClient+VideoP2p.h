//
//  RTCClient+VideoP2p.h
//  LiveDataEngine
//
//  Created by zsl on 2023/5/23.
//
#import <UIKit/UIKit.h>
#import "RTCClient.h"
#import "LDEnum.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTCClient (VideoP2p)
/// 发起p2p视频
/// @param userId 用户iD int64
/// @param captureVideoLevel 清晰度等级
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)requestP2PVideoWithUserId:(NSNumber * _Nonnull)userId
               captureVideoLevel:(LDCaptureVideoLevel)captureVideoLevel
                         timeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTCAnswerFailCallBack)failCallback;


/// 发起者取消p2p视频
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)cancelP2PVideoWithTimeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTCAnswerFailCallBack)failCallback;


/// 关闭p2p视频
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)closeP2PVideoWithTimeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTCAnswerFailCallBack)failCallback;


/// 接受p2p视频
/// @param timeout 请求超时时间 秒
/// @param captureVideoLevel 清晰度等级
/// @param containerView 对方视频显示容器视图
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)acceptP2PVideoWithTimeout:(int)timeout
               captureVideoLevel:(LDCaptureVideoLevel)captureVideoLevel
                   containerView:(UIView*)containerView
                         success:(void(^)(void))successCallback
                            fail:(RTCAnswerFailCallBack)failCallback;


/// 拒绝p2p视频
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)refuseP2PVideoWithTimeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTCAnswerFailCallBack)failCallback;
@end

NS_ASSUME_NONNULL_END
