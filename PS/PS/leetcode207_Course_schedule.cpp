//
//  leetcode207_Course_schedule.cpp
//  check cycle in undirected graph 
//
//  Created by HesSong on 2017. 10. 9..
//  Copyright © 2017년 Hes Song. All rights reserved.
//

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        bool result = true;
        int sizeOfPre = prerequisites.size();
        vector<vector<int>> graph(numCourses, vector<int>(numCourses, 0));
        vector<int> indegree(numCourses, 0);
        queue<int> Queue;
        
        for(auto iter = 0; iter < sizeOfPre; ++iter){
            pair<int, int> pair_vec = prerequisites[iter];
            graph[pair_vec.first][pair_vec.second] = 1;
            indegree[pair_vec.second] += 1;
        }
        for(auto i = 0; i < numCourses; ++i){
            if(indegree[i] == 0)    Queue.push(i);
        }
        int counter = 0;
        while(!Queue.empty()){
            int front = Queue.front();
            Queue.pop();
            for(auto iter = 0; iter < numCourses; ++iter){
                if(graph[front][iter] == 1){
                    indegree[iter] -= 1;
                    if(indegree[iter] == 0)     Queue.push(iter);
                }
            }
            counter += 1;
        }
        cout << counter;
        if (counter != numCourses) result = false;
        
        return result;
    }
};
