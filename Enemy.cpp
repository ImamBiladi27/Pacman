#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <vector>

class enemy:public FactoryGameplay{

public:


 vector<target> walk_queue;

vector<walk> BFSArray;

void AddArray( int x, int y, int wc , int back ){
	if( a.tmp_map[y][x] == ' ' || a.tmp_map[y][x] == '.' ){
		a.tmp_map[y][x] = '#';
		walk tmp;
		tmp.x = x;
		tmp.y = y;
		tmp.walk_count = wc;
		tmp.back = back;
		BFSArray.push_back( tmp );
	}
}



void FindPath( int sx, int sy, int x, int y ){
	memcpy( a.tmp_map, a.map, sizeof(a.map) );
	BFSArray.clear();
	walk tmp;
	tmp.x = sx;
	tmp.y = sy;
	tmp.walk_count = 0;
	tmp.back = -1;
	BFSArray.push_back( tmp );

	int i = 0;
	while( i < BFSArray.size() ){
		if( BFSArray[i].x == x && BFSArray[i].y == y ){
			walk_queue.clear();
			target tmp2;
			while( BFSArray[i].walk_count != 0 ){
				tmp2.x = BFSArray[i].x;
				tmp2.y = BFSArray[i].y;
				walk_queue.push_back( tmp2 );

				i = BFSArray[i].back;
			}

			break;
		}

		AddArray( BFSArray[i].x+1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x-1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );

		/*
			AddArray( BFSArray[i].x+1, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x-1, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x+1, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x+1, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );

			AddArray( BFSArray[i].x+1, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x-1, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x-1, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x-1, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );
		*/
		i++;
	}

	BFSArray.clear();
}
};
