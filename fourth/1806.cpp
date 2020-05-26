#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>

using namespace std;
const int N = 50001;
const int M = 20000001;
const int max_ = 0x3f3f3f3f;

int n;
int valForTransition[15];
string telegraphNumber[N];
map<long long, int> node;
struct edge {
    int v, w, next;
} edge[M];
int head[N], ec;

int dis[N], par[N];
bool vis[N];
vector<int> vec;
struct pp{
    int d, u;
    bool operator < (const pp &cmp) const {
        return d > cmp.d;
    }
};


void add_edge(int u, int v, int w) {
    edge[ec] = {v, w, head[u]};
    head[u] = ec++;
}

vector<long long> py;


//для определения всех связей между телеграфами
void deal(int id) {
    long long tmp = 0;
    // восстановление номера телеграфа
    for (int i = 0; i < 10; ++i) {
        tmp = tmp * 10 + telegraphNumber[id][i] - '0';
    }
    const long long tt = tmp;
    //поиск связи при замене одной цифры
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            tmp = tmp - (telegraphNumber[id][i] - '0' - j) * py[i];
            auto it = node.find(tmp);
            if (it != node.end()) {
                int len = 0;
                int idx = it->second;
                while (len < 9 && telegraphNumber[id][len] == telegraphNumber[idx][len]) {
                    len++;
                }
                add_edge(id, idx, valForTransition[len]);
                add_edge(idx, id, valForTransition[len]);
            }
            tmp = tt;
        }
    }
    //поиск связи при смене 2-х цифр местами
    for (int i = 0; i < 10; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            int t1 = telegraphNumber[id][i] - '0';
            int t2 = telegraphNumber[id][j] - '0';
            tmp = tmp - (t1 - t2) * py[i] - (t2 - t1) * py[j];
            auto it = node.find(tmp);
            if (it != node.end()){
                int len = 0;
                int idx = it->second;
                while (len < 9 && telegraphNumber[id][len] == telegraphNumber[idx][len]){
                    len++;
                }
                add_edge(id, idx, valForTransition[len]);
                add_edge(idx, id, valForTransition[len]);
            }
            tmp = tt;
        }
    }
    node.insert({tt, id});
}

// Алгоритм Дейкстры
void Dijkstra(int x){
    priority_queue<pp> pq;
    dis[x] = 0;
    pq.push({dis[x], x});
    while (!pq.empty()){
        int u = pq.top().u;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (int i = head[u]; i != -1 ; i = edge[i].next) {
            int v = edge[i].v;
            if (dis[v] > dis[u] + edge[i].w){
                par[v] = u;
                dis[v] = dis[u] + edge[i].w;
                pq.push({dis[v], v});
            }
        }
    }
}


int main() {

    long long tmp = 1;

    for (int i = 0; i < 10; ++i) {
        py.push_back(tmp);
        tmp *= 10;
    }

    reverse(py.begin(), py.end());

    cin >> n;

    memset(head, -1, sizeof(head));
    ec = 0;                             // счетчик узлов

    for (int i = 0; i < 10; ++i) {
        cin >> valForTransition[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> telegraphNumber[i];
        deal(i);
    }

    memset(dis, max_, sizeof(dis));
    par[1] = -1;


    Dijkstra(1);

    if (dis[n] == max_){
        cout << "-1";
        return 0;
    }

    cout << dis[n] << "\n";

    int x = n;
    while(x != -1){
        vec.push_back(x);
        x = par[x];
    }
    reverse(vec.begin(), vec.end());
    cout << vec.size() << "\n";
    for (int i = 0; i < vec.size(); ++i){
        cout << vec[i] << (i == vec.size() - 1? "\n" : " ");
    }

    return 0;
}