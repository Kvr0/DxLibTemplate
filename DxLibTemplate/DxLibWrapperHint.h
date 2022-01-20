#pragma once
#ifndef _DXLIBWRAPPERHINT_H_
#define _DXLIBWRAPPERHINT_H_

#include "ValueWrapper.h"

class DxLibWrapperHint
{
public:
	// AlwaysRun
	valuew::value1<bool> alwaysRunFlag;

	// WindowSizeChange
	valuew::value2<bool> windowSizeChangeEnableFlag;
	valuew::value2<double> windowSizeExtendRate;

	// OutApplicationLogValid
	valuew::value1<bool> outApplicationLogValidFlag;

	// WindowText
	valuew::string windowText;

	// WindowMode
	valuew::value1<bool> windowMode;

	// GraphMode
	valuew::value4<int> graphMode;

public:
	DxLibWrapperHint(
		valuew::value1<bool> _alwaysRunFlag = false,
		valuew::value2<bool> _windowSizeChangeEnableFlag = valuew::value2<bool>(false, true),
		valuew::value2<double> _windowSizeExtendRate = valuew::value2<double>(1.0, -1.0),
		valuew::value1<bool> _outApplicationLogValidFlag = false,
		valuew::string _windowText = valuew::string(),
		valuew::value1<bool> _windowMode = true,
		valuew::value4<int> _graphMode = valuew::value4<int>(640, 480, 32, 60)
	);
};

#endif