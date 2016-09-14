#include <iostream>
using namespace std;

int max(int a, int b){
	if(a>=b) return a;
	return b;
}

int knapsack(int weights[], int values[], int n/* number of items */, int c/* maximum knapsack capacity */){
	int F[c+1][n+1]; // weight so far and number of items inside subproblems

	for(int i = 0; i <= c; i++){
		F[i][0] = 0; // for zero items the solution is zero
	}
	for(int i = 0; i <= n; i++){
		F[0][i] = 0; // for total weight of zero the solution is zero
	}

	for(int i = 1; i <= n; i++){ // for every item
		for(int j = 1; j <= c; j++){ // for every weight till capacity
			if(weights[i-1] <= j){ //if weight of item i-1 is smaller than current total capacity
				F[j][i] = max(F[j-weights[i-1]][i-1] + values[i-1], F[j][i-1]); // we compare the gains and pick the best option
			}
			else F[j][i] = F[j][i-1]; // else just copy the result of i-1 items
		}
	}

	/*
	for(int i = 0; i <= c; i++){
		for(int j = 0; j <= n; j++){
			cout << F[i][j] << " ";
		}
		cout << endl;
	}
	*/

	return F[c][n];
}

int main(){
	const int N = 5;
	const int C = 13;
	int weights[N] = {5, 5, 3, 5, 4};
	int values[N] = {100, 100, 30, 5, 4};

	int result = knapsack(weights, values, N, C);
	cout << result;

}
