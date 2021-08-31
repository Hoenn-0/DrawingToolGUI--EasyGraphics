#pragma once
#include <string>
#include "EasyGraphics.h"


class Button 
{
private:
	std::wstring imagePath;
	int x;
	int y;
	std::string name;

public:

	Button(std::string name, std::wstring imagePath, int x, int y, int (*funcPDraw)() ); // std::string (*funcPDraw)(std::string)
	~Button();
	
	void draw(EasyGraphics* window);
	bool hitTest(int testX, int testY);

	std::wstring getPath();
	std::string getName();
	int getX();
	int getY();

};

inline std::wstring Button::getPath()
{ 
	return imagePath; 
}

inline std::string Button::getName()
{
	return name;
}
inline int Button::getX()
{
	return x; 
}
inline int Button::getY() 
{ 
	return y; 
}