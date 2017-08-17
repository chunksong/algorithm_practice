#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <stack>

int find (std::vector<int> &v, int num){
	if(v[num] == num)	return num;
	else{
		v[num] = find(v,v[num]);
		return v[num];
	}
}

int main(){

	int iKindOfNum = 0;
	int iCalCount = 0;

	scanf("%d %d",&iKindOfNum, &iCalCount);

	std::vector<int> class_of_num;
	class_of_num.reserve(iKindOfNum + 1);
	for(int i = 0; i < iKindOfNum+1; ++i)
		class_of_num.push_back(i);
	// std::vector<std::vector<int> > graph(iKindOfNum + 1);
	// for(int i = 0; i < iKindOfNum + 1; ++i){
	// 	std::vector<int> row(iKindOfNum+1, 0);
	// 	graph[i] = row;
	// }

	while(iCalCount > 0){
		
		int iElementOne = 0;
		int iElementTwo = 0;
		int isUnionOP = 0;
		bool result = false;

		scanf("%d %d %d",&isUnionOP,&iElementOne,&iElementTwo);
		if(isUnionOP == 1){
			if(find(class_of_num,iElementOne) == find(class_of_num,iElementTwo))
				printf("YES\n");
			else
				printf("NO\n");
		}
		else{
			class_of_num[find(class_of_num,iElementOne)] = class_of_num[find(class_of_num,iElementTwo)];
		}

		--iCalCount;
	}
	// while(iCalCount > 0){

	// 	int iElementOne = 0;
	// 	int iElementTwo = 0;
	// 	int isUnion = 0;
	// 	bool result = false;

	// 	scanf("%d %d %d",&isUnion,&iElementOne,&iElementTwo);
	// 	if(isUnion == 1){
	// 		std::stack<int> Stack;
	// 		if(iElementOne != iElementTwo){
	// 			int last_elm = iElementOne;
	// 			for(int iter = 1; iter <= iKindOfNum; ++iter){
	// 				if(graph[last_elm][iter] == 1)
	// 					Stack.push(iter);
	// 			}
	// 			while(!Stack.empty()){
	// 				int front_elm = Stack.top();
	// 				Stack.pop();
	// 				if(front_elm == iElementTwo){
	// 					result = true;
	// 					break;
	// 				}
	// 				for(int iter = front_elm + 1; iter <= iKindOfNum; ++iter){
	// 					if(graph[front_elm][iter] == 1)
	// 						Stack.push(iter);
	// 				}
	// 			}
	// 		}
	// 		else result = true;
	// 		if(result == true) std::cout << "YES" << std::endl;
	// 		else std::cout << "NO" << std::endl;
	// 	}
	// 	else{
	// 		graph[iElementOne][iElementTwo] = 1;
	// 		graph[iElementTwo][iElementOne] = 1;
	// 	}
	// 	--iCalCount;
	// }
	return 0;

}