#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int N = 1e+5;
vector<ull> V(N+1, 0);
vector<ull> S(N+1, 0);

ull sqrt(ull x) {
    ull left = 0;
    ull right = 4e+9;
    while (right - left > 1) {
        ull mid = (left + right) / 2;
        if (mid * mid > x) right = mid;
        else left = mid;
    }
    return left;
}

void solve() {
    ull X;
    cin >> X;
    ull Y = sqrt(X);
    ull Z = sqrt(Y);
    ull ans = 0;
    for (ull z = 1; z <= Z; z++) {
        ans += (Y - z*z + 1) * V[z];
    }
    cout << ans << endl;
}

int main() {
    V[1] = 1;
    S[1] = 1;
    for (ull x = 2; x <= N; x++) {
        ull y = sqrt(x);
        V[x] = S[y];
        S[x] = V[x] + S[x-1];
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
}
