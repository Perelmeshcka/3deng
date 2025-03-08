#include <CSFML/Graphics.h>
#include <stdint.h>

#include "config.h"

sfRenderWindow* window;

void
init()
{
  if (fullscreen)
    window = sfRenderWindow_create(sfVideoMode_getDesktopMode(),
                                   title,
                                   sfDefaultStyle,
                                   sfFullscreen | sfClose,
                                   NULL);
  else
    window = sfRenderWindow_create((sfVideoMode){width, height, bpp},
                                   title,
                                   sfDefaultStyle,
                                   sfResize | sfClose,
                                   NULL);
}

bool
is_open()
{
  return sfRenderWindow_isOpen(window);
}

void
close()
{
  if (is_open())
    sfRenderWindow_close(window);
  sfRenderWindow_destroy(window);
}

void
events()
{
  sfEvent event;
  while (sfRenderWindow_pollEvent(window, &event))
  {
    if (event.type == sfEvtClosed)
      close();
  }
}

void
tick()
{
  sfRenderWindow_display(window);
}

void
fill_background(uint8_t color[3])
{
  sfRenderWindow_clear(window, (sfColor){color[0], color[1], color[2], 100});
}

void
draw_triangle(int pa[2], int pb[2], int pc[2], int color[3])
{
  sfConvexShape* triangle = sfConvexShape_create();

  sfConvexShape_setPointCount(triangle, 3);
  sfConvexShape_setPoint(triangle, 0, (sfVector2f){pa[0], pa[1]});
  sfConvexShape_setPoint(triangle, 1, (sfVector2f){pb[0], pb[1]});
  sfConvexShape_setPoint(triangle, 2, (sfVector2f){pc[0], pc[1]});
  sfConvexShape_setFillColor(triangle, (sfColor){color[0], color[1], color[2], 100});

  sfRenderWindow_drawConvexShape(window, triangle, NULL);

  sfConvexShape_destroy(triangle);
}
