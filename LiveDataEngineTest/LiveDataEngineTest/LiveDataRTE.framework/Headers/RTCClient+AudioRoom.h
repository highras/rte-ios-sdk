//
//  RTCClient+AudioRoom.h
//  LiveDataEngine
//
//  Created by zsl on 2023/5/23.
//

#import "RTCClient.h"
#import "RTCAudioEnterRoomAnswer.h"
#import "RTCAudioCreateRoomAnswer.h"
#import "RTCAudioEnterRoomTokenAnswer.h"
#import "RTCAudioRoomMembersAnswer.h"
#import "RTCAudioRoomMemberCount.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTCClient (AudioRoom)

/// 创建语音房间 创建成功后会自动加入（有可能会加入失败）
/// @param roomId 房间id int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)createVoiceRoomWithId:(NSNumber * _Nonnull)roomId
                enableRecord:(BOOL)enableRecord
                     timeout:(int)timeout
                     success:(void(^)(RTCAudioCreateRoomAnswer * answer))successCallback
                        fail:(RTCAnswerFailCallBack)failCallback;




/// 进入语音房间成功后需要设置 voiceActiveRoom 设置当前活跃房间 多房间只会播放和发送当前活跃房间的语音
/// @param roomId 房间ID int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)enterVoiceRoomWithRoomId:(NSNumber * _Nonnull)roomId
                        timeout:(int)timeout
                        success:(void(^)(RTCAudioEnterRoomAnswer * answer))successCallback
                           fail:(RTCAnswerFailCallBack)failCallback;




//设置当前活跃房间  默认-1为没有设置活跃房间  可以同时加入多个房间(enterVoiceRoomWithRoomId) 只会播放接收和发送这个活跃房间的声音（不会持久化）  也可通过该接口设置-1  来暂时关闭实时语音功能
@property(nonatomic,assign,readonly)int64_t voiceActiveRoom;
-(BOOL)setCurrentVoiceActiveRoom:(int64_t)voiceActiveRoom;


//麦克风开关 默认关闭 断线重连重新进入房间后会恢复默认状态
-(BOOL)openMicrophone:(BOOL)open;
//声音开关 默认开启 断线重连重新进入房间后会恢复默认状态
-(BOOL)openSound:(BOOL)open;



//设置扬声器输出 默认扬声器 YES扬声器 NO听筒   接入耳机时设置无效
-(void)setAudioRouteToSpeaker:(BOOL)isSpeaker;
//---------------------------------------------------------------------------------------------------


/// 邀请用户加入房间(非强制，需要对端确认)
/// @param roomId 房间id int64
/// @param userIds [int64]
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)inviteUserIntoVoiceRoomWithId:(NSNumber * _Nonnull)roomId
                             userIds:(NSArray<NSNumber*>*)userIds
                             timeout:(int)timeout
                             success:(void(^)(void))successCallback
                                fail:(RTCAnswerFailCallBack)failCallback;





/// 离开语音房间
/// @param roomId 房间id int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)exitVoiceRoomWithId:(NSNumber * _Nonnull)roomId
                   timeout:(int)timeout
                   success:(void(^)(void))successCallback
                      fail:(RTCAnswerFailCallBack)failCallback;





/// 获取语音房间成员列表
/// @param roomId 房间id int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)getVoiceRoomMembersWithId:(NSNumber * _Nonnull)roomId
                         timeout:(int)timeout
                         success:(void(^)(RTCAudioRoomMembersAnswer*))successCallback
                            fail:(RTCAnswerFailCallBack)failCallback;





/// 获取语音房间成员个数
/// @param roomId 房间id int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)getVoiceRoomMemberCountWithId:(NSNumber * _Nonnull)roomId
                             timeout:(int)timeout
                             success:(void(^)(RTCAudioRoomMemberCount*))successCallback
                                fail:(RTCAnswerFailCallBack)failCallback;





/// 屏蔽房间某些人的语音
/// @param roomId 房间id int64
/// @param userIds [int64]
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)shieldUserInVoiceRoomWithId:(NSNumber * _Nonnull)roomId
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
-(void)removeShieldUserInVoiceRoomWithId:(NSNumber * _Nonnull)roomId
                                 userIds:(NSArray<NSNumber*>*)userIds
                                 timeout:(int)timeout
                                 success:(void(^)(void))successCallback
                                    fail:(RTCAnswerFailCallBack)failCallback;

@end

NS_ASSUME_NONNULL_END
