// https://atcoder.jp/contests/abc122/tasks/abc122_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (ll)(1e+9) + 7LL;

vector<string> S{"AGC", "ACG", "GAC"};
string ACGT = "ACGT";

void solve() {
    ll N;
    cin >> N;
    map<string, ll> mp;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                string s = "";
                s.push_back(ACGT[i]);
                s.push_back(ACGT[j]);
                s.push_back(ACGT[k]);
                mp[s] = 1;
            }
        }
    }

    for (string t : S) mp[t] = 0;
    N -= 3;

    while (N--) {
        map<string,ll> mp_new;
        for (auto iter = mp.begin(); iter != mp.end(); iter++) {
            string s = iter->first;
            string t = "";
            t.push_back(s[1]);
            t.push_back(s[2]);
            for (int k = 0; k < 4; k++) {
                if (s[0] == 'A' && (s[1] == 'G' || s[2] == 'G') && k == 1) continue;
                char c = ACGT[k];
                t.push_back(c);
                mp_new[t] = (mp_new[t] + mp[s]) % MOD;
                t.pop_back();
            }
        }
        for (string t : S) mp_new[t] = 0;
        swap(mp, mp_new);
    }

    ll ans = 0;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        ans = (ans + (iter->second)) % MOD;
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
