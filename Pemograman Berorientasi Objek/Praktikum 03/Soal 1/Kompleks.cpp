#include "Kompleks.h"
#include <iostream>

using namespace std;

int Kompleks::n_kompleks=0;

Kompleks::Kompleks(){
  n_kompleks++;
  real=0;
  imaginer=0;
}

Kompleks::Kompleks(int real, int imaginer){
  n_kompleks++;
  this->real=real;
  this->imaginer=imaginer;
}

int Kompleks::GetReal() const{
  return real;
}

int Kompleks::GetImaginer() const{
  return imaginer;
}

void Kompleks::SetReal(int r) {
  real=r;
}

void Kompleks::SetImaginer(int i) {
  imaginer=i;
}

Kompleks operator+(const Kompleks &K1, const Kompleks &K2){
  Kompleks NK;
  NK.SetReal(K1.GetReal()+K2.GetReal());
  NK.SetImaginer(K1.GetImaginer()+K2.GetImaginer());
  return NK;
}

Kompleks operator-(const Kompleks &K1, const Kompleks &K2){
  Kompleks NK;
  NK.SetReal(K1.GetReal()-K2.GetReal());
  NK.SetImaginer(K1.GetImaginer()-K2.GetImaginer());
  return NK;
}

Kompleks operator*(const Kompleks &K1, const Kompleks &K2){
  Kompleks NK;
  NK.SetReal((K1.GetReal()*K2.GetReal())-(K1.GetImaginer()*K2.GetImaginer()));
  NK.SetImaginer((K1.GetImaginer()*K2.GetReal())+(K2.GetImaginer()*K1.GetReal()));
  return NK;
}

Kompleks operator*(const Kompleks &K, const int n){
  Kompleks NK(K.GetReal()*n,K.GetImaginer()*n);
  return NK;
}

Kompleks operator*(const int n, const Kompleks &K){
  Kompleks NK(K.GetReal()*n,K.GetImaginer()*n);
  return NK;
}

int Kompleks::CountKompleksInstance(){
  return n_kompleks;
}

void Kompleks::Print(){
  cout << real;
  if (imaginer>=0){
    cout << "+";
  }
  cout << imaginer << "i" << endl;
}
