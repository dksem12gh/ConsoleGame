#pragma once
#include<string>

using namespace std;

struct Monster
{
	string _name;
	string _text;
	int _maxHp;
	int _curHp;
	int _def;
	int _maxAttack;
	int _minAttack;
	int _exp;	
	int _gold;	
};

Monster monster[6];
Monster tMonster[1];

