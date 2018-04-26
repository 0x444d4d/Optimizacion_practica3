#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

int main(void) {
  int inx = 0;
  ifstream inFile;
  vector<string> fileVector;

  //system("ls *.gr");
  system("ls > filelist.txt");
  inFile.open("filelist.txt");

  string aux;
  while (inFile >> aux)
    if (aux.substr(aux.find_last_of(".")) == ".gr")
      fileVector.push_back(aux);

  while (inx < fileVector.size()) {
    for (int len = 0; len < 4 && len < fileVector.size(); ++len) {
      cout << fileVector[inx] << " ";
      ++inx;
    }
    cout << endl;
  }   

  return 0;
}
