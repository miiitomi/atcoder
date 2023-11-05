#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    unordered_map<int,int> mp;
    queue<int> Q;
    int ans = -1;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        mp[a[i]]++;
        if (mp[a[i]] == 1) cnt++;
        Q.push(i);

        while (cnt > K) {
            int j = Q.front();
            Q.pop();
            mp[a[j]]--;
            if (mp[a[j]] == 0) cnt--;
        }

        ans = max(ans, (int)Q.size());
    }

    cout << ans << endl;
}
