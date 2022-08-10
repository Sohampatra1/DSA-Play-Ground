class Solution {
public:
	int strStr(string haystack, string needle) {
		if(needle == ""){
			return 0;
		}
		int i = 0, j = 0, k = 0;
		while(i < haystack.size() && j < needle.size() && k < haystack.size()){   
			if(haystack[k] == needle[j]){
				j++;
				k++;
			}
			else{
				j = 0;
				i++;
				k = i; 
			}
		}
		if(j == needle.size()){
			return i;
		}
		return -1;
	}
};
