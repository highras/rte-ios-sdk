//
//  IMClient+Chat.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/3/22.
//

#import "IMClient.h"
#import "IMGetMessage.h"
#import "IMHistory.h"
#import "LDEngine.h"
NS_ASSUME_NONNULL_BEGIN

@interface IMClient (Chat)

/// 发送聊天消息
/// - Parameters:
///   - targetId: 目标Id 根据conversationType 对应 userId groupId roomId
///   - message: 消息内容
///   - attrs: 自定义属性
///   - conversationType: 会话类型
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)sendChatMessage:(NSNumber * _Nonnull)targetId
               message:(NSString * _Nonnull)message
                 attrs:(NSString * _Nonnull)attrs
      conversationType:(LDConversationType)conversationType
               timeout:(int)timeout
               success:(void(^)(IMSendAnswer * sendAnswer))successCallback
                  fail:(IMAnswerFailCallBack)failCallback;


/// 获取消息
/// - Parameters:
///   - messageId: 消息Id
///   - fromUserId: 发送者
///   - targetId: 接受者 根据conversationType 对应 userId groupId roomId
///   - conversationType: 会话类型
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getMessage:(NSNumber * _Nonnull)messageId
       fromUserId:(NSNumber * _Nonnull)fromUserId
         targetId:(NSNumber * _Nonnull)targetId
 conversationType:(LDConversationType)conversationType
          timeout:(int)timeout
          success:(void(^)(IMGetMessage * _Nullable message))successCallback
             fail:(IMAnswerFailCallBack)failCallback;



/// 删除消息
/// - Parameters:
///   - messageId: 消息Id
///   - fromUserId: 发送者
///   - targetId: 接受者 根据conversationType 对应 userId groupId roomId
///   - conversationType: 会话类型
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)deleteMessage:(NSNumber * _Nonnull)messageId
          fromUserId:(NSNumber * _Nonnull)fromUserId
            targetId:(NSNumber * _Nonnull)targetId
    conversationType:(LDConversationType)conversationType
             timeout:(int)timeout
             success:(void(^)(void))successCallback
                fail:(IMAnswerFailCallBack)failCallback;



/// 获取历史消息 (通过messageId)
/// - Parameters:
///   - targetId: 接受者 根据conversationType 对应 userId groupId roomId
///   - desc: 是否降序
///   - count: 数量
///   - beginMsec: 开始时间
///   - endMsec: 结束时间
///   - messageId: 消息Id
///   - conversationType: 会话类型
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getHistoryChatMessageByMessageId:(NSNumber * _Nonnull)targetId
                                   desc:(BOOL)desc
                                  count:(NSNumber * _Nonnull)count
                              beginMsec:(NSNumber * _Nullable)beginMsec
                                endMsec:(NSNumber * _Nullable)endMsec
                              messageId:(NSNumber * _Nonnull)messageId
                       conversationType:(LDConversationType)conversationType
                                timeout:(int)timeout
                                success:(void(^)(IMHistory* _Nullable history))successCallback
                                   fail:(IMAnswerFailCallBack)failCallback;


/// 获取历史消息 (通过cursorId)
/// - Parameters:
///   - targetId: 接受者 根据conversationType 对应 userId groupId roomId
///   - desc: 是否降序
///   - count: 数量
///   - beginMsec: 开始时间
///   - endMsec: 结束时间
///   - lastCursorId: 游标Id
///   - conversationType: 会话类型
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getHistoryChatMessage:(NSNumber * _Nonnull)targetId
                        desc:(BOOL)desc
                       count:(NSNumber * _Nonnull)count
                   beginMsec:(NSNumber * _Nullable)beginMsec
                     endMsec:(NSNumber * _Nullable)endMsec
                lastCursorId:(NSNumber * _Nullable)lastCursorId
            conversationType:(LDConversationType)conversationType
                     timeout:(int)timeout
                     success:(void(^)(IMHistory* _Nullable history))successCallback
                        fail:(IMAnswerFailCallBack)failCallback;

@end

NS_ASSUME_NONNULL_END
