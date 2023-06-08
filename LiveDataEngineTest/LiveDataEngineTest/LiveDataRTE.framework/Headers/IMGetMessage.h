//
//  IMGetMessage.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/3/23.
//

#import <Foundation/Foundation.h>
#import "IMFileInfo.h"
#import "LDEnum.h"
NS_ASSUME_NONNULL_BEGIN

@interface IMGetMessage : NSObject
@property(nonatomic,assign)int64_t messageType;
@property(nonatomic,assign)int64_t cursorId;
@property(nonatomic,copy)NSString * stringMessage;
@property(nonatomic,strong)NSData * binaryMessage;
@property(nonatomic,strong)NSData * audioMessage;
@property(nonatomic,copy)NSString * attrs;
@property(nonatomic,assign)int64_t modifiedTime;
@property(nonatomic,strong)IMFileInfo * fileInfo;
@property(nonatomic,assign)LDImMessageType ldMessageType;
@end

NS_ASSUME_NONNULL_END
