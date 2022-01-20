#include "Input.h"

namespace input
{
	ULONGLONG ButtonState::getNow()
	{
		return ConvSysPerformanceCountToMilliSeconds(GetNowSysPerformanceCount());
	}
	// ButtonState
	ButtonState::ButtonState()
		:m_pressed(false), m_pressedTime(0ull), m_lastPressedTime(0ull)
	{
	}
	bool ButtonState::isPressed() const
	{
		return m_pressed;
	}
	ULONGLONG ButtonState::pressedTime() const
	{
		if (!m_pressed) return 0ull;
		return getNow() - m_pressedTime;
	}
	ULONGLONG ButtonState::lastPressedTime() const
	{
		return m_lastPressedTime;
	}
	void ButtonState::press()
	{
		m_pressedTime = getNow();
		m_pressed = true;
	}
	void ButtonState::release()
	{
		m_lastPressedTime = getNow() - m_pressedTime;
		m_pressed = false;
	}

	// Mouse
	valuew::value2<int> Mouse::pos = valuew::value2<int>(0,0);
	ButtonState Mouse::left;
	ButtonState Mouse::right;
	ButtonState Mouse::middle;
	valuew::value1<ULONGLONG> Mouse::wheel = 0ull;
	void Mouse::update()
	{
		// Pos
		GetMousePoint(&pos.a, &pos.b);

		// Input
		auto __input = GetMouseInput();

		// Left
		if (!left.isPressed() && (__input & MOUSE_INPUT_LEFT)) left.press();
		if (left.isPressed() && !(__input & MOUSE_INPUT_LEFT)) left.release();

		// Right
		if (!right.isPressed() && (__input & MOUSE_INPUT_RIGHT)) right.press();
		if (right.isPressed() && !(__input & MOUSE_INPUT_RIGHT)) right.release();

		// Middle
		if (!middle.isPressed() && (__input & MOUSE_INPUT_MIDDLE)) middle.press();
		if (middle.isPressed() && !(__input & MOUSE_INPUT_MIDDLE)) middle.release();

		// Wheel
		wheel.a += GetMouseWheelRotVol();
	}
	void Mouse::setDisplayFlag(bool _display)
	{
		SetMouseDispFlag(_display ? TRUE : FALSE);
	}
	void Mouse::setPos(const valuew::value2<int>& _pos)
	{
		SetMousePoint(_pos.a, _pos.b);
	}
}
