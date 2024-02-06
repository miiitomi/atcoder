// https://atcoder.jp/contests/abc180/tasks/abc180_d
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

void solve() {
    cpp_int X, Y, A, B;
    cin >> X >> Y >> A >> B;
    cpp_int ans = 0;

    while ((A-1)*X <= B) {
        X *= A;
        ans++;
        if (X >= Y) {
            X /= A;
            ans--;
            break;
        }
    }

    cpp_int r = Y - X;
    ans += (r - 1) / B;
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
