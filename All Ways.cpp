#include <iostream>
#include <cmath>
using namespace std;

int allWays(int x, int n, int start) {
    if(x==0){ return 1; }
    /* if x-pow(start,n) is < 0, then no need to make 2nd recursive call
    This is also a base case */
    if(x-pow(start,n)<0){ return 0; }
    int ans1 = allWays(x-pow(start,n),n,start+1);
    int ans2 = allWays(x,n,start+1);
    return ans1+ans2;
}
    
int allWays(int x, int n){
    return allWays(x,n,1);
}

int main(){
    int t;
    cin >> t ;
    while(t--){
        int x,n;
        cin >> x >> n;
        cout << allWays(x,n) << endl;
    }
}
