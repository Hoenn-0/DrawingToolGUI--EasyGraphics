#pragma once
#include "Shape.h"
#include "EasyGraphics.h"
class Triangle : public Shape
{
private:
	int x2 = 0;
	int y2 = 0;

	int x3 = 0;
	int y3 = 0;

public:
	Triangle(int x, int y, std::string fill, std::string pen);
	~Triangle();

	void setX2(int newX2);
	void setY2(int newY2);

	int getX2();
	int getY2();

	void setX3(int newX3); 
	void setY3(int newY3);

	int getX3();
	int getY3();

	void draw(EasyGraphics* window);
	bool hitTest(int testX, int testY);
	void move(int x, int y);
	void drawSelection(EasyGraphics* window);


};


