//
//  IMClient+Conversation.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/3/22.
//

#import "IMClient.h"
#import "IMConversation.h"
#import "LDEnum.h"
NS_ASSUME_NONNULL_BEGIN

@interface IMClient (Conversation)




/// 获取会话
/// - Parameters:
///   - mtime: mtime参数为毫秒级时间戳，大于该时间戳的消息被计为未读消息，未读消息的最后一条作为会话的最后一条消息。不传则默认取上次离线时间。
///   - conversationType: 会话类型
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getConversation:(int64_t)mtime
      conversationType:(LDConversationType)conversationType
               timeout:(int)timeout
               success:(void(^)( NSArray <IMConversation*> *array))successCallback
                  fail:(IMAnswerFailCallBack)failCallback;




/// 获取所有未读会话
/// - Parameters:
///   - mtime: 参数为毫秒级时间戳，大于该时间戳的消息被计为未读消息，未读消息的最后一条作为会话的最后一条消息。不传则默认取上次离线时间。
///   - clear: 参数为是否清除会话未读状态
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getAllUnreadConversation:(int64_t)mtime
                          clear:(BOOL)clear
                        timeout:(int)timeout
                        success:(void(^)(NSArray <IMConversation*> *p2p,NSArray <IMConversation*> *group))successCallback
                           fail:(IMAnswerFailCallBack)failCallback;



/// 清除所有未读
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)clearUnread:(int)timeout
           success:(void(^)(void))successCallback
              fail:(IMAnswerFailCallBack)failCallback;





/// 移除p2p会话
/// - Parameters:
///   - toId: 用户Id
///   - oneWay:YES-单向删除 NO-双向删除
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)removeP2pConversation:(int64_t)toId
                      oneWay:(BOOL)oneWay
                     timeout:(int)timeout
                     success:(void(^)(void))successCallback
                        fail:(IMAnswerFailCallBack)failCallback;


@end

NS_ASSUME_NONNULL_END
