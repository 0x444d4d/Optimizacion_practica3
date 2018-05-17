#include <ncurses.h>
#include <iostream>
#include <cstdlib>

#include "grafo_t.hpp"

const unsigned KEY_DOWN = 258
const unsigned KEY_UP = 259
const unsigned KEY_LEFT = 260
const unsigned KEY_RIGHT = 261

int menu(bool mplex);
void show_files(void);

using namespace std;

int main(void)
{	

  char fichero[50];
  bool errorfichero;

  system("clear");
  show_files();
  cout << "Escriba el nombre del fichero: ";
  cin >> fichero;
  getchar();
  
  grafo_t grafo(fichero, errorfichero);

  while(1)
  {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    switch(menu(0))
    {
      case 0:
	system("clear");
	show_files();
	cout << "Escriba el nombe del fichero: ";
	cin >> fichero;
	getchar();
        grafo.update(fichero, errorfichero);
      break;

      case 1:
	system("clear");
	grafo.info_grafo();
	getchar();
      break;

      case 2:
	system("clear");
        grafo.mostrar_listas();
	getchar();
      break;

      case 3:
	system("clear");
	grafo.componentes_conexas();	
	getchar();
      break;

      case 4:
	system("clear");
        endwin();
        system("clear");
	exit(0);
      break;
    }


  }
  return 0;

}


int menu(bool mplex)
{
  short unsigned selector = 0;


  while (1) 
  {
    if (!mplex)
    {
      clear();

      attron(A_UNDERLINE);
      mvprintw(3, 10, "MENU");
      attroff(A_UNDERLINE);

      if (selector == 0) mvprintw(5, 0, ">");
      else attron(A_DIM);
      mvprintw(5, 3, "Cargar otro grafo");
      attroff(A_DIM);
      
      if (selector == 1) mvprintw(6, 0, ">");
      else attron(A_DIM);
      mvprintw(6, 3, "Mostrar informacion basica");
      attroff(A_DIM);

      if (selector == 2) mvprintw(7, 0, ">");
      else attron(A_DIM);
      mvprintw(7, 3, "Mostrar lista de adyacencia");
      attroff(A_DIM);

      if (selector == 3) mvprintw(8, 0, ">");
      else attron(A_DIM);
      mvprintw(8, 3, "Mostrar componentes conexas");
      attroff(A_DIM);

      if (selector == 4) mvprintw(9, 0, ">");
      else attron(A_DIM);
      mvprintw(9, 3, "Salir");
      attroff(A_DIM);

    }
    
    refresh();

    switch(getch()) 
    {
      case KEY_DOWN:
        if (selector < (mplex ? 5:4)) ++selector;
        break;
    
      case KEY_UP: 
        if (selector) --selector;
        break;

      case KEY_LEFT: 
        //Not used
        break;

      case KEY_RIGHT: 
        endwin();
        return selector;
        break;
    }
  }
}


void show_files(void) {
  system("ls *.gr");
}
	
