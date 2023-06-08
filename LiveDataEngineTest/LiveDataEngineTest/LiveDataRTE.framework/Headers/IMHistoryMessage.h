//
//  IMHistoryMessage.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/3/23.
//

#import <Foundation/Foundation.h>
#import "IMMessage.h"
NS_ASSUME_NONNULL_BEGIN

@interface IMHistoryMessage : IMMessage
@property(nonatomic,assign)int64_t cursorId;
@end

NS_ASSUME_NONNULL_END
