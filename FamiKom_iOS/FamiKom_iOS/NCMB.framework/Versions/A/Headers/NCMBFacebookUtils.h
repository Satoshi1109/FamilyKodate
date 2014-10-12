//
//  NCMBFacebookUtils.h
//  NIFTY Cloud mobile backend
//
//  Created by NIFTY Corporation on 2013/04/18.
//  Copyright 2013 NIFTY Corporation All Rights Reserved.
//


#import <Foundation/Foundation.h>
#import "NCMBConstants.h"
#import <FacebookSDK/FBSession.h>

@class NCMBUser;

@class FBSession;

typedef int NCMBSessionDefaultAudience;

/**
 NCMBFacebookUtilsクラスは、Facebook連携の機能を提供するクラスです。
 */
@interface NCMBFacebookUtils : NSObject


/**
 FBSessionの取得
 */
+ (FBSession *)session;

/**
 Facebookの初期化
 */
+ (void)initializeFacebook;

/**
 urlSchemeSuffixを指定し、Facebookの初期化
 @param urlSchemeSuffix アプリケーションのURL Suffix。１つのFacebookAppIDを複数のアプリケーションで使用する場合に用いる。
 */
+ (void)initializeFacebookWithUrlSchemeSuffix:(NSString *)urlSchemeSuffix;

/**
 指定したユーザがfacebook連携されているかを判断。facebook連携されている場合はtureを返す。
 @param user 指定するユーザ
 */
+ (BOOL)isLinkedWithUser:(NCMBUser *)user;

/**
 facebookを利用してユーザログイン。ログインし終わったら与えられたblockを呼び出す。
 @param permissions ログイン時に要求するパーミッション
 @param block ログイン後実行されるblock。blockは次の引数のシグネチャを持つ必要がある （NCMBUser *user, NSError *error）userにはログインしたユーザ情報が渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)logInWithPermissions:(NSArray *)permissions block:(NCMBUserResultBlock)block;

/**
 facebookを利用してユーザログイン。ログインし終わったら指定されたコールバックを呼び出す。
 @param permissions ログイン時に要求するパーミッション
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。 (void)callbackWithResult:(NCMBUser *)user error:(NSError **)error
 userにはログインしたユーザ情報が渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)logInWithPermissions:(NSArray *)permissions target:(id)target selector:(SEL)selector;

/**
 facebookを利用してユーザログイン。ログインし終わったら与えられたblockを呼び出す。
 @param facebookId ログインさせるFacebookアカウントのfacebookID
 @param accessToken ログインさせるFacebookアカウントのaccessToken
 @param expirationDate ログインさせるFacebookアカウントのaccessToken有効期限
 @param block ログイン後実行されるblock。blockは次の引数のシグネチャを持つ必要がある （NCMBUser *user, NSError *error）userにはログインしたユーザ情報が渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)logInWithFacebookId:(NSString *)facebookId
                accessToken:(NSString *)accessToken
             expirationDate:(NSDate *)expirationDate
                      block:(NCMBUserResultBlock)block;

/**
 facebookを利用してユーザログイン。ログインし終わったら指定されたコールバックを呼び出す。
 @param facebookId ログインさせるFacebookアカウントのfacebookID
 @param accessToken ログインさせるFacebookアカウントのaccessToken
 @param expirationDate ログインさせるFacebookアカウントのaccessToken有効期限
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。 (void)callbackWithResult:(NCMBUser *)user error:(NSError **)error
 userにはログインしたユーザ情報が渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)logInWithFacebookId:(NSString *)facebookId
                accessToken:(NSString *)accessToken
             expirationDate:(NSDate *)expirationDate
                     target:(id)target
                   selector:(SEL)selector;

/**
 指定したユーザにfacebook連携情報をリンクさせる
 @param user 指定するユーザ
 @param permissions ログイン時に要求するパーミッション
 */
+ (void)linkUser:(NCMBUser *)user permissions:(NSArray *)permissions;

/**
 指定したユーザにfacebook連携情報をリンクさせる。リンクし終わったら与えられたblockを呼び出す。
 @param user 指定するユーザ
 @param permissions ログイン時に要求するパーミッション
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある （BOOL succeeded, NSError *error）succeededにはリンクの有無がBOOL型で渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)linkUser:(NCMBUser *)user permissions:(NSArray *)permissions block:(NCMBBooleanResultBlock)block;

/**
 指定したユーザにfacebook連携情報をリンクさせる。リンクし終わったら指定されたコールバックを呼び出す。
 @param user 指定するユーザ
 @param permissions ログイン時に要求するパーミッション
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。 (void)callbackWithResult:(NSNumber *)result error:(NSError **)error
 resultにはリンクの有無をNSNumber型で渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)linkUser:(NCMBUser *)user permissions:(NSArray *)permissions target:(id)target selector:(SEL)selector;


/**
 指定したユーザにfacebook連携情報をリンクさせる。リンクし終わったら与えられたblockを呼び出す。
 @param user 指定するユーザ
 @param facebookId ユーザにリンクさせるID
 @param accessToken ユーザにリンクさせるaccessToken
 @param expirationDate ユーザにリンクさせるaccessTokenの有効期限
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある （BOOL succeeded, NSError *error）succeededにはリンクの有無がBOOL型で渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)linkUser:(NCMBUser *)user
      facebookId:(NSString *)facebookId
     accessToken:(NSString *)accessToken
  expirationDate:(NSDate *)expirationDate
           block:(NCMBBooleanResultBlock)block;

/**
 指定したユーザにfacebook連携情報をリンクさせる。リンクし終わったら指定されたコールバックを呼び出す。
 @param user 指定するユーザ
 @param facebookId ユーザにリンクさせるID
 @param accessToken ユーザにリンクさせるaccessToken
 @param expirationDate ユーザにリンクさせるaccessTokenの有効期限
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。 (void)callbackWithResult:(NSNumber *)result error:(NSError **)error
 resultにはリンクの有無をNSNumber型で渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)linkUser:(NCMBUser *)user
      facebookId:(NSString *)facebookId
     accessToken:(NSString *)accessToken
  expirationDate:(NSDate *)expirationDate
          target:(id)target
        selector:(SEL)selector;


/**
 指定したユーザとfacebookのリンクを解除
 @param user 指定するユーザ
 */
+ (BOOL)unlinkUser:(NCMBUser *)user;

/**
 指定したユーザとfacebookのリンクを解除。必要があればエラーをセットし、取得することもできる。
 @param user 指定するユーザ
 @param error 処理中に起きたエラーのポインタ
 */
+ (BOOL)unlinkUser:(NCMBUser *)user error:(NSError **)error;

/**
 指定したユーザとfacebookのリンクを非同期で解除
 @param user 指定するユーザ
 */
+ (void)unlinkUserInBackground:(NCMBUser *)user;

/**
 指定したユーザとfacebookのリンクを解除。リンク解除し終わったら与えられたblockを呼び出す。
 @param user 指定するユーザ
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある （BOOL succeeded, NSError *error）succeededにはリンク解除の有無がBOOL型で渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)unlinkUserInBackground:(NCMBUser *)user block:(NCMBBooleanResultBlock)block;

/**
 指定したユーザとfacebookのリンクを解除。リンク解除し終わったら指定されたコールバックを呼び出す。
 @param user 指定するユーザ
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。 (void)callbackWithResult:(NSNumber *)result error:(NSError **)error
 resultにはリンク解除の有無をNSNumber型で渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)unlinkUserInBackground:(NCMBUser *)user target:(id)target selector:(SEL)selector;


/**
 指定ユーザのfacebook投稿権限の取得。取得し終わったら与えられたblockを呼び出す。
 @param user 指定するユーザ
 @param permissions 要求するPublishPermissions
 @param audience 投稿の公開範囲
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある （BOOL succeeded, NSError *error）succeededには取得の有無がBOOL型で渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)reauthorizeUser:(NCMBUser *)user
 withPublishPermissions:(NSArray *)permissions
               audience:(NCMBSessionDefaultAudience)audience
                  block:(NCMBBooleanResultBlock)block;

/**
 指定ユーザのfacebook投稿権限の取得。取得し終わったら指定されたコールバックを呼び出す。
 @param user 指定するユーザ
 @param permissions 要求するPublishPermissions
 @param audience 投稿の公開範囲
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。 (void)callbackWithResult:(NSNumber *)result error:(NSError **)error
 resultには取得の有無をNSNumber型で渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)reauthorizeUser:(NCMBUser *)user
 withPublishPermissions:(NSArray *)permissions
               audience:(NCMBSessionDefaultAudience)audience
                 target:(id)target
               selector:(SEL)selector;

/**
 facebook認証情報の処理を行います。
 AppDelegateでapplication:handleOpenURL:メソッドもしくは、application:openURL:sourceApplication:annotationメソッドにより取得したurl内のアクセストークンを用い、APIを呼び出す処理を行います。
 @param url ユーザの認証情報
 */
+ (BOOL)handleOpenURL:(NSURL *)url;

@end
