// https://atcoder.jp/contests/abc155/tasks/abc155_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }

    int m = -1;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        m = max(m, iter->second);
    }

    vector<string> v;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        if (iter->second == m) {
            v.push_back(iter->first);
        }
    }

    sort(v.begin(), v.end());

    for (string s : v) cout << s << endl;
}
