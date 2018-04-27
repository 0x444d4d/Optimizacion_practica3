#include <ncurses.h>
#include <iostream>
#include <cstdlib>

int menu(bool mplex);

int main()
{	
  //Inicializamos la ventana
	initscr();
	cbreak();
  //Noecho permite usar el teclado sin
  //imprimir en pantalla.
	noecho();
	keypad(stdscr, TRUE);

  menu(0);

  endwin();

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

      mvprintw(3, 10, "MENU");

      if (selector == 0) mvprintw(5, 0, ">");
      mvprintw(5, 3, "opcion0");
      
      if (selector == 1) mvprintw(6, 0, ">");
      mvprintw(6, 3, "opcion1");

      if (selector == 2) mvprintw(7, 0, ">");
      mvprintw(7, 3, "opcion2");
    }
    
    switch(getch()) 
    {
      case 258: 
        if (selector < (mplex ? 5:2)) ++selector;
        break;
    
      case 259: 
        if (selector) --selector;
        break;

      case 260: 
        //Not used
        break;

      case 261: 
        return selector;
        break;
    }
  }
}
