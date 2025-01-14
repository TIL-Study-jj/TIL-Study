#include <iostream>
#include <vector>
using namespace std;
int main(){
    int num;
    cin >> num;
    int cntmax = 0;
    int cnt;
    
    int firstrealnum; 
    int firstvariable; 
    int secondrealnum; 
    int secondvariable; // actually, i dont like long variable name. but i just use it sometimes. i don't know why.
    int swapnum;
    vector<int> vecmax;
    for(int i =1; i <= num; i++){
        
        cnt = 2;
        
        firstrealnum = 0;
        firstvariable = i;
        secondrealnum = num;
        secondvariable = -i;
        vector<int> vec;
        
        vec.push_back(num);
        vec.push_back(i);
        
        while(true){
            if ((secondrealnum + secondvariable) < 0){
                break;
            }
            else{ // using swap? << nice try zz
                vec.push_back(secondrealnum + secondvariable);
                swapnum = secondrealnum;
                secondrealnum = firstrealnum - secondrealnum;
                firstrealnum = swapnum;
                
                swapnum = secondvariable;
                secondvariable = firstvariable - secondvariable;
                firstvariable = swapnum;
                cnt += 1;
            }
        }
        if (cntmax < cnt){
            vecmax = vec; // save vector to another vector : damn, it works! 
            cntmax = cnt;
        }
        
    }
    cout << cntmax << endl;
    for(int i = 0; i < cntmax; i++){
        cout << vecmax[i] << " ";
    }
}