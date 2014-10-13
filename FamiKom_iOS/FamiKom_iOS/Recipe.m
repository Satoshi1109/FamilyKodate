//
//  Recipe.m
//  FamiKom_iOS
//
//  Created by 山本　恭大 on 2014/10/12.
//  Copyright (c) 2014年 山本　恭大. All rights reserved.
//

#import "Recipe.h"
#import "AFHTTPRequestOperationManager.h"

@implementation Recipe
-(instancetype)initWithDictionary:(NSDictionary *)dict
{
    self = [super init];
    if(self)
    {
        NSInteger recipeID = [dict[@"recipeId"] intValue];
        if (recipeID) {
            self.recipeID = recipeID;
        }
        
        NSString* title = dict[@"recipeTitle"];
        if ([title isKindOfClass:[NSString class]]) {
            self.title = title;
        }
        
        NSString* recipeURL = dict[@"recipeUrl"];
        if ([recipeURL isKindOfClass:[NSString class]]) {
            self.recipeURL = recipeURL;
        }
        
        NSString* foodImageURL = dict[@"foodImageUrl"];
        if ([foodImageURL isKindOfClass:[NSString class]]) {
            self.foodImageURL = foodImageURL;
        }
        
        NSString* mediumImageURL = dict[@"mediumImageUrl"];
        if ([mediumImageURL isKindOfClass:[NSString class]]) {
            self.mediumImageURL = mediumImageURL;
        }
        
        NSString* smallImageURL = dict[@"smallImageUrl"];
        if ([smallImageURL isKindOfClass:[NSString class]]) {
            self.smallImageURL = smallImageURL;
        }
        
        NSString* recipeDescription = dict[@"recipeDescription"];
        if ([recipeDescription isKindOfClass:[NSString class]]) {
            self.recipeDescription = recipeDescription;
        }
        
        NSArray* recipeMaterials = dict[@"recipeMaterial"];
        if ([recipeMaterials isKindOfClass:[NSArray class]]) {
            self.recipeMaterials = recipeMaterials;
        }
        
        NSString* recipeCost = dict[@"recipeCost"];
        if ([recipeCost isKindOfClass:[NSString class]]) {
            self.recipeCost = recipeCost;
        }
        
        NSString* strRank = dict[@"rank"];
        if ([strRank isKindOfClass:[NSString class]]) {
            self.strRank = strRank;
        }
        
        [self setfoodImage];
        [self setfoodImageThumb];
    }
    return self;
}

-(UIImage*)setfoodImage
{
    __block UIImage *ret=self.foodImage;
    if(ret != nil) return ret;
    
    if(self.foodImageURL == nil) return nil;
    
    AFHTTPRequestOperationManager* manager = [AFHTTPRequestOperationManager manager];
    manager.responseSerializer = [AFHTTPResponseSerializer serializer];
    __block bool flag = YES;
    [manager GET:self.foodImageURL
      parameters:nil success:^(AFHTTPRequestOperation *operation, id pic) {
          self.foodImage = [[UIImage alloc] initWithData:pic];
          flag = NO;
          
      } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
          NSLog(@"operationFriends:%@",operation.request.URL.relativeString);
          NSLog(@"Error: %@", error);
          flag = NO;
      }];
    while(flag)
        [[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.5]];
    return self.foodImage;
}

-(UIImage*)setfoodImageThumb
{
    __block UIImage *ret=self.foodImageThumb;
    if(ret != nil) return ret;
    
    if(self.foodImageURL == nil) return nil;
    
    AFHTTPRequestOperationManager* manager = [AFHTTPRequestOperationManager manager];
    manager.responseSerializer = [AFHTTPResponseSerializer serializer];
    __block bool flag = YES;
    [manager GET:self.mediumImageURL
      parameters:nil success:^(AFHTTPRequestOperation *operation, id pic) {
          self.foodImageThumb = [self roundImage:[[UIImage alloc] initWithData:pic]];
          flag = NO;
          
      } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
          NSLog(@"operationFriends:%@",operation.request.URL.relativeString);
          NSLog(@"Error: %@", error);
          flag = NO;
      }];
    while(flag)
        [[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.5]];
    return self.foodImageThumb;
}

-(UIImage*)roundImage:(UIImage*)im
{
    if(im == nil) return nil;
    //丸い画像生成
    UIImageView *layerView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, 50, 50)];
    layerView.clipsToBounds = YES;
    layerView.layer.borderWidth = 1.0f;
    layerView.layer.borderColor = [[UIColor blackColor] CGColor];
    layerView.layer.cornerRadius = 24.0;
    layerView.image = im;
    return [self imageFromView:layerView];
}

- (UIImage*)imageFromView:(UIView*)view
{
    UIImage* image;
    
    // UIView のサイズの画像コンテキストを開始します。
    UIGraphicsBeginImageContextWithOptions(view.frame.size, NO, 0.0);
    
    // 開始した画像コンテキストを取得します。
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    // UIView の内容を、開始した画像コンテキストへ書き出させます。
    [view.layer renderInContext:context];
    
    // 画像コンテキストから画像を生成します。
    image = UIGraphicsGetImageFromCurrentImageContext();
    
    // 画像コンテキストを終了します。
    UIGraphicsEndImageContext();
    
    return image;
}
@end

