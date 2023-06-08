//
//  RTMClient+Room.h
//  LiveDataEngine
//
//  Created by ld_zsl on 2023/2/2.
//

#import "RTMClient.h"
#import "RTMAttriAnswer.h"
#import "RTMRoomMemberCountAnswer.h"
#import "RTMInfoAnswer.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTMClient (Room)

/// 获取加入的房间
/// - Parameters:
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getUserRooms:(int)timeout
            success:(void(^)(NSArray * _Nullable roomArray))successCallback
               fail:(RTMAnswerFailCallBack)failCallback;




/// 进入房间 (不会持久化)
/// - Parameters:
///   - roomId: 房间id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)enterRoom:(NSNumber * _Nonnull)roomId
         timeout:(int)timeout
         success:(void(^)(void))successCallback
            fail:(RTMAnswerFailCallBack)failCallback;




/// 离开房间
/// - Parameters:
///   - roomId: 房间id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)leaveRoom:(NSNumber * _Nonnull)roomId
         timeout:(int)timeout
         success:(void(^)(void))successCallback
            fail:(RTMAnswerFailCallBack)failCallback;




/// 获取房间成员
/// - Parameters:
///   - roomId: 房间id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getRoomMembers:(NSNumber * _Nonnull)roomId
              timeout:(int)timeout
              success:(void(^)(NSArray * _Nullable userIdArray))successCallback
                 fail:(RTMAnswerFailCallBack)failCallback;



/// 获取房间成员数量
/// - Parameters:
///   - roomIds: 房间id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getRoomMemberCount:(NSArray <NSNumber*>* _Nonnull)roomIds
                  timeout:(int)timeout
                  success:(void(^)(RTMRoomMemberCountAnswer * answer))successCallback
                     fail:(RTMAnswerFailCallBack)failCallback;




/// 设置房间信息
/// - Parameters:
///   - roomId: 房间id
///   - openInfo: 公开信息
///   - privateInfo: 私有信息
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)setRoomInfo:(NSNumber * _Nonnull)roomId
          openInfo:(NSString * _Nullable)openInfo
       privateInfo:(NSString * _Nullable)privateInfo
           timeout:(int)timeout
           success:(void(^)(void))successCallback
              fail:(RTMAnswerFailCallBack)failCallback;



/// 获取房间信息
/// - Parameters:
///   - roomId: 房间id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getRoomInfo:(NSNumber * _Nonnull)roomId
           timeout:(int)timeout
           success:(void(^)(RTMInfoAnswer * _Nullable info))successCallback
              fail:(RTMAnswerFailCallBack)failCallback;




/// 获取房间公开信息
/// - Parameters:
///   - roomIds: 房间id
///   - timeout: 请求超时时间 秒
///   - successCallback: 成功回调
///   - failCallback: 失败回调
-(void)getRoomsPublicInfo:(NSArray <NSNumber* > * _Nullable)roomIds
                  timeout:(int)timeout
                  success:(void(^)(RTMAttriAnswer * _Nullable info))successCallback
                     fail:(RTMAnswerFailCallBack)failCallback;
@end

NS_ASSUME_NONNULL_END

