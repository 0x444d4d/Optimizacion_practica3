#include <vector>
#include <fstream>

#include "grafo_t.hpp"

//constructor
grafo_t::grafo_t(char nombrefichero[], int &errorapertura) {

  ifstream inFile(nombrefichero);
  int node, dest;
  unsigned int size = 0;
  vector auxnode, auxdest;

  inFile >> n_;
  inFile >> m_;
  inFile >> dirigido_;
  
  LS_.resize(n_);
  LP_.resize(n_);

  while ( !inFile.eof() ) {
    cin >> node;
    cin >> dest;

    ++size;

    auxnode.resize(size, node);
    auxdest.resize(size, dest);
  }

  for ( unsigned int index = 1; index <= auxnode.size() ; ++i ) {
  }
}

