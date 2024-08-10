#include <bits/stdc++.h>
#define ll long long 
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end()); 
        vector<vector<string>>result;
        string currentPrefix = "";
        for(auto&c : searchWord){
            currentPrefix+=c; // Build the prefix incrementally
            vector<string> suggestions;
            //  Use lower_bound to find the first product that is not less than the current prefix
            auto it = lower_bound(products.begin(), products.end(), currentPrefix);
            // Collect up to three valid suggestions
            int i = 0;
        while(i < 3 && it != products.end() && it->substr(0, currentPrefix.size()) == currentPrefix){
            suggestions.push_back(*it);
            ++i;
            ++it;
        }
            result.push_back(suggestions);
        }
        
        return result;
    }
};
