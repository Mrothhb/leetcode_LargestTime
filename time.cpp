class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        
        string str = "";
        
        for(int i = 0; i<arr.size(); i++){
            str+=to_string(arr[i]);
        }
 
    return permute(str);
    }
    
    // Function to print permutations of string str 
// using next_permutation 
string permute(string str) 
{ 
    vector<string> strings;
    vector<string> finals;
    vector<int> numbers;
    int tempInt = 0;
    string newStr = "";
    std::string finalstr= str;
    // Sort the string in lexicographically 
    // ascennding order 
    sort(str.begin(), str.end()); 
  
    // Keep printing next permutation while there 
    // is next permutation 
    do { 
      // cout << str << endl;
        strings.push_back(str);
    } while (next_permutation(str.begin(), str.end())); 
    
    for(int i = 0; i<strings.size();i++){
        
        if(strings[i][0] > 50){
            continue;
        }
        if(strings[i][2] > 53){
            continue;
        }
        if(strings[i][0] == 50 && strings[i][1] > 51){
            continue;
        }
        finals.push_back(strings[i]);
    }
    
    if(finals.size() == 0){
        return "";
    }
   for( int i = 0; i< finals.size();i++){
    stringstream str(finals[i]); 
    str >> tempInt;
    numbers.push_back(tempInt);  
   }
    tempInt = *std::max_element(numbers.begin(),numbers.end());
    finalstr = to_string(tempInt);
    
    while(finalstr.length() < 4){
        finalstr.insert(0,"0");
    }
    for( int i = 0; i<4;i++){
        newStr+=finalstr[i];
        if(i==1){ newStr+=":";}
    }
    return newStr;
} 
};
