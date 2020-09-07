/* QUESTION: Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string>s;
        string st="";
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==' ')
            {
                s.push_back(st);
                st="";
                
            }
            else
                st+=str[i];
        }
        if(st!="")
            s.push_back(st);
        if(pattern.size()!=s.size())
            return false;
        map<string,vector<int> > ms;
        map<char,vector<int> > mt;
         for(int i=0;i<s.size();i++)
        {
            ms[s[i]].push_back(i);
            mt[pattern[i]].push_back(i);
            
        }
        for(int i=0;i<s.size();i++)
        {
            if(ms[s[i]]!=mt[pattern[i]])return false;
        }
        return true;
    }
};
