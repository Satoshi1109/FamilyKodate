//
//  NCMBPush.h
//  NIFTY Cloud mobile backend
//
//  Created by NIFTY Corporation on 2013/04/19.
//  Copyright 2013 NIFTY Corporation All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import "NCMBConstants.h"
#import "NCMBObject.h"
#import "NCMBSubclassing.h"

#define __deprecated_msg(_msg) __attribute__((deprecated(_msg)))

@class NCMBQuery;
@class NCMBACL;

/**
 NCMBPushクラスは、プッシュ通知を管理するクラスです。
 
 デバイスのチャネル情報の取得や変更などを行う際は、NCMBInstallationクラスより、NCMBPuchのクラスメソッドを使用するのが適切です。
 */
@interface NCMBPush : NCMBObject<NCMBSubclassing>

/** @name Create */

/**
 NCMBPushのインスタンスを生成
 */
+ (NCMBPush *)push;

/**
 プッシュ通知を送信するチャネルを設定
 @param channel プッシュ通知を送信するチャネル
 */
- (void)setChannel:(NSString *)channel;

/**
 プッシュ通知を送信する複数のチャネルを設定
 @param channels プッシュ通知を送信する複数のチャネルを格納した配列
 */
- (void)setChannels:(NSArray *)channels;

/**
 (非推奨:新たに利用する場合はsetSearchConditionを使いましょう)
 プッシュ通知の配信先となる配信端末を絞り込むためのクエリを設定
 @param query プッシュ先を絞り込むためのクエリ
 */
- (void)setQuery:(NCMBQuery *)query;

/**
 プッシュ通知の配信先となる配信端末を絞り込むためのクエリを設定
 @param query プッシュ先を絞り込むためのクエリ
 */
- (void)setSearchCondition:(NCMBQuery *)query;

/**
 プッシュ通知の配信先となる会員を絞り込むためのクエリを設定
 @param query プッシュ先を絞り込むためのクエリ
 */
//- (void)setUserSearchCondition:(NCMBQuery *)query;

/**
 プッシュ通知のメッセージ内容を設定
 @param message プッシュ通知のメッセージ内容
 */
- (void)setMessage:(NSString *)message;

/**
 プッシュ通知の内容を設定
 @param data プッシュ通知内容
 */
- (void)setData:(NSDictionary *)data;

/**
 Android端末でダイアログプッシュ通知を行う設定
 @param dialog ダイアログプッシュ通知を行う場合はtrueを設定。
 */
- (void)setDialog:(BOOL)dialog;

/**
 リッチプッシュ通知用のURLを設定
 @param url リッチプッシュ通知で表示するWebページのURL
 */
- (void)setRichUrl:(NSString *)url;

/**
 Androidへの配信設定
 @param pushToAndroid 配信設定。配信する場合はtrueを設定。
 */
- (void)setPushToAndroid:(BOOL)pushToAndroid;

/**
 iOSへの配信設定
 @param pushToIOS 配信設定。配信する場合はtrueを設定。
 */
- (void)setPushToIOS:(BOOL)pushToIOS;


/**
 プッシュ通知の有効期限を設定
 @param date プッシュ通知の有効期限
 */
- (void)expireAtDate:(NSDate *)date;

/**
 プッシュ通知配信日時から設定したインターバル後を有効期限に設定
 @param timeInterval 設定できる値は、時間単位で指定する場合は「n hour」(n=1～24）、日単位で指定する場合は「n day」（n=1～28）。
 */
- (void)expireAfterTimeInterval:(NSString*)timeInterval;

/**
 プッシュ通知の有効期限の削除
 */
- (void)clearExpiration;


/**
 ユーザの情報を設定。開発者が付与したい情報を設定することができる。ここで設定した値はプッシュ通知のペイロードから「com.nifty.Data」というキーで取得できる
 @param userSettingValue ユーザの情報
 */
- (void)setUserSettingValue:(NSDictionary *)userSettingValue;

/**
 プッシュ通知の配信日時を設定
 @param date プッシュ通知の配信日時
 */
- (void)setDeliveryTime:(NSDate *)date;

/**
 即時配信フラグを設定
 @param immediateDeliveryFlag 即時配信フラグ。即時配信にする場合はYESを設定。デフォルトはYES。
 */
- (void)setImmediateDeliveryFlag:(BOOL)immediateDeliveryFlag;

/**
 プッシュ通知内容を取得
 */
- (NSDictionary *)getData;



/** @name Send */

/**
 指定したチャネルにメッセージのみのプッシュ通知を送信。必要があればエラーをセットし、取得することもできる。
 @param channel プッシュ先のチャネル
 @param message メッセージ内容
 @param error 処理中に起きたエラーのポインタ
  */
+ (BOOL)sendPushMessageToChannel:(NSString *)channel
                     withMessage:(NSString *)message
                           error:(NSError **)error;

/**
 指定したチャネルに非同期でメッセージのみのプッシュ通知を送信。
 @param channel プッシュ先のチャネル
 @param message メッセージ内容
*/

+ (void)sendPushMessageToChannelInBackground:(NSString *)channel
                                 withMessage:(NSString *)message;

/**
 指定したチャネルに非同期でメッセージのみのプッシュ通知を送信。登録し終わったら与えられたblockを呼び出す。
 @param channel プッシュ先のチャネル
 @param message メッセージ内容
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある(BOOL succeeded, NSError *error)
 succeededには送信完了の有無がBOOL型で渡される。errorにはエラーがなければnilが渡される。
*/
+ (void)sendPushMessageToChannelInBackground:(NSString *)channel
                                 withMessage:(NSString *)message
                                       block:(NCMBBooleanResultBlock)block;

/**
 指定したチャネルに非同期でメッセージのみのプッシュ通知を送信。取得し終わったら指定されたcallbackを呼び出す。
 @param channel プッシュ先のチャネル
 @param message メッセージ内容
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。(void)callbackWithResult:(NSNumber )result error:(NSError )error
 resultには送信完了の有無をNSNumber型で渡される。errorにはエラーがなければnilが渡される。
*/
+ (void)sendPushMessageToChannelInBackground:(NSString *)channel
                                 withMessage:(NSString *)message
                                      target:(id)target
                                    selector:(SEL)selector;

/**
 指定したクエリを満たした配信端末にメッセージのみのプッシュ通知を送信。必要があればエラーをセットし、取得することもできる。
 @param query 指定するクエリ
 @param message メッセージ内容
 @param error 処理中に起きたエラーのポインタ
*/
+ (BOOL)sendPushMessageToQuery:(NCMBQuery *)query
                   withMessage:(NSString *)message
                         error:(NSError **)error;

/**
 指定したクエリを満たした配信端末に非同期でメッセージのみのプッシュ通知を送信
 @param query 指定するクエリ
 @param message メッセージ内容
*/
+ (void)sendPushMessageToQueryInBackground:(NCMBQuery *)query
                               withMessage:(NSString *)message;

/**
 指定したクエリを満たした配信端末に非同期でメッセージのみのプッシュ通知を送信。登録し終わったら与えられたblockを呼び出す。
 @param query 指定するクエリ
 @param message メッセージ内容
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある(BOOL succeeded, NSError *error)
 succeededには送信完了の有無がBOOL型で渡される。errorにはエラーがなければnilが渡される。
 */
+ (void)sendPushMessageToQueryInBackground:(NCMBQuery *)query
                               withMessage:(NSString *)message
                                     block:(NCMBBooleanResultBlock)block;


/**
 指定したチャネルにプッシュ通知を送信。必要があればエラーをセットし、取得することもできる。
 @param channel プッシュ先のチャネル
 @param data プッシュ通知内容
 @param error 処理中に起きたエラーのポインタ
*/
+ (BOOL)sendPushDataToChannel:(NSString *)channel
                     withData:(NSDictionary *)data
                        error:(NSError **)error;


/**
 指定したチャネルに非同期でプッシュ通知を送信。
 @param channel プッシュ先のチャネル
 @param data プッシュ通知内容
*/
+ (void)sendPushDataToChannelInBackground:(NSString *)channel
                                 withData:(NSDictionary *)data;


/**
 指定したチャネルに非同期でプッシュ通知を送信。登録し終わったら与えられたblockを呼び出す。
 @param channel プッシュ先のチャネル
 @param data プッシュ通知内容
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある(BOOL succeeded, NSError *error)
 succeededには送信完了の有無がBOOL型で渡される。errorにはエラーがなければnilが渡される。
*/
+ (void)sendPushDataToChannelInBackground:(NSString *)channel
                                 withData:(NSDictionary *)data
                                    block:(NCMBBooleanResultBlock)block;


/**
 指定したチャネルに非同期でプッシュ通知を送信。登録し終わったら指定されたcallbackを呼び出す。
 @param channel プッシュ先のチャネル
 @param data プッシュ通知内容
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。(void)callbackWithResult:(NSNumber )result error:(NSError )error
 resultには送信完了の有無をNSNumber型で渡される。errorにはエラーがなければnilが渡される。
*/
+ (void)sendPushDataToChannelInBackground:(NSString *)channel
                                 withData:(NSDictionary *)data
                                   target:(id)target
                                 selector:(SEL)selector;

/**
 指定したクエリを満たした配信端末にプッシュ通知を送信。必要があればエラーをセットし、取得することもできる。
 @param query 指定するクエリ
 @param data プッシュ通知内容
 @param error 処理中に起きたエラーのポインタ
*/
+ (BOOL)sendPushDataToQuery:(NCMBQuery *)query
                   withData:(NSDictionary *)data
                      error:(NSError **)error;

/**
 指定したクエリを満たした配信端末に非同期でプッシュ通知を送信。
 @param query 指定するクエリ
 @param data プッシュ通知内容
*/
+ (void)sendPushDataToQueryInBackground:(NCMBQuery *)query
                               withData:(NSDictionary *)data;

/**
 指定したクエリを満たした配信端末に非同期でプッシュ通知を送信。登録し終わったら与えられたblockを呼び出す。
 @param query 指定するクエリ
 @param data プッシュ通知内容
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある(BOOL succeeded, NSError *error)
 succeededには送信完了の有無がBOOL型で渡される。errorにはエラーがなければnilが渡される。
*/
+ (void)sendPushDataToQueryInBackground:(NCMBQuery *)query
                               withData:(NSDictionary *)data
                                  block:(NCMBBooleanResultBlock)block;

/**
 プッシュ通知を送信。必要があればエラーをセットし、取得することができる。
 @param error 処理中に起きたエラーのポインタ
*/
- (BOOL)sendPush:(NSError **)error;


/**
 プッシュ通知を非同期で送信。
*/
- (void)sendPushInBackground;

/**
 プッシュ通知を非同期で送信。登録し終わったら与えられたblockを呼び出す。
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある(BOOL succeeded, NSError *error)
 succeededには送信完了の有無がBOOL型で渡される。errorにはエラーがなければnilが渡される。
*/
- (void)sendPushInBackgroundWithBlock:(NCMBBooleanResultBlock)block;

/**
 プッシュ通知を非同期で送信。取得し終わったら指定されたcallbackを呼び出す。
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。(void)callbackWithResult:(NSNumber )result error:(NSError )error
 resultには送信完了の有無をNSNumber型で渡される。errorにはエラーがなければnilが渡される。
*/
- (void)sendPushInBackgroundWithTarget:(id)target selector:(SEL)selector;


/** @name Handling */

/**
 アプリ起動中にプッシュ通知内容を取得した場合、通知内容を表示する。
 @param userInfo プッシュ通知内容
 */
+ (void)handlePush:(NSDictionary *)userInfo;

/**
 アプリ起動中にプッシュ通知内容を取得した場合、Webページを表示する。
 @param userInfo プッシュ通知内容
 */
+ (void)handleRichPush:(NSDictionary *)userInfo;

/**
 プッシュ通知のデータを受け取り、Webページや画像を表示する
 @param userInfo .
 */
/*
+ (void)handleRichPush:(NSDictionary *)userInfo;
*/

/** @name Query */

/**
 クラス名を指定してクエリの生成
 */
+ (NCMBQuery *)query;

@end
