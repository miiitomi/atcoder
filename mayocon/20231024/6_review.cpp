// https://atcoder.jp/contests/abc231/tasks/abc231_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<ll> A;
map<pair<int, ll>, ll> M;

ll rec(int i, ll X) {
    if (M.count(make_pair(i, X))) return M[make_pair(i, X)];

    ll Y = X;
    ll ans = X / A[i];
    X -= (X / A[i]) * A[i];
    if (X != 0) {
        ans += min(rec(i+1, X), 1 + rec(i+1, -(X - A[i])));
    }
    M[make_pair(i, Y)] = ans;
    return ans;
}

int main() {
    ll X;
    cin >> N >> X;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    reverse(A.begin(), A.end());

    cout << rec(0, X) << endl;
}
