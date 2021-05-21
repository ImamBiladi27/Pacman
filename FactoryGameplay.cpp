#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

class FactoryGameplay{
public:
	InterfaceArena a;
	
	
	
void ShowMap()
{
	for(int i = 0; i < 18; i++) {
		printf("%s\n",a.map[i] );
	}
}

static gotoxy( short x, short y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;

    SetConsoleCursorPosition( hStdout, position ) ;
}
};

