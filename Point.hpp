
#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
class Point
{
private:
    double x;
    double y;
public:
	double getX();
	double getY();
	void setX(double _x);
	void setY(double _y);
};

#endif /* Point_hpp */
