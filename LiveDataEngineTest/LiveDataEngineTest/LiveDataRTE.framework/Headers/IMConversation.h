//
//  IMConversation.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/3/28.
//

#import <Foundation/Foundation.h>
#import "IMHistoryMessage.h"
NS_ASSUME_NONNULL_BEGIN

@interface IMConversation : NSObject


@property(nonatomic,assign)int64_t conversationId;          //会话ID
@property(nonatomic,assign)int64_t unreadaCount;            //每个会话未读数
@property(nonatomic,strong)IMHistoryMessage * historyMessage;//最后一条消息
@end

NS_ASSUME_NONNULL_END
