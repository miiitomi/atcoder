#include <bits/stdc++.h>
using namespace std;

int D, N;
set<pair<int,int>> set_r;
set<int> set_T;
vector<int> T;
vector<int> Js{0,8,1,7,2,6,3,5,4}, di{0, 0, -1, 1}, dj{1, -1, 0, 0};

void dfs(vector<vector<int>> &G, vector<bool> &reached, int x, int v) {
    if (v == x || T[v] != -1) return;
    int i = v / D, j = v % D;
    for (int k = 0; k < 4; k++) {
        int new_i = i + di[k], new_j = j + dj[k], new_v = D*new_i + new_j;
        if (!(0<=new_i && new_i < D && 0<=new_j && new_j<D) || set_r.count(make_pair(new_i, new_j))) continue;
        if (reached[new_v]) continue;
        reached[new_v] = true;
        dfs(G, reached, x, new_v);
    }
}

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
    cin >> D >> N;
    int M = D*D-1-N;
    vector<pair<int,int>> r(N);
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

    T.assign(D*D, -1);

    for (int i = 0; i < M; i++) {
        int t;
        cin >> t;

        vector<int> ts;
        for (int l = 0; l < M; l++) if (!set_T.count(l)) ts.push_back(l);
        int tt;
        for (int l = 0; l < (int)ts.size(); l++) if (ts[l] == t) tt = l;


        vector<pair<pair<int,int>, pair<int,int>>> PQ;
        for (int x = 0; x < D*D; x++) {
            if (x == 4 || T[x] != -1 || set_r.count(make_pair(x/D, x%D))) continue;
            vector<bool> reached(D*D, false);
            reached[4] = true;
            dfs(G, reached, x, 4);

            pair<int,int> p = make_pair(0, 0);
            for (int y = 0; y < D*D; y++) {
                if (set_r.count(make_pair(y / D, y % D))) continue;
                if (!reached[y] && T[y] == -1) p.first++;
                else if (!reached[y] && T[y] < t) p.second++;
            }
            PQ.push_back(make_pair(p, make_pair(-1, x)));
        }
        sort(PQ.begin(), PQ.end());

        vector<int> sort_d;
        sort(sort_d.begin(), sort_d.end());

        for (int l = 0; l < (int)PQ.size(); l++) {
            if (PQ[l].first != PQ[0].first) break;
            int s = PQ[l].second.second;
            sort_d.push_back(d[s]);
        }
        sort(sort_d.begin(), sort_d.end());
        int ttt = (double)sort_d.size()*(double)tt/(double)ts.size();
        for (int l = 0; l <  (int)PQ.size(); l++) {
            PQ[l].second.first = abs(sort_d[ttt] - d[PQ[l].second.second]);
        }
        sort(PQ.begin(), PQ.end());

        int x = PQ[0].second.second;
        cout << x / D << " " << x % D << endl;
        T[x] = t;
        set_T.insert(t);
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
