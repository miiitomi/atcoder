#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1e18;
int N, M, D, K;

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

void dijkstra(vector<vector<Edge>> &G, vector<Edge> &edge_lists, vector<ll> &dist, int day, int s) {
    for (int i = 0; i < N; i++) dist[i] = INF;
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
}

void compute_min_distance_each_day(vector<vector<Edge>> &G, vector<Edge> &edge_lists, vector<vector<ll>> &dist, int day) {
    for (int i = 0; i < N; i++) {
        dijkstra(G, edge_lists, dist[i], day, i);
    }
}

ll score(vector<vector<Edge>> &G, vector<Edge> &edge_lists) {
    vector<vector<ll>> optimal_distance(N, vector<ll>(N));
    compute_min_distance_each_day(G, edge_lists, optimal_distance, -1);

    vector<vector<vector<ll>>> distance_each_day(D, vector<vector<ll>>(N, vector<ll>(N)));
    for (int d = 0; d < D; d++) {
        int day = d + 1;
        compute_min_distance_each_day(G, edge_lists, distance_each_day[d], day);
    }

    double res = 0;
    for (int d = 0; d < D; d++) {
        double res_day = 0;
        for (int i = 0; i < N-1; i++) {
            for (int j = i+1; j < N; j++) {
                res_day += distance_each_day[d][i][j] - optimal_distance[i][j];
            }
        }
        res += res_day / (double)(N * (N-1));
    }
    ll ans = (ll)((res * (double)2.0 / (double)D)*((double)1e+3));

    return ans;
}

int main() {
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

    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

    // 前から1日K個ずつ工事していく.
    int day = 1;
    int sum_same_day = 0;
    for (int i = 0; i < M; i++) {
        edge_lists[i].day = day;
        sum_same_day++;
        if (sum_same_day == K) {
            sum_same_day = 0;
            day++;
        }
    }

    ll final_score = score(G, edge_lists);
    cout << final_score << endl;
}
