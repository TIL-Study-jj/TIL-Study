#include <iostream>
#include <algorithm>
using namespace std;
const int ml = 2250000; // 1500*1500
int arr[ml];

bool ss(int a, int b){
    return a > b;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); // faster cin/cout
    int n, num;
    cin >> n;
    int nn = n*n;
    for(int i = 0; i < nn; i++){
        cin >> num;
        arr[i] = num;
    }
    sort(arr, arr+nn, ss);
    cout << arr[n - 1];
    return 0;
}