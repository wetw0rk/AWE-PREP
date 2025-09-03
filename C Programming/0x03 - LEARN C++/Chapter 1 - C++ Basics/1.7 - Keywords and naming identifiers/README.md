# Keywords and naming identifiers

This section covers **keywords** used within C++. As of C++23, C++ reserves a set of 92 keywords for its own use.

Below is a list of all C++ keywords through C++23:

```
alignas
alignof
and
and_eq
asm
auto
bitand
bitor
bool
break
case
catch
char
char8_t (since C++20)
char16_t
char32_t
class
compl
concept (since C++20)
const
consteval (since C++20)
constexpr
constinit (since C++20)
const_cast
continue
co_await (since C++20)
co_return (since C++20)
co_yield (since C++20)
decltype
default
delete
do
double
dynamic_cast
else
enum
explicit
export
extern
false
float
for
friend
goto
if
inline
int
long
mutable
namespace
new
noexcept
not
not_eq
nullptr
operator
or
or_eq
private
protected
public
register
reinterpret_cast
requires (since C++20)
return
short
signed
sizeof
static
static_assert
static_cast
struct
switch
template
this
thread_local
throw
true
try
typedef
typeid
typename
union
unsigned
using
virtual
void
volatile
wchar_t
while
xor
xor_eq
```

C++ also defines special identifiers: `override, final, import, and module`. These have a specific meaning when used in certain contexts but are not reserved otherwise.

# Identifier naming best practices

Just for the sake of doing things the "right" way below are convential ways to name variables.

```c
int value;

int my_var_name;

int my_function_name();

int myVarName;

int myFunctionName();
```

**Best practice**: When working in an existing program, use the conventions of that program (even if they don’t conform to modern best practices). Use modern best practices when you’re writing new programs.

# Quiz

Based on how you should name a variable, indicate whether each variable name is conventional (follows best practices), unconventional (compiler will accept but does not follow best practices), or invalid (will not compile), and why.

```c
int sum {};              // conventional
int _apples {};          // unconventional
int VALUE {};            // unconventional
int my variable name {}; // invalid
int TotalCustomers {};   // unconventional
int void {};             // invalid
int numFruit {};         // conventional
int 3some {};            // invalid
int meters_of_pipe {};   // conventional
```
