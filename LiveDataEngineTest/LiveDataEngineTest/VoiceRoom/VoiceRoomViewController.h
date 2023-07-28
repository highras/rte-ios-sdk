//
//  VoiceRoomViewController.h
//  LiveDataEngineTest
//
//  Created by zsl on 2023/6/29.
//

#import <UIKit/UIKit.h>
#import <LiveDataRTE/LiveDataEngine.h>
#import "UIImage+RTM.h"
#import "Masonry.h"
#import "MBProgressHUD.h"
NS_ASSUME_NONNULL_BEGIN

#define RTM_Color16Hex(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]


#define RTM_MainColor RTM_Color16Hex(0xedecec)
#define RTM_BlueColor RTM_Color16Hex(0x368af6)
#define RTM_GreenColor RTM_Color16Hex(0xa9e87a)

@interface VoiceRoomViewController : UIViewController
@property(nonatomic,strong)UIScrollView * backSrcollView;

@property(nonatomic,strong)UIButton * openMicrophone;
@property(nonatomic,strong)UIButton * openPlay;
@property(nonatomic,strong)UIButton * playBGM;
@property(nonatomic,strong)UIButton * stopBGM;
@property(nonatomic,strong)UIButton * pauseBGM;
@property(nonatomic,strong)UIButton * resumeBGM;
@property(nonatomic,strong)UIButton * playSoundEffect;
@property(nonatomic,strong)LDEngine * engine;
@property(nonatomic,strong)UISlider * bgmPlaySlider;
@property(nonatomic,strong)UISlider * bgmVolumeSlider;

@property(nonatomic,strong)UILabel * volume_time;
@property(nonatomic,strong)UILabel * usersVolumeShow;
@property(nonatomic,strong)dispatch_source_t speakTimer;


- (void)_setUi;
- (void)hiddenHud;
- (void)showHudMessage:(NSString*)message;
- (void)showLoadHudMessage:(NSString*)message;

@end

NS_ASSUME_NONNULL_END
