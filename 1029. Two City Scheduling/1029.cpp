#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Compara a diferença de custo (custoA - custoB) entre duas pessoas
    static bool compareByCostDiff(vector<int>& cost1, vector<int>& cost2) {
        int diff1 = cost1[0] - cost1[1];
        int diff2 = cost2[0] - cost2[1];
        return diff1 < diff2;
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        // Ordenar pela diferença de custo entre ir para cidade A e B
        sort(costs.begin(), costs.end(), compareByCostDiff);

        int size = costs.size();
        int n = size / 2;
        int totalCost = 0;

        // Seleciona as primeiras n pessoas para a cidade A e as últimas n para a cidade B
        for (int i = 0; i < n; i++) {
            totalCost += costs[i][0];
            totalCost += costs[size - i - 1][1];
        }

        return totalCost;
    }
};