#include "Matriks.h"
#include <iostream>

using namespace std;

Matriks::Matriks():num_brs(DEFSIZE),num_kol(DEFSIZE){
  b = new int*[num_brs];
  for (int i=0;i<num_brs;i++){
    b[i] = new int[num_kol];
    for (int j=0;j<num_kol;j++){
      b[i][j]=0;
    }
  }
}

Matriks::Matriks(int n, int m):num_brs(n),num_kol(m){
  b = new int*[num_brs];
  for (int i=0;i<num_brs;i++){
    b[i] = new int[num_kol];
    for (int j=0;j<num_kol;j++){
      b[i][j]=0;
    }
  }
}

Matriks::Matriks(const Matriks &m):num_brs(m.num_brs),num_kol(m.num_kol){
  b = new int*[num_brs];
  for (int i=0;i<num_brs;i++){
    b[i] = new int[num_kol];
    for (int j=0;j<num_kol;j++){
      b[i][j]=m.b[i][j];
    }
  }
}

Matriks::~Matriks(){
  for (int i=0;i<num_brs;i++){
    delete b[i];
  }
  delete b;
}

bool IsEqSize(Matriks m1, Matriks m2){
  return m1.num_brs== m2.num_brs && m1.num_kol== m2.num_kol;
}

Matriks Matriks::operator+(Matriks m2){
  int n,m;
  if (num_brs > m2.num_brs){
    n=num_brs;
  }
  else{
    n=m2.num_brs;
  };
  if (num_kol > m2.num_kol){
    m=num_kol;
  }
  else{
    m=m2.num_kol;
  };
  Matriks mx(n,m);
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if (i<num_brs && j<num_kol){
        mx.b[i][j]+=b[i][j];
      }
      if (i<m2.num_brs && j<m2.num_kol){
        mx.b[i][j]+=m2.b[i][j];
      }
    }
  }
  return mx;
}

Matriks operator-(const Matriks &m1, const Matriks &m2){
  int n,m;
  if (m1.num_brs > m2.num_brs){
    n=m1.num_brs;
  }
  else{
    n=m2.num_brs;
  };
  if (m1.num_kol > m2.num_kol){
    m=m1.num_kol;
  }
  else{
    m=m2.num_kol;
  };
  Matriks mx(n,m);
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if (i<m1.num_brs && j<m1.num_kol){
        mx.b[i][j]+=m1.b[i][j];
      }
      if (i<m2.num_brs && j<m2.num_kol){
        if (!(i<m1.num_brs && j<m1.num_kol)){
          mx.b[i][j]+=m2.b[i][j];
        }
        else{
          mx.b[i][j]-=m2.b[i][j];
        }
      }
    }
  }
  return mx;
}

Matriks Matriks::operator*(const int n){
  Matriks mx(num_brs,num_kol);
  for (int i=0;i<num_brs;i++){
    for (int j=0;j<num_kol;j++){
      mx.b[i][j]=b[i][j]*n;
    }
  }
  return mx;
}

Matriks operator*(const int n, const Matriks m2){
  Matriks mx(m2.num_brs,m2.num_kol);
  for (int i=0;i<m2.num_brs;i++){
    for (int j=0;j<m2.num_kol;j++){
      mx.b[i][j]=m2.b[i][j]*n;
    }
  }
  return mx;
}

void Matriks::SetData(int i, int j, int v){
  b[i][j]=v;
}

int Matriks::GetData(int i, int j) const{
  return b[i][j];
}

int Matriks::GetBrs() const{
  return num_brs;
}

int Matriks::GetKol() const{
  return num_kol;
}

bool Matriks::IsSimetri() const{
  return num_brs==num_kol;
}
