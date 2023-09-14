#include <iostream>
#include <vector>

using namespace std;

// Función para resolver el problema del 0-1 Knapsack
int knapsack(vector<int> &weights, vector<int> &values, int capacity)
{
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= capacity; ++w)
        {
            // Si el peso del elemento actual es menor o igual a la capacidad actual
            // entonces podemos considerar agregarlo o no al knapsack
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else
            {
                // Si el peso del elemento actual es mayor que la capacidad actual,
                // no podemos agregarlo al knapsack
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int capacity = 5;

    int maxValue = knapsack(weights, values, capacity);

    cout << "El valor máximo que se puede obtener es: " << maxValue << endl;

    return 0;
}
