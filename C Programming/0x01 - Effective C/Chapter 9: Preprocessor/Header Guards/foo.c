#include "bar.h"
#include "bar.h" // Repeated inclusion is
                 // usually not this obvious.

int main(void) {
  return func();
}
