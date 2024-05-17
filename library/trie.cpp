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
        int now = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (Nodes[now].next[s[i]-'a'] == -1) return 0;
            now =  Nodes[now].next[s[i]-'a'];
        }
        return Nodes[now].last;
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
    int N;
    cin >> N;
    Trie t;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        t.insert(s);
    }
    ll ans = 0;
    for (int i = 1; i < (int)t.Nodes.size(); i++) {
        ll n = t.Nodes[i].cnt;
        ans += n*(n-1)/2;
    }
    cout << ans << "\n";
}