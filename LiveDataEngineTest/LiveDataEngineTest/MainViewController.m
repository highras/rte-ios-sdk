//
//  MainViewController.m
//  LiveDataEngineTest
//
//  Created by zsl on 2023/7/27.
//

#import "MainViewController.h"
#import "Masonry.h"
#import "IMDemoViewController.h"
#import "VoiceRoomViewController.h"
#import "VideoViewController.h"
@interface MainViewController ()

@end

@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    UIButton * imButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [imButton setTitle:@"IM场景" forState:UIControlStateNormal];
    [imButton addTarget:self action:@selector(_imClick) forControlEvents:UIControlEventTouchUpInside];
    [imButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    imButton.backgroundColor = RTM_BlueColor;
    [self.view addSubview:imButton];
    [imButton mas_makeConstraints:^(MASConstraintMaker *make) {
    
        make.top.equalTo(self.view).offset(120);
        make.left.equalTo(self.view).offset(40);
        make.right.equalTo(self.view).offset(-40);
        make.height.equalTo(@(50));
    }];
    
    
    UIButton * voiceRoomButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [voiceRoomButton setTitle:@"语聊房场景" forState:UIControlStateNormal];
    [voiceRoomButton addTarget:self action:@selector(_voiceRoomClick) forControlEvents:UIControlEventTouchUpInside];
    [voiceRoomButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    voiceRoomButton.backgroundColor = RTM_BlueColor;
    [self.view addSubview:voiceRoomButton];
    [voiceRoomButton mas_makeConstraints:^(MASConstraintMaker *make) {
    
        make.top.equalTo(imButton.mas_bottom).offset(40);
        make.left.equalTo(self.view).offset(40);
        make.right.equalTo(self.view).offset(-40);
        make.height.equalTo(@(50));
        
    }];
    
    
}
-(void)_imClick{
    
    IMDemoViewController * vc = [IMDemoViewController new] ;
    vc.modalPresentationStyle = UIModalPresentationFullScreen;
    [self presentViewController:vc animated:YES completion:nil];
}

-(void)_voiceRoomClick{
    
    VoiceRoomViewController * vc = [VoiceRoomViewController new] ;
    vc.modalPresentationStyle = UIModalPresentationFullScreen;
    [self presentViewController:vc animated:YES completion:nil];
    
}
-(void)_videoRoomClick{
    
    VideoViewController * vc = [VideoViewController new] ;
    vc.modalPresentationStyle = UIModalPresentationFullScreen;
    [self presentViewController:vc animated:YES completion:nil];
    
}
@end
