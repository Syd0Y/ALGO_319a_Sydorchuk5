#include <iostream>
#include <cmath>
using namespace std;

bool inRect(double x, double y, double a, double b) {
    return x >= 0 && x <= b && y >= 0 && y <= a;
}

bool inCircle(double x, double y, double a, double b, double R) {
    double dx = x - b / 2, dy = y - a / 2;
    return dx * dx + dy * dy <= R * R;
}


bool variant1(double x, double y, double a, double b, double R) {
    bool c = inCircle(x, y, a, b, R);
    bool r = inRect(x, y, a, b);
    return (x <= b / 2 && c) || (x >= b / 2 && r && !c);
}

void task1() {
    double a, b, R, x, y;
    cout << "Введіть a, b, R: ";
    cin >> a >> b >> R;
    cout << "Введіть x, y: ";
    cin >> x >> y;

    cout << "Варіант 1: " << (variant1(x, y, a, b, R) ? "належить" : "не належить") << endl;
}

// ---------- Задача 20 ----------
void task20() {
    double x;
    int n;
    cout << "Введіть x та n: ";
    cin >> x >> n;

    double t = -1 + cos(x);
    if (fabs(t) >= 1) {
        cout << "Умова |-1+cos(x)| < 1 не виконується!" << endl;
        return;
    }

    double sum = 0, p = 1; // p = t^k
    for (int k = 1; k <= n; k++) {
        p *= t;
        sum += pow(-1, k) * p / k;
    }
    sum = -sum;

    cout << "Сума ряду      = " << sum << endl;
    cout << "Точне значення = " << log(cos(x)) << endl;
}

// ---------- Задача 27 ----------
void task27() {
    double x;
    int N;
    cout << "Введіть x та N: ";
    cin >> x >> N;

    double sum = 0;
    double f = -1; // f_1 = (-1)^1 * x^0 / 1! = -1
    for (int n = 1; n <= N; n++) {
        sum += f * sqrt(3.0 * n + 1);
        f *= -x / (n + 1); // f_{n+1} = f_n * (-x) / (n+1)
    }

    cout << "Сума ряду = " << sum << endl;
}

// ---------- Головне меню ----------
int main() {
    int choice;
    do {
        cout << "\n=== Меню ===" << endl;
        cout << "1  - Задача 1 (геометрична область)" << endl;
        cout << "20 - Задача 20 (ряд з cos(x))" << endl;
        cout << "27 - Задача 27 (ряд з sqrt(3n+1)/n!)" << endl;
        cout << "0  - Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:  task1();  break;
            case 20: task20(); break;
            case 27: task27(); break;
            case 0:  cout << "Кінець програми." << endl; break;
            default: cout << "Невірний вибір!" << endl;
        }
    } while (choice != 0);

    return 0;
}