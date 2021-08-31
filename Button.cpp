#include "Button.h"


Button::Button(std::string name, std::wstring imagePath, int x, int y, int (*funcPDraw)() ) : name(name), imagePath(imagePath), x(x), y(y)
{ 
// call back function here
}

Button::~Button()
{ }

void Button::draw(EasyGraphics* window)
{
	window->drawBitmap(imagePath.c_str(), x, y, 50, 50, EasyGraphics::WHITE);
}

bool Button::hitTest(int testX, int testY)
{

	return (testX >= x && testX < (x + 50) && testY > y && testY < (y + 50));

}

