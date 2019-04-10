#include <SFML/Graphics.hpp>
#include <time.h>
#include "point.h"
using namespace sf;

int
main()
{
  srand(time(0));

  RenderWindow app(VideoMode(400, 533), "Doodle Game!");
  app.setFramerateLimit(60);

  Texture t1, t2, t3;
  t1.loadFromFile("images/background.png");
  t2.loadFromFile("images/platform.png");
  t3.loadFromFile("images/doodle.png");

  Sprite sBackground(t1), sPlat(t2), sPers(t3);

  point plat[20];

  for (int i = 0; i < 10; i++) {
    plat[i].changex (rand() % 400);
    plat[i].changey (rand() % 533);
  }

  int x = 100, y = 100, h = 200;
  float dx = 0, dy = 0;

  //Main loop
  while (app.isOpen()) {
    Event e;
    while (app.pollEvent(e)) {
      if (e.type == Event::Closed)
        app.close();
    }

    if (Keyboard::isKeyPressed(Keyboard::Right))
      x += 3;
    if (Keyboard::isKeyPressed(Keyboard::Left))
      x -= 3;

    dy += 0.2;
    y += dy;
    if (y > 500)
      dy = -10;

    if (y < h)
      for (int i = 0; i < 10; i++) {
        y = h;
        plat[i].changey(plat[i].gety() - dy);
        if (plat[i].gety() > 533) {
          plat[i].changey(0);
          plat[i].changex(rand() % 400);
        }
      }

    for (int i = 0; i < 10; i++)
      if ((x + 50 > plat[i].getx()) && (x + 20 < plat[i].getx() + 68) &&
          (y + 70 > plat[i].gety()) && (y + 70 < plat[i].gety() + 14) && (dy > 0))
        dy = -10;

    sPers.setPosition(x, y);

    app.draw(sBackground);
    app.draw(sPers);
    for (int i = 0; i < 10; i++) {
      sPlat.setPosition(plat[i].getx(), plat[i].gety());
      app.draw(sPlat);
    }

    app.display();
  }

  return 0;
}
