// https://atcoder.jp/contests/abc326/tasks/abc326_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
string R, C;

bool check(vector<string> &S) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == '.') continue;
            else if (S[i][j] == R[i]) break;
            else return false;
        }
    }
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (S[i][j] == '.') continue;
            else if (S[i][j] == C[j]) break;
            else return false;
        }
    }
    return true;
}

void solve() {
    cin >> N >> R >> C;
    vector<ll> a(N), b(N), c(N);
    for (int i = 0; i < N; i++) {
        a[i] = i; b[i] = i; c[i] = i;
    }
    do {
        do {
            do {
                vector<string> S(N, string(N, '.'));
                bool is_ok = true;
                for (int i = 0; i < N; i++) {
                    if (S[i][a[i]] != '.') is_ok = false;
                    S[i][a[i]] = 'A';
                    if (S[i][b[i]] != '.') is_ok = false;
                    S[i][b[i]] = 'B';
                    if (S[i][c[i]] != '.') is_ok = false;
                    S[i][c[i]] = 'C';
                }
                if (!is_ok) continue;
                if (check(S)) {
                    cout << "Yes\n";
                    for (string s : S) cout << s << "\n";
                    return;
                }
            } while (next_permutation(c.begin(), c.end()));
        } while (next_permutation(b.begin(), b.end()));
    } while (next_permutation(a.begin(), a.end()));

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
