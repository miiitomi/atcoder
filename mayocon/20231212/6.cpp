// https://atcoder.jp/contests/abc242/tasks/abc242_g
#include <bits/stdc++.h>
using namespace std;

vector<int> A;

template <typename T>
struct Mo {
    struct Query {
        int id, l, r, l_;
        Query(int i, int l, int r, int b = 1): id(i), l(l), r(r) {l_ = l / b;}
    };

    int N, Q, B;
    vector<Query> queries;
    vector<T> ans;
    int left=0, right=-1;

    /* Update below! */
    vector<T> state;    // TODO: Set state variables.
    T tmp = 0;    // TODO: Set initial tmp answer.

    void _add(int a) {
        // TODO: Set add function used in query().
        state[a]++;
        if (state[a] % 2 == 0) tmp++;
    }
    void _remove(int a) {
        // TODO: Set remove function used in query().
        state[a]--;
        if (state[a] % 2 != 0) tmp--;
    }
    void _query(Query &q) {
        while (right < q.r) {
            right++;
            _add(A[right]);    // TODO: Update arg.
        }
        while (q.l < left) {
            left--;
            _add(A[left]);    // TODO: Update arg.
        }
        while (left < q.l) {
            _remove(A[left]);    // TODO: Update arg.
            left++;
        }
        while (q.r < right) {
            _remove(A[right]);    // TODO: Update arg.
            right--;
        }
        ans[q.id] = tmp;
    }
    Mo(int n, int q): N(n), Q(q) {
        B = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));
        queries.assign(Q, {0, 0, 0});
        ans.assign(Q, 0);
        state.assign(N, 0);  // TODO: Set state variable.
    }
    /* Up to here! */

    void add_query(int i, int l, int r) {
        // Add i'th query for [l, r] . (REMARK: closed interval!)
        queries[i] = Query(i, l, r, B);
    }

    void run() {
        sort(queries.begin(), queries.end(), [](Query &q1, Query &q2){
            if (q1.l_ != q2.l_) return q1.l_ < q2.l_;
            return q1.r < q2.r;
        });
        for (Query &q : queries) _query(q);
    }
};

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    int Q;
    cin >> Q;
    Mo<int> model(N, Q);
    for (int q = 0; q < Q; q++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        model.add_query(q, l, r);
    }
    model.run();
    for (int c : model.ans) cout << c << "\n";
}
