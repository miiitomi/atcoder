#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    int s = S.size(), t = T.size();
    while (N--) {
        int a;
        cin >> a;
        while (a % s != 0) {
            cout << T << " ";
            a -= t;
        }
        while (a > 0) {
            cout << S << " ";
            a -= s;
        }
        cout << "\n";
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
