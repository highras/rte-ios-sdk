//
//  RTMClient+Message.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/2/2.
//

#import "RTMClient.h"
#import "RTMHistory.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTMClient (Message)



/// 发送消息 可自定义 messageType
/// - Parameters:
///   - toId: 目标id 根据conversationType 对应 userId groupId roomId
///   - messageType: 消息类型id
///   - conversationType: 会话类型
///   - message: 消息内容
///   - attrs: 自定义属性
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)sendBasicMessage:(NSNumber * _Nonnull)toId
            messageType:(NSNumber * _Nonnull)messageType
       conversationType:(LDConversationType)conversationType
                message:(NSString * _Nonnull)message
                  attrs:(NSString * _Nonnull)attrs
                timeout:(int)timeout
                success:(void(^)(RTMSendAnswer * sendAnswer))successCallback
                   fail:(RTMAnswerFailCallBack)failCallback;




/// 发送二级制数据消息 可自定义 messageType
/// - Parameters:
///   - toId: 目标id 根据conversationType 对应 userId groupId roomId
///   - messageType: 消息类型id
///   - conversationType: 会话类型
///   - data: 二进制数据
///   - attrs: 自定义属性
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)sendBinaryMessage:(NSNumber * _Nonnull)toId
             messageType:(NSNumber * _Nonnull)messageType
        conversationType:(LDConversationType)conversationType
                    data:(NSData * _Nonnull)data
                   attrs:(NSString * _Nonnull)attrs
                 timeout:(int)timeout
                 success:(void(^)(RTMSendAnswer * sendAnswer))successCallback
                    fail:(RTMAnswerFailCallBack)failCallback;





/// 获取历史消息 可指定messageType
/// - Parameters:
///   - toId: 目标id 根据conversationType 对应 userId groupId roomId
///   - desc: 是否降序
///   - count: 数量
///   - beginMsec: 开始时间 毫秒
///   - endMsec: 结束时间 毫秒
///   - lastCursorId: 游标id
///   - messageTypes: 消息类型id
///   - conversationType: 会话类型
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getHistoryBasicMessage:(NSNumber * _Nonnull)toId
                         desc:(BOOL)desc
                        count:(NSNumber * _Nonnull)count
                    beginMsec:(NSNumber * _Nullable)beginMsec
                      endMsec:(NSNumber * _Nullable)endMsec
                 lastCursorId:(NSNumber * _Nullable)lastCursorId
                 messageTypes:(NSArray <NSNumber *> * _Nullable)messageTypes
             conversationType:(LDConversationType)conversationType
                      timeout:(int)timeout
                      success:(void(^)(RTMHistory* _Nullable history))successCallback
                         fail:(RTMAnswerFailCallBack)failCallback;
@end

NS_ASSUME_NONNULL_END

