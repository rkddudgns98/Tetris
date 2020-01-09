#include "Stage.h"
#include "ShapeManager.h"
#include "StageManager.h"

#include "Rectangle.h"
#include "ShapeLine.h"
#include "ShapeGun.h"
#include "ShapeRGun.h"
#include "ShapeS.h"
#include "ShapeZ.h"
#include "ShapeT.h"

CShapeManager* CShapeManager::m_pInst = NULL;

CShapeManager::CShapeManager() :
	m_pCurShape(NULL),
	m_pNextShape(NULL)
{
	m_pCurShape = CreateRandomShape();
	m_pNextShape = CreateRandomShape();
	m_iSpeed = 0;
}

CShapeManager::~CShapeManager()
{
	SAFE_DELETE(m_pCurShape);
	SAFE_DELETE(m_pNextShape);
}

void CShapeManager::Update()
{
	CStage* pStage = CStageManager::GetInst()->GetCurrentStage();
	++m_iSpeed;
	if (pStage->GetSpeed() == m_iSpeed) {
		/*true일 경우 바닥에 닿았으므로 리스트에 추가하고 다음 도형을 현재 도형으로
		만들고 그후 다음 도형을 생성한다.*/
		if (m_pCurShape->MoveDown()) {

			//지워주기 전에 블럭을 추가해준다
			pStage->AddBlock(m_pCurShape, m_pCurShape->GetPosition());

			SAFE_DELETE(m_pCurShape);

			m_pCurShape = m_pNextShape;
			m_pCurShape->SetPosition(4, 0);


			m_pNextShape = CreateRandomShape();
		} 
		m_iSpeed = 0;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		m_pCurShape->MoveLeft();
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		m_pCurShape->MoveRight();
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		m_pCurShape->Rotation();
	}
}

void CShapeManager::Render()
{	//현재 도형의 렌더링
	m_pCurShape->Render();

	//다음 도형의 렌더링
	m_pNextShape->SetPosition(12, 4);
	m_pNextShape->RenderNext();
}

CShape* CShapeManager::CreateRandomShape()
{
	int iType = rand() % ST_END;

	return CreateShape((SHAPE_TYPE)iType);
}

CShape* CShapeManager::CreateShape(SHAPE_TYPE eType)
{
	CShape* pShape = NULL;

	switch (eType) 
	{
	case ST_RECT:
		pShape = new CRectangle;
		break;
	case ST_LINE:
		pShape = new CShapeLine;
		break;
	case ST_GUN:
		pShape = new CShapeGun;
		break;
	case ST_RGUN:
		pShape = new CShapeRGun;
		break;
	case ST_S:
		pShape = new CShapeS;
		break;
	case ST_Z:
		pShape = new CShapeZ;
		break;
	case ST_T:
		pShape = new CShapeT;
		break;
	}
	if (!pShape->Init()) {
		SAFE_DELETE(pShape);
		return NULL;
	}

	return pShape;
}
