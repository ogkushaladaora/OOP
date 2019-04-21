#ifndef PROJECT_CHARACTER_H
#define PROJECT_CHARACTER_H

class character {
public:
    character(int newx, int newy)
    : x(newx), y(newy) {};
    void changex (int newx);
    void changey (int newy);
    void plusy (int newy);
    void minusy (int newy);
    void plusx (int newx);
    void minusx (int newy);
    int getx();
    int gety();

private:
    int x, y;
};

#endif
