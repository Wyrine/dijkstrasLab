//Kirolos Shahat
//implementing dijkstra's algorithm on graph data provided by the user
//main.cpp

#include "driver.h"

using namespace std;

int main(){
  //opening a file with the string constant
  ifstream input(FILENAME);
  //defining a graph that should be fully loaded
  //once it goes through the readFile function
  Graph myGraph;
  //checking that the file opened properly
  checkFile(input);
  //reading in the data from the file and initializing the graph
  readFile(input, myGraph);
  myGraph.print();
}
