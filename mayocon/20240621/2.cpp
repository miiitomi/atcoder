// https://atcoder.jp/contests/abc294/tasks/abc294_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;
    priority_queue<int, vector<int>, greater<int>> PQ;
    for (int x = 1; x <= N; x++) PQ.push(x);
    set<int> S;
    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int x = PQ.top();
            PQ.pop();
            S.insert(x);
        } else if (k == 2) {
            int x;
            cin >> x;
            S.erase(x);
        } else {
            auto iter = S.begin();
            cout << *iter << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
