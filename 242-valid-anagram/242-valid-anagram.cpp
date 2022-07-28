class Solution {
public:
bool isAnagram(string a, string b) {

  unordered_map<char,int> mymap;
     
   if(a.size()!=b.size()) 
        return false;
 
    
         for(int i =0;i<a.size();i++)
  {
      mymap[a[i]]++;
      mymap[b[i]]--;
       }
 
    for(auto i:mymap)
  {
    
       if(i.second!=0)
        return false;
  
   
   }
  return true;
    }
};
