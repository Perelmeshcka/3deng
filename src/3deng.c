#include "draw.h"

int
main(int argc, char *argv[])
{
  init();
  while (is_open())
  {
    events();
    tick();
  }

  close();
  return 0;
}
