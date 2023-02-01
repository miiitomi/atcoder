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

    vector<vector<ll>> optimal_distance(N, vector<ll>(N));
    compute_min_distance_each_day(G, edge_lists, optimal_distance, -1);

    vector<int> v_lists;
    set<int> done;

    vector<ll> sum_dist(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum_dist[i] += optimal_distance[i][j];
        }
    }

    int most_far_point = 0;
    for (int v = 1; v < N; v++) {
        if (sum_dist[most_far_point] < sum_dist[v]) {
            most_far_point = v;
        }
    }


    int now = most_far_point;
    v_lists.push_back(0);
    done.insert(0);

    for (int i = 0; i < N-1; i++) {
        int next = -1;
        ll min_dist = 1e+9;
        for (int v = 0; v < N; v++) {
            if (done.count(v)) continue;
            if (min_dist > optimal_distance[now][v]) {
                min_dist = optimal_distance[now][v];
                next = v;
            }
        }
        v_lists.push_back(next);
        done.insert(next);
        now = next;
    }

    int day = 1;
    for (int v : v_lists) {
        for (Edge e : G[v]) {
            if (edge_lists[e.id].day != 0) continue;
            edge_lists[e.id].day = day;
            day++;
            if (day == D+1) day=1;
        }
    }

    for (int i = 0; i < M; i++) {
        cout << edge_lists[i].day;
        if (i < M-1) cout << " ";
        else cout << endl;
    }
}
