#include "grafo_t.hpp"

int main (void) {

  char fichero[10] = "text.gr";
  bool errorfichero = false;
  grafo_t A(fichero, errorfichero);


  A.mostrar_listas();
  A.info_grafo();

  return 0;
}
