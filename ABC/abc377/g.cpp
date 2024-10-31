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
        ll len;
        Node(int i) {
            idx = i;
            next.assign(26, -1);
            cnt = 0;
            last = 0;
            len = INF;
        }
    };

    vector<Node> Nodes;
    Trie() {
        Nodes.push_back(Node(0));
        Nodes.back().len = 0;
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
            Nodes[now].len = min(Nodes[now].len, (ll)s.size());
        }
        Nodes[now].last++;
    }

    ll search(string s) {
        int now = 0;
        ll ans = s.size();
        for (int i = 0; i < (int)s.size(); i++) {
            if (Nodes[now].next[s[i]-'a'] == -1) break;
            now =  Nodes[now].next[s[i]-'a'];
            ans = min(ans, (ll)s.size()+Nodes[now].len-2*(i+1));
        }
        return ans;
    }
};


void solve() {
    ll N;
    cin >> N;
    Trie t;

    for (ll i = 0; i < N; i++) {
        string s;
        cin >> s;
        cout << t.search(s) << "\n";
        t.insert(s);
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
