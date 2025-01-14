#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    long long a, b, n;
    int attempt;
    for(int i = 0; i < t; i++){
        cin >> a >> b >> n;
        attempt = 0;
        while(true){
            if (n < a || n < b){
                break;
            }
            else{
                if (a < b){
                    a += b;
                    attempt += 1;
                    if(a > n){
                        break;
                    }
                    attempt += 1;
                    b += a;
                }
                else{
                    b += a;
                    attempt += 1;
                    if(b > n){
                        break;
                    }
                    attempt += 1;
                    a += b;
                }
            }
        }
        cout << attempt << endl;
    }
}