//
//  leetcode690_Employee_Importance.cpp
//  PS
//
//  Created by HesSong on 1/23/18.
//  Copyright © 2018 Hes Song. All rights reserved.
//

/*
 You are given a data structure of employee information, which includes the employee's unique id, his importance value and his direct subordinates' id.
 
 For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3. They have importance value 15, 10 and 5, respectively. Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.
 
 Now given the employee information of a company, and an employee id, you need to return the total importance value of this employee and all his subordinates.
 
 Example 1:
 Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
 Output: 11
 Explanation:
 Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3. They both have importance value 3. So the total importance value of employee 1 is 5 + 3 + 3 = 11.
 Note:
 One employee has at most one direct leader and may have several subordinates.
 The maximum number of employees won't exceed 2000.
 */

/*
 // Employee info
 class Employee {
 public:
 // It's the unique ID of each node.
 // unique id of this employee
 int id;
 // the importance value of this employee
 int importance;
 // the id of direct subordinates
 vector<int> subordinates;
 };
 */
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        queue<int> employee_queue;
        employee_queue.push(id);
        
        int result = 0 ;
        
        while(!employee_queue.empty()){
            int id = employee_queue.front();
            employee_queue.pop();
            
            int idx = 0;
            Employee * em = employees[idx];
            while(em->id != id){
                idx += 1;
                em = employees[idx];
            }
            
            result += em->importance;
            for(int i = 0; i < em->subordinates.size(); ++i){
                employee_queue.push(em->subordinates[i]);
            }
        }
        return result;
    }
};
