//
//  RTMRecordManager.h
//  Test
//
//  Created by ld_zsl on 2020/8/13.
//  Copyright © 2020 FunPlus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IMAudioModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface LDRecordManager : NSObject


-(void)startRecordWithLang:(NSString * _Nonnull)lang;
-(void)stopRecord:(void(^)(IMAudioModel * _Nullable audioModel))recorderFinish;


@end

NS_ASSUME_NONNULL_END
