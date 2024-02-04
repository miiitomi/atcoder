#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> mods;

void solve() {
    int N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(20, 0));
    vector<map<ll, ll>> mp(20);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        for (int j = 0; j < 20; j++) {
            ll b = 1;
            for (char c : s) {
                A[i][j] = (A[i][j] + (c - '0') * b) % mods[j];
                b = (b * 10) % mods[j];
            }
            mp[j][A[i][j]]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ll tmp = 1e+18;
            for (int h = 0; h < 20; h++) {
                ll z = A[i][h] * A[j][h] % mods[h];
                if (mp[h].count(z)) tmp = min(tmp, mp[h][z]);
                else {
                    tmp = 0;
                    break;
                }
            }
            ans += tmp;
        }
    }
    cout << ans << endl;
}

void pre() {
    mt19937_64 engine(random_device{}());
    uniform_int_distribution<> dist((int)1e+9, (int)2e+9);
    set<ll> S;
    while (S.size() < 20) {
        int x = dist(engine);
        bool is_prime = true;
        for (ll y = 2; y * y <= x; y++) {
            if (x % y == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) S.insert(x);
    }
    for (ll s : S) mods.push_back(s);
}

int main() {
    pre();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
