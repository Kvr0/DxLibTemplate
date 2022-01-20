#pragma once
#ifndef _INPUT_H_
#define _INPUT_H_

#include <DxLib.h>
#include "ValueWrapper.h"

namespace input
{
	class ButtonState
	{
	public:
		static ULONGLONG getNow();
	private:
		bool m_pressed;
		ULONGLONG m_pressedTime;
		ULONGLONG m_lastPressedTime;
	public:
		ButtonState();

		bool isPressed() const;
		ULONGLONG pressedTime() const;
		ULONGLONG lastPressedTime() const;

		void press();
		void release();
	};

	class Mouse
	{
	public:
		static valuew::value2<int> pos;
		static ButtonState left;
		static ButtonState right;
		static ButtonState middle;
		static valuew::value1<ULONGLONG> wheel;

		static void update();

		static void setDisplayFlag(bool _display);
		static void setPos(const valuew::value2<int>& _pos);
	};
}

#endif