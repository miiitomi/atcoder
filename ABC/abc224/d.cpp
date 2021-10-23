#include <bits/stdc++.h>
using namespace std;

int main() {
    int M;
    cin >> M;
    vector<vector<int>> G(9);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    string p;
    for (int i = 0; i < 8; i++) {
        int x;
        cin >> x;
        x--;
        p = p + to_string(x);
    }

    if (p == "01234567") {
        cout << 0 << endl;
        return 0;
    }

    set<string> S, S_old, S_new;
    S.insert(p);
    S_old.insert(p);

    string x = "012345678";
    int counter = 1;
    while (true) {
        for (string q : S_old) {
            int e = 0;
            for (int i = 0; i <= 8; i++) {
                if (q.find(x[i]) == string::npos) {
                    e = i;
                    break;
                }
            }
            for (int v : G[e]) {
                string n = q;
                int f = n.find(to_string(v));
                n[f] = x[e];
                if (!S.count(n)) {
                    S.insert(n);
                    S_new.insert(n);
                }
            }
        }
        if (S_new.count("01234567")) {
            cout << counter << endl;
            return 0;
        } else if (S_new.empty()) {
            cout << -1 << endl;
            return 0;
        } else {
            S_old = S_new;
            S_new.clear();
            counter++;
        }
    }
}
