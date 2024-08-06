// https://atcoder.jp/contests/abc268/tasks/abc268_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

struct Node {
    int idx;
    vector<int> next;
    int cnt;
    int last;
    Node(int i) {
        idx = i;
        next.assign(26, -1);
        cnt = 0;
        last = 0;
    }
};

struct Trie {
    vector<Node> Nodes;
    Trie() {
        Nodes.push_back(Node(0));
    }

    void insert(string &s) {
        int now = 0;
        Nodes[now].cnt++;
        for (int i = 0; i < (int)s.size(); i++) {
            if (Nodes[now].next[s[i]-'a'] == -1) {
                Nodes[now].next[s[i]-'a'] = Nodes.size();
                Nodes.push_back(Node(Nodes.size()));
                now = Nodes.back().idx;
            } else {
                now = Nodes[now].next[s[i]-'a'];
            }
            Nodes[now].cnt++;
        }
        Nodes[now].last++;
    }

    int search(string &s) {
        int now = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (Nodes[now].next[s[i]-'a'] == -1) return 0;
            now =  Nodes[now].next[s[i]-'a'];
        }
        return Nodes[now].last;
    }

    int prefix(string &s) {
        int now = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (Nodes[now].next[s[i]-'a'] == -1) return 0;
            now =  Nodes[now].next[s[i]-'a'];
        }
        return Nodes[now].cnt;
    }

    int tmp(string &s) {
        int ans = 0, now = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            ans += Nodes[now].last;
            now =  Nodes[now].next[s[i]-'a'];
        }
        return ans;
    }
};

void solve() {
    ll N;
    cin >> N;
    vector<string> S(N);
    Trie T;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        T.insert(S[i]);
    }
    mint p = ((mint)2).inv();

    for (string &s : S) {
        ll b = T.tmp(s), l = T.prefix(s);
        mint ans = 1 + b + (N-b-l)*p;
        cout << ans.val() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
