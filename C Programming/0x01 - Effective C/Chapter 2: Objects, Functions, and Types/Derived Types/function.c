/*

Function types are derived types. In this case, the type is derived from the
return type and the number and types of its parameters. The return type of a
function cannot be an array type.

*/

/* Function Prototype Examples */

void example(void)
{
  int f(void); // declare function f no parameters that returns an int
  int *fip(); // declare function fip, no specified parameters that returns pointer to an int (WRONG)
  void g(int i, int j); // declare function g, takes 2 parameters and return void (CORRECT CODE PRACTICE)
  void h(int, int); // declare function h, takes 2 parameters and return void (BAD CODE)
}

/*

WTF IS WRONG WITH FIP()?:

  In a function declaration, specifying paramters is optional. However, failing to do so is
  occasionally problematic.

  If you were to write the function declaration for fip in C++, it would declare a function
  accepting no arguments and returning an int *.

  In C, fip declares a function accepting any number of arguments of any type and returning
  an int *. You should NEVER declare functions with an empter parameter list in C. Use void
  instead: `int *fip(void)`

*/
