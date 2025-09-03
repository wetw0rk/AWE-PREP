/*

Enumerations allow us to define a type that assigns names to constant values. If we
don't specify a value to the first enumerator with = the enumeration constant will
be set to 0, and each following enum will be incremented by 1.

You can also assign specific values to each enumerator, as shown by the cardinal_points.

The months enumeration sets the first enumerator to 1, and each subsequent enumerator
that isn't specifically assigned a value will be incremented by 1.

*/

enum dat { sun, mon, tue, wed, thu, fri, sat };
enum cardinal_points { north = 0, east = 90, south = 180, west = 270 };
enum months { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
