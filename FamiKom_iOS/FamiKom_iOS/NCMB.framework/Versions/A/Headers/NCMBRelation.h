//
//  NCMBRelation.h
//  NIFTY Cloud mobile backend
//
//  Created by NIFTY Corporation on 2013/04/19.
//  Copyright 2013 NIFTY Corporation All Rights Reserved.
//

#import <Foundation/Foundation.h>

@class NCMBObject;
@class NCMBQuery;

/**
 NCMBRelationは、オブジェクトの関係を管理するクラスです。
 */
@interface NCMBRelation : NSObject

/**
 リレーションで示されたオブジェクトのクラス名を指定してクエリを生成
 */
- (NCMBQuery *)query;

/**
 リレーションに指定したオブジェクトを追加
 @param object 指定するオブジェクト
 */
- (void)addObject:(NCMBObject *)object;

/**
 リレーションから指定したオブジェクトを削除
 @param object 指定するオブジェクト
 */
- (void)removeObject:(NCMBObject *)object;

@end
