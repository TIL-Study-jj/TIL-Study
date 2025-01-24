#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int Dwarfs[9] = {0};
    int height;
    int heightsum = 0;
    for(int i = 0; i < 9; i++){
        cin >> height;
        Dwarfs[i] = height;
        heightsum += height;
    }
    sort(Dwarfs, Dwarfs+9);
    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 9; j++){
            if((heightsum - Dwarfs[i] - Dwarfs[j]) == 100){
                for(int k = 0; k < 9; k++){
                    if(k != i && k != j){
                        cout << Dwarfs[k] << "\n";
                    }
                }
                return 0;
            }
        }
    }
}