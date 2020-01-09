#pragma once

#include "Value.h"

class CCore
{
private:
	CCore();
	~CCore();

private:
	static CCore* m_pInst;

public:
	static CCore* GetInst() {
		if (!m_pInst)
			m_pInst = new CCore;

		return m_pInst;

	}

	static void DestroyInst() {
		SAFE_DELETE(m_pInst);
	}

private:
	HANDLE m_hConsole;
	bool m_bLoop;

public:
	bool Init();
	void Run();
	void SetConsolePos(int x, int y);	//콘솔창 커서이동
	void End()
	{
		m_bLoop = false;
	}
};

