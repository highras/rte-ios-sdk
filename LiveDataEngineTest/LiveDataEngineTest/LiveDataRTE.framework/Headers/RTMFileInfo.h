//
//  RTMFileInfo.h
//  Rtm
//
//  Created by ld_zsl on 2020/10/20.
//  Copyright © 2020 FunPlus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDEnum.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTMFileInfo : NSObject


@property(nonatomic,strong)NSString * url;  //文件和语音消息链接
@property(nonatomic,assign)long size;       //文件大小

//文件消息
@property(nonatomic,assign)LDFileType fileType;
@property(nonatomic,strong)NSString * surl; //图片缩略图
@property(nonatomic,strong)NSString * fileName;//文件名字
@property(nonatomic,strong)NSString * ext;//文件后缀

//语音消息
@property(nonatomic,strong)NSString * lang; //语言
@property(nonatomic,assign)int duration;    //语音消息时长
@property(nonatomic,assign)int srate;       //采样率
@property(nonatomic,strong)NSString * codec;//编码格式



@end

NS_ASSUME_NONNULL_END
