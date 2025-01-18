#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Compara os cursos pelo último dia
    bool compareByLastDay(vector<int> course1, vector<int> course2) {
        return course1[1] < course2[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {
        // Ordenar os cursos pelo último dia
        // Ideia similiar ao interval scheduling
        sort(courses.begin(), courses.end(), compareByLastDay);

        
    }
};