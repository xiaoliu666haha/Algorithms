#include<stdio.h>
int linerSearch(int * A, int n, int v){
	int idx = -1;
	for(int i = 0;i <n;i++){
		if(A[i]==v){
			return i;
		}
	}
	return idx;
}
int main(){
	int A[7]={4,1,3,6,2,5,8};
	int n = sizeof(A)/sizeof(A[0]);
	printf("%d ",linerSearch(A,n,2));
	printf("%d ",linerSearch(A,n,7));
	return 0;
}