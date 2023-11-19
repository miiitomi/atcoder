#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<set<int>> S(N+1);
    for (int i = 1; i <= N; i++) {
        int c;
        cin >> c;
        S[i].insert(c);
    }

    while (Q--) {
        int a, b;
        cin >> a >> b;
        if (S[a].size() > S[b].size()) swap(S[a], S[b]);
        S[b].merge(S[a]);
        S[a].clear();
        cout << S[b].size() << endl;
    }
}
