//
//  COSViewController.m
//  CosmoseSDKDemo
//
//  Created by Krzysztof Magiera on 13.03.2014.
//  Copyright (c) 2014 Cosmose. All rights reserved.
//

#import "COSViewController.h"

#import <FacebookSDK/FacebookSDK.h>
#import <CosmoseSDK/CosmoseSDK.h>

@interface COSViewController () <FBLoginViewDelegate>

@property (strong, nonatomic) FBProfilePictureView *profilePictureView;

@end

@implementation COSViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // Create facebook login button
    FBLoginView *loginView = [[FBLoginView alloc] init];
    loginView.delegate = self;
    loginView.readPermissions = @[@"basic_info", @"email"];
    loginView.center = self.view.center;
    [self.view addSubview:loginView];
    
    // Create profile picture view
    self.profilePictureView = [[FBProfilePictureView alloc] initWithFrame:CGRectMake(0, 0, 50, 50)];
    self.profilePictureView.center = CGPointMake(self.view.center.x, self.view.center.y - 80);
    [self.view addSubview:self.profilePictureView];
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

#pragma mark - FBLoginViewDelegate

- (void)loginViewFetchedUserInfo:(FBLoginView *)loginView user:(id<FBGraphUser>)user
{
    self.profilePictureView.profileID = user.id;
}

- (void)loginViewShowingLoggedInUser:(FBLoginView *)loginView
{
    [CosmoseSDK updateFbSession:[FBSession activeSession]];
}

- (void)loginViewShowingLoggedOutUser:(FBLoginView *)loginView
{
    self.profilePictureView.profileID = nil;
}

- (void)loginView:(FBLoginView *)loginView handleError:(NSError *)error
{
    [[[UIAlertView alloc] initWithTitle:@"Facebook Login Error" message:[error localizedDescription] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
}

@end
