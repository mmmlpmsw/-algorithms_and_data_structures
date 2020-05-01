
#include <algorithm>
#include <set>
#include <iostream>
//291630JT
//1628. Белые полосы
using namespace std;

//typedef pair<int, int> PII;
long N, M, K, ans;

bool compare_use_first(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first<b.first;
    return a.second<b.second;
}

bool compare_use_second(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) return a.second<b.second;
    return a.first<b.first;
}

pair<int, int> cell[180000];
set<pair<int, int> > S;

int main() {

    cin >> N >> M >> K;
    int x, y;
    for (long i = 0; i < K; ++i) {
        cin >> x >> y;
        cell[i] = make_pair(x, y);
    }

    // добавляем границы матрицы
    for (long i = 1; i <= M; i++) {
        //левая вертикальная граница
        cell[K++] = make_pair(0, i);
        // правая вертикальная граница
        cell[K++] = make_pair(N + 1, i);
    }
    for (long i = 1; i <= N; i++) {
        //верхняя горизонтальная
        cell[K++] = make_pair(i, 0);
        //нижняя горизонтальная
        cell[K++] = make_pair(i, M + 1);
    }
    //развороточка с сортировкой по Х
    sort(cell, cell + K, compare_use_first);
    for (int i = 0; i < K ; i++) {
        // длина полоски по координате У
        int diff = cell[i + 1].second - cell[i].second;
        // в одном столбце и не соседние
        if (cell[i].first == cell[i + 1].first && diff >= 2) {
            // нашлась одинокая белая клеточка
            if (diff == 2)
                //кладем в множество эту белую клетку, т.к. i - номер идущей перед ней черной клетки
                S.insert(make_pair(cell[i].first, cell[i].second + 1));
            else ans ++;
        }
    }

    sort(cell, cell + K, compare_use_second);
    for (int i = 0; i < K; i++) {
        int diff = cell[i + 1].first - cell[i].first;
        //если на одной строке и клетки не рядом
        if (cell[i].second == cell[i + 1].second && diff >= 2) {
            //одинокая белая клетка посередине
            if (diff == 2) {
                if (S.find(make_pair(cell[i].first + 1, cell[i].second)) != S.end())
                    ans ++;
            }
            else ans ++;
        }
    }

    cout << ans << endl;

    return 0;
}