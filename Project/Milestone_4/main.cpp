#include <SFML/Graphics.hpp>
#include <time.h>
#include "point.hpp"
#include "character.hpp"
#include "event.cpp"

using namespace sf;

//This is here because having it anywhere else gave me a linker error.
//I'll try to figure out why but don't expect a miracle
//Or even a solution for that matter
void GenerateTileState(point plat[20]){
        for (int i = 0; i < 10; i++) {
    plat[i].changex (rand() % 400);
    plat[i].changey (rand() % 533);
    }
}

//At this point I'm sure the problem is how I set up the makefile
//but I'm too afraid of failure to change it
//Anyway here is the keyboard events
void LeftandRight(character& c){
    if (Keyboard::isKeyPressed(Keyboard::Right))
       c.plusx(3);
    if (Keyboard::isKeyPressed(Keyboard::Left))
       c.minusx(3);
}

//It sends everything to the renderwindow and readies that for rendering
void DrawEverything(RenderWindow& app, point plat[20], point badplat[20], Sprite sPlat, 
                    Sprite sBadPlat, Sprite sBackground, Sprite sPers){
    app.draw(sBackground);
    app.draw(sPers);
    for (int i = 0; i < 10; i++) {
        sPlat.setPosition(plat[i].getx(), plat[i].gety());
        sBadPlat.setPosition(badplat[i].getx(), badplat[i].gety());
        app.draw(sPlat);
        app.draw(sBadPlat);
    }

    app.display();
}

//This is vertical movement
void GibeMovement(character& c, point plat[20], point badplat[20], float& dx, float& dy){
    for (int i = 0; i < 10; i++){
        if ((c.getx() + 50 > plat[i].getx()) && (c.getx() + 20 < plat[i].getx() + 68) &&
            (c.gety() + 70 > plat[i].gety()) && (c.gety() + 70 < plat[i].gety() + 14) && (dy > 0))
        dy = -10;
        if ((c.getx() + 50 > badplat[i].getx()) && (c.getx() + 20 < badplat[i].getx() + 68) &&
            (c.gety() + 70 > badplat[i].gety()) && (c.gety() + 70 < badplat[i].gety() + 14) && (dy > 0))
            dy = 0;
    }
    //dx does nothing but it is there for future use
}

//This starts the movement of the character sprite
void GibeMomentum(character& c, float& dy){
    dy += 0.2;
    c.plusy(dy);
    if (c.gety() > 500)
         dy = -10;
}

//this randomizes the location of the platforms
void ShufflePlatforms(character& c, point plat[20], point badplat[20], float& dy, int h){
    if (c.gety() < h)
        for (int i = 0; i < 10; i++) {
           c.changey(h);
           plat[i].changey(plat[i].gety() - dy);
           if (plat[i].gety() > 533) {
                plat[i].changey(0);
                plat[i].changex(rand() % 400);
        }
        badplat[i].changey(plat[i].gety() - dy);
        if (badplat[i].gety() > 533) {
            badplat[i].changey(0);
            badplat[i].changex(rand() % 400);
        }
    }
}

int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(400, 533), "Land on Green!");
    app.setFramerateLimit(60);

    Texture t1, t2, t3, t4, t5;
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/platform.png");
    t3.loadFromFile("images/doodle.png");
    t4.loadFromFile("images/badplatform.png");
    t5.loadFromFile("images/gameover.png");

    Sprite sBackground(t1), sPlat(t2), sPers(t3), sBadPlat(t4), sGameOver(t5);

    point plat[20];
    point badplat[20];

    GenerateTileState(plat);
    GenerateTileState(badplat);

    character c(100, 100);

    int h = 200;
    float dx = 0, dy = 0;

    //Main loop
    while (app.isOpen()) {
        Event e;
        while (app.pollEvent(e)) {
            if (e.type == Event::Closed)
            app.close();
        }

        //All processing is done through these function calls
        LeftandRight(c);
        GibeMomentum(c, dy);
        ShufflePlatforms(c, plat, badplat, dy, h);
        GibeMovement(c, plat, badplat, dx, dy);
        sPers.setPosition(c.getx(), c.gety());
        DrawEverything(app, plat, badplat, sPlat, sBadPlat, sBackground, sPers);
    }

    return 0;
}
