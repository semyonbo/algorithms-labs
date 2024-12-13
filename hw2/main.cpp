#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

// Функция для вычисления расстояния между двумя точками
double distance(pair<double, double> p1, pair<double, double> p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) +
                (p1.second - p2.second) * (p1.second - p2.second));
}

// Решение задачи коммивояжера
double travelingSalesman(const vector<pair<double, double> > &points) {
    int n = points.size();
    vector<vector<double> > dist(n, vector<double>(n));
    vector<vector<double> > dp(1 << n, vector<double>(n, numeric_limits<double>::infinity()));

    // Вычисление матрицы расстояний
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = distance(points[i], points[j]);
        }
    }

    // Начальное условие: стартуем из первой точки
    dp[1][0] = 0;

    // Динамическое программирование
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (mask & (1 << u)) { // Если точка u входит в текущий маршрут
                for (int v = 0; v < n; ++v) {
                    if (!(mask & (1 << v))) { // Если точка v еще не посещена
                        dp[mask | (1 << v)][v] = 
                            min(dp[mask | (1 << v)][v], dp[mask][u] + dist[u][v]);
                    }
                }
            }
        }
    }

    // Найти минимальный путь, возвращающийся в начальную точку
    double result = numeric_limits<double>::infinity();
    for (int i = 1; i < n; ++i) {
        result = min(result, dp[(1 << n) - 1][i] + dist[i][0]);
    }

    return result;
}

int main() {
    // Ввод точек
    vector<pair<double, double> > points = {
        {0, 0},
        {1, 1},
        {2, 2},
        {1, 3},
        {0, 4}
    };

    double result = travelingSalesman(points);
    cout << "Min lenght: " << result << endl;

    return 0;
}