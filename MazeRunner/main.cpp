#include"Position.h"
#include<iostream>
using namespace std;
#define wid 8
#define high 8
bool maze[wid][high];
void setmaze()
{
	int x,y;
	for (int i = 0; i < wid; i++)
		for (int j = 0; j < high; j++)
			maze[i][j] = 1;
	while (cin>>x)
	{
		cin >> y;
		maze[x - 1][y - 1] = 0;
	}
}
int main()
{
	setmaze();
	Position start(1, 1);
	start.mark();
	Way solution;
	solution.Push(start);
	while (!solution.isempty())
	{
		if (solution.GetEnd().pass())
		{

			solution.Push(solution.GetEnd().nextPosition());
			solution.GetEnd().mark();
			if (solution.GetEnd().x==wid&&solution.GetEnd().y==high)
			{
				solution.display();
				break;
			}
		}
		else
		{
			solution.Pop();
			while (solution.GetEnd().di>4)
			{

				solution.Pop();
			}
		}
	}
	if (solution.isempty())
		solution.display();
	system("pause");
}

inline bool Position::pass()
{
	if ((x > 1 && maze[x - 2][y - 1]) || (y > 1 && maze[x - 1][y - 2]) || (x < wid&&maze[x][y - 1]) || (y < high&&maze[x - 1][y]))
	{
		return true;
	}
	return false;
}

Position Position::nextPosition()
{
	Position temp(x,y);
	do
	{
		switch (this->di++)//try once each direction
		{
		case 1:temp.x = x + 1; temp.y = y;  break;
		case 2:temp.y = y + 1; temp.x = x;  break;
		case 3:temp.x = x - 1; temp.y = y;  break;
		case 4:temp.y = y - 1; temp.x = x;  break;
		default:
			cerr << "can't fetch the next position";
			return temp;
		}
	} while (!(temp.x > 0 && temp.y > 0 && temp.x <= wid&&temp.y <= high&&maze[temp.x - 1][temp.y - 1]));
	return temp;
}

void Position::mark()
{
	maze[x - 1][y - 1] = 0;
}
