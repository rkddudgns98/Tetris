#include "Shape.h"

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
		for (int j = 0; j < 4; j++) {
			if (m_cShape[i][j] == '0')
				cout << "■";
			else cout << "　";
		}
	}
}

void CShape::MoveDown()
{
	if (m_tPos.y == STAGE_HEIGHT - 1)
		return;

	m_tPos.y++;
}

void CShape::MoveLeft()
{
	if (m_tPos.x == 0)
		return;

	m_tPos.x--;
}

void CShape::MoveRight()	//기준점이 왼쪽아래이기 때문에 오른쪽으로 갈때 변수필요
{
	if (m_tPos.x + m_iWidthCount == STAGE_WIDTH)	//오른쪽으로 갈 때 예외사항
		return;

	m_tPos.x++;
}

