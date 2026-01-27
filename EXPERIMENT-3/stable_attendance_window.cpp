#include <bits/stdc++.h>
using namespace std;

int main() {

    unordered_map<int, int> mp;
    mp[0] = -1;
    int sum = 0, ans = 0;
    int n;
    cin >> n;
    
    vector<char> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 'P')
            sum++;
        else
            sum--;

        if (mp.find(sum) != mp.end()) {
            ans = max(ans, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }

    cout<<ans<<endl;
    return 0;
}
