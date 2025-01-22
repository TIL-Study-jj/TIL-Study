#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;

    int inputnum1, inputnum2, inputnum3;
    int largeinputnum1, largeinputnum2, largeinputnum3;
    int smallinputnum1, smallinputnum2, smallinputnum3;
    
    int smallnum1 = 0;
    int smallnum2 = 0;
    int smallnum3 = 0;

    int largenum1 = 0;
    int largenum2 = 0;
    int largenum3 = 0;

    for(int i = 0; i < n; i++){
        cin >> inputnum1 >> inputnum2 >> inputnum3;
        
        largeinputnum1 = inputnum1;
        largeinputnum2 = inputnum2;
        largeinputnum3 = inputnum3;

        smallinputnum1 = inputnum1;
        smallinputnum2 = inputnum2;
        smallinputnum3 = inputnum3;
        
        if(i == 0){
            largenum1 = largeinputnum1;
            largenum2 = largeinputnum2;
            largenum3 = largeinputnum3;
    
            smallnum1 = smallinputnum1;
            smallnum2 = smallinputnum2;
            smallnum3 = smallinputnum3;
        }
        else{
            // get small first (larget= first doesn't matter)
            if(smallnum1 >= smallnum2){
                smallinputnum1 += smallnum2;
            }
            else{
                smallinputnum1 += smallnum1;
            }
            
            if(smallnum1 <= smallnum2 && smallnum1 <= smallnum3){
                smallinputnum2 += smallnum1;
            }
            else if(smallnum3 <= smallnum1 && smallnum3 <= smallnum2){
                smallinputnum2 += smallnum3;
            }
            else{
                smallinputnum2 += smallnum2;
            }
            
            if(smallnum2 >= smallnum3){
                smallinputnum3 += smallnum3;
            }
            else{
                smallinputnum3 += smallnum2;
            }
            // now get the large
            
            if(largenum1 > largenum2){
                largeinputnum1 += largenum1;
            }
            else{
                largeinputnum1 += largenum2;
            }
            
            if(largenum2 >= largenum1 && largenum2 >= largenum3){
                largeinputnum2 += largenum2;
            }
            else{
                if(largenum1 >= largenum3){
                    largeinputnum2 += largenum1;
                }
                else{
                    largeinputnum2 += largenum3;
                }
            }
            
            if(largenum2 >= largenum3){
                largeinputnum3 += largenum2;
            }
            else{
                largeinputnum3 += largenum3;
            }

            // finally, change the value
            smallnum1 = smallinputnum1;
            smallnum2 = smallinputnum2;
            smallnum3 = smallinputnum3;
            largenum1 = largeinputnum1;
            largenum2 = largeinputnum2;
            largenum3 = largeinputnum3;
        }
    }
    if(largenum1 >= largenum2 && largenum1 >= largenum3){
        cout << largenum1;
    }
    else if(largenum2 >= largenum1 && largenum2 >= largenum3){
        cout << largenum2;
    }
    else{
        cout << largenum3;
    }

    cout << " ";
    
    if(smallnum1 <= smallnum2 && smallnum1 <= smallnum3){
        cout << smallnum1;
    }
    else if(smallnum2 <= smallnum1 && smallnum2 <= smallnum3){
        cout << smallnum2;
    }
    else{
        cout << smallnum3;
    }
}