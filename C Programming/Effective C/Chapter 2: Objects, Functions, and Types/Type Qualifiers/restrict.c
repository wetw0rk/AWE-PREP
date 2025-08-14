/*

A restrict pointer is used to promote optimization.

Notes links:

  https://en.wikipedia.org/wiki/Restrict

*/

/* If the compiler knows that there is only one pointer to a memory block, it can
   produce better optimized code for instance:

     void updatePtrs(size_t *ptrA, size_t *ptrB, size_t *val)
     {
       *ptrA += *val;
       *ptrB += *val;
     }

   In the above code, the pointers ptrA, ptrB, and val might refer to the same
   memory location, so the compoler may generate less optimal code:

     ; Hypothetical RISC Machine.
     ldr r12, [val]     ; Load memory at val to r12. <-----------------------------+- *ptrA += *val;
     ldr r3, [ptrA]     ; Load memory at ptrA to r3.                               |
     add r3, r3, r12    ; Perform addition: r3 = r3 + r12.                         |
     str r3, [ptrA]     ; Store r3 to memory location ptrA, updating the value. ]--+

     ldr r3, [ptrB]     ; 'load' may have to wait until preceding 'store' completes
     ldr r12, [val]     ; Have to load a second time to ensure consistency
     add r3, r3, r12
     str r3, [ptrB]

   However, if the restrict keyword is used and the above function is declared as

     void updatePtrs(size_t *restrict ptrA, size_t *restrict ptrB, size_t *restrict val);

   then the compiler is allowed to assume that ptrA, ptrB, and val point to different locations
   and updating the memory location referenced by on pointer will not affect the memory locations
   referenced by the other pointers.

   The programmer, not the compiler, is responsible for ensuring that the pointers do not point to
   identical locations. The compiler can rearrange the code, first loading all memory locations,
   then performing the operations before committing the results back to memory.

     ldr r12, [val]  ; Note that val is now only loaded once
     ldr r3, [ptrA]  ; Also, all 'load's in the beginning ..-.
     ldr r4, [ptrB]
     add r3, r3, r12
     add r4, r4, r12
     str r3, [ptrA]  ; ... all 'store's in the end.
     str r4, [ptrB]

   The above asm is shorter because val is loaded only once. Also, since the compiler can
   rearrange the code more freely, the compiler can generate code that executes faster. in
   the second version of the above example, the store operations are all taking place after
   the load operations, ensuring that the processor won't have to block in the middle of the
   code to wait until the store operations are complete. */


/* f: Copies n bytes from the storage referenced by q to the storage referenced by p.
      The function parameters p and q are both restrict pointers.
     
      Because both p and q are restrict pointers, the compiler can assume that an
      object accessed through one of the pointer parameters is not also accessed
      through the other.

      Although using restrict pointers can result in more efficient code, you must
      ensure that the pointers do not refer to overlapping memory to prevent
      undefined behavior. */
void f(unsigned int n, int * restrict p, int * restrict q) {
  while (n-- > 0) {
    *p++ = *q++;
  }
}










































