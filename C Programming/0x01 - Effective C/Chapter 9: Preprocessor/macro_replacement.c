/* Any parameter in the replacement list preceded by a # token is replaced with a
   string literal preprocessing token that contains the text of the argument
   preprocessing tokens. */

#define STRINGIZE(x) #x
const char *str = STRINGIZE(12); // str = "12"

/* The preprocessor also deletes all instances of the ## preprocessing token in
   the replacement list, concatenating the preceding preprocessing token with
   the following token, which is called token pasting.
  
   The PASTE macro below is used to create a new identifier by concatenating foo,
   the underscore character (_), and bar. */

#define PASTE(x, y) ## _ ## y
int PASTE(foo, bar) = 12; // same as: int foo_bar = 12;
