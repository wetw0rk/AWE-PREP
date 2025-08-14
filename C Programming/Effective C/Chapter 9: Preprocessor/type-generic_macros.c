/*

<math.h> has three sin functions (sin, sinf, and sinl) because each of the three
floating types (double, float, and long fouble, respectively) has a different
precision. Using generic selection expressions, you can define a single function
like identifier that delegates to the correct underlying implementation based on
the argument type when called.

This program defines a type-generic macro to select the correct variant of the
sin function from <math.h>

*/

/* The controlling expression (X) of the generic selection expression is
   unevaluated; the type of the expresion selects a function from the list
   if type : expr mappings. */
#define sin(X) _Generic((X), \
  float: sinf, \
  double: sin, \
  long double: sinl \
)(X)

int main(void) {
  float f = sin(1.5708f); // sinf(1.5708f);
  double d = sin(3.14159); // sin(3.14159);
}
