#include "Shape.h"
#include "Core.h"
#include "Stage.h"
#include "StageManager.h"

CShape::CShape() {
	m_iWidthCount = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m_cShape[i][j] = '1';
		}
	}
}

CShape::~CShape() {

}

bool CShape::Init()
{
	m_tPivot.x = 0;
	m_tPivot.y = 3;

	return true;
}

void CShape::Render()	//도형출력
{
	for (int i = 0; i < 4; i++) {
		int iYIndex = m_tPos.y - (3 - i);
		if (iYIndex < 0)
			continue;

		//콘솔창에 출력할 좌표를 설정한 후에 출력한다
		CCore::GetInst()->SetConsolePos(m_tPos.x, iYIndex);
		for (int j = 0; j < 4; j++) {
			if (m_tPos.x + j >= STAGE_WIDTH)	//오른쪽으로갈때 벽이 안뚫리게 예외처리
				continue;

			if (m_cShape[i][j] == '0')
				cout << "■";
		}
		cout << endl;
	}
}

void CShape::RenderNext()
{
	for (int i = 0; i < 4; i++) {
		int iYIndex = m_tPos.y - (3 - i);
		if (iYIndex < 0)
			continue;

		//콘솔창에 출력할 좌표를 설정한 후에 출력한다
		CCore::GetInst()->SetConsolePos(m_tPos.x, iYIndex);
		for (int j = 0; j < 4; j++) {
			if (m_cShape[i][j] == '0')
				cout << "■";

			else
				cout << "　";
		}
		cout << endl;
	}
}

//true = 바닥에 닿았다,  false = 바닥에 닿지 않았다
bool CShape::MoveDown()
{
	CStage* pStage = CStageManager::GetInst()->GetCurrentStage();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (m_cShape[i][j] == '0') {
				if (pStage->CheckBlock(m_tPos.x + j, m_tPos.y - (2 - i))) {
					return true;
				}
			}
		}
	}
	m_tPos.y++;

	return false;	//바닥에 닿지 않았다
}

void CShape::MoveLeft()
{
	if (m_tPos.x == 0)
		return;

	CStage* pStage = CStageManager::GetInst()->GetCurrentStage();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (m_cShape[i][j] == '0') {
				if (pStage->CheckBlock(m_tPos.x + j - 1, m_tPos.y - (3 - i))) {
					return;
				}
			}
		}
	}

	m_tPos.x--;
}

void CShape::MoveRight()
{
	if (m_tPos.x + m_iWidthCount == STAGE_WIDTH)	//오른쪽으로 갈 때 예외사항
		return;

	CStage* pStage = CStageManager::GetInst()->GetCurrentStage();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (m_cShape[i][j] == '0') {
				if (pStage->CheckBlock(m_tPos.x + j + 1, m_tPos.y - (3 - i))) {
					return;
				}
			}
		}
	}

	m_tPos.x++;
}

