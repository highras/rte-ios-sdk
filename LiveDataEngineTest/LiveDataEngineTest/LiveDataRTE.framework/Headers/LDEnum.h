//
//  LDEnum.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/3/17.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, LDClientConnectStatus){
    
    LDClientConnectStatusConnectClosed = 0,
    LDClientConnectStatusConnecting = 1,
    LDClientConnectStatusConnected = 2,
    
};

typedef NS_ENUM(NSInteger, LDConversationType) {
    
    P2p          = 1,//IM+RTM
    Group        = 2,//IM+RTM
    Room         = 3,//RTM
    Broadcast    = 4,//RTM
    
};

typedef NS_ENUM(NSInteger, LDFileType) {
    
    Image = 0,
    Voice = 1,
    Video = 2,
    Other = 3,
    
};


typedef NS_ENUM(NSInteger, LDImMessageType) {
    
    Text = 0,
    Audio = 1,
    File = 2,
    
};


//group:允许任何人，需要审批，拒绝任何人
//room: 允许任何人，密码
typedef NS_ENUM(NSInteger, LDApplyGrantType) {
    
    ApplyGrantAll = 0,   //允许任何人
    ApplyGrantVerify = 1,//需要验证
    ApplyGrantDeny = 2,  //拒绝任何人
    ApplyGrantPassword = 3   //需要密码
    
};

typedef NS_ENUM(NSInteger, LDInviteGrantType) {
    
    InviteGrantDeny = 0,  //不许所有群成员邀请人 只允许管理员
    InviteGrantAll = 1,   //允许所有群成员邀请人
    
};

typedef NS_ENUM(NSInteger, LDCaptureVideoLevel){
    
    LDCaptureVideoDefault = 1,// 320 * 240  15f
    LDCaptureVideoMiddle = 2, // 320 * 240  30f
    LDCaptureVideoHigh = 3,   // 640 * 480  30f
    
};
