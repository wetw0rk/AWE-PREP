/* The <limits.h> Header File */

The <limits.h> header file provides the minimum and maximum representable
values for the various integer types.

/* Declaring Integers */

Unless declared as unsigned, integer types are assumed to be signed (except
for char which can go either way). Below are valid declarations of unsigned
integers:

```
unsigned int ui; // unsigned required
unsigned u; // int can be omitted
unsigned long long ull2; // int can be omitted
unsigned char us; // unsigned required
```

When declaring signed integer types, you can omit the signed keyword expect
for signed char. The following are all valid:

```
int i; // signed can be omitted
long long int sll; // signed can be omitted
long long sll2; // signed and int can be omitted
signed char sc; // signed required
```

/* Wraparound */

Wraparound occurs when you perform arithmetic operations that result in 
values too small (less than 0) or too large (greater than 2^n - 1) to
be respresented as a particular unsigned integer type.

For example the code below initializes ui to its maximum value and then
increments it. The resulting value cannot be represented as an unsigned
int, so it wraps around to 0. If this value is then decremented, it will
fall outside range once more, so it wraps around again to UINT_MAX:

```
unsigned int ui = UINT_MAX; // 4,294,967,295 on x86
ui++
printf("ui = %u\n", ui); // ui is 0
ui--;
printf("ui = %u\n", ui); // ui is 4,294,967,295
```

It's important to check for wraparound by using the limits from <limits.h>.
We should be careful though as it's easy to make mistakes. For example the
fillowing code contains a defect as sum + ui can never be larger than UINT_MAX:

```
extern unsigned int ui, sum;
// assign values to ui and sum
if (sum + ui > UINT_MAX)
  too_big();
else
  sum = sum + ui;
```

If the result of sum + ui is larger than UINT_MAX, it's reduced modulo
UINT_MAX + 1. Therefore, this entire test is useless. To remedy this,
we can subtract sum from both sides of the inequality to form the
following effective test:

```
extern unsigned int ui, sum;
// assign values to ui and sum
if (ui > UINT_MAX - sum)
  too_big();
else
  sum = sum + ui;
```

/* An Example of Implicit Conversion */

The following example illustrates the use of integer conversion rank,
integer promotions, and the usual arithmetic conversions. This code
compares the signed char value c for equality with the unsigned int
value ui. We'll assume this code was compiled on an x86 machine:

```
unsigned int ui = UINT_MAX;
signed char c = -1;
if (c == ui) {
  puts("-1 equals 4,294,967,295")
}
```






















