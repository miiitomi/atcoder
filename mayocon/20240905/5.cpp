// https://atcoder.jp/contests/abc353/tasks/abc353_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

struct Trie {
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

    vector<Node> Nodes;
    Trie() {
        Nodes.push_back(Node(0));
    }

    void insert(string s) {
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

    int search(string s) {
        int now = 0, ans = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (Nodes[now].next[s[i]-'a'] == -1) break;
            now =  Nodes[now].next[s[i]-'a'];
            ans += Nodes[now].cnt;
        }
        return ans;
    }

    int prefix(string s) {
        int now = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (Nodes[now].next[s[i]-'a'] == -1) return 0;
            now =  Nodes[now].next[s[i]-'a'];
        }
        return Nodes[now].cnt;
    }
};


void solve() {
    ll N;
    cin >> N;
    ll ans = 0;
    Trie t;
    while (N--) {
        string s;
        cin >> s;
        ans += t.search(s);
        t.insert(s);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
