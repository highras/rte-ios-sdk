//
//  ViewController.m
//  LiveDataEngineTest
//
//  Created by ld_zsl on 2023/1/31.
//

#import "IMDemoViewController.h"


@interface IMDemoViewController ()<UITableViewDelegate,UITableViewDataSource ,LDBaseDelegate,IMDelegate,RTMDelegate>
@property(nonatomic,assign)int64_t testUid;
@end

@implementation IMDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    [self _setBaseUi];
}

-(void)_logins:(NSInteger)number name:(NSString*)name{
    
    NSLog(@"=====================%@=====================",name);
    
    
    self.testUid = 666;
    
    if (number == 0) {
        
        
        if (self.mainEngine == nil) {
            self.mainEngine = [LDEngine clientWithEndpoint:@""
                                                 projectId:999
                                                    userId:self.testUid
                                              baseDelegate:self
                                                    config:nil];
            
            [self.mainEngine setIMDelegate:self];
//            [self.mainEngine setRTMDelegate:self]; 两个delegate互斥IM业务接口丰富
            
        }
        
    }else if (number == 1){
        
        NSDictionary * tokenDic = [LDToken getToken:@"key"
                                                pid:@"999"
                                                uid:[NSString stringWithFormat:@"%lld", self.testUid]];
        
        [self.mainEngine loginWithToken:[tokenDic objectForKey:@"token"]
                                     ts:[[tokenDic objectForKey:@"ts"]longLongValue]
                               language:@"zh"
                              attribute:nil
                                timeout:10
                                success:^{
            
            NSLog(@"登录成功 %lld",self.mainEngine.userId);
            dispatch_async(dispatch_get_main_queue(), ^{
                
                self.title = [NSString stringWithFormat:@"已登录 useId = %lld ",self.testUid];
                
            });
            
        } connectFail:^(FPNError * _Nullable error) {
            
            NSLog(@"登录失败%@",error);
            
        }];
        
    }
    
}
#pragma  mark 聊天
-(void)_chat:(NSInteger)number name:(NSString*)name{
    
    if (number == 0) {
        
        [self.mainEngine.imClient sendChatMessage:@((self.testUid == 666) ? 777 : 666)
                                          message:@"sendChatMessage"
                                            attrs:@"attrs"
                                 conversationType:P2p
                                          timeout:10
                                          success:^(IMSendAnswer * _Nonnull sendAnswer) {
            
            NSLog(@"sendChatMessage 成功");
            
        } fail:^(FPNError * _Nullable error) {
            
            NSLog(@"sendChatMessage 失败 %@",error.ld_autoDescription);
            
        }];
        
        
    }else if (number == 1){
        
        [self.mainEngine.imClient getMessage:@(110218614470666385)
                                  fromUserId:@(self.testUid)
                                    targetId:@((self.testUid == 666) ? 777 : 666)
                            conversationType:P2p
                                     timeout:10
                                     success:^(IMGetMessage * _Nullable message) {
            
            NSLog(@"getMessage 成功 %@",message.ld_autoDescription);
            
        } fail:^(FPNError * _Nullable error) {
            
            NSLog(@"getMessage 失败 %@",error.ld_autoDescription);
            
        }];
        
        
    }else if (number == 2){
        
        [self.mainEngine.imClient deleteMessage:@(110218614470666385)
                                     fromUserId:@(self.testUid)
                                       targetId:@((self.testUid == 666) ? 777 : 666)
                               conversationType:P2p
                                        timeout:10 success:^{
            
            NSLog(@"deleteMessage 成功");
            
        } fail:^(FPNError * _Nullable error) {
            
            NSLog(@"deleteMessage 失败");
            
        }];
        
    }else if (number == 3){
        
        [self.mainEngine.imClient getHistoryChatMessageByMessageId:@((self.testUid == 666) ? 777 : 666)
                                                              desc:YES
                                                             count:@(10)
                                                         beginMsec:nil
                                                           endMsec:nil
                                                         messageId:@(110218613797224553)
                                                  conversationType:P2p
                                                           timeout:10
                                                           success:^(IMHistory * _Nullable history) {
            
            NSLog(@"getHistoryChatMessageByMessageId 成功");
            for (IMHistoryMessage * item in history.messageArray) {
                NSLog(@"getHistoryChatMessageByMessageId %@  ---  %@",item.ld_autoDescription,item.translatedInfo.ld_autoDescription);
            }
            
            
        } fail:^(FPNError * _Nullable error) {
            
            NSLog(@"getHistoryChatMessageByMessageId 失败 %@",error.ld_autoDescription);
            
        }];
        
        
        
    }else if (number == 4){
        
        [self.mainEngine.imClient getHistoryChatMessage:@((self.testUid == 666) ? 777 : 666)
                                                   desc:YES
                                                  count:@(10)
                                              beginMsec:nil
                                                endMsec:nil
                                           lastCursorId:@(406)
                                       conversationType:P2p
                                                timeout:10
                                                success:^(IMHistory * _Nullable history) {
            
            NSLog(@"getHistoryChatMessage 成功");
            for (IMHistoryMessage * item in history.messageArray) {
                NSLog(@"getHistoryChatMessage %@ -- %@",item.ld_autoDescription,item.translatedInfo.ld_autoDescription);
            }
            
        } fail:^(FPNError * _Nullable error) {
            
            NSLog(@"getHistoryChatMessage 失败 %@",error.ld_autoDescription);
            
        }];
        
    }
    
}
#pragma  mark 会话
-(void)_conversation:(NSInteger)number name:(NSString*)name{
    
    if (number == 0) {
        
        [self.mainEngine.imClient getConversation:0
                                 conversationType:P2p
                                          timeout:10
                                          success:^(NSArray<IMConversation *> * _Nonnull array) {
            
            for(IMConversation * item in array){
                NSLog(@"getConversation %@",item.ld_autoDescription);
            }
            
            
        } fail:^(FPNError * _Nullable error) {
            
            NSLog(@"getConversation 失败 %@",error.ld_autoDescription);
            
        }];
        
    }else if (number == 1){
        
        [self.mainEngine.imClient getAllUnreadConversation:0
                                                     clear:NO
                                                   timeout:10
                                                   success:^(NSArray<IMConversation *> * _Nonnull p2p, NSArray<IMConversation *> * _Nonnull group) {
            for(IMConversation * item in p2p){
                NSLog(@"getAllUnreadConversation  p2p %@",item.ld_autoDescription);
            }
            
            for(IMConversation * item in group){
                NSLog(@"getAllUnreadConversation  group %@",item.ld_autoDescription);
            }
            
            
            
        } fail:^(FPNError * _Nullable error) {
            NSLog(@"getAllUnreadConversation 失败 %@",error.ld_autoDescription);
        }];
        
    }else if (number == 2){
        
        [self.mainEngine.imClient clearUnread:10
                                      success:^{
            
            NSLog(@"clearUnread 成功");
            
        } fail:^(FPNError * _Nullable error) {
            
            NSLog(@"clearUnread 失败 %@",error.ld_autoDescription);
            
        }];
        
    }else if (number == 3){
        
      
        [self.mainEngine.imClient removeP2pConversation:((self.testUid == 666) ? 777 : 666)
                                                 oneWay:YES
                                                timeout:10
                                                success:^{
            NSLog(@"removeP2pConversation 成功");
            
        } fail:^(FPNError * _Nullable error) {
            
            NSLog(@"removeP2pConversation 失败 %@",error.ld_autoDescription);
            
        }];
        
    }
    
}
#pragma  mark  文件
-(void)_file:(NSInteger)number name:(NSString*)name{
    
    if (number == 0) {
        
        self.recordManager = [[LDRecordManager alloc] init];
        [self.recordManager startRecordWithLang:@"zh-CN"];
        
        
        
    }else if (number == 1) {
        
        
        [self.recordManager stopRecord:^(IMAudioModel * _Nullable audioModel) {
             
            NSLog(@"停止录音audioModel %@",audioModel.ld_autoDescription);
            
            [self.mainEngine.imClient sendAudioMessageWithId:@((self.testUid == 666) ? 777 : 666)
                                                  audioModel:audioModel
                                                       attrs:@{}
                                            conversationType:P2p
                                                     timeout:20
                                                     success:^(IMSendAnswer * _Nonnull sendAnswer) {
                
                NSLog(@"发送录音成功，进行播放");
                [[LDAudioplayer shareInstance] playWithAudioModel:audioModel];
                [LDAudioplayer shareInstance].playFinish = ^{
                    
                    NSLog(@"play finish");

                };
                
            } fail:^(FPNError * _Nullable error) {
                
                NSLog(@"发送录音失败 %@",error.ld_autoDescription);
                
            }];
            
        }];
        
        
        
        
        
    }else if (number == 2){
        
        NSData *imageData = UIImageJPEGRepresentation([UIImage imageNamed:@"image123.jpg"], 1);
        NSLog(@"%@",imageData);
        [self.mainEngine.imClient sendFileWithId:@((self.testUid == 666) ? 777 : 666)
                                        fileData:imageData
                                        fileName:@"123"
                                      fileSuffix:@"jpg"
                                        fileType:Image
                                           attrs:@{}
                                conversationType:P2p
                                         timeout:20
                                         success:^(IMSendAnswer * _Nonnull sendAnswer) {
            
            NSLog(@"发送文件成功");
            
        } fail:^(FPNError * _Nullable error) {
            
            NSLog(@"发送文件失败 %@",error.ld_autoDescription);
            
        }];
        
        
        
    }
    

}
-(void)_other:(NSInteger)number name:(NSString*)name{
    
    [self.mainEngine.vaClient translateText:@"hello"
                           originalLanguage:@"en"
                             targetLanguage:@"zh-CN"
                                       type:nil
                                  profanity:nil
                                    timeout:10
                                    success:^(VATranslatedInfo * _Nullable translatedInfo) {
        
        NSLog(@"translateText %@",translatedInfo.ld_autoDescription);
        
    } fail:^(FPNError * _Nullable error) {
        
        NSLog(@"上translateText文件失败 %@",error.ld_autoDescription);
        
    }];

}
-(void)_setBaseUi{
    
    
    self.titleArray = [NSMutableArray array];
    [self.titleArray addObject:@{@"登录":@[@"1.初始化相关设置",@"2.登录"]}];
    [self.titleArray addObject:@{@"聊天":@[@"发送聊天消息",@"获取单条消息",@"删除单条消息",@"拉取多条历史消息方式1",@"拉取多条历史消息方式2"]}];
    [self.titleArray addObject:@{@"会话":@[@"获取所有会话",@"获取未读会话",@"清理未读",@"移除p2p会话"]}];
    [self.titleArray addObject:@{@"文件":@[@"开始录音",@"结束录音并发送语音消息且播放",@"发送文件"]}];
    [self.titleArray addObject:@{@"增值服务":@[@"翻译等"]}];

    [self.view addSubview:self.mainTableView];
    [self.mainTableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.equalTo(self.view);
    }];
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    NSDictionary * itemDic = [self.titleArray objectAtIndex:indexPath.section];
    
    switch (indexPath.section) {
        case 0:
        {
            [self _logins:indexPath.row name:[itemDic.allValues.firstObject objectAtIndex:indexPath.row]];
        }
            break;
        case 1:
        {
            [self _chat:indexPath.row name:[itemDic.allValues.firstObject objectAtIndex:indexPath.row]];
        }
            break;
        case 2:
        {
            [self _conversation:indexPath.row name:[itemDic.allValues.firstObject objectAtIndex:indexPath.row]];
        }
            break;
       
        case 4:
        {
            [self _file:indexPath.row name:[itemDic.allValues.firstObject objectAtIndex:indexPath.row]];
        }
            break;
        case 5:
        {
            [self _other:indexPath.row name:[itemDic.allValues.firstObject objectAtIndex:indexPath.row]];
        }
            break;
        
        
        default:
            break;
    }
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return 77;
}
-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    NSDictionary * itemDic = self.titleArray[section];
    NSArray * names = itemDic.allValues.firstObject;
    return names.count;
}
-(UIView*)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section{
    
    UIButton * titleName = [UIButton buttonWithType:UIButtonTypeCustom];
    [titleName setTitleColor:[UIColor redColor] forState:UIControlStateNormal];
    NSDictionary * itemDic = self.titleArray[section];
    [titleName setTitle:itemDic.allKeys.firstObject forState:UIControlStateNormal];
    titleName.titleLabel.font = [UIFont boldSystemFontOfSize:15];
    return titleName;
}
-(CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section{
    return 55;
}
-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return self.self.titleArray.count;
}
-(UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    UITableViewCell * cell = [tableView dequeueReusableCellWithIdentifier:@"id"];
    if (cell == nil) {
        cell = [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"id"];
    }
    NSDictionary * dic = self.titleArray[indexPath.section];
    NSArray * names = dic.allValues.firstObject;
    cell.textLabel.text = names[indexPath.row];
    cell.textLabel.textColor = [UIColor blackColor];
    cell.textLabel.font = [UIFont systemFontOfSize:16];
    cell.textLabel.numberOfLines = 0;
    return cell;
}
-(UITableView*)mainTableView{
    if (_mainTableView == nil) {
        _mainTableView = [[UITableView alloc]initWithFrame:CGRectZero style:UITableViewStyleGrouped];
        _mainTableView.delegate = self;
        _mainTableView.dataSource = self;
    }
    return _mainTableView;
}

@end
