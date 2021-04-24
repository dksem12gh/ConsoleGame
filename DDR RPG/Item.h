#pragma once
#include<string>

using namespace std;


class Item
{
private:
	string _name;//이름	
	int _iMin;
	int _iMax;
	int _price;//가격
	int _count;//갯수
	int _type;//0무기 1아머 2공백

public:
	Item() : _name("없음"), _price(0), _count(0), _type(0),_iMin(0),_iMax(0) {}//기본생성
	Item(const string &name, int price, int count,int type,int min,int max) : _name(name), _price(price), _count(count),_type(type),_iMin(min),_iMax(max) //오버로딩 갯수확인
	{
		if (count < 0) { _count = 0; }
		else if (count > 99) { _count = 99; }
	}
	Item(const string &name) : _name(name){}//오버로딩 생성
	~Item();

	void addItem();

	void delItem();

	string getName() const{ return _name; }
	int getPrice() const{ return _price; }
	int getCount() const{ return _count; }
	int getType() const{ return _type; }
	int getMin() const{ return _iMin; }
	int getMax() const{ return _iMax; }

	void setName(const string& name) { _name = name; }
	void setPrice(const int price) { _price = price; }
	void setCount(const int count) { _count = count; }	
	void getType(const int type) { _type = type; }
	void getMin(const int min) { _iMin = min; }
	void getMax(const int max) { _iMax = max; }


};

