#include <iostream>
using namespace std;

bool SSS(int A[], int n, int T){
	bool F[n+1][T+1];
	for(int i = 0; i <= n; i++){
		F[i][0] = true;
	}
	for(int i = 1; i <= T; i++){
		F[0][i] = false;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= T; j++){
			if(A[i] <= j)	F[i][j] = F[i-1][j] || F[i-1][j-A[i]];
			else			F[i][j] = F[i-1][j];
		}
	}

	return F[n][T];
}

int main(){
	const int N = 10;
	int A[N] = {1, 5, 3, 5, 4, 12, 8, 1, 2, 6};

	bool result = SSS(A, N, 0);
	if(result){
		cout << "true";
	}else{
		cout << "false";
	}

}
