#include "DxLibWrapper.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DxLibWrapperHint hint;

	DxLibWrapper wrapper(hint);

	wrapper.run();

	return 0;
}
