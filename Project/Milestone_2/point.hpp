//
// Created by Daniel Ulinski on 2019-04-10.
//

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


#endif //PROJECT_POINT_H
