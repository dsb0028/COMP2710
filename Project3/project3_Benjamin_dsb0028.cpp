//============================================================================
// Name        : project3_Benjamin_dsb0028.cpp
// Author      : Daniel Benjamin
// AU UserID   : dsb0028
// Description : COMP2710 Software Construction Project 3
// Compile     : g++ project3_Benjamin_dsb0028.cpp -o Project3.out
// Run         : ./Project3.out
// Help			: 
//============================================================================



#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
     
string filename;  

int readfile (int inputArray[], ifstream &instream) {
   int index = 0;
   if (instream.fail()) {
      cout << "Input file won't open." << endl;
      exit(1);
   }
   instream >> inputArray[index];
   while (!instream.eof()) { 
      index = index + 1; 
      instream >> inputArray[index]; 
   }          
   return index;
}

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
   int outputArray_size = inputArray1_size + inputArray2_size;
   int i = 0; //counter for inputArray1
   int j = 0; //counter for inputArray2
   int k = 0; //counter for outputArray
   
   for (int l = 0; l < outputArray_size; l++) {
   
      if (j < inputArray2_size)  {
         if (inputArray1[i] <= inputArray2[j]) {
            outputArray[k++] = inputArray1[i++];
         }
         
         else {
            outputArray[k++] = inputArray2[j++];
         }  
      } 
      
              
      else  {
         outputArray[k++] = inputArray1[i];
         i++;
      }
   
   } 
   
   
   
   return outputArray_size;
}

void writefile(int outputArray[], int outputArray_size) {
   ofstream outputFile;  
   outputFile.open((char*)filename.c_str());
   if (!outputFile.is_open()) {
   
      cout << " problem with opening the file" << endl;
      
   }
   
   else {
   
      for (int i = 0; i < outputArray_size; i++) {
         outputFile << outputArray[i] << endl;
      }
    
      outputFile.close();
   }

   
}
   

int main() {
   const int MAX_SIZE = 100;
   int inputArray2[MAX_SIZE];
   int inputArray1[MAX_SIZE];
   int inputArray1_size;
   int inputArray2_size;
   int outputArray[MAX_SIZE];

   ifstream file1, file2;
   cout << "***Welcome to Daniel's sorting program***\n" 
      << "Enter the first input file name: ";
   

   cin >> filename;
   file1.open((char*)filename.c_str());
   inputArray1_size = readfile(inputArray1, file1);

   cout << "The list of " << inputArray1_size << " numbers in file " << filename << " is:\n";
   for(int i = 0; i < inputArray1_size; i++) {
      cout << inputArray1[i] << endl;
   }
   file1.close();
   
   
   cout << "\nEnter the second input file name: ";
   
   cin >> filename;
   
   file2.open((char*)filename.c_str());
   inputArray2_size = readfile(inputArray2, file2);

   cout << "The list of " << inputArray2_size << " numbers in file " << filename << " is:\n";
   for(int i = 0; i < inputArray2_size; i++) {
      cout << inputArray2[i] << endl;
   }
   file2.close();
 
   int outputArray_size = sort(inputArray1, inputArray1_size, inputArray2, inputArray2_size, outputArray);
   cout << "\nThe sorted list of " << outputArray_size  << " numbers is: "; 
   for(int i = 0; i < outputArray_size; i++) {
      cout << outputArray[i] << " ";
   }
   
   cout << endl;
   
   cout << "Enter the output file name: ";
   
   cin >> filename;
   
   writefile(outputArray, outputArray_size);
   
   cout << "*** Please check the new file - " << filename << " ***" << endl;
   cout << "*** Goodbye. ***" << endl;
   
   return 0;
}