//
//  IMHistory.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/3/23.
//

#import <Foundation/Foundation.h>
#import "IMHistoryMessage.h"
NS_ASSUME_NONNULL_BEGIN

@interface IMHistory : NSObject
@property(nonatomic,strong)NSArray <IMHistoryMessage*> *  messageArray;
@property(nonatomic,assign)int64_t begin;
@property(nonatomic,assign)int64_t end;
@property(nonatomic,assign)int64_t lastid;
@end

NS_ASSUME_NONNULL_END
