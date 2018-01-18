//
//  leetcode383_Ransom_Note.cpp
//  PS
//
//  Created by HesSong on 1/15/18.
//  Copyright © 2018 Hes Song. All rights reserved.
//

/*
 
 Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
 
 Each letter in the magazine string can only be used once in your ransom note.
 
 Note:
 You may assume that both strings contain only lowercase letters.
 
 canConstruct("a", "b") -> false
 canConstruct("aa", "ab") -> false
 canConstruct("aa", "aab") -> true

 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len_ransomNote = ransomNote.length();
        int len_magazine = magazine.length();
        vector<int> alphabet(27,0);
        for(int idx = 0; idx < len_magazine; ++idx){
            alphabet[magazine[idx]-'a'+1]++;
        }
        for(int idx = 0; idx < len_ransomNote; ++idx){
            alphabet[ransomNote[idx]-'a'+1]--;
            if(alphabet[ransomNote[idx]-'a'+1] < 0)    return false;
        }
        return true;
    }
};
