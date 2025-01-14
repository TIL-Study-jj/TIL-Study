#include <iostream>
using namespace std;
int main(){
int tc;
cin >> tc;
double p, q;
double s1, s2;
for(int i = 1; i < tc + 1; i++){
cin >> p >> q;
s1 = (1-p)*(q);
s2 = (p)*(1-q)*(q);

if(s1 < s2){
cout << "#" << i << " " << "YES" << endl;
}
else{
cout << "#" << i << " " << "NO" << endl;
}
}
}