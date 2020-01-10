#include "Core.h"

void StartMenu()
{
	SetConsoleSize(40, 20);

	while (1) {
		Clear();
		GotoXY(2, 6);
		printf("#Tetris");
		GotoXY(2, 8);
		printf("#����:����� ȸ��:SPACEBAR");
		GotoXY(2, 10);
		printf("#����: ������ ������ ���̸� ���� ��");
		GotoXY(2, 12);
		printf("#Press any key");
		Sleep(50);
		if (_kbhit()) break;
	}
}

int main() {

	if (!CCore::GetInst()->Init()) {
		CCore::DestroyInst();
		return 0;
	}
	StartMenu();

	CCore::GetInst()->Run();

	CCore::DestroyInst();

	return 0;

}