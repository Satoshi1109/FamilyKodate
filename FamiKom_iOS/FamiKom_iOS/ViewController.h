//
//  ViewController.h
//  FamiKom_iOS
//
//  Created by 山本　恭大 on 2014/10/07.
//  Copyright (c) 2014年 山本　恭大. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TimesSquare/TimesSquare.h>
@interface ViewController : UIViewController<TSQCalendarViewDelegate>

@property (nonatomic, strong) NSCalendar *calendar;
@end

