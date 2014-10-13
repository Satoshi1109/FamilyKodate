//
//  RecipeList.m
//  FamiKom_iOS
//
//  Created by 山本　恭大 on 2014/10/13.
//  Copyright (c) 2014年 山本　恭大. All rights reserved.
//

#import "RecipeList.h"
#import "Recipe.h"
#import "Config.h"
#import "AFHTTPRequestOperationManager.h"

@implementation RecipeList

-(NSMutableArray*)getRecipes
{
    __block NSMutableArray *ret=self.recipes;
    if(ret != nil) return ret;//キャッシュが有ったらそっちを使う
    
    // 入力パラメータ
    NSDictionary *sdict = @{
                            @"categoryId" :[NSNumber numberWithInteger: self.categoryID],
                            @"applicationId": kRaktenAppID,
                            @"format":@"json"
                            };
    
    AFHTTPRequestOperationManager* manager = [AFHTTPRequestOperationManager manager];
    manager.responseSerializer = [AFHTTPResponseSerializer serializer];
    __block bool flag = YES;
    [manager GET:kRakutenCategoryRanking
      parameters:sdict success:^(AFHTTPRequestOperation *operation, NSData *resp) {
          NSDictionary *dict = [NSJSONSerialization JSONObjectWithData:resp options:NSJSONReadingMutableContainers error:nil];
          ret = [self convertRecipe:dict];
          self.recipes = ret;
          flag = NO;
          NSLog(@"success:%@",dict);
      } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
          NSLog(@"operationFriends:%@",operation.request.URL.relativeString);
          NSLog(@"Error: %@", error);
          flag = NO;
      }];
    while(flag)
        [[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.5]];
    return self.recipes;
}

-(NSMutableArray *)convertRecipe:(NSDictionary*)dict
{
    NSArray *arr = [dict objectForKey:@"result"];
    NSMutableArray *ret = [[NSMutableArray alloc] init];
    for(int i = 0; i < arr.count ; i++)
    {
        Recipe *recipe = [[Recipe alloc] initWithDictionary:arr[i]];
        [ret addObject:recipe];
    }
    return ret;
}
@end
