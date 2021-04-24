#include"DDR RPG.h"

int main()
{	
	system("title DDR 일주일 콘솔");
	GameManager game = GameManager();
	int select;	
	int a;
	while (true)
	{
		bool gameLoop = true;

		while (gameLoop)
		{
			PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			game.title();

			Util().setXY(67, 20);
			cout << "Deep Dark Rpg";

			select = game.drawMenu(70, 30, 5);			
			switch (select)
			{
			case 0://게임시작						
				game.gameStart(gameLoop);				
				break;
			case 1://게임방법
				system("cls");
				Util().setXY(67, 10);
				cout << "[ 게임 설명 ]" << endl;
				Util().setXY(50, 12);
				cout << "플레이어는 누군가의 함정에 빠져 몸이 개조된 상태다." << endl;
				Util().setXY(45, 13);
				cout << "행동할때 마다 줄어드는 체력을 관리하며 엔딩을 보면 게임 클리어" << endl;

				Util().setXY(55, 15);
				cout << "병원 : 3/1 소지금을 주고 전체 회복" << endl;
				Util().setXY(55, 16);
				cout << "옷장 : 아이템 장착및 아이템 세부 정보 확인" << endl;
				Util().setXY(55, 17);
				cout << "상점 : 아이템 구매 및 판매하기" << endl;
				system("pause");
				break;
			case 2://겜종료
				return 0;
			}
			system("cls");
		}
		return 0;
	}
}

