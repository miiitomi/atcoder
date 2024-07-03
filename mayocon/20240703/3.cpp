// https://atcoder.jp/contests/abc268/tasks/abc268_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> cnt(N, 0);
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        int tmp = (N+p-i)%N;
        cnt[(tmp-1+N)%N]++;
        cnt[tmp]++;
        cnt[(tmp+1)%N]++;
    }
    cout << *max_element(cnt.begin(), cnt.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
