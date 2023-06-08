//
//  RTMClient+File.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/2/2.
//

#import "RTMClient.h"
#import "LDEngine.h"
#import "RTMAudioModel.h"
#import "RTMFileAnswer.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTMClient (File)


/// 发送语音消息
/// - Parameters:
///   - toId: 目标id 根据conversationType 对应 userId groupId roomId
///   - audioModel: 语音消息结构 (通过LDRecordManager录音后返回)
///   - attrs: 自定义属性
///   - conversationType: 会话类型
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)sendAudioMessageWithId:(NSNumber * _Nonnull)toId
                   audioModel:(RTMAudioModel * _Nullable)audioModel
                        attrs:(NSDictionary * _Nullable)attrs
            conversationType:(LDConversationType)conversationType
                      timeout:(int)timeout
                      success:(void(^)(RTMSendAnswer * sendAnswer))successCallback
                         fail:(RTMAnswerFailCallBack)failCallback;





/// 发送文件
/// - Parameters:
///   - toId: 目标Id 根据conversationType 对应 userId groupId roomId
///   - fileData: 文件数据
///   - fileName: 文件名称
///   - fileSuffix: 文件后缀
///   - fileType: 文件类型
///   - attrs: 自定义属性
///   - conversationType: 会话类型
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)sendFileWithId:(NSNumber * _Nonnull)toId
             fileData:(NSData * _Nullable)fileData
             fileName:(NSString * _Nullable)fileName
           fileSuffix:(NSString * _Nullable)fileSuffix
             fileType:(LDFileType)fileType
                attrs:(NSDictionary * _Nullable)attrs
     conversationType:(LDConversationType)conversationType
              timeout:(int)timeout
              success:(void(^)(RTMSendAnswer * sendAnswer))successCallback
                 fail:(RTMAnswerFailCallBack)failCallback;




/// 上传文件
/// - Parameters:
///   - fileData: 文件数据
///   - fileName: 文件名称
///   - fileSuffix: 文件后缀
///   - fileType: 文件类型
///   - audioModel: 语音消息结构 (通过LDRecordManager录音后返回)
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)uploadFileData:(NSData * _Nullable)fileData
             fileName:(NSString * _Nullable)fileName
           fileSuffix:(NSString * _Nullable)fileSuffix
             fileType:(LDFileType)fileType
           audioModel:(RTMAudioModel * _Nullable)audioModel
              timeout:(int)timeout
              success:(void(^)(RTMFileAnswer * fileAnswer))successCallback
                 fail:(RTMAnswerFailCallBack)failCallback;
@end

NS_ASSUME_NONNULL_END
