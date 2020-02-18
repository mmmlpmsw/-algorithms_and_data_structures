//
// Created by mmmlpmsw on 10.02.2020.
//

#include <iostream>

using namespace std;

//подпрограмма, которая удалит дуоны на двух ребрах и выведет сообщение о том, на каком ребре сработала
void step(int* x, int* y, string msg) {
    (*x)--;
    (*y)--;
    cout << msg << '-' << endl;
};

int main() {
    // переменные, для хранения кол-ва дуонов в ребрах куба
    int a, b, c, d, e, f, g, h;

    // считывание кол-ва дуонов в ребрах куба
    cin >> a >> b >> c >> d >> e >> f >> g >> h;

    // если сумма дуонов на несмежных вершинах
    // не совпадает - решения нет
    if (a + h + f + c != e + d + b + g) {
        //вывод соответствующего сообщения и выход из программы
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    //пока не закончатся дуоны в одной из групп
    while (a + h + f + c > 0) {
        // если дуоны в вершине А не закончились, проверяем сначала 3 смежные с ней вершины,
        // а затем наиболее удаленную от нее - G, добавляем ребро, у которого одна вершина
        // смежная с А, а другая с G, затем удаляем эти отрезки.
        if (a > 0) {
            if (e > 0) step(&a, &e, "AE");
            else if (d > 0) step(&a, &d, "AD");
            else if (b > 0) step (&a, &b, "AB");
            else if (g > 0) {
                a--;
                g--;
                cout << "FB+" << endl;
                cout << "AB-" << endl;
                cout << "FG-" << endl;
            }
        }
        //аналогичные действия с вершиной H
        if (h > 0) {
            if (e > 0) step(&h, &e, "HE");
            else if (d > 0) step(&h, &d, "HD");
            else if (g > 0) step(&h, &g, "HG");
            else if (b > 0) {
                h--;
                b--;
                cout << "DC+" << endl;
                cout << "HD-" << endl;
                cout << "BC-" << endl;
            }
        }
        //аналогичные действия с вершиной F
        if (f > 0) {
            if (e > 0) step(&f, &e, "EF");
            else if (b > 0) step(&f, &b, "BF");
            else if (g > 0) step(&f, &g, "FG");
            else if (d > 0) {
                d--;
                f--;
                cout << "AB+" << endl;
                cout << "AD-" << endl;
                cout << "BF-" << endl;
            }
        }
        //аналогичные действия с вершиной C
        if (c > 0) {
            if (b > 0) step(&b, &c, "BC");
            else if (d > 0) step(&c, &d, "CD");
            else if (g > 0) step(&c, &g, "CG");
            else if (e > 0) {
                c--;
                e--;
                cout << "FB+" << endl;
                cout << "EF-" << endl;
                cout << "BC-" << endl;
            }
        }
    }
    return 0;
}

// Время работы – линейное, зависит от количества дуонов.
