//
//  leetcode692_Top_K_Frequent_Words.cpp
//  useing map
//
//  Created by HesSong on 2017. 10. 27..
//  Copyright © 2017년 Hes Song. All rights reserved.
//
/*
 
 Given a non-empty list of words, return the k most frequent elements.
 
 Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
 
 Example 1:
 Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 Output: ["i", "love"]
 Explanation: "i" and "love" are the two most frequent words.
 Note that "i" comes before "love" due to a lower alphabetical order.
 Example 2:
 Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
 Output: ["the", "is", "sunny", "day"]
 Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
 with the number of occurrence being 4, 3, 2 and 1 respectively.
 Note:
 You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 Input words contain only lowercase letters.

 */
class Solution {
    public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> dic;
        vector<string> result;
        
        int words_size = words.size();
        
        for(auto i = 0; i < words_size; ++i){
            if(!dic[words[i]])      dic[words[i]] = 1;
            else                    dic[words[i]] += 1;
        }
        
        vector<int> number_cnt(words_size,0);
        for(auto it = dic.begin(); it != dic.end(); ++it){
            number_cnt[it->second] += 1;
        }
        
        int cnt = 0;
        for(auto i = words_size - 1; i > 0; --i){
            if(number_cnt[i] != 0){
                for(auto it = dic.begin(); it != dic.end(); ++it){
                    if(it->second == i){
                        result.push_back(it->first);
                        ++cnt;
                        if (cnt == k)       break;
                    }
                    
                }
                if (cnt == k)       break;
            }
            
        }
        
        return result;
    }
};
