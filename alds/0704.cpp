#include <iostream>
using namespace std;
#define MAX 10000

int n;

void CountingSort(int A[], int B[], int k){
    int C[k+1];
    for (int i = 0; i <= k; ++i) {
        C[i] = 0;
    }

    for (int j = 1 ; j < n; ++j) {
        C[A[j]]++;
    }

    for (int i = 1; i <= k; ++i) {
        C[i] = C[i] + C[i-1];
    }

    for (int j = 1; j <= n ; j++) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}

int main(){

    cin >> n;

    int A[n+1];
    int B[n+1];

    for (int i = 0; i < n; ++i) {
        cin >> A[i+1];
    }

    CountingSort(A,B,MAX);

    for (int i = 0; i < n; ++i) {
        if(i) cout << " ";
        cout << B[i];
    }
    cout << endl;

    return 0;
}