#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<cpp_int> A(N);
    map<cpp_int, int> mp;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        mp[A[i]]++;
    }
    sort(A.begin(), A.end());
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            cpp_int z = A[i] * A[j];
            if (z > A.back()) break;
            if (mp.count(z)) {
                if (i == j) ans += mp[z];
                else ans += 2*mp[z];
            }
        }
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
