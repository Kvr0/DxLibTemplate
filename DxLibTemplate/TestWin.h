#pragma once

#include "DxLibWrapper.h"

class TestWin : public DxLibWrapper
{
public:
	TestWin(const DxLibWrapperHint& _hint)
		:DxLibWrapper(_hint)
	{
	}

	virtual bool main()
	{
		input::Mouse::update();

		DrawFormatString(0, 0, 0xffffff, "%d %d", input::Mouse::pos.a, input::Mouse::pos.b);

		return true;
	}
};
