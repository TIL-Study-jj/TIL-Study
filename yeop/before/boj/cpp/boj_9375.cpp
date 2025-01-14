#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main(){
   int tc;
   scanf("%d", &tc);
   for(int i = 0; i < tc; i++){
        int cn;
        scanf("%d", &cn);
        map <string, int> fashion;
        for(int j = 0; j < cn; j++){
           char name[20];
           char where[20];
            scanf("%s %s", name, where);    
            fashion[where] += 1;
        }
        int t = 1;
        for(auto j = fashion.begin(); j != fashion.end(); j++){
            t *= (1 + j->second);
        }
        t--;
        printf("%d\n", t);
   }
}