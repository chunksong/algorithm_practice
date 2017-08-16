#include <iostream>
#include <vector>
#include <set>
#include <queue>


int main(){

	int iNumOfTestBuilding = 0;
	std::cin >> iNumOfTestBuilding;

	std::vector< std::vector<int> > priority_rule;
	std::vector<int> BuildTime;
	std::vector<int> resultTime;

	for(int iBuildingNum = 0; iBuildingNum < iNumOfTestBuilding; ++iBuildingNum){
		int iTimeForBuild = 0;
		std::cin >> iTimeForBuild;
		BuildTime.push_back(iTimeForBuild); //first element in vector is consuming time

		std::vector<int> readyBuilding;
		int iPriorityNum = 0;
		std::cin >> iPriorityNum;
		while(iPriorityNum != -1){
			readyBuilding.push_back(iPriorityNum);
			std::cin >> iPriorityNum;
		}
		priority_rule.push_back(readyBuilding);		
	}
	
	int Num = 0;
	while(Num < iNumOfTestBuilding){

		int iTotalTime = 0;
		std::set<int> readyBuildingSet;
		std::queue<int> readyQueue;
		std::set<int>::iterator it;

		iTotalTime = BuildTime[Num];
			
		for(int iter_one = 0; iter_one < priority_rule[Num].size(); ++iter_one){
			readyQueue.push(priority_rule[Num][iter_one]);
			readyBuildingSet.insert(priority_rule[Num][iter_one]);
			while(!readyQueue.empty()){
				int buildingNum = readyQueue.front();
				readyQueue.pop();
				for(int i = 0; i < priority_rule[buildingNum].size(); ++i){
					it = readyBuildingSet.find(priority_rule[buildingNum][i]);
					if(it == readyBuildingSet.end()){
						readyQueue.push(priority_rule[buildingNum][i]);
						readyBuildingSet.insert(priority_rule[buildingNum][i]);
					}
				}
				
			}
		}

		for (it = readyBuildingSet.begin(); it != readyBuildingSet.end(); ++it){
			int buildingNum = *it;
			iTotalTime += BuildTime[buildingNum-1];
		}

		resultTime.push_back(iTotalTime);
		// for(int i = 0; i < priority_rule[Num].size(); ++i)
		// 	std::cout << priority_rule[Num][i] << " "; 
		// std::cout << std::endl;
		++Num;
	}

	for(int i = 0; i < iNumOfTestBuilding; ++i)
		std::cout << resultTime[i] << std::endl;

	return 0;
}