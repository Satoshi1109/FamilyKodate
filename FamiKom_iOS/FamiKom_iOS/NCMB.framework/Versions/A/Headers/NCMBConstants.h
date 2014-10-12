//
//  NCMBConstants.h
//  NIFTY Cloud mobile backend
//
//  Created by NIFTY Corporation on 2013/04/19.
//  Copyright 2013 NIFTY Corporation All Rights Reserved.
//

#import <Foundation/Foundation.h>

@class NCMBUser;
@class NCMBObject;

/// コールバックブロック
typedef void (^NCMBBooleanResultBlock)(BOOL succeeded, NSError *error);
typedef void (^NCMBIntegerResultBlock)(int number, NSError *error);
typedef void (^NCMBObjectResultBlock)(NCMBObject *object, NSError *error);
typedef void (^NCMBArrayResultBlock)(NSArray *objects, NSError *error);
typedef void (^NCMBSetResultBlock)(NSSet *channels, NSError *error);
typedef void (^NCMBUserResultBlock)(NCMBUser *user, NSError *error);

typedef void (^NCMBDataResultBlock)(NSData *data, NSError *error);
typedef void (^NCMBDataStreamResultBlock)(NSInputStream *stream, NSError *error);
typedef void (^NCMBProgressBlock)(int percentDone);


/// キャッシュポリシー
typedef enum {
    // キャッシュしない(default)
    kNCMBCachePolicyIgnoreCache = 0,
    
    // キャッシュのみ利用。キャッシュがない場合エラー。
    kNCMBCachePolicyCacheOnly,
    
    // キャッシュから読込はしないが、取得結果はキャッシュする。
    kNCMBCachePolicyNetworkOnly,
    
    // キャッシュ、ネットワークの順に読込。両方失敗時はエラー。
    kNCMBCachePolicyCacheElseNetwork,
    
    // ネットワーク、キャッシュの順に読込。両方失敗時はエラー。
    kNCMBCachePolicyNetworkElseCache,
    
    // キャッシュ、ネットワークの順に両方から読込。両方コールバックされ結果が異なる場合がある。
    kNCMBCachePolicyCacheThenNetwork
    
} NCMBCachePolicy;