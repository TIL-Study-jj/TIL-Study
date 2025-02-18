#include <iostream>
#include <cmath>
using namespace std;
long long arr[1000000] = {0};
int main() {
    long long n;
    cin >> n;
    long long num;
    for(int i = 0; i < n ; i++){
        cin >> num;
        arr[i] = num;
    }
    long long b,c;
    cin >> b >> c;
    long long tot = n;
    for(int i = 0; i < n ; i++){
        if(arr[i]-b > 0){
            tot += (ceil((double(arr[i]-b))/c));
        }
        // cout << i << " " << (1 + ceil((double(arr[i]-b))/c)) << "\n";
    }
    cout << tot;
    return 0;
}