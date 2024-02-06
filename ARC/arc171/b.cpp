#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<vector<int>> V(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        V[A[i]].push_back(i);
        if (A[i] < i) {
            cout << "0\n";
            return;
        }
    }
    vector<int> S, T;
    for (int i = 0; i < N; i++) {
        if (V[i].empty()) continue;
        S.push_back(V[i][0]);
        T.push_back(V[i].back());
        if (V[i].back() != i) {
            cout << "0\n";
            return;
        }
    }
    sort(S.begin(), S.end());
    sort(T.begin(), T.end());
    ll ans = 1, c = 0;
    int j = 0;
    for (int i = 0; i < (int)T.size(); i++) {
        while (j < (int)S.size() && S[j] <= T[i]) {
            c++;
            j++;
        }
        ans = (ans * c) % MOD;
        c--;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
