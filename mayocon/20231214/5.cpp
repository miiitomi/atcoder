// https://atcoder.jp/contests/abc176/tasks/abc176_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, M;
    cin >> H >> W >> M;
    vector<int> h(M), w(M);
    vector<pair<int,int>> v(W, {0, 0});
    vector<set<int>> s(H);
    for (int j = 0; j < W; j++) v[j].second = j;
    for (int i = 0; i < M; i++) {
        cin >> h[i] >> w[i];
        h[i]--;
        w[i]--;
        v[w[i]].first++;
        s[h[i]].insert(w[i]);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int ans = -1;
    for (int i = 0; i < H; i++) {
        int tmp = s[i].size();
        for (int j = 0; j < W; j++) {
            if (!s[i].count(v[j].second)) {
                ans = max(ans, tmp+v[j].first);
                break;
            } else {
                ans = max(ans, tmp+v[j].first - 1);
            }
        }
    }

    cout << ans << endl;
}
