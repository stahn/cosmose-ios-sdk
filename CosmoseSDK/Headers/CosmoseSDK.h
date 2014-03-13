//
//  CosmoseSDK.h
//  CosmoseSDK
//
//  Created by Krzysztof Magiera on 11.03.2014.
//  Copyright (c) 2014 Cosmose. All rights reserved.
//

#import <Foundation/Foundation.h>

@class FBSession;

@interface CosmoseSDK : NSObject

+ (void)start;
+ (BOOL)handleOpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication;
+ (void)updateFbSession:(FBSession*)fbSession;

@end
