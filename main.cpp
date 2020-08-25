#include <iostream>
#include <fstream>

using namespace std;

const int TAM = 100;

void ingresar(int Arreglo[TAM], int t);
void ordenar_insercion(int Arreglo[TAM], int t);
int sumatoria(int Arreglo[TAM], int t);

int main() {
  ofstream ordenar;
  int arreglo[TAM], tamanio, i;
  ordenar.open("Ordenamiento", ios::out);
  if (ordenar.is_open())
  {
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> tamanio;
    ingresar(arreglo, tamanio);
    ordenar << "Arreglo original: ";
    for (i = 0; i < tamanio; i++)
    {
      ordenar << arreglo[i] << " ";
    }
    ordenar << '\n';

    ordenar_insercion(arreglo, tamanio);
    ordenar << "Arreglo ordenado: ";
    for (i = 0; i < tamanio; i++)
    {
      ordenar << arreglo[i] << " ";
    }
    ordenar << '\n';
    ordenar << "\nEl total de elementos es: " << tamanio << '\n';
    ordenar << "La suma de los número ingresados es: " << sumatoria(arreglo, tamanio);
  }
  else
  {
    cout << "El archivo no abrio con exitosamente" << endl;
  }
  ordenar.close();
}

void ingresar(int Arreglo[TAM], int t)
{
  for (int i = 0; i < t; i++)
  {
    cout << "Ingrese los valores al arreglo: ";
    cin >> Arreglo[i];
  }
}

void imprimir(int Arreglo[TAM], int t)
{
  for (int i = 0; i < t; i++)
  {
    cout << Arreglo[i] << " ";
  }
}

void ordenar_insercion(int Arreglo[TAM], int t)
{
  int aux, p;
  for (int i = 0; i < t; i++)
  {
    aux = Arreglo[i];
    p=i;
    while(p > 0)
    {
      if(Arreglo[p-1]>aux)
      {
        Arreglo[p]=Arreglo[p-1];
        Arreglo[p-1]=aux;
      }
      p--;
    }
  }
}

int sumatoria(int Arreglo[TAM], int t)
{
  int suma = 0;
  for (int i = 0; i < t; i++)
  {
    suma += Arreglo[i];
  }
  return suma;
}