#pragma once
class CallBackFunctions
{
public:
	CallBackFunctions();
	~CallBackFunctions();

protected:
	virtual int onLineButton() = 0;
	virtual int onTriangleButton() = 0;
	virtual int onSquareButton() = 0;
};

