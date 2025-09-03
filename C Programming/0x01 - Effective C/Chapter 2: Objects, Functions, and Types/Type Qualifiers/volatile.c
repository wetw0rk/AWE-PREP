/*

volatile object types are used to model memory-mapped input/output (I/O) ports, and
static constant volatile object types model memory-mapped input ports such as a real
time clock.

Notes also from:

  - https://barrgroup.com/embedded-systems/how-to/c-volatile-keyword):

n practice, only three types of variables could change:

  1) Memory-mapped peripheral registers
  2) Global variables modified by an interrupt service routine
  3) Global variables accessed by multiple tasks within multi-threaded application

*/

/* Peripheral Registers 

   Embedded systems contain peripheral registers whose values may change asynchronously
   to the program flow. As a very simple example consider an 8-bit status register that
   is memory mapped at address 0x1234. It's required that I poll the status register
   until it becomes non-zero. The naive and incorrect implementation would be as follows: */

   uint8_t *p_reg = (uint8_t *) 0x1234;

   do { ... } while ( 0 == *p_reg) // Wait for register to read non-zero

/* This code will almost certainly fail as soon as you turn compiler optimization on.
   That's because the compiler will generate assembly language (here for an 16-bit
   x86 processor) that looks something like this:

     mov p_reg, #0x1234
     mov a, @p_reg
   loop:
     ...
     bz loop

   The rationale of the optimizer is quite simple: having alread read the variable's
   value into the accumulator (on the second line of assembly), there is no need to
   reread it, since the value will always be the same. So from the 3rd line of asm,
   we enter an infinite loop.

   To force the compiler to do what we want, we should modify the declaration to: */

   uint8_t volatile *p_reg = (uint8_t volatile *) 0x1234;

/* The assembly langauge now looks like this: 

     mov p_reg, #0x1234
   loop:
     ...
     mov a, @p_reg
     bz loop 

   The desired behavior is thus achieved. */

int main()
{
  /* In the following code, the compiler must generate instructions to read 
     the value from port and then write this value back to port. */

  volatile int port;
  port = port;

  /* Without the volatile qualification, the compiler would see this as a no-op
     and potentially eliminate both the read and write. */
}
