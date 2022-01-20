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
	ButtonState::operator bool() const
	{
		return isPressed();
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
		if (!left && (__input & MOUSE_INPUT_LEFT)) left.press();
		if (left && !(__input & MOUSE_INPUT_LEFT)) left.release();

		// Right
		if (!right && (__input & MOUSE_INPUT_RIGHT)) right.press();
		if (right && !(__input & MOUSE_INPUT_RIGHT)) right.release();

		// Middle
		if (!middle && (__input & MOUSE_INPUT_MIDDLE)) middle.press();
		if (middle && !(__input & MOUSE_INPUT_MIDDLE)) middle.release();

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
	void Mouse::resetWheel()
	{
		wheel = 0ull;
	}

	// Keyboard
	std::array<ButtonState, 256> Keyboard::keys = {};
	void Keyboard::update()
	{
		char __keys[256];
		GetHitKeyStateAll(__keys);
		for (int i = 0; i < 256; i++)
		{
			if (!keys[i] && __keys[i]) keys[i].press();
			if (keys[i] && !__keys[i]) keys[i].release();
		}
	}
}
