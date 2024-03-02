#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> cnt(1 + *max_element(A.begin(), A.end()), 0);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int a = A[i];
        vector<int> v;
        for (int x = 2; x * x <= a; x++) {
            while (a % x == 0) {
                v.push_back(x);
                a /= x;
            }
        }
        if (a > 1) v.push_back(a);

        sort(v.begin(), v.end());
        int y = 1;
        if (a == 0) y = 0;
        else {
            while (!v.empty()) {
                if (v.size() >= 2 && v[v.size()-1] == v[v.size()-2]) {
                    v.pop_back();
                    v.pop_back();
                } else {
                    y *= v.back();
                    v.pop_back();
                }
            }
        }

        if (y != 0) {
            ans += cnt[0];
            ans += cnt[y];
        } else {
            ans += i;
        }

        cnt[y]++;
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
