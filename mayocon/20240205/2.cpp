// https://atcoder.jp/contests/abc219/tasks/abc219_c
#include <bits/stdc++.h>
using namespace std;

string X;
int N;

bool cmp(const string &l, const string &r) {
    int N = min(l.size(), r.size());
    for (int i = 0; i < N; i++) {
        int a = X.find(l[i]), b = X.find(r[i]);
        if (a != b) return a < b;
    }
    return l.size() < r.size();
}

void solve() {
    cin >> X >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    sort(S.begin(), S.end(), cmp);
    for (string s : S) cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
