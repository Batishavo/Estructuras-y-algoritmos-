#include <iostream>
using namespace std;

int maxSumSubarray(int arr[], int size) {
    int max_sum = arr[0];
    int current_sum = arr[0];

    for (int i = 1; i < size; i++) {
        // Si la suma actual es negativa, reiniciamos la suma actual a 0
        if (current_sum < 0) {
            current_sum = 0;
        }

        // Sumamos el elemento actual al subarreglo
        current_sum += arr[i];

        // Si la suma actual es mayor que la suma máxima encontrada hasta ahora, actualizamos la suma máxima
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    return max_sum;
}

int main() {
    int arr[] = { -2, 3, -1, 5, 4, -7, 2, 1, -3, 6 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int max_sum = maxSumSubarray(arr, size);

    cout << "La suma continua más grande es: " << max_sum << endl;

    return 0;
}
 