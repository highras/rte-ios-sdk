//
//  AppDelegate.m
//  LiveDataEngineTest
//
//  Created by ld_zsl on 2023/1/31.
//

#import "AppDelegate.h"
#import "IMDemoViewController.h"
//#import "RTMDemoViewController.h"
//#import "RTCDemoViewController.h"
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UINavigationController * nav = [[UINavigationController alloc] initWithRootViewController:[IMDemoViewController new]];
//    UINavigationController * nav = [[UINavigationController alloc] initWithRootViewController:[RTMDemoViewController new]];
//    UINavigationController * nav = [[UINavigationController alloc] initWithRootViewController:[RTCDemoViewController new]];
    [self.window setRootViewController:nav];
    [self.window makeKeyAndVisible];
    
    return YES;
}





@end
