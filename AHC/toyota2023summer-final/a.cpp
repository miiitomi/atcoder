#include <bits/stdc++.h>
using namespace std;

vector<int> Js{0,8,1,7,2,6,3,5,4}, di{0, 0, -1, 1}, dj{1, -1, 0, 0};

void dijkstra(vector<vector<int>> &G, vector<int> &d) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push(make_pair(0, 4));

    while (!Q.empty()) {
        int d_ = Q.top().first;
        int v = Q.top().second;
        Q.pop();
        if (d[v] < d_) continue;

        for (int p : G[v]) {
            if (d[v] + 1 < d[p]) {
                d[p] = d[v] + 1;
                pair<int, int> q = make_pair(d[p], p);
                Q.push(q);
            }
        }
    }
}


int main() {
    int D, N;
    cin >> D >> N;
    int M = D*D-1-N;
    vector<pair<int,int>> r(N);
    set<pair<int,int>> set_r;
    for (int i = 0; i < N; i++) {
        cin >> r[i].first >> r[i].second;
        set_r.insert(r[i]);
    }

    vector<vector<int>> G(D*D);
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < D; j++) {
            if (set_r.count(make_pair(i, j))) continue;
            int x = D*i + j;
            for (int k = 0; k < 4; k++) {
                int new_i = i + di[k], new_j = j + dj[k];
                if (!(0<=new_i && new_i<D && 0<= new_j && new_j < D)) continue;
                pair<int,int> new_x = make_pair(i+di[k], j+dj[k]);
                if (set_r.count(new_x)) continue;
                G[x].push_back(D*new_i + new_j);
            }
        }
    }

    vector<int> d(D*D, 1e+9);
    d[4] = 0;
    dijkstra(G, d);

    vector<pair<int,int>> sorted_d_x_pair;
    for (int i = 0; i < D*D; i++) {
        if (d[i] == (int)1e+9 || i == 4) continue;
        sorted_d_x_pair.push_back(make_pair(d[i], i));
    }
    sort(sorted_d_x_pair.begin(), sorted_d_x_pair.end());
    reverse(sorted_d_x_pair.begin(), sorted_d_x_pair.end());

    vector<int> T(D*D, -1);

    for (int i = 0; i < M; i++) {
        int t;
        cin >> t;
        int x = sorted_d_x_pair[i].second;
        cout << x / D << " " << x % D << endl;
        T[x] = t;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> P;
    set<int> set_open;
    vector<int> tmp{3,5,4+D};
    for (int i : tmp) {
        if (!set_r.count(make_pair(i /D, i %D))) {
            P.push(make_pair(T[i], i));
            set_open.insert(i);
        }
    }

    while (!P.empty()) {
        int x = P.top().second;
        P.pop();
        int i = x / D;
        int j = x % D;
        cout << i << " " << j << endl;
        for (int k = 0; k < 4; k++) {
            int new_i = i + di[k], new_j = j + dj[k];
            if (!(0<=new_i && new_i<D && 0<= new_j && new_j < D)) continue;
            if ((new_i == 0 && new_j == 4) || set_r.count(make_pair(new_i, new_j))) continue;
            int new_x = D*new_i + new_j;
            if (set_open.count(new_x)) continue;
            P.push(make_pair(T[new_x], new_x));
            set_open.insert(new_x);
        }
    }
}
