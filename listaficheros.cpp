#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

//#define DEBUGGING


using namespace std;

int main(void) {
  int inx = 0;
  size_t pos;
  ifstream inFile;
  vector<string> fileVector;

  system("ls > filelist.txt");
  inFile.open("filelist.txt");

  string aux;
  while (inFile >> aux)
  {
    #ifdef DEBUGGING 
    pos = aux.find_last_of('.');
    std::cout << pos << std::endl;
    #endif
    
    #ifndef DEBUGGING
    pos = aux.find_last_of('.');
    if ( pos != string::npos )
      if (aux.substr( pos ) == ".gr")
        fileVector.push_back( aux );
    
    #endif
  }
  while (inx < fileVector.size()) {
    for (int len = 0; len < 4 && len < fileVector.size(); ++len) {
      std::cout << fileVector[inx] << " ";
      ++inx;
    }
    std::cout << std::endl;
  }   

  return 0;
}
