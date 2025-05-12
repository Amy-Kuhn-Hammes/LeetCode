#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cstdint>
using std::vector;



class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        uint8_t matrix[2001][2001] = {0};
        int dependences[2001] = {0}, i;
        vector<int> ans, queue;
        ans.reserve(numCourses);
        queue.reserve(numCourses);

        for(i = 0; i < prerequisites.size(); i++) {
            matrix[prerequisites[i][1]][prerequisites[i][0]] = 1;
            dependences[prerequisites[i][0]]++;
        }   

        for(i = 0; i < numCourses; i++) {
            if(!dependences[i]) {
                queue.push_back(i);
            } 
        }

        while(!queue.empty()) {
            ans.push_back(queue[0]);
            for(i = 0; i < numCourses; i++) {
                if(matrix[queue[0]][i]) {
                    dependences[i]--;
                    if(!dependences[i]) {
                        queue.push_back(i);
                    }
                }
            }
            queue.erase(queue.begin(), queue.begin()+1);
        }

        if(numCourses - ans.size()) {
            return queue;
        } 
        
        return ans;
    }
};