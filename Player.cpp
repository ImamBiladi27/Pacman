#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;
class Player:public FactoryGameplay {
public:
	FactoryGameplay g;
	
private:
	int x;
	int y;	

public:
	
	Player( int x, int y ){
		this ->x = x;
		this ->y = y;
	}

	void move_x( int p ){
		if( a.map[y][x+p] == ' ' ) x += p;
	}

	void move_y( int p ){
		if( a.map[y+p][x] == ' ' ) y += p;
	}

	void move( int p, int q ){
		x += p;
		y += q;
	}

	int get_x(){ return x; }
	int get_y(){ return y; }

	void draw( char p ){
		a.map[x][y] = p;
		gotoxy( x, y ); printf( "%c", p );
	}
};


struct walk {
	short walk_count;
	short x;
	short y;
	short back;
};

struct target {
	short x;
	short y;
};
