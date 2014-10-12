//
//  NCMBRole.h
//  NIFTY Cloud mobile backend
//
//  Created by NIFTY Corporation on 2013/04/17.
//  Copyright 2013 NIFTY Corporation All Rights Reserved.
//

#import "NCMBObject.h"
#import "NCMBSubclassing.h"

@class NCMBACL;
@class NCMBRelation;
@class NCMBQuery;

/**
 NCMBRoleは、ユーザーに付与する役割を管理するクラスです。主にACLで利用します。
  */
@interface NCMBRole : NCMBObject<NCMBSubclassing>

/** @name Properties */

/// ロール名の設定。ロール名はロールを保存する前に設定する必要があり、保存後は変更不可。
@property (nonatomic, copy) NSString *name;

/// ユーザのリレーション
@property (nonatomic, readonly, retain) NCMBRelation *users;

/// ロールのリレーション
@property (nonatomic, readonly, retain) NCMBRelation *roles;

/** @name Create */

/**
 ロール名を指定してNCMBRoleのインスタンスを初期化
 @param name NCMBBRoleのインスタンス名
 */
- (id)initWithName:(NSString *)name;

/**
 ロール名とACLを指定してNCMBRoleのインスタンスを初期化
 @param name NCMBBRoleのインスタンス名
 @param acl 指定する権限情報
 */
- (id)initWithName:(NSString *)name acl:(NCMBACL *)acl;

/**
 ロール名を指定してNCMBRoleのインスタンスを生成
 @param name NCMBRoleのインスタンス名
 */
+ (NCMBRole *)roleWithName:(NSString *)name;

/**
 ロール名とNCMBACLを指定してNCMBRoleを生成
 @param name NCMBRoleのインスタンス名
 @param acl 指定する権限情報
 */
+ (NCMBRole *)roleWithName:(NSString *)name acl:(NCMBACL *)acl;


/** @name Query */

/**
 ロールを検索するためのNCMBQueryを生成
 */
+ (NCMBQuery *)query;

@end
