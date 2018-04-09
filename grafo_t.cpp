#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

#include "grafo_t.hpp"

using namespace std;

//constructor
grafo_t::grafo_t(char nombrefichero[], bool &errorapertura) {

  /*
  ifstream inFile(nombrefichero);

  if (!inFile) {
    errorapertura = true;
  } else { build(inFile); } 
  */

  ifstream inFile;
  if ( errorapertura = !openFile(nombrefichero, inFile)) 
    build(inFile);
}



grafo_t::~grafo_t(void) {
  
  for (unsigned col = 0; col < get_nodes(); ++col) {
    LS_[col].clear();
    LP_[col].clear();
  }

  LS_.clear();
  LP_.clear();

}



void grafo_t::build(ifstream &inFile) {

  elementoLista_T aux;
  int node, dest;

  inFile >> n_ >> m_ >> dirigido_;

  LS_.resize(n_);
  LP_.resize(n_);

    while ( !inFile.eof() ) {

      //ERROR. El constructor repite el ultimo nodo.
      //Es posible que sea un error de grafo::write().
      inFile >> node >> dest;

      aux.j = (dest - 1);
      aux.c = 0;

      LS_[node - 1].push_back(aux);
    }
  predecesorList();
}



void grafo_t::update(char nombrefichero[], bool &errorapertura) {

  for (unsigned col = 0; col < get_nodes(); ++col) {
    LS_[col].clear();
  }

  LS_.clear();

/*
  ifstream inFile(nombrefichero); 

  if (!inFile) { 
    errorapertura = true;
  } else { build(inFile); }
*/

  ifstream inFile;
  if ( errorapertura = !openFile(nombrefichero, inFile)) 
    build(inFile);
}



void grafo_t::write(void) {

  cout << "Lista de sucesores:" << endl;

  for ( unsigned int row = 0; row < get_nodes(); ++row ) {
    cout << "nodo " << (row + 1) << ": ";
    for ( unsigned int col = 0; col < LS_[row].size(); ++col ) {
      cout << (LS_[row][col].j + 1) << " ";
    }
    cout << endl;
  }

  cout << "Lista de predecesores:" << endl;
   
  for ( unsigned int row = 0; row < get_nodes(); ++row ) {
    cout << "nodo " << (row + 1) << ": ";
    for ( unsigned int col = 0; col < LP_[row].size(); ++col ) {
      cout << (LP_[row][col].j + 1) << " ";
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



bool grafo_t::openFile(char filename[], ifstream &inFile) {

  inFile.open(filename);
  return ((inFile.is_open() == true) ? false : true);
   
}



void grafo_t::predecesorList(void) {

  elementoLista_T aux;

  for (unsigned int row = 0; row < get_nodes(); ++row)
    for (unsigned int col = 0; col < LS_[row].size() ; ++col) {
    
      aux.j = row; 
      aux.c = 0;

      LP_[LS_[row][col].j].push_back(aux);
    
    }
}
