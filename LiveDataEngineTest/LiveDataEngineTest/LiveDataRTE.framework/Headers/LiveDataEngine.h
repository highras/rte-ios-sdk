



//版本 iOS_v1.0.0


//1.在TARGETS->Build Settings->Other Linker Flags （选中ALL视图）中添加-ObjC，字母O和C大写，符号“-”请勿忽略
//2.静态库中采用Objective-C++实现，因此需要您保证您工程中至少有一个.mm后缀的源文件(您可以将任意一个.m后缀的文件改名为.mm)
//3.添加库libresolv.9.tbd
//4.如需音视频功能需在 Info.plist 添加权限  Privacy - Microphone Usage Description    Privacy - Camera Usage Description

//注意！SDK回调线程为子线程 更新UI及耗时操作请切换线程


//engine
#import <LiveDataRTE/LDEngine.h>


//IM
#import <LiveDataRTE/IMClient+Chat.h>
#import <LiveDataRTE/IMClient+File.h>
#import <LiveDataRTE/IMClient+Conversation.h>
#import <LiveDataRTE/IMClient+Group.h>
#import <LiveDataRTE/IMClient+Room.h>
#import <LiveDataRTE/IMClient+Friend.h>
#import <LiveDataRTE/IMClient+User.h>
#import <LiveDataRTE/IMClient+Tools.h>


//语音消息
#import <LiveDataRTE/LDRecordManager.h>
#import <LiveDataRTE/LDAudioplayer.h>


//RTM
#import <LiveDataRTE/RTMClient+Message.h>
#import <LiveDataRTE/RTMClient+Chat.h>
#import <LiveDataRTE/RTMClient+File.h>
#import <LiveDataRTE/RTMClient+Conversation.h>
#import <LiveDataRTE/RTMClient+Group.h>
#import <LiveDataRTE/RTMClient+Room.h>
#import <LiveDataRTE/RTMClient+Friend.h>
#import <LiveDataRTE/RTMClient+User.h>
#import <LiveDataRTE/RTMClient+Tools.h>


//RTC
#import <LiveDataRTE/RTCClient+AudioRoom.h>
#import <LiveDataRTE/RTCClient+AudioP2p.h>
#import <LiveDataRTE/RTCClient+VideoRoom.h>
#import <LiveDataRTE/RTCClient+VideoP2p.h>
#import <LiveDataRTE/RTCClient+AutoTranslateAudioRoom.h>


//VA 增值服务
#import <LiveDataRTE/VAClient+Services.h>


//语聊房
#import <LiveDataRTE/LDVoiceRoomClient.h>
#import <LiveDataRTE/LDVoiceRoomClient+VoiceRoom.h>

