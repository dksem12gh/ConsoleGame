#pragma once

#include <list>
#include <string>
#include "Item.h"
#include "Player.h"

using namespace std;

class Player;

class Shop
{
private:
	list<Item> itemList;//상품		
public:
	void sAddItem(const Item &item, bool first = false);
	bool sDelItem(const string &itemName);
	
	void inShop(Player &player,bool& play , int &mep);
	void isHospital(Player &player, bool& play, int &map);

	void sGetItem(const string &itemName, Item &item);
	bool sSellItem(Player &player);
	bool sBuyItem(Player &player);

	void showShop(int x, int y);
	void showShopList(int x, int y);

	Shop();
	~Shop();//리스트 정리
};

