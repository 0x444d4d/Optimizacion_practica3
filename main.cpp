#include "grafo_t.hpp"

int main (void) {

  char fichero[10] = "text.gr";
  grafo_t A(fichero);


  A.write();
  A.info_grafo();

  return 0;
}
