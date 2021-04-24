#include "GameManager.h"
#include "Map.h"
#include "Monster.h"

Util util;
Player player;
Shop _shop;

void GameManager::helpShow()
{
}

GameManager::GameManager()
{		
	util.setHide();
	system("mode con:cols=151 lines=44");//맵크기 101*30	
}

GameManager::~GameManager()
{
}

void GameManager::title()
{	
	util.setColor(util.white, util.black);
	GameManager().settingMap(8);
	GameManager().drawMap(15);		

}

void GameManager::ending()
{
	if (dCount < 3)return;

	system("cls");
	Util().setXY(65, 30);
	cout << "준비한 포폴은 여기까지입니다!" << endl;	
	Util().setXY(65, 31);
	cout << "감사합니다!" << endl;
	Sleep(5000);
	exit(0);
}

//밤새니까 코드 정리가 안된다 그냥 짜자..

//draw뜯어고쳐야함 - 각 맵의 ui만들거나 클래스를 만들자
void GameManager::drawUI()
{
	util.setColor(util.white, util.black);

	util.setXY(5, 31);
	cout << "[플레이어 이름 : "<<player.getPlayer().name<<"]";

	util.setXY(30, 31);
	cout << "[레벨 " << player.getPlayer().level << "]";

	util.setXY(50, 31);
	cout << "가진 돈 : "<<player.getPlayer().gold <<"원";

	util.setXY(5, 33);
	cout << "[ 체력 ]";
	player.progressbar(player.getPlayer().hpMax, player.getPlayer().hpCur, 5, 34);

	util.setXY(5, 36);
	cout << "[ 경험치 ]";
	player.expbar(player.getPlayer().expMax, player.getPlayer().expCur,5, 37);


	Util().setXY(50, 33);
	cout << "[ 최소 ~ 최대 공격력 ]";

	Util().setXY(75, 33);
	cout << "[ 장착한 무기 ]";

	if (!player.getPlayer().equipB[0])
	{
		Util().setXY(75, 34);
		cout << "[없음]" << endl;
		Util().setXY(50, 34);
		cout << "[" << player.getPlayer().attackMin << " ~ " << player.getPlayer().attackMax << "]";
	}
	else
	{
		Util().setXY(75, 34);
		cout << "[" << player.getPlayer().equipT[0].getName() << "]" << endl;
		Util().setXY(50, 34);
		cout << "[" << player.getPlayer().attackMin << "+" << player.getPlayer().equipT[0].getMin() << " ~ " << player.getPlayer().attackMax << "+" << player.getPlayer().equipT[0].getMax() << "]";
	}


	Util().setXY(75, 36);
	cout << "[ 장창한 방어구 ]";
	Util().setXY(50, 36);
	cout << "[ 최소 ~ 최대 방어력 ]";
	if (!player.getPlayer().equipB[1])
	{
		Util().setXY(75, 37);
		cout << "[없음]" << endl;
		Util().setXY(50, 37);
		cout << "[" << player.getPlayer().defMin << " ~ " << player.getPlayer().defMax << "]";
	}
	else
	{
		Util().setXY(75, 37);
		cout << "[" << player.getPlayer().equipT[1].getName() << "]" << endl;
		Util().setXY(50, 37);
		cout << "[" << player.getPlayer().defMin << "+" << player.getPlayer().equipT[1].getMin() << " ~ " << player.getPlayer().defMax << "+" << player.getPlayer().equipT[1].getMin() << "]";
	}

	Util().setXY(120, 36);
	cout << "엔딩까지 남은 드래곤 "<<dCount<<"/3"<< endl;

	util.setXY(125, 2);
	cout << "[ 인벤토리 ]";
	player.pShowItem2(118, 3);



	util.setColor(util.black, util.white);
	util.setXY(10, 2);
	cout << "병원";

	util.setColor(util.black, util.white);
	util.setXY(80, 4);
	cout << "하던전";

	util.setColor(util.black, util.white);
	util.setXY(58, 13);
	cout << "중던전";

	util.setColor(util.black, util.white);
	util.setXY(90, 20);
	cout << "상던전";

	util.setColor(util.black, util.white);
	util.setXY(10, 9);
	cout << "상점";

	util.setColor(util.black, util.white);
	util.setXY(10, 16);
	cout << "옷장";

	util.setColor(util.white, util.black);
}

void GameManager::fildUI()
{
	util.setColor(util.white, util.black);

	util.setXY(5, 31);
	cout << "[플레이어 이름 : " << player.getPlayer().name << "]";

	util.setXY(30, 31);
	cout << "[레벨 " << player.getPlayer().level << "]";

	util.setXY(50, 31);
	cout << "가진 돈 : " << player.getPlayer().gold << "원";

	util.setXY(100, 31);
	cout << "마을로가기 : ESC";


	util.setXY(5, 33);
	cout << "[ 체력 ]";
	player.progressbar(player.getPlayer().hpMax, player.getPlayer().hpCur, 5, 34);

	util.setXY(5, 36);
	cout << "[ 경험치 ]";
	player.expbar(player.getPlayer().expMax, player.getPlayer().expCur, 5, 37);


	Util().setXY(50, 33);
	cout << "[ 최소 ~ 최대 공격력 ]";

	Util().setXY(75, 33);
	cout << "[ 장착한 무기 ]";

	if (!player.getPlayer().equipB[0])
	{
		Util().setXY(75, 34);
		cout << "[없음]" << endl;
		Util().setXY(50, 34);
		cout << "[" << player.getPlayer().attackMin << " ~ " << player.getPlayer().attackMax << "]";
	}
	else
	{
		Util().setXY(75, 34);
		cout << "[" << player.getPlayer().equipT[0].getName() << "]" << endl;
		Util().setXY(50, 34);
		cout << "[" << player.getPlayer().attackMin << "+" << player.getPlayer().equipT[0].getMin() << " ~ " << player.getPlayer().attackMax << "+" << player.getPlayer().equipT[0].getMax() << "]";
	}


	Util().setXY(75, 36);
	cout << "[ 장창한 방어구 ]";
	Util().setXY(50, 36);
	cout << "[ 최소 ~ 최대 방어력 ]";
	if (!player.getPlayer().equipB[1])
	{
		Util().setXY(75, 37);
		cout << "[없음]" << endl;
		Util().setXY(50, 37);
		cout << "[" << player.getPlayer().defMin << " ~ " << player.getPlayer().defMax << "]";
	}
	else
	{
		Util().setXY(75, 37);
		cout << "[" << player.getPlayer().equipT[1].getName() << "]" << endl;
		Util().setXY(50, 37);
		cout << "[" << player.getPlayer().defMin << "+" << player.getPlayer().equipT[1].getMin() << " ~ " << player.getPlayer().defMax << "+" << player.getPlayer().equipT[1].getMin() << "]";
	}

	util.setXY(125, 2);
	cout << "[ 인벤토리 ]";
	player.pShowItem2(118, 3);
}

void GameManager::drawMap(const int wallColor)
{
	shootCount = 0;
	system("cls");
	for (int i = 0; i < mapX; i++)
	{
		for (int j = 0; j < mapY; j++)
		{
			unsigned char temp = tMap[i][j];
			if (temp == BLOCK_null)
			{				
				util.setColor(util.black, util.black);
				cout << "□";//빈공간
			}
			else if (temp == BLOCK_wall)
			{
				util.setColor(util.white, util.black);
				cout << "■"; //벽
			}
			else if (temp == BLOCK_wall01)
			{
				Util().setColor(Util().lightcyan, Util().darkgray);
				cout << "  ";
			}
			else if (temp == BLOCK_player)
			{
				Util().setColor(Util().lightblue, Util().black);
				cout << "  ";
				//플레이어 위치 확인하면 위치값 초기화
				player.p_Pos_X = j;
				player.p_Pos_Y = i;
				
				tMap[i][j] = BLOCK_null;				
			}
			else if (temp == BLCOK_battlePotal01)
			{
				Util().setColor(Util().yellow, Util().yellow);
				cout << "  ";
			}
			else if (temp == BLCOK_battlePotal02)
			{
				Util().setColor(Util().yellow, Util().yellow);
				cout << "  ";
			}
			else if (temp == BLCOK_battlePotal03)
			{
				Util().setColor(Util().yellow, Util().yellow);
				cout << "  ";
			}
			else if (temp == BLCOK_healing)
			{
				Util().setColor(Util().yellow, Util().yellow);
				cout << "  ";
			}
			else if (temp == BLCOK_shopPotal)
			{
				Util().setColor(Util().yellow, Util().yellow);
				cout << "  ";
			}
			else if (temp == BLCOK_miniPotal)
			{
				Util().setColor(Util().yellow, Util().yellow);
				cout << "  ";
			}
			else if (temp == BLOCK_monsterH || temp == BLOCK_monsterV)
			{
				Util().setColor(Util().black, Util().black);

				cout << "○";

				struct pos tempPos;
				if (temp == BLOCK_monsterV)
				{
					if (tMap[i][j - 2] == BLOCK_wall)
					{
						tempPos.dir = true;
					}
					else
					{
						tempPos.dir = false;
					}
				}
				else if (temp == BLOCK_monsterH)
				{
					if (tMap[i - 2][j] == BLOCK_wall)
					{
						tempPos.dir = true;
					}
					else
					{
						tempPos.dir = false;
					}
				}

				tempPos.x = j;
				tempPos.y = i;

				shoot[shootCount++] = tempPos;
			}	
		}
		util.setColor(util.white, util.black);
		cout << "\n";		
	}
}

int GameManager::drawMenu(const int x, const int y, const int max)
{
	bool loop = true; // 반복 불리언
	int selectNum = 0;//리턴값

	util.setXY(x, y);
	cout << "일어난다" << endl;

	util.setXY(x, y+2);
	cout << "하는방법" << endl;

	util.setXY(x, y+4);
	cout << "게임종료" << endl;

	//현재 선택 위치
	util.setXY(x - 3, y + selectNum);
	cout << "▷";
	util.setXY(x + 9, y + selectNum);
	cout << "◁";	

	while (loop)
	{		
		Sleep(50);//딜레이 일부러줘 다중입력방지
		int s = keyInput();

		switch (s)
		{
		case 2://up
			if (selectNum > 0)
			{
				util.setXY(x - 3, y + selectNum);
				cout << " ";
				util.setXY(x + 9, y + selectNum);
				cout << " ";
				selectNum-=2;
				util.setXY(x - 3, y + selectNum);
				cout << "▷";
				util.setXY(x + 9, y + selectNum);
				cout << "◁";
			}
			break;
		case 3://down
			if (selectNum < 4)
			{
				util.setXY(x - 3, y + selectNum);
				cout << " ";
				util.setXY(x + 9, y + selectNum);
				cout << " ";
				selectNum+=2;
				util.setXY(x - 3, y + selectNum);
				cout << "▷";
				util.setXY(x + 9, y + selectNum);
				cout << "◁";
			}
			break;
		case 4://enter 결정하면

			util.setXY(x - 3, y + selectNum);
			cout << " ";
			util.setXY(x + 9, y + selectNum);
			cout << " ";			
			util.setXY(x - 2, y + selectNum);
			cout << "▷";
			util.setXY(x + 8, y + selectNum);
			cout << "◁";
			Sleep(100);

			util.setXY(x - 2, y + selectNum);
			cout << " ";
			util.setXY(x + 8, y + selectNum);
			cout << " ";
			util.setXY(x - 2, y + selectNum);
			cout << "▶";
			util.setXY(x + 8, y + selectNum);
			cout << "◀";
			Sleep(100);

			util.setXY(x - 2, y + selectNum);
			cout << " ";
			util.setXY(x + 8, y + selectNum);
			cout << " ";
			cout << "▷";
			util.setXY(x + 8, y + selectNum);
			cout << "◁";
			Sleep(100);
			util.setXY(x - 2, y + selectNum);
			cout << " ";
			util.setXY(x + 8, y + selectNum);
			cout << " ";
			util.setXY(x - 2, y + selectNum);
			cout << "▶";
			util.setXY(x + 8, y + selectNum);
			cout << "◀";			
			loop = false;// 반복종료
			break;
		}
	}
	return selectNum/2;//몇번 메뉴 골랐는지 리턴
}

void GameManager::monsterMgr()
{
	for (int i = 0; i < shootCount; i++)
	{
		struct pos* target = &shoot[i];
		int x = target->x;
		int y = target->y;
		Util().setXY(x, y);
		cout << " ";

		unsigned char temp = tMap[y][x];
				/*[174]‘//가로 몹
			[175]’*///세로 몹
		if (temp == 174)
		{
			if (target->dir)
			{
				if (tMap[y][x + 2] == 224)
				{
					tMap[y][x] = 224;
					tMap[y][x + 2] = 174;

					target->x++;
					target->x++;

					Util().setXY(x + 2, y);
					Util().setColor(Util().lightpurple, Util().black);
					cout << "M";
				}
				else
				{
					shoot[i].dir = false;
				}
			}
			else
			{
				if (tMap[y][x - 2] == 224)
				{
					tMap[y][x] = 224;
					tMap[y][x - 2] = 174;
					
					target->x--;
					target->x--;

					Util().setXY(x-2, y);
					Util().setColor(Util().lightpurple, Util().black);
					cout << "M";
				}
				else
				{
					shoot[i].dir = true;
				}
			}
		}
		else if (temp == 175)
		{
			if (target->dir)
			{
				if (tMap[y + 1][x] == 224)
				{
					tMap[y][x] = 224;
					tMap[y + 1][x] = 175;

					target->y++;					

					Util().setXY(x, y + 1);
					Util().setColor(Util().lightpurple, Util().black);
					cout << "M";
				}
				else
				{
					shoot[i].dir = false;
				}
			}
			else
			{
				if (tMap[y - 1][x] == 224)
				{
					tMap[y][x] = 224;
					tMap[y - 1][x] = 175;
					
					target->y--;

					Util().setXY(x, y - 1);
					Util().setColor(Util().lightpurple, Util().black);
					cout << "M";
				}
				else
				{
					shoot[i].dir = true;
				}
			}
		}

		if (target->x == player.p_Pos_X && target->y == player.p_Pos_Y)
		{
			//몬스터 만나는 소리
			//충돌
		}
	}
}


void GameManager::battleUI()
{
}

void GameManager::levelCheck(int curExp, int maxExp)
{
	if (curExp < maxExp) return;
	util.setXY(40, 31);
	util.setColor(util.black, util.white);
	cout << "[Level Up!]";
	Sleep(1000);
	util.setXY(40, 31);
	util.setColor(util.black, util.black);
	cout << "[Level Up!]";
	util.setColor(util.white, util.black);



	player.setPlayer().level += player.getLevelTable().level;
	player.setPlayer().hpMax += player.getLevelTable().hpMax;
	player.setPlayer().hpCur = player.getPlayer().hpMax;
	player.setPlayer().attackMin += player.getLevelTable().attackMin;
	player.setPlayer().attackMax += player.getLevelTable().attackMax;
	player.setPlayer().defMin += player.getLevelTable().defMin;
	player.setPlayer().defMax += player.getLevelTable().defMax;
	player.setPlayer().expMax += player.getLevelTable().expMax;
	player.setPlayer().expCur = 0;	
}

int GameManager::keyInput()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		return KEY_LEFT;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		return KEY_RIGHT;
	}
	else if (GetAsyncKeyState(VK_UP) & 0x8000) {
		return KEY_UP;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		return KEY_DOWN;
	}
	else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
		return KEY_ENTER;
	}
	else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
		return KEY_ESC;
	}
	else {
		return -1;
	}
}

int GameManager::nowLodingMap()
{
	int cur = player.getPlayerMap();	

	return cur;
}

void GameManager::settingMap(const int map)
{
	//맵 설정
	switch (map)
	{
	default:
	case 0:
		memcpy(tMap, loby, sizeof(tMap));
		break;
	case 1:
		memcpy(tMap, shop, sizeof(tMap));
		break;
	case 2:
		memcpy(tMap, bag, sizeof(tMap));
		break;
	case 3:
		memcpy(tMap, hospital, sizeof(tMap));
		break;
	case 4:
		memcpy(tMap, fild01, sizeof(tMap));
		break;
	case 5:
		memcpy(tMap, fild02, sizeof(tMap));
		break;
	case 6:
		memcpy(tMap, fild03, sizeof(tMap));
		break;
	case 7:
		memcpy(tMap, battle, sizeof(tMap));
		break;
	case 8:
		memcpy(tMap, mTitle, sizeof(tMap));
		break;
	case 9:
		memcpy(tMap, battle, sizeof(tMap));
		break;
	}
}

void GameManager::gameStart(bool& gameMain)
{	
	bool nameCheck = true;
	bool nameLoop = true;
	int s = 0;
	int select = 0;
	int a = 0;

	InitShop(_shop);
	InitMonster();

	while (nameCheck)
	{
		nameLoop = true;

		system("cls");
		util.setXY(65, 20);
		cout << "너의 이름은 무엇인가?" << endl;
		cin >> player.setPlayer().name;			
		while (nameLoop)
		{
			system("cls");
			util.setXY(65, 20);
			cout << "'" << player.getPlayer().name << "' 이 너의 이름이 맞나?" << endl;
			util.setXY(65, 22);
			cout << "(1) 네  (2) 아니오" << endl;
			cin >> s;

			if (s == 2)
			{
				nameLoop = false;
			}
			else if (s == 1)
			{
				nameCheck = false;
				nameLoop = false;				
			}
			else
			{
				system("cls");
				util.setXY(65, 20);
				cout << "네 / 아니오 중 하나만 선택해야한다." << endl;
				Sleep(1000);
				continue;
			}
		}
	}

	gamePlay = false;

	while (true)
	{		
		int map = nowLodingMap();//플레이어 맵 어딘지 받아와야함

		system("cls");

		switch (map)
		{
		case 0:
			settingMap(LOBY);
			gamePlay = true;
			break;
		case 1:
			settingMap(SHOP);
			gamePlay = true;
			break;
		case 2:
			settingMap(INVEN);
			gamePlay = true;
			break;
		case 3:
			settingMap(HOSPITAL);
			gamePlay = true;
			break;
		case 4:
			settingMap(FILD01);
			gamePlay = true;
			break;
		case 5:
			settingMap(FILD02);
			gamePlay = true;
			break;
		case 6:
			settingMap(FILD03);
			gamePlay = true;
			break;
		case 7:
			settingMap(BATTLE);
			gamePlay = true;
			break;
		case 8:
			settingMap(BATTLE02);
			gamePlay = true;
			break;
		case 9:
			settingMap(BATTLE03);
			gamePlay = true;
			break;
		default:
			return;
		}

		ending();//엔딩 급하게

		//<- 게임 인잇
		drawMap(15);
		Sleep(100);
		/*
			추가할것

			샵, 가방 등 플레이어 없을 곳에 출력안되게
			샵, 가방 ui따로 만들기 draw함수를 따로 만들거나 draw함수 클래스를 새로 만들자
		*/
		//루프
		while (gamePlay)
		{				
			int s = keyInput();									

			if (map == LOBY || map == FILD01 || map == FILD02 || map == FILD03)
			{
				switch (s)
				{
				case KEY_LEFT:
					if (player.getPlayer().hpCur > 1)
					{
						player.setPlayer().hpCur = player.getPlayer().hpCur - 1;
						player.setPlayer().expCur = player.getPlayer().expCur + 1;
					}
					util.move(tMap, -2, 0, player.p_Pos_X, player.p_Pos_Y, map, gamePlay);
					break;
				case KEY_RIGHT:
					if (player.getPlayer().hpCur > 1)
					{
						player.setPlayer().hpCur = player.getPlayer().hpCur - 1;
						player.setPlayer().expCur = player.getPlayer().expCur + 1;
					}
					util.move(tMap, 2, 0, player.p_Pos_X, player.p_Pos_Y, map, gamePlay);
					break;
				case KEY_UP:
					if (player.getPlayer().hpCur > 1)
					{
						player.setPlayer().hpCur = player.getPlayer().hpCur - 1;
						player.setPlayer().expCur = player.getPlayer().expCur + 1;
					}
					util.move(tMap, 0, -1, player.p_Pos_X, player.p_Pos_Y, map, gamePlay);
					break;
				case KEY_DOWN:
					if (player.getPlayer().hpCur > 1)
					{
						player.setPlayer().hpCur = player.getPlayer().hpCur - 1;
						player.setPlayer().expCur = player.getPlayer().expCur + 1;
					}
					util.move(tMap, 0, 1, player.p_Pos_X, player.p_Pos_Y, map, gamePlay);
					break;
				case KEY_ESC:
					if (map == FILD01 || map == FILD02 || map == FILD03)
					{
						map = 0;
						gamePlay = false;
					}
					else if (map == LOBY)
					{

					}
					break;
				case KEY_I:
					break;
				default:
					break;
				}
			}
			else if (map == SHOP)
			{
				_shop.inShop(player,gamePlay,map);
			}
			else if (map == INVEN)
			{
				player.playerEquipShow(player,gamePlay,map);
			}
			else if (map == HOSPITAL)
			{
				_shop.isHospital(player, gamePlay, map);
			}
			else if (map == BATTLE)
			{
				battleCheck(_battleNum,gamePlay,map);
			}
			else if (map == BATTLE02)
			{
				battleCheck02(_battleNum, gamePlay, map);
			}
			else if (map == BATTLE03)
			{
				battleCheck03(_battleNum, gamePlay, map);
			}
			levelCheck(player.getPlayer().expCur, player.getPlayer().expMax);
			player.setPlayerMap(map);

			if (map == LOBY)
			{
				drawUI();
			}
			else if(map == FILD01 || map == FILD02 || map == FILD03)
			{
				fildUI();
				monsterMgr();
			}			
			Sleep(50);
		}
	}
}

void GameManager::InitShop(Shop & shop)
{
	//무기
	shop.sAddItem(Item("살구나무로 맹근 너클", 300, 3, 0, 10, 20), true);
	shop.sAddItem(Item("여운의 노가다 목장갑", 500, 3, 0, 15, 25), true);
	shop.sAddItem(Item("주먹 장갑", 1000, 2, 0, 30, 50), true);
	shop.sAddItem(Item("세월이 느껴지는 철장갑", 1200, 4, 0, 40, 75), true);
	shop.sAddItem(Item("오뉴월 서리가 맺힌 너클", 2000, 1, 0, 80, 150), true);
	shop.sAddItem(Item("판도라의상자", 100000, 1, 0, 1, 1000), true);
	shop.sAddItem(Item("짱쌘무기", 200000, 1, 0, 1000, 1000), true);

	//방어구
	shop.sAddItem(Item("코코볼로 만든 옷", 200, 5, 1, 5, 8), true);
	shop.sAddItem(Item("드락사르의 옷", 450, 3, 1, 10, 15), true);
	shop.sAddItem(Item("짜왕범벅이 된 천갑옷", 700, 2, 1, 10, 30), true);
	shop.sAddItem(Item("기성세대의 월급봉투", 1000, 1, 1, 25, 60), true);
	shop.sAddItem(Item("시배목 전리품 보닛아머", 1500, 1, 1, 70, 100), true);
	shop.sAddItem(Item("러시안룰렛 아머", 50000, 1, 1, 1, 1000), true);	
}

void GameManager::InitMonster()
{
	monster[0]._name = "다람쥐";
	monster[0]._text = "넥슨은 다람쥐를 뿌려라!!";
	monster[0]._maxHp = 300;
	monster[0]._curHp = monster[0]._maxHp;
	monster[0]._minAttack = 50;
	monster[0]._maxAttack = 100;
	monster[0]._def = 10;
	monster[0]._exp = 30;
	monster[0]._gold = 120;

	monster[1]._name = "뱀";
	monster[1]._text = "문지기를 뚫고 간신히 만난 몬스터";
	monster[1]._maxHp = 350;
	monster[1]._curHp = monster[1]._maxHp;
	monster[1]._minAttack = 70;
	monster[1]._maxAttack = 100;
	monster[1]._def = 15;
	monster[1]._exp = 60;
	monster[1]._gold = 200;

	monster[2]._name = "해골";
	monster[2]._text = "WA!!!! 샌주우!!!";
	monster[2]._maxHp = 500;
	monster[2]._curHp = monster[2]._maxHp;
	monster[2]._minAttack = 50;
	monster[2]._maxAttack = 200;
	monster[2]._def = 30;
	monster[2]._exp = 150;
	monster[2]._gold = 400;

	monster[3]._name = "멧돼지";
	monster[3]._text = "가성비 좋은 든든~한 국밥의 메인재료";
	monster[3]._maxHp = 700;
	monster[3]._curHp = monster[3]._maxHp;
	monster[3]._minAttack = 100;
	monster[3]._maxAttack = 250;
	monster[3]._def = 40;
	monster[3]._exp = 350;
	monster[3]._gold = 1000;

	monster[4]._name = "보팔레빗";
	monster[4]._text = "만만해보이는 외모와는 달리 매우 잔혹한 생물";
	monster[4]._maxHp = 500;
	monster[4]._curHp = monster[4]._maxHp;
	monster[4]._minAttack = 150;
	monster[4]._maxAttack = 300;
	monster[4]._def = 60;
	monster[4]._exp = 300;
	monster[4]._gold = 2500;

	monster[5]._name = "드래곤";
	monster[5]._text = "둥지를 짓다 뛰쳐나왔다.";
	monster[5]._maxHp = 1000;
	monster[5]._curHp = monster[5]._maxHp;
	monster[5]._minAttack = 300;
	monster[5]._maxAttack = 550;
	monster[5]._def = 60;
	monster[5]._exp = 500;
	monster[5]._gold = 5000;
}

void GameManager::battleCheck(int battleNum, bool &play, int& map)
{	
	srand(time(NULL));	
	char s;

	int battle = _battleNum;

	int n = rand() % 2;
	int a = 0;

	GameManager().settingMap(7);
	GameManager().drawMap(15);

	while (true)
	{			
		levelCheck(player.getPlayer().expCur, player.getPlayer().expMax);
		Util().setColor(Util().white, Util().black);

		Util().setXY(5, 31);
		cout << "[플레이어 이름 : " << player.getPlayer().name << "]";

		Util().setXY(30, 31);
		cout << "[레벨 " << player.getPlayer().level << "]";

		Util().setXY(50, 31);
		cout << "가진 돈 : " << player.getPlayer().gold << "원";

		Util().setXY(5, 33);
		cout << "[ 체력 ]";
		player.progressbar(player.getPlayer().hpMax, player.getPlayer().hpCur, 5, 34);

		Util().setXY(5, 36);
		cout << "[ 경험치 ]";
		player.expbar(player.getPlayer().expMax, player.getPlayer().expCur, 5, 37);

		Util().setXY(50, 33);
		cout << "[ 최소 ~ 최대 공격력 ]";

		Util().setXY(75, 33);
		cout << "[ 장착한 무기 ]";

		if (!player.getPlayer().equipB[0])
		{
			Util().setXY(75, 34);
			cout << "[없음]" << endl;
			Util().setXY(50, 34);
			cout << "[" << player.getPlayer().attackMin << " ~ " << player.getPlayer().attackMax << "]";
		}
		else
		{
			Util().setXY(75, 34);
			cout << "[" << player.getPlayer().equipT[0].getName() << "]" << endl;
			Util().setXY(50, 34);
			cout << "[" << player.getPlayer().attackMin << "+" << player.getPlayer().equipT[0].getMin() << " ~ " << player.getPlayer().attackMax << "+" << player.getPlayer().equipT[0].getMax() << "]";
		}


		Util().setXY(75, 36);
		cout << "[ 장창한 방어구 ]";
		Util().setXY(50, 36);
		cout << "[ 최소 ~ 최대 방어력 ]";
		if (!player.getPlayer().equipB[1])
		{
			Util().setXY(75, 37);
			cout << "[없음]" << endl;
			Util().setXY(50, 37);
			cout << "[" << player.getPlayer().defMin << " ~ " << player.getPlayer().defMax << "]";
		}
		else
		{
			Util().setXY(75, 37);
			cout << "[" << player.getPlayer().equipT[1].getName() << "]" << endl;
			Util().setXY(50, 37);
			cout << "[" << player.getPlayer().defMin << "+" << player.getPlayer().equipT[1].getMin() << " ~ " << player.getPlayer().defMax << "+" << player.getPlayer().equipT[1].getMax() << "]";
		}								

		if (battle == 0)
		{
			Util().setXY(60, 4);
			Util().setColor(Util().white, Util().black);
			cout << "[" << monster[n]._name << "]";
			player.progressbar(monster[n]._maxHp, monster[n]._curHp, 60, 5);
			Util().setXY(60, 7);
			cout << "설명 :" << monster[n]._text;
			Util().setXY(60, 8);
			cout << "공격력 :" << monster[n]._minAttack << " ~ " << monster[n]._maxAttack;
			Util().setXY(60, 9);
			cout << "방어력 :" << monster[n]._def;
			Util().setXY(60, 10);
			cout << "처치시 획득 경험치 :" << monster[n]._exp;
			Util().setXY(60, 11);
			cout << "처치시 획득 골드 :" << monster[n]._gold;

			Util().setXY(60, 26);
			cout << "1. 공격하기     2.도망가기" << endl;
			Util().setXY(60, 27);
			cout << "메뉴를 선택하세요 :"; cin >> a;

			if (a == 2)
			{				
				play = false;
				map = 4;
				break;
			}
			else if (a == 1)
			{
				int tAttackMin = player.getPlayer().attackMin;
				int tAttackMax = player.getPlayer().attackMax;

				if (player.getPlayer().equipB[EQ_WEPON])//무기 끼고있다면 더함
				{
					tAttackMin += player.getPlayer().equipT[EQ_WEPON].getMin();
					tAttackMax += player.getPlayer().equipT[EQ_WEPON].getMax();
				}

				int tAttack = rand() % (tAttackMax - tAttackMin + 1) + tAttackMin;
				int tArmor = monster[n]._def;

				int Damage = tAttack - tArmor;
				Damage = Damage < 1 ? 1 : Damage;

				monster[n]._curHp -= Damage;

				if (monster[n]._curHp <= 0)
				{
					Util().setXY(60, 27);
					cout << "몬스터를 잡았다!" << endl;
					Sleep(1000);
					player.setPlayer().expCur += monster[n]._exp;
					player.setPlayer().gold += monster[n]._gold;

					monster[n]._curHp = monster[n]._maxHp;			

					system("pause");
					play = false;
					map = 4;
					break;
				}

				tAttack = rand() % (monster[n]._maxAttack - monster[n]._minAttack + 1) + monster[n]._minAttack;

				int pArmorMin = player.getPlayer().defMin;
				int pArmorMax = player.getPlayer().defMax;

				if (player.getPlayer().equipB[EQ_ARMOR])
				{
					pArmorMin += player.getPlayer().equipT[EQ_ARMOR].getMin();
					pArmorMax += player.getPlayer().equipT[EQ_ARMOR].getMax();
				}
				tArmor = rand() % (pArmorMax - pArmorMin + 1) + pArmorMin;
				Damage = tAttack - tArmor;

				Damage = Damage < 1 ? 1 : Damage;

				player.setPlayer().hpCur -= Damage;

				if (player.getPlayer().hpCur <= 0)
				{
					Util().setXY(60, 27);
					cout << "플레이어 사망!"<<endl;
					Sleep(1000);

					int tExp = player.getPlayer().expCur*0.1;
					int tGold = player.getPlayer().gold *0.1;

					player.setPlayer().expCur -= tExp; //죽으면 경험치 돈 상실
					player.setPlayer().gold -= tGold;	

					map = 0;
					play = false;
					break;
				}
			}
		}
	}
}

void GameManager::battleCheck02(int battleNum, bool & play, int & map)
{
	srand(time(NULL));
	char s;

	int battle = _battleNum;

	int n = rand() % 4 +2;
	int a = 0;
	GameManager().settingMap(7);
	GameManager().drawMap(15);
	while (true)
	{
		levelCheck(player.getPlayer().expCur, player.getPlayer().expMax);

		Util().setColor(Util().white, Util().black);

		Util().setXY(5, 31);
		cout << "[플레이어 이름 : " << player.getPlayer().name << "]";

		Util().setXY(30, 31);
		cout << "[레벨 " << player.getPlayer().level << "]";

		Util().setXY(50, 31);
		cout << "가진 돈 : " << player.getPlayer().gold << "원";

		Util().setXY(5, 33);
		cout << "[ 체력 ]";
		player.progressbar(player.getPlayer().hpMax, player.getPlayer().hpCur, 5, 34);

		Util().setXY(5, 36);
		cout << "[ 경험치 ]";
		player.expbar(player.getPlayer().expMax, player.getPlayer().expCur, 5, 37);

		Util().setXY(50, 33);
		cout << "[ 최소 ~ 최대 공격력 ]";

		Util().setXY(75, 33);
		cout << "[ 장착한 무기 ]";

		if (!player.getPlayer().equipB[0])
		{
			Util().setXY(75, 34);
			cout << "[없음]" << endl;
			Util().setXY(50, 34);
			cout << "[" << player.getPlayer().attackMin << " ~ " << player.getPlayer().attackMax << "]";
		}
		else
		{
			Util().setXY(75, 34);
			cout << "[" << player.getPlayer().equipT[0].getName() << "]" << endl;
			Util().setXY(50, 34);
			cout << "[" << player.getPlayer().attackMin << "+" << player.getPlayer().equipT[0].getMin() << " ~ " << player.getPlayer().attackMax << "+" << player.getPlayer().equipT[0].getMax() << "]";
		}


		Util().setXY(75, 36);
		cout << "[ 장창한 방어구 ]";
		Util().setXY(50, 36);
		cout << "[ 최소 ~ 최대 방어력 ]";
		if (!player.getPlayer().equipB[1])
		{
			Util().setXY(75, 37);
			cout << "[없음]" << endl;
			Util().setXY(50, 37);
			cout << "[" << player.getPlayer().defMin << " ~ " << player.getPlayer().defMax << "]";
		}
		else
		{
			Util().setXY(75, 37);
			cout << "[" << player.getPlayer().equipT[1].getName() << "]" << endl;
			Util().setXY(50, 37);
			cout << "[" << player.getPlayer().defMin << "+" << player.getPlayer().equipT[1].getMin() << " ~ " << player.getPlayer().defMax << "+" << player.getPlayer().equipT[1].getMax() << "]";
		}

		if (battle == 0)
		{
			Util().setXY(60, 4);
			Util().setColor(Util().white, Util().black);
			cout << "[" << monster[n]._name << "]";
			player.progressbar(monster[n]._maxHp, monster[n]._curHp, 60, 5);
			Util().setXY(60, 7);
			cout << "설명 :" << monster[n]._text;
			Util().setXY(60, 8);
			cout << "공격력 :" << monster[n]._minAttack << " ~ " << monster[n]._maxAttack;
			Util().setXY(60, 9);
			cout << "방어력 :" << monster[n]._def;
			Util().setXY(60, 10);
			cout << "처치시 획득 경험치 :" << monster[n]._exp;
			Util().setXY(60, 11);
			cout << "처치시 획득 골드 :" << monster[n]._gold;

			Util().setXY(60, 26);
			cout << "1. 공격하기     2.도망가기" << endl;
			Util().setXY(60, 27);
			cout << "메뉴를 선택하세요 :"; cin >> a;

			if (a == 2)
			{
				play = false;
				map = 5;
				break;
			}
			else if (a == 1)
			{
				int tAttackMin = player.getPlayer().attackMin;
				int tAttackMax = player.getPlayer().attackMax;

				if (player.getPlayer().equipB[EQ_WEPON])//무기 끼고있다면 더함
				{
					tAttackMin += player.getPlayer().equipT[EQ_WEPON].getMin();
					tAttackMax += player.getPlayer().equipT[EQ_WEPON].getMax();
				}

				int tAttack = rand() % (tAttackMax - tAttackMin + 1) + tAttackMin;
				int tArmor = monster[n]._def;

				int Damage = tAttack - tArmor;
				Damage = Damage < 1 ? 1 : Damage;

				monster[n]._curHp -= Damage;

				if (monster[n]._curHp <= 0)
				{
					Util().setXY(60, 27);
					cout << "몬스터를 잡았다!" << endl;
					Sleep(1000);
					player.setPlayer().expCur += monster[n]._exp;
					player.setPlayer().gold += monster[n]._gold;

					monster[n]._curHp = monster[n]._maxHp;

					system("pause");
					play = false;
					map = 5;
					break;
				}

				tAttack = rand() % (monster[n]._maxAttack - monster[n]._minAttack + 1) + monster[n]._minAttack;

				int pArmorMin = player.getPlayer().defMin;
				int pArmorMax = player.getPlayer().defMax;

				if (player.getPlayer().equipB[EQ_ARMOR])
				{
					pArmorMin += player.getPlayer().equipT[EQ_ARMOR].getMin();
					pArmorMax += player.getPlayer().equipT[EQ_ARMOR].getMax();
				}
				tArmor = rand() % (pArmorMax - pArmorMin + 1) + pArmorMin;
				Damage = tAttack - tArmor;

				Damage = Damage < 1 ? 1 : Damage;

				player.setPlayer().hpCur -= Damage;

				if (player.getPlayer().hpCur <= 0)
				{
					Util().setXY(60, 27);
					cout << "플레이어 사망!" << endl;
					Sleep(1000);

					int tExp = player.getPlayer().expCur*0.1;
					int tGold = player.getPlayer().gold *0.1;

					player.setPlayer().expCur -= tExp; //죽으면 경험치 돈 상실
					player.setPlayer().gold -= tGold;

					map = 0;
					play = false;
					break;
				}
			}
		}
	}
}

void GameManager::battleCheck03(int battleNum, bool & play, int & map)
{
	srand(time(NULL));
	char s;

	int battle = _battleNum;

	int n = 5;
	int a = 0;

	GameManager().settingMap(7);
	GameManager().drawMap(15);

	while (true)
	{

		levelCheck(player.getPlayer().expCur, player.getPlayer().expMax);
		Util().setColor(Util().white, Util().black);

		Util().setXY(5, 31);
		cout << "[플레이어 이름 : " << player.getPlayer().name << "]";

		Util().setXY(30, 31);
		cout << "[레벨 " << player.getPlayer().level << "]";

		Util().setXY(50, 31);
		cout << "가진 돈 : " << player.getPlayer().gold << "원";

		Util().setXY(5, 33);
		cout << "[ 체력 ]";
		player.progressbar(player.getPlayer().hpMax, player.getPlayer().hpCur, 5, 34);

		Util().setXY(5, 36);
		cout << "[ 경험치 ]";
		player.expbar(player.getPlayer().expMax, player.getPlayer().expCur, 5, 37);

		Util().setXY(50, 33);
		cout << "[ 최소 ~ 최대 공격력 ]";

		Util().setXY(75, 33);
		cout << "[ 장착한 무기 ]";

		if (!player.getPlayer().equipB[0])
		{
			Util().setXY(75, 34);
			cout << "[없음]" << endl;
			Util().setXY(50, 34);
			cout << "[" << player.getPlayer().attackMin << " ~ " << player.getPlayer().attackMax << "]";
		}
		else
		{
			Util().setXY(75, 34);
			cout << "[" << player.getPlayer().equipT[0].getName() << "]" << endl;
			Util().setXY(50, 34);
			cout << "[" << player.getPlayer().attackMin << "+" << player.getPlayer().equipT[0].getMin() << " ~ " << player.getPlayer().attackMax << "+" << player.getPlayer().equipT[0].getMax() << "]";
		}


		Util().setXY(75, 36);
		cout << "[ 장창한 방어구 ]";
		Util().setXY(50, 36);
		cout << "[ 최소 ~ 최대 방어력 ]";
		if (!player.getPlayer().equipB[1])
		{
			Util().setXY(75, 37);
			cout << "[없음]" << endl;
			Util().setXY(50, 37);
			cout << "[" << player.getPlayer().defMin << " ~ " << player.getPlayer().defMax << "]";
		}
		else
		{
			Util().setXY(75, 37);
			cout << "[" << player.getPlayer().equipT[1].getName() << "]" << endl;
			Util().setXY(50, 37);
			cout << "[" << player.getPlayer().defMin << "+" << player.getPlayer().equipT[1].getMin() << " ~ " << player.getPlayer().defMax << "+" << player.getPlayer().equipT[1].getMax() << "]";
		}
			Util().setXY(60, 4);
			Util().setColor(Util().white, Util().black);
			cout << "[" << monster[n]._name << "]";
			player.progressbar(monster[n]._maxHp, monster[n]._curHp, 60, 5);
			Util().setXY(60, 7);
			cout << "설명 :" << monster[n]._text;
			Util().setXY(60, 8);
			cout << "공격력 :" << monster[n]._minAttack << " ~ " << monster[n]._maxAttack;
			Util().setXY(60, 9);
			cout << "방어력 :" << monster[n]._def;
			Util().setXY(60, 10);
			cout << "처치시 획득 경험치 :" << monster[n]._exp;
			Util().setXY(60, 11);
			cout << "처치시 획득 골드 :" << monster[n]._gold;

			Util().setXY(60, 26);
			cout << "1. 공격하기     2.도망가기" << endl;
			Util().setXY(60, 27);
			cout << "메뉴를 선택하세요 :"; cin >> a;

			if (a == 2)
			{
				play = false;
				map = 6;
				break;
			}
			else if (a == 1)
			{
				int tAttackMin = player.getPlayer().attackMin;
				int tAttackMax = player.getPlayer().attackMax;

				if (player.getPlayer().equipB[EQ_WEPON])//무기 끼고있다면 더함
				{
					tAttackMin += player.getPlayer().equipT[EQ_WEPON].getMin();
					tAttackMax += player.getPlayer().equipT[EQ_WEPON].getMax();
				}

				int tAttack = rand() % (tAttackMax - tAttackMin + 1) + tAttackMin;
				int tArmor = monster[n]._def;

				int Damage = tAttack - tArmor;
				Damage = Damage < 1 ? 1 : Damage;

				monster[n]._curHp -= Damage;

				if (monster[n]._curHp <= 0)
				{
					Util().setXY(60, 27);
					cout << "몬스터를 잡았다!" << endl;
					Sleep(1000);
					player.setPlayer().expCur += monster[n]._exp;
					player.setPlayer().gold += monster[n]._gold;

					monster[n]._curHp = monster[n]._maxHp;

					dCount++;

					system("pause");
					play = false;
					map = 6;
					break;
				}

				tAttack = rand() % (monster[n]._maxAttack - monster[n]._minAttack + 1) + monster[n]._minAttack;

				int pArmorMin = player.getPlayer().defMin;
				int pArmorMax = player.getPlayer().defMax;

				if (player.getPlayer().equipB[EQ_ARMOR])
				{
					pArmorMin += player.getPlayer().equipT[EQ_ARMOR].getMin();
					pArmorMax += player.getPlayer().equipT[EQ_ARMOR].getMax();
				}
				tArmor = rand() % (pArmorMax - pArmorMin + 1) + pArmorMin;
				Damage = tAttack - tArmor;

				Damage = Damage < 1 ? 1 : Damage;

				player.setPlayer().hpCur -= Damage;

				if (player.getPlayer().hpCur <= 0)
				{
					Util().setXY(60, 27);
					cout << "플레이어 사망!" << endl;
					Sleep(1000);

					int tExp = player.getPlayer().expCur*0.1;
					int tGold = player.getPlayer().gold *0.1;

					player.setPlayer().expCur -= tExp; //죽으면 경험치 돈 상실
					player.setPlayer().gold -= tGold;

					map = 0;
					play = false;
					break;
				}
			}
		
	}
}
