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
    //read in a fileName from the user
    cin >> fileName;
    //try to open
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
  //finished reading from the file. Closing the file
  input.close();
  //call the buildRelation to create load the myGraph instance with the data
  myGraph.buildRelation(graphSize, startNode, targetNode, connectionWeight);
}

//mainMenu Asks the user if they would like to view the shortest path from one
//node to another or not
void mainMenu(Graph myGraph){
  char choice;
  int startNode, targetNode;
  do{
    //Asking the user if they would like to get the shortest path
    cout << "Would you like to find the shortest path between two nodes (y/n)? ";
    cin >> choice;
    //if the user wants to get the shortest path
    if(choice == 'y' || choice == 'Y'){
      cout << "Which node would you like to be the start node? ";
      cin >> startNode;
      cout << "Which node would you like to be the target node? ";
      cin >> targetNode;
      //finding the shortest path between the two nodes
      //myGraph.shortestPath(startNode, targetNode);
    }
  //loop while the user wanted to see a shortest path
  }while(choice == 'y' || choice == 'Y');
  //thanking the user
  cout << "Thank you for using this program! Goodbye!\n";
}
