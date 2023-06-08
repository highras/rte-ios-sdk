//
//  RTMSession.h
//  Rtm
//
//  Created by ld_zsl on 2022/11/22.
//  Copyright © 2022 FunPlus. All rights reserved.
//

#import "RTMBaseAnswer.h"
#import "RTMHistoryMessage.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTMConversation : RTMBaseAnswer

@property(nonatomic,assign)int64_t conversationId;          //会话ID
@property(nonatomic,assign)int64_t unreadaCount;            //每个会话未读数
@property(nonatomic,strong)RTMHistoryMessage * historyMessage;//最后一条消息


@end

NS_ASSUME_NONNULL_END

