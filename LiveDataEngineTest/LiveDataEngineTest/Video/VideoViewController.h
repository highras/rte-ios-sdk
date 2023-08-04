//
//  VideoViewController.h
//  SdkTest
//
//  Created by zsl on 2021/7/1.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Masonry.h"
#import "MBProgressHUD.h"
#import "LDToken.h"
#import <LiveDataRTE/LiveDataEngine.h>
NS_ASSUME_NONNULL_BEGIN

@interface VideoViewController : UIViewController
@property(nonatomic,strong)UIButton * joinRoomButton;
@property(nonatomic,strong)UIButton * createRoomButton;
@property(nonatomic,strong)UIButton * subscribeUserButton;
@property(nonatomic,strong)UIButton * audioManagerButton;
-(void)_setUi;

- (void)showHudMessage:(NSString*)message;
- (void)showLoadHudMessage:(NSString*)message;
@end

NS_ASSUME_NONNULL_END
