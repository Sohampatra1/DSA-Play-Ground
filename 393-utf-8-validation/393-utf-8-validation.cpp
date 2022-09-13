class Solution {
public:

    string inttos(int d){
        if(d == 0) return "0";
        string ans;
        while(d > 0){
            ans = (char)((d&1) + '0') + ans;
            d = d>>1; 
        }
        while(ans.length() < 8) ans = '0' + ans;
        return ans;
    }

    bool validUtf8(vector<int>& data) {
        // we have 1
        vector<string> tem;
        for(int i=0;i<data.size();i++){
            // convert str to binary strings
            tem.push_back(inttos(data[i]));
        }
        // now iterate over tem
        int i=0;
        while(i<tem.size()){
           
            string t = tem[i];
            if(t[0] == '0'){
                
            }else if(t.substr(0,3) == "110"){
                
                i++;
                if(i >= tem.size()) return false;
                string t2 = tem[i];
                if(t2.substr(0,2) != "10") return false;
            }else if(t.substr(0,4) == "1110"){
                
                int x = 2;
                i++;
                while(x-- > 0 && i < tem.size()){
                    string t2 = tem[i];
                    if(t2.substr(0,2) != "10") return false;
                    i++;
                }
                if(x > 0) return false;
                i--;
            }else if(t.substr(0,5) == "11110"){
                int x = 3;
                i++;
                while(x-- > 0 && i < tem.size()){
                    string t2 = tem[i];
                    if(t2.substr(0,2) != "10") return false;
                    i++;
                }
                if(x > 0) return false;
                i--;
            }else{
                return false;
            }
            i++;
        }
        return true;
    }
};