// https://atcoder.jp/contests/abc235/tasks/abc235_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    map<int, vector<int>> mp;
    for (int i = 0; i < N; i++) mp[a[i]].push_back(i);

    for (int i = 0; i < Q; i++) {
        int x, k;
        cin >> x >> k;
        k--;
        if (k < mp[x].size()) cout << mp[x][k] + 1 << endl;
        else cout << -1 << endl;
    }
}
