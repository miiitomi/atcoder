#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1e+9;
int N, M, D, K;

int RandInt(int a, int b) {
    return a + rand() % (b - a + 1);
}

struct Edge {
    int id;
    int from;
    int to;
    int weight;
    int day;

    Edge(int id_, int from_, int to_, int weight_) {
        id = id_;
        from = from_;
        to = to_;
        weight = weight_;
        day = 0;
    }
};

void dijkstra(vector<vector<Edge>> &G, vector<Edge> &edge_lists, int eid, vector<int> &res) {
    vector<pair<ll, int>> dist(N);
    for (int i = 0; i < N; i++) {
        dist[i].first = INF;
        dist[i].second = -1;
    }

    int s = edge_lists[eid].from;
    int t = edge_lists[eid].to;

    dist[s].first = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    Q.push(make_pair(0, s));

    while (!Q.empty()) {
        ll d = Q.top().first;
        int v = Q.top().second;
    
        if (v == t) break;

        Q.pop();
        if (dist[v].first < d) continue;

        for (auto e : G[v]) {
            if (e.id == eid) continue;
            if (dist[v].first + e.weight < dist[e.to].first) {
                dist[e.to].first = dist[v].first + e.weight;
                dist[e.to].second = e.id;
                pair<ll, ll> q = make_pair(dist[e.to].first, e.to);
                Q.push(q);
            }
        }
    }

    int now = t;
    while (now != s) {
        res.push_back(dist[now].second);
        if (now == edge_lists[dist[now].second].from) {
            now = edge_lists[dist[now].second].to;
        } else {
            now = edge_lists[dist[now].second].from;
        }
    }
}

ll dijkstra2(vector<vector<Edge>> &G, vector<Edge> &edge_lists, int day, int s) {
    // day における s 出発の最短距離の合計.
    vector<ll> dist(N, INF);
    dist[s] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    Q.push(make_pair(0, s));

    while (!Q.empty()) {
        ll d = Q.top().first;
        ll v = Q.top().second;
        Q.pop();
        if (dist[v] < d) continue;

        for (auto e : G[v]) {
            if (edge_lists[e.id].day != day && dist[v] + e.weight < dist[e.to]) {
                dist[e.to] = dist[v] + e.weight;
                pair<ll, ll> q = make_pair(dist[e.to], e.to);
                Q.push(q);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) ans += dist[i];

    return ans;
}

int main() {
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
    int t = 0;

    cin >> N >> M >> D >> K;

    vector<vector<Edge>> G(N);
    vector<Edge> edge_lists;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(Edge(i, u, v, w));
        G[v].push_back(Edge(i, v, u, w));
        edge_lists.push_back(Edge(i, u, v, w));
    }

    vector<vector<int>> lists_ukairo(M);
    for (int i = 0; i < M; i++) dijkstra(G, edge_lists, i, lists_ukairo[i]);

    vector<vector<int>> ng(M, vector<int>(D+1, 0));
    vector<int> num_koji_edges(D+1, 0);

    for (int i = 0; i < M; i++) {
        map<int, vector<int>> Mp;
        for (int d = 1; d <= D; d++) {
            Mp[ng[i][d]].push_back(d);
        }
        for (auto iter = Mp.begin(); iter != Mp.end(); iter++) {
            vector<int> &days = iter->second;
            int num_min_koji_edges = K;
            int optim_day = -1;
            for (int day : days) {
                if (num_koji_edges[day] < num_min_koji_edges) {
                    optim_day = day;
                    num_min_koji_edges = num_koji_edges[day];
                }
            }
            if (num_min_koji_edges < K) {
                edge_lists[i].day = optim_day;
                num_koji_edges[optim_day]++;
                for (int j : lists_ukairo[i]) {
                    ng[j][optim_day]++;
                }
                break;
            }
        }
    }

    while (t <= 5950) {
        int i = RandInt(0, M-1);
        int j = RandInt(0, M-1);
        int day1 = edge_lists[i].day;
        int day2 = edge_lists[j].day;

        if (edge_lists[i].day == edge_lists[j].day || ng[i][day2] > 0 || ng[j][day1] > 0) {
            end = chrono::system_clock::now();
            t = (int)chrono::duration_cast<chrono::milliseconds>(end-start).count();
            continue;
        }

        vector<int> starts(4);
        starts[0] = edge_lists[i].from;
        starts[1] = edge_lists[j].from;
        starts[2] = edge_lists[i].to;
        starts[3] = edge_lists[j].to;

        ll fuman_0 = 0;
        for (int k = 0; k < 4; k++) {
            fuman_0 += dijkstra2(G, edge_lists, day1, starts[k]);
            fuman_0 += dijkstra2(G, edge_lists, day2, starts[k]);
        }

        swap(edge_lists[i].day, edge_lists[j].day);
        ll fuman_1 = 0;
        for (int k = 0; k < 4; k++) {
            fuman_1 += dijkstra2(G, edge_lists, day1, starts[k]);
            fuman_1 += dijkstra2(G, edge_lists, day2, starts[k]);
        }

        if (fuman_0 < fuman_1) {
            swap(edge_lists[i].day, edge_lists[j].day);
        } else {
            for (int k : lists_ukairo[i]) {
                ng[k][day1]--;
                ng[k][day2]++;
            }
            for (int k : lists_ukairo[j]) {
                ng[k][day2]--;
                ng[k][day1]++;
            }
        }

        end = chrono::system_clock::now();
        t = (int)chrono::duration_cast<chrono::milliseconds>(end-start).count();
    }

    for (int i = 0; i < M; i++) {
        cout << edge_lists[i].day;
        if (i < M - 1) cout << " ";
        else cout << endl;
    }
}
