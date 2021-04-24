#include "Player.h"

void Player::playerDraw(const int dirx,const int diry, int& p_x, int& p_y)
{		
	Util().setXY(p_x, p_y);
	cout << " ";
	Util().setXY(p_x + dirx, p_y + diry);
	Util().setColor(Util().lightyellow, Util().black);
	cout << "P";
	p_x += dirx;
	p_y += diry;	
}

void Player::pShowItem(int x, int y)
{
	int num = 1;

	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++, num++)
	{
		Util().setXY(x, y + num);
		cout << num << ". " << (*i).getName() << " X " << (*i).getCount() << "| 판매값 :" << (*i).getPrice() * 0.6 << endl;
	}

	if (itemList.size() == 0)
	{
		Util().setXY(x, y + 1);
		cout << "가진 아이템이 없다                          " << endl;
	}
}


void Player::pShowItem2(int x, int y) //메인 화면의 작은 가방
{
	int num = 1;	

	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++ , num++)
	{
		Util().setXY(x,y + num);
		cout << num << ". " << (*i).getName().substr(0,4) + "···" << " X " << (*i).getCount() <<endl;
	}

	if (itemList.size() == 0)
	{
		Util().setXY(x, y+1);
		cout << "가진 아이템이 없다." << endl;
	}
}

void Player::pShowItem3(int x, int y) //옷장 건물의 가방
{
	int num = 1;

	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++, num++)
	{
		Util().setXY(x, y + num);
		if ((*i).getType() == 0)
		{
			cout << num << ". " << (*i).getName() << " X " << (*i).getCount() << "|\t [최소 공격력 :" << (*i).getMin()<<"] [최대 공격력 :"<< (*i).getMax() <<"]"<< endl;
		}
		else if ((*i).getType() == 1)
		{
			cout << num << ". " << (*i).getName() << " X " << (*i).getCount() << "|\t [최소 방어력 :" << (*i).getMin() << "] [최대 방어력 :" << (*i).getMax() << "]" << endl;
		}
	}

	if (itemList.size() == 0)
	{
		Util().setXY(x, y + 1);
		cout << "가진 아이템이 없다." << endl;
	}
}

void Player::playerEquip(string name)
{
	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++)
	{
		if ((*i).getName() == name) //상품을 찾으면
		{
			EQUIP eq;

			switch ((*i).getType())
			{
			case 0:
				eq = EQ_WEPON;
				break;
			case 1:
				eq = EQ_ARMOR;
				break;			
			}

			//아이템 이미 장착시 스왑
			if (player.equipB[eq] == true)
			{
				Item temp = player.equipT[eq];
				player.equipT[eq] = (*i);
				(*i) = temp;
			}
			else//장착 없다면 아이템 장착으로 인벤 지우기
			{
				player.equipT[eq] = (*i);
				pDelItem(name);
				player.equipB[eq] = true;
			}

			return;
		}
		else
		{						
		}
	}
}

void Player::playerEquipShow(Player &player, bool &play, int &map)
{
	bool done = false;
	char s;
	string name;
	while (done == false)
	{
		system("cls");
		GameManager().settingMap(2);
		GameManager().drawMap(15);

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
			cout << "[" << player.getPlayer().attackMin<<"+"<< player.getPlayer().equipT[0].getMin() << " ~ " << player.getPlayer().attackMax<<"+"<< player.getPlayer().equipT[0].getMax() << "]";
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
			cout << "[" << player.getPlayer().defMin <<"+"<< player.getPlayer().equipT[1].getMin()<< " ~ " << player.getPlayer().defMax<<"+"<<player.getPlayer().equipT[1].getMax() << "]";
		}

		Util().setXY(70, 2);
		cout << "[ 인벤토리 ]";
		player.pShowItem3(42, 3);

		Util().setXY(45, 25);
		cout << "두가지중 하나를 고르시오. (장착 (e), 나가기(q)) : ";
		cin >> s;
		cin.ignore(1024, '\n');
		if (s == tolower('q'))// tolower - 자동을 소문자 반환
		{
			map = 0;
			play = false;
			done = true;
		}
		else
		{
			if (s == tolower('e'))
			{
				Util().setXY(45, 25);
				Util().setColor(Util().black, Util().black);
				cout << "                                                         ";
				Util().setColor(Util().white, Util().black);
				Util().setXY(45, 25);
				cout << "장착할 아이템을 입력하세요. : ";
				getline(cin, name);
				cin.ignore(1024, '\n');
				playerEquip(name);
			}
		}
	}
	
}

void Player::pAddItem(const Item & item, bool first)
{
	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++)
	{
		if ((*i).getName() == item.getName()) //상품을 찾으면
		{
			(*i).addItem();//템 추가
			return;
		}
	}
	//못잦으면 추가
	itemList.push_back(item);

	if (first == false) //새 상품은 무조건 하나
	{
		itemList.back().setCount(1);
	}
}

bool Player::pDelItem(const string & itemName)
{
	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++)
	{
		if ((*i).getName() == itemName)
		{
			(*i).delItem();

			if ((*i).getCount() <= 0) //갯수가 0이되면 리스트에서 삭제
			{
				itemList.erase(i);
				return true;
			}
		}
	}
	//찾는게 없다면
	return false;
}

bool Player::buyItem(const Item & item)
{
	int price = item.getPrice();

	if (player.gold >= price)
	{
		player.gold -= price;
		pAddItem(item);
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

void Player::sellItem(const string & itemName, int price)
{
	pDelItem(itemName);
	player.gold += price;
}


void Player::progressbar(int maxHp, int curHp, float x, float y)
{
	int len = 15;
	int maxHP = maxHp;
	int curHP = curHp;
	int barCount = 0;

	float tick = (float)100 / len;
	float percent;

	Util().setXY(x, y);
	cout << curHP << " / " << maxHP << "\t";
	percent = (float)curHP / maxHP * 100;
	barCount = percent / tick;

	for (int i = 0; i < len; i++)
	{
		if (barCount > i)
		{
			Util().setColor(Util().black, Util().lightgreen);
			cout << " ";
			Util().setColor(Util().white, Util().black);
		}
		else
		{
			Util().setColor(Util().black, Util().red);
			cout << " ";
			Util().setColor(Util().white, Util().black);
		}
	}
}

void Player::expbar(int maxExp, int curExp, float x, float y)
{
	int len = 15;
	int maxEXP = maxExp;
	int curEXP = curExp;
	int barCount = 0;

	float tick = (float)100 / len;
	float percent;

	Util().setXY(x, y);
	cout << curEXP << " / " << maxEXP << "\t";
	percent = (float)curEXP / maxEXP * 100;
	barCount = percent / tick;

	for (int i = 0; i < len; i++)
	{
		if (barCount <= i)
		{
			Util().setColor(Util().black, Util().darkgray);
			cout << " ";
			Util().setColor(Util().white, Util().black);
		}
		else
		{
			Util().setColor(Util().black, Util().yellow);
			cout << " ";
			Util().setColor(Util().white, Util().black);
		}
	}
}

//리스트 검색해 이름찾으면 아이템저장
void Player::getItem(const string & itemName, Item & item)
{
	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++)
	{
		if ((*i).getName() == itemName)
		{
			item = *i;
		}
	}
}

Player::Player()
{	
	player.level = 1;
	player.hpMax = 500;
	player.hpCur = player.hpMax;	
	player.attackMin = 10;
	player.attackMax = 30;
	player.defMin = 10;
	player.defMax = 15;
	player.expMax = 100;
	player.expCur = 0;	
	player.gold = 1000000;	
	player.equipB[0] = false;
	player.equipB[1] = false;
}

Player::~Player()
{
}
