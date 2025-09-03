/*

Tags are special naming mechanism for structs, unions, and enumerations.

NOTE: The following code is mostly psuedo

*/

struct s { /* s in the following structure is a tag */
  // --snip--
};


/* By itself, a tag is not a type and cannot be used to declare a
   variable. Instead you have to declare variables of this type as
   follows: */

struct s v;  /* instance of struct s */
struct s *p; /* pointer to struct s */

/* The names of unions and enumerations are also tags and not types,
   meaning that they cannot be used alone to declare a variable. For
   example: */

enum day { sun, mon, tue, wed, thu, fri, sat };
day today; // error
enum day tommorow; // OK

/* tags of structs, unions, and enums are defined in a seperate
   namespace from ordinary identifiers. This allows a C program
   to have both a tag and other identifier with the same name in
   the same scope: */

enum status { ok, fail }; // enumeration
enum status status(void); // function
struct s s; // we can even declare an object s of type struct s

/* You can think of struct tags as type names and define an alias for
   the tag by using a typedef. Here's an example: */

typedef struct s { int x; } t; /* This allows us to declare variables
                                  of type t instead of struct s */

typedef struct { int x; } t; /* we can rm the tag name entirely too */
