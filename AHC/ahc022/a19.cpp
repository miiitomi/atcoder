// a19.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool prd_env = false;
// random_device seed_gen;
// mt19937 engine(seed_gen());
// mt19937 engine(0);
normal_distribution<> ndist(0.0, 1.0);
uniform_int_distribution<> dist_l(10, 50);
uniform_int_distribution<> dist_n(60, 100);
uniform_int_distribution<> dist_s(1, 30);
vector<int> high_values{100,100,100,150,200,250,300,400,450,550,650,800,900,950,1000};

// chrono::system_clock::time_point start, end_t;

struct Simulator {
    int L, N, S, high_value;
    vector<pair<int,int>> X;
    vector<int> A, E;
    vector<vector<int>> P;
    ll place_cost;
    ll move_cost;
    ll total_cost;
    int num_wrong;
    double total_score;
    double K = 3.7;
    set<pair<int,int>> Q;
    set<pair<int,int>> Q_zero;
    bool final_phase = false;
    int p = 1;
    vector<pair<int,int>> step;

    void set_P(mt19937 &engine) {
        uniform_int_distribution<> dist_x(0, L-1);
        int max_p = (int)sqrt((50.0*N*N*L)/(4.0*high_value*high_value)) - 1;
        int l=1, r=max_p+1;

        ll tmp_min_cost = 1e+17;
        int min_i=-1, min_j=-1;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                ll tmp_cost = 0;
                vector<pair<int,int>> tmp_step(N);
                for (int k = 0; k < N; k++) {
                    int a = X[k].first, b = X[k].second;
                    int x, y;
                    x = (i-a+L)%L;
                    y = (j-b+L)%L;
                    if (abs((a-i+L)%L) < abs(x)) x = -((a-i+L)%L);
                    if (abs((b-j+L)%L) < abs(y)) y = -((b-j+L)%L);
                    tmp_cost += 10+abs(x)+abs(y);
                    tmp_step[k] = make_pair(x,y);
                }
                if (tmp_cost < tmp_min_cost) {
                    tmp_min_cost = tmp_cost;
                    min_i = i;
                    min_j = j;
                    step = tmp_step;
                }
            }
        }
        Q.insert(make_pair(min_i, min_j));

        while (r-l>1) {
            int tmp_p = (r+l)/2;
            vector<pair<int,int>> tmp_opt_step(N);
            bool is_able = false;
            tmp_min_cost = 1e+17;
            set<pair<int,int>> tmp_opt_Q;
            for (int i_ = 0; i_ < 1e+3; i_++) {
                ll tmp_cost = 0;
                set<pair<int,int>> tmp_Q;
                vector<pair<int,int>> tmp_step(N);
                while ((int)tmp_Q.size() < tmp_p) tmp_Q.insert(make_pair(dist_x(engine), dist_x(engine)));
                for (int k = 0; k < N; k++) {
                    int a = X[k].first, b = X[k].second;
                    int min_x=0, min_y=0;
                    int min_value = 1e+9;
                    for (auto iter = tmp_Q.begin(); iter != tmp_Q.end(); iter++) {
                        int i=iter->first,j=iter->second;
                        int x, y;
                        x = (i-a+L)%L;
                        y = (j-b+L)%L;
                        if (abs((a-i+L)%L) < abs(x)) x = -((a-i+L)%L);
                        if (abs((b-j+L)%L) < abs(y)) y = -((b-j+L)%L);
                        if (abs(x) + abs(y) < min_value) {
                            min_value = abs(x) + abs(y);
                            min_x = x;
                            min_y = y;
                        }
                    }
                    tmp_cost += 10+abs(min_x)+abs(min_y);
                    tmp_step[k] = make_pair(min_x, min_y);
                }
                int counter = 0;
                for (int k = 0; k < N; k++) for (int l = 0; l < N; l++) counter+= tmp_Q.count(make_pair((X[k].first+tmp_step[l].first+L)%L, (X[k].second+tmp_step[l].second+L)%L));
                if (counter == N && tmp_cost < tmp_min_cost) {
                    is_able = true;
                    tmp_min_cost = tmp_cost;
                    tmp_opt_Q = tmp_Q;
                    tmp_opt_step = tmp_step;
                }
            }

            if (is_able) {
                l = tmp_p;
                p = tmp_p;
                Q = tmp_opt_Q;
                step = tmp_opt_step;
            } else {
                r = tmp_p;
            }
        }

        for (int k = 0; k < N; k++) for (int l = 0; l < N; l++) {
            pair<int,int> pt = make_pair((X[k].first+step[l].first+L)%L, (X[k].second+step[l].second+L)%L);
            if (!Q.count(pt)) Q_zero.insert(pt);
        }

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                pair<int,int> pt = make_pair(i,j);
                if (Q.count(pt)) P[i][j] = high_value;
                else P[i][j] = 0;
            }
        }

        for (int t_ = 0; t_ < 1e+3; t_++) {
            for (int i = 0; i < L; i++) {
                for (int j = 0; j < L; j++) {
                    pair<int,int> pt = make_pair(i,j);
                    if (!Q.count(pt) && !Q_zero.count(pt)) {
                        P[i][j] = 0;
                        P[i][j] += P[(i+1)%L][j];
                        P[i][j] += P[(i-1+L)%L][j];
                        P[i][j] += P[i][(j+1)%L];
                        P[i][j] += P[i][(j-1+L)%L];
                        P[i][j] /= 4;
                    }
                }
            }            
        }

        // end_t = chrono::system_clock::now();
        // int t = (int)chrono::duration_cast<chrono::milliseconds>(end_t-start).count();
        // cout << "# " << t << " [ms]" << endl;
    }

    Simulator(int l_, int n_, int s_, mt19937 &engine) {
        if (l_ != -1) L = l_;
        else L = dist_l(engine);
        if (n_ != -1) N = n_;
        else N = dist_n(engine);            
        if (s_ != -1) S = s_;
        else S = (int)pow((int)dist_s(engine), 2);
        if ((int)sqrt(s_) <= 15) high_value = high_values[(int)sqrt(s_)-1];
        else high_value = 1000;

        X.resize(N);
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

        A.resize(N);
        for (int i = 0; i < N; i++) A[i] = i;

        P.assign(L, vector<int>(L, 0));
        set_P(engine);
    }

    void cout_P() {
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) cout << P[i][j] << " ";
            cout << endl;
        }
    }

    int warp(int i, int x, int y, mt19937 &engine) {
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

    void compute_total_cost(mt19937 &engine) {
        if (prd_env && final_phase) {
            warp(-1, -1, -1, engine);
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
        place_cost = 0;
        move_cost = 0;
        num_wrong = 0;
        total_score = 1e+14;
    }

    void solve(bool _final_phase, mt19937 &engine) {
        reset();

        final_phase = _final_phase;
        if (!final_phase) shuffle(A.begin(), A.end(), engine);

        place_cost = 4*p*(high_value*high_value);
        if (prd_env && final_phase) cout_P();

        vector<vector<int>> R(N, vector<int>(N, 0));
        vector<priority_queue<pair<int,int>>> V(N);
        vector<bool> done(N, false);
        int counter = 0;
        int remain_warp = 10000;
        
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N; k++) {
                if (done[k]) continue;
                remain_warp--;
                int q = warp(i, step[k].first, step[k].second, engine);
                if ((double)q >= S*K) {
                    E[i] = k;
                    done[k] = true;
                    counter++;
                    break;
                }
                R[i][k] += q;
                V[i].push(make_pair(q, k));
            }
        }

        int remain_warp_par_entrance = 0;
        if (N - counter > 0) remain_warp_par_entrance = min(N-counter, remain_warp/(N-counter));

        for (int i = 0; i < N; i++) {
            if (E[i] != -1) continue;
            for (int t_ = 0; t_ < remain_warp_par_entrance; t_++) {
                auto pt = V[i].top();
                V[i].pop();
                int k = pt.second;
                if (done[k]) continue;
                int q = warp(i, step[k].first, step[k].second, engine);
                if ((double) q >= S*K) {
                    E[i] = k;
                    done[k] = true;
                    counter++;
                    break;                    
                }
                R[i][k] = (R[i][k] + q) / 2;
            }
        }

        priority_queue<pair<int,pair<int,int>>> PQ;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (E[i] != -1 && done[j]) continue;
                pair<int, pair<int,int>> p;
                p.first = R[i][j];
                p.second = make_pair(i, j);
                PQ.push(p);
            }
        }
        for (; counter < N;) {
            auto p = PQ.top();
            PQ.pop();
            int i = p.second.first;
            int j = p.second.second;
            if (E[i] != -1 || done[j]) continue;
            E[i] = j;
            done[j] = true;
            counter++;
        }

        compute_total_cost(engine);
        return;
    }
};

ll solve(int l, int n, int s, mt19937 &engine) {
    if (prd_env) cin >> l >> n >> s;
    else {
        if (l == -1) l = dist_l(engine);
        if (n == -1) n = dist_n(engine);            
        if (s == -1) s = (int)pow((int)dist_s(engine), 2);
    }

    Simulator sim(l, n, s, engine);

    double default_score = 1e+9;
    for (int k = 1; k <= n; k++) default_score *= 0.8;

    double predicted_score = 0;

    for (int t = 0; t < 100; t++) {
        sim.solve(false, engine);
        predicted_score += sim.total_score;
    }
    predicted_score /= 100.0;

    if (predicted_score > default_score) {
        sim.solve(true, engine);
    } else if (prd_env) {
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) cout << 0 << " ";
            cout << endl;
        }
        cout << "-1 -1 -1" << endl;
        for (int i = 0; i < n; i++) cout << i << endl;
    } else {
        sim.reset();
        sim.num_wrong = n;
        sim.place_cost = 0;
        sim.move_cost = 0;
        sim.total_score = default_score;
    }

    return 1+(ll)sim.total_score;
}

int main() {
    // start = chrono::system_clock::now();
    if (prd_env) {
        random_device seed_gen;
        mt19937 engine(seed_gen());
        solve(-1,-1,-1, engine);
        return 0;
    }

    for (int s = 1; s <= 30; s++) {
        ll ans = 0;
        for (int i = 0; i < 10; i++) {
            mt19937 engine((10*(s-1))+i);
            ans += solve(-1, -1, s*s, engine);
        }
        cout << "S = " << s*s << " : " << ans/10 << endl;
    }
}
