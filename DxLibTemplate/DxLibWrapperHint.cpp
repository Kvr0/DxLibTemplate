#include "DxLibWrapperHint.h"

DxLibWrapperHint::DxLibWrapperHint(
	valuew::value1<bool> _alwaysRunFlag,
	valuew::value2<bool> _windowSizeChangeEnableFlag,
	valuew::value2<double> _windowSizeExtendRate,
	valuew::value1<bool> _outApplicationLogValidFlag,
	valuew::string _windowText,
	valuew::value1<bool> _windowMode,
	valuew::value4<int> _graphMode
)
	:alwaysRunFlag(_alwaysRunFlag),
	windowSizeChangeEnableFlag(_windowSizeChangeEnableFlag),
	windowSizeExtendRate(_windowSizeExtendRate),
	outApplicationLogValidFlag(_outApplicationLogValidFlag),
	windowText(_windowText),
	windowMode(_windowMode),
	graphMode(_graphMode)
{
}
