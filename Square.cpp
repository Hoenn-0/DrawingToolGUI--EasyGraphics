#include "Square.h"



Square::Square(int x, int y, int width, int height, std::string fill, std::string pen) : width(width), height(height)
{
	setX(x);
	setY(y);
	setPen(pen);
	setFill(fill);
}


Square::~Square()
{ }

void Square::draw(EasyGraphics* window)
{
	window->drawRectangle(getX(), getY(), width, height, true);
}

bool Square::hitTest(int testX, int testY)
{
	return (testX >= getX() && testX < (getX() + getWidth()) &&
		testY > getY() && testY < (getY() + getHeight()));
}

void Square::drawSelection(EasyGraphics* window)
{
	window->setPenColour(EasyGraphics::GREY, 4);
	window->drawRectangle(getX(), getY(), width+5, height+5, true);
}



