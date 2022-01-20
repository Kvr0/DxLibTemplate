#pragma once
#ifndef _DXLIBWRAPPER_H_
#define _DXLIBWRAPPER_H_

#include <DxLib.h>
#include "DxLibWrapperHint.h"
#include "Input.h"

class DxLibWrapper
{
private:
	// Initialize Flag
	valuew::value1<bool> m_isInit;
private:
	virtual void init(const DxLibWrapperHint& _hint);
	virtual void end();

public:
	DxLibWrapper(const DxLibWrapperHint& _hint);
	virtual ~DxLibWrapper();

	virtual bool main();
	void run();
};

#endif // !_DXLIBWRAPPER_H_
