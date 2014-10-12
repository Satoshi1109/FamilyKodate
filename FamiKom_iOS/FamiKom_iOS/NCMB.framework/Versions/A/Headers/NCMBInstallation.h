//
//  NCMBInstallation.h
//  NIFTY Cloud mobile backend
//
//  Created by NIFTY Corporation on 2013/04/19.
//  Copyright 2013 NIFTY Corporation All Rights Reserved.
//
#import "NCMBObject.h"
#import "NCMBSubclassing.h"

@class NCMBQuery;

/**
 NCMBInstallationクラスは、プッシュ配信端末情報を管理し、プッシュ通知を送信するのに必要なデバイストークンを設定します。
 */
@interface NCMBInstallation : NCMBObject<NCMBSubclassing>

/** @name Current Installation */

/**
 アプリが動作している端末のNCMBInstallationを取得。
 */
+ (NCMBInstallation *)currentInstallation;

/**
 NSData型のデバイストークンを設定
 @param deviceTokenData デバイストークン
 */
- (void)setDeviceTokenFromData:(NSData *)deviceTokenData;


/** @name Properties */

/// deviceType 登録された端末の種類
@property (nonatomic, readonly, retain) NSString *deviceType;
/// installationId 配信端末ID
@property (nonatomic, readonly, retain) NSString *installationId;
/// deviceToken 登録された端末のデバイストークン
@property (nonatomic, retain) NSString *deviceToken;
/// badge バッジ数
@property (nonatomic, assign) NSInteger badge;
/// timeZone タイムゾーン
@property (nonatomic, readonly, retain) NSString *timeZone;
/// channels 登録されたチャネルリスト
@property (nonatomic, retain) NSArray *channels;

/** @name Query */

/**
 配信端末情報を検索するためのNCMBQueryを生成
 */
+ (NCMBQuery *)query;

@end
