#include <iostream>
#include <vector>

using namespace std;

int longestIncreasingSubsequence(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 1);  // Creamos un vector para almacenar la longitud de la LIS hasta cada elemento.

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);  // Si el elemento actual es mayor que el elemento anterior, actualizamos la longitud de la LIS.
            }
        }
    }

    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        maxLength = max(maxLength, dp[i]);  // Encontramos la longitud máxima de la LIS en todo el vector dp.
    }

    return maxLength;
}

int main() {
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int length = longestIncreasingSubsequence(nums);
    cout << "La longitud de la subsecuencia creciente más larga es: " << length << endl;
    return 0;
}
