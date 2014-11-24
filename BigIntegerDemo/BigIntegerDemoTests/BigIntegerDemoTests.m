//
//  BigIntegerDemoTests.m
//  BigIntegerDemoTests
//
//  Created by Soto on 14/11/24.
//  Copyright (c) 2014年 Soto. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <XCTest/XCTest.h>

#import "STBigInteger.h"
#import "JKBigInteger.h"

@interface BigIntegerDemoTests : XCTestCase

@end

@implementation BigIntegerDemoTests

- (void)setUp {
	[super setUp];
	// Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
	// Put teardown code here. This method is called after the invocation of each test method in the class.
	[super tearDown];
}

- (void)testExample {
	// This is an example of a functional test case.
	NSLog(@"大数据计算测试");
	STBigInteger *bigtest = [[STBigInteger alloc] initWithLong:1000000000000];
	bigtest = [bigtest divide:[[STBigInteger alloc] initWithLong:2]];
	NSLog(@"%ld", (long)[bigtest intValue]);

	JKBigInteger *int1 = [[JKBigInteger alloc] initWithString:@"1000000000000"];

	int1 = [int1 divide:[[JKBigInteger alloc] initWithString:@"2"]];
	NSLog(@"%lu", [int1 unsignedIntValue]);
	XCTAssert(YES, @"Pass");
}

- (void)testPerformanceExample {
	// This is an example of a performance test case.
	[self measureBlock: ^{
	    // Put the code you want to measure the time of here.
	}];
}

@end
