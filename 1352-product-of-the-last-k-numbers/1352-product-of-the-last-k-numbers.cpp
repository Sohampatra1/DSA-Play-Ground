class ProductOfNumbers {
public:
    
    vector<int>v;
    
    ProductOfNumbers() {
        v.push_back(1);
    }
    
    void add(int num) {
        if(num!=0)
        {
             v.push_back(v[v.size()-1]*num);
        }
        else
        {
            v.clear();
            v.push_back(1);
        }
       
    }
    
    int getProduct(int k) {
      
        if(v.size()<=k)
            return 0;
        
        else
            return v[v.size()-1]/v[v.size()-k-1];
        
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */