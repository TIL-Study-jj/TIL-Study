#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int vinylcnt = 0;
    while(n >= 0){
        if(n % 5 == 0){
            vinylcnt += (n / 5);
            n = 0;
            break;
        }
        else{
            n -= 3;
            vinylcnt++;
        }
    }
    if(n == 0){
        cout << vinylcnt;
    }
    else{
        cout << "-1";
    }
}