//
//  NCMBSubclassing.h
//  NIFTY Cloud mobile backend
//
//  Created by NIFTY Corporation on 2013/06/13.
//  Copyright 2013 NIFTY Corporation All Rights Reserved.
//

#import <Foundation/Foundation.h>

@class NCMBQuery;

/**
 NCMBSubclassingに準拠したNCMBObjectのサブクラスは、registerSubclassメソッドを呼び出すことで、
 ニフティクラウドmobile backendのオブジェクトとして、使用することができます。
 */
@protocol NCMBSubclassing <NSObject>

/**
 オブジェクトを生成
 */
+ (id)object;

/**
 指定したobjectIdでオブジェクトを生成
 @param objectId 生成するオブジェクトのobjectIdを指定
 */
+ (id)objectWithoutDataWithObjectId:(NSString *)objectId;

/**
 クラス名を取得
 */
+ (NSString *)ncmbClassName;

/**
 設定されているクラスを対象として検索するためのNCMBQueryを生成
 */
+ (NCMBQuery *)query;

/**
 サブクラスの登録 setApplicationKey:clientKey:の前にこのメソッドを呼んで下さい。
 */
+ (void)registerSubclass;

@end
