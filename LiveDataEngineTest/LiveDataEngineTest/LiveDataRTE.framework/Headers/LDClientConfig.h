//
//  LDClientConfig.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/2/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LDClientConfig : NSObject

//此config为全局配置  单独接口的可独立设置
@property(nonatomic,assign)int sendQuestTimeout; //默认30
@property(nonatomic,assign)int fileQuestTimeout; //默认60


@end

NS_ASSUME_NONNULL_END
