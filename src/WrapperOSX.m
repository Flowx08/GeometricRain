////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "WrapperOSX.h"
#import <Foundation/Foundation.h>

////////////////////////////////////////////////////////////
const char* wrResourcePath()
{
    char* rpath;
    @autoreleasepool {
    NSBundle* bundle = [NSBundle mainBundle];

        if (bundle == nil) {
#ifdef DEBUG
            NSLog(@"bundle is nil... thus no resources path can be found.");
#endif
        } else {
            NSString* path = [bundle resourcePath];
            rpath = (char*)[path UTF8String];
            strcat(rpath, "/");
        }

    }

    return rpath;
}

////////////////////////////////////////////////////////////
const char* wrTemporaryDiractory()
{
    return [NSTemporaryDirectory() UTF8String];
}

////////////////////////////////////////////////////////////
void wrCreateGroupDirectory()
{
    NSFileManager *fm = [NSFileManager defaultManager];
    NSString *appGroupName = @"94PFKP66PW.com.virtualshock.geometricrain"; /* For example */
    
    NSURL *groupContainerURL = [fm containerURLForSecurityApplicationGroupIdentifier:appGroupName];
    NSError* theError = nil;
    if (![fm createDirectoryAtURL: groupContainerURL withIntermediateDirectories:YES attributes:nil error:&theError]) {
        printf("Error while creating the group container\n");
    }
}