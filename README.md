# Cosmose iOS SDK

Cosmose iOS SDK allows app partners to easily integrate core Cosmose functionality into iOS apps.

# Installation

## Using cocoapods

Add `CosmoseSDK` dependency to your `Podfile`:
Here's an example:

```ruby
pod 'CosmoseSDK', :git => 'https://github.com/Cosmose/cosmose-ios-sdk.git'
```

# Configure `.plist`

Cosmose SDK require few lines of configuration in your app's main `Info.plist` file. Follow steps below to complete integration:

1. Create `CosmoseAppID` key and assign a unique Cosmose App Partner ID received from Cosmose Team
2. Create an array key `URL types` with a single item `URL Scheme` of type `Array` (if not already exists) and add a `String` item containing Cosmose CrossApp Communication URL Scheme received from Cosmose Team (the scheme should start from `xcosmose`)

After all these operations your app's main `Info.plist` file should look like the one below.
![Zrzut ekranu 2014-03-13 o 17.02.43.png](https://bitbucket.org/repo/bRB6MA/images/2935216394-Zrzut%20ekranu%202014-03-13%20o%2017.02.43.png)

# SDK Integration

In each file you refer to Cosmose SDK methods add header import directive:

```objective-c
#import <CosmoseSDK/CosmoseSDK.h>
```

Alternatively you may add this line to your app's prefix header file `-Prefix.pch`


There are a few entry points in which Cosmose SDK methods should be invoked. Please follow the instruction below to complete the integration process. In terms of the meaning of individual SDK calls, please refer to `appledoc` documentation in `CosmoseSDK.h` main header file:

1. In app's `UIApplicationDelegate` method `application:didFinishLaunchingWithOptions:` call `[CosmoseSDK start]`
2. In app's `UIApplicationDelegate` method `application:openURL:sourceApplication:annotation:` add call to `[CosmoseSDK handleOpenURL:sourceApplication:]` in a way presented below:

```objective-c
- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation {

    BOOL wasHandled;

    wasHandled = [CosmoseSDK handleOpenURL:url sourceApplication:sourceApplication];

    return wasHandled;
}
```

## Facebook Login integration

We assume here, that your app integrating Facebook Login is based on a official Facebook iOS SDK.

1. After the successfull login or once the app detect that user is already logged in call: `[CosmoseSDK updateFbSession:]`, and pass an instance of `FBSession` that represents the active session (e.g., `[FBSession activeSession]`).

Please refer to `[CosmoseSDK updateFbDataWithToken:userInfo:]` method (more info in the `appledoc`) if your app is based on incompatible version of Facebook SDK or your app is not based on Facebook SDK at all but still supports Facebook Sign In.

## Google SignIn integration

If your app supports Google SignIn, you may use `[CosmoseSDK updateGoogleSignIn:]` method to provide basic user data to Cosmose SDK. If ths sign-in process is compatible with the instructions from here: https://developers.google.com/+/mobile/ios/sign-in then you may add a call to `[CosmoseSDK updateGoogleSignIn:]` directly to your apps' `GPPSignInDelegate`. Otherwise please refer to Cosmose SDK `appledoc` and method `[CosmoseSDK updateGoogleSignInDataWithEmail:userID]` in order to pass basic user info to Cosmose SDK.

## Alternative user identification methods

If your app does not incorporate Facebook or Google Sign In but still requires user to type in his or her email address (for alternative sign in process or regardless of the reason) you may provide that information to Cosmose SDK. Once user type in a email address within your app you should call `[CosmoseSDK updateUserEmail:]` passing that email address. Please refer to the `appledoc` for more information about this method.

# Demo App

Under [CosmoseSDKDemo](https://github.com/Cosmose/cosmose-ios-sdk/tree/master/CosmoseSDKDemo) dir you will find a source code of a sample app utilizing Cosmose SDK. CosmoseSDKDemo app consist of a single view with Facebook Login button. Please refer to this project to see how to integrate Cosmose SDK with an iOS app with Facebook Login. This sample application is based on Facebook Login app tutorial that can be found here: https://developers.facebook.com/docs/ios/login-tutorial/