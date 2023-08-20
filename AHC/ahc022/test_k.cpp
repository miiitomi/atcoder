// a12.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool prd_env = false;
random_device seed_gen;
mt19937 engine(seed_gen());
normal_distribution<> ndist(0.0, 1.0);
uniform_int_distribution<> dist_l(10, 50);
uniform_int_distribution<> dist_n(60, 100);
uniform_int_distribution<> dist_s(1, 30);
vector<int> high_values{100,100,100,150,200,250,300,400,450,550,650,800,900,950,1000};

struct Simulator {
    int L, N, S;
    vector<pair<int,int>> X;
    vector<int> A, E;
    vector<vector<int>> P;
    ll place_cost;
    ll move_cost;
    int num_wrong;
    double total_score;
    double K = 3.7;
    int min_i, min_j;
    bool final_phase = false;

    void reset_instance() {
        if (prd_env) {
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
                if (!Set_x.count(p)) Set_x.insert(p);
            }
            int i = 0;
            for (auto iter = Set_x.begin(); iter != Set_x.end(); iter++) {
                X[i] = *iter;
                i++;
            }
        }

        P.assign(L, vector<int>(L, 0));
        ll min_cost = 1e+17;
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
    }

    Simulator(int l_, int n_, int s_) {
        if (l_ != -1) L = l_;
        else L = dist_l(engine);
        if (n_ != -1) N = n_;
        else N = dist_n(engine);            
        if (s_ != -1) S = s_;
        else {
            int s = dist_s(engine);
            S = s*s;
        }

        X.resize(N);
        A.resize(N);
        for (int i = 0; i < N; i++) A[i] = i;
        reset_instance();
    }

    void cout_P() {
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) cout << P[i][j] << " ";
            cout << endl;
        }
    }

    int warp(int i, int x, int y) {
        if (prd_env && final_phase) {
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
        if (prd_env && final_phase) {
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

    void reset() {
        E.assign(N, -1);
        move_cost = 0;
        num_wrong = 0;
        total_score = 1e+14;
    }

    void solve(int high_value, bool _final_phase, double k) {
        K = k;
        reset();

        final_phase = _final_phase;
        if (!final_phase) shuffle(A.begin(), A.end(), engine);

        P[min_i][min_j] = high_value;
        place_cost = 4*(high_value*high_value);
        if (prd_env && final_phase) cout_P();

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
        for (int counter = 0; counter < N;) {
            auto p = PQ.top();
            PQ.pop();
            int i = p.second.first;
            int j = p.second.second;
            if (E[i] != -1 || done[j]) continue;
            E[i] = j;
            done[j] = true;
            counter++;
        }

        compute_total_cost();
        return;
    }
};

void solve(int l, int n, int s) {
    int h, x = (int)sqrt(s);
    if (x <= 15) h = high_values[x-1];
    else h = 1000;

    Simulator sim(l, n, s);

    for (int k = 1; k <= 50; k++) {
        sim.solve(h, false, k/10.0);
        cout << sim.L << " " << sim.N << " " << sim.S << " " << (double)k/10.0 << " " << 1+(ll)sim.total_score << " " << n - sim.num_wrong << " " << sim.num_wrong << " " << sim.place_cost << " " << sim.move_cost << endl;
    }
}

int main() {
    vector<int> Ss(30);
    for (int i = 1; i <= 30; i++) Ss[i-1] = i*i;
    cout << "L N S K total_score num_right num_wrong place_cost move_cost" << endl;
    for (int s : Ss) for (int i = 0; i < 200; i++) solve(-1, -1, s);
}
