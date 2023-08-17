#include <iostream>
#include <climits>

using namespace std;

int kadane(int arr[], int n)
{
    int maxEndingHere = 0;
    int maxSoFar = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxEndingHere = max(maxEndingHere + arr[i], arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

int maxSubmatrixSum(int matrix[][100], int rows, int cols)
{
    int maxSum = INT_MIN;

    for (int left = 0; left < cols; left++)
    {
        int temp[100] = {0};

        for (int right = left; right < cols; right++)
        {
            for (int i = 0; i < rows; i++)
            {
                temp[i] += matrix[i][right];
            }

            int currentSum = kadane(temp, rows);
            maxSum = max(maxSum, currentSum);
        }
    }

    return maxSum;
}

int main()
{
    int rows, cols;
    cout << "Ingrese el número de filas: ";
    cin >> rows;
    cout << "Ingrese el número de columnas: ";
    cin >> cols;

    int matrix[100][100];
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int maxSum = maxSubmatrixSum(matrix, rows, cols);
    cout << "La máxima suma de una submatriz es: " << maxSum << endl;

    return 0;
}
