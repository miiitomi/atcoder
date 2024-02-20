// https://atcoder.jp/contests/abc300/tasks/abc300_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> is_prime(1e+6, true);
vector<ll> p;

void solve() {
    ll N, ans=0;
    cin >> N;
    for (int i = 0; p[i]*p[i]*p[i+1]*p[i+2]*p[i+2] <= N; i++) {
        for (int j = i+1; p[i]*p[i]*p[j]*p[j+1]*p[j+1] <= N; j++) {
            ll M = N / (p[i]*p[i]*p[j]);
            ll left = j+1, right = p.size();
            while (right - left > 1) {
                ll m = (left + right) / 2;
                if (p[m]*p[m] > M) right = m;
                else left = m;
            }
            ans += left - j;
        }
    }
    cout << ans << "\n";
}

int main() {
    for (int x = 2; x < 1e+6; x++) {
        if (is_prime[x]) {
            p.push_back(x);
            for (int y = 2*x; y < 1e+6; y += x) is_prime[y] = false;
        }
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
