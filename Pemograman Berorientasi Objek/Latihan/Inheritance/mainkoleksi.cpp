#include "KoleksiKendaraan.cpp"
#include <iostream>
using namespace std;

int main()
{
  // KAMUS
  Mobil M1;
  Mobil M2(0, 0, "a", "a");
  Bus B1;
  Bus B2(0, 0, "a", 0);
  Minibus MB1;
  Minibus MB2(0, 0, "a");
  KoleksiKendaraan K1;
  KoleksiKendaraan K2(5);

  // ALGORITMA
  K1 + M1;
  K1 + M2;
  K2 + B1;
  K2 + B2;
  K1 + MB1;
  K1 + MB2;
  K1 + K2;

  cout << "Koleksi 1" << endl;
  K1.PrintAll();

  cout << endl << "Koleksi 2" << endl;
  K2.PrintAll();
}
