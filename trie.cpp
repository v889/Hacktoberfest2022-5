#include<bits/stdc++.h>
using namespace std;
class TrieNode{
 public:
   char data;
   TrieNode *children[26];
    bool isterminal;
    TrieNode(char d){
        data=d;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isterminal=false;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode('\0');
    }
    void insert(TrieNode* root,string word){
        if(word.length()==0){
            root->isterminal=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
    insert(child, word.substr(1));

    }
bool searchUtil(TrieNode* root,string word){
    if(word.length()==0){
        return root->isterminal;
        }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
           return false;
        }
        return searchUtil(child, word.substr(1));
}
 bool search(string word) {
return  searchUtil(root, word);
    }
    bool prefixUtil(TrieNode *root, string word)
{
  if(word.length()==0)
  {
    return true;
  }
  int index=word[0]-'a';
  TrieNode* child;
  // present
  if(root->children[index]!=NULL)
  {
    child=root->children[index];
  }
  else{
    return false;
  }
  // Recursion
  return prefixUtil(child, word.substr(1));
}
    bool startsWith(string prefix) {
  return prefixUtil(root,prefix);
    }
};

int main(){
     TrieNode* root=new TrieNode('\0');
     Trie* t;
     int n;
     cin>>n;
    for(int i=0;i<n;i++){
        string res;
        cin>>res;
        t->insert(root,res);
    }
    cout<<t->searchUtil(root,"shivam")<<endl;
    cout<<t->prefixUtil(root,"viv")<<endl;
}