// https://atcoder.jp/contests/abc161/tasks/abc161_e
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;
    vector<int> left, right;
    int l = 0;
    while (l <= N-1) {
        if (S[l] == 'x') {
            l++;
            continue;
        }
        left.push_back(l);
        l += C+1;
    }
    int r = N-1;
    while (r >= 0) {
        if (S[r] == 'x') {
            r--;
            continue;
        }
        right.push_back(r);
        r -= C+1;
    }
    reverse(right.begin(), right.end());

    vector<int> ans;
    for (int i = 0; i <= N-1; i++) {
        if (S[i] == 'x') continue;
        int tmp = 0;
        auto iter = lower_bound(left.begin(), left.end(), i);
        int t = i+1;
        if (iter != left.begin()) {
            tmp += distance(left.begin(), iter);
            iter--;
            t = max(t, *iter + C+1);
        }
        auto iter2 = lower_bound(right.begin(), right.end(), t);
        tmp += distance(iter2, right.end());
        if (tmp < K) ans.push_back(i+1);
    }

    for (int x : ans) cout << x << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
