//
//  LDEngine.h
//  LDEngine
//
//  Created by ld_zsl on 2023/1/31.
//

#import <Foundation/Foundation.h>
#import "LDBaseDelegate.h"
#import <Fpnn/FPNError.h>
#import "LDEnum.h"
#import "LDClientConfig.h"
#import "RTMDelegate.h"
#import "IMDelegate.h"
#import "RTCAudioProtocol.h"
#import "RTCVideoProtocol.h"
#import "LDVoiceRoomDelegate.h"
NS_ASSUME_NONNULL_BEGIN

typedef void (^LDLoginSuccessCallBack)(void);
typedef void (^LDLoginFailCallBack)(FPNError * _Nullable error);

@class RTMClient,IMClient,VAClient,RTCClient,LDVoiceRoomClient;
@interface LDEngine : NSObject

/// 版本号
+(NSString*)getSdkVersion;


/// 初始化
/// - Parameters:
///   - endpoint: 项目地址 管理后台获取
///   - projectId: 项目id
///   - userId: 用户id
///   - baseDelegate: 基础代理(自动重连)
///   - config: 项目配置
+ (nullable instancetype)clientWithEndpoint:(nonnull NSString * )endpoint
                                  projectId:(int64_t)projectId
                                     userId:(int64_t)userId
                               baseDelegate:(id <LDBaseDelegate>)baseDelegate
                                     config:(nullable LDClientConfig *)config;


/// 登录
/// - Parameters:
///   - token: 两种方式获取    1.客户端生成                2.服务端拉取返回
///   - ts: 对应token获取方式  1.客户端生成token对应时间戳   2.传0
///   - language: 用户语言
///   - attribute: 自定义属性
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
- (void)loginWithToken:(nonnull NSString *)token
                    ts:(int64_t)ts
              language:(nullable NSString *)language
             attribute:(nullable NSDictionary *)attribute
               timeout:(int)timeout
               success:(LDLoginSuccessCallBack)loginSuccess
           connectFail:(LDLoginFailCallBack)loginFail;


/// base代理对象 用于处理自动重连
@property(nonatomic,weak)id <LDBaseDelegate> baseDelegate;



/// 聊天通信（对比rtmClient具备更丰富的业务接口）  ---------- 注意！rtmDelegate和imDelegate不可同时设定使用
-(BOOL)setIMDelegate:(id <IMDelegate>_Nullable)imDelegate;
@property(nonatomic,weak,readonly)id <IMDelegate> imDelegate;
@property(nonatomic,strong)IMClient * imClient;



/// 基础聊天通信                               ---------- 注意！rtmDelegate和imDelegate不可同时设定使用
-(BOOL)setRTMDelegate:(id <RTMDelegate> _Nullable)rtmDelegate;
@property(nonatomic,weak,readonly)id <RTMDelegate> rtmDelegate;
@property(nonatomic,strong)RTMClient * rtmClient;




/// 语聊房场景（对比rtcClient具备更丰富的业务接口） ---------- 注意！RTCAudioProtocol，RTCVideoProtocol和LDVoiceRoomDelegate不可同时设定使用
-(BOOL)setLDVoiceRoomDelegate:(id <LDVoiceRoomDelegate> _Nullable)voiceRoomDelegate;
@property(nonatomic,weak,readonly)id <LDVoiceRoomDelegate> voiceRoomDelegate;
@property(nonatomic,strong)LDVoiceRoomClient * voiceRoomClient;



/// 基础实时音视频                              ---------- 注意！RTCAudioProtocol，RTCVideoProtocol和LDVoiceRoomDelegate不可同时设定使用
-(BOOL)setRtcAudioDelegate:(id <RTCAudioProtocol> _Nullable)rtcAudioDelegate;
-(BOOL)setRtcVideoDelegate:(id <RTCVideoProtocol> _Nullable)rtcVideoDelegate;
@property(nonatomic,weak,readonly)id <RTCAudioProtocol> rtcAudioDelegate;
@property(nonatomic,weak,readonly)id <RTCVideoProtocol> rtcVideoDelegate;
@property(nonatomic,strong)RTCClient * rtcClient;



/// 增值服务（审核，翻译等）
@property(nonatomic,strong)VAClient * vaClient;


/// 项目id
@property(nonatomic,readonly,assign)int64_t projectId;
/// 用户id
@property(nonatomic,readonly,assign)int64_t userId;


/// 当前用户连接状态
@property (nonatomic,readonly,assign)LDClientConnectStatus currentConnectStatus;
//退出下线  登录连接状态下有效LDClientConnectStatusConnected
-(BOOL)closeConnect;



- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

