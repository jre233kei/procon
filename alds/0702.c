#include <stdio.h>


int partition(int A[], int p, int r){
    int x,i;
    x = A[r];
    i = p-1;
    for(int j=p;j<r;j++){
        if(A[j]<=x){
            i = i+1;
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    int tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp;
    return i+1;

}

int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    int res = partition(A,0,n-1);
    for(int i=0;i<n;i++){
        if (i) printf(" ");
        if(i==res)
            printf("[%d]",A[i]);
        else
            printf("%d",A[i]);
    }
    printf("\n");
    return 0;
}