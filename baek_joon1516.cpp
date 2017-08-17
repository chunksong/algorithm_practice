#include <iostream>
#include <vector>
#include <set>
#include <queue>


int main(){

	int iNumOfTestBuilding = 0;
	std::cin >> iNumOfTestBuilding;

	std::vector<std::vector<int> > priority_rule;
	std::vector<int> readyCount;
	std::vector<int> BuildTime;
	std::vector<int> resultTime;
	std::set<int> remainDest;

	for(int iBuildingNum = 0; iBuildingNum < iNumOfTestBuilding; ++iBuildingNum){
		//insert building number to remainDest
		remainDest.insert(iBuildingNum);

		// get building consuming time
		int iTimeForBuild = 0;
		std::cin >> iTimeForBuild;
		BuildTime.push_back(iTimeForBuild);
		
		// get ready time to 2D matrix  
		std::vector<int> readyBuilding(iNumOfTestBuilding,0);
		int iPriorityNum = 0;
		int iReadyCount = 0;

		std::cin >> iPriorityNum;
		while(iPriorityNum != -1){
			++iReadyCount;
			readyBuilding[iPriorityNum - 1] = 1;
			std::cin >> iPriorityNum;
		}
		readyCount.push_back(iReadyCount);
		priority_rule.push_back(readyBuilding);		
	}
	
	int startNum = 0;
	int currentCount = readyCount[0];
	for(int iter = 0; iter < iNumOfTestBuilding; ++iter){
		if(readyCount[iter] < currentCount){
			currentCount = readyCount[iter];
			startNum = iter;
		} 
	}
	
	while(!remainDest.empty()){

		int iTotalTime = 0;
		remainDest.erase(startNum);
		iTotalTime += BuildTime[startNum];

		for(int i = 0 ; i < iNumOfTestBuilding ; ++i)
			if(priority_rule[startNum][i])
				iTotalTime += BuildTime[i];

		for(int row = 0; row < iNumOfTestBuilding; ++row)
			priority_rule[row][startNum] = 0;

		resultTime[startNum] = iTotalTime;

		
		// for(int i = 0; i < priority_rule[Num].size(); ++i)
		// 	std::cout << priority_rule[Num][i] << " "; 
		// std::cout << std::endl;
	}

	for(int i = 0; i < iNumOfTestBuilding; ++i)
		std::cout << BuildTime[i] << std::endl;

	return 0;
}