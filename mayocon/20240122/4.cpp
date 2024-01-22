// https://atcoder.jp/contests/abc084/tasks/abc084_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> v;
    vector<bool> is_prime(1e+6, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int x = 2; x < 1e+6; x++) {
        if (is_prime[x]) {
            for (int y = 2*x; y < 1e+6; y += x) is_prime[y] = false;
            if (x > 2 && is_prime[(x+1)/2]) v.push_back(x);
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << distance(lower_bound(v.begin(), v.end(), l), lower_bound(v.begin(), v.end(), r+1)) << "\n";
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
