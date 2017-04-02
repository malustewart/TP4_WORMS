#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
class Point
{
private:
    float x;
    float y;
public:
    float getX(){return x;}     //se que esta medio cabeza, hay que corregirlo depsues y ponerle un .cpp
    float getY(){return y;}
    void setX(float _x){x = _x;}
    void setY(float _y) {y = _y;}
};

#endif /* Point_hpp */
