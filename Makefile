#objetos especifica los cpp a incluir en la compilacion.
objetos = grafo_t.cpp main.cpp
#flags especifca las flags a incluir en la compilacion.
flags = -g
#salida especifica el nombre el ejecutable.
salida = programa.out


#este es el objetivo que compila el ejecutable.
all : $(objetos)
	g++ $(flags) $(objetos) -o $(salida)
