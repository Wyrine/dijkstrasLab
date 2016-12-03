//Kirolos Shahat
//prototypes and header files for the driver
//driver.h

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "graph.h"

//creating a constant that is the file name with the graph data
const std::string FILENAME = "graphdata.txt";


//prototypes for functions
void checkFile(std::ifstream& input);
void readFile(std::ifstream& input, Graph &myGraph);
void mainMenu(Graph myGraph);
