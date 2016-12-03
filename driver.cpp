//Kirolos Shahat
//driver function implementations
//driver.cpp

#include "driver.h"

using namespace std;

void checkFile(ifstream& input){
  string fileName;
  while(input.fail()){
    cout << "File opening failed. Try again: ";
    cin >> fileName;
    input.open(fileName);
  }
}

void readFile(ifstream& input){

}
