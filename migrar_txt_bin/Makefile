INCLUDE = $(PWD)
FLAGS = -lc -lm -w -Wall -O3 -ggdb
CC = g++
CPPFLAGS =

objects = estudiante.o

%.o: %.cc
	$(CC) -c -I$(INCLUDE) -L$(INCLUDE) $(FLAGS) $(CPPFLAGS) $< -o $@

all : $(objects)
	$(CC) -I$(INCLUDE) -L$(INCLUDE) $(FLAGS) $(CPPFLAGS) $(objects) migrar_txt_bin.cc -o migrar_txt_bin 
	$(CC) -I$(INCLUDE) -L$(INCLUDE) $(FLAGS) $(CPPFLAGS) $(objects) mostrar_bin.cc -o mostrar_bin
	$(CC) -I$(INCLUDE) -L$(INCLUDE) $(FLAGS) $(CPPFLAGS) generar_estudiantes.cc -o generar_estudiantes

clean:
	rm -f *.o
	rm -f migrar_txt_bin
	rm -f mostrar_bin
	rm -f generar_estudiantes
