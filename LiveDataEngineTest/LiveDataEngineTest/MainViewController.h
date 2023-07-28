//
//  MainViewController.h
//  LiveDataEngineTest
//
//  Created by zsl on 2023/7/27.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#define RTM_Color16Hex(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
#define RTM_BlueColor RTM_Color16Hex(0x368af6)

@interface MainViewController : UIViewController

@end

NS_ASSUME_NONNULL_END
