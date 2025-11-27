//
//  RTCCustomOpusManager.h
//  LiveDataEngine
//
//  Created by Admin on 12/31/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCCustomOpusManager : NSObject
+ (instancetype)initWithChannel:(int)channel highBitrate:(BOOL)highBitrate hz:(int)hz;
/**
 * 将pcm格式压缩为opus格式
 * @param data pcm格式的音频data
 * @return opus格式的音频data
 */
- (NSData*)encodePCMData:(NSData*)data;
/**
 * 将opus格式解压为pcm格式
 * @param data opus格式的data
 * @return pcm格式的音频data
 */
- (short *)decodeOpusData:(NSData*)data;
@end

NS_ASSUME_NONNULL_END
