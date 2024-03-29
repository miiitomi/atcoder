// https://atcoder.jp/contests/abc293/tasks/abc293_g
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> A;
int max_a;

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
    T tmp = 0;    // TODO: set initial tmp answer.

    void add(int a) {
        state[a]++;
        T c = state[a];
        if (c >= 3) tmp += (c-1)*(c-2)/2;
    }
    void remove(int a) {
        T c = state[a];
        state[a]--;
        if (c >= 3) tmp -= (c-1)*(c-2)/2;
    }
    void query(Query &q) {
        while (right < q.r) {
            right++;
            add(A[right]);
        }
        while (q.l < left) {
            left--;
            add(A[left]);
        }
        while (left < q.l) {
            remove(A[left]);
            left++;
        }
        while (q.r < right) {
            remove(A[right]);
            right--;
        }
        ans[q.id] = tmp;
    }
    Mo(int n, int q): N(n), Q(q) {
        B = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));
        queries.assign(Q, {0, 0, 0});
        ans.assign(Q, 0);
        state.assign(max_a + 1, 0);  // TODO: set state variable.
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
        for (Query &q : queries) query(q);
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    max_a = *max_element(A.begin(), A.end());

    Mo<ll> mo(N, Q);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        mo.add_query(i, l, r);
    }

    mo.run();
    for (int i = 0; i < Q; i++) {
        cout << mo.ans[i] << endl;
    }
}
