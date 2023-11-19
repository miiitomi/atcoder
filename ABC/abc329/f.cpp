#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<unordered_set<int>> S(N);
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        S[i].insert(c);
    }
    vector<int> mp(N);
    for (int i = 0; i < N; i++) mp[i] = i;

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        if (S[mp[a]].size() >= S[mp[b]].size()) swap(mp[a], mp[b]);
        int ia = mp[a], ib = mp[b];
        for (int x : S[ia]) S[ib].insert(x);
        S[ia] = {};

        cout << S[ib].size() << endl;
    }
}
