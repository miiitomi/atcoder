// https://atcoder.jp/contests/abc350/tasks/abc350_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), pos(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        pos[A[i]] = i;
    }
    vector<pair<int,int>> ans;
    for (int i = 0; i < N; i++) {
        if (A[i] == i) continue;
        int j = pos[i];
        ans.push_back(make_pair(i, j));
        swap(A[i], A[j]);
        swap(pos[A[i]], pos[A[j]]);
    }

    cout << ans.size() << endl;
    for (auto p : ans) cout << p.first+1 << " " << p.second+1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
