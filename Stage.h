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

public:
	bool Init();
	void Render();
};
