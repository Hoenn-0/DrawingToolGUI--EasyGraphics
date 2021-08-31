#include <windows.h>

#include <crtdbg.h>
#include "DrawingTool.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdline, int show)
{
#ifdef _DEBUG
	_onexit(_CrtDumpMemoryLeaks);
#endif // DEBUG

	_CrtDumpMemoryLeaks();
	//PaintTool dt;
	//dt.create(hInstance, 800, 700, 100, false); // x =777 y =655
	//dt.waitForClose();
	//ButtonsUI* a = new ButtonsUI(100, 200);
	//DrawingTool* test = new DrawingTool(hInstance);
	//int* tesybug = malloc(sizeof(double))
	DrawingTool dt(hInstance);

	return 0;
}