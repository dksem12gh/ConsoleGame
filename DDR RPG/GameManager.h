#pragma once
#include<time.h>
#include"DDR RPG.h"
#include"Item.h"
#include "Shop.h"
#include "Player.h"

//키입력 방향
enum
{
	KEY_LEFT,
	KEY_RIGHT,
	KEY_UP,
	KEY_DOWN,
	KEY_ENTER,//선택
	KEY_ESC,//일시정지
	KEY_I,//인벤토리
};

struct pos
{
	int x;
	int y;
	bool dir; //가로 true : 왼 false : 오
	bool dir2;//세로 true : 위 false : 아래
};

class Shop;

class GameManager
{
private:	
	int shootCount;
	bool gamePlay;
	pos shoot[149];
public:	
	int _battleNum = 0;

	int dCount = 0;

	void title();
	void ending();

	//그리기 함수
	//lobyUI
	void drawUI();
	void fildUI();
	void drawMap(const int wallColor);
	int drawMenu(const int x, const int y, const int max);

	//heal UI
	void monsterMgr();

	//battle UI
	void battleUI();	

	void levelCheck(int curExp,int maxExp);

	//키입력
	int keyInput();

	//맵
	int nowLodingMap(); //현재 무슨맵 그리고있는지 int 값 리턴해 가르쳐주기
	void settingMap(const int map);	 //리턴받은값 맵 바꾸기

	//게임
	void gameStart(bool& gameMain); //메인 업데이트 함수

	void InitShop(Shop &shop);
	void InitMonster();

	void battleCheck(int battleNum , bool &play,int& map);

	void battleCheck02(int battleNum, bool &play, int& map);

	void battleCheck03(int battleNum, bool &play, int& map);

	int getBattleNum() { return _battleNum; }
	void setBattleNum(int battleNum) { _battleNum = battleNum; }

	void helpShow();

	GameManager();
		~GameManager();
};

