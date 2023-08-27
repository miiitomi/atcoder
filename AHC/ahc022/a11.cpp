#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

random_device seed_gen;
mt19937 engine(seed_gen());
normal_distribution<> ndist(0.0, 1.0);
uniform_int_distribution<> dist_l(10, 50);
uniform_int_distribution<> dist_n(60, 100);
uniform_int_distribution<> dist_s(1, 30);

struct Simulator {
    int L, N, S;
    vector<pair<int,int>> X;
    vector<int> A, E;
    vector<vector<int>> P;
    ll place_cost = 0;
    ll move_cost = 0;
    int num_wrong = 0;
    double total_score = 1e+14;
    double K = 3.7;
    int high_value;
    bool prd_env;

    Simulator(int l_, int n_, int s_, int h_, bool prd) {
        high_value = h_;
        prd_env = prd;
        if (l_ != -1) L = l_;
        else {
            L = dist_l(engine);
        }
        if (n_ != -1) N = n_;
        else {
            N = dist_n(engine);            
        }
        if (s_ != -1) S = s_;
        else {
            int s = dist_s(engine);
            S = s*s;
        }
    
        if (prd_env) {
            X.resize(N);
            for (int i = 0; i < N; i++) {
                cin >> X[i].first >> X[i].second;
            }
        } else {
            set<pair<int,int>> Set_x;
            uniform_int_distribution<> dist_x(0, L-1);
            while ((int)Set_x.size() < N) {
                pair<int,int> p;
                p.first = dist_x(engine);
                p.second = dist_x(engine);
                if (!Set_x.count(p)) {
                    Set_x.insert(p);
                    X.push_back(p);
                }
            }
            sort(X.begin(), X.end());
            for (int i = 0; i < N; i++) A.push_back(i);
            shuffle(A.begin(), A.end(), engine);
        }
    }

    void set_P() {
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                if (prd_env) cout << P[i][j] << " ";
                else {
                    ll a = (P[i][j] - P[(i+1)%L][j]);
                    ll b = (P[i][j] - P[i][(j+1)%L]);
                    place_cost += a*a + b*b;
                }
            }
            if (prd_env) cout << endl;
        }
    }

    int warp(int i, int x, int y) {
        if (prd_env) {
            cout << i << " " << x << " " << y << endl;
            if (i == -1 && x == -1 && y == -1) return -1;
            int p;
            cin >> p;
            return p;
        }
        if (i == -1 && x == -1 && y == -1) return -1;
        move_cost += 100 * (10 + abs(x) + abs(y));
        int a = (X[A[i]].first + x + L) % L;
        int b = (X[A[i]].second + y + L) % L;
        double m = (double)P[a][b] + ndist(engine) * (double)S;
        return max(0, min(1000, (int)round(m)));
    }

    void compute_total_cost() {
        if (prd_env) {
            warp(-1, -1, -1);
            for (int e : E) cout << e << endl;
            return;
        }
        for (int i = 0; i < N; i++) {
            if (E[i] != A[i]) num_wrong++;
        }
        for (int i = 0; i < num_wrong; i++) total_score *= (double)0.8;
        total_score /= (1e+5 + place_cost + move_cost);
    }

    void solve() {
        P.assign(L, vector<int>(L, 0));
        ll min_cost = 1e+17;
        int min_i = -1, min_j = -1;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                ll tmp_cost = 0;
                for (int k = 0; k < N; k++) {
                    int a = X[k].first, b = X[k].second;
                    int x, y;
                    x = (i-a+L)%L;
                    y = (j-b+L)%L;
                    if (abs((a-i+L)%L) < abs(x)) x = -((a-i+L)%L);
                    if (abs((b-j+L)%L) < abs(y)) y = -((b-j+L)%L);
                    tmp_cost += 10+abs(x)+abs(y);
                }
                if (tmp_cost < min_cost) {
                    min_cost = tmp_cost;
                    min_i = i;
                    min_j = j;
                }
            }
        }

        P[min_i][min_j] = high_value;
        set_P();

        vector<vector<int>> Q(N, vector<int>(N, 0));
        
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N; k++) {
                int a = X[k].first, b = X[k].second;
                int x, y;
                x = (min_i-a+L)%L;
                y = (min_j-b+L)%L;
                if (abs((a-min_i+L)%L) < abs(x)) x = -((a-min_i+L)%L);
                if (abs((b-min_j+L)%L) < abs(y)) y = -((b-min_j+L)%L);
                int q = warp(i, x, y);
                Q[i][k] += q;
                if ((double)q >= S*K) break;
            }
        }

        priority_queue<pair<int,pair<int,int>>> PQ;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                pair<int, pair<int,int>> p;
                p.first = Q[i][j];
                p.second = make_pair(i, j);
                PQ.push(p);
            }
        }
        vector<bool> done(N, false);
        E.assign(N, -1);
        while (!PQ.empty()) {
            auto p = PQ.top();
            PQ.pop();
            int i = p.second.first;
            int j = p.second.second;
            if (E[i] != -1 || done[j]) continue;
            E[i] = j;
            done[j] = true;
        }

        compute_total_cost();
        return;
    }
};

void solve(bool prd, int l, int n, int s) {
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();

    if (prd) cin >> l >> n >> s;
    else {
        if (l == -1) l = dist_l(engine);
        if (n == -1) n = dist_n(engine);            
        if (s == -1) {
            int s_ = dist_s(engine);
            s = s_*s_;
        }
    }

    double default_score = 1e+9;
    for (int k = 1; k <= n; k++) default_score *= 0.8;

    int T = 0;
    int min_h = 100;
    vector<ll> scores(1000/min_h, 0);
    int t;
    do {
        T++;
        for (int i = 0; i < (int)scores.size(); i++) {
            Simulator sim(l, n, s, min_h*(i+1), false);
            sim.solve();
            scores[i] += 1+(ll)sim.total_score;
        }

        end = chrono::system_clock::now();
        t = (int)chrono::duration_cast<chrono::milliseconds>(end-start).count();
    } while (t <= 3000);

    int i = distance(scores.begin(), max_element(scores.begin(), scores.end()));
    int h = min_h*(i+1);

    double max_score = (double)scores[i] / T;

    if (max_score > default_score) {
        Simulator sim(l, n, s, h, prd);
        sim.solve();
    } else if (prd) {
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) cout << 0 << " ";
            cout << endl;
        }
        cout << "-1 -1 -1" << endl;
        for (int i = 0; i < n; i++) cout << i << endl;
    }

    cout << l << " " << n << " " <<s << " " << T << endl;
}

int main() {
    int l=-1, n=-1, s=-1;
    bool prd = true;
    for (int i = 0; i < 10; i++) solve(prd, l, n, s);
}