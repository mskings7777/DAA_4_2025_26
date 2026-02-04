#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < n; i++) {
        int score;
        cin >> score;

        if(minHeap.size() < k) {
            minHeap.push(score);
            if(minHeap.size() < k)
                cout << -1 << endl;
            else
                cout << minHeap.top() << endl;
        }
        else {
            if(score > minHeap.top()) {
                minHeap.pop();
                minHeap.push(score);
            }
            cout << minHeap.top() << endl;
        }
    }

    return 0;
}
