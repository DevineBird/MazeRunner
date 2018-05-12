#pragma once

class Position
{
public:
	Position(int a = 0, int b = 0) { x = a; y = b; }
	int x;
	int y;
	int di = 1;
	bool pass();
	void mark();
	Position nextPosition();
};

class Way
{
public:
	Way();
	Position *head;
	Position *tail;
	void Push(Position);
	Position& Pop();
	Position& GetEnd();
	bool isempty();
	~Way()
	{
		delete[]head;
	}
	void display();
};
