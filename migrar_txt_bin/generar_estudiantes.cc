# include <iostream>
# include <string>
using namespace std;

# include <cstdlib>

int main(int argc, char * argv[]) {
  srand(time(NULL));

  string nombres[20] = {"Juan", "Pedro", "Marco", "Maria", "Juana", "Petra",
    "Gabriela", "Antonieta", "Antonio", "Francisco", "Angel", "David", "Jose",
    "Flor", "Marta", "Iris", "Arleni", "Andrea", "Pagola", "Miguel"};

  string apellidos[20] {"Perez", "Peralta", "Garcia", "Chavez", "Miranda",
    "Bolivar", "Uzcategui", "Varela", "Molina", "Martinez", "Leo", "Torrealba",
    "Rojas", "Torres", "Velasco", "Contreras", "Pineda", "Pirela", "Arcia",
    "Hernandez"};

  string carreras[6] = {"Ingenieria de Sistemas", "Ingenieria Geologica",
    "Ingenieria Civil", "Ingenieria Quimica", "Ingenieria Mecanica",
    "Ingenieria Electrica"};

  string nacionalidad[5] = {"venezolano", "cubano", "colombiano", "argentino",
    "chileno"};

  const long kNumEstudiantes = argc > 1 ? atol(argv[1]) : 1000;
  int cant_nombres;
  int cant_apellidos;

  for(long i = 0; i < kNumEstudiantes; ++i) {

    cant_nombres = rand() % 3;
    for (int j = 0; j < cant_nombres; ++j) {
      cout << nombres[rand() % 20] << " ";
    }
    cout << nombres[rand() % 20] << ";";

    cant_apellidos = rand() % 3;
    for (int j = 0; j < cant_apellidos; ++j) {
      cout << apellidos[rand() % 20] << " ";
    }
    cout << apellidos[rand() % 20] << ";";

    cout << nacionalidad[rand() % 5] << ";";
    cout << rand() % 30000000 + 500000 << ";";
    cout << 2010 + rand() % 3;

    int mes = rand() % 12 + 1;
    if( mes < 10)
      cout << "0" << mes;
    else
      cout << mes;

    int dia = rand() % 30;
    if (dia < 10)
      cout << "0" << dia;
    else
      cout << dia;
    cout << ";";

    cout << carreras[rand() % 6];
    cout << endl;
  }

  return 0;
}
