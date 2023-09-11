// https://atcoder.jp/contests/abc145/tasks/abc145_d
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;

vector<mint> factorial;

mint C(int n, int r) {
    return factorial[n] / (factorial[n-r] * factorial[r]);
}

int main() {
    factorial.assign(1e+7+1, 1);
    for (int i = 1; i <= (int)1e+7; i++) factorial[i] = i * factorial[i-1];

    ll X, Y;
    cin >> X >> Y;

    if (2*X - Y < 0 || 2*Y- X < 0 || (2*X - Y) % 3 != 0 || (2*Y - X) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    ll a = (2*Y - X) / 3, b = (2*X - Y) / 3;

    cout << C(a+b, b).val() << endl;
}
