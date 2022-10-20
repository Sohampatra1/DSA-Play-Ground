class Solution {
public:
    string intToRoman(int num) 
    {
        string *vec=new string[13]{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int *val=new int[13]{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string str="";
        for(int i=0;i<13;++i)
        {
            while(num>=val[i])
            {
               str+=vec[i];
               num-=val[i];
            }
        }
        return str;
    }
};