#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int dimension[2];
    ifstream inFile; 
	inFile.open("rosalind_2sum.txt");
	
	// open the file to capture the dimensions of the matrix to put it in the array
	if (inFile.is_open())
    {
        for (int i = 0; i < 2; i++) // the dimensions of the dataset is on the top of the file
        {
            inFile >> dimension[i]; // get the dimensions for the array file
        }

        inFile.close();
    }
    else { 
        cerr << "Can't open the file!" << endl;
    }
    
    inFile.open("rosalind_2sum.txt"); //open the file again to read the data into matrix
    int matrix[dimension[0]][dimension[1]];
    int l;
    int n = 0;
    if (inFile.is_open()){
        for (int i=0;i<dimension[0];++i){
            for (int j=0;j<dimension[1];++j){
                while (n < 2){
                    inFile >> l;
                    n++;
                }
                inFile >> matrix[i][j];
                 
            }
        }
        
        inFile.close();
    }else { 
        cerr << "Can't open the file!" << endl;
    }
    
 /*    //use this loop to print out the matrix
    for (int i=0;i<dimension[0];i++){
        for (int j=0;j<dimension[1];j++){
            cout << matrix[i][j];
        }
        
        cout << endl;
    } */
    
    
    
    int flag=0; // used this flag to print -1
    
    inFile.open("rosalind_2sum.txt"); //open the file to print the result
    if (inFile.is_open()) //we open the file again
    {
        // loop goes through matrix and prints out the indices if A[p] = -A[q] and if not then it prints -1   
        for (int i=0;i<dimension[0];++i){ 
            for (int j=0;j<dimension[1];++j){
                for (int k=j+1;k<dimension[1];++k){
                    if(matrix[i][j]+matrix[i][k]==0){
                        cout << "Array no: " << i << " | " << j+1 << " " << k+1 << endl;
                        flag=1; 
                    }
                    
                
                
                }
            }
            
            if (flag==0){
                cout << -1 << endl;    
            }
            
            flag = 0;
            
        }
        

        inFile.close();
    }
    else { 
        cerr << "Can't open the file!" << endl;
    }
    

    
	
	//int arr[] = {2,-3,4,10,5,8,2,4,-2,-8,-5,2,3,2,-4,5,4,-5,6,8};
    //int arr_size = sizeof(arr)/sizeof(int);
	
	
	
	
 

    return 0;
}
 
