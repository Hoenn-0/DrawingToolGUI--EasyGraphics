#pragma once
#include "Shape.h"
#include "EasyGraphics.h"
class Square : public Shape
{

private:
	int width;
	int height;

public:
	Square(int x, int y, int width, int height, std::string fill, std::string pen);
	~Square();
	
	void setHeight(int newHeight);
	void setWidth(int newWidth);
	int getWidth();
	int getHeight();

	void draw(EasyGraphics* window);
	bool hitTest(int testX, int testY);
	void move(int x, int y);
	void drawSelection(EasyGraphics* window);

};

inline void Square::move(int x, int y)
{
	setX(x);
	setY(y);
}

inline void Square::setWidth(int newWidth)
{
	width = newWidth;
}

inline void Square::setHeight(int newHeight)
{
	height = newHeight;
}

inline int Square::getWidth()
{
	return width;
}

inline int Square::getHeight()
{
	return height;
}