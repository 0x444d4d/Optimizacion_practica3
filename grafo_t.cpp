#include "grafo_t.hpp"

using namespace std;

//constructor
  grafo_t::grafo_t(char nombrefichero[], bool &errorapertura) {

  ifstream inFile;
  errorapertura = open_file(nombrefichero, inFile);
  if (!errorapertura) build(inFile);
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

  while ( inFile >> node >> dest )
    if (dest) {
      aux.j = (dest - 1);
      aux.c = 0;

      LS_[node - 1].push_back(aux);    
    }

  predecessor_list();
}



void grafo_t::update(char nombrefichero[], bool &errorapertura) {

  for (unsigned col = 0; col < get_nodes(); ++col) {
    LS_[col].clear();
  }

  for (unsigned col = 0; col < get_nodes(); ++col) {
    LP_[col].clear();
  }

  LS_.clear();
  LP_.clear();

  ifstream inFile;
  errorapertura = open_file(nombrefichero, inFile);
  if (!errorapertura) build(inFile);
}



void grafo_t::write(LA_nodo lista) {

  for ( unsigned int row = 0; row < get_nodes(); ++row ) {
    cout << "nodo " << (row + 1) << ": ";
    for ( unsigned int col = 0; col < lista[row].size(); ++col ) {
      cout << (lista[row][col].j + 1) << " ";
    }
    cout << endl;
  }
}



void grafo_t::write(LA_nodo lista, LA_nodo lista2) {

  for ( unsigned int row = 0; row < get_nodes(); ++row ) {
    cout << "nodo " << (row + 1) << ": ";
    if (lista[row].size()) {
      for ( unsigned int col = 0; col < lista[row].size(); ++col ) {
        cout << (lista[row][col].j + 1) << " ";
      }
    } else {
      for ( unsigned int col = 0; col < lista2[row].size(); ++col ) {
        cout << (lista2[row][col].j + 1) << " ";
      }
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

void grafo_t::mostrar_listas(void) {
  
  if (es_dirigido()) {

      cout << "Lista sucesores:" << endl;
      write(LS_); 
      
      cout << endl << "Lista de predecesores:" << endl;
      write(LP_);

    } else { 
       cout << "Lista de adyacencia:" << endl;
       write(LS_, LP_);
    }
}


void grafo_t::mostrar_listas(bool mplex) {
  
  if (es_dirigido()) {

    if (mplex) {
      cout << "Lista de predecesores:" << endl;
      write(LP_);

    } else {
      cout << "Lista sucesores:" << endl;
      write(LS_); 
    }

  } else { 
    cout << "Lista de adyacencia:" << endl;
    write(LS_);
  }
}



bool grafo_t::open_file(char filename[], ifstream &inFile) {

  inFile.open(filename);
  return !inFile.is_open();
   
}



void grafo_t::predecessor_list(void) {

  elementoLista_T aux;

  for (unsigned int row = 0; row < get_nodes(); ++row)
    for (unsigned int col = 0; col < LS_[row].size() ; ++col) {
    
      aux.j = row; 
      aux.c = 0;

      LP_[LS_[row][col].j].push_back(aux);
    
    }
}

void grafo_t::dfs(unsigned int i, vector<bool> &visitado) {

  visitado[i] = true;
  cout << i+1 << ", ";
  for (unsigned int j=0; j < LS_[i].size(); ++j)
    if (!visitado[LS_[i][j].j])
      dfs(LS_[i][j].j, visitado);

}

void grafo_t::componentes_conexas(void) {
  vector<bool> visitado(n_);
  unsigned int inx;
  unsigned int comp = 0;
 
  for (inx = 0; inx < n_; ++inx)
    visitado[inx] = false;
 
  inx = 0;
  cout << "Componente conexa: " << inx+1 << " {";
  dfs(inx, visitado);
  cout << "}" << endl;
    
  for (inx = 1; inx < n_; ++inx) {
    if (!visitado[inx]) {
      cout << "Componente conexa" << inx+1 << "{";
      dfs(inx, visitado);
      cout << "}" << endl;
      ++comp;
    }
  }
  
  if (!comp) 
    cout << "El grafo es conexo" << endl;
  else 
    cout << "El grafo no es conexo" << endl;
}
