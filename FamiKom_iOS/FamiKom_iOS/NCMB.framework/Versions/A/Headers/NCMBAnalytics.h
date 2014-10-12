//
//  NCMBAnalytics.h
//  NIFTY Cloud mobile backend
//
//  Created by NIFTY Corporation on 2013/07/02.
//  Copyright 2013 NIFTY Corporation All Rights Reserved.
//

#import <Foundation/Foundation.h>

/**
 NCMBAnalyticsクラスは、プッシュの開封状況を取得するためのクラスです。
 開封状況を取得すると、コントロールパネル上でプッシュ通知の統計情報を確認することができます。
 */
@interface NCMBAnalytics : NSObject

/**
 アプリが起動された際に、情報を送信。didFinishLaunchingWithOptions内で呼び出す。
  @param launchOptions プッシュ通知内容を含むアプリケーションの起動オプション
 */
+ (void)trackAppOpenedWithLaunchOptions:(NSDictionary *)launchOptions;

/**
 プッシュ通知によりアプリが起動された際に、情報を送信。didReceiveRemoteNotification内で呼び出す
  @param userInfo プッシュ通知内容
*/
+ (void)trackAppOpenedWithRemoteNotificationPayload:(NSDictionary *)userInfo;

@end
