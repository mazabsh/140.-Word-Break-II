#include<iostream> 
#include<vector> 
#include<set> 
#include<string>

using namespace std; 

class Solution{
public: 
      void backtrack(const string& s, const set<string>& wordSet, vector<string>& res, string& currentSentence, int indx){
        int n = s.size(); 
        if(indx==n) {
           res.push_back(currentSentence); 
           return; 
        }
        for(int i=indx+1; i<=n; ++i){
            string word = s.substr(indx, i-indx); 
            if(wordSet.count(word)){
              string origin = currentSentence; 
              if(!currentSentence.empty()) currentSentence+=" "; 
              currentSentence +=word; 
              backtrack(s, wordSet, res, currentSentence, i);
              currentSentence = origin; 
            }
            
            
        }
      }
      vector<string> wordBreak(string& s, vector<string>& wordDict){
        vector<string> res; 
        set<string> wordSet(wordDict.begin(),wordDict.end()); 
        string currentSentence; 
        backtrack(s, wordSet, res, currentSentence,0); 
        return res; 
      }
};
int main(){
  string s = "catsanddog";
  vector<string> wordDict={"cats", "dog", "sand", "and", "cat"};
  Solution sol; 
  vector<string> res = sol.wordBreak(s, wordDict); 
  for(string sent:res){
    cout << sent << endl;
  }
  return 0; 
}
