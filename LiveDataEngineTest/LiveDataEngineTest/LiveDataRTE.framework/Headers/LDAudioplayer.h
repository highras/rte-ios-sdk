//
//  LDAudioplayer.h
//  Test
//
//  Created by ld_zsl on 2020/8/13.
//  Copyright © 2020 FunPlus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IMAudioModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface LDAudioplayer : NSObject

+(instancetype)shareInstance;
@property(nonatomic,copy) void(^playFinish)(void);
-(void)playWithAudioModel:(IMAudioModel*)audioModel;//audioFilePath is not nil
-(void)playWithAmrData:(NSData*)amrData;//通过音频url获取的二进制数据
-(void)stop;

@end

NS_ASSUME_NONNULL_END
