#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        
        int oddcnt = 0;
        int evncnt = 0;
        int number;
        
        for(int j = 0; j < num; j++){
            cin >> number;
            if (number%2 == 0){
                evncnt++;
            }
            else{
                oddcnt++;
            }
        }

        if((oddcnt-evncnt) == 0){
            cout << "heeda0528" << endl;
        }
        else{
            int bigcnt;
            if(oddcnt > evncnt){
                bigcnt = oddcnt;
            }
            else{
                bigcnt = evncnt;
            }
            if(bigcnt % 2 == 0){
                cout << "heeda0528" << endl;
            }
            else{
                cout << "amsminn" << endl;       
            }
        }
        
    }
}