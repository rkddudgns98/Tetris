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
	int m_iWidthCount;	//�������� ���ʾƷ��̱⶧���� ���������� �� �� ������ �ʿ�

public:
	//�̵��� �ʿ��� ������ �����
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
	void MoveRight();	//�������� ���ʾƷ��̱� ������ ���������� ���� �����ʿ�
	
};

