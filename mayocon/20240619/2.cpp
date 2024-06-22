// https://atcoder.jp/contests/abc278/tasks/abc278_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;

    vector<int> T(Q), A(Q), B(Q), v;
    for (int i = 0; i < Q; i++) {
        cin >> T[i] >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        v.push_back(A[i]);
        v.push_back(B[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < Q; i++) {
        A[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), A[i]));
        B[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), B[i]));
    }

    vector<set<int>> S(v.size());
    for (int i = 0; i < Q; i++) {
        int t = T[i], a = A[i], b = B[i];
        if (t == 1) {
            S[a].insert(b);
        } else if (t == 2) {
            if (S[a].count(b)) {
                S[a].erase(b);
            }
        } else {
            if (S[a].count(b) && S[b].count(a)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
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
