# include <list>
using std::list;

# include <string>
using std::string;

# include <cstdlib>
// Prototipo de atoi

# include "estudiante.h"
# include "archivo_estudiante.h"

ArchivoEstudiante::ArchivoEstudiante(const string & n, const char d) {
  delimitador = d;
  nombre_ = n;
  this->open();
}

ArchivoEstudiante::ArchivoEstudiante(const ArchivoEstudiante & fuente) {
  delimitador = fuente.delimitador;
  nombre_ = fuente.nombre_;
  this->open();
}

void ArchivoEstudiante::open(const string n) {
  if (not archivo) {}
  else
    close();

  if (n != "")
    nombre_ = n;

  archivo.open(nombre_.c_str(), ios::in | ios::out | ios::ate);

  if (not archivo) {
    cerr << "Problemas al abrir \"" << nombre_ << "\" ";
    abierto_ = false;
  }
  else {
    abierto_ = true;
  }
}

void ArchivoEstudiante::close() {
  archivo.close();
}

ArchivoEstudiante::~ArchivoEstudiante() {
  close();
}

bool ArchivoEstudiante::agregar(const Estudiante & e) {

  archivo.clear();
  archivo.seekp(0, ios::end);
  archivo << e.nombre() << delimitador << e.cedula() << delimitador << e.nota1()
      << delimitador << e.nota2() << delimitador << e.nota3() << endl;
  archivo.flush();
}

bool ArchivoEstudiante::leer(Estudiante & e) {
  string buffer;
  int nota;

  if (not archivo)
    return false;

  // Nombre
  getline(archivo, buffer, delimitador);
  e.nombre(buffer);

  if (archivo.eof())
    return false;

  // Cedula
  getline(archivo, buffer, delimitador);
  e.cedula(atol(buffer.c_str()));

  // Nota 1
  getline(archivo, buffer, delimitador);
  e.nota1(atoi(buffer.c_str()));

  // Nota 2
  getline(archivo, buffer, delimitador);
  e.nota2(atoi(buffer.c_str()));

  // Nota 3
  getline(archivo, buffer, '\n');
  e.nota3(atoi(buffer.c_str()));

  return true;
}

Estudiante ArchivoEstudiante::eliminar(const long & cedula) {
  Estudiante tmp, e;
  ofstream aux("/tmp/auxiliar_estudiantes.txt");
  
  if (not aux) {
    cerr << "Error abriendo archivo auxiliar" << endl;
    return e;
  }

  archivo.clear();
  archivo.seekp(0, ios::beg);

  while (leer(tmp)) {
    cout << "XXXX" << endl;
    cout << tmp.nombre();
    cout << "XXXX" << endl;

    if (tmp.cedula() != cedula) {
      aux << tmp.nombre() << delimitador << tmp.cedula() << delimitador << tmp.nota1()
          << delimitador << tmp.nota2() << delimitador << tmp.nota3() << endl;
    }
    else {
      e = tmp;
    }
  }
  
  aux.flush();
  aux.close();

  // Si el registro no existia no hay necesidad de renombrar el archivo
  if (e.cedula() != -1) {
    this->close();

    string command("mv /tmp/auxiliar_estudiantes.txt ");
    command.append(this->nombre());
    system(command.c_str());

    this->open();
  }

  return e;
}

Estudiante ArchivoEstudiante::modificar(const Estudiante & e, const long & cedula) {}

Estudiante ArchivoEstudiante::buscar_por_cedula(const long & cedula) {
  Estudiante buffer;

  archivo.clear();
  archivo.seekg(0);

  while (leer(buffer)) {
    if (buffer.cedula() == cedula)
      return buffer;
  }

  buffer.nombre("");
  buffer.cedula(-1);

  return buffer;
}

list<Estudiante> ArchivoEstudiante::buscar_por_nombre(const string & nombre) {
  Estudiante buffer;
  list<Estudiante> l;

  archivo.clear();
  archivo.seekg(0);

  while (not archivo.eof()) {
    leer(buffer);
    if (buffer.nombre() == nombre)
      l.push_back(Estudiante(buffer));
  }

  return l;
}

list<Estudiante> ArchivoEstudiante::buscar_por_promedio(const float & prom) {
  Estudiante buffer;
  list<Estudiante> l;

  archivo.clear();
  archivo.seekg(0);

  while (leer(buffer)) {
    if (buffer.promedio() >= prom)
      l.push_back(Estudiante(buffer));
  }

  return l;
}

template< class Compare >
list<Estudiante> ArchivoEstudiante::buscar(const int & nota, const Compare & cmp) {

  Estudiante buffer;
  list<Estudiante> l;

  archivo.clear();
  archivo.seekg(0);

  while (leer(buffer)) {
    if (cmp(buffer, nota))
      l.push_back(Estudiante(buffer));
  }
}

template< class Compare >
list<Estudiante> & ArchivoEstudiante::buscar(const string & nombre, const Compare & cmp) {

  Estudiante buffer;
  list<Estudiante> l;

  archivo.clear();
  archivo.seekg(0);

  while (leer(buffer)) {
    if (cmp(buffer, nombre))
      l.push_back(Estudiante(buffer));
  }
}

void ArchivoEstudiante::particion_por_nota(const string &, const float &) {

}

template< class Compare >
void ArchivoEstudiante::particion(const string &, const Compare & cmp) {

}

void ArchivoEstudiante::mezclar(const string &) {

}

long ArchivoEstudiante::cantidad_registros() {

}

string ArchivoEstudiante::nombre() const {
  return nombre_;
}

bool ArchivoEstudiante::abierto() const {
}

void ArchivoEstudiante::mostrar() {
  Estudiante e;

  archivo.clear();
  archivo.seekg(0, ios::beg);

  while (leer(e)) {
    cout << e << endl;
  }
}
