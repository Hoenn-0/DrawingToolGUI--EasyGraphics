#pragma once
#include "EasyGraphics.h"
#include "Button.h"
#include "Shape.h"
#include "CallBackFunctions.h"


class DrawingTool : public EasyGraphics // ,public CallBackFunctions
{
public:

	int onLineButton();
	int onTriangleButton();
	int onSquareButton();

	void test();

	DrawingTool(HINSTANCE hInstance);
	~DrawingTool();
	void onDraw();
	void onLButtonDown(UINT nFlags, int x, int y);
	void onLButtonUp(UINT nFlags, int x, int y);
	void onMouseMove(UINT nFlags, int x, int y);
	void onCreate();
	



private:
	void initializeButtons();
	void drawMenu();
	void drawShapes();

	//set to true when left click is pressed
	bool sizingInProgress = false;
	// set to true when left click is pressed during move 
	bool moveInProgress = false;
	// points to shape that is currently selected
	Shape* workingShape = nullptr;

	std::vector<Button*> buttons;
	std::string selectedPen = "Red Line";
	std::string selectedFill = "Red Fill";
	std::string selectedAction = "Line";
	

};
