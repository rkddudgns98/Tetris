#include "Stage.h"

CStage::CStage() {

}

CStage::~CStage() {

}

bool CStage::Init() {
	memset(m_Stage, 0, STAGE_WIDTH * STAGE_HEIGHT);

	return true;
}

void CStage::Render() {
	for (int i = 0; i < STAGE_HEIGHT + 1; i++) {	//���� �������ؼ� +2 but �������� +1
		for (int j = 0; j < STAGE_WIDTH + 2; j++) {
			if (i == 0 && (j == 0 || j == STAGE_WIDTH + 1))
				cout << "��";
			else if (j == 0)
				cout << "��";
			else if (i == STAGE_HEIGHT)
				cout << "��";
			else if (j == STAGE_WIDTH + 1)
				cout << "��";
			else
				cout << "��";
		}
		cout << endl;
	}
}