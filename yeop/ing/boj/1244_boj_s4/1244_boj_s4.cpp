#include <iostream>
using namespace std;
int arr[100] = {0};
int main() {
    int n, num;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        arr[i] = num;
    }
    int s, gender, number;
    cin >> s;
    for(int i = 0; i < s; i++){
        cin >> gender >> number;
        if(gender == 2){ // using two pointer
            int lp = (number - 1) - 1;
            int rp = (number - 1) + 1;
            while(true){
                if(lp < 0 || rp >= n || arr[lp] != arr[rp]){
                    lp += 1;
                    // rp shouldn't be changed (range)
                    break;
                }
                lp--;
                rp++;
            }
            for(int j = lp; j < rp; j++){
                if(arr[j] == 1){
                    arr[j] = 0;
                }
                else{
                    arr[j] = 1;
                }
            }
        }
        else{
            for(int j = (number - 1); j < n; j += number){
                if(arr[j] == 1){
                    arr[j] = 0;
                }
                else{
                    arr[j] = 1;
                }
            }
        }
        // for(int i = 0; i < n; i++){
        //     cout << arr[i] << " ";
        // }
        // cout << "\n";
    }
    int arridx = 1;
    while(true){
        cout << arr[arridx - 1] << " ";
        if(arridx % 20 == 0){
            cout << "\n";
        }
        arridx++;
        if(arridx > n){
            break;
        }
    }
    return 0;
}