// https://atcoder.jp/contests/abc082/tasks/arc087_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<bool> f(vector<int> &X) {
    int sum = 0;
    for (auto x : X) sum += x;
    vector<vector<bool>> dp(X.size()+1, vector<bool>(2*sum+1, false));
    dp[0][sum] = true;
    for (int i = 0; i < (int)X.size(); i++) {
        int x = X[i];
        for (int j = 0; j <= 2*sum; j++) {
            if (!dp[i][j]) continue;
            if (j-x >= 0) dp[i+1][j-x] = true;
            if (j+x <= 2*sum) dp[i+1][j+x] = true;
        }
    }
    return dp.back();
}

void solve() {
    string S;
    int x, y;
    cin >> S >> x >> y;
    reverse(S.begin(), S.end());
    while (!S.empty() && S.back() == 'F') {
        S.pop_back();
        x--;
    }
    reverse(S.begin(), S.end());
    vector<pair<char,int>> V;
    for (char c : S) {
        if (V.empty() || V.back().first != c) V.push_back({c, 1});
        else V.back().second++;
    }
    vector<int> X, Y;
    int k = 0;
    for (auto &v : V) {
        if (v.first == 'F') {
            if (k & 1) Y.push_back(v.second);
            else X.push_back(v.second);
        } else {
            k += v.second;
        }
    }
    
    bool ok = true;
    vector<bool> v = f(X);
    int sum = (v.size() - 1) / 2;
    if (!(0 <= sum + x && sum + x <= 2*sum) || !v[sum + x]) ok = false;
    v = f(Y);
    sum = (v.size() - 1) / 2;
    if (!(0 <= sum + y && sum + y <= 2*sum) || !v[sum + y]) ok = false;

    if (ok) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
