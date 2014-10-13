//
//  TodaysRecipe.h
//  FamiKom_iOS
//
//  Created by 山本　恭大 on 2014/10/13.
//  Copyright (c) 2014年 山本　恭大. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Recipe.h"

@interface TodaysRecipe : NSObject

@property(nonatomic)familyType type;//誰が選んだ

@property(nonatomic)Recipe *recipe;//レシピ

@end
