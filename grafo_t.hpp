#pragma once




class grafo_t {

  private:
 
  //Estructuras de la clase
  
  typedef struct {

    unsigned j; //nodo 
    int c; //atributo (peso, coste, etc.)

  }ELEMENTO_LISTA_T

  typedef <vector <vector <ELEMENTO_LISTA_T> > > LA_nodo;

  //Atributos de la clase

  unsigned int n_; //numero de nodos o vertices
  unsigned int m_; //numero de arcos o aristas
  unsigned int dirigido_;
  LA_nodo LS_; //lista de sucesores
  vector<LA_nodo> LP_; //lista de predecesores


  public:

  //constructores
  grafo_t(void): 
    n_(0), 
    m_(0), 
    dirigido_(0) 
  {}

  grafo_t(char nombrefichero[], int &errorapertura);
  //destructores

  ~grafo_t(void) {}

  //setters
  void set_n() {} 
  void set_m() {} 

  //getters
};
