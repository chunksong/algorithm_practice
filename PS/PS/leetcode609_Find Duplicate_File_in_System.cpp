//
//  leetcode609_Find Duplicate_File_in_System.cpp
//  PS
//
//  Created by HesSong on 2017. 9. 21..
//  Copyright © 2017년 Hes Song. All rights reserved.
//

/*
 
 Given a list of directory info including directory path, and all the files with contents in this directory, you need to find out all the groups of duplicate files in the file system in terms of their paths.
 
 A group of duplicate files consists of at least two files that have exactly the same content.
 
 A single directory info string in the input list has the following format:
 
 "root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
 
 It means there are n files (f1.txt, f2.txt ... fn.txt with content f1_content, f2_content ... fn_content, respectively) in directory root/d1/d2/.../dm. Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.
 
 The output is a list of group of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:
 
 "directory_path/file_name.txt"
 
 Example 1:
 Input:
 ["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
 Output:
 [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
 Note:
 No order is required for the final output.
 You may assume the directory name, file name and file content only has letters and digits, and the length of file content is in the range of [1,50].
 The number of files given is in the range of [1,20000].
 You may assume no files or directories share the same name in the same directory.
 You may assume each given directory info represents a unique directory. Directory path and file info are separated by a single blank space.
 Follow-up beyond contest:
 Imagine you are given a real file system, how will you search files? DFS or BFS?
 If the file content is very large (GB level), how will you modify your solution?
 If you can only read the file by 1kb each time, how will you modify your solution?
 What is the time complexity of your modified solution? What is the most time-consuming part and memory consuming part of it? How to optimize?
 How to make sure the duplicated files you find are not false positive?

 
 */


class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int InputSize = paths.size();
        vector<vector<string>> result;
        
        vector<string>  fileNameVec;
        vector<string>  fileContentVec;
        set<string>     fileContentSet;
        for(int i = 0; i < InputSize; ++i){
            string path = paths[i];
            string directory;
            string fileName;
            string content;
            int spaceCnt = 0;
            bool contentFlag = false;
            for(int cursor = 0; cursor < path.length(); ++cursor){
                if(path[cursor] == ' '){
                    ++spaceCnt;
                    fileName = "";
                    content = "";
                }
                else if(path[cursor] == '(')    contentFlag = true;
                else if(path[cursor] == ')'){
                    contentFlag = false;
                    fileContentVec.push_back(content);
                    fileContentSet.insert(content);
                    fileNameVec.push_back(directory + "/" + fileName);
                }
                else{
                    if(spaceCnt == 0)   directory += path[cursor];
                    else{
                        if(contentFlag) content += path[cursor];
                        else    fileName += path[cursor];
                    }
                }
            }
        }
        for(auto it = fileContentSet.begin(); it != fileContentSet.end(); ++it){
            vector<string> temp;
            for(int i = 0; i < fileNameVec.size(); ++i){
                if(fileContentVec[i] == *it)    temp.push_back(fileNameVec[i]);
            }
            if(temp.size() > 1)    result.push_back(temp);
        }
        
        return result;
    }
};      //time limit code

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> files;
        vector<vector<string>> result;
        
        for (auto path : paths) {
            stringstream ss(path);
            string root;
            string s;
            getline(ss, root, ' ');
            while (getline(ss, s, ' ')) {
                string fileName = root + '/' + s.substr(0, s.find('('));
                string fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
                files[fileContent].push_back(fileName);
            }
        }
        
        for (auto file : files) {
            if (file.second.size() > 1)
                result.push_back(file.second);
        }
        
        return result;
    }
};
// use unordered map to solve time complexity

