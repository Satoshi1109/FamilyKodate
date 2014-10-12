//
//  NCMBTwitterUtils.h
//  NIFTY Cloud mobile backend
//
//  Created by NIFTY Corporation on 2013/04/18.
//  Copyright 2013 NIFTY Corporation All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import "NCMBConstants.h"

@class NCMBUser;


@interface NCMB_Twitter : NSObject

@property (nonatomic, copy) NSString *consumerKey;
@property (nonatomic, copy) NSString *consumerSecret;
@property (nonatomic, copy) NSString *authToken;
@property (nonatomic, copy) NSString *authTokenSecret;
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *screenName;

- (void)authorizeWithSuccess:(void (^)(void))success failure:(void (^)(NSError *error))failure cancel:(void (^)(void))cancel;
- (void)signRequest:(NSMutableURLRequest *)request;

@end


/**
 NCMBTwitterUtilsクラスは、Twitter連携の機能を提供するクラスです。
 */
@interface NCMBTwitterUtils : NSObject

/**
NCMB_Twitterオブジェクトの取得
 */
+ (NCMB_Twitter *)twitter;

/**
 twitterの初期化
 @param consumerKey twitterアプリのconsumerKey
 @param consumerSecret twitterアプリのconsumerSecret
 */
+ (void)initializeWithConsumerKey:(NSString *)consumerKey
                   consumerSecret:(NSString *)consumerSecret;

/**
 指定したユーザがtwitter連携されているかを判断。twitter連携されている場合は、trueを返す。
 @param user 指定するユーザ
 */
+ (BOOL)isLinkedWithUser:(NCMBUser *)user;

/**
 twitterを利用してユーザログイン。ログインし終わったら与えられたblockを呼び出す。
 @param block ログイン後実行されるblock。blockは次の引数のシグネチャを持つ必要がある （NCMBUser *user, NSError *error）userにはログインしたユーザ情報が渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)logInWithBlock:(NCMBUserResultBlock)block;

/**
 twitterを利用してユーザログイン。ログインし終わったら指定されたコールバックを呼び出す。
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。 (void)callbackWithResult:(NCMBUser *)user error:(NSError **)error
 userにはログインしたユーザ情報が渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)logInWithTarget:(id)target selector:(SEL)selector;

/**
 twitterを利用してユーザログイン。ログインし終わったら与えられたblockを呼び出す。
 @param twitterId ログインさせるtwitterアカウントのtwitterID
 @param screenName ログインさせるtwitterアカウントのscreenName
 @param authToken ログインさせるtwitterアカウントのaccessToken
 @param authTokenSecret ログインさせるtwitterアカウントのauthTokenSecret
 @param block ログイン後実行されるblock。blockは次の引数のシグネチャを持つ必要がある （NCMBUser *user, NSError *error）userにはログインしたユーザ情報が渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)logInWithTwitterId:(NSString *)twitterId
                screenName:(NSString *)screenName
                 authToken:(NSString *)authToken
           authTokenSecret:(NSString *)authTokenSecret
                     block:(NCMBUserResultBlock)block;

/**
 twitterを利用してユーザログイン。ログインし終わったら指定されたコールバックを呼び出す。
 @param twitterId ログインさせるtwitterアカウントのtwitterID
 @param screenName ログインさせるtwitterアカウントのscreenName
 @param authToken ログインさせるtwitterアカウントのaccessToken
 @param authTokenSecret ログインさせるtwitterアカウントのauthTokenSecret
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。 (void)callbackWithResult:(NCMBUser *)user error:(NSError **)error
 userにはログインしたユーザ情報が渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)logInWithTwitterId:(NSString *)twitterId
                screenName:(NSString *)screenName
                 authToken:(NSString *)authToken
           authTokenSecret:(NSString *)authTokenSecret
                    target:(id)target
                  selector:(SEL)selector;

/**
 指定したユーザにtwitter連携情報をリンクさせる。
 @param user 指定するユーザ
 */
+ (void)linkUser:(NCMBUser *)user;

/**
 指定したユーザにtwitter連携情報をリンクさせる。リンクし終わったら与えられたblockを呼び出す。
 @param user 指定するユーザ
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある （BOOL succeeded, NSError *error）succeededにはリンクの有無がBOOL型で渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)linkUser:(NCMBUser *)user block:(NCMBBooleanResultBlock)block;

/**
 指定したユーザにtwitter連携情報をリンクさせる。リンクし終わったら指定されたコールバックを呼び出す。
 @param user 指定するユーザ
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。 (void)callbackWithResult:(NSNumber *)result error:(NSError **)error
 resultにはリンクの有無をNSNumber型で渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)linkUser:(NCMBUser *)user
          target:(id)target
        selector:(SEL)selector;

/**
 指定したユーザにtwitter連携情報をリンクさせる。リンクし終わったら与えられたblockを呼び出す。
 @param user 指定するユーザ
 @param twitterId ユーザにリンクさせるtwitterアカウントのtwitterID
 @param screenName ユーザにリンクさせるtwitterアカウントのscreenName
 @param authToken ユーザにリンクさせるtwitterアカウントのaccessToken
 @param authTokenSecret ユーザにリンクさせるtwitterアカウントのauthTokenSecret
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある （BOOL succeeded, NSError *error）succeededにはリンクの有無がBOOL型で渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)linkUser:(NCMBUser *)user
       twitterId:(NSString *)twitterId
      screenName:(NSString *)screenName
       authToken:(NSString *)authToken
 authTokenSecret:(NSString *)authTokenSecret
           block:(NCMBBooleanResultBlock)block;

/**
指定したユーザにtwitter連携情報をリンクさせる。リンクし終わったら指定されたコールバックを呼び出す。
 @param user 指定するユーザ
 @param twitterId ユーザにリンクさせるtwitterアカウントのtwitterID
 @param screenName ユーザにリンクさせるtwitterアカウントのscreenName
 @param authToken ユーザにリンクさせるtwitterアカウントのaccessToken
 @param authTokenSecret ユーザにリンクさせるtwitterアカウントのauthTokenSecret
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。 (void)callbackWithResult:(NSNumber *)result error:(NSError **)error
 resultにはリンクの有無をNSNumber型で渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)linkUser:(NCMBUser *)user
       twitterId:(NSString *)twitterId
      screenName:(NSString *)screenName
       authToken:(NSString *)authToken
 authTokenSecret:(NSString *)authTokenSecret
          target:(id)target
        selector:(SEL)selector;

/**
 指定したユーザとtwitterのリンクを解除
 @param user 指定するユーザ
 */
+ (BOOL)unlinkUser:(NCMBUser *)user;

/**
 指定したユーザとtwitterのリンクを解除。必要があればエラーをセットし、取得することもできる。
 @param user 指定するユーザ
 @param error 処理中に起きたエラーのポインタ
 */
+ (BOOL)unlinkUser:(NCMBUser *)user error:(NSError **)error;

/**
 指定したユーザとtwitterのリンクを非同期で解除
 @param user 指定するユーザ
 */
+ (void)unlinkUserInBackground:(NCMBUser *)user;

/**
 指定したユーザとtwitterのリンクを解除。解除し終わったら与えられたblockを呼び出す。
 @param user 指定するユーザ
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある （BOOL succeeded, NSError *error）succeededにはリンク解除の有無がBOOL型で渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)unlinkUserInBackground:(NCMBUser *)user
                         block:(NCMBBooleanResultBlock)block;

/**
 指定したユーザとtwitterのリンクを解除する。解除し終わったら指定されたコールバックを呼び出す。
 @param user 指定するユーザ
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。 (void)callbackWithResult:(NSNumber *)result error:(NSError **)error
 resultにはリンク解除の有無をNSNumber型で渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)unlinkUserInBackground:(NCMBUser *)user
                        target:(id)target selector:(SEL)selector;

@end
