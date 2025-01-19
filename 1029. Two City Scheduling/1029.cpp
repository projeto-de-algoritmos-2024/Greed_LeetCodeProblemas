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
    }
};