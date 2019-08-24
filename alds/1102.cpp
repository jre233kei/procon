#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static const int N = 1000;

int lcs(string X, string Y){
    int C[N+1][N+1];
    int m = X.size();
    int n = Y.size();
    int maxl = 0;
    X = ' ' + X;
    Y = ' ' + Y;
    for(int i=0; i<=m;i++) C[i][0] = 0;
    for(int j=1; j<=n;j++) C[0][j] = 0;

    for(int i=1;i<=m;i++){
        for(int j=1; j<=n;j++){
            if(X[i]==Y[j]){
                C[i][j] = C[i-1][j-1] + 1;
            } else {
                C[i][j] = max(C[i-1][j], C[i][j-1]);
            }
            maxl = max(maxl, C[i][j]);
        }
    }
    return maxl;
}

int main(){
    string s1, s2;
    int n; cin >> n;
    for(int i=0;i<n;i++){
        cin >> s1 >> s2;
        cout << lcs(s1,s2) << endl;
    }
    return 0;
}