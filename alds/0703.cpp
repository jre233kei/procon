#include <iostream>
#include <cstring>
using namespace std;
#define MAX 200000
#define SENTINEL 2000000000

typedef struct{
    char name[10];
    int num;
} Card;

int partition(Card A[], int p, int r){
    int i;
    Card x = A[r];
    i = p-1;
    for(int j=p;j<r;j++){
        if(A[j].num<=x.num){
            i = i+1;
            Card tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    Card tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp;
    return i+1;

}

void quickSort(Card A[], int p, int r){
    if (p < r){
        int q = partition(A,p,r);
        quickSort(A,p,q-1);
        quickSort(A,q+1,r);
    }
}

Card L[MAX/2+2], R[MAX/2+2];

void merge(Card A[], int n, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i < n1; ++i) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = A[mid + i];
    }
    L[n1].num = R[n2].num = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; ++k) {
        if(L[i].num <= R[j].num){
            A[k] = L[i++];
        }else{
            A[k] = R[j++];
        }
    }
}

void mergeSort(Card A[], int n, int left, int right){
    if(left+1 < right){
        int mid = (left+right)/2;
        mergeSort(A,n,left,mid);
        mergeSort(A,n,mid,right);
        merge(A,n,left,mid,right);
    }
}

int main(){

    Card A[MAX];
    Card B[MAX];
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> A[i].name >> A[i].num;
        strcpy(B[i].name, A[i].name);
        B[i].num = A[i].num;
    }

    mergeSort(A,n,0, n);
    quickSort(B,0,n-1);

    int fl = 0;


    for(int i= 0;i < n; i++){
        if(strcmp(A[i].name, B[i].name)!=0)
        {
            fl = 1;
            break;
        }
    }

    if(fl==1) cout << "Not stable" << endl;
    else cout << "Stable" << endl;


    for (int i = 0; i < n; ++i) {
        cout << B[i].name << " " << B[i].num << endl;
    }


    return 0;
}