#pragma once
#include "EasyGraphics.h"
class Shape
{
public:
	Shape();
	~Shape();

	
	int getX();
	int getY();

	
	void setX(int newX);
	void setY(int newY);

	std::string getFill();
	void setFill(std::string newFill);
	std::string getPen();
	void setPen(std::string newPen);

	//Pure Virtual funcntions//abstract
	virtual void draw(EasyGraphics* window) = 0; // make sure drawing canvas is passed in
	virtual void move(int x, int y) = 0;
	virtual bool hitTest(int testX, int testY) = 0;
	virtual void drawSelection(EasyGraphics* window) = 0;

private:
	int x = 0;
	int y= 0;
	std::string fill;
	std::string pen;
};

//setters
inline void Shape::setFill(std::string newFill)
{
	fill = newFill;
}

inline void Shape::setPen(std::string newPen)
{
	pen = newPen;
}

inline void Shape::setX(int newX)
{
	x = newX;
}

inline void Shape::setY(int newY)
{
	y = newY;
}


//getters
inline int Shape::getX()
{
	return x;
}

inline int Shape::getY()
{
	return y;
}

inline std::string Shape::getFill()
{
	return fill;
}

inline std::string Shape::getPen()
{
	return pen;
}