#pragma once
#ifndef _VALUEWRAPPER_H_
#define _VALUEWRAPPER_H_

#include <string>
#include <array>

namespace valuew
{
	template<typename _T>
	class value1
	{
	public:
		using type = _T;
		type a;

		value1(type _a)
			:a(_a)
		{
		}
	};

	template<typename _T>
	class value2
	{
	public:
		using type = _T;
		type a;
		type b;

		value2(type _a, type _b)
			:a(_a), b(_b)
		{
		}
	};

	template<typename _T>
	class value3
	{
	public:
		using type = _T;
		type a;
		type b;
		type c;

		value3(type _a, type _b, type _c)
			:a(_a), b(_b)
		{
		}
	};

	template<typename _T>
	class value4
	{
	public:
		using type = _T;
		type a;
		type b;
		type c;
		type d;

		value4(type _a, type _b, type _c, type _d)
			:a(_a), b(_b), c(_c), d(_d)
		{
		}
	};

#ifdef UNICODE
	using string = std::wstring;
#else
	using string = std::string;
#endif

	template <class _Ty, size_t _Size>
	using array = std::array<_Ty, _Size>;
}

#endif // !_VALUEWRAPPER_H_
