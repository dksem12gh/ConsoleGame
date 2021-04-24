#pragma once
#include "DDR RPG.h"

class Util
{
public:
	//색 설정
	enum
	{
		black,		//검
		blue,		//파
		green,		//초
		cyan,		//하늘
		red,		//빨
		purple,		//보
		yellow,		//노
		lightgray,	//밝회
		darkgray,	//어회
		lightblue,	//어파
		lightgreen,	//밝초
		lightcyan,	//밝하
		lightred,	//밝빨
		lightpurple,//밝보
		lightyellow,//밝노
		white		//하양
	};

	//위치 설정
	void setXY(const float x, const float y);
	
	//이동
	void move(unsigned char map[][149],const int dirX, const int dirY,int& p_X, int& p_Y,int& pMap, bool& inMap);//맵 정보,이동범위X,이동범위Y,이동하는 오브젝트 좌표 X,Y,루트탈출

	//커서 숨기자
	void setHide();

	//색 설정
	void setColor(const int fGround, const int bGround);

	bool _battle01;

	bool getBattle01() { return _battle01; }
	void setBattle01(bool battle01) { battle01 = _battle01; }

	Util();
	~Util();
};

