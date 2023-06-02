/* 
 * CS:APP Data Lab 
 * 
 * <Szymon Ligas, szli6792>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically and a negative shift value results in zero.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES, FOLLOW THE DIRECTIONS in README.md
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
 
int bitOr(int x, int y) {
    // From CSCI 2820: (X ∨ Y) is logicaly equivalent to ¬(¬X ∧ ¬Y), according to De Morgan's Laws. This is how I do bitwise OR using bitwise AND and BITWISE negation.
  return ~(~x & ~y);
}

/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */

int isZero(int x) {
    /* In C and C++, every number that is not 0 is true, and only 0 is false.
    Negating 0 returns 1, which is true.
    Negating any number that is not zero returns 0, which is false.
    */
  return !x;
}

/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */

int tmax(void) {
    /* A byte is 8 bits. An int has 4 bytes. Therefore, an int has 32 bits. If it is signed, 
    0111 1111 1111 1111 1111 1111 1111 1111 represents the largest value for an int.
    I can negate 1000 0000 0000 0000 0000 0000 0000 0000
    with ~ to get:
    0111 1111 1111 1111 1111 1111 1111 1111 (It switches every bit)
    
    However, to get 1000 0000 0000 0000 0000 0000 0000 0000,
    I can start with 0000 0000 0000 0000 0000 0000 0000 0001, which is bitwise 1,
    and left shift it by 31 spaces.
    Therefore, I can left shift 1 by 31, and then do a BITWISE negation with ~.
    */
  return ~(1 << 31);
}

/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */

int anyOddBit(int x) {
    /* A in hexidecimal is 1010 (A half-byte that has value 1 in place of all odd numbered bits). There is a value of 1 in the 2^1 position and 2^3 position.
    Expanded, 0xAAAAAAAA is an int that has 1's in all odd positions (1010 1010 1010 1010 1010 1010 1010 1010).
    We are forbidden from using 0xAAAAAAAA, so I need to make 0xAAAAAAAA out of 0xAA, using left shifting and OR gates.
    */
    int mask = (0xAA << 24) | (0xAA << 16) | (0xAA << 8) | 0xAA;
    /*
    Using bitwise AND, any int with a 1 in the odd position, combined with 0xAAAAAAAA, produces a non-zero int. 
    Using bitwise AND, any int without a 1 in the odd position, combined with 0xAAAAAAAA, produces an all 0 int (0000 0000 0000 0000 0000 0000 0000 0000).
    
    Now that we have only two possible cases:
    Logically negating a non-zero int returns 0. Negating it again returns 1.
    Logically negating a zero int returns 1. Negating it again returns 0.
    Our function now only returns 1 or 0, instead of some number or 0, depending on it having at least one odd bit.
    */
    return !(!(x & mask));
}

/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
             
int fitsBits(int x, int n) {
  /* A signed n-bit can fit an int x, if int x is less than 2**(n-1), and greater than or equal to -2**(n-1).
  
  Because we cannot use substraction as a legal operator, we need to find a way to compute n + (-1).
  -1 can be represented by bitwise negating 0:
  ~0, which is ~(0000 0000 0000 0000 0000 0000 0000 0000) in bitwise, simplifies to 1111 1111 1111 1111 1111 1111 1111 1111, which is equal to -1. (-2**32 + 2**31 + ... + 2*1 + 2*0 == -1)
  So, our conditional equation is now -2**(b) ≤ x < 2**(b), where our binary exponent b = n - 1.
  
  We can start with computing the binary exponent that log2(x) must be greater than, in the case of negative x, or less than or equal to, in the case of positive x:
  */
  int binary_exponent = n + ~0;
    
  /* This binary exponent b is giving us the number of bits the n-bit can accomodate.
     Now that we have two cases for our logic, based off our equation, we can use shifting to check the size of b relative to x.
  
    In the case that x is negative, if its binary representation is right shifted by b places,
    and it returns a bitwise non-zero integer (a bitwise int that has any non-zero bits), it is indeed greater than the binary representation for n, and it fits.
    If it returns bitwise 0, it is less than or equal to n, and it does not fit.
    
    In the case that x is positive, if its binary representation is shifted by b places, and it returns a bitwise non-zero integer (a bitwise int that has any non-zero bits), then x is also greater than the binary representation for n,
    but this means it has failed our initial equation, and does not fit.
    If it returns bitwise 0, it is less than or equal to n, and it does fit.
    
    The common thing between our two cases is the need to right shift x by our binary exponent:
  */
   int shifted = x >> binary_exponent;  // I DID NOT ACCOUNT FOR ARITHMETIC SHIFT!
   
   /*
    Given these two cases, we need to find a way to determine if x is positive or negative:
    
    The leading bit in a signed int determines whether the bit is positive or negative. (0 or 1 respectively)
    By right shifting the signed int x by 31, we can find the sign, because a 32 bit int shifted over 31 places gives us either 0000 0000 0000 0000 0000 0000 0000 0000
    or 0000 0000 0000 0000 0000 0000 0000 0001 (bitwise for 0 or 1).
   */
  int sign = x >> 31;   // I DID NOT ACCOUNT FOR ARITHMETIC SHIFT!
   
  /*  If the int x we are testing is positive, int sign = 0, and if shifting returns a non-zero integer, int shifted = 1, we need to show that fitsBits failed and returns 0.
      If the int x we are testing is positive, int sign = 0, and if shifting returns zero, int shifted = 0, we need to show that fitsBits worked and returns 1.
      If the int x we are testing is negative, int sign = 1, and if shifting returns a non-zero integer, int shifted = 1, we need to show that fitsBits worked and returns 1.
      If the int x we are testing is positive, int sign = 1, and if shifting returns zero, int shifted = 0, we need to show that fitsBits failed and returns 0.
      
      Therefore, our truth table should be:
      sign   shifted    return
       0        1         0
       0        0         1
       1        1         1
       1        0         0
       
       This is a XAND gate (exclusive and). A XAND gate can be constructed by logically negating an exclusive or (XOR) gate.
       Therefore, we can use operators ! and ^ respectively to combine our int sign and int shifted:
  */ 
  return !(sign ^ shifted);   
}
             
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
  /*   0 & (~0 + 1) produce 0: (If x == 0, return 0)
  0000 0000 0000 0000 0000 0000 0000 0000
  1111 1111 1111 1111 1111 1111 1111 1111 + 1 (the overflow case)
  ---------------------------------------
  0000 0000 0000 0000 0000 0000 0000 0000
  
      1 & (~1 + 1) produce 1: (an odd int will always have a 1 in its rightmost bit)
  0000 0000 0000 0000 0000 0000 0000 0001
  1111 1111 1111 1111 1111 1111 1111 1110 + 1
  ---------------------------------------
  0000 0000 0000 0000 0000 0000 0000 0001
  
      2 & (~2 + 1) produce 2: (a number that can be represented by 2**n for some n will always return itself as the rightmost 1 bit)
  0000 0000 0000 0000 0000 0000 0000 0010
  1111 1111 1111 1111 1111 1111 1111 1101 + 1
  ---------------------------------------
  0000 0000 0000 0000 0000 0000 0000 0010
  
      3 & (~3 + 1) produce 1: (an odd int will always have a 1 in its rightmost bit)
  0000 0000 0000 0000 0000 0000 0000 0011
  1111 1111 1111 1111 1111 1111 1111 1100 + 1
  ---------------------------------------
  0000 0000 0000 0000 0000 0000 0000 0001

  So, we know this format works for all odds.
  
      4 & (~4 + 1) produce 4: (a number that can be represented by 2**n for some n will always return itself as the rightmost 1 bit)
  0000 0000 0000 0000 0000 0000 0000 0100
  1111 1111 1111 1111 1111 1111 1111 1011 + 1
  ---------------------------------------
  0000 0000 0000 0000 0000 0000 0000 0100

      6 & (~6 + 1) produce 2:
  0000 0000 0000 0000 0000 0000 0000 0110
  1111 1111 1111 1111 1111 1111 1111 1001 + 1
  ---------------------------------------
  0000 0000 0000 0000 0000 0000 0000 0010
  
       8 & (~8 + 1) produce 8: (a number that can be represented by 2**n for some n will always return itself as the rightmost 1 bit)
  0000 0000 0000 0000 0000 0000 0000 1000
  1111 1111 1111 1111 1111 1111 1111 0111 + 1
  ---------------------------------------
  0000 0000 0000 0000 0000 0000 0000 1000
  
       10 & (~10 + 1) produce 2: 
  0000 0000 0000 0000 0000 0000 0000 1010
  1111 1111 1111 1111 1111 1111 1111 0101 + 1
  ---------------------------------------
  0000 0000 0000 0000 0000 0000 0000 0010 
  
        12 & (~12 + 1) produce 4:
  0000 0000 0000 0000 0000 0000 0000 1100
  1111 1111 1111 1111 1111 1111 1111 0011 + 1
  ---------------------------------------
  0000 0000 0000 0000 0000 0000 0000 0100
  
        14 & (~14 + 1) produce 2:
  0000 0000 0000 0000 0000 0000 0000 1110
  1111 1111 1111 1111 1111 1111 1111 0001 + 1
  ---------------------------------------
  0000 0000 0000 0000 0000 0000 0000 0010
  
  We have now proven that all even cases for our rightmost byte are handled correctly. If we left-shift our even cases however many bytes, the basic logic remains the same for any even int.
  Therefore, we can insert x into our order of operations for the general case:
  */
  return x & (~x + 1);
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    /*  0x30 <= x <= 0x39 is the hexidecimal equivalent of 48 <= x <= 57
    
        0x39 is the top of our range:                   (0000 0000 0000 0000 0000 0000 0011 1001)
        ~0x39, the bitwise negation, flips all the bits: 1111 1111 1111 1111 1111 1111 1100 0110
        
        If int x is greater than 0x39, adding it to ~0x39 will always produce a positive number, because it will cascade up the sequence of 1-bits in binary addition, and leave a leading 0 (the bit that signs the int).
        If int x is equal to or less than 0x39, adding it to ~0x39 will always produce a negative number, because this number cannot change the leading 1-bit.
        
        We can check if the leading bit of this result is 1, by right shifting it by 31 after addition:
    */
    int isGreaterThanUpperBound = (x + (~0x39)) >> 31; // this int must be 1 for function to return true (return 1)
    
    /*  0x30 is the bottom of our range:                   (0000 0000 0000 0000 0000 0000 0011 0000)
        ~0x30, the bitwise negation, flips all the bits: 1111 1111 1111 1111 1111 1111 1100 1111
        
        If int x is greater than 0x30, adding it to ~0x30 will always produce a positive number, because it will cascade up the sequence of 1-bits in binary addition, and leave a leading 0 (the bit that signs the int).
        If int x is equal to or less than 0x30, adding it to ~0x39 will always produce a negative number, because this number cannot change the leading 1-bit.
        
        However, we are looking for logic that seperates two categories: greater than or equal to, or less than.
        Therefore, let's use 0x2f as the bottom of our range instead (this is the next bit in the range down from 0x30, when using hexacdemial, and is the equivalent of 47).
        The greater than logic now satisfies the lower bound for our range perfectly.
        
        We can again check if the leading bit of this result is 1, by right shifting it by 31 after addition:
    */    
    int isGreaterThanLowerBound = (x + (~0x2f)) >> 31; // this int must be 0 for the function to return true (return 1)
    /* Now we need to combine our two boolean values to return the correct outcome
    
    We need:
    
    isGreaterThanUpperBound    isGreaterThanLowerBound      result
                1                        0                    1
                0                        0                    0
                1                        1                    0
                0                        1                    0
                
    From CSCI 2824: Notice this is the negation of a conditional statement, ¬(P → Q), which is logically equivalent to ¬(¬P ∨ Q)
    Therefore, we can use | and ! operators to combine our boolean balues:
    */
  return !((!isGreaterThanUpperBound) | isGreaterThanLowerBound);  // I DID NOT ACCOUNT FOR ARITHMETIC SHIFT!
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    /*  
        Let's see if y is greater than x. If yes, than this should return 1, otherwise 0.
        If y - x returns a positive number or 0, then it is greater than.
        Therefore, we need to find a way to bitwise subtract x.
        Subtraction is the same as adding the negative number.
        Therefore, we need to first translate y to its bitwise negative counterpart. (~0 = -1, ~1 = -2, ~2 = -3, ... , ~(2**32 - 1) = -2**32)
        
        For a positive integer, notice that the ~ operator always returns the negative integer counterpart - 1, aka -(x + 1).
        By adding 1 to -(x + 1), we always find the negative integer counterpart.
        Therefore, we are looking for the first bit of y + (~x + 1) to be 0, indicating that it is positive.
        We can do this by right shifting the bit.
        The ! operator changes 0000 0000 0000 0000 0000 0000 0000 0000 to true, and 1111 1111 1111 1111 1111 1111 1111 1111 to false.
    */        
    int positiveANDpositive = !((y + (~x + 1)) >> 31);
    /*  
        However, there can be an overflow error when signs of x and y are different or both numbers are negative.
        To combat this, I can simply switch the inequality logic and make both numbers positive, recycling the same process.
    */
    int negativeANDnegative = ((x + (~y + 1)) >> 31);
    /*      
        If x is negative and y is positive, let's output 0 with conditional logic.
        If x is positive and y is negative, let's output 1 with conditional logic.
        
        To accomodate the cases, we need ints to store the signs of x and y.
        We use 0 to denote a positive sign, and 1 to denote a negative sign:
    */  
    int signX = (x >> 31) & 1;
    int signY = (y >> 31) & 1;
    
    // If the signs the not same, we use a 0 to nullify the previous logic with AND, and use the OR to pass the correct sign logic.
  return (positiveANDpositive & !(signX ^ signY)) | (negativeANDnegative & !(signX ^ signY)) | ((signX & 1) & (signX ^ signY));
}
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
    /*
        We need to isolate each of the four bytes, move each individually, and then recombine them.
        We can recombine them with OR gates.
        
        To isolate a byte, I can use a byte that is all 1-bit's (1111 1111) and use an and statement:
    */
    int mask = 0xff; // Same as 0000 0000 0000 0000 0000 0000 1111 1111
    /*
        To select the first rightmost byte, I just use an and statement with the input x.
        To select the second rightmost byte, I first left shift the mask over by a byte, and use an and statement with the input x.
        To select the third and fourth remaining bytes, I left shift over by their respective lengths and repeat the same process as in the first and second bytes:
    */
    int byte1 = mask & x;
    int byte2 = (mask << 8) & x;
    int byte3 = (mask << 16) & x; 
    int byte4 = (mask << 24) & x; 
    /*
        Now I need to reorder the bytes to their respective positions, using the appropriate left or right shifts:
    */    
    int newbyte1 = (byte4 >> 24) & 0xFF; // We use & 0x000000FF to clear the 2 leading bytes from copying 1's, just in case they are created by arithmetically right shifting.
    int newbyte2 = (byte3 >> 8) & ((0xFF << 8) | 0xFF); // We use & 0x0000FFFF to clear the 2 leading bytes from copying 1's, just in case they are created by arithmetically right shifting.
    int newbyte3 = byte2 << 8;
    int newbyte4 = (byte1 << 24);
    // Combining these four bytes with OR operators will produce a 32-bit output:
  return newbyte1 | newbyte2 | newbyte3 | newbyte4;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    /*
        We could take  1 (0000 0000 0000 0000 0000 0000 0000 0001) and left-shift by one position each time we want to compare it with a singe bit in our input using an AND gate.
        Then we would double negate it with !!, which returns a count of one. For each of the 32 positions, we could count how many 1-bits there are.
        However, this process involves way over 40 operations.
        
        To reduce the number of operations, we need to break up our 32-bit int into a bunch of very small manageable pieces.
        There is a divide and conquer algorithm that can break it into 16 adjacent 2-bits, using evens and odds.
        It takes all the even bits (masked by an AND gate and 0xAAAAAAAA), and right shifts them by 1, so that they can be added to all the odd bits (masked by an AND gate and 0x55555555).
        Becuase I am limited to byte contants, I need to make a bunch of masks from 0xFF:
     */
    int mask_32bit = 0xff | (0xff << 8);
    int mask_16bit = mask_32bit ^ (mask_32bit << 8);
    int mask_8bit = mask_16bit ^ (mask_16bit << 4);    
    int mask_4bit = mask_8bit ^ (mask_8bit << 2);     
    int mask_2bit = mask_4bit ^ (mask_4bit << 1); 
    
    x = (x & mask_2bit) + ((x >> 1) & mask_2bit);
    /*
        Now, our resulting 32-bit int x displays 16 adjacent 2-bits, each of which has a value of 2, 1, or 0 (represented in binary), depending on the sum of each adjacent even and odd bit in the original input.
        If we consider our 32-bit int as a list of 16 adjacent 2-bits, we can once again use the previous evens + odds technique to all the 16 2-bits in an alternating fashion.
        This requires us to use the half-byte masks 1100 and 0011, which represent C and 3 in hexidecimal.
        Therefore, our new masks should be 0xCCCCCCCC and 0x33333333, respectively, and we need to right shift the first mask by 2, because we are dealing with 2-bits now:
    */
    x = (x & mask_4bit) + ((x >> 2) & mask_4bit);
    /*
        Now, our resulting 32-bit int x displays 8 adjacent 4-bits, each of which has a value that is the sum of the previous 2-bits (represented in binary), depending on the sum of each adjacent even and odd 2-bit in the prior step.
        If we consider our 32-bit int as a list of 8 adjacent 4-bits, we can once again use the previous evens + odds technique to all the 8 4-bits in an alternating fashion.
        This requires us to use the half-byte masks 1111 and 0000, which represent F and 0 in hexidecimal.
        Therefore, our new masks should be 0xF0F0F0F0 and 0x0F0F0F0F, respectively, and we need to right shift the first mask by 4, because we are dealing with 4-bits now:
    */
    x = (x & mask_8bit) + ((x >> 4) & mask_8bit);
    /*
        Now, our resulting 32-bit int x displays 4 adjacent 8-bits, each of which has a value that is the sum of the previous 4-bits (represented in binary), depending on the sum of each adjacent even and odd 4-bit in the prior step.
        If we consider our 32-bit int as a list of 4 adjacent 8-bits, we can once again use the previous evens + odds technique to all the 4 8-bits in an alternating fashion.
        This requires us to use the byte masks 1111 1111 and 0000 0000, which represent FF and 00 in hexidecimal.
        Therefore, our new masks should be 0xFF00FF00 and 0x00FF00FF, respectively, and we need to right shift the first mask by 8, because we are dealing with 8-bits now:
    */    
    x = (x & mask_16bit) + ((x >> 8) & mask_16bit);
    /*
        Now, our resulting 32-bit int x displays 2 adjacent 16-bits, each of which has a value that is the sum of the previous 8-bits (represented in binary), depending on the sum of each adjacent even and odd 8-bit in the prior step.
        If we consider our 32-bit int as a list of 2 adjacent 16-bits, we can finally now simply add them together to output a 32-bit int that has accounted for all the 1's in out initial input.
        This requires us to use the 2-byte masks 1111 1111 1111 1111 and 0000 0000 0000 0000, which represent FFFF and 0000 in hexidecimal.
        Therefore, our new masks should be 0xFFFF0000 and 0x0000FFFF, respectively, and we need to right shift the first mask by 16, because we are dealing with 2 16-bits now.
        We can return this result:
    */      
  return (x & mask_32bit) + ((x >> 16) & mask_32bit);
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    /*
        As shown previously, (~x + 1) is the way to get any x*(-1), aka, flip that integer from negative to positive, or positive to negative.
        So, 0 will always flip to 0.
        
        Operation 1: 
        Any positive int, multiplied by negative 1, produces a negative int, which can be right shifted by 31 to make -1, due to arithmetic copying of the leading 1-bit.
        0, mutliplied by negative 1, produces a positive int, which can be right shifted by 31 to make 0. 
        Any negative int, mutliplied by negative 1, produces a positive int, which can be right shifted by 31 to make 0.
        
        
        Operation 2: 
        Any positive int and 0, right shifted by 31, will produce 0.
        Any negative int, right shifted by 31, will produce -1, due to arithmetic copying of the leading 1-bit.
        
        
        Case 1: a positive non-zero input produces -1 after Operation 1, and 0 after operation 2.
        Case 2: a negative input produces 0 after Operation 1, and -1 after operation 2.
        Case 3: a input of 0 produces 0 after Operation 1, and 0 after operation 2.
        
        To return 1 from Case 3, we need to OR the two operations to get 0, and add 1.
  
        To return 0 from Case 1 and 2, we need to OR the two operations to get -1, then add 1 to cause a cascade across the full-bit, and resets it to 0:
    */
  return (((~x + 1) >> 31) | (x >> 31)) + 1;
}
/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueFiveEighths(11) = 6
 *            trueFiveEighths(-9) = -5
 *            trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
 */
int trueFiveEighths(int x)
{
    /*
        To protect from overflow, it is in our interest to divide first before multiplying. This works here, because our function returns a fraction of the input, meaning that it will always be smaller than the input.
        
        Because binary creates 2^n representations of numbers, you can divide, modulus style, by any mutliple of 2 by right shifting the appropriate amount.
        (2**n)/2 is the same as 2**(n-1)
        (2**n)/4 is the same as 2**(n-2)
        (2**n)/8 is the same as 2**(n-3) etc.
        Therefore, to modulus divide by 8, the input can be right shifted by 3.
        However, right shifting destroys information.
        To recover that information (which is the remainder), we have to recover the same amount of bits that we shifted.
        We can do this using & 0x7 before we divide.
        
        This works for negative input as well, because right shifting is arithmetic, and losing 0's as a bitwise negative number means you are adding 2**n for whichever n-bit is turning from 0 to 1:
     */  
     int modulus;
     int remainder;
     int quotient;
     int isNegative;
     int overflow_screener = ~(0xE << 28);
    
     isNegative = x >> 31;
     x = (isNegative & (~x + 1)) + (~isNegative & x); //flips our signs
    
     modulus = (x >> 3) & overflow_screener; // screen for negative overflow
     remainder = x & 0x7;
     /*
        To multiply, we can do the same thing with left shift, but without having to worry about remainders.
        (2**n)*2 is the same as 2**(n+1)
        (2**n)*4 is the same as 2**(n+2)
        (2**n)*8 is the same as 2**(n+3) etc.
        Therefore, to multiply by 5, we can set aside a copy of out int, right shift it by 2 to return a mutliple of 4, then add it to the original to get a mutliple of 5.
     */
    modulus = modulus + (modulus << 2);
     /*
        We divided before multiplying to prevent overflow.
        However, this means that we need to also multiply our remainder, because our modulus division was not perfect.
        We can mutlply our remainder by 5 in he same way we mutliplied our result from modulus division.
     */
    remainder = remainder + (remainder << 2);
     /*
        Now, we have a new problem: our remainder was multiplied, but never divided by our original division.
        Multiplying made it larger, so we need to divide it again, save the new result
    */
    remainder = remainder >> 3;
     /*        
        Finally, we can add the main result of division and multiplication, the multiplied and divided remainder, and the remainder of the remainder.   
    */
    quotient = modulus + remainder;
    
    return (isNegative & (~quotient + 1)) + (~isNegative & quotient);  // Filters back from negative numbers
}
/*
 * Extra credit
 */
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
    unsigned exponent_mask;
    unsigned exponent;
    unsigned mantissa_mask;
    unsigned sign_mask;
    
    mantissa_mask = ~0 + (1 << 23);
    
    sign_mask = (1 << 31);
    
    exponent_mask = ~(sign_mask | mantissa_mask);
    exponent = exponent_mask & uf; 
    
    if ((exponent == exponent_mask) && (mantissa_mask & uf)) {
        return uf;
    }
    else {
        return uf + sign_mask; // if leading bit of uf is 0, it adds 1 to it (switches signes), if it is 1, it adds 1 to it to produce 0 via overflow (also switcheds signes)
    }
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
    /*        
      Multiplying by two in single-precision is the same as left shifting the exponent value by 1.
      However, if the exponent is 127, it turns to 255 after the shift, 
      which is the same as 128 after debias. (A value reserved for NaN and infinity)
      This edge case, as well as NaN input, need to be accounted for.
    */
    unsigned sign_mask;
    unsigned sign;
    unsigned mantissa_mask;
    unsigned mantissa;
    unsigned exponent_mask;
    unsigned exponent;
    
    sign_mask = (1 << 31);
    sign = uf & sign_mask;
    
    mantissa_mask = ~0 + (1 << 23);
    mantissa = mantissa_mask & uf;
    
    exponent_mask = ~(sign_mask ^ mantissa_mask);
    exponent = exponent_mask & uf;
    
    if ((exponent == exponent_mask) && (mantissa_mask & uf)) {
        return uf;
    }
    else if ((exponent == exponent_mask) && exponent) {
        return uf;
    }
    else if (uf == 0) {
        return 0;
    }
    else if (uf == sign_mask) {
        return sign_mask;
    }
    else if (exponent == 0) {
        return sign | (mantissa << 1);
    }
    else {
        exponent = exponent_mask & (exponent + mantissa_mask + 1);
        return sign | exponent | mantissa;
    }
}

/*  0x30 <= x <= 0x39 is the hexidecimal equivalent of 48 <= x <= 57
    
        ASCII is only a 7 bit character
        0x2f represents 0000 0000 0000 0000 0000 0000 0111 1111, the biggest possible ASCII encoding.
        ~0x2f, the bitwise negation, flips all the bits: 1111 1111 1111 1111 1111 1111 1000 0000
        
        If int x is an ASCII character, adding it to ~0x2f will always produce a negative number.
        If int x is not an ASCII character, adding it to ~0x2f will always produce a positive number, because it will cascade up the sequence of 1-bits in binary addition, and leave a leading 0.
        
        We can check if the leading bit of this result is 1, by right shifting it by 31 after addition:
        int isASCII = (x + (~0x2f)) >> 31;
*/
