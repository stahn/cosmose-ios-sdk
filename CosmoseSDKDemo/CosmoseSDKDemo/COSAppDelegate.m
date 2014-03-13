//
//  COSAppDelegate.m
//  CosmoseSDKDemo
//
//  Created by Krzysztof Magiera on 13.03.2014.
//  Copyright (c) 2014 Cosmose. All rights reserved.
//

#import "COSAppDelegate.h"

#import <FacebookSDK/FacebookSDK.h>
#import <CosmoseSDK/CosmoseSDK.h>

@implementation COSAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Launch Cosmose SDK in application:didFinishLanuchingWithOptions:
    [CosmoseSDK start];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

#pragma mark - FB Related stuff

- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation {
    
    // Call FBAppCall's handleOpenURL:sourceApplication to handle Facebook app responses
    BOOL wasHandled;
    
    wasHandled = [FBAppCall handleOpenURL:url sourceApplication:sourceApplication];
    
    if (!wasHandled) {
        wasHandled = [CosmoseSDK handleOpenURL:url sourceApplication:sourceApplication];
    }
    
    return wasHandled;
}

@end
