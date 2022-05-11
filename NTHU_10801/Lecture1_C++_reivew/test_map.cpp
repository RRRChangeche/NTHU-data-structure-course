#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    string p = "abc";
    string s = "cbaebabacd";
    map<char, int> pmap, smap;
    // vector<int> pmap(26), smap(26);
    int l = p.length();
    vector<int> ans;
    
    // store all letters in p 
    for (char c : p) pmap[c]++;
    
    // for loop s
    for (int i=0; i<s.length(); i++){
        smap[s[i]]++;
        if (i>=l) smap.erase(s[i-l]);
        if (pmap == smap) ans.push_back(i-l+1);
    }
    
    return 0;
}