#include <iostream>
using namespace std;

int min(int a, int b){
	if(a<=b) return a;
	return b;
}

const int X = 5;
const int Y = 5;

int shortest(int tab[Y][X], int y, int x){
	int F[y+1][x+1];

	for(int i = 0; i <= y; i++) F[i][0] = 1000;
	for(int i = 0; i <= x; i++) F[0][i] = 1000;
	F[0][0] = 0;
	F[1][0] = 0;
	F[0][1] = 0;

	for(int i = 1; i <= y; i++){
		for(int j = 1; j <= x; j++){
			F[i][j] = min(F[i-1][j], F[i][j-1]) + tab[i-1][j-1];
		}
	}

	for(int i = 0; i <= y; i++){
		for(int j = 0; j <= x; j++){
			cout << F[i][j] << " ";
		}
		cout << endl;
	}

	return F[y][x];
	

}

int main(){
	int tab[Y][X] = {
		{1, 1, 34, 31, 45},
		{2, 1, 11, 223, 22},
		{24, 1, 44, 44, 46},
		{1, 1, 2, 3, 4},
		{32, 1, 1, 1, 1}
	};
	cout << shortest(tab, Y, X);

}
