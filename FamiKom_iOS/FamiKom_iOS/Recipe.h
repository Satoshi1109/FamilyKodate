//
//  Recipe.h
//  FamiKom_iOS
//
//  Created by 山本　恭大 on 2014/10/12.
//  Copyright (c) 2014年 山本　恭大. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface Recipe : NSObject
-(instancetype)initWithDictionary:(NSDictionary *)dict;

@property(nonatomic)NSInteger recipeID;
@property(nonatomic)NSString *title;//料理名
@property(nonatomic)NSString *recipeURL;
@property(nonatomic)NSString *foodImageURL;
@property(nonatomic)NSString *mediumImageURL;
@property(nonatomic)NSString *smallImageURL;
@property (nonatomic)NSString *recipeDescription;//説明文
@property (nonatomic)NSArray *recipeMaterials;//素材の文字列がarrayで入ってる
@property (nonatomic)NSString *recipeIndication;//所要時間
@property (nonatomic)NSString *recipeCost;
@property(nonatomic)NSString *strRank;//
@property(nonatomic)NSInteger rank;//順位の順番でソートとかする

@property(nonatomic)UIImage *foodImage;
@property(nonatomic)UIImage *foodImageThumb;//丸い画像にして入れておく

@end
