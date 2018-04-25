#include <cstdlib>
#include <iostream>

#include "grafo_t.hpp"

void menu(void);
short unsigned print_menu(bool mode);
void show_files(void);

int main (void) {

  menu();

  return 0;
}



void menu (void) {
  unsigned int select;
  char fichero[50];
  bool errorfichero;

  system("clear");
  show_files();
  //system("./a.out");
  cout << "Escriba el nombre del fichero: ";
  cin >> fichero;
  getchar();
  
  grafo_t A(fichero, errorfichero);

  do {
    if (!errorfichero) {
      if (A.es_dirigido()) {
        
        switch (print_menu(A.es_dirigido())) {

          case 1:
            //system("./a.out");
	    show_files();
            cout << "Escriba el nombre del fichero: ";
            cin >>  fichero;
            getchar();
            A.update(fichero, errorfichero);
            break;

          case 2:
            A.info_grafo();
            getchar();
            break;

          case 3:
            A.mostrar_listas(0);
            getchar();
           break;

          case 4:
            A.mostrar_listas(1);
            getchar();
            break;

          case 5:
            system("clear");
            exit(0);

          default:
            cout << "Opcion no valida";
            getchar();
        }
      
      } else {

        switch (print_menu(A.es_dirigido())) {

          case 1:
            //system("./a.out");
            show_files();
	    cout << "Escriba el nombre del fichero: ";
            cin >>  fichero;
            getchar();
            A.update(fichero, errorfichero);
            break;

          case 2:
            A.info_grafo();
            getchar();
            break;

          case 3:
            A.mostrar_listas();
            getchar();
            break;
	
          case 4:
            A.componentes_conexas();
            cin.get();
            break;

          case 5:
            system("clear");
            exit(0);

          default:
            cout << "Opcion no valida";
            getchar();
        }
      
      }
    }
  } while(1);
}

short unsigned print_menu(bool mode) {
  short unsigned select;

  system("clear");

  cout << "1.- Cargar fichero de datos." << endl;
  cout << "2.- Mostrar informacion basica." << endl;
  if (mode) {
    cout << "3.- Mostrar lista de sucesores." << endl;
    cout << "4.- Mostrar lista de predecesores." << endl;
    cout << "5.- Salir del programa." << endl;
  } else {
    cout << "3.- Mostrar lista de adyacencia." << endl;
    cout << "4.- Mostrar componentes conexas." << endl;
    cout << "5.- Salir del programa." << endl;
  }

  cout << "Indique una opcion: ";
  cin >> select;
  getchar();

  system("clear");

  return select;

}

void show_files(void) {
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
