#include "Util.h"

HANDLE coutHandle = GetStdHandle(STD_OUTPUT_HANDLE); //출력핸들

GameManager gm;

void Util::setXY(const float x, const float y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(coutHandle, pos);	
}

void Util::move(unsigned char map[][149],const int dirX, const int dirY ,int& p_X,int& p_Y,int& pMap,bool& inMap)
{
	//BLCOK_battlePotal01 = 232, //↑
	//BLCOK_battlePotal02 = 233, //↓
	//BLCOK_battlePotal03 = 234, //↔
	//BLCOK_healing = 196 ,	   //∞∞
	//BLCOK_shopPotal = 238, //√√
	//BLCOK_miniPotal = 230 //→→

	unsigned char object = map[p_Y + dirY][p_X + dirX];
	if (object == 224)
	{
		Player().playerDraw(dirX, dirY, p_X, p_Y);
	}
	else if (object == 238)
	{
		Player().playerDraw(dirX, dirY, p_X, p_Y);
		pMap = 1;
		inMap = false;
	}
	else if (object == 230)
	{
		Player().playerDraw(dirX, dirY, p_X, p_Y);
		pMap = 2;
		inMap = false;
	}
	else if (object == 196)
	{
		Player().playerDraw(dirX, dirY, p_X, p_Y);
		pMap = 3;
		inMap = false;
	}
	else if (object == 232)
	{
		Player().playerDraw(dirX, dirY, p_X, p_Y);
		gm.setBattleNum(0);
		pMap = 4;
		inMap = false;
	}
	else if (object == 233)
	{
		Player().playerDraw(dirX, dirY, p_X, p_Y);
		gm.setBattleNum(1);
		pMap = 5;
		inMap = false;
	}
	else if (object == 234)
	{
		Player().playerDraw(dirX, dirY, p_X, p_Y);
		gm.setBattleNum(2);
		pMap = 6;
		inMap = false;
	}

	switch (pMap)
	{
	case 4:
		if (object == 174 || object == 175)
		{
			Player().playerDraw(dirX, dirY, p_X, p_Y);
			pMap = 7;
			inMap = false;
		}
		break;
	case 5:
		if (object == 174 || object == 175)
		{
			Player().playerDraw(dirX, dirY, p_X, p_Y);
			pMap = 8;
			inMap = false;
		}
		break;
	case 6:
		if (object == 174 || object == 175)
		{
			Player().playerDraw(dirX, dirY, p_X, p_Y);
			pMap = 9;
			inMap = false;
		}
		break;	
	}

}

void Util::setHide()
{	
	CONSOLE_CURSOR_INFO cursor; //커서값
	cursor.bVisible = false;	//끄기
	cursor.dwSize = 1;
	SetConsoleCursorInfo(coutHandle, &cursor);	//커서값 지정
}

void Util::setColor(const int fGround, const int bGround)
{
	int txt = fGround + bGround * 16;
	SetConsoleTextAttribute(coutHandle, txt);
}

Util::Util()
{
}

Util::~Util()
{
}
