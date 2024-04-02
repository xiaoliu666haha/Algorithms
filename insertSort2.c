#include<stdio.h>
void insertSort(int * A,int n){
	for (int j =1;j<n;j++){
		int key = A[j];
		int i = j-1;
		while(i>=0 && A[i]<key){
			A[i+1]=A[i];
			i--;
		}
		A[i+1]=key;
	}
}
int main(){
	int A[6]={4,1,6,3,2,8};
	int n = sizeof(A)/sizeof(A[0]);
	insertSort(A,n);
	for (int i = 0;i<n;i++){
		printf("%d ",A[i]);
	}
	return 0;
}
