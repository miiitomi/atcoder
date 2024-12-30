#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    if (N <= 2) {
        int ans = -1;
        for (int i = 1; i <= N; i++) {
            cout << "? " << i << endl;
            int tmp;
            cin >> tmp;
            ans = max(ans, tmp);
        }
        cout << "! " << ans << endl;
        return;
    }
    vector<int> v(2, 1);
    while (v.back() <= N) {
        v.push_back(v[v.size()-2]+v[v.size()-1]);
    }
    vector<int> A(N, 0);
    while ((int)A.size() < v.back()) A.push_back(A.back()-1);
    N = v.back();
    v.pop_back();
    int s = 0;
    while (N > 2) {
        int l = v[v.size()-2], r = v[v.size()-1];
        if (A[s+l-1] == 0) {
            cout << "? " << s+l << endl;
            cin >> A[s+l-1];
        }
        if (A[s+r-1] == 0) {
            cout << "? " << s+r << endl;
            cin >> A[s+r-1];
        }
        if (A[s+l-1] < A[s+r-1]) s = s+l;
        N = v.back();
        v.pop_back();
    }
    cout << "! " << max(A[s], A[s+1]) << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
