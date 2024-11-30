#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int N;

int f(vector<int> &B) {
    vector<int> cnt(N, 0);
    int r = 0;
    int ans = 0;
    for (int l = 0; l < (int)B.size(); l++) {
        if (B[l] == -1) continue;
        r = max(r, l);
        while (r < (int)B.size() && B[r] != -1 && cnt[B[r]] == 0) {
            cnt[B[r]]++;
            r++;
        }
        ans = max(ans, r-l);
        cnt[B[l]]--;
    }
    return 2*ans;
}

void solve() {
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<int> B, C;
    for (int i = 0; i+1 < N; i++) {
        if (i % 2 == 0) {
            if (A[i] == A[i+1]) B.push_back(A[i]);
            else B.push_back(-1);
        } else {
            if (A[i] == A[i+1]) C.push_back(A[i]);
            else C.push_back(-1);
        }
    }
    int ans = max(f(B), f(C));
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
