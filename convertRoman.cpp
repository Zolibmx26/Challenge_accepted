// Program to convert Roman Numerals to Numbers and vice versa

#include <bits/stdc++.h>
using namespace std;

// This function returns value
// of a Roman symbol
int value(char r)
{
	if (r == 'I')
		return 1;
	if (r == 'V')
		return 5;
	if (r == 'X')
		return 10;
	if (r == 'L')
		return 50;
	if (r == 'C')
		return 100;
	if (r == 'D')
		return 500;
	if (r == 'M')
		return 1000;
    
	return -1;
}

// Returns decimal value of
// roman numaral
int romanToDecimal(string& str)
{
	// Initialize result
	int res = 0;
	
	//Initialize counter
	int counter = 0;
	int count_V = 0;
	int count_L = 0;
	int count_D = 0;

	// Traverse given input
	for (int i = 0; i < str.length(); i++) {
		// Getting value of symbol s[i]
		int s1 = value(str[i]);
		
		// Countin V, L and D appearence
		if(s1 == 5){
		    count_V++;
		}
		
		if(s1 == 50){
		    count_L++;
		}
		
		if(s1 == 500){
		    count_D++;
		}
		
		//Exception in case of multiple V, L or D
		if ((count_V > 1) || (count_L > 1) || (count_D > 1)) {
		    cout << "Invalid data ";
		    return 0;
		}
	
		//Exception if more than 3 consecutive of the same type
		if (counter > 2){
		    cout << "Invalid - More than 3 consecutive ";
		    return 0;
		}
        
        
		if (i + 1 < str.length()) {
			// Getting value of symbol s[i+1]
			int s2 = value(str[i + 1]);
            
            // Comparing both values
            if (s1 >= s2) {
				// Value of current symbol
				// is equal to or greater than
				// the next symbol
				res = res + s1;
				
				if (s1 == s2) {
				    counter++;
				}
				
				if (s1 > s2) {
				    counter = 0;
				}
				
            }
				
			else {
				// Value of current symbol is
				// less than the next symbol
				
				// Exception if value of current symbol is more than 10 times smaller than the next
				if (s2 - s1*10 > 0){
                    cout << "Invalid data ";
                    return 0;
		        }
				
				res = res + s2 - s1;
				i++;
			}
		}
		else {
			res = res + s1;
		}
	}
	return res;
}


string decimalToRoman(int n) {

    string str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string result = "";

    for (int i = 0; i < 13; i++)
        {
            while(n - values[i] >= 0)
            {
                result += str_romans[i];
                n -= values[i];
            }
        }

    return result;
}

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

// Driver Code
int main(int argc, char** argv)
{
	
	
	string str = argv[1];
	int decimal = 0;
	
	if (is_number(str)) {
	    decimal = stoi(str);
	    //cout << "Roman form of Decimal Numeral is " << 
	    cout << decimalToRoman(decimal) << endl;
	    
	}
	else {
	    //cout << "Decimal form of Roman Numeral is " << 
	    cout << romanToDecimal(str) << endl;
	}

	return 0;
}