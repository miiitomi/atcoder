// https://atcoder.jp/contests/abc246/tasks/abc246_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353LL;
const string ABC = "abcdefghijklmnopqrstuvwxyz";

ll mod_pow(ll a, ll n) {
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res % MOD * a % MOD;
    else return res * res % MOD;
}

int main() {
    int N, L;
    cin >> N >> L;
    vector<set<char>> S(N);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (char c : s) S[i].insert(c);
    }

    ll ans = 0;
    for (int b = 1; b < (1 << N); b++) {
        set<char> C(ABC.begin(), ABC.end());
        int num_line = 0;
        for (int k = 0; k < N; k++) {
            if (!(b & (1 << k))) continue;
            num_line++;
            for (int c : ABC) if (C.count(c) && !S[k].count(c)) C.erase(c);
        }
        if (C.empty()) continue;
        ll num_strings = mod_pow((ll)C.size(), L);

        if (num_line % 2 == 1) ans = (ans + num_strings) % MOD;
        else ans = (ans - num_strings + MOD) % MOD;
    }

    cout << ans << endl;
}
