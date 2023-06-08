//
//  VAClient+Services.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/2/8.
//

#import "VAClient.h"
#import "VATranslatedInfo.h"
#import "VASpeechRecognitionAnswer.h"
#import "VAVoiceTranslateAnswer.h"
#import "VATextReviewAnswer.h"
#import "VAReviewAnswer.h"
NS_ASSUME_NONNULL_BEGIN



@interface VAClient (Services)


/// 设置当前用户需要的翻译语言
/// - Parameters:
///   - language: 语言
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)setUserLanguage:(NSString * _Nonnull)language
               timeout:(int)timeout
               success:(void(^)(void))successCallback
                  fail:(VAAnswerFailCallBack)failCallback;





/// 翻译, 返回翻译后的字符串及 经过翻译系统检测的 语言类型（调用此接口需在管理系统启用翻译系统）
/// - Parameters:
///   - translateText: 翻译文本
///   - originalLanguage: 原语言类型
///   - targetLanguage: 目标语言类型
///   - type: 可选值为chat或mail。如未指定，则默认使用chat
///   - profanity: 敏感词过滤   默认：off censor: 用星号(*)替换敏感词
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)translateText:(NSString * _Nonnull)translateText
    originalLanguage:(NSString * _Nullable)originalLanguage
      targetLanguage:(NSString * _Nonnull)targetLanguage
                type:(NSString * _Nullable)type
           profanity:(NSString * _Nullable)profanity
             timeout:(int)timeout
             success:(void(^)(VATranslatedInfo * _Nullable translatedInfo))successCallback
                fail:(VAAnswerFailCallBack)failCallback;





/// 语音转文字（调用此接口需在管理系统启用语音识别系统）调用这个接口的超时时间得加大到120s
/// - Parameters:
///   - audioUrl: 音频数据 audioUrl audioData二选一 同时传audioData优先
///   - audioData: 音频数据 audioUrl audioData二选一 同时传audioData优先
///   - lang: 语言
///   - codec: 编解码 传空 默认AMR_WB
///   - srate: 采样率 传空 默认为16000
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)speechToText:(NSString * _Nullable)audioUrl
          audioData:(NSData * _Nullable)audioData
               lang:(NSString *_Nonnull)lang
              codec:(NSString *_Nullable)codec
              srate:(int32_t)srate
            timeout:(int)timeout
            success:(void(^)(VASpeechRecognitionAnswer * _Nullable recognition))successCallback
               fail:(VAAnswerFailCallBack)failCallback;





/// 语音翻译（调用此接口需在管理系统启用语音翻译系统）调用这个接口的超时时间得加大到120s
/// - Parameters:
///   - audioData: 音频文件的二进制
///   - speechLanguageCode: 源语言类型
///   - textLanguageCode: 目标语言类型
///   - codec: 编解码 传空默认为AMR_WB
///   - srate: 0或者空则默认为16000
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)speechTranslate:(NSData * _Nonnull)audioData
    speechLanguageCode:(NSString * _Nonnull)speechLanguageCode
      textLanguageCode:(NSString *_Nonnull)textLanguageCode
                 codec:(NSString *_Nullable)codec
                 srate:(int32_t)srate
               timeout:(int)timeout
               success:(void(^)(VAVoiceTranslateAnswer * _Nullable translateAnswer))successCallback
                  fail:(VAAnswerFailCallBack)failCallback;





/// 文本审核, 返回过滤后的字符串或者返回错误（调用此接口需在管理系统启用文本审核系统）
/// - Parameters:
///   - text: 需要过滤的文本
///   - strategyId: 对应文本审核的策略编号
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)textCheck:(NSString * _Nonnull)text
      strategyId:(NSString * _Nullable) strategyId
         timeout:(int)timeout
         success:(void(^)(VATextReviewAnswer * _Nullable textReview))successCallback
            fail:(VAAnswerFailCallBack)failCallback;





/// 图片审核, （调用此接口需在管理系统启用图片审核系统）调用这个接口的超时时间得加大到120s
/// - Parameters:
///   - imageUrl: 图片数据 imageUrl imageData 二选一  同时传imageData优先
///   - imageData: 图片数据 imageUrl imageData 二选一 同时传imageData优先
///   - strategyId: 对应文本审核的策略编号
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)imageCheck:(NSString * _Nullable)imageUrl
        imageData:(NSData * _Nullable)imageData
       strategyId:(NSString * _Nullable) strategyId
          timeout:(int)timeout
          success:(void(^)(VAReviewAnswer * _Nullable imageReview))successCallback
             fail:(VAAnswerFailCallBack)failCallback;





/// 音频审核, （调用此接口需在管理系统启用语音审核系统）调用这个接口的超时时间得加大到120s
/// - Parameters:
///   - audioUrl: 音频数据 audioUrl audioData二选一 同时传audioData优先
///   - audioData: 音频数据 audioUrl audioData二选一 同时传audioData优先
///   - lang: 语言
///   - codec: 编解码 传空 默认AMR_WB
///   - srate: 采样率 传空 默认为16000
///   - strategyId: 对应文本审核的策略编号
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)audioCheck:(NSString * _Nullable)audioUrl
        audioData:(NSData * _Nullable)audioData
             lang:(NSString * _Nonnull)lang
            codec:(NSString * _Nullable)codec
            srate:(int32_t)srate
       strategyId:(NSString * _Nullable) strategyId
          timeout:(int)timeout
          success:(void(^)(VAReviewAnswer * _Nullable audioReview))successCallback
             fail:(VAAnswerFailCallBack)failCallback;





/// 视频审核, （调用此接口需在管理系统启用视频审核系统） 调用这个接口的超时时间得加大到120s
/// - Parameters:
///   - videoUrl: 视频数据 videoUrl videoData二选一
///   - videoData: 视频数据 videoUrl videoData二选一
///   - videoName: 视频名字
///   - strategyId: 对应文本审核的策略编号
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)videoCheck:(NSString * _Nullable)videoUrl
        videoData:(NSData * _Nullable)videoData
        videoName:(NSString * _Nonnull)videoName
       strategyId:(NSString * _Nullable) strategyId
          timeout:(int)timeout
          success:(void(^)(VAReviewAnswer * _Nullable videoReview))successCallback
             fail:(VAAnswerFailCallBack)failCallback;


@end

NS_ASSUME_NONNULL_END

