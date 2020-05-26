#include <bits/stdc++.h>
using namespace std;

struct node {
    node* parent;
    int rank; // для объединения по рангу
    int n{0};  // номер этого узла
    node() : parent(this), rank(0) { }
};

struct edge {
    node* a, *b;
    int weight;
    edge(node* a, node* b, int weight) : a(a), b(b), weight(weight) {}
};

node* find(node* s) {
    if (s != s->parent) {
        s->parent = find(s->parent);
    }
    return s->parent;
}

void join(node* c, node* d) {
    node* a = find(c);
    node* b = find(d);
    if(a->rank > b->rank) {
        b->parent = a;
    } else {
        a->parent = b;

        if(a->rank == b->rank) {
            b->rank++;
        }
    }
}

vector<node> nodes;
vector<edge> edges;
vector<edge*> ans;

int main() {

    int n, m;
    cin >> n >> m;
    nodes.reserve(n + 1);

    for (int i = 0; i < n + 1; i++) {
        nodes.emplace_back();
        nodes.back().parent = &nodes.back();
        nodes.back().n = i;
    }

    edges.reserve(m);
    ans.reserve(m);

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.emplace_back(&nodes[x], &nodes[y], w);
    }
    sort(edges.begin(), edges.end(), [] (edge& a, edge& b) { return a.weight < b.weight; });
    int max_res = 0;

    // алгоритм Краскала
    for (int i = 0; i < edges.size(); i ++) {
        edge& e = edges.at(i);
      
        if(find(e.a) != find(e.b)) {
            join(e.a, e.b);
            max_res = max(max_res, e.weight);
            ans.push_back(&e);
        }
    }
    
    cout << max_res << "\n";
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i ++) {
        auto e = ans.at(i);
        cout << e->a->n << " " << e->b->n << "\n";
    }
    return 0;
}