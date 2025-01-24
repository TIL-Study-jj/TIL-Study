#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int main(){
    int iter;
    int n, m;
    int num;
    cin >> iter;
    for(int i  = 0; i < iter; i++){
        cin >> n >> m;
        vector<int> vec1;
        for(int j = 0; j < n; j++){
            cin >> num;
            vec1.push_back(num);
        }
        vector<int> vec2;
        for(int j =0; j < m; j++){
            cin >> num;
            vec2.push_back(num);
        }
        int Mnum = 0;
        if (n <= m){
            for(int j = 0; j < m - n + 1; j++){
                int Cnum = 0;
                for(int k = 0; k < n; k++){
                    Cnum += vec1[k]*vec2[k+j];
                }
                if (Mnum < Cnum){
                    Mnum = Cnum;
                }
            }
        }
        else{
            for(int j = 0; j < n - m + 1; j++){
                int Cnum = 0;
                for(int k = 0; k < m; k++){
                    Cnum += vec1[k+j]*vec2[k];
                }
                if (Mnum < Cnum){
                    Mnum = Cnum;
                }
            }
        }
        cout << "#" << i + 1 << " "<< Mnum << endl;
    }
}