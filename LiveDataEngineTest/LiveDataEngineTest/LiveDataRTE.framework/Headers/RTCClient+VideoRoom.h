//
//  RTCClient+VideoRoom.h
//  LiveDataEngine
//
//  Created by zsl on 2023/5/23.
//
#import <UIKit/UIKit.h>
#import "RTCClient.h"
#import "RTCVideoCreateRoomAnswer.h"
#import "RTCVideoEnterRoomAnswer.h"
#import "RTCVideoEnterRoomTokenAnswer.h"
#import "RTCVideoRoomMembersAnswer.h"
#import "RTCVideoRoomMemberCount.h"
#import "RTCBaseAnswer.h"
#import "LDEnum.h"

#import "RTCAudioRoomMemberCount.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTCClient (VideoRoom)
//自己镜像view
@property(nonatomic,strong)UIView * mySelfPreview;

//更新自己镜像view frame
-(void)updatePreviewFrame;
//更新成员视频view frame
-(void)updateChildrenPreviewFrame;


- (CGFloat)getMaxExposureValue;
- (CGFloat)getMinExposureValue;
@property(nonatomic,assign)CGFloat exposure;//曝光 0为默认





//清晰度 默认 RTCRealTimeVideoDefault
@property(nonatomic,assign)LDCaptureVideoLevel captureVideoLevel;
//旋转摄像头
-(BOOL)switchCamera;

//摄像头开关
@property(nonatomic,assign,readonly)BOOL isOpenCamera;
-(BOOL)openCamera;
-(BOOL)closeCamera;

//麦克风开关
@property(nonatomic,assign,readonly)BOOL isOpenVideoRoomVoiceSpeak;
-(BOOL)openVideoRoomVoiceSpeak;
-(BOOL)closeVideoRoomVoiceSpeak;

//扬声器开关
@property(nonatomic,assign,readonly)BOOL isOpenVideoRoomVoicePlay;
-(BOOL)openVideoRoomVoicePlay;
-(BOOL)closeVideoRoomVoicePlay;


/// 创建房间
/// @param roomId 房间id int64
/// @param captureVideoLevel 采集等级
/// @param enableRecord 是否开启录制
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)createVideoRoomWithId:(NSNumber * _Nonnull)roomId
           captureVideoLevel:(LDCaptureVideoLevel)captureVideoLevel
                enableRecord:(BOOL)enableRecord
                     timeout:(int)timeout
                     success:(void(^)(RTCVideoCreateRoomAnswer * answer))successCallback
                        fail:(RTCAnswerFailCallBack)failCallback;


/// 加入视频房间
/// @param roomId 房间id int64
/// @param captureVideoLevel 采集等级
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)enterVideoRoomWithRoomId:(NSNumber * _Nonnull)roomId
              captureVideoLevel:(LDCaptureVideoLevel)captureVideoLevel
                        timeout:(int)timeout
                        success:(void(^)(RTCVideoEnterRoomAnswer * answer))successCallback
                           fail:(RTCAnswerFailCallBack)failCallback;


/// 离开语音房间
/// @param roomId 房间id int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)exitVideoRoomWithRoomId:(NSNumber * _Nonnull)roomId
                       timeout:(int)timeout
                       success:(void(^)(void))successCallback
                          fail:(RTCAnswerFailCallBack)failCallback;


/// 订阅
/// @param roomId 房间id int64
/// @param uids 用户id int64
/// @param containerViews 渲染背景View 对应uids
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)subscribeVideoWithRoomId:(NSNumber * _Nonnull)roomId
                            uid:(NSArray <NSNumber*> *)uids
                 containerViews:(NSArray<UIView*>*)containerViews
                        timeout:(int)timeout
                        success:(void(^)(void))successCallback
                           fail:(RTCAnswerFailCallBack)failCallback;
/// 取消订阅
/// @param roomId 房间id int64
/// @param uids 用户id int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)cancelSubscribeVideoWithRoomId:(NSNumber * _Nonnull)roomId
                                  uid:(NSArray <NSNumber*> *)uids
                              timeout:(int)timeout
                              success:(void(^)(void))successCallback
                                 fail:(RTCAnswerFailCallBack)failCallback;


/// 获取视频房间成员列表
/// @param roomId 房间id int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)getVideoRoomMembersWithId:(NSNumber * _Nonnull)roomId
                         timeout:(int)timeout
                         success:(void(^)(RTCVideoRoomMembersAnswer*))successCallback
                            fail:(RTCAnswerFailCallBack)failCallback;



/// 邀请用户加入视频房间(非强制，需要对端确认)
/// @param roomId 房间id int64
/// @param userIds [int64]
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)inviteUserIntoVideoRoomWithId:(NSNumber * _Nonnull)roomId
                             userIds:(NSArray<NSNumber*>*)userIds
                             timeout:(int)timeout
                             success:(void(^)(void))successCallback
                                fail:(RTCAnswerFailCallBack)failCallback;


/// 获取视频房间成员个数
/// @param roomId 房间id int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)getVideoRoomMemberCountWithId:(NSNumber * _Nonnull)roomId
                             timeout:(int)timeout
                             success:(void(^)(RTCAudioRoomMemberCount*))successCallback
                                fail:(RTCAnswerFailCallBack)failCallback;




/// 屏蔽房间某些人的语音
/// @param roomId 房间id int64
/// @param userIds [int64]
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)shieldUserVoiceInVideoRoomWithId:(NSNumber * _Nonnull)roomId
                                userIds:(NSArray<NSNumber*>*)userIds
                                timeout:(int)timeout
                                success:(void(^)(void))successCallback
                                   fail:(RTCAnswerFailCallBack)failCallback;




/// 解除屏蔽房间某些人的语音
/// @param roomId 房间id int64
/// @param userIds [int64]
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)removeShieldUserVoiceInVideoRoomWithId:(NSNumber * _Nonnull)roomId
                                      userIds:(NSArray<NSNumber*>*)userIds
                                      timeout:(int)timeout
                                      success:(void(^)(void))successCallback
                                         fail:(RTCAnswerFailCallBack)failCallback;





/// 下发给用户的管理员操作
/// @param roomId 房间id int64
/// @param userIds [int64]
/// @param commandType // command: 0 赋予管理员权限，1 剥夺管理员权限，2 禁止发送音频数据(不会转发)3 允许发送音频数据(会转发)4 禁止发送视频数据(不会转发)5 允许发送视频数据(会转发) 6 关闭他人麦克风(需调用closeVoiceSpeak)7 关闭他人摄像头(需调用closeCamera)
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)adminCommandVideoRoomWithId:(NSNumber * _Nonnull)roomId
                           userIds:(NSArray<NSNumber*>*)userIds
                           command:(int)commandType
                           timeout:(int)timeout
                           success:(void(^)(void))successCallback
                              fail:(RTCAnswerFailCallBack)failCallback;







@end

NS_ASSUME_NONNULL_END
