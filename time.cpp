class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        
        bool invalid = true;
        bool second_max = false;
        std::vector<int>::iterator it; 
        vector<int> arr_copy; 
        string time = "";
        arr_copy = arr;
        
        for(int i = 2; i >= 0; i--){
            it = std::find (arr_copy.begin(), arr_copy.end(), i);
            if (it != arr_copy.end()){
                if( i == 2 )
                    second_max = true;
                time+= std::to_string(i);
                arr_copy.erase(it);
                invalid = false;
                break;
            }
        }
        
        if(invalid)
            return "";
        
        if(!second_max){
            for(int i = 9; i >= 0; i--){
            it = std::find (arr_copy.begin(), arr_copy.end(), i);
            if (it != arr_copy.end()){
                time+= std::to_string(i);
                arr_copy.erase(it);
                break;
            }
        }
        invalid = false;
            
        } else{
            
         invalid = true; 
         for(int i = 3; i >= 0; i--){
            it = std::find (arr_copy.begin(), arr_copy.end(), i);
            if (it != arr_copy.end()){
                time+= std::to_string(i);
                arr_copy.erase(it);
                invalid = false;
                break;
            }
        }
            
        }
        
        if(invalid)
            return "";
        invalid = true; 
        time+=":";
        
        for(int i = 5; i >= 0; i--){
            it = std::find (arr_copy.begin(), arr_copy.end(), i);
            if (it != arr_copy.end()){
                time+= std::to_string(i);
                arr_copy.erase(it);
                invalid = false;
                break;
            }
        }
        
        if(invalid)
            return "";
        
        time+= std::to_string(arr_copy[0]);
        
        
        return time;
        
    }
};
