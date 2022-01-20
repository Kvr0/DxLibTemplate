#include "TestWin.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DxLibWrapperHint hint;

	TestWin test(hint);

	test.run();

	return 0;
}
