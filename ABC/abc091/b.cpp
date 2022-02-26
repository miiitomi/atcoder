#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> mp;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        mp[s]--;
    }

    int ans = 0;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        ans = max(ans, iter->second);
    }

    cout << ans << endl;
}
