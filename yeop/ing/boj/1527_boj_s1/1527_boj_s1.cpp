#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    long long n1, n2;
    cin >> n1 >> n2;
    // n2의 자릿수까지의 금민수들을 모두 뽑고, 범위 내에 해당하는 것만 출력한다.
    int n2size = to_string(n2).size();
    vector<string> kms = {"4", "7"};
    int curmaxkms = 1;
    while(n2size > curmaxkms){
        int ckmssize = kms.size();
        for(int i = 0; i < ckmssize; i++){
            if(kms[i].size() == curmaxkms){
                string subst1 = kms[i] + "4";
                string subst2 = kms[i] + "7";
                kms.push_back(subst1);
                kms.push_back(subst2);
            }
        }
        curmaxkms++;
    }
    int cnt = 0;
    for(int i = 0; i < kms.size(); i++){
        if(n1 <= stoll(kms[i]) && stoll(kms[i]) <= n2){
            cnt++;
        }
    }
    cout << cnt;
}
