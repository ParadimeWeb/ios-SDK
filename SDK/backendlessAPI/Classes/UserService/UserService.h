//
//  UserService.h
//  backendlessAPI
/*
 * *********************************************************************************************************************
 *
 *  BACKENDLESS.COM CONFIDENTIAL
 *
 *  ********************************************************************************************************************
 *
 *  Copyright 2012 BACKENDLESS.COM. All Rights Reserved.
 *
 *  NOTICE: All information contained herein is, and remains the property of Backendless.com and its suppliers,
 *  if any. The intellectual and technical concepts contained herein are proprietary to Backendless.com and its
 *  suppliers and may be covered by U.S. and Foreign Patents, patents in process, and are protected by trade secret
 *  or copyright law. Dissemination of this information or reproduction of this material is strictly forbidden
 *  unless prior written permission is obtained from Backendless.com.
 *
 *  ********************************************************************************************************************
 */

#import <Foundation/Foundation.h>

@class BackendlessUser, Fault;
@class FBSession;
@protocol IResponder;
@protocol FBGraphUser;

@interface UserService : NSObject

@property (strong, nonatomic, readonly) BackendlessUser *currentUser;

// sync methods

/////__deprecated

-(BackendlessUser *)registering:(BackendlessUser *)user __deprecated ;
-(BackendlessUser *)update:(BackendlessUser *)user __deprecated;
-(BackendlessUser *)login:(NSString *)login password:(NSString *)password __deprecated;
-(id)logout __deprecated;
-(id)restorePassword:(NSString *)login __deprecated;
-(NSArray *)describeUserClass __deprecated;
-(id)user:(NSString *)user assignRole:(NSString *)role __deprecated;
-(id)user:(NSString *)user unassignRole:(NSString *)role __deprecated;
-(id)loginWithFacebookSDK:(FBSession *)session user:(NSDictionary<FBGraphUser> *)user fieldsMapping:(NSDictionary *)fieldsMapping __deprecated;
-(NSArray *)getUserRoles __deprecated_msg("will be private only");

-(BackendlessUser *)registering:(BackendlessUser *)user error:(Fault **)fault;
-(BackendlessUser *)update:(BackendlessUser *)user error:(Fault **)fault;
-(BackendlessUser *)login:(NSString *)login password:(NSString *)password error:(Fault **)fault;
-(BOOL)logoutError:(Fault **)fault;
-(BOOL)restorePassword:(NSString *)login error:(Fault **)fault;
-(NSArray *)describeUserClassError:(Fault **)fault;
-(BOOL)user:(NSString *)user assignRole:(NSString *)role error:(Fault **)fault;
-(BOOL)user:(NSString *)user unassignRole:(NSString *)role error:(Fault **)fault;
-(BackendlessUser *)loginWithFacebookSDK:(FBSession *)session user:(NSDictionary<FBGraphUser> *)user fieldsMapping:(NSDictionary *)fieldsMapping error:(Fault **)fault;
-(NSArray *)getUserRolesError:(Fault **)fault;


// async methods with responder
-(void)registering:(BackendlessUser *)user responder:(id <IResponder>)responder;
-(void)update:(BackendlessUser *)user responder:(id <IResponder>)responder;
-(void)login:(NSString *)login password:(NSString *)password responder:(id <IResponder>)responder;
-(void)logout:(id <IResponder>)responder;
-(void)restorePassword:(NSString *)login responder:(id <IResponder>)responder;
-(void)describeUserClass:(id <IResponder>)responder;
-(void)user:(NSString *)user assignRole:(NSString *)role responder:(id <IResponder>)responder;
-(void)user:(NSString *)user unassignRole:(NSString *)role responder:(id <IResponder>)responder;
-(void)loginWithFacebookSDK:(FBSession *)session user:(NSDictionary<FBGraphUser> *)user fieldsMapping:(NSDictionary *)fieldsMapping responder:(id <IResponder>)responder;
-(void)getUserRoles:(id <IResponder>)responder;

// async methods with block-base callbacks
-(void)registering:(BackendlessUser *)user response:(void(^)(BackendlessUser *))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)update:(BackendlessUser *)user response:(void(^)(BackendlessUser *))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)login:(NSString *)login password:(NSString *)password response:(void(^)(BackendlessUser *))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)logout:(void(^)(id))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)restorePassword:(NSString *)login response:(void(^)(id))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)describeUserClass:(void(^)(NSArray *))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)user:(NSString *)user assignRole:(NSString *)role response:(void(^)(id))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)user:(NSString *)user unassignRole:(NSString *)role response:(void(^)(id))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)loginWithFacebookSDK:(FBSession *)session user:(NSDictionary<FBGraphUser> *)user fieldsMapping:(NSDictionary *)fieldsMapping response:(void(^)(id))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)getUserRoles:(void(^)(NSArray *))responseBlock error:(void(^)(Fault *))errorBlock;

// async social easy logins
-(void)easyLoginWithFacebookFieldsMapping:(NSDictionary *)fieldsMapping permissions:(NSArray *)permissions response:(void(^)(id))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)easyLoginWithTwitterFieldsMapping:(NSDictionary *)fieldsMapping response:(void(^)(id))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)easyLoginWithFacebookFieldsMapping:(NSDictionary *)fieldsMapping permissions:(NSArray *)permissions responder:(id<IResponder>)responder;
-(void)easyLoginWithTwitterFieldsMapping:(NSDictionary *)fieldsMapping responder:(id<IResponder>)responder;
-(void)easyLoginWithFacebookFieldsMapping:(NSDictionary *)fieldsMapping permissions:(NSArray *)permissions;
-(void)easyLoginWithTwitterFieldsMapping:(NSDictionary *)fieldsMapping;

// utilites
-(id)handleOpenURL:(NSURL *)url;

@end
