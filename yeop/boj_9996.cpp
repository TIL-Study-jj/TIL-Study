#include <iostream>
#include <string>
using namespace std;

int main() {
    int files;
    cin >> files;
    string st;
    cin >> st;
    string sst;
    bool dane;
    for(int i = 0; i < files; i++){
        cin >> sst;
        dane = true;
        if(st.size() > sst.size() + 1){
            cout << "NE" << endl;
        }
        else{
            for(int j = 0; j < st.size(); j++){
                if (st[j] == '*'){
                    break;
                }
                else if(st[j] != sst[j]){
                    dane = false;
                    break;
                }
            }
            for(int j = 0; j < st.size(); j++){
                if (st[st.size() - j - 1] == '*'){
                    break;
                }
                else if(st[st.size() - j - 1] != sst[sst.size() - j - 1]){
                    dane = false;
                    break;
                }
            }
            if (dane){
                cout << "DA" << endl;
            }
            else{
                cout << "NE" << endl;
            }   
        }
    }
}
