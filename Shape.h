#pragma once

#include "Value.h"

class CShape
{
public:
	CShape();
	virtual ~CShape();

protected:
	char m_cShape[4][4];
	POSITION m_tPos;
	POSITION m_tPivot;
	int m_iWidthCount;	//기준점이 왼쪽아래이기때문에 오른쪽으로 갈 때 변수가 필요

public:
	//이동시 필요한 기준점 세우기
	void SetPosition(int x, int y) {	
		m_tPos.x = x;
		m_tPos.y = y;
	}

	void SetPosition(const POSITION& tPos) {
		m_tPos = tPos;
	}

	POSITION GetPosition() const {
		return m_tPos;
	}

	POSITION GetPivot() const {
		return m_tPivot;
	}

public:
	virtual bool Init();

public:
	void Render();
	void MoveDown();
	void MoveLeft();
	void MoveRight();	//기준점이 왼쪽아래이기 때문에 오른쪽으로 갈때 변수필요
	
};

