#include <bits/stdc++.h>
using namespace std;

// nC2 구하는 문제

int n,m,k[15004],ret,cnt;

int main(){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> k[i];
    }
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            ret = k[i] + k[j];
            if (ret==m){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}