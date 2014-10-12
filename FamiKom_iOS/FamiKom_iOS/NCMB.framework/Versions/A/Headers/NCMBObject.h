//
//  NCMBObject.h
//  NIFTY Cloud mobile backend
//
//  Created by NIFTY Corporation on 2013/04/17.
//  Copyright 2013 NIFTY Corporation All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import "NCMBConstants.h"

@class NCMBACL;
@class NCMBQuery;
@class NCMBRelation;

/**
 NCMBObjectクラスは、ニフティクラウドmobile backendとアプリ間のデータの送受信を管理するクラスです。アプリケーション内オブジェクトの取得・保存・削除などを管理するメインのクラスです。
 */
@interface NCMBObject : NSObject{
    NSMutableArray *operationSetQueue;
    NSMutableDictionary *estimatedData;
    NSMutableDictionary *serverData;
}

/** @name Create */

/**
 クラス名を指定してNCMBObjectのインスタンスを生成
 @param className 指定するクラス名
 */
+ (NCMBObject *)objectWithClassName:(NSString *)className;

/**
 クラス名とデータを指定してNCMBObjectのインスタンスを生成
 @param className 指定するクラス名
 @param attrs 設定するデータ内容
 */
+ (NCMBObject *)objectWithClassName:(NSString *)className
                            attrs:(NSDictionary *)attrs;

/**
 クラス名とobjectIdを指定してNCMBObjecrtのインスタンスを生成
 @param className 指定するクラス名
 @param objectId 指定するObjectId
 */
+ (NCMBObject *)objectWithoutDataWithClassName:(NSString *)className
                                    objectId:(NSString *)objectId;


/**
 クラス名を指定してNCMBObjectのインスタンスを生成
 
 【使用例】
 NCMBObject *testObject = [[NCMBObject alloc]initWithClassName:@"クラス名"];
 @param className 指定するクラス名
 */
- (id)initWithClassName:(NSString *)className;

/** @name Object */

/// objectId オブジェクトのobjectID（ニフティクラウドmobile backend上で自動的に生成）
@property (nonatomic, retain) NSString *objectId;

/// updatedAt オブジェクトの更新日時
@property (nonatomic, retain, readonly) NSDate *updatedAt;

/// createdAt オブジェクトの登録日時
@property (nonatomic, retain, readonly) NSDate *createdAt;

/// ACL オブジェクトのアクセス権限情報
@property (nonatomic, retain) NCMBACL *ACL;

/// ncmbClassName オブジェクトのクラス名
@property (readonly) NSString *ncmbClassName;

/**
 オブジェクトのキーを取得。createdAt、updatedAt、objectIdは含まれない。
 */
- (NSArray *)allKeys;

/**
 キーで指定した値を取得
 @param key 指定するキー
 */
- (id)objectForKey:(NSString *)key;

/**
 キーで指定した値の取得。
 @param key 指定するキー
 */
- (id)objectForKeyedSubscript:(NSString *)key;

/**
 指定したキーに指定したオブジェクトを設定
 @param object 設定するオブジェクト
 @param key 指定するキー
 */
- (void)setObject:(id)object forKey:(NSString *)key;

/**
 指定したキーにオブジェクトを設定。
 @param object 設定するオブジェクト
 @param key 指定するキー
 */
- (void)setObject:(id)object forKeyedSubscript:(NSString *)key;


/**
 指定したキーのリレーションを取得
 @param key 指定するキー
 */
- (NCMBRelation *)relationforKey:(NSString *)key;


/**
 キーで指定された配列の末尾にオブジェクトを追加
 @param object 追加するオブジェクト
 @param key 追加する配列のキー
 */
- (void)addObject:(id)object forKey:(NSString *)key;

/**
 キーで指定された配列の末尾に複数のオブジェクトを追加
 @param objects 追加する複数のオブジェクト
 @param key 追加する配列のキー
 */
- (void)addObjectsFromArray:(NSArray *)objects forKey:(NSString *)key;

/**
 キーで指定した配列に指定したオブジェクトを追加。オブジェクトの順序は保証されません。また、追加したオブジェクトが配列内に既に存在した場合は追加されません。
 @param object 追加するオブジェクト
 @param key 追加する配列のキー
 */
- (void)addUniqueObject:(id)object forKey:(NSString *)key;

/**
 キーで指定した配列に指定した複数のオブジェクトを追加。オブジェクトの順序は保証されません。また、追加したオブジェクトが配列内に既に存在した場合は追加されません。
 @param objects 追加する複数のオブジェクト
 @param key 追加する配列のキー
 */
- (void)addUniqueObjectsFromArray:(NSArray *)objects forKey:(NSString *)key;

/**
 指定したキーに設定された値から、指定されたオブジェクトを削除
 @param object 削除するオブジェクト
 @param key 指定するキー
 */
- (void)removeObject:(id)object forKey:(NSString *)key;

/**
 指定したキーに設定された値から、指定された配列に含まれるオブジェクトと一致するものを削除
 @param objects 削除する複数のオブジェクト
 @param key 指定するキー
 */
- (void)removeObjectsInArray:(NSArray *)objects forKey:(NSString *)key;


/**
 指定したキーに設定された値を全て削除
 @param key 指定するキー
 */
-(void)removeObjectForKey:(NSString *)key;



/**
 指定したキーの値に１を足す。未登録のものは新規登録される。デフォルト値は１。
 @param key 指定するキー
 */
- (void)incrementKey:(NSString *)key;

/**
 指定したキーの値にamountで指定した増減値を加える。未登録のものは新規登録される。デフォルトは０に増減値を加えた値になる。
 @param key 指定するキー
 @param amount 増減値
 */
- (void)incrementKey:(NSString *)key byAmount:(NSNumber *)amount;


/** @name Save */

/**
 オブジェクトを保存
  */
- (BOOL)save;

/**
 オブジェクトを保存。必要があればエラーをセットし、取得することもできる。
 @param error 処理中に起きたエラーのポインタ
 
*/
- (BOOL)save:(NSError **)error;


/**
 オブジェクトを非同期で保存
*/
- (void)saveInBackground;


/**
 オブジェクトを非同期で保存。取得し終わったら与えられたblockを呼び出す。
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある（BOOL succeeded, NSError *error）
 succeededには保存完了の有無がBOOL型で渡される。errorにはエラーがなければnilが渡される。
*/
- (void)saveInBackgroundWithBlock:(NCMBBooleanResultBlock)block;



/**
 オブジェクトを非同期で保存。取得し終わったら指定されたコールバックを呼び出す。
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。 (void)callbackWithResult:(NSNumber )result error:(NSError )error
 resultには保存完了の有無をNSNumber型で渡される。errorにはエラーがなければnilが渡される。
*/
- (void)saveInBackgroundWithTarget:(id)target selector:(SEL)selector;



/**
 オブジェクトを保存。通信できない場合は、次回オンライン時に保存される。
 保存処理が完了前にアプリが終了した場合は、次回アプリ起動後オンライン時に保存される。
*/
- (void)saveEventually;


/**
 オブジェクトを保存。通信できない場合は、次回オンライン時に保存される。
 保存処理が完了前にアプリが終了した場合は、次回アプリ起動後オンライン時に保存される。
 保存し終わったら指定されたコールバックを呼び出す。
 @param callback 通信後実行されるcallback。callbackは次の引数のシグネチャを持つ必要がある（BOOL succeeded, NSError *error）
 succeededには保存完了の有無がBOOL値で渡される。errorにはエラーがなければnilが渡される。
*/
- (void)saveEventually:(NCMBBooleanResultBlock)callback;



/** @name Save All */

/**
 全てのオブジェクトを保存
 
 @warning saveAll系メソッドでは、引数であるobjectsにはそのクラスのインスタンスのみが格納されます。
 @param objects NCMBObjectを継承したインスタンスを格納した配列
 */
+ (BOOL)saveAll:(NSArray *)objects;


/**
 全てのオブジェクトを保存。必要があればエラーをセットし、取得することもできる。
 @param objects NCMBObjectを継承したインスタンスを格納した配列
 @param error 処理中に起きたエラーのポインタ
*/
+ (BOOL)saveAll:(NSArray *)objects error:(NSError **)error;



/**
 全てのオブジェクトを非同期で保存
 @param objects NCMBObjectを継承したインスタンスを格納した配列
*/
+ (void)saveAllInBackground:(NSArray *)objects;


/**
 全てのオブジェクトを非同期で保存。保存し終わったら与えられたblockを呼び出す。
 @param objects NCMBObjectを継承したインスタンスを格納した配列
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある（BOOL succeeded, NSError *error）
 succeededには保存完了の有無がBOOL型で渡される。errorにはエラーがなければnilが渡される。
*/
+ (void)saveAllInBackground:(NSArray *)objects
                      block:(NCMBBooleanResultBlock)block;



/**
 全てのオブジェクトを非同期で保存。保存し終わったら指定されたコールバックを呼び出す。
 @param objects NCMBObjectを継承したインスタンスを格納した配列
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。 (void)callbackWithError:(NSError *)error
 errorにはエラーがなければnilが渡される。
 */
+ (void)saveAllInBackground:(NSArray *)objects target:(id)target selector:(SEL)selector;


/** @name Get */

/**
 既存オブジェクトに対して、データが取得されたかどうかを判定。
 false：クラス名とobjectIDのみ指定された既存オブジェクトに対してデータがない場合
 */
- (BOOL)isDataAvailable;


/**
 オブジェクトの再取得
  */
- (void)refresh;


/**
 オブジェクトの再取得。必要があればエラーをセットし、取得することもできる。
 @param error 処理中に起きたエラーのポインタ
*/
- (void)refresh:(NSError **)error;


/**
 オブジェクトを非同期で再取得。取得し終わったら与えられたblockを呼び出す。
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある（NCMBObject *object, NSError *error）
 objectには取得したオブジェクトが渡される。errorにはエラーがなければnilが渡される。
*/
- (void)refreshInBackgroundWithBlock:(NCMBObjectResultBlock)block;


/**
 オブジェクトを非同期で再取得。取得し終わったら指定されたコールバックを呼び出す。
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。 (void)callbackWithResult:(NCMBObject)refreshedObject error:(NSError )error
 refreshedObjectには更新したオブジェクトが渡される。errorにはエラーがなければnilが渡される。
*/
- (void)refreshInBackgroundWithTarget:(id)target selector:(SEL)selector;



/**
 オブジェクトの取得
*/
- (void)fetch;


/**
 オブジェクトの取得。必要があればエラーをセットし、取得することもできる。
 @param error 処理中に起きたエラーのポインタ
*/
- (void)fetch:(NSError **)error;


/**
 オブジェクトを非同期で取得。取得し終わったら与えられたblockを呼び出す。
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある（NCMBObject *object, NSError *error）
 objectには取得したオブジェクトが渡される。errorにはエラーがなければnilが渡される。
 */
- (void)fetchInBackgroundWithBlock:(NCMBObjectResultBlock)block;


/**
 オブジェクトを非同期で取得。取得し終わったら指定されたコールバックを呼び出す。
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。(void)callbackWithResult:(NCMBObject) fetchedObject error:(NSError )error
 fetchedObjectには取得した配列が渡される。errorにはエラーがなければnilが渡される。
*/
- (void)fetchInBackgroundWithTarget:(id)target selector:(SEL)selector;


/**
 オブジェクトを取得（isDataAvailableがfalseの場合のみサーバから取得）
 */
- (NCMBObject *)fetchIfNeeded;


/**
 オブジェクトを取得（isDataAvailableがfalseの場合のみサーバから取得）。必要があればエラーをセットし、取得することもできる。
 @param error 処理中に起きたエラーのポインタ
  */
- (NCMBObject *)fetchIfNeeded:(NSError **)error;


/**
 オブジェクトを非同期で取得（isDataAvailableがfalseの場合のみサーバから取得）。取得し終わったら与えられたblockを呼び出す。
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある（NCMBObject *object, NSError *error）
 objectsには取得された配列が渡される。errorにはエラーがなければnilが渡される。
 */
- (void)fetchIfNeededInBackgroundWithBlock:(NCMBObjectResultBlock)block;


/**
 オブジェクトを非同期で取得（isDataAvailableがfalseの場合のみサーバから取得）。取得し終わったら指定されたコールバックを呼び出す。
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。(void)callbackWithResult:(NCMBObject) fetchedObject error:(NSError )error
 fetchedObjectsには取得された配列が渡される。errorにはエラーがなければnilが渡される。
  */
- (void)fetchIfNeededInBackgroundWithTarget:(id)target
                                   selector:(SEL)selector;


/** @name Get All */

/**
 全てのオブジェクトを取得
  @param objects NCMBObjectを継承したインスタンスを格納した配列
*/
+ (void)fetchAll:(NSArray *)objects;


/**
 全てのオブジェクトを取得。必要があればエラーをセットし、取得することもできる。
 @param objects NCMBObjectを継承したインスタンスを格納した配列
 @param error 処理中に起きたエラーのポインタ
*/
+ (void)fetchAll:(NSArray *)objects error:(NSError **)error;


/**
 全てのオブジェクトを非同期で取得。取得し終わったら与えられたblockを呼び出す。
 @param objects NCMBObjectを継承したインスタンスを格納した配列
 @param block 通信後実行されるblock。blockは次の引数のシグネチャを持つ必要がある（NSArray *objects, NSError *error）
 objectsには取得した配列が渡される。errorにはエラーがなければnilが渡される。
*/
+ (void)fetchAllInBackground:(NSArray *)objects
                       block:(NCMBArrayResultBlock)block;

/**
 全てのオブジェクトを非同期で取得。取得し終わったら指定されたコールバックを呼び出す。
 @param objects NCMBObjectを継承したインスタンスを格納した配列
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。(void)callbackWithResult:(NSArray )fetchedObjects error:(NSError )error
 fetchedObjectsには取得した配列が渡される。errorにはエラーがなければnilが渡される。
*/
+ (void)fetchAllInBackground:(NSArray *)objects
                      target:(id)target
                    selector:(SEL)selector;


/**
 全てのオブジェクトを取得。（各オブジェクトのisDataAvailableがfalseの場合のみサーバから取得）
 @param objects NCMBObjectを継承したインスタンスを格納した配列
  */
+ (void)fetchAllIfNeeded:(NSArray *)objects;

/**
 全てのオブジェクトを取得（各オブジェクトのisDataAvailableがfalseの場合のみサーバから取得）。必要があればエラーをセットし、取得することもできる。
 @param objects NCMBObjectを継承したインスタンスを格納した配列
 @param error 処理中に起きたエラーのポインタ
 */
+ (void)fetchAllIfNeeded:(NSArray *)objects error:(NSError **)error;



/**
 全てのオブジェクトを非同期で取得（各オブジェクトのisDataAvailableがfalseの場合のみサーバから取得）。取得し終わったら与えられたblockを呼び出す。
 @param objects NCMBObjectを継承したインスタンスを格納した配列
 @param block 通信後に実行されるblock。blockは次の引数のシグネチャを持つ必要がある（NSArray *objects, NSError *error）
 objectsには取得した配列が渡される。errorにはエラーがなければnilが渡される。
 */
+ (void)fetchAllIfNeededInBackground:(NSArray *)objects block:(NCMBArrayResultBlock)block;


/**
 全てのオブジェクトを非同期で取得（各オブジェクトのisDataAvailableがfalseの場合のみサーバから取得）。取得し終わったら指定されたコールバックを呼び出す。
 @param objects NCMBObjectを継承したインスタンスを格納した配列
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。(void)コールバックWithResult:(NSArray )fetchedObjects error:(NSError )error
 fetchedObjectsには取得した配列が渡される。errorにはエラーがなければnilが渡される。*/
+ (void)fetchAllIfNeededInBackground:(NSArray *)objects target:(id)target selector:(SEL)selector;


/** @name Delete */

/**
 オブジェクトを削除
*/
- (BOOL)delete;

/**
 オブジェクトを削除。必要があればエラーをセットし、取得することもできる。
 @param error 処理中に起きたエラーのポインタ
*/
- (BOOL)delete:(NSError **)error;


/**
 オブジェクトを非同期で削除
 */
- (void)deleteInBackground;


/**
 オブジェクトを非同期で削除。削除し終わったら与えられたblockを呼び出す。
 @param block 通信後に実行されるblock。blockは次の引数のシグネチャを持つ必要がある (BOOL succeeded, NSError *error)
 succeededには削除完了の有無がBOOL型で渡される。errorにはエラーがなければnilが渡される。
*/
- (void)deleteInBackgroundWithBlock:(NCMBBooleanResultBlock)block;


/**
 オブジェクトを非同期で削除。削除し終わったら指定されたコールバックを呼び出す。
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。 (void)callbackWithResult:(NSNumber )result error:(NSError )error
 resultには削除完了の有無をNSNumber型で渡される。errorにはエラーがなければnilが渡される。
*/
- (void)deleteInBackgroundWithTarget:(id)target
                            selector:(SEL)selector;


/**
 オブジェクトを削除。通信できない場合は、次回オンライン時に削除される。
 削除処理が完了前にアプリが終了した場合は、次回アプリ起動後オンライン時に削除される。
 */
- (void)deleteEventually;



@end
