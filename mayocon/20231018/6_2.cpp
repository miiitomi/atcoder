// https://atcoder.jp/contests/abc314/tasks/abc314_f
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

struct Team {
    int idx;
    mint ex;
    int par;
    int num;
    vector<int> child;

    Team(int _idx, mint _ex, int _par, int _num) {
        idx = _idx;
        ex = _ex;
        par = _par;
        num = _num;
    }

    void add_child(int v) {
        child.push_back(v);
    }
};

map<int, mint> mp;

int main() {
    int N;
    cin >> N;
    vector<Team> Teams;
    for (int i = 0; i < N; i++) Teams.push_back(Team(i, 0, -1, 1));
    vector<int> Now(N);
    for (int i = 0; i < N; i++) Now[i] = i;

    for (int i = 0; i < N-1; i++) {
        int p, q;
        cin >> p >> q;
        p--;
        q--;
        int idx_p = Now[p], idx_q = Now[q];

        Team tp = Teams[idx_p];
        while (tp.par != -1) {
            int tp_idx_old = tp.idx;
            tp = Teams[tp.par];
            Teams[tp_idx_old].par = (int)Teams.size();
        }
        Now[p] = (int)Teams.size();

        Team tq = Teams[idx_q];
        while (tq.par != -1) {
            int tq_idx_old = tq.idx;
            tq = Teams[tq.par];
            Teams[tq_idx_old].par = (int)Teams.size();
        }
        Now[q] = (int)Teams.size();

        int x = tp.num + tq.num;
        if (!mp.count(x)) mp[x] = ((mint)x).inv();
        mint s = mp[x];

        tp.ex += tp.num * s;
        tq.ex += tq.num * s;
        tp.par = Teams.size();
        tq.par = Teams.size();
        Teams[tp.idx] = tp;
        Teams[tq.idx] = tq;

        Team new_team(Teams.size(), 0, -1, tp.num + tq.num);
        new_team.add_child(tp.idx);
        new_team.add_child(tq.idx);
        Teams.push_back(new_team);
    }

    for (int i = (int)Teams.size() - 1; i >= N; i--) {
        Team now_team = Teams[i];
        for (int c : now_team.child) {
            Teams[c].ex += now_team.ex;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << Teams[i].ex.val() << " ";
    }
    cout << endl;
}
