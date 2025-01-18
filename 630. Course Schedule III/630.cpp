#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    // Compara os cursos pelo último dia
    static bool compareByLastDay(vector<int>& course1, vector<int>& course2) {
        return course1[1] < course2[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        // Ordenar os cursos pelo último dia
        // Ideia similiar ao interval scheduling
        sort(courses.begin(), courses.end(), compareByLastDay);

        
        int time = 0; // Tempo total acumulado dos cursos selecionados
        priority_queue<int> maxHeap; // Max-heap para armazenar as durações dos cursos selecionados

        // Seleção dos cursos
        for (auto& course : courses) {
            int duration = course[0];
            int deadline = course[1];

            maxHeap.push(duration);
            time += duration;

            // Se o tempo total ultrapassar o prazo, removemos o curso mais longo
            // para liberar tempo e maximizar o número de cursos selecionados.
            if (time > deadline) {
                time -= maxHeap.top();
                maxHeap.pop();
            }
        }
        
        return maxHeap.size();
    }
};