/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : sekretaris.cpp
 * Topik     : Praktikum 6
 * Tanggal   : 28 Februari 2019
 * Deskripsi : Realisasi sekretaris.cpp */

#include "sekretaris.h"
#include <iostream>
using namespace std;

Sekretaris::Sekretaris()
{
	kertas = KERTAS_DEFAULT;
	tinta = TINTA_DEFAULT;
	energi = ENERGI_MAX;
	memoLength = 0;
	memo = new Memo[100];
}

Sekretaris::Sekretaris(int _kertas, int _tinta)
{
	kertas = _kertas;
	tinta = _tinta;
	energi = ENERGI_MAX;
	memoLength = 0;
	memo = new Memo[100];
}

Sekretaris::~Sekretaris()
{
	delete[] memo;
}

void Sekretaris::buatMemo(string pesan, string untuk)
{
	try
	{
		pakaiKertas();
		pakaiTinta(pesan.length());
		pakaiEnergi();
		Memo memoTemp(pesan, untuk);
		memo[memoLength] = memoTemp;
		memoLength++;
		cout << "Memo [" << memoLength << "] untuk " << untuk << " berhasil dibuat" << endl;
	}
	catch (KertasHabisException E)
	{
		cout << E.what();
		cout << ", segera isi kertas" << endl;
	}
	catch (TintaKurangException E)
	{
		batalPakaiKertas();
		cout << E.what();
		cout << ", segera isi tinta" << endl;
	}
	catch (EnergiHabisException E)
	{
		batalPakaiKertas();
		batalPakaiTinta(pesan.length());
		cout << E.what();
		cout << ", segera istirahat" << endl;
	}
	catch (PesanKepanjanganException E)
	{
		batalPakaiKertas();
		batalPakaiTinta(pesan.length());
		batalPakaiEnergi();
		cout << E.what();
		cout << ", perpendek pesannya" << endl;
	}
}

void Sekretaris::pakaiKertas()
{
	kertas--;
	
	if (kertas < 0)
	{
		batalPakaiKertas();
		throw KertasHabisException();
	}
}

void Sekretaris::pakaiTinta(int num)
{
	tinta -= num;
	
	if (tinta < 0)
	{
		batalPakaiTinta(num);
		throw TintaKurangException();
	}
}

void Sekretaris::pakaiEnergi()
{
	energi--;
	
	if (energi < 0)
	{
		batalPakaiEnergi();
		throw EnergiHabisException();
	}
}

void Sekretaris::batalPakaiKertas()
{
	kertas++;
}

void Sekretaris::batalPakaiTinta(int num)
{
	tinta += num;
}

void Sekretaris::batalPakaiEnergi()
{
	energi++;
}

void Sekretaris::isiTinta(int num)
{
	tinta += num;
}

void Sekretaris::isiKertas(int num)
{
	kertas += num;
}

void Sekretaris::istirahat()
{
	energi = ENERGI_MAX;
}

void Sekretaris::printStatus()
{
	int i;
	
	cout << "Status" << endl;
	cout << "  Energi : " << energi << endl;
	cout << "  Tinta : " << tinta << endl;
	cout << "  Kertas : " << kertas << endl;
	cout << "  Memo : " << memoLength << endl;
	
	for (i = 0; i < memoLength; i++)
	{
		cout << "    Memo [" << i+1 << "]" << endl;
		cout << "      Pesan : " << memo[i].getPesan() << endl;
		cout << "      Untuk : " << memo[i].getUntuk() << endl;
	}
}
