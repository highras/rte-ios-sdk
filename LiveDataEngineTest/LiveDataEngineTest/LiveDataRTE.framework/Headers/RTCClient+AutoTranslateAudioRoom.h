//
//  RTCClient+AutoTranslateAudioRoom.h
//  LiveDataEngine
//
//  Created by zsl on 2023/6/25.
//

#import "RTCClient.h"
#import "RTCAudioEnterRoomAnswer.h"
#import "RTCAudioCreateRoomAnswer.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTCClient (AutoTranslateAudioRoom)
/// 创建自动翻译语音房间 创建成功后会自动加入（有可能会加入失败）
/// @param language 自己的语言 必传
/// @param roomId 房间id int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)createAutoTranslateVoiceRoomWithId:(NSNumber * _Nonnull)roomId
                                 language:(NSString * _Nonnull)language
                             enableRecord:(BOOL)enableRecord
                                  timeout:(int)timeout
                                  success:(void(^)(RTCAudioCreateRoomAnswer * answer))successCallback
                                     fail:(RTCAnswerFailCallBack)failCallback;


/// 进入语音房间成功后需要设置 voiceActiveRoom 设置当前活跃房间 多房间只会播放和发送当前活跃房间的语音
/// @param roomId 房间ID int64
/// @param language 自己的语言 必传
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)enterAutoTranslateVoiceRoomWithRoomId:(NSNumber * _Nonnull)roomId
                                    language:(NSString * _Nonnull)language
                                     timeout:(int)timeout
                                     success:(void(^)(RTCAudioEnterRoomAnswer * answer))successCallback
                                        fail:(RTCAnswerFailCallBack)failCallback;



//mp3 转单声道 + 固定采样率   16000 or 48000
+(NSData*)getPcmData:(NSString*)mp3Path sampleRate:(int)sampleRate;

@end

NS_ASSUME_NONNULL_END
