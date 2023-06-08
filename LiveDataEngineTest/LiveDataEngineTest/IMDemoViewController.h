//
//  ViewController.h
//  LiveDataEngineTest
//
//  Created by ld_zsl on 2023/1/31.
//

#import <UIKit/UIKit.h>

#import <LiveDataRTE/LiveDataEngine.h>
#import "Masonry.h"
#import "LDToken.h"
#import "NSObject+Description.h"
@interface IMDemoViewController : UIViewController 

@property(nonatomic,strong)UITableView * mainTableView;
@property(nonatomic,strong)NSMutableArray * titleArray;
@property(nonatomic,strong)LDEngine * mainEngine;
@property(nonatomic,strong)LDRecordManager * recordManager;

@end


