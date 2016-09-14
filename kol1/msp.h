// maximum subarray problem
// complexity: O(n)
#include "utility.h"

int msp(int A[], int n){
	int result = 0, partial = 0;
	for(int i = 0; i < n; i++){
		partial += A[i];
		partial = max(0, partial);
		if(partial > result) result = partial;
	}
	return result;
}
