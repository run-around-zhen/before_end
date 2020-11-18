
#include <stdio.h>
 
#define MAXN 5000000 + 10
typedef int ElementType;
 
ElementType Median(ElementType A[], int N);
 ElementType A[MAXN];
 inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x * f;
}
int main(){
	int T;
	scanf("%d ", &T);
	while(T --){
	int N, k;
	scanf("%d %d", &N, &k);
	k--;
//	for(int i = 0; i <  MAXN - 10;i ++) A[i] = 2e9;
	for(int i=0; i<N; i++){
		A[i] = read();
	}
	printf("%d\n", Median(A,k));
}
	// printf("Test:\n");
	// for(int i = 0; i < N; ++i){
	// 	printf("%f ", A[i]);
	// }
	return 0;
}
 
void swap(ElementType A[], int i, int j){
	// printf("Swaped! ");
	ElementType temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
 
int partition(ElementType A[], int N, int left, int right){
	// printf("reached! %d %d ", left, right);
	ElementType pivot = A[right];
	int index = left - 1;
	for(int i = left; i < right; ++i){
		if(A[i] < pivot) swap(A, ++index, i);
	}
	swap(A, ++index, right);
	return index;
}
 
// 查找N个元素中的第K个小的元素（来自编程珠玑）
ElementType Median(ElementType A[], int N){
	// printf("reached! ");
	int position = -1, left = 0, right = N - 1;
	int target = N / 2;
	// if(N % 2 == 0) --target; 
	// if(position == target) return A[target];
	while(1){
		if (position < target) {
			left = position + 1;
			position = partition(A, N, left, right);
		}
		else if(position > target){
			right = position - 1;
			position = partition(A, N, left, right);
		}
		else {
			return A[position];
		}	
	}
}
