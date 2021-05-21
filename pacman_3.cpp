#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <vector>
#include "arena.cpp"
#include "FactoryGameplay.cpp"
#include "Player.cpp"
#include "Enemy.cpp"
using namespace std;

//public:







int main()
{
	FactoryGameplay g;
	//Player p;
	enemy e;
	InterfaceArena a;
    bool running = true;
	int x = 15; // hero x
	int y = 16; // hero y
	int old_x;
	int old_y;

	int ex = 1;
	int ey = 1;


	int pts = 0;

	printf("Instruction:\n1. Arrow Keys to move your hero\n2. Eat the dots produced by the Eater to gain poins\n3. Don't get caught by the Eater\n\n");
	printf("H -> Hard\nN -> Normal\nE -> Easy\n\nInput : ");

	char diffi;
	int speedmod = 3;

	cin >> diffi;

	if( diffi == 'N' ){
		speedmod = 2;
	}else if( diffi == 'H' ){
		speedmod = 1;
	}

	system("cls");
    g.ShowMap();

	g.gotoxy( x, y ); cout << "H";

	int frame = 0;

	e.FindPath( ex,ey,x,y );

	while( running ){
		g.gotoxy( x, y ); cout << " ";

		old_x = x;
		old_y = y;

		if ( GetAsyncKeyState( VK_UP ) ){
			if( a.map[y-1][x] == '.' ){ y--; pts++; } else
			if( a.map[y-1][x] == ' ' ) y--;
		}
		if ( GetAsyncKeyState( VK_DOWN ) ){
			if( a.map[y+1][x] == '.' ){ y++; pts++; } else
			if( a.map[y+1][x] == ' ' ) y++;
		}
		if ( GetAsyncKeyState( VK_LEFT ) ){
			if( a.map[y][x-1] == '.' ){ x--; pts++; } else
			if( a.map[y][x-1] == ' ' ) x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) ){
			if( a.map[y][x+1] == '.' ){ x++; pts++; } else
			if( a.map[y][x+1] == ' ' ) x++;
		}

		if( old_x != x || old_y != y ){
			e.FindPath( ex,ey,x,y );
		}

		g.gotoxy( x,y ); cout << "H";

		a.map[ey][ex] = '.';
		g.gotoxy( ex, ey ); cout << ".";

		if( frame%speedmod == 0 && e.walk_queue.size() != 0 ){
			ex = e.walk_queue.back().x;
			ey = e.walk_queue.back().y;
			e.walk_queue.pop_back();
		}

		g.gotoxy( ex, ey ); cout << " ";

		if( ex == x && ey == y ){
			break;
		}


		g.gotoxy( 32, 18 );
		g.gotoxy( 32, 1 ); cout << pts;
		Sleep( 100 );
		frame++;
	}

	system("cls");
	printf("You Lose and your score is : %i\t", pts );
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();

	return 0;
}
