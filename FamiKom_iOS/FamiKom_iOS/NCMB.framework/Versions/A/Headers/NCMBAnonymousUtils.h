//
//  NCMBAnonymousUtils.h
//  NIFTY Cloud mobile backend
//
//  Created by NIFTY Corporation on 2013/04/19.
//  Copyright 2013 NIFTY Corporation All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import "NCMBConstants.h"

@class NCMBUser;

/**
 NCMBAnonymousUtilsクラスは、匿名ユーザでのログインを管理しているクラスです。
 
 匿名ユーザには、下記のようないくつかの規則があります。
 
 ・匿名ユーザは、ユーザ名とパスワードなしでログインできます。

 ・一度ログアウトした場合は、匿名ユーザを復元することはできません。
 
 ・currentUserが匿名の場合、以下の(1)～(3)のように別のユーザに切り替えたり、正式なアカウントに変更します。
 
   (1)signUpは、ユーザ名とパスワードが与えられ、匿名ユーザから正式アカウントへ移行させます。その際、匿名ユーザ時のデータは保存されます。
 
   (2)ログインは、匿名ユーザ自体は変わらず、ユーザを変更します。この際、匿名ユーザのデータは失われます。
 
   (3)Facebook、twitterによるログインは、リンクさせることでFacebookやtwitter情報を用い、匿名ユーザから正式アカウントへ移行します。すでにリンクされている場合は、登録してある既存ユーザに切り替えます。
 */
@interface NCMBAnonymousUtils : NSObject

/**
 匿名ユーザでログイン。ログインし終わったら与えられたblockを呼び出す。
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある（NCMBUser *user, NSError *errorr） userにはログインしたユーザの情報が渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)logInWithBlock:(NCMBUserResultBlock)block;

/**
匿名ユーザでログイン。ログインし終わったら指定されたコールバックを呼び出す。
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。(void)callbackWithResult:(NCMBUser *)user error:(NSError **)error
 userにはログインしたユーザの情報が渡される。errorにはエラーがあればエラーのポインタが、なければnilが渡される。
 */
+ (void)logInWithTarget:(id)target selector:(SEL)selector;

/**
 指定したユーザが匿名ユーザかどうか判断。匿名ユーザの場合はtrueを返す。
 @param user 指定するユーザ
 */
+ (BOOL)isLinkedWithUser:(NCMBUser *)user;

@end
