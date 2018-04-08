#include <vector>


#include <fstream>
#include <iostream>

#include "grafo_t.hpp"

using namespace std;

//constructor
grafo_t::grafo_t(char nombrefichero[]) {

  ifstream inFile(nombrefichero);
  elementoLista_T aux;
  int node, dest;

  if (!inFile) cerr << "Error de apertura";

  else {
  
    inFile >> n_;
    inFile >> m_;
    inFile >> dirigido_;

    LS_.resize(n_);
    LP_.resize(n_);

    while ( !inFile.eof() ) {

      //ERROR. El constructor repite el ultimo nodo.
      inFile >> node;
      inFile >> dest;

      aux.j = dest;
      aux.c = 0;

      LS_[node - 1].push_back(aux);

    }
  }
}


void grafo_t::write(void) {

  cout << endl;
  for ( unsigned int row = 0; row < get_nodes(); ++row ) {
    for ( unsigned int col = 0; col < LS_[row].size(); ++col ) {
      cout << row + 1 << " " << LS_[row][col].j << endl;
    }
  }
}
