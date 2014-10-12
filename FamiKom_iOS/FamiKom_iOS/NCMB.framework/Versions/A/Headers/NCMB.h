//
//  NCMB.h
//  NIFTY Cloud mobile backend
//
//  Created by NIFTY Corporation on 2013/04/17.
//  Copyright 2013 NIFTY Corporation All Rights Reserved.
//

#import <Foundation/Foundation.h>

#import "NCMBObject.h"
#import "NCMBRelation.h"
#import "NCMBUser.h"
#import "NCMBACL.h"
#import "NCMBFile.h"
#import "NCMBRole.h"
#import "NCMBQuery.h"
#import "NCMBInstallation.h"
#import "NCMBError.h"
#import "NCMBConstants.h"
#import "NCMBPush.h"
#import "NCMBAnonymousUtils.h"
#import "NCMBTwitterUtils.h"
#import "NCMBSubclassing.h"
#import "NCMBAnalytics.h"

#if defined(__has_include)
#if __has_include(<FacebookSDK/FacebookSDK.h>)
#import "NCMBFacebookUtils.h"
#else
#define NCMBFacebookUtils Please_add_the_Facebook_iOS_SDK_3.2.1_to_your_Xcode_project
#endif
#endif


@interface NCMB : NSObject

/**
 アプリケーションキーとクライアントキーの設定
 @param applicationKey アプリケーションを一意に識別するキー
 @param clientKey APIを利用する際に必要となるキー
 */
+ (void)setApplicationKey:(NSString *)applicationKey clientKey:(NSString *)clientKey;

/**
アプリケーションキーの取得
 */
+ (NSString *)getApplicationKey;

/**
 クライアントキーの取得
 */
+ (NSString *)getClientKey;

/**
 レスポンスが改ざんされていないか判定する機能を有効にする<br/>
 デフォルトは無効です
 @param checkFlag true:有効, false:無効
 */
+ (void)enableResponseValidation:(BOOL)checkFlag;

/**
 レスポンバリデーションの設定状況を取得
 */
+ (BOOL)getResponseValidationFlag;

@end
