Method 2:
It is a simple algorithm to reverse bits of the 32-bit integer. This algorithm uses the eight constant value for the reversing the bits and takes five simple steps.

In below section, I am describing the functioning of each step.

Steps 1:
num = (((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1));

This expression used to swap the bits.
Let an example, suppose num is 0100, after the above expression it will be 1000.

Steps 2:
num = (((num & 0xcccccccc) >> 2) | ((num & 0x33333333) << 2));

Above expression uses to swap the 2 bits of a nibble. Suppose num is 10 00, after the above expression, it will be 00 01.

Steps 3:
num = (((num & 0xf0f0f0f0) >> 4) | ((num & 0x0f0f0f0f) << 4));

An expression used to swaps the nibbles. like if num is 0011 0010 then after the above expression it will be 0010 0011.

Steps 4:
num = (((num & 0xff00ff00) >> 8) | ((num & 0x00ff00ff) << 8));

This statement uses to swap the bytes of an integer. Let num is 00001000 00001100, after the above expression, it will be 00001100 00001000.

Steps 5:
((num >> 16) | (num << 16));

The above expression uses to swap the half-word of an integer. Means that if the num is 0000000011001110 1000100100000110 after the above result number will be 1000100100000110 0000000011001110.

//bit reversal function
unsigned int ReverseTheBits(register unsigned int x)
{
x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
return((x >> 16) | (x << 16));
}

//bit reversal function
unsigned int ReverseTheBits(register unsigned int x)
{
 x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
 x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
 x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
 x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
 
 return((x >> 16) | (x << 16));
 
}
