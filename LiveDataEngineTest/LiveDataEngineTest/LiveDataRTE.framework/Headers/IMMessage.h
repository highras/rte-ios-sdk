//
//  IMMessage.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/3/22.
//

#import <Foundation/Foundation.h>
#import "IMFileInfo.h"
#import "IMTranslatedInfo.h"
#import "LDEnum.h"
NS_ASSUME_NONNULL_BEGIN


@interface IMMessage : NSObject
@property(nonatomic,assign)int64_t fromUid;
@property(nonatomic,assign)int64_t targetId;//根据p2p group room  可代表userId  groupId  roomId
@property(nonatomic,assign)int64_t messageType;
@property(nonatomic,assign)int64_t messageId;
@property(nonatomic,copy)NSString * stringMessage;
@property(nonatomic,copy,nullable)NSString * attrs;
@property(nonatomic,assign)int64_t modifiedTime;
@property(nonatomic,strong)IMFileInfo * fileInfo;
@property(nonatomic,strong)IMTranslatedInfo * translatedInfo;//chat结构
@property(nonatomic,assign)LDImMessageType ldMessageType;

@end

NS_ASSUME_NONNULL_END
