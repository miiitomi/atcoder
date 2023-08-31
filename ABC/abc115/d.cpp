#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll rec(int N, ll X, vector<ll> &paties, vector<ll> &alls) {
    if (X == 1) {
        if (N == 0) return 1;
        else return 0;
    }
    if (X == 2 + alls[N-1]) return paties[N-1] + 1;
    if (X >= alls[N]) return 2*paties[N-1] + 1;
    if (X <= 1+alls[N-1]) return rec(N-1, X-1, paties, alls);
    X -= 2+alls[N-1];
    return paties[N-1] + 1LL + rec(N-1, X, paties, alls);
}

int main() {
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> paties(1+N, 0), alls(1+N, 0);
    paties[0] = 1;
    alls[0] = 1;
    for (int i = 1; i <= N; i++) {
        paties[i] = 2LL*paties[i-1] + 1LL;
        alls[i] = 2LL*alls[i-1] + 3LL;
    }

    ll ans = 0;
    ans = rec(N, X, paties, alls);
    cout << ans << endl;
}
