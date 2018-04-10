#include <cstdlib>
#include <iostream>

#include "grafo_t.hpp"

void menu(void);
void print_menu(bool mode);

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

  grafo_t A(fichero, errorfichero);

  do {
    if (errorfichero) {
      print_menu(A.es_dirigido());
      cin >> select;
      getchar();
    
      switch (select) {
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
         A.mostrar_listas();
         getchar();
         break;

       case 5:
         exit(0);

     }
    }
  } while(1);
}

void print_menu(bool mode) {

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

}
