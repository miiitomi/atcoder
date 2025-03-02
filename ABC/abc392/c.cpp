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
    vector<int> who_is_wearing_i(N+1), who_is_i_watching(N+1), which_number_i_is_wearing(N+1);
    for (int i = 1; i <= N; i++) {
        int p;
        cin >> p;
        who_is_i_watching[i] = p;
    }
    for (int i = 1; i <= N; i++) {
        int q;
        cin >> q;
        who_is_wearing_i[q] = i;
        which_number_i_is_wearing[i] = q;
    }

    for (int i = 1; i <= N; i++) {
        int who = who_is_wearing_i[i];
        int watched_person = who_is_i_watching[who];
        int s = which_number_i_is_wearing[watched_person];
        cout << s << " ";
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
