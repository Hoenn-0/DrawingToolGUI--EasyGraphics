#include "DrawingTool.h"
#include <algorithm>
#include "Button.h"
#include "Shapes.h"
#include "Triangle.h"
#include "Square.h"
#include "Line.h"

/*
* ToDo
Naming convention: lowerCamelCase Function and Variables and Upper for Class X
shorten and remove comments redundant  X
use algorithm X

*/

DrawingTool::DrawingTool(HINSTANCE hInstance)
{
	setImmediateDrawMode(false); // - flickering - true
	create(hInstance, 800, 700, 40, true);
	waitForClose();
}

// Heap memory clean up // for every new keyword. Add a delete keyword (Pairs)
DrawingTool::~DrawingTool()
{

	for (auto aButton : buttons)
	{
		delete aButton;
	}

	delete workingShape;
	Shapes::destructShapes();
}

//DrawingTool::
int CallBackFunctions::onLineButton() 
{
	return 1;
}
//DrawingTool::
int CallBackFunctions::onTriangleButton()
{
	return 2;
}
//DrawingTool::
int CallBackFunctions::onSquareButton()
{
	return 3;
}


void DrawingTool::test()
{
	int x = 0;
	//return 5 + 10;
}

typedef void (*my_func_ptr_T)();


void DrawingTool::initializeButtons()
{
	/*my_func_ptr_T foo;
	foo = &test;*/
	/*int (*func1) ();
	func1 = &DrawingTool::test;*/

	// Y axis	
	buttons.push_back(new Button("Line", L"DrawingTools - Icons\\Line.bmp", 0, 60, nullptr)); // change pointer function to correct derived class
	buttons.push_back(new Button("Triangle", L"DrawingTools - Icons\\Triangle.bmp", 0, 120, nullptr)); // &CallBackFunctions::onTriangleButton
	buttons.push_back(new Button("Square", L"DrawingTools - Icons\\Square.bmp", 0, 180, nullptr));
	buttons.push_back(new Button("Move", L"DrawingTools - Icons\\Move.bmp", 0, 240, nullptr));
	buttons.push_back(new Button("Delete", L"DrawingTools - Icons\\Delete.bmp", 0, 300, nullptr));
	buttons.push_back(new Button("Colour Change", L"DrawingTools - Icons\\Colour Change.bmp", 0, 360, nullptr));
	//buttons.push_back(new Button(L"DrawingTools - Icons\\Open.bmp", 0, 420, this));
	//buttons.push_back(new Button("save",L"DrawingTools - Icons\\Save.bmp", 0, 480, this));

	//To do: save - for loop the shapes vector and get all the position of the shapes and write to file
	//To do: open - read file and 

	//X axis
	buttons.push_back(new Button("Red Line", L"DrawingTools - Icons\\Red Line.bmp", 60, 0, nullptr));
	buttons.push_back(new Button("Green Line", L"DrawingTools - Icons\\Green Line.bmp", 120, 0, nullptr));
	buttons.push_back(new Button("Blue Line", L"DrawingTools - Icons\\Blue Line.bmp", 180, 0, nullptr));
	buttons.push_back(new Button("Red Fill", L"DrawingTools - Icons\\Red Fill.bmp", 300, 0, nullptr));
	buttons.push_back(new Button("Green Fill", L"DrawingTools - Icons\\Green Fill.bmp", 360, 0, nullptr));
	buttons.push_back(new Button("Blue Fill", L"DrawingTools - Icons\\Blue Fill.bmp", 420, 0, nullptr));
}


void DrawingTool::onCreate()
{
	initializeButtons();
	::SetWindowText(getHWND(), L"Drawing Tool GUI");
	clearScreen(WHITE);
	EasyGraphics::onCreate();

}



void DrawingTool::onDraw()
{
	clearScreen(WHITE);
	//auto functionPointerDraw = &drawShapes;
	drawShapes();

	drawMenu(); // Make sure this is invoked last. So Menu is not covered

	if (selectedAction == "Colour Change" && workingShape != nullptr)
	{
		workingShape->drawSelection(this);
	}
	EasyGraphics::onDraw();
}

void DrawingTool::onLButtonDown(UINT nFlags, int x, int y)
{

	bool buttonHit = false;
	std::string selectedID;

	for (Button* aButton : buttons) 
	{
		if (aButton->hitTest(x, y)) // ask object if its current x and y  matches with the passed in x and y. then return true
		{
			buttonHit = true;
			selectedID = aButton->getName();
			if (selectedID == "Red Line" || selectedID == "Blue Line" || selectedID == "Green Line")
			{
				selectedPen = selectedID;
				if (selectedAction == "Colour Change" && workingShape != nullptr)
				{
					workingShape->setPen(selectedID);
				}
				onDraw();
			}

			else if (selectedID == "Red Fill" || selectedID == "Blue Fill" || selectedID == "Green Fill")
			{
				selectedFill = selectedID;
				if (selectedAction == "Colour Change" && workingShape != nullptr)
				{
					workingShape->setFill(selectedID);
				}
				onDraw();
			}

			else
			{
				selectedAction = selectedID;
				onDraw();
			}
			break;
		}
	}

	if (!buttonHit) // if draw button tool is pressed, add/push a new object(shape) into a vector
	{
		if (selectedAction == "Line")
		{
			Shapes::getShapes()->addShape(new Line(x, y, selectedFill, selectedPen)); 
			onDraw();
			sizingInProgress = true;

		}

		else if (selectedAction == "Square")
		{
			Shapes::getShapes()->addShape(new Square(x, y, 30, 40, selectedFill, selectedPen)); 
			onDraw();
			sizingInProgress = true;

		}

		else if (selectedAction == "Triangle")
		{
			Shapes::getShapes()->addShape(new Triangle(x, y, selectedFill, selectedPen)); 
			onDraw();
			sizingInProgress = true;
		}


		// Iterate each shape created 
		else if (selectedAction == "Delete")
		{
			int i = 0;
			for (Shape* aShape : Shapes::getShapes()->getShapesVector())
			{
				if (aShape->hitTest(x, y))
				{
					Shapes::getShapes()->deleteShape(i);
					break;
				}
				i++;
			}
			onDraw();
		}

		else if (selectedAction == "Move")
		{
			int i = 0;
			for (Shape* aShape : Shapes::getShapes()->getShapesVector())
			{
				if (aShape->hitTest(x, y)) {
					workingShape = aShape;
					moveInProgress = true;
					break;
				}
				i++;
			}
			onDraw();
		}

		else if (selectedAction == "Colour Change")
		{
			for (Shape* aShape : Shapes::getShapes()->getShapesVector())
			{
				if (aShape->hitTest(x, y))
				{
					workingShape = aShape;
					break;
				}
			}
			onDraw();
		}

	}
}

void DrawingTool::drawMenu()
{

	for (std::vector<Button*>::iterator it = buttons.begin(); 
		it != buttons.end(); it++)
	{
		std::string id = (*it)->getName();
		(*it)->draw(this);
		if (id == selectedAction || id == selectedFill || id == selectedPen)
		{
			setPenColour(RED, 2);
		}

		else
		{
			setPenColour(BLACK, 2);
		}

		drawRectangle((*it)->getX(), (*it)->getY(), 50, 50, false); // draw rectangle border for each button and outline with red border if selected
	}
}

void DrawingTool::drawShapes()  
// create a function pointer to this class. pass in the get pen and get fill and use the drawback in the vector when  pushed
{
	for (Shape* aShape : Shapes::getShapes()->getShapesVector()) //iterate over each shape created inside vector (vector of objects)
	{
		std::string penColor = aShape->getPen();
		std::string fillColor = aShape->getFill();

		//set pen colour and back colour of shape before drawing
		if (penColor == "Red Line")
		{
			setPenColour(RED, 4);
		}

		else if (penColor == "Blue Line") {
			setPenColour(BLUE, 4);
		}

		else
		{
			setPenColour(GREEN, 4);
		}

		if (fillColor == "Red Fill")
		{
			setBackColour(RED);
		}

		else if (fillColor == "Blue Fill")
		{
			setBackColour(BLUE);
		}

		else
		{
			setBackColour(GREEN);
		}

		aShape->draw(this); // After object is created/updated. shape is drawn to canvas - draw()
	}

}

void DrawingTool::onMouseMove(UINT nFlags, int x, int y) // Get mouse co-ordinates and when draw button is pressed. set the current co-ordinates to the right draw tool
{
	if (sizingInProgress)
	{
		if (selectedAction == "Line") {

			Line* ptrToLine = dynamic_cast<Line*>(Shapes::getShapes()->getShapesVector().back());

			if (ptrToLine)
			{
				ptrToLine->setX2(ptrToLine->getX() + (x - ptrToLine->getX()));  //updates x, y co-ordinates
				ptrToLine->setY2(ptrToLine->getY() + (y - ptrToLine->getY()));
			}
			onDraw();

		}

		else if (selectedAction == "Triangle")
		{
			Triangle* ptrToLine = dynamic_cast<Triangle*>(Shapes::getShapes()->getShapesVector().back());
			if (ptrToLine)
			{
				ptrToLine->setX2(ptrToLine->getX() + (x - ptrToLine->getX()));
				ptrToLine->setY2(ptrToLine->getY() + (y - ptrToLine->getY()));
				ptrToLine->setX3(ptrToLine->getX() + (x - ptrToLine->getX()));
				ptrToLine->setY3(ptrToLine->getY() + (y - ptrToLine->getY()));
			}
			onDraw();
		}

		else if (selectedAction == "Square")
		{
			Square* ptrToLine = dynamic_cast<Square*>(Shapes::getShapes()->getShapesVector().back());

			if (ptrToLine)
			{
				ptrToLine->setWidth(x - ptrToLine->getX());
				ptrToLine->setHeight(y - ptrToLine->getY());
			}
			onDraw();

		}

		
	}

	else if (moveInProgress)
	{
		workingShape->move(x, y); 
		onDraw();
	}

}

void DrawingTool::onLButtonUp(UINT nFlags, int x, int y) // reset sizing and moving to false after each task is done
{
	if (sizingInProgress)
	{
		sizingInProgress = false;
	}

	else if (moveInProgress)
	{
		moveInProgress = false;
	}

}


