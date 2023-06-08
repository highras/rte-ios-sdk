//
//  RTMClient+Conversation.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/2/2.
//

#import "RTMClient.h"
#import "RTMConversation.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTMClient (Conversation)

/// 获取会话
/// - Parameters:
///   - mtime: mtime参数为毫秒级时间戳，大于该时间戳的消息被计为未读消息，未读消息的最后一条作为会话的最后一条消息。不传则默认取上次离线时间。
///   - messageType: 消息类型
///   - conversationType: 会话类型
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getConversation:(int64_t)mtime
           messageType:(NSArray <NSNumber*>* _Nullable)messageType
      conversationType:(LDConversationType)conversationType
               timeout:(int)timeout
               success:(void(^)( NSArray <RTMConversation*> *array))successCallback
                  fail:(RTMAnswerFailCallBack)failCallback;



/// 获取所有未读会话
/// - Parameters:
///   - mtime: 参数为毫秒级时间戳，大于该时间戳的消息被计为未读消息，未读消息的最后一条作为会话的最后一条消息。不传则默认取上次离线时间。
///   - clear: 参数为是否清除会话未读状态
///   - messageType: 消息类型
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getAllUnreadConversation:(int64_t)mtime
                          clear:(BOOL)clear
                    messageType:(NSArray <NSNumber*> * _Nullable)messageType
                        timeout:(int)timeout
                        success:(void(^)(NSArray <RTMConversation*> *p2p,NSArray <RTMConversation*> *group))successCallback
                           fail:(RTMAnswerFailCallBack)failCallback;



/// 清除所有未读
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)clearUnread:(int)timeout
           success:(void(^)(void))successCallback
              fail:(RTMAnswerFailCallBack)failCallback;





/// 移除p2p会话
/// - Parameters:
///   - toId: 用户Id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)removeP2pConversation:(int64_t)toId
                     timeout:(int)timeout
                     success:(void(^)(void))successCallback
                        fail:(RTMAnswerFailCallBack)failCallback;



@end

NS_ASSUME_NONNULL_END


    

