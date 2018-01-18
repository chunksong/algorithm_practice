//
//  leetcode71_Simplify_Path.cpp
//  PS
//
//  Created by HesSong on 1/17/18.
//  Copyright © 2018 Hes Song. All rights reserved.
//

/*
 Given an absolute path for a file (Unix-style), simplify it.
 
 For example,
 path = "/home/", => "/home"
 path = "/a/./b/../../c/", => "/c"
 click to show corner cases.
 
 Corner Cases:
 Did you consider the case where path = "/../"?
 In this case, you should return "/".
 Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 In this case, you should ignore redundant slashes and return "/home/foo".
 */
class Solution {
public:
    string simplifyPath(string path) {
        string result = "";
        size_t found = path.find("/");
        stack<string> str_stack;
        
        while(found != string::npos){
            size_t found_back = path.find("/",found+1);
            string sub_str = path.substr(found+1,found_back-(found+1));
            if(sub_str == ".."){
                if(!str_stack.empty())  str_stack.pop();
            }
            else if(sub_str != "." && sub_str != "")     str_stack.push(sub_str);
            found = found_back;
        }
        while(!str_stack.empty()){
            
            result = "/" + str_stack.top() + result;
            str_stack.pop();
        }
        if(result == "")    result = "/";
        
        return result;
    }
};
