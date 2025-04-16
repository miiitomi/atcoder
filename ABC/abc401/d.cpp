#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<ll> min_dp(string S) {
    int N = S.size();
    vector<ll> dp(N, 0);
    for (int i = 0; i < N; i++) {
        if (i > 0) dp[i] = dp[i-1];
        if (S[i] == 'o') dp[i]++;
    }
    return dp;
}

vector<vector<ll>> make_dp(string S) {
    int N = S.size();
    vector<vector<ll>> dp(N, {-INF, -INF});
    if (S[0] == '.') dp[0] = {0, -INF};
    else if (S[0] == 'o') dp[0] = {-INF, 1};
    else dp[0] = {0, 1};
    for (int i = 1; i < N; i++) {
        if (S[i] != 'o') {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        }
        if (S[i] != '.') {
            dp[i][1] = dp[i-1][0] + 1;
        }
    }
    return dp;
}

void solve() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<ll> min_left = min_dp(S);
    vector<vector<ll>> dp_left = make_dp(S);
    reverse(S.begin(), S.end());
    vector<ll> min_right = min_dp(S);
    vector<vector<ll>> dp_right = make_dp(S);
    reverse(min_right.begin(), min_right.end());
    reverse(dp_right.begin(), dp_right.end());
    reverse(S.begin(), S.end());

    for (int i = 0; i < N; i++) {
        if (S[i] != '?') {
            cout << S[i];
            continue;
        }
        if ((i >= 1 && S[i-1]=='o') || (i+1 < N && S[i+1]=='o') || min_left.back() == K) {
            cout << '.';
            continue;
        }

        bool can_dot = true, can_o = true;
        can_dot = (dp_left[i][0] + dp_right[i][0] >= K);
        can_o = (dp_left[i][1] + dp_right[i][1] - 1 >= K);
        if (can_dot && can_o) cout << '?';
        else if (can_dot) cout << '.';
        else cout << 'o';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
