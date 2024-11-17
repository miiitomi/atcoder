#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

string L = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string s = "abcdefghijklmnopqrstuvwxyz";

void solve() {
    string S;
    cin >> S;
    ll N = S.size();
    ll Q;
    cin >> Q;
    while (Q--) {
        ll K;
        cin >> K;
        K--;

        if (K < N) {
            cout << S[K] << " ";
            continue;
        }

        ll M = S.size();
        while (2*M <= K) M *= 2;
        ll cnt = 0;
        while (K >= N) {
            if (K >= M) {
                cnt++;
                K -= M;
            }
            M /= 2;
        }
        if (cnt % 2 == 0) cout << S[K] << " ";
        else if ('a' <= S[K] && S[K] <= 'z') cout << L[(int)(S[K]-'a')] << " ";
        else cout << s[(int)(S[K] - 'A')] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
