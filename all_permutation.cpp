#include <bits/stdc++.h>
using namespace std;

void generatePermutations(vector<int>& elements, vector<int>& permutation, int m)
{
    if (permutation.size() == m)
    {
        for (int i : permutation)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < elements.size(); i++)
    {
        vector<int> remaining = elements;
        remaining.erase(remaining.begin() + i);

        permutation.push_back(elements[i]);
        generatePermutations(remaining, permutation, m);
        permutation.pop_back();
    }
}

int main()
{
    int n, m;
    cout << "Ingrese la cantidad de elementos (n): ";
    cin >> n;
    cout << "Ingrese el tamaño de las permutaciones (m): ";
    cin >> m;

    vector<int> elements(n);
    for (int i = 0; i < n; i++)
    {
        elements[i] = i + 1;
    }

    vector<int> permutation;
    generatePermutations(elements, permutation, m);

    return 0;
}
