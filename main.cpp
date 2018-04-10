#include <cstdlib>
#include <iostream>

#include "grafo_t.hpp"

void menu(void);
short unsigned print_menu(bool mode);

int main (void) {

  menu();

  return 0;
}



void menu (void) {
  unsigned int select;
  char fichero[50];
  bool errorfichero;

  system("clear");
  cout << "Escriba el nombre del fichero: ";
  cin >> fichero;
  getchar();
  
  grafo_t A(fichero, errorfichero);

  do {
    if (!errorfichero) {
      if (A.es_dirigido()) {
        
        switch (print_menu(A.es_dirigido())) {

          case 1:
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
    cout << "4.- Salir del programa." << endl;
  }

  cout << "Indique una opcion: ";
  cin >> select;
  getchar();

  system("clear");

  return select;

}
