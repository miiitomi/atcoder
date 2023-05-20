#include <bits/stdc++.h>
using namespace std;
int N, M;

void bfs(int v, vector<unordered_set<int>> &contained_set, vector<unordered_set<int>> &contained_vertex, vector<int> &d) {
    queue<int> q;
    q.push(v);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int s : contained_set[u]) {
            contained_vertex[s].erase(u);
            for (int t : contained_vertex[s]) {
                if (d[t] == (int)1e+9) {
                    d[t] = d[u] + 1;
                    q.push(t);
                }
                contained_set[t].erase(s);
            }
        }
    }
}

int main() {
    cin >> N >> M;

    vector<unordered_set<int>> contained_set(M);
    vector<unordered_set<int>> contained_vertex(N);

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        for (int s = 0; s < a; s++) {
            int x;
            cin >> x;
            x--;
            contained_set[x].insert(i);
            contained_vertex[i].insert(x);
        }
    }

    vector<int> d(M, (int)1e+9);
    d[0] = -1;

    bfs(0, contained_set, contained_vertex, d);

    if (d[M-1] == (int)1e+9) {
        cout << -1 << endl;
    } else {
        cout << d[M-1] << endl;
    }
}
