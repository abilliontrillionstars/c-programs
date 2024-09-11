//third program. like the name printer, but uses a prefab. use #define statements to fill in the blanks to print without modifying the code.

// Name: Ethan Ward
// Class: Systems Programming   Section: ETEC 2110-51
// Assignment: Lab 1, part 3
#include <stdio.h>
// Only #defines are allowed here in this program.
// You should fill them in.
#define NAME "Ethan Ward"
#define QUOTE "\"We have a saying in our field: \"Magic isn't\". It doesn't \"just work,\" it doesn't respond to your thoughts, you can't just throw fireballs or create a roast dinner from thin air.\""
#define ATTRIBUTION "   -qntm, \"Ra\"\n"
#define begin {
#define end }
#define write printf
#define writeln(x) printf(x); printf("\n")


main()
begin
  write("first");
  write("line");
  writeln(" ");
  writeln(NAME);
  writeln(QUOTE);
  writeln(ATTRIBUTION);
end
