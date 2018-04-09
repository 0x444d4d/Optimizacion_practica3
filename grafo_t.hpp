#pragma once

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


class grafo_t {

 private:
 
  //Estructuras de la clase
  
  typedef struct {

    unsigned int j; //nodo 
    int c; //atributo (peso, coste, etc.)

    }elementoLista_T;

  typedef vector<vector<elementoLista_T> > LA_nodo;

  //Atributos de la clase
  unsigned int n_; //numero de nodos o vertices
  unsigned int m_; //numero de arcos o aristas
  bool dirigido_;
  LA_nodo LS_; //lista de sucesores
  LA_nodo LP_; //lista de predecesores



 public:

  //constructores
  grafo_t(char nombrefichero[], bool &errorapertura);

  //destructores
  ~grafo_t(void);


  //getters
  const unsigned int get_nodes(void) const {return n_;};
  const unsigned int get_arcs(void) const {return m_;};
  const bool es_dirigido(void) const {return dirigido_;};


  void write (void);
  void info_grafo(void);

  
 private: 

  bool openFile(char nombrefichero[], ifstream &inFile);
  void build(ifstream &inFile);
  void predecesorList(void);
  void update(char nombrefichero[], bool &errorapertura); 

};



