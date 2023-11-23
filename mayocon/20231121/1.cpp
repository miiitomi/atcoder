// https://atcoder.jp/contests/abc067/tasks/abc067_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> l(N);
    for (int i = 0; i < N; i++) cin >> l[i];
    sort(l.begin(), l.end());
    int ans = 0;
    while (K--) {
        ans += l.back();
        l.pop_back();
    }
    cout << ans << endl;
}
