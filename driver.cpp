//Kirolos Shahat
//driver function implementations
//driver.cpp

#include "driver.h"

using namespace std;

//checkFile makes sure that the ifstream parameter that is passed is opened correctly
//and if not then it asks the user for a new fileName to attempt and loops until a file
//is open
void checkFile(ifstream& input){
  string fileName;
  Graph myGraph;
  //loop while the input fail flag is set
  while(input.fail()){
    cout << "File opening failed. Try again: ";
    //read in a fileName from the user and try again
    cin >> fileName;
    input.open(fileName);
  }
}

//readFile takes the graph data from the input file and gets the graph size
//based on the biggest number between the first and second columns in the given
//data file
void readFile(ifstream& input, Graph &myGraph){
  //these are going to be arcs of a graph that are read in
  vector<int> startNode, targetNode, connectionWeight;
  //graphSize will be the highest value node in the list for allocation
  int graphSize = 0, startData, targetData, weightData;
  //while it is possible to read in data from the file
  while(input >> startData){
    //read in the rest of the current line
    input >> targetData >> weightData;
    //get the maximum among the graphSize, startData, and targetData
    graphSize = max(graphSize, max(startData, targetData));
    //push back the data read in into their appropriate vectors
    startNode.push_back(startData);
    targetNode.push_back(targetData);
    connectionWeight.push_back(weightData);
  }
  input.close();
  //myGraph.buildGraph(graphSize, startNode, targetNode, connectionWeight);
}
