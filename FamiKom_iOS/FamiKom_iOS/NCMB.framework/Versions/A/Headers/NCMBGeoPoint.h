//
//  NCMBGeoPoint.h
//  NCMB
//
//  Created by NIFTY Corporation. on 2013/11/29.
//  Copyright (c) 2013年 NIFTY Corporation. All rights reserved.
//

#import "NCMBObject.h"
#import "NCMBSubclassing.h"
#import <CoreLocation/CoreLocation.h>

@class CLLocation;
/**
 NCMBGeoPointクラスは、ニフティクラウドmobile backend上でアプリに必要な位置情報を管理するクラスです。
*/
@interface NCMBGeoPoint : NSObject <CLLocationManagerDelegate>

/** @name Properties */

/// 緯度
@property (nonatomic, readwrite) double latitude;

/// 経度
@property (nonatomic, readwrite) double longitude;


/** @name Create */

/**
 NCMBGeoPointオブジェクトを作成。緯度、経度には0.0が設定される。
 */
+ (NCMBGeoPoint *)geoPoint;

/**
 NCMBGeoPointオブジェクトを作成。緯度、経度には引数のCLLocationが示す値が設定される。
 @param location 位置情報
 */
+ (NCMBGeoPoint *)geoPointWithLocation:(CLLocation *) location;

/**
 NCMBGeoPointオブジェクトを作成。緯度、経度には引数の値が設定される。
 @param latitude 緯度
 @param longitude 経度
 */
+ (NCMBGeoPoint *)geoPointWithLatitude:(double) latitude longitude:(double)longitude;

/**
 NCMBGeoPointオブジェクトを非同期で作成。緯度、経度にはGPS等で取得した端末の現在位置が設定される。
 @param geoPointHandler geoPointとerrorのHandler
 */
+ (void)geoPointForCurrentLocationInBackground:(void(^)(NCMBGeoPoint *geoPoint, NSError *error))geoPointHandler;

@end
