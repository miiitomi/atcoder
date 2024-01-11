// https://atcoder.jp/contests/abc234/tasks/abc234_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    priority_queue<int, vector<int>, greater<int>> Q;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (i < K) Q.push(x);
        else {
            int y = Q.top();
            Q.pop();
            Q.push(max(x, y));
        }

        if (i >= K-1) cout << Q.top() << "\n";
    }
}
