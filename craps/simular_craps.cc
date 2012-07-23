# include <iostream>
using namespace std;

# include <cstdlib>

int craps();
int dado();

int main() {
  int resultados[13] = {0};

  for(int i = 0; i < 1000000; ++i) {
    resultados[craps()]++;
  }

  int total = 0;
  for(int i = 2; i < 13; ++i) {
    cout << i << ": " << resultados[i] << endl;
    total += resultados[i];
  }

  cout << total << endl;

  return 0;
}

int craps() {
  return dado() + dado();
}

int dado() {
  return rand() % 6 + 1;
}
