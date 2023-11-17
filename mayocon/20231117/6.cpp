// https://atcoder.jp/contests/abc293/tasks/abc293_g
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> A;
int max_a;
int B;

struct Query {
    int id, l, r;
    Query(int i, int l, int r): id(i), l(l), r(r) {}
};

bool cmp(Query &q1, Query &q2) {
    if (q1.l/B != q2.l/B) return q1.l/B < q2.l/B;
    return q1.r < q2.r;
}

template <typename T>
struct Mo {
    int N, Q;
    vector<Query> queries;
    vector<T> ans;
    int left=0, right=-1;
    vector<T> cnt;
    T tmp = 0;

    void add(int a) {
        cnt[a]++;
        T c = cnt[a];
        if (c >= 3) tmp += (c-1)*(c-2)/2;
    }
    void remove(int a) {
        T c = cnt[a];
        cnt[a]--;
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
        B = max(1, (int)round(N / sqrt((double)Q)));
        queries.assign(Q, {0, 0, 0});
        ans.assign(Q, 0);
        cnt.assign(max_a + 1, 0);
    }

    void add_query(int i, int l, int r) {
        queries[i] = Query(i, l, r);
    }

    void run() {
        sort(queries.begin(), queries.end(), cmp);
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
