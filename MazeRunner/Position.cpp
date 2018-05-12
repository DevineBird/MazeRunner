#include "Position.h"
#include<iostream>
using namespace std;
#define InitSize 100
Way::Way()
{
	tail = head = new Position[InitSize];
}
void Way::Push(Position obj)
{
	tail->x = obj.x;
	tail->y = obj.y;
	tail->di = obj.di;
	tail++;
}

Position & Way::Pop()
{
	return *(--tail);
	// TODO: 在此处插入 return 语句
}

Position & Way::GetEnd()
{
	if (isempty())
	{
		cerr << "trying to get an item from an empty stack";
		exit(0);
	}
	return *(tail - 1);
	// TODO: 在此处插入 return 语句
}

inline bool Way::isempty()
{
	if (head==tail)
	{
		return true;
	}
	return false;
}

void Way::display()
{
	if(!isempty())
		for (Position*temp = head; temp != tail; temp++)
			cout << temp->x << ' ' << temp->y << endl;
	else
	{
		cout << "can't find a solution";
	}
}

