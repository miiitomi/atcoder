// https://atcoder.jp/contests/abc210/tasks/abc210_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> c(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }

    queue<int> Q;
    map<int, int> mp;
    int i = 0;
    while (K--) {
        Q.push(c[i]);
        mp[c[i]]++;
        i++;
    }

    int ans = mp.size();
    for (; i < N; i++) {
        int x = Q.front();
        Q.pop();
        mp[x]--;
        if (mp[x] == 0) mp.erase(x);
        x = c[i];
        Q.push(x);
        mp[x]++;
        ans = max(ans, (int)mp.size());
    }

    cout << ans << endl;
}
