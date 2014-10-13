//
//  RecipeListManager.m
//  FamiKom_iOS
//
//  Created by 山本　恭大 on 2014/10/13.
//  Copyright (c) 2014年 山本　恭大. All rights reserved.
//

#import "RecipeListManager.h"
#import "RecipeList.h"
@implementation RecipeListManager
static RecipeListManager* _sharedInstance = nil;

+ (RecipeListManager*)sharedManager
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _sharedInstance = [[RecipeListManager alloc] init];
    });
    
    return _sharedInstance;
}

- (id)init
{
    self = [super init];
    if (!self) {
        return nil;
    }
    self.Recipes = [[NSMutableArray alloc] init];
    self.SelectRecipes = [[NSMutableArray alloc] init];
    self.calenderRecipes = [[NSMutableDictionary alloc] init];
    self.recipesChache =[[NSMutableDictionary alloc] init];
    return self;
}

-(RecipeList*)RecipeList:(NSInteger)categoryID
{
    //キャッシュが有ったらそっちを利用
    RecipeList *chch = [self.recipesChache objectForKey:[NSString stringWithFormat:@"%d",categoryID]];
    if(chch != nil)
    {
        return chch;
    }
    
    //無かったら作る
    RecipeList *recipes = [RecipeList alloc];
    recipes.categoryID = categoryID;
    [recipes getRecipes];
    [self.recipesChache setObject:recipes forKey:[NSString stringWithFormat:@"%d",categoryID]];
    return recipes;
}

-(void)selectRecipe:(NSInteger) categoryID withIndex:(NSInteger)index
{
    RecipeList *recipes = [RecipeList alloc];
    recipes.categoryID = categoryID;
}
@end
