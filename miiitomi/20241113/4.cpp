// https://atcoder.jp/contests/abc268/tasks/abc268_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<vector<int>> V;
void f(vector<int> v, int i, int sum, int m) {
    if (i == (int)v.size()) {
        V.push_back(v);
        return;
    }
    f(v, i+1, sum, m);
    while (sum < m) {
        v[i]++;
        sum++;
        f(v, i+1, sum, m);
    }
}

void solve() {
    ll N, M, sum = 0;
    cin >> N >> M;
    vector<string> S(N);
    for (string &s : S) {
        cin >> s;
        sum += s.size();
    }
    sort(S.begin(), S.end());
    set<string> T;
    for (int i = 0; i < M; i++) {
        string t;
        cin >> t;
        T.insert(t);
    }

    if (N == 1) {
        if ((int)S[0].size() <= 2 || T.contains(S[0])) cout << -1 << endl;
        else cout << S[0] << endl;
        return;
    }

    sum += N-1;

    vector<int> v(N-1, 1);
    f(v, 0, sum, 16);
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());

    do {
        for (auto &w : V) {
            string X = "";
            for (int i = 0; i < N; i++) {
                X += S[i];
                if (i < N-1) X += string(w[i], '_');
            }
            if (!T.contains(X)) {
                cout << X << endl;
                return;
            }
        }
    } while (next_permutation(S.begin(), S.end()));

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
