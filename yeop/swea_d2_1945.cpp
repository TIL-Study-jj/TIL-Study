#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n + 1; i++){
        int num;
        cin >> num;
        cout << "#" << i << " ";
        int jisu = 0;
        if(num % 2 == 0){
            while(num % 2 == 0){
                num /= 2;
                jisu += 1;
            }
        }
        cout << jisu << " ";
        
        jisu = 0;
        if(num % 3 == 0){
            while(num % 3 == 0){
                num /= 3;
                jisu += 1;
            }
        }
        cout << jisu << " ";
        
        jisu = 0;
        if(num % 5 == 0){
            while(num % 5 == 0){
                num /= 5;
                jisu += 1;
            }
        }
        cout << jisu << " ";
        
        jisu = 0;
        if(num % 7 == 0){
            while(num % 7 == 0){
                num /= 7;
                jisu += 1;
            }
        }
        cout << jisu << " ";
        
        jisu = 0;
        if(num % 11 == 0){
            while(num % 11 == 0){
                num /= 11;
                jisu += 1;
            }
        }
        cout << jisu << endl;
        
    }
}