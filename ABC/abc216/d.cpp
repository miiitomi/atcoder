#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> k(M);
    vector<queue<int>> a(M);
    for (int i = 0; i < M; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            int x;
            cin >> x;
            a[i].push(x);
        }
    }

    map<int, int> top;
    set<int> Se;
    stack<pair<int, int>> St;
    int cnt = 0;

    for (int i = 0; i < M; i++) {
        int v = a[i].front();
        if (Se.count(v)) {
            St.push(make_pair(i, top[v]));
        } else {
            Se.insert(v);
            top[v] = i;
        }

        while (!St.empty()) {
            pair<int, int> p = St.top();
            St.pop();
            int v = a[p.first].front();
            a[p.first].pop();
            a[p.second].pop();
            Se.erase(v);
            cnt++;
            top.erase(v);

            if (!a[p.first].empty() && !a[p.second].empty() && a[p.first].front() == a[p.second].front()) {
                Se.insert(a[p.first].front());
                St.push(make_pair(p.first, p.second));
                continue;
            }

            if (!a[p.first].empty()) {
                if (Se.count(a[p.first].front())) {
                    St.push(make_pair(p.first, top[a[p.first].front()]));
                } else {
                    Se.insert(a[p.first].front());
                    top[a[p.first].front()] = p.first;
                }
            }

            if (!a[p.second].empty()) {
                if (Se.count(a[p.second].front())) {
                    St.push(make_pair(p.second, top[a[p.second].front()]));
                } else {
                    Se.insert(a[p.second].front());
                    top[a[p.second].front()] = p.second;
                }
            }
        }
    }

    if (cnt == N) cout << "Yes" << endl;
    else cout << "No" << endl;
}
