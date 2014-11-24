//
//  NSString+HexToBytes.m
//  BigInteger
//
//  Created by Soto on 14/11/9.
//  Copyright (c) 2014年 Soto. All rights reserved.
//

#import "NSString+HexToBytes.h"

@implementation NSString (HexToBytes)

- (NSData *)hexToBytes
{
    NSMutableData   *data = [NSMutableData data];
    int             idx;

    for (idx = 0; idx + 2 <= self.length; idx += 2) {
        NSRange         range = NSMakeRange(idx, 2);
        NSString        *hexStr = [self substringWithRange:range];
        NSScanner       *scanner = [NSScanner scannerWithString:hexStr];
        unsigned int    intValue;
        [scanner scanHexInt:&intValue];
        [data appendBytes:&intValue length:1];
    }

    return data;
}

@end
