// Game of life
#include <bits/stdc++.h>
using namespace std;


// Driver Code
int main(int argc, char** argv)
{
	// Considering inputs given are valid
	
	int gen = atoi(argv[1]);
	int horizontal = atoi(argv[2]);
	int vertical = atoi(argv[3]);
    
    int coordinates[100][2];
	char grid_gen1[100][100];
	char grid_next_gen[100][100];
	
	for (int i = 0; i < vertical; i++) {

        for (int j = 0; j < horizontal; j++) {
	        
	        grid_gen1[i][j] = '.';
	        grid_next_gen[i][j] = '.';
	        
        }
	}
	
	string str;
	
	for (int i = 4; i < argc; i++) {
	    
	    str = argv[i];
	    coordinates[i-4][0] = str[0] - '0';
	    coordinates[i-4][1] = str[2] - '0';
	    
	
	}
	
	for (int i = 0; i < argc-4; i++) {
	    
	    grid_gen1[coordinates[i][1]][coordinates[i][0]] = 'X';
	    grid_next_gen[coordinates[i][1]][coordinates[i][0]] = 'X';

	}
	
	/*
	for (int i = 0; i < vertical; i++) {
	    
	    for (int j = 0; j < horizontal; j++) {
	        
	        cout << grid_gen1[i][j] << " ";
	        
	   }
	   cout << endl;
	}
	*/
	
	
	int counter = 0;
	
for(int k = 1; k < gen; k++) {
	
	for (int i = 0; i < vertical; i++) {
	    
	    for (int j = 0; j < horizontal; j++) {
	            
	            if (grid_gen1[i][j+1] == 'X') {
	                
                    counter++;	                 
	            }
	            
	            if (grid_gen1[i][j-1] == 'X') {
	                
                    counter++;	                 
	            }
	            
	            if (grid_gen1[i+1][j] == 'X') {
	                
                    counter++;	                 
	            }
	            
	            if (grid_gen1[i-1][j] == 'X') {
	                
                    counter++;	                 
	            }
	            
	            if (grid_gen1[i-1][j-1] == 'X') {
	                
                    counter++;	                 
	            }
	            
	            if (grid_gen1[i-1][j+1] == 'X') {
	                
                    counter++;	                 
	            }
	            
	            if (grid_gen1[i+1][j-1] == 'X') {
	                
                    counter++;	                 
	            }
	            
	            if (grid_gen1[i+1][j+1] == 'X') {
	                
                    counter++;	                 
	            }
	            
	            
	            //Underpopulation or overpopulation
	            if ((grid_gen1[i][j] == 'X') && ((counter < 2) || (counter > 3))) {
	            
                    grid_next_gen[i][j] = '.';
    	            
                }
                
                if ((grid_gen1[i][j] == '.') && (counter == 3)) {
	            
                    grid_next_gen[i][j] = 'X';
    	            
                }
        counter = 0;
	        
	   }
	
	}
	
memcpy(grid_gen1, grid_next_gen, sizeof(grid_gen1));

}
	
	for (int i = 0; i < vertical; i++) {
	    
	    for (int j = 0; j < horizontal; j++) {
	        
	        cout << grid_next_gen[i][j] << " ";
	        
	   }
	   cout << endl;
	}
    
    
	
	return 0;
}