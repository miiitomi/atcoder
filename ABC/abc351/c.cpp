#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> B;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        B.push_back(a);
        while (B.size() >= 2 && B[(int)B.size()-1] == B[(int)B.size()-2]) {
            B.pop_back();
            B.back()++;
        }
    }
    cout << B.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
