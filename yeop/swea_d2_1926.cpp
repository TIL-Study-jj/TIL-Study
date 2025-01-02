#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    int clap;
    string tsi = "";
    for(int i = 1; i < n + 1; i++){
        clap = 0;
        tsi = to_string(i);
        for(int j = 0; j < tsi.size(); j++){
            if (tsi[j] == '3' || tsi[j] == '6' || tsi[j] == '9'){
                clap += 1;
            }
        }
        if (clap == 0){
            cout << i << " ";    
        }
        else{
            for(int j = 0; j < clap; j++){
                cout << "-";    
            }
            cout << " ";    
        }
        
    }
}