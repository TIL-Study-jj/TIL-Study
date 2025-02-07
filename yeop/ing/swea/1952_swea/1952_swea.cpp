#include <iostream>
using namespace std;
int ans;

void findcheapest(int CurrentMonth, int EndingMonth, int* tickets, int* monthly, int price){
    if(CurrentMonth == EndingMonth){
        if(price < ans){
            ans = price;
        }
        return;
    }
    if(monthly[CurrentMonth] == 0){
        findcheapest(CurrentMonth + 1, EndingMonth, tickets, monthly, price);
    }
    else{
        // 1 day use, 1 month use
        int month_1st = monthly[CurrentMonth];
        monthly[CurrentMonth] = 0;
        findcheapest(CurrentMonth + 1, EndingMonth, tickets, monthly, price + month_1st*tickets[0]);
        findcheapest(CurrentMonth + 1, EndingMonth, tickets, monthly, price + tickets[1]);
        
        // 2 month use, 3 month use : change all of monthly
        if(CurrentMonth <= 9){
            int month_2nd = monthly[CurrentMonth + 1];
            int month_3rd = monthly[CurrentMonth + 2];
            monthly[CurrentMonth + 1] = 0;
            monthly[CurrentMonth + 2] = 0;
            findcheapest(CurrentMonth + 1, EndingMonth, tickets, monthly, price + tickets[2]);
            findcheapest(CurrentMonth + 1, EndingMonth, tickets, monthly, price + tickets[3]);
            monthly[CurrentMonth + 1] = month_2nd;
            monthly[CurrentMonth + 2] = month_3rd;
        }
        // 2 month use, 3 month use : change only two monthly
        else if (CurrentMonth <= 10){
            int month_2nd = monthly[CurrentMonth + 1];
            monthly[CurrentMonth + 1] = 0;
            findcheapest(CurrentMonth + 1, EndingMonth, tickets, monthly, price + tickets[2]);
            findcheapest(CurrentMonth + 1, EndingMonth, tickets, monthly, price + tickets[3]);
            monthly[CurrentMonth + 1] = month_2nd;
        }
        // 2 month use, 3 month use, : but no change
        else{
            findcheapest(CurrentMonth + 1, EndingMonth, tickets, monthly, price + tickets[2]);
            findcheapest(CurrentMonth + 1, EndingMonth, tickets, monthly, price + tickets[3]);
        }
        monthly[CurrentMonth] = month_1st;
    }
}

int main(){
    int tc;
    cin >> tc;
    for(int i = 1; i <= tc; i++){
        
        int tickets[4] = {0};
        int ticket;
        for(int j = 0; j < 4; j++){
            cin >> ticket;
            tickets[j] = ticket;
        }
        
        int monthly[12] = {0};
        int month;
        for(int j = 0; j < 12; j++){
            cin >> month;
            monthly[j] = month;
        }
        ans = tickets[3];
        findcheapest(0, 12, tickets, monthly, 0);
        
        cout<<"#" << i << " " << ans <<"\n";    
    }
    

    return 0;
}