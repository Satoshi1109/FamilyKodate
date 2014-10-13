//
//  RecipeListManager.h
//  FamiKom_iOS
//
//  Created by 山本　恭大 on 2014/10/13.
//  Copyright (c) 2014年 山本　恭大. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RecipeList.h"
#import "Recipe.h"

@interface RecipeListManager : NSObject
+ (RecipeListManager*)sharedManager;
@property(nonatomic)NSMutableDictionary *recipesChache;//レシピリストのキャッシュ
@property(nonatomic)NSMutableArray *Recipes;//RecipeListのarray（今の所使わない、消す？）
@property(nonatomic)NSMutableArray *SelectRecipes;//選択されたレシピ（TodaysRecipeのarray）

@property(nonatomic)NSMutableDictionary *calenderRecipes;//Keyは日付、valueは、todaysRecipe

-(RecipeList*)RecipeList:(NSInteger)categoryID; //登録するときに表示するリスト
-(void)selectRecipe:(NSInteger) categoryID withIndex:(NSInteger)index; //selectedRecipesにaddする

@end
