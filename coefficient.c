#include<stdio.h>

int f(int x){
	return 1 + x + 3 * x * x + 2 * x * x * x;
}

void coe(int* A){
	//s1+1进制，f(1)将所有系数加起来以保证每位系数不大于s1+1，但是仅仅只能用于系数全为正的情况
	int s1 = f(1);
	int s2 = f(s1 + 1);
	for(int i = 0; i <= 3; i++){
		A[i] = s2 % (s1 + 1);
		s2 = s2 / (s1 + 1);
	}
}

int main()
{
	int A[20] = {0};
	coe(A);
	for(int i = 0; i <= 3; i++){
		printf("%d\t",A[i]);
	}
	return 0;
}
