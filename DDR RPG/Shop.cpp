#include "Shop.h"
#include "Player.h"

//□□□□□□□■■■■■■■■■■□□□□□□□
//□□□□□□■■□□□■■□□□■■□□□□□□
//□□□□□■■□□□□■■□□□□■■□□□□□
//□□□□□■□□□□■■■■□□□□■□□□□□
//□□□□□■□□□□□■■□□□□□■□□□□□
//□□□□■□■■□□□■■□□□■■□■□□□□
//□□□□■□□□■■■■■■■■□□□■□□□□
//□□□■□□□■□□□□□□□□■□□□■□□□
//□□□■□□□■□□■□□■□□■□□□■□□□
//□□□■□□■□□□■□□■□□□■□□■□□□
//□□□□■□■□□□□□□□□□□■□■□□□□
//□□□□□■■■■□□□□□□■■■■□□□□□
//□□□□□□■□□■■□□■■□□■□□□□□□
//□□□□□■□■□□□■■□□□■□■□□□□□
//□□□□□■□□■□□□□□□■□□■□□□□□
//□□□□□□■■□■□□□□■□■■□□□□□□
//□□□□□□■■■■□□□□■■■■□□□□□□
//□□□□□□□■□□□□□□□□■□□□□□□□
//□□□□□□□□■■■■■■■■□□□□□□□□
//□□□□□□□□■□□■■□□■□□□□□□□□
//□□□□□□□□□■■□□■■□□□□□□□□□

Shop::Shop()
{
}

Shop::~Shop()
{
	itemList.clear();
}

void Shop::sAddItem(const Item & item, bool first)
{
	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++)
	{
		if ((*i).getName() == item.getName())
		{
			(*i).addItem();
			return;
		}
	}

	itemList.push_back(item);

	if (first == false)
	{
		itemList.back().setCount(1);
	}
}

bool Shop::sDelItem(const string & itemName)
{
	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++)
	{
		if ((*i).getName() == itemName)
		{
			(*i).delItem();

			if ((*i).getCount() <= 0)
			{
				itemList.erase(i);
				return true;
			}
		}
	}
	return false;
}

void Shop::inShop(Player & player,bool &play,int &map)
{
	bool done = false;
	char s;			
	while (done == false)
	{
		GameManager().settingMap(1);
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

		Util().setXY(30, 2);
		cout << "[ 상 점 ]";
		showShopList(15, 3);

		Util().setXY(110, 2);
		cout << "[ 인벤토리 ]";
		player.pShowItem(90, 3);

		Util().setXY(4, 20);
		cout << "하고 싶은걸 고르시오. (구매 (b), 판매 (s), 나가기(q)) : ";		
		cin >> s;
		cin.clear();
		if (s == tolower('q'))// tolower - 자동을 소문자 반환
		{
			map = 0;
			play = false;
			done = true;
		}
		else
		{
			if (s == tolower('b'))
			{
				sSellItem(player);
			}
			else if (s == tolower('s'))
			{
				sBuyItem(player);
			}						
		}
	}
}

void Shop::isHospital(Player & player, bool & play, int & map)
{
	bool done = false;
	char s;	
	while (done == false)
	{	
		int sprite = 0;
		GameManager().settingMap(2);
		GameManager().drawMap(15);
		while (sprite < 2)
		{
			Util().setXY(50, 2);
			cout << "              ■■■■■■■■■■";
			Util().setXY(50, 3);
			cout << "            ■■      ■■      ■■";
			Util().setXY(50, 4);
			cout << "          ■■        ■■        ■■";
			Util().setXY(50, 5);
			cout << "          ■        ■■■■        ■";
			Util().setXY(50, 6);
			cout << "          ■          ■■          ■";
			Util().setXY(50, 7);
			cout << "        ■  ■■      ■■      ■■  ■";
			Util().setXY(50, 8);
			cout << "        ■      ■■■■■■■■      ■";
			Util().setXY(50, 9);
			cout << "      ■      ■                ■      ■";
			Util().setXY(50, 10);
			cout << "      ■      ■    ■    ■    ■      ■";
			Util().setXY(50, 11);
			cout << "      ■    ■      ■    ■      ■    ■";
			Util().setXY(50, 12);
			cout << "        ■  ■                    ■  ■";
			Util().setXY(50, 13);
			cout << "          ■■■■            ■■■■";
			Util().setXY(50, 14);
			cout << "            ■    ■■    ■■    ■";
			Util().setXY(50, 15);
			cout << "          ■  ■      ■■      ■  ■";
			Util().setXY(50, 16);
			cout << "          ■    ■            ■    ■";
			Util().setXY(50, 17);
			cout << "            ■■  ■        ■  ■■";
			Util().setXY(50, 18);
			cout << "            ■■■■        ■■■■";
			Util().setXY(50, 19);
			cout << "              ■                ■";
			Util().setXY(50, 20);
			cout << "                ■■■■■■■■";
			Util().setXY(50, 21);
			cout << "                ■    ■■    ■";
			Util().setXY(50, 22);
			cout << "                 ■■    ■■";

			Sleep(500);
			Util().setColor(Util().black, Util().black);
			Util().setXY(50, 2);
			cout << "              ■■■■■■■■■■";
			Util().setXY(50, 3);
			cout << "            ■■      ■■      ■■";
			Util().setXY(50, 4);
			cout << "          ■■        ■■        ■■";
			Util().setXY(50, 5);
			cout << "          ■        ■■■■        ■";
			Util().setXY(50, 6);
			cout << "          ■          ■■          ■";
			Util().setXY(50, 7);
			cout << "        ■  ■■      ■■      ■■  ■";
			Util().setXY(50, 8);
			cout << "        ■      ■■■■■■■■      ■";
			Util().setXY(50, 9);
			cout << "      ■      ■                ■      ■";
			Util().setXY(50, 10);
			cout << "      ■      ■    ■    ■    ■      ■";
			Util().setXY(50, 11);
			cout << "      ■    ■      ■    ■      ■    ■";
			Util().setXY(50, 12);
			cout << "        ■  ■                    ■  ■";
			Util().setXY(50, 13);
			cout << "          ■■■■            ■■■■";
			Util().setXY(50, 14);
			cout << "            ■    ■■    ■■    ■";
			Util().setXY(50, 15);
			cout << "          ■  ■      ■■      ■  ■";
			Util().setXY(50, 16);
			cout << "          ■    ■            ■    ■";
			Util().setXY(50, 17);
			cout << "            ■■  ■        ■  ■■";
			Util().setXY(50, 18);
			cout << "            ■■■■        ■■■■";
			Util().setXY(50, 19);
			cout << "              ■                ■";
			Util().setXY(50, 20);
			cout << "                ■■■■■■■■";
			Util().setXY(50, 21);
			cout << "                ■    ■■    ■";
			Util().setXY(50, 22);
			cout << "                 ■■    ■■";

			Sleep(100);
			Util().setColor(Util().white, Util().black);

			Util().setXY(50, 2);
			cout << "              ■■■■■■■■■■";
			Util().setXY(50, 3);
			cout << "            ■■      ■■      ■■";
			Util().setXY(50, 4);
			cout << "          ■■        ■■        ■■";
			Util().setXY(50, 5);
			cout << "          ■        ■■■■        ■";
			Util().setXY(50, 6);
			cout << "          ■          ■■          ■";
			Util().setXY(50, 7);
			cout << "        ■  ■■      ■■      ■■  ■";
			Util().setXY(50, 8);
			cout << "        ■      ■■■■■■■■      ■";
			Util().setXY(50, 9);
			cout << "      ■      ■                ■      ■";
			Util().setXY(50, 10);
			cout << "      ■      ■                ■      ■";
			Util().setXY(50, 11);
			cout << "      ■    ■       _     _      ■    ■";
			Util().setXY(50, 12);
			cout << "        ■  ■                    ■  ■";
			Util().setXY(50, 13);
			cout << "          ■■■■            ■■■■";
			Util().setXY(50, 14);
			cout << "            ■    ■■    ■■    ■";
			Util().setXY(50, 15);
			cout << "          ■  ■      ■■      ■  ■";
			Util().setXY(50, 16);
			cout << "          ■    ■            ■    ■";
			Util().setXY(50, 17);
			cout << "            ■■  ■        ■  ■■";
			Util().setXY(50, 18);
			cout << "            ■■■■        ■■■■";
			Util().setXY(50, 19);
			cout << "              ■                ■";
			Util().setXY(50, 20);
			cout << "                ■■■■■■■■";
			Util().setXY(50, 21);
			cout << "                ■    ■■    ■";
			Util().setXY(50, 22);
			cout << "                 ■■    ■■";

			Sleep(100);
			Util().setColor(Util().white, Util().black);

			Util().setXY(50, 2);
			cout << "              ■■■■■■■■■■";
			Util().setXY(50, 3);
			cout << "            ■■      ■■      ■■";
			Util().setXY(50, 4);
			cout << "          ■■        ■■        ■■";
			Util().setXY(50, 5);
			cout << "          ■        ■■■■        ■";
			Util().setXY(50, 6);
			cout << "          ■          ■■          ■";
			Util().setXY(50, 7);
			cout << "        ■  ■■      ■■      ■■  ■";
			Util().setXY(50, 8);
			cout << "        ■      ■■■■■■■■      ■";
			Util().setXY(50, 9);
			cout << "      ■      ■                ■      ■";
			Util().setXY(50, 10);
			cout << "      ■      ■                ■      ■";
			Util().setXY(50, 11);
			cout << "      ■    ■       _     _      ■    ■";
			Util().setXY(50, 12);
			cout << "        ■  ■                    ■  ■";
			Util().setXY(50, 13);
			cout << "          ■■■■            ■■■■";
			Util().setXY(50, 14);
			cout << "            ■    ■■    ■■    ■";
			Util().setXY(50, 15);
			cout << "          ■  ■      ■■      ■  ■";
			Util().setXY(50, 16);
			cout << "          ■    ■            ■    ■";
			Util().setXY(50, 17);
			cout << "            ■■  ■        ■  ■■";
			Util().setXY(50, 18);
			cout << "            ■■■■        ■■■■";
			Util().setXY(50, 19);
			cout << "              ■                ■";
			Util().setXY(50, 20);
			cout << "                ■■■■■■■■";
			Util().setXY(50, 21);
			cout << "                ■    ■■    ■";
			Util().setXY(50, 22);
			cout << "                 ■■    ■■";

			Sleep(100);

			Util().setXY(50, 2);
			cout << "              ■■■■■■■■■■";
			Util().setXY(50, 3);
			cout << "            ■■      ■■      ■■";
			Util().setXY(50, 4);
			cout << "          ■■        ■■        ■■";
			Util().setXY(50, 5);
			cout << "          ■        ■■■■        ■";
			Util().setXY(50, 6);
			cout << "          ■          ■■          ■";
			Util().setXY(50, 7);
			cout << "        ■  ■■      ■■      ■■  ■";
			Util().setXY(50, 8);
			cout << "        ■      ■■■■■■■■      ■";
			Util().setXY(50, 9);
			cout << "      ■      ■                ■      ■";
			Util().setXY(50, 10);
			cout << "      ■      ■    ■    ■    ■      ■";
			Util().setXY(50, 11);
			cout << "      ■    ■      ■    ■      ■    ■";
			Util().setXY(50, 12);
			cout << "        ■  ■                    ■  ■";
			Util().setXY(50, 13);
			cout << "          ■■■■            ■■■■";
			Util().setXY(50, 14);
			cout << "            ■    ■■    ■■    ■";
			Util().setXY(50, 15);
			cout << "          ■  ■      ■■      ■  ■";
			Util().setXY(50, 16);
			cout << "          ■    ■            ■    ■";
			Util().setXY(50, 17);
			cout << "            ■■  ■        ■  ■■";
			Util().setXY(50, 18);
			cout << "            ■■■■        ■■■■";
			Util().setXY(50, 19);
			cout << "              ■                ■";
			Util().setXY(50, 20);
			cout << "                ■■■■■■■■";
			Util().setXY(50, 21);
			cout << "                ■    ■■    ■";
			Util().setXY(50, 22);
			cout << "                 ■■    ■■";

			sprite++;
		}

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

		int price;

		Util().setXY(53, 25);
		cout << "체력회복 비용 :"<<player.getPlayer().gold*0.3;
		price = player.getPlayer().gold*0.3;
		Util().setXY(53, 27);
		cout << "무엇을 도와드릴까요?. (체력회복 (h), 나가기(q)) : ";
		cin >> s;
		cin.clear();
		if (s == tolower('q'))// tolower - 자동을 소문자 반환
		{
			map = 0;
			play = false;
			done = true;
		}
		else
		{
			if (s == tolower('h'))
			{
				player.setPlayer().gold -= price;

				player.setPlayer().hpCur = player.getPlayer().hpMax;

				Util().setXY(53, 28);
				cout << "감사합니다, 다음에 또 오세요!" << endl;
				Sleep(1000);
				return;
			}
		}
	}
}

void Shop::sGetItem(const string & itemName, Item & item)
{
	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++)
	{
		if ((*i).getName() == itemName)
		{
			item = *i;
		}
	}
}

bool Shop::sSellItem(Player & player)
{
	Util().setXY(4, 24);
	Util().setColor(Util().white, Util().black);
	cout << "구매할 상품을 적으세요. :";
	string name;
	cin.ignore(1024, '\n');
	getline(cin, name);
	cin.ignore(1024, '\n');
	Util().setXY(4, 24);
	Util().setColor(Util().black, Util().black);
	cout << "구매할 상품을 적으세요. :                        ";

	Item item;
	sGetItem(name, item); //상점상품찾고 아이템에 넣는다

	if (item.getName() == "없음")//상춤 못찾으면
	{
		Util().setXY(4, 24);
		Util().setColor(Util().white, Util().black);
		cout << "그런 상품은 없습니다.";
		Sleep(500);
		Util().setXY(4, 24);
		Util().setColor(Util().black, Util().black);
		cout << "그런 상품은 없습니다.";
		Util().setColor(Util().white, Util().black);	
		return false;
	}

	if (player.buyItem(item) == false) //구매 못하면
	{
		Util().setXY(4, 24);
		Util().setColor(Util().white, Util().black);
		cout << "돈이 " << item.getPrice() - player.getPlayer().gold << "만큼 부족합니다.";
		Sleep(500);
		Util().setXY(4, 24);
		Util().setColor(Util().black, Util().black);
		cout << "                                                  ";
		Util().setColor(Util().white, Util().black);

		return false;
	}
	else
	{
		Util().setXY(4, 24);
		Util().setColor(Util().white, Util().black);
		cout << "아이템을 판매 했습니다." << endl;
		sDelItem(name);
		Sleep(500);
		Util().setXY(4, 24);
		Util().setColor(Util().black, Util().black);
		cout << "                                                  ";
		Util().setColor(Util().white, Util().black);
		return true;
	}
	
	return true;
}

bool Shop::sBuyItem(Player & player)
{
	Util().setXY(4, 24);
	Util().setColor(Util().white, Util().black);

	cout << "판매할 상품을 적어주세요. 되판매 가격은 기존가격의 60%입니다. : ";
	string name;	
	cin.ignore(1024, '\n');
	getline(cin, name);

	Util().setXY(4, 24);
	Util().setColor(Util().black, Util().black);
	cout << "판매할 상품을 적어주세요. 되판매 가격은 기존가격의 60%입니다. :                                           ";

	Item item;
	player.getItem(name, item);

	if (item.getName() == "없음")
	{
		Util().setXY(4, 24);
		Util().setColor(Util().white, Util().black);

		cout << "제대로 적으세요.";

		Sleep(500);
		Util().setXY(4, 24);
		Util().setColor(Util().black, Util().black);
		cout << "                                                            ";
		Util().setColor(Util().white, Util().black);
		return false;
	}

	int price = static_cast<int>(item.getPrice() *0.6);

	Util().setXY(4, 24);
	Util().setColor(Util().white, Util().black);

	cout << name << "은 " << price << " 이 가격에 판매할수 있습니다.";

	Sleep(500);
	Util().setXY(4, 24);
	Util().setColor(Util().black, Util().black);
	cout << "                                                             ";
	Util().setColor(Util().white, Util().black);

	sAddItem(item);
	player.sellItem(name, price);

	Util().setXY(4, 24);
	Util().setColor(Util().white, Util().black);

	cout << name << "을 판매 했습니다.";

	Sleep(500);
	Util().setXY(4, 24);
	Util().setColor(Util().black, Util().black);
	cout << "                                                            ";
	Util().setColor(Util().white, Util().black);

	return true;
}

void Shop::showShop(int x, int y)
{
}

void Shop::showShopList(int x, int y)
{
	int num = 1;
	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++,num++)
	{	
		Util().setXY(x, y + num);		
		cout << num << ".\t" << (*i).getName() << " X " << (*i).getCount() << "| 구매 값 : " << (*i).getPrice()<<endl;				
	}

}
