#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// https://algo.monster/problems/amazon-oa-unique-character


int get_unique_character(std::string& s) {
    unordered_map<char, vector<int>> freq;
    for(int i = 0; i < s.size(); i++)
        freq[s[i]].push_back(i);
    
    int mini = INT_MAX;
    for(auto &[ch, vec] : freq){
       if(vec.size() == 1)
           mini = min(mini, vec[0]);
    }
    if(mini == INT_MAX)
        return -1;
    
    return mini + 1;
}