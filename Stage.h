#pragma once

#include "Value.h"

class CStage
{
private:
	CStage();
	~CStage();

private:
	friend class CStageManager;

private:
	char m_Stage[STAGE_WIDTH][STAGE_HEIGHT];
	int m_iSpeed;

public:
	int GetSpeed() const {
		return m_iSpeed;
	}
	void SetSpeed(int iSpeed){
		m_iSpeed = iSpeed;
	}

public:
	bool Init();
	void Render();
};
