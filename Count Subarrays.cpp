https://www.codechef.com/problems/SUBINC

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int* arr = new int[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        long long int sum = 0;
        long long int length=1;
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1]){
                length+=1;
            }else{
                sum+= length*(length+1)/2;
                length=1;
            }
        }
        sum += length*(length+1)/2;
        cout << sum << endl;
    }
}
