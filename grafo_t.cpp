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

    cout << dirigido_;

    LS_.resize(n_);
    LP_.resize(n_);

    while ( !inFile.eof() ) {

      inFile >> node;
      inFile >> dest;

      aux.j = node;
      aux.c = 0;

      LS_[node - 1].push_back(aux);

    }
  }
}

