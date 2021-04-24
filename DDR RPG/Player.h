#pragma once
#include<list>
#include "Util.h"
#include "Item.h"

#define NAMEMAX 64


enum EQUIP
{
	EQ_WEPON,
	EQ_ARMOR,
	EQ_MAX
};

class Player
{	
	list<Item> itemList;

	struct inventory
	{
		Item item;
		int count;		
	};

	struct playerState
	{
		char name[NAMEMAX];
		int level;
		int attackMin;
		int attackMax;
		int defMin;
		int defMax;
		int hpMax;
		int hpCur;
		int expMax;
		int expCur;
		int gold;
		Item equipT[EQ_MAX];
		bool equipB[EQ_MAX];
		inventory invenT;
	};

	struct levelUp
	{
		int level = 1;
		int attackMin = 10;
		int attackMax = 20;
		int defMin = 10;
		int defMax = 20;
		int hpMax = 300;
		int expMax = 300;
	};
public:		

	playerState player;
	levelUp levelTable;

	int p_hp = 500;
	int p_mhp = 500;

	int p_mExp = 500;
	int p_Exp = 0;

	int p_Map_Set;

	int p_Pos_X;
	int p_Pos_Y;

	void playerDraw(const int dirx,const int diry, int& p_x, int& p_y);

	const playerState & getPlayer() const { return player; }
	playerState & setPlayer() { return player; }

	const levelUp & getLevelTable() const { return levelTable; }

	void pShowItem(int x, int y);
	void pShowItem2(int x, int y);
	void pShowItem3(int x, int y);

	void playerEquip(string name);
	void playerEquipShow(Player &player,bool &play,int &map);

	void pAddItem(const Item& item, bool first = false);
	bool pDelItem(const string &itemName);

	bool buyItem(const Item &item);
	void sellItem(const string &itemName, int price);

	void progressbar(int maxHp, int curHp, float x, float y);
	void expbar(int maxExp, int curExp, float x, float y);


	void getItem(const string &itemName, Item &item);

	int getPlayerMap() { return p_Map_Set; }
	void setPlayerMap(int num) { p_Map_Set = num; }
	
	Player();
	~Player();
};

