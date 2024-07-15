#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

string S;
vector<int> sa;

int bisect(string &T, int left, int right) {
    int M = T.size(), N = S.size();
    while (right - left > 1) {
        int mid = (left+right)/2;
        int i = sa[mid];
        bool substr_is_weakly_larger_than_t, done = false;
        int R = min(M, N-i);
        for (int k = 0; k < R; k++) {
            if (S[i+k] > T[k]) {
                substr_is_weakly_larger_than_t = true;
                done = true;
                break;
            } else if (S[i+k] < T[k]) {
                substr_is_weakly_larger_than_t = false;
                done = true;
                break;
            }
        }
        if (!done) {
            if (M <= N-i) substr_is_weakly_larger_than_t = true;
            else substr_is_weakly_larger_than_t = false;
        }
        if (substr_is_weakly_larger_than_t) right = mid;
        else left = mid;
    }
    return right;
}

void solve() {
    cin >> S;
    sa = suffix_array(S);
    int N = S.size();
    int Q;
    cin >> Q;
    while (Q--) {
        string T;
        cin >> T;
        int l = bisect(T, -1, N);
        T.push_back('~');
        int r = bisect(T, l-1, N);
        cout << r-l << "\n";
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
