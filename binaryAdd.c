#include<stdio.h>
void binaryAdd(int *A, int *B,int *C,int n)
{

	
	for(int i = 0;i<n+1;i++){
		C[i] = 0;
	}
	for(int i = 0;i<n;i++){
		C[n-i] += A[n-1-i]+B[n-1-i];
		if(C[n-i]>=2){
			C[n-i-1]+=1;
			C[n-i]-=2;
		}
	}
}
int main(){
	int A[5] = {1,0,1,1,1};
	int B[5] = {0,1,0,1,1};
	int n = sizeof(A)/sizeof(A[0]);
	int C[6] = {0};
	binaryAdd(A,B,C,n);
	for(int i = 0;i<n;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	for(int i = 0;i<n;i++){
		printf("%d ",B[i]);
	}
	printf("\n");	
	for(int i = 0;i<n+1;i++){
		printf("%d ",C[i]);
	}
	printf("\n");
	return 0;
}
