#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int lcs(string str1, string str2){
    if(str1.size()==0 || str2.size()==0){
        return 0;
    }
    if(str1[0] == str2[0]){
        return 1+lcs(str1.substr(1),str2.substr(1));
    }
    int ans1 = lcs(str1,str2.substr(1));
    int ans2 = lcs(str1.substr(1),str2);
    return max(ans1,ans2);
}

int lcsDP(string str1, string str2){
    int m = (int)str1.size();
    int n = (int)str2.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){ dp[i][0] = 0; }
    for(int i=0;i<=n;i++){ dp[0][i] = 0; }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[m-i]==str2[n-j]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    //code
    int t;
    cin >> t;
    while(t--){
        string str1,str2;
        cin >> str1;
        cin >> str2;
        cout << lcsDP(str1,str2) << endl;
    }
    return 0;
}
