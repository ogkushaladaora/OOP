#ifndef PROJECT_POINT_H
#define PROJECT_POINT_H


class point {
public:
    void changex (int newx);
    void changey (int newy);
    int getx();
    int gety();
private:
    int x, y;
};


#endif
