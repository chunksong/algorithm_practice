//
//  baekjoon_1753.cpp
//  최단경로 찾기 shortest path algorithm
//
//  Created by Hes Song on 8/18/17.
//  Copyright © 2017 Hes Song. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <functional>

#define MAX_INT (2147483647 >> 1)

int main(int argc, const char * argv[]) {
    
    int iVertexCnt;
    int iEdgeCnt;
    int iStartVertex;
    scanf("%d %d %d",&iVertexCnt, &iEdgeCnt, &iStartVertex);
    
//    std::vector<std::vector<int>> graph;
    std::vector<std::vector<std::pair<int,int>>> graph(iVertexCnt+1);
//    std::set<int> set_vertex;
    std::vector<bool> check_list(iVertexCnt+1,false);
    std::vector<int> path(iVertexCnt+1,MAX_INT);
    
    
    // need to modify to solve memory control
    // transform to adjacency matrix
    for(int i = 1; i <= iVertexCnt; ++i){
//        std::vector<int> row(iVertexCnt+1 , 0);
//        graph.push_back(row);
        graph[i].push_back(std::make_pair(i,0));
    }
    
    for(int i = 1; i <= iEdgeCnt; ++i){
        int StartPnt;
        int EndPnt;
        int Weight;
        
        scanf("%d %d %d",&StartPnt,&EndPnt,&Weight);
        graph[StartPnt].push_back(std::make_pair(EndPnt,Weight));
    }
//        if(graph[StartPnt][EndPnt] == 0)
//            graph[StartPnt][EndPnt] = Weight;
//        else
//            graph[StartPnt][EndPnt] = graph[StartPnt][EndPnt] > Weight ? Weight : graph[StartPnt][EndPnt];
//    }
    
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> readyQueue;
    
        readyQueue.push(std::make_pair(0,iStartVertex));
        path[iStartVertex] = 0;
    
        while(!readyQueue.empty()){
            int start_pnt = readyQueue.top().second;
            readyQueue.pop();
//            set_vertex.erase(start_pnt);
            if(check_list[start_pnt]) continue;
            else check_list[start_pnt] = true;
            
            int minimum_weight = path[start_pnt];
            
            for(int i = 0; i < graph[start_pnt].size(); ++i){
                int dst_vertex = graph[start_pnt][i].first;
                int weight = graph[start_pnt][i].second;
                
                if(!check_list[dst_vertex] && path[dst_vertex] > minimum_weight + weight){
                    path[dst_vertex] = minimum_weight + weight;
                    readyQueue.push(std::make_pair(path[dst_vertex], dst_vertex));
                }

            }
        }
//        for(int vertex = 1; vertex <= iVertexCnt; ++vertex)
//            if(graph[start_pnt][vertex] != 0){
//                if(set_vertex.find(vertex) == set_vertex.end()) readyQueue.push(vertex);
//                if(path[vertex] == -1) path[vertex] =  path[start_pnt] + graph[start_pnt][vertex];
//                path[vertex] = path[vertex] < minimum_weight + graph[start_pnt][vertex] ? path[vertex] : minimum_weight + graph[start_pnt][vertex];
//            }
    for(int i = 1; i <= iVertexCnt; ++i){
        if(check_list[i])   printf("%d\n", path[i]);
        else    printf("INF\n");
    }
   
    return 0;
}
