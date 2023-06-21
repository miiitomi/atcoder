#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    int parent;
    vector<int> children;
    int number;

    Node(int id, int parent) : id(id), parent(parent) {}

    void add_child(int child) {
        children.push_back(child);
    }
};

void dfs(int N, int K, vector<Node> &tree, vector<bool> &written_numbers, int v, int &count) {
    int k = tree[v].number;
    if (0 <= k) {
        written_numbers[k] = true;
    } else {
        count++;
    }

    for (int c : tree[v].children) {
        dfs(N, K, tree, written_numbers, c, count);
    }
}

bool can_win(int N, int K, vector<Node> &tree, int s) {
    vector<bool> written_numbers(N+1, false);
    int count = 0;
    dfs(N, K, tree, written_numbers, s, count);

    if (written_numbers[K]) return false;

    if (count >= 2) return false;

    int cnt_not_written = 0;
    for (int x = 0; x < K; x++) {
        if (!written_numbers[x]) {
            cnt_not_written++;
            if (cnt_not_written == 2) return false;
        }
    }

    if (count == 1 && cnt_not_written <= 1) return true;
    if (count == 0 && cnt_not_written == 0) return true;

    return false;
}

void solve() {
    int N, K;
    cin >> N >> K;

    vector<Node> tree;
    tree.push_back(Node(0, -1));

    for (int i = 1; i < N; i++) {
        int p;
        cin >> p;
        p--;
        tree.push_back(Node(i, p));
        tree[p].add_child(i);
    }
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        tree[i].number = a;
    }

    for (int x = 0; x < N; x++) {
        if (can_win(N, K, tree, x)) {
            std::cout << "Alice" << endl;
            return;
        }
    }

    std::cout << "Bob" << endl;
    return;
}


int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
}
