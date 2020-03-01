//подключение необходимых библиотек
#include <iostream>
#include <cmath>

// использование пространства имен std
using namespace std;

// объявление константы для числа π
#define PI 3.141592653589793238462643383279502884197169399375105820974;
#define AbsMin -9223372036854775807LL - 1;

// структура, хранящая данные о точке: координаты, угол, номер
struct point {
    long int x;
    long int y;
    double arc;
    int index;
};

// объявление переменной для хранения кол-ва точек и массива точек
int n;
point points[30001];

//функция, поиска стартовой точки, с которой удобно будет пойти
int countStartArc() {
    double max_a = (points[1].arc - points[n - 1].arc) + 360;
    int max_i = 1;
    for (int i = 1; i < n - 1; i ++) {
        if (points[i + 1].arc - points[i].arc > max_a) {
            max_a = points[i + 1].arc - points[i].arc;
            max_i = i + 1;
        }
    }
    return max_i;
}

//функция для сравнения точек по углу и, при равенстве углов, по расстоянию (при необходимости расстоянию)
int compare(const void *var1, const void *var2) {
    const point *dot1 = (point *) var1;
    const point *dot2 = (point *) var2;
    if (dot1->arc - dot2->arc > 1e-10) {
        return 1;
    } else if (dot1->arc - dot2->arc < -1e-10) {
        return -1;
    } else {
        if ((dot1->x - points[0].x) * (dot1->x - points[0].x) + (dot1->y - points[0].y) * (dot1->y - points[0].y) >
            (dot2->x - points[0].x) * (dot2->x - points[0].x) + (dot2->y - points[0].y) * (dot2->y - points[0].y)) {
            return 1;
        } else {
            return -1;
        }
    }
}

int main() {
    // считывание кол-ва точек
    cin >> n;
    for (int i = 0; i < n; i ++) {
        //считывание координат точки, присвоение точке номера
        cin >> points[i].x;
        cin >> points[i].y;
        points[i].index = i;

        //первой точке присваивается минимальное значение угла
        if (i == 0) {
            points[i].arc = AbsMin;
            continue;
        }

        // если первая точка и текущая имеют одинаковые абсциссы, то отдельно обозначим углы в 90 и -90 градусов
        if (points[i].x - points[0].x == 0) {
            if (points[i].y > points[0].y) {
                points[i].arc = 90;
            } else {
                points[i].arc = -90;
            }
            continue;
        }

        // вычисляем значения остальных углов
        points[i].arc = atan((double) (points[i].y - points[0].y) / (points[i].x - points[0].x)) * 180.0 / PI;

        //обработка случая, когда угол может лежать во II или III координатных четвертях
        if ((points[i].x - points[0].x) <= 0) {
            points[i].arc -= 180;
        }
    }

    qsort(points, n, sizeof(point), compare);

    // выводим кол-во точек, которые можно соединить
    cout << n << endl;

    // выводим стартовую точку
    cout << 1 << endl;

    // определяем ту точку, с которой удобнее делать обход
    int startPosition = countStartArc();

    // обход в конечном итоге замкнется, поэтому сначала выводим точки, которые
    // окажутся в массиве после выбранной нами стартовой позиции
    for (int i = startPosition; i < n; i ++) {
        cout << points[i].index + 1 << endl;
    }

    // а затем те, которые оказались перед выбранной нами стартовой позицией
    for (int i = 1; i < startPosition; i ++) {
        cout << points[i].index + 1 << endl;
    }
    return 0;
}
