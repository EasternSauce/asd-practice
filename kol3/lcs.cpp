#include <iostream>
using namespace std;

//F[i][j] = LCS(A[0..i], B[0..j)
//LCS[0][i] = LCS[i][0] = 0
//F[i][j] = F[i-1][j-1] + 1 if A[i-1]==B[j-1]
//else
//F[i][j] = max(F[i-1][j], F[i][j-1])

int LCS(char A[], char B[], int n, int m){
	int F[n+1][m+1];

	for(int i = 0; i <= n; i++){
		F[0][i] = 0;
	}
	for(int i = 0; i <= m; i++){
		F[i][0] = 0;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(A[i-1] == B[j-1]){
				F[i][j] = F[i-1][j-1] + 1;
			}
			else{
				if(F[i-1][j] > F[i][j-1]){
					F[i][j] = F[i-1][j];
				}
				else{
					F[i][j] = F[i][j-1];
				}
			}
			
		}
	}

	int max = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			cout << F[i][j] << " ";
			if(F[i][j] > max) max = F[i][j];
		}
		cout << endl;
	}

	return max;

}

int main(){
	const int N = 5;
	const int M = 4;
	char A[N+1] = "KEEPO";
	char B[M+1] = "KUPA";

	cout << LCS(A, B, N, M);
}
