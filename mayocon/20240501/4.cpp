// https://atcoder.jp/contests/abc330/tasks/abc330_e
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;
    set<int> S;
    for (int k = 0; k <= N+1; k++) S.insert(k);
    vector<int> A(N);
    unordered_map<int,int> mp;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        mp[A[i]]++;
        if (mp[A[i]] == 1) S.erase(A[i]);
    }

    while (Q--) {
        int i, x;
        cin >> i >> x;
        i--;
        int a = A[i];
        mp[a]--;
        if (mp[a] == 0) S.insert(a);
        A[i] = x;
        mp[x]++;
        if (mp[x] == 1) S.erase(x);
        cout << *S.begin() << "\n";
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
