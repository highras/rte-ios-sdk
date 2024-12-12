//
//  LDVoiceRoomClient+VoiceRoom.h
//  LiveDataEngine
//
//  Created by zsl on 2023/6/21.
//

#import "LDVoiceRoomClient.h"
#import "LDVoiceRoomCreateRoomAnswer.h"
#import "LDVoiceRoomEnterRoomAnswer.h"
NS_ASSUME_NONNULL_BEGIN

@interface LDVoiceRoomClient (VoiceRoom)



//麦克风开关 默认关闭 断线重连重新进入房间后会恢复默认状态
-(BOOL)openVoiceRoomMicrophone:(BOOL)open;
//声音开关 默认开启 断线重连重新进入房间后会恢复默认状态
-(BOOL)openVoiceRoomSound:(BOOL)open;
//发送上传数据开关 默认开启
-(void)setOpenUploadVoiceData:(BOOL)open;
//设置扬声器输出 默认扬声器 YES扬声器 NO听筒   接入耳机时设置无效
-(void)setAudioRouteToSpeaker:(BOOL)isSpeaker;
/// 播放音效
/// - Parameters:
///   - soundId: 音效id
///   - mp3Path: 路径
///   - loopCount: 循环次数  -1为无限循环
///   - playStart: 播放结果
-(void)playSoundEffect:(int64_t)soundId
                  path:(NSString*)mp3Path
             loopCount:(int64_t)loopCount
             playStart:(void(^)(BOOL successPlay,int allTimeSecond))playStart;

//停止播放所有音效
-(void)stopAllSoundEffect;
//停止播放音效
-(void)stopSoundEffect:(int64_t)soundId;
//暂停播放音效
-(void)pauseSoundEffect:(int64_t)soundId;
//恢复播放音效
-(void)resumeSoundEffect:(int64_t)soundId;
//设置音效音量 默认100 范围0-100
-(void)setSoundEffectVolume:(int)volume;




/// 播放背景音乐
/// - Parameters:
///   - mp3Path: 路径
///   - loopCount: 循环次数  -1为无限循环
///   - startTime: 起始播放时间 单位秒
///   - playStart: 每一次循环都会触发
///   - playFinish:每一次循环触发
-(void)playBGMMusic:(NSString*)mp3Path
          loopCount:(int64_t)loopCount
          startTime:(int)startTime
          playStart:(void(^)(BOOL successPlay,int allTimeSecond))playStart
         playFinish:(void(^)(void))playFinish;


//停止播放背景音乐
-(void)stopBGMMusic;
//暂停播放背景音乐
-(void)pausePlayBGMMusic;
//恢复播放背景音乐
-(void)resumePlayBGMMusic;
//设置播放进度    单位 秒
-(void)setBGMCurrentPlayTime:(int)time;
//获取当前播放进度 单位 秒
-(void)getBGMCurrentPlayTime:(void(^)(int64_t currentTime))currentPlayTime;
//设置背景音乐音量 默认100 范围0-100
-(void)setBGMVolume:(int)volume;


/// 创建语音房间 创建成功后会自动加入（有可能会加入失败）
/// @param roomId 房间id int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)createVoiceRoomWithId:(NSNumber * _Nonnull)roomId
                enableRecord:(BOOL)enableRecord
                     timeout:(int)timeout
                     success:(void(^)(LDVoiceRoomCreateRoomAnswer * answer))successCallback
                        fail:(LDVoiceRoomAnswerFailCallBack)failCallback;



/// 进入语音房间
/// @param roomId 房间ID int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)enterVoiceRoomWithRoomId:(NSNumber * _Nonnull)roomId
                        timeout:(int)timeout
                        success:(void(^)(LDVoiceRoomEnterRoomAnswer * answer))successCallback
                           fail:(LDVoiceRoomAnswerFailCallBack)failCallback;



/// 离开语音房间
/// @param roomId 房间id int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)exitVoiceRoomWithId:(NSNumber * _Nonnull)roomId
                   timeout:(int)timeout
                   success:(void(^)(void))successCallback
                      fail:(LDVoiceRoomAnswerFailCallBack)failCallback;

@end

NS_ASSUME_NONNULL_END
