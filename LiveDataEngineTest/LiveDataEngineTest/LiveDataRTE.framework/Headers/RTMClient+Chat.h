//
//  RTMClient+Chat.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/2/2.
//

#import "RTMClient.h"
#import "RTMGetMessage.h"
#import "RTMHistory.h"
#import "LDEngine.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTMClient (Chat)

/// 发送聊天消息 （可开启增值服务，自动翻译审核等）
/// - Parameters:
///   - toId: 根据conversationType 对应 userId groupId roomId
///   - message: 消息内容
///   - attrs: 自定义属性
///   - conversationType: 会话类型
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)sendChatMessage:(NSNumber * _Nonnull)toId
               message:(NSString * _Nonnull)message
                 attrs:(NSString * _Nonnull)attrs
      conversationType:(LDConversationType)conversationType
               timeout:(int)timeout
               success:(void(^)(RTMSendAnswer * sendAnswer))successCallback
                  fail:(RTMAnswerFailCallBack)failCallback;



/// 发送cmd命令
/// - Parameters:
///   - toId: 根据conversationType 对应 userId groupId roomId
///   - message: 消息内容
///   - attrs: 自定义属性
///   - conversationType: 会话类型
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)sendCMDMessage:(NSNumber * _Nonnull)toId
              message:(NSString * _Nonnull)message
                attrs:(NSString * _Nonnull)attrs
     conversationType:(LDConversationType)conversationType
              timeout:(int)timeout
              success:(void(^)(RTMSendAnswer * sendAnswer))successCallback
                 fail:(RTMAnswerFailCallBack)failCallback;




/// 获取消息
/// - Parameters:
///   - messageId: 消息id
///   - fromUserId: 发送者id
///   - toId: 根据conversationType 对应 userId groupId roomId
///   - conversationType: 会话类型
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getMessage:(NSNumber * _Nonnull)messageId
       fromUserId:(NSNumber * _Nonnull)fromUserId
             toId:(NSNumber * _Nonnull)toId
 conversationType:(LDConversationType)conversationType
          timeout:(int)timeout
          success:(void(^)(RTMGetMessage * _Nullable message))successCallback
             fail:(RTMAnswerFailCallBack)failCallback;





/// 删除消息
/// - Parameters:
///   - messageId: 消息id
///   - fromUserId: 发送者id
///   - toId: 根据conversationType 对应 userId groupId roomId
///   - conversationType: 会话类型
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)deleteMessage:(NSNumber * _Nonnull)messageId
          fromUserId:(NSNumber * _Nonnull)fromUserId
                toId:(NSNumber * _Nonnull)toId
    conversationType:(LDConversationType)conversationType
             timeout:(int)timeout
             success:(void(^)(void))successCallback
                fail:(RTMAnswerFailCallBack)failCallback;





/// 拉取历史消息 通过messageId
/// - Parameters:
///   - toId: 根据conversationType 对应 userId groupId roomId
///   - desc: 是否降序
///   - count: 数量
///   - beginMsec: 开始时间 毫秒
///   - endMsec: 结束时间 毫秒
///   - messageId: 消息id
///   - conversationType: 会话类型
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getHistoryChatMessageByMessageId:(NSNumber * _Nonnull)toId
                                   desc:(BOOL)desc
                                  count:(NSNumber * _Nonnull)count
                              beginMsec:(NSNumber * _Nullable)beginMsec
                                endMsec:(NSNumber * _Nullable)endMsec
                              messageId:(NSNumber * _Nonnull)messageId
                       conversationType:(LDConversationType)conversationType
                                timeout:(int)timeout
                                success:(void(^)(RTMHistory* _Nullable history))successCallback
                                   fail:(RTMAnswerFailCallBack)failCallback;




/// /// 拉取历史消息 通过cursorId
/// - Parameters:
///   - toId: 根据conversationType 对应 userId groupId roomId
///   - desc: 是否降序
///   - count: 数量
///   - beginMsec: 开始时间 毫秒
///   - endMsec: 结束时间 毫秒
///   - lastCursorId: 游标 cursorId
///   - conversationType: 会话类型
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getHistoryChatMessage:(NSNumber * _Nonnull)toId
                        desc:(BOOL)desc
                       count:(NSNumber * _Nonnull)count
                   beginMsec:(NSNumber * _Nullable)beginMsec
                     endMsec:(NSNumber * _Nullable)endMsec
                lastCursorId:(NSNumber * _Nullable)lastCursorId
            conversationType:(LDConversationType)conversationType
                     timeout:(int)timeout
                     success:(void(^)(RTMHistory* _Nullable history))successCallback
                        fail:(RTMAnswerFailCallBack)failCallback;



@end

NS_ASSUME_NONNULL_END





