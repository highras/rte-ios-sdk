//
//  RTMSendAnswer.h
//  Rtm
//
//  Created by ld_zsl on 2020/8/13.
//  Copyright © 2020 FunPlus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTMBaseAnswer.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTMSendAnswer : RTMBaseAnswer
@property(nonatomic,assign)int64_t mtime;
@property(nonatomic,assign)int64_t messageId;
@property(nonatomic,strong)NSString * msg;
@end

NS_ASSUME_NONNULL_END
