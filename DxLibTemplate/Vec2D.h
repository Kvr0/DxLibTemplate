#pragma once
#ifndef _VEC2D_H_

#include "ValueWrapper.h"
#include <cmath>

template<typename _T>
class Vec2D : public valuew::value2<_T>
{
public:

	_T length() const
	{
		return std::sqrt(a * a + b * b);
	}
	
	Vec2D& operator+=(const Vec2D& _rhs)
	{
		a += _rhs.a;
		b += _rhs.b;
		return *this;
	}
	Vec2D& operator-=(const Vec2D& _rhs)
	{
		a -= _rhs.a;
		b -= _rhs.b;
		return *this;
	}
	Vec2D& operator*=(_T _rhs)
	{
		a *= _rhs;
		b *= _rhs;
		return *this;
	}
	Vec2D& operator/=(_T _rhs)
	{
		a /= _rhs;
		b /= _rhs;
		return *this;
	}

};

template<typename _T>
Vec2D<_T> operator+(const Vec2D<_T>& _lhs, const Vec2D<_T>& _rhs)
{
	Vec2D<_T> __tmp = _lhs;
	__tmp += _rhs;
	return __tmp;
}
template<typename _T>
Vec2D<_T> operator-(const Vec2D<_T>& _lhs, const Vec2D<_T>& _rhs)
{
	Vec2D<_T> __tmp = _lhs;
	__tmp -= _rhs;
	return __tmp;
}
template<typename _T>
Vec2D<_T> operator*(const Vec2D<_T>& _lhs, _T _rhs)
{
	Vec2D<_T> __tmp = _lhs;
	__tmp *= _rhs;
	return __tmp;
}
template<typename _T>
Vec2D<_T> operator*(_T _lhs, const Vec2D<_T>& _rhs)
{
	return _rhs * _lhs;
}
template<typename _T>
Vec2D<_T> operator/(const Vec2D<_T>& _lhs, _T _rhs)
{
	Vec2D<_T> __tmp = _lhs;
	__tmp /= _rhs;
	return __tmp;
}
template<typename _T>
Vec2D<_T> operator/(_T _lhs, const Vec2D<_T>& _rhs)
{
	return _rhs / _lhs;
}

#endif