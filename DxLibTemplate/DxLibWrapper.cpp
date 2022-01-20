#include "DxLibWrapper.h"

// DxLibWrapper
void DxLibWrapper::init(const DxLibWrapperHint& _hint)
{
	m_isInit = false;

	// AlwaysRun
	SetAlwaysRunFlag(_hint.alwaysRunFlag.a ? TRUE : FALSE);

	// WindowSizeChangeEnable
	SetWindowSizeChangeEnableFlag(_hint.windowSizeChangeEnableFlag.a ? TRUE : FALSE, _hint.windowSizeChangeEnableFlag.b ? TRUE : FALSE);

	// WindowSizeExtendRate
	SetWindowSizeExtendRate(_hint.windowSizeExtendRate.a, _hint.windowSizeExtendRate.b);

	// OutApplicationLogValid
	SetOutApplicationLogValidFlag(_hint.outApplicationLogValidFlag.a ? TRUE : FALSE);

	// WindowText
	SetWindowText(_hint.windowText.c_str());

	// WindowMode
	ChangeWindowMode(_hint.windowMode.a);

	// GraphMode
	SetGraphMode(_hint.graphMode.a, _hint.graphMode.b, _hint.graphMode.c, _hint.graphMode.d);

	if (DxLib_Init() != 0) return;

	SetDrawScreen(DX_SCREEN_BACK);

	m_isInit = true;
}
void DxLibWrapper::end()
{
	DxLib_End();
	m_isInit = false;
}
bool DxLibWrapper::main()
{
	return true;
}

DxLibWrapper::DxLibWrapper(const DxLibWrapperHint& _hint)
	:m_isInit(false)
{
	init(_hint);
}
DxLibWrapper::~DxLibWrapper()
{
	end();
}

void DxLibWrapper::run()
{
	while (ProcessMessage() == 0 && ScreenFlip() == 0 && ClearDrawScreen() == 0 && main());
}
