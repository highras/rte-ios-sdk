//
//  AppDelegate.m
//  LiveDataEngineTest
//
//  Created by ld_zsl on 2023/1/31.
//

#import "AppDelegate.h"
#import "MainViewController.h"
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UINavigationController * nav = [[UINavigationController alloc] initWithRootViewController:[MainViewController new]];
    [self.window setRootViewController:nav];
    [self.window makeKeyAndVisible];
    
    return YES;
}




@end
