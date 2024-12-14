#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;


double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


int main() {

    vector<pair<double, double>> points = {
        {0.0, 0.0},
        {2.0, 3.0},
        {5.0, 1.0},
        {6.0, 4.0}
    };

    int n = points.size();
    int numSubsets = 1 << n; // << это сдвиг влево на n битов, что эквивалентно умножению на 2^n

    vector<vector<double>> dp(numSubsets, vector<double>(n, numeric_limits<double>::max()));

    dp[1][0] = 0;

    for (int mask = 1; mask < numSubsets; ++mask) {
        for (int last = 0; last < n; ++last) {
            if (!(mask & (1 << last))) continue;   // если  не включена, пропускаем

            for (int next = 0; next < n; ++next) { // ищем следующую точку
                if (mask & (1 << next)) continue; // если уже посещена

                int nextMask = mask | (1 << next); // обновляем маску 
                double distance = dist(points[last].first, points[last].second, points[next].first, points[next].second);

                // обновляем минимальное расстояние
                dp[nextMask][next] = min(dp[nextMask][next], dp[mask][last] + distance);
            }
        }
    }

    double minDistance = numeric_limits<double>::max();
    for (int last = 1; last < n; ++last) { // Последняя точка перед возвращением в начальную
        double distance = dp[numSubsets - 1][last] + dist(points[last].first, points[last].second, points[0].first, points[0].second);
        minDistance = min(minDistance, distance);
    }
    cout << "Mininmal lenght: " << minDistance << endl;

    return 0;
}