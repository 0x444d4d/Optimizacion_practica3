
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

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
      //Es posible que sea un error de grafo::write().
      inFile >> node;
      inFile >> dest;

      aux.j = (dest - 1);
      aux.c = 0;

      LS_[node - 1].push_back(aux);
    }
  }

}


void grafo_t::write(void) {

  for ( unsigned int row = 0; row < get_nodes(); ++row ) {
    cout << "nodo " << (row + 1) << ": ";
    for ( unsigned int col = 0; col < LS_[row].size(); ++col ) {
      cout << (LS_[row][col].j + 1) << " ";
    }
    cout << endl;
  }

}

void grafo_t::info_grafo(void) {

  cout << "Numero de nodos: " << setw(3) << get_nodes() << endl;
  cout << "Numero de arcos: " << setw(3) << get_arcs() << endl;
  cout << "Tipo de grafo: ";
  if (es_dirigido()) cout << "dirigido" << endl;
  else cout << "no dirigido";

}
