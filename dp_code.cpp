#include <iostream>
using namespace std;

int fib(int n, vector<int> &dp){
    if(n<=1){
        return n;
    }

    if(n != -1){
        return dp[n];
    }

    dp[n] = fib(n-1, dp) + fib(n-2, dp);

}

int main(){
    int n;
    vector<int> dp(n, -1);
    cin>>n;

    if(n<0){
        cout<<"not possible";
    }

    cout<< fib(n-1, dp)<<endl;
}

// 0 1 1 2 3 5