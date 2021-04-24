#include "Item.h"

void Item::addItem()
{
	if (_count < 99) //최대 갯수 99까지
	{
		_count++;
	}
}

void Item::delItem()
{
	if (_count > 0)//필욘 없지만 보기 좋기 좋으라고
	{
		_count--;
	}
}

Item::~Item()
{
}
