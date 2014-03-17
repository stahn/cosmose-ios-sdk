//
//  CosmoseSDK.h
//  CosmoseSDK
//
//  Created by Krzysztof Magiera on 11.03.2014.
//  Copyright (c) 2014 Cosmose. All rights reserved.
//

#import <Foundation/Foundation.h>

@class FBSession, GPPSignIn;

/**
 `CosmoseSDK` is a main entry class of Cosmose SDK library.
 
 Use this interface to launch Cosmose SDK background beacon monitoring and controll another
 
 ## Application configuration
 
 Cosmose SDK require that the app provide a unique Cosmose SDK App Identifier via an app specific Info.plist file as well as custom URL scheme (`xcosmose`) need to be defined for the app. For more details please refer to the documentation under https://github.com/Cosmose/cosmose-ios-sdk . Example app using Cosmose SDK and Facebook login can be found at https://github.com/Cosmose/cosmose-ios-sdk/tree/master/CosmoseSDKDemo .
 */

@interface CosmoseSDK : NSObject

/**
 Launches Cosmose SDK background iBeacon monitoring (if not already launched).
 This method should be called directly from `application:didFinishLaunchingWithOptions:` method of `UIApplicationDelegate` as soon as possible.
 */
+ (void)start;

/**
 Use this method from `application:openURL:sourceApplication:annotation` method of `UIApplicationDelegate`.
 This method is responsible for handling interapp communication with other Cosmose partners apps. See the example implementation of `UIApplicationDelegate` method for handling custom URL scheme. This method will detect Cosmose URL scheme (prefixed with `xcosmose`) and process it properly. It is safe to provide URL other than prefixed with `xcosmose`, althought in this case `NO` will be returned. Thus the result of this method can be forwarded as a result of `application:openURL:sourceApplication:annotation` if the app does not handle custom URL schemes other than the one that is required by Cosmose SDK.
 
    - (BOOL)application:(UIApplication *)application
        openURL:(NSURL *)url
        sourceApplication:(NSString *)sourceApplication
        annotation:(id)annotation {
 
        BOOL wasHandled;
 
        wasHandled = [CosmoseSDK handleOpenURL:url sourceApplication:sourceApplication];
 
        return wasHandled;
    }
 
 @param url The URL received through `application:openURL:sourceApplication:annotation` method of `UIApplicationDelegate`
 @param sourceApplication The bundle ID of app requesting to open the URL
 
 @return `YES` if URL scheme starts from `xcosmose` and was handled properly, `NO` otherwise
 */
+ (BOOL)handleOpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication;

/**
 This method links user facebook account to Cosmose SDK user database.
 Use this method if the app have implemented Facebook login.
 This method should be called as soon as fb session is established. One of the possible entry point for calling this method is `FBLoginViewDelegate`'s method `loginViewShowingLoggedInUser:loginView`.
 Either way it is possible to provide `FBSession` instance by directly calling `[FBSession activeSession]` from the app's login flow.
 
 @param fbSession The instance of active and open Facebook session obtained via Facebook-iOS-SDK (see https://developers.facebook.com/docs/ios )
 
 @see updateFbDataWithToken:userInfo:
 */
+ (void)updateFbSession:(FBSession*)fbSession;

/**
 Alternative way to update facebook related user details. Use this method instead of `updateFbSession:`) when your app doesn't utilize Facebook SDK or when incompatible version of SDK is in use.
 `Nil` value can be provided for each of two parameters if not available at the moment of call and can be provided later.
 
 @param fbToken Facebook API token (if available)
 @param fbUserInfo Dictionary with user data including user fbid (if available)
 
 @see updateFbSession:
 */
+ (void)updateFbDataWithToken:(NSString*)fbToken userInfo:(NSDictionary*)fbUserInfo;

/**
 Link user's google account to Cosmose SDK user database.
 If your app supports Google SignIn via Google Plus SDK use this method to provide basic user data to Cosmose SDK.
 This method should be called as soon as the sing in (or silent sign in) is completed. The best place to put call to this method is in `GPPSignInDelegate`'s method `finishedWithAuth:error:` when error is not `nil.
 To retrieve handle to active `GPPSignIn` instance you may call `[GPPSignIn sharedInstance]`
 
 @param googleSignIn The active instance of `GPPSignIn` interface
 
 @see updateGoogleSignInDataWithEmail:userID:
 */
+ (void)updateGoogleSignIn:(GPPSignIn*)googleSignIn;

/**
 Alternative way to provide basic user data info in case when app supports Google Sign In. You should use this method instead of `updateGoogleSignIn:` when `GPPSignIn` inteface is not available in your app.
 
 @param googleUserEmail User's email address used for Google Sign In
 @param googleUserID User's google ID retireved after successfull sing in
 
 @see updateGoogleSignIn:
 */
+ (void)updateGoogleSignInDataWithEmail:(NSString*)googleUserEmail userID:(NSString*)googleUserID;

/**
 If your app support user login via e-mail and no Facebook nor Google authentication is in use, you may call this method to link basic user's info with Cosmose SDK.
 
 @param userEmail User's email address used for app sign in or retireved from user at any point during the app usage
 
 @see updateGoogleSignIn: updateFbSession:
 */
+ (void)updateUserEmail:(NSString*)userEmail;

@end
