#include <iostream>
#include <vector>

struct money {
    int a, b;
    double r, c;
};

std::vector<money> vectorOfMoney;
double nd[101];

int main() {
    int n, m, s;
    double v;
    std::cin >> n >> m >> s >> v;
    nd[s] = v;
    for (int i = 0; i < m; i++) {
        int a, b;
        double rab, cab, rba, cba;
        std::cin >> a >> b >> rab >> cab >> rba >> cba;
        vectorOfMoney.push_back({a, b, rab, cab});
        vectorOfMoney.push_back({b, a, rba, cba});
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < vectorOfMoney.size(); j++) {
            if (nd[vectorOfMoney[j].b] - (nd[vectorOfMoney[j].a] - vectorOfMoney[j].c) * vectorOfMoney[j].r < 0.000001) {
                nd[vectorOfMoney[j].b] = (nd[vectorOfMoney[j].a] - vectorOfMoney[j].c) * vectorOfMoney[j].r;
            }
        }
    }

    for (int i = 0; i < vectorOfMoney.size(); i++) {
        if ((nd[vectorOfMoney[i].a] - vectorOfMoney[i].c) * vectorOfMoney[i].r - nd[vectorOfMoney[i].b] > 0.000001) {
            std::cout << "YES";
            return 0;
        }
    };
    std::cout << "NO";
    return 0;
}
