#include"concol.h"
#include<iostream>
#include<stack>
#include<string>
#include<windows.h>
#include<limits>
#include<stdexcept>
#include<conio.h>
#include<algorithm>
using namespace std;
using namespace eku;

void menu();
void displayart();
void straightline();
void inputarray();
void bubblesort();
void selectionsort();
void sortswap(int i, int j);
void selectionoutput(int min, int i, int point);
void bubbleoutput(int j);
void transferarray();

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13
#define MAX_ARRAY 15

string array[MAX_ARRAY];
string arraycopy[MAX_ARRAY];
int size;

struct console
  {
  console( unsigned width, unsigned height )
    {
    SMALL_RECT r;
    COORD      c;
    hConOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (!GetConsoleScreenBufferInfo( hConOut, &csbi ))
      throw runtime_error( "You must be attached to a human." );

    r.Left   =
    r.Top    = 0;
    r.Right  = width -1;
    r.Bottom = height -1;
    SetConsoleWindowInfo( hConOut, TRUE, &r );

    c.X = width;
    c.Y = height;
    SetConsoleScreenBufferSize( hConOut, c );
    }

  ~console()
    {
    SetConsoleTextAttribute(    hConOut,        csbi.wAttributes );
    SetConsoleScreenBufferSize( hConOut,        csbi.dwSize      );
    SetConsoleWindowInfo(       hConOut, TRUE, &csbi.srWindow    );
    }

  void color( WORD color = 0x07 )
    {
    SetConsoleTextAttribute( hConOut, color );
    }

  HANDLE                     hConOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  };

console con( 50, 50 );

int main(void){
	menu();
	system("exit");
	return 0;
}

void menu(){
	SetConsoleTitle("Ayala Project");
	concolinit();
	string returncode;
	int position = 1;
	int key;
	int y=26;
	while(true){
		system("cls");
		key = 0;
		displayart();
		straightline();
		cout<<white<<"              Bubble-Selection Sort"<<endl<<dark_white;
		straightline();
		cout<<endl<<"     Main Menu(Use arrow keys to select)"<<endl;
		cout<<"        [ ] Input new array."<<endl;
		cout<<"        [ ] Sort by Bubble Sort."<<endl;
		cout<<"        [ ] Sort by Selection Sort."<<endl;
		cout<<"        [ ] Exit";
		if(position == 0){
			position = 4;
		}
		else if(position == 5){
			position = 1;
		}
		COORD p;
		switch(position){
			case 1:
    			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {9, 24});
    			cout<<green;
    			break;
    		case 2:
    			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {9, 25});
    			cout<<green;
    			break;
    		case 3:
    			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {9, 26});
    			cout<<green;
    			break;
			case 4:
    			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {9, 27});
    			cout<<green;
    			break;
    	}
		cout<<"X";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
    		switch((key=getche())) {
        		case KEY_UP:
					position--;
            		break;
        		case KEY_DOWN:
					position++;
            		break;
            	case ENTER:
            		Beep(500, 200);
            		transferarray();
            		if(position == 1){
            			inputarray();
					}
					else if(position == 2){
						bubblesort();
					}
					else if(position == 3){
						selectionsort();
					}
					else if(position == 4){
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 22});
						cout<<"                                           ";
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {8, 22});
						cout<<"Have a nice day!";
						return;
					}
				}
		Beep(800, 175);
    }
}

void inputarray(){
	while(true){
		system("cls");
		straightline();
		cout<<white<<"              Bubble-Selection Sort"<<endl<<dark_white;
		straightline();
		cout<<"Enter array size(MAX = 15): ";
		cin>>size;
		if(cin.fail()){
			cout<<endl<<red<<"Not a integer!"<<dark_white;
			getche();
			cin.clear();
			cin.ignore(256,'\n');
		}
		else if(size<=15){
			break;
		}
		else{
			cout<<endl<<red<<"Maximum reached!"<<dark_white;
			getche();
		}
	}
	
	Beep(500, 200);
	for(int i=0;i<=size-1;i++){
		cout<<"Input["<<i+1<<"]: ";
		cin>>array[i];
		Beep(500, 200);
	}
}

void transferarray(){
	for(int i=0;i<=MAX_ARRAY-1;i++){
		arraycopy[i] = array[i];
	}
}

void selectionsort(){
	system("cls");
	straightline();
	cout<<white<<"              Selection Sort Algorithm"<<endl<<dark_white;
	straightline();
	cout<<endl;
	for(int i=0;i<=size-1;i++){
		int min = i;
		for(int j=i+1;j<=size-1;j++){
			if(arraycopy[j] < arraycopy[min]){
				min = j;
			}
			system("cls");
			straightline();
			cout<<white<<"              Selection Sort Algorithm"<<endl<<dark_white;
			straightline();
			cout<<endl;
			cout<<green<<"INDEX: "<<i<<endl;
			cout<<"MIN: "<<min<<endl;
			cout<<red<<"SELECTED: "<<j<<dark_white<<endl<<endl;
			selectionoutput(min, i, j);
			Sleep(1500);
			Beep(500, 200);
		}
		sortswap(i, min);
	}
	cout<<endl<<endl<<"Finished!";
	getche();
}

void bubblesort(){
	system("cls");
	straightline();
	cout<<white<<"              Bubble Sort Algorithm"<<endl<<dark_white;
	straightline();
	cout<<endl;
	for(int i=size-1;i>=0;i--){
		for(int j=0;j<=i-1;j++){
			if(arraycopy[j] > arraycopy[j+1]){
				sortswap(j, j+1);
			}
			system("cls");
			straightline();
			cout<<white<<"              Bubble Sort Algorithm"<<endl<<dark_white;
			straightline();
			cout<<endl;
			bubbleoutput(j);
			Sleep(1000);
			Beep(500, 200);
		}
	}
	cout<<endl<<endl<<"Finished!";
	getche();
}

void sortswap(int i, int j){
	string temp = arraycopy[i];
	arraycopy[i] = arraycopy[j];
	arraycopy[j] = temp;
}

void displayart(){
	cout<<blue<<"          MMMMMMMM              MMMMMMMM"<<endl;
	cout<<"          MMMMMMMMMMMMMM   MMMMMMMMMMMMM"<<endl;
	cout<<"          MMMM   MMMMMMMMMMMMMMMM   MMMM"<<endl;
	cout<<"          MMMM                      MMMM"<<endl;
	cout<<"          MMMM         "<<white<<"AAAA"<<blue<<"         MMMM"<<endl;
	cout<<"          MMMM        "<<white<<"AAAAAA"<<blue<<"        MMMM"<<endl;
	cout<<"          MMMM       "<<white<<"AAA  AAA"<<blue<<"       MMMM"<<endl;
	cout<<"          MMMM      "<<white<<"AAA    AAA"<<blue<<"      MMMM"<<endl;
	cout<<"          MMMM     "<<white<<"AAAAAAAAAAAA"<<blue<<"     MMMM"<<endl;
	cout<<"          MMMM    "<<white<<"AAAAAAAAAAAAAA"<<blue<<"    MMMM"<<endl;
	cout<<"          MMMM   "<<white<<"AAA          AAA"<<blue<<"   MMMM"<<endl;
	cout<<"          MMMM  "<<white<<"AAA            AAA"<<blue<<"  MMMM"<<endl;
	cout<<"          MMMM "<<white<<"AAA              AAA"<<blue<<" MMMM"<<endl;
	cout<<"          MMMM                      MMMM"<<endl;
	cout<<"           MMMM   "<<white<<"AYALA-PROJECT"<<blue<<"   MMMM"<<endl;
	cout<<"            MMMM                  MMMM"<<endl;
	cout<<"              MMMMMMMMMMMMMMMMMMMMMM"<<endl;
	cout<<"                  MMMMMMMMMMMMMM"<<endl<<endl;
}


void selectionoutput(int min, int i, int point){
	for(int c=0;c<=size-1;c++){
		for(int p=0; p<=c; p++){
			cout<<"  ";
		}
		if(point==c){cout<<red;}
		if(i==c){cout<<green;}
		if(min==c){cout<<green;}
		cout<<c<<"-";
		cout<<arraycopy[c]<<dark_white<<endl;
	}
}

void bubbleoutput(int j){
	for(int c=0;c<=size-1;c++){
		for(int p=0; p<=c; p++){
			cout<<"  ";
		}
		if(j==c){cout<<green;}
		if(j+1==c){cout<<green;}
		cout<<c<<"-";
		cout<<arraycopy[c]<<dark_white<<endl;
	}
}

void straightline(){
	cout<<blue<<"================================================="<<endl<<dark_white;
}


