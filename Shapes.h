#pragma once
#include "Shape.h"

class Shapes
{

private:
	static Shapes* instance;
	std::vector<Shape*> shapes;

public:
	Shapes();
	~Shapes();

	static Shapes* getShapes();

	void addShape(Shape* newShape);
	void deleteShape(int index);

	std::vector<Shape*> getShapesVector();	

	static void destructShapes();

};


