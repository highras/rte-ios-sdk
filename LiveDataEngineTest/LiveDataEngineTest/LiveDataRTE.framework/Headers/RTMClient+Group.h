//
//  RTMClient+Group.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/2/2.
//

#import "RTMClient.h"
#import "RTMMemberCountAnswer.h"
#import "RTMMemberAnswer.h"
#import "RTMInfoAnswer.h"
#import "RTMAttriAnswer.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTMClient (Group)

/// 获取加入的群组
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getUserGroups:(int)timeout
             success:(void(^)(NSArray * _Nullable groupArray))successCallback
                fail:(RTMAnswerFailCallBack)failCallback;



/// 获取群组成员
/// - Parameters:
///   - groupId: 群id
///   - online: 是否在线
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getGroupMembers:(NSNumber * _Nonnull)groupId
                online:(BOOL)online
               timeout:(int)timeout
               success:(void(^)(RTMMemberAnswer * _Nullable memberCountAnswer))successCallback
                  fail:(RTMAnswerFailCallBack)failCallback;


/// 获取群组成员数量
/// - Parameters:
///   - groupId: 群id
///   - online: 是否在线
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getGroupMemberCount:(NSNumber * _Nonnull)groupId
                    online:(BOOL)online
                   timeout:(int)timeout
                   success:(void(^)(RTMMemberCountAnswer * _Nullable memberCountAnswer))successCallback
                      fail:(RTMAnswerFailCallBack)failCallback;


/// 添加群成员
/// - Parameters:
///   - groupId: 群id
///   - memberIds: 成员id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)addGroupMembers:(NSNumber * _Nonnull)groupId
             memberIds:(NSArray <NSNumber* >* _Nonnull)memberIds
               timeout:(int)timeout
               success:(void(^)(void))successCallback
                  fail:(RTMAnswerFailCallBack)failCallback;


/// 删除群成员
/// - Parameters:
///   - groupId: 群id
///   - memberIds: 群成员id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)deleteGroupMembers:(NSNumber * _Nonnull)groupId
                memberIds:(NSArray <NSNumber* >* _Nonnull)memberIds
                  timeout:(int)timeout
                  success:(void(^)(void))successCallback
                     fail:(RTMAnswerFailCallBack)failCallback;




/// 获取群组信息
/// - Parameters:
///   - groupId: 群id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getGroupInfo:(NSNumber * _Nonnull)groupId
            timeout:(int)timeout
            success:(void(^)(RTMInfoAnswer * _Nullable info))successCallback
               fail:(RTMAnswerFailCallBack)failCallback;


/// 设置群信息
/// - Parameters:
///   - groupId: 群id
///   - openInfo: 公开信息
///   - privateInfo: 私有信息
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)setGroupInfo:(NSNumber * _Nonnull)groupId
           openInfo:(NSString * _Nullable)openInfo
        privateInfo:(NSString * _Nullable)privateInfo
            timeout:(int)timeout
            success:(void(^)(void))successCallback
               fail:(RTMAnswerFailCallBack)failCallback;



/// 获取群信息
/// - Parameters:
///   - groupIds: 群id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getGroupsPublicInfo:(NSArray <NSNumber* > * _Nullable)groupIds
                   timeout:(int)timeout
                   success:(void(^)(RTMAttriAnswer * _Nullable info))successCallback
                      fail:(RTMAnswerFailCallBack)failCallback;
@end

NS_ASSUME_NONNULL_END



