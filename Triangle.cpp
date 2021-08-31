#include "Triangle.h"

Triangle::Triangle(int x, int y, std::string fill, std::string pen) 
{
	setX(x);
	setY(y);

	setX2(x + 10);
	setY2(y + 10);

	setX3(x + 15);
	setY3(y + 15);

	setPen(pen);
	setFill(fill);
}

Triangle::~Triangle()
{
}

inline void Triangle::setX2(int newX2) 
{
	x2 = newX2;
}
inline void Triangle::setY2(int newY2)
{ 
	y2 = newY2; 
}

inline void Triangle::setX3(int newX3)
{
	x3 = newX3;
}
inline void Triangle::setY3(int newY3)
{
	y3 = newY3;
}


inline int Triangle::getX2() 
{ 
	return x2;
}
inline int Triangle::getY2()
{
	return y2;
}

inline int Triangle::getX3() 
{
	return x3;
}
inline int Triangle::getY3() 
{ 
	return y3; 
}


void Triangle::draw(EasyGraphics* window)
{
	window->drawTriangle(getX(), getY(), getX2(), getY2(), getX3(), getY3(), true);
}

bool Triangle::hitTest(int testX, int testY)
{
	return (testX >= getX() && testX < (getX() + getX2())
		&&
		testY > getY() && testY < (getY() + getY2()));
}

void Triangle::drawSelection (EasyGraphics* window)
{
	window->setPenColour(EasyGraphics::GREY, 4);
	window->drawTriangle(getX(), getY(), getX2(), getY2(), getX3(), getY3(), true);
}

inline void Triangle::move(int x, int y)
{
	setX(x);
	setY(y);
}
