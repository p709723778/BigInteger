// ************************************************************************************
//
//  STBigInteger.h
//  BigInteger
//
//  Created by Soto on 14/11/8.
//  Copyright (c) 2014年 Soto. All rights reserved.
//
// This is a port of C# code originally written by Chew Keong TAN
// See http://www.codeproject.com/csharp/biginteger.asp for more details.
//
// ALL LICENSES AND TERMS ARE EXTENSIONS OF THOSE OUTLINED FOR THE ORIGINAL WORK
//
// All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, and/or sell copies of the Software, and to permit persons
// to whom the Software is furnished to do so, provided that the above
// copyright notice(s) and this permission notice appear in all copies of
// the Software and that both the above copyright notice(s) and this
// permission notice appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT
// OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
// HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL
// INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING
// FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
// NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
// WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//
//
// Disclaimer
// ----------
// Although reasonable care has been taken to ensure the correctness of this
// implementation, this code should never be used in any application without
// proper verification and testing.  I disclaim all liability and responsibility
// to any person or entity with respect to any loss or damage caused, or alleged
// to be caused, directly or indirectly, by the use of this BigInteger class.
//
// Features
// --------
// 1) Arithmetic operations involving large signed integers (2's complement).
// 2) Primality test using Fermat little theorm, Rabin Miller's method,
//    Solovay Strassen's method and Lucas strong pseudoprime.
// 3) Modulo exponential with Barrett's reduction.
// 4) Inverse modulo.
// 5) Pseudo prime generation.
// 6) Co-prime generation.
//
//
// Known Problem
// -------------
// This pseudoprime passes my implementation of
// primality test but failed in JDK's isProbablePrime test.
//
//       byte[] pseudoPrime1 = { (byte)0x00,
//             (byte)0x85, (byte)0x84, (byte)0x64, (byte)0xFD, (byte)0x70, (byte)0x6A,
//             (byte)0x9F, (byte)0xF0, (byte)0x94, (byte)0x0C, (byte)0x3E, (byte)0x2C,
//             (byte)0x74, (byte)0x34, (byte)0x05, (byte)0xC9, (byte)0x55, (byte)0xB3,
//             (byte)0x85, (byte)0x32, (byte)0x98, (byte)0x71, (byte)0xF9, (byte)0x41,
//             (byte)0x21, (byte)0x5F, (byte)0x02, (byte)0x9E, (byte)0xEA, (byte)0x56,
//             (byte)0x8D, (byte)0x8C, (byte)0x44, (byte)0xCC, (byte)0xEE, (byte)0xEE,
//             (byte)0x3D, (byte)0x2C, (byte)0x9D, (byte)0x2C, (byte)0x12, (byte)0x41,
//             (byte)0x1E, (byte)0xF1, (byte)0xC5, (byte)0x32, (byte)0xC3, (byte)0xAA,
//             (byte)0x31, (byte)0x4A, (byte)0x52, (byte)0xD8, (byte)0xE8, (byte)0xAF,
//             (byte)0x42, (byte)0xF4, (byte)0x72, (byte)0xA1, (byte)0x2A, (byte)0x0D,
//             (byte)0x97, (byte)0xB1, (byte)0x31, (byte)0xB3,
//       };

#import <Foundation/Foundation.h>

#define MAX_LENGTH 1024

typedef unsigned long long ulong;

@interface STBigInteger : NSObject {
    @public
    int     dataLength;
    uint    data[MAX_LENGTH]; // stores bytes from the Big Integer
}

@property (nonatomic) int dataLength;

- (id)init;
- (id)initWithInt:(int)value;
- (id)initWithLong:(long)value;
- (id)initWithULong:(ulong)value;
- (id)initWithBigInt:(STBigInteger *)value;
- (id)initWithUIntArray:(uint *)value withSize:(int)size;
- (id)initWithString:(NSString *)value andRadix:(int)radix;

+ (STBigInteger *)create;
+ (STBigInteger *)createFromInt:(int)value;
+ (STBigInteger *)createFromLong:(long)value;
+ (STBigInteger *)createFromULong:(ulong)value;
+ (STBigInteger *)createFromBigInt:(STBigInteger *)value;
+ (STBigInteger *)createFromString:(NSString *)value andRadix:(int)radix;

- (STBigInteger *)add:(STBigInteger *)bi2;
- (STBigInteger *)subtract:(STBigInteger *)bi2;
- (STBigInteger *)multiply:(STBigInteger *)bi2;
- (STBigInteger *)divide:(STBigInteger *)bi2;

- (STBigInteger *)negate;
- (STBigInteger *)not;
- (STBigInteger *)shiftLeft:(int)shiftVal;
- (STBigInteger *)shiftRight:(int)shiftVal;
- (STBigInteger *)mod:(STBigInteger *)bi2;
- (STBigInteger *)and:(STBigInteger *)bi2;
- (STBigInteger *)or:(STBigInteger *)bi2;
- (STBigInteger *)xOr:(STBigInteger *)bi2;

- (BOOL)equals:(STBigInteger *)bi;
- (BOOL)greaterThan:(STBigInteger *)bi2;
- (BOOL)lessThan:(STBigInteger *)bi2;
- (BOOL)lessThanOrEqualTo:(STBigInteger *)bi2;
- (BOOL)greaterThanOrEqualTo:(STBigInteger *)bi2;

// ***********************************************************************
// Returns the lowest 4 bytes of the BigInteger as an int.
// ***********************************************************************
- (NSInteger)intValue;

// ***********************************************************************
// Returns the absolute value
// ***********************************************************************
- (STBigInteger *)abs;

- (STBigInteger *)sqrt;
- (STBigInteger *)gcd:(STBigInteger *)bi;

- (uint *)getData;
- (uint)getDataAtIndex:(int)index;
- (void)setData:(uint)value atIndex:(int)index;

// ***********************************************************************
// Returns the position of the most significant bit in the BigInteger.
//
// Eg.  The result is 0, if the value of BigInteger is 0...0000 0000
//      The result is 1, if the value of BigInteger is 0...0000 0001
//      The result is 2, if the value of BigInteger is 0...0000 0010
//      The result is 2, if the value of BigInteger is 0...0000 0011
//
// ***********************************************************************
- (int)bitCount;

// ***********************************************************************
// Returns a string representing the BigInteger in sign-and-magnitude
// format in the specified radix.
//
// Example
// -------
// If the value of BigInteger is -255 in base 10, then
// [self toStringWithRadix:16] returns "-FF"
//
// ***********************************************************************
- (NSString *)toStringWithRadix:(int)radix;

// ***********************************************************************
// Modulo Exponentiation
// ***********************************************************************
- (STBigInteger *)modPow:(STBigInteger *)exp withMod:(STBigInteger *)mod;

// ***********************************************************************
// Populates "this" with the specified amount of random bits
// ***********************************************************************
- (void)getRandomBits:(int)bits;

// ***********************************************************************
// Generates a positive BigInteger that is probably prime.
// ***********************************************************************
+ (STBigInteger *)generatePseudoPrimeWithBits:(int)bits andConfidence:(int)confidence;

+ (STBigInteger *)generateNumberWithBits:(int)bits;

// ***********************************************************************
// Determines whether this BigInteger is probably prime using a
// combination of base 2 strong pseudoprime test and Lucas strong
// pseudoprime test.
//
// The sequence of the primality test is as follows,
//
// 1) Trial divisions are carried out using prime numbers below 2000.
//    if any of the primes divides this BigInteger, then it is not prime.
//
// 2) Perform base 2 strong pseudoprime test.  If this BigInteger is a
//    base 2 strong pseudoprime, proceed on to the next step.
//
// 3) Perform strong Lucas pseudoprime test.
//
// Returns True if this BigInteger is both a base 2 strong pseudoprime
// and a strong Lucas pseudoprime.
//
// For a detailed discussion of this primality test, see [6].
//
// ***********************************************************************
- (BOOL)isProbablePrime;

// ***********************************************************************
// Determines whether a number is probably prime, using the Rabin-Miller's
// test.  Before applying the test, the number is tested for divisibility
// by primes < 2000
//
// Returns true if number is probably prime.
// ***********************************************************************
- (BOOL)isProbablePrimeWithConfidence:(int)confidence;

// ***********************************************************************
// Performs the calculation of the kth term in the Lucas Sequence.
// For details of the algorithm, see reference [9].
//
// k must be odd.  i.e LSB == 1
// ***********************************************************************
+ (NSMutableArray *)lucasSequence:(STBigInteger *)P andQ:(STBigInteger *)Q andk:(STBigInteger *)k andn:(STBigInteger *)n andConstant:(STBigInteger *)constant ands:(int)s;

// ***********************************************************************
// Probabilistic prime test based on Rabin-Miller's
//
// for any p > 0 with p - 1 = 2^s * t
//
// p is probably prime (strong pseudoprime) if for any a < p,
// 1) a^t mod p = 1 or
// 2) a^((2^j)*t) mod p = p-1 for some 0 <= j <= s-1
//
// Otherwise, p is composite.
//
// Returns
// -------
// True if "this" is a strong pseudoprime to randomly chosen
// bases.  The number of chosen bases is given by the "confidence"
// parameter.
//
// False if "this" is definitely NOT prime.
//
// ***********************************************************************
- (BOOL)rabinMillerTestWithConfidence:(int)confidence;

// ***********************************************************************
// Fast calculation of modular reduction using Barrett's reduction.
// Requires x < b^(2k), where b is the base.  In this case, base is
// 2^32 (uint).
//
// Reference [4]
// ***********************************************************************
+ (STBigInteger *)barrettReduction:(STBigInteger *)x andN:(STBigInteger *)n andConstant:(STBigInteger *)constant;

+ (void)singleByteDivide:(STBigInteger *)bi1 bi2:(STBigInteger *)bi2 outQuotient:(STBigInteger *)outQuotient outRemainder:(STBigInteger *)outRemainder;
+ (void)multiByteDivide:(STBigInteger *)bi1 bi2:(STBigInteger *)bi2 outQuotient:(STBigInteger *)outQuotient outRemainder:(STBigInteger *)outRemainder;

+ (int)shiftLeft:(uint *)buffer withSizeOf:(int)bufferSize bits:(int)shiftVal;
+ (int)shiftRight:(uint *)buffer withSizeOf:(int)bufferSize bits:(int)shiftVal;

+ (BOOL)lucasStrongTest:(STBigInteger *)thisVal;
+ (int)jacobi:(STBigInteger *)a andB:(STBigInteger *)b;

// Hashing

- (NSString *)sha256;
- (NSString *)sha512;

- (NSString *)sha256:(NSString *)input;
- (NSString *)sha512:(NSString *)input;

@end
