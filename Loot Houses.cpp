#include <iostream>
using namespace std;

int getMaxMoney(int arr[], int n){
    if(n==1) return arr[0];
    if(n==0) return 0;
    return max(getMaxMoney(arr+1,n-1),arr[0]+getMaxMoney(arr+2,n-2));
}

int getMaxMoneyDP(int arr[], int n){
    int* dp = new int[n+1];
    dp[0] = 0;
    dp[1] = arr[n-1];
    for(int i=2;i<=n;i++){
        dp[i] = max(dp[i-1],arr[n-i]+dp[i-2]);
    }
    delete[] dp;
    return dp[n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        cout << getMaxMoney(arr,n);
    }
}

