//
//  IMClient+User.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/3/22.
//

#import "IMClient.h"
#import "IMUserInfo.h"
#import "LDEnum.h"
NS_ASSUME_NONNULL_BEGIN

@interface IMClient (User)


/// 获取用户信息
/// - Parameters:
///   - uids: userId集合
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getUsersInfo:(NSArray <NSNumber *> *)uids
            timeout:(int)timeout
            success:(void(^)(NSArray <IMUserInfo *> * array))successCallback
               fail:(IMAnswerFailCallBack)failCallback;


@end


NS_ASSUME_NONNULL_END


