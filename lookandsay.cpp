// Lookandsay
#include <bits/stdc++.h>
using namespace std;


string lookandsaySequence(string& str)
{
    int counter = 1;
    string result = "";
    
    
    for (int i = 0; i < str.length(); i++) {
        
        if (str[i] != str[i+1]) {
        
            result += counter + '0';
            result += str[i];
            
            counter = 1;
        }
        
        else {
            
            counter++;
         
        }
        
        
    }
    
return result;

}

string lookandsayReflected(string& str) {
    
    string result = "";
    int counter = 0;
    
    for (int i = 0; i < str.length(); i += 2) {
        
        counter = str[i] - '0';
        
        while (counter--) {
            
            result += str[i+1];
        } 
     
        
        
    }
    
return result;
}


// Driver Code
int main(int argc, char** argv)
{
	// Considering inputs given are valid
	string arg = argv[1];
	string str = argv[2];
	
	if (arg == "-l") {
	    cout << lookandsaySequence(str);
	}
	
	if (arg == "-r") {
	    cout << lookandsayReflected(str);
	}
	return 0;
}