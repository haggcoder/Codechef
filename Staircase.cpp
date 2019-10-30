#include <climits>
#include <iostream>
using namespace std;

long staircase(int n){
    if(n==1||n==2){
        return n;
    }
    if(n==3){
        return 4;
    }
    long dp[n+1];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4;i<=n;i++){
        dp[i]= dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    while(n!=-1){
        cout << staircase(n) << endl;
        cin >> n;
    }
    return 0;
}
