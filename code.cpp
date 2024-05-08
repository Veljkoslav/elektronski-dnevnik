#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

void kreiranjeOdeljenja(string ime, string prezime, string odeljenje);
void glavniMeni(string ime, string prezime, string odeljenje);
void meniRoditelj(string id, string odeljenje, string korisnicko);
void pocetniMeni();
void upisOcena();
void izborNasumicnogUcenika();

vector < string > split(const string & s, char delim) {
  vector < string > result;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) result.push_back(item);
  return result;
};

void promenaSifreRoditelja(string id, string odeljenje, string korisnicko) {
  string staraSifra, novaSifra;
  cout << "Unesite trenutnu šifru: ";
  cin >> staraSifra;
  cout << "Unesite novu šifru: ";
  cin >> novaSifra;

  vector < string > linije;
  string x;
  ifstream baza("roditelji.txt");
  if (baza.is_open()) {
    bool tacnost = false;
    while (getline(baza, x)) {
      vector < string > niz = split(x, ',');
      if (niz[2] == korisnicko && niz[3] == staraSifra) {
        linije.push_back(niz[0] + "," + niz[1] + "," + niz[2] + "," + novaSifra);
        tacnost = true;
      } else {
        linije.push_back(x);
      }
    };
    if (!tacnost) {
      cout << "Uneli ste pogrešnu lozinku." << endl;
    } else {
      ofstream baza2;
      baza2.open("roditelji.txt");
      for (string linija: linije) baza2 << linija << endl;
      baza2.close();
      cout << "Uspešno ste promenili lozinku." << endl;
    }
    baza.close();
    return meniRoditelj(id, odeljenje, korisnicko);
  }
}

void promenaSifreProfesora(string ime, string prezime, string odeljenje) {
  string staraSifra, novaSifra;
  cout << "Unesite trenutnu šifru: ";
  cin >> staraSifra;
  cout << "Unesite novu šifru: ";
  cin >> novaSifra;

  vector < string > linije;
  string x;
  ifstream baza("profesori.txt");
  if (baza.is_open()) {
    bool tacnost = false;
    while (getline(baza, x)) {
      vector < string > niz = split(x, ',');
      if (niz[2] == ime && niz[3] == prezime && niz[1] == staraSifra) {
        linije.push_back(niz[0] + "," + novaSifra + "," + niz[2] + "," + niz[3] + "," + niz[4]);
        tacnost = true;
      } else {
        linije.push_back(x);
      }
    };
    if (!tacnost) {
      cout << "Uneli ste pogrešnu lozinku." << endl;
    } else {
      ofstream baza2;
      baza2.open("profesori.txt");
      for (string linija: linije) baza2 << linija << endl;
      baza2.close();
      cout << "Uspešno ste promenili lozinku." << endl;
    }
    baza.close();
    return glavniMeni(ime, prezime, odeljenje);
  }
}

void meniRoditelj(string id, string odeljenje, string korisnicko) {
  string ime, prezime, x;
  vector < double > ocene;
  bool tacnost = false;
  ifstream baza(odeljenje + ".txt");
  if (baza.is_open()) {
    while (getline(baza, x)) {
      vector < string > niz = split(x, ',');
      if (niz[0] == id) {
        ime = niz[1];
        prezime = niz[2];
        for (int i = 3; i < niz.size(); i++) {
          ocene.push_back(std::stod(niz[i]));
        }
        tacnost = true;
        break;
      };
    };
  };
  if (!tacnost) {
    cout << "Uneli ste pogrešno korisničko ime ili lozinku." << endl;
    cout << "Bićete preusmereni u meni za ulaz u sistem." << endl;
    pocetniMeni();
    return;
  };
  cout << "\n====================";
  cout << "eDnevnik v1.0";
  cout << "====================" << endl;
  cout << "Dobro došli, " + ime + " " + prezime + "!" << endl;
  cout << "Vaše odeljenje je " + odeljenje << "." << endl << endl;
  cout << "Vaše ocene: ";
  for (int i = 0; i < ocene.size(); i++) i + 1 == ocene.size() ? cout << ocene[i] : cout << ocene[i] << ", ";
  cout << endl;

  int sum = std::accumulate(ocene.begin(), ocene.end(), 0);
  float prosek = (double) sum / ocene.size();

  cout << "Prosek Vaših ocena je " << prosek << "." << endl;
  cout << "Vaš uspeh je " << (prosek >= 4.50 ? "odličan" : prosek >= 3.50 ? "vrlodobar" : prosek >= 2.50 ? "dobar" : prosek >= 1.50 ? "dovoljan" : "nedovoljan") << "." << endl << endl;
  cout << "1 - Promena lozinke" << endl;
  cout << "0 - Odjava" << endl << endl;
  cout << "Opcija - ";
  int opcija;
  cin >> opcija;

  if (opcija == 0) return pocetniMeni();
  if (opcija == 1) return promenaSifreRoditelja(id, odeljenje, korisnicko);

};

bool sortPrezime(string a, string b) {
  vector < string > niz1 = split(a, ',');
  vector < string > niz2 = split(b, ',');
  return niz1[2] < niz2[2];
}

void kreiranjeOdeljenja(string ime, string prezime, string odeljenje) {
  int brojac;
  vector < string > linijeUcenici;
  string imeUcenika, prezimeUcenika, ucenikKorisnicko, ucenikPass;
  cout << "Unesite broj učenika odeljenja " + odeljenje + ": ";
  cin >> brojac;
  for (int i = 0; i < brojac; i++) {
    cout << "Unesite ime " << i + 1 << ". učenika: ";
    cin >> imeUcenika;
    cout << "Unesite prezime " << i + 1 << ". učenika: ";
    cin >> prezimeUcenika;
    cout << "Unesite korisničko ime " << i + 1 << ". učenika: ";
    cin >> ucenikKorisnicko;
    cout << "Unesite lozinku " << i + 1 << ". učenika: ";
    cin >> ucenikPass;
    cout << endl;
    ofstream bazaroditelja;
    bazaroditelja.open("roditelji.txt", ios::app);
    bazaroditelja << (to_string(i + 1) + "," + odeljenje + "," + ucenikKorisnicko + "," + ucenikPass + "\n");
    bazaroditelja.close();
    linijeUcenici.push_back((to_string(i + 1) + "," + imeUcenika + "," + prezimeUcenika));
  };

  std::sort(linijeUcenici.begin(), linijeUcenici.end(), sortPrezime);

  ofstream bazaodeljenja;
  bazaodeljenja.open(odeljenje + ".txt", ios::app);
  for (string linija: linijeUcenici) bazaodeljenja << linija << endl;
  bazaodeljenja.close();

  cout << "Uspešno ste snimili vaše odeljenje." << endl;
  cout << "Bićete preusmereni u glavni meni." << endl;
  glavniMeni(ime, prezime, odeljenje);
};

void ispisUcenika(string ime, string prezime, string odeljenje) {
  cout << "Učenici koji pohađaju " << odeljenje << " odeljenje su:" << endl;
  string x;
  ifstream baza(odeljenje + ".txt");
  if (baza.is_open()) {
    while (getline(baza, x)) {
      vector < string > niz = split(x, ',');
      string id = niz[0];
      string imeUcenika = niz[1];
      string prezimeUcenika = niz[2];
      cout << id << ". " << imeUcenika << " " << prezimeUcenika << endl;
    };
  };
  glavniMeni(ime, prezime, odeljenje);
}

void upisKontrolni(string ime, string prezime, string odeljenje) { 
  vector < string > fajl;
  string x;
  bool imaUcenika = false;
  
  ifstream baza(odeljenje + ".txt");
  if (baza.is_open()) {
    while (getline(baza, x)) {
      vector<string> n = split(x, ',');
      imaUcenika = true;
      cout << "Ocena za ucenika " << n[0] << ": ";
      int ocena;
      cin >> ocena;
      fajl.push_back(x + "," + to_string(ocena));
    }
  };
  
  if (!imaUcenika) {
    cout << "Odeljenje nema učenike." << endl;
    cout << "Bićete preusmereni u glavni meni." << endl;
    return glavniMeni(ime, prezime, odeljenje);
  }

  ofstream baza2;
  baza2.open(odeljenje + ".txt");
  for (string linija: fajl) baza2 << linija << endl;
  baza2.close();

  cout << endl << "Ocene su uspešno zabeležene." << endl;
  cout << "Bićete preusmereni u glavni meni." << endl;
  glavniMeni(ime, prezime, odeljenje);
}

void upisOcena(string ime, string prezime, string odeljenje) { 
  int redniBroj, brojOcena;
  cout << "Unesite redni broj učenika: ";
  cin >> redniBroj;
  cout << "Unesite broj ocena za upis: ";
  cin >> brojOcena;
  cout << endl;
  vector < double > ocene;
  for (int i = 0; i < brojOcena; i++) {
    double ocena;
    cout << "Unesite " << i + 1 << ". ocenu: ";
    cin >> ocena;
    ocene.push_back(ocena);
  }

  vector < string > fajl;
  string x;
  bool postoji = false;
  ifstream baza(odeljenje + ".txt");
  if (baza.is_open()) {
    while (getline(baza, x)) {
      postoji = true;
      fajl.push_back(x);
    }
  };
  if (!postoji) {
    cout << "Odeljenje nema učenike." << endl;
    cout << "Bićete preusmereni u glavni meni." << endl;
	  return glavniMeni(ime, prezime, odeljenje);
  }
  int _id = -1;
  bool pronadjen = false;

  for (string xx: fajl) {
    vector<string> n = split(xx, ',');
    if (std::atoi(n[0].c_str()) == redniBroj) {
      pronadjen = true;
      _id++;
    } else {
      if (!pronadjen) _id++;
    }
  }

  if (!pronadjen) {
    cout << endl << "Učenik pod tim rednim brojem nije pronađen." << endl;
    cout << "Bićete preusmereni u glavni meni." << endl;
    glavniMeni(ime, prezime, odeljenje);
  }

  for (int ocena: ocene) {
    fajl[_id] = fajl[_id] + "," + to_string(ocena);
  }

  ofstream baza2;
  baza2.open(odeljenje + ".txt");
  for (string linija: fajl) baza2 << linija << endl;
  baza2.close();

  cout << endl << "Ocene su uspešno zabeležene." << endl;
  cout << "Bićete preusmereni u glavni meni." << endl;
  glavniMeni(ime, prezime, odeljenje);
}

void izborNasumicnogUcenika(string ime, string prezime, string odeljenje) { 
  string x;
  vector < string > linije;
  bool kreiranoOdeljenje = false;
  ifstream baza(odeljenje + ".txt");
  if (baza.is_open()) {
    while (getline(baza, x)) {
      kreiranoOdeljenje = true;
      linije.push_back(x);
    }
  }
  baza.close();
  if (!kreiranoOdeljenje) {
    cout << "Odeljenje nema učenike." << endl;
    cout << "Bićete preusmereni u glavni meni." << endl;
    return glavniMeni(ime, prezime, odeljenje);
  }
  srand(time(0));
  int uc = rand() % linije.size();
  string ucenik = linije[uc];
  vector < string > niz = split(ucenik, ',');

  cout << "Izabran: " << niz[1] << " " << niz[2] << endl;

  vector < double > ocene;
  for (int i = 3; i < niz.size(); i++) {
    ocene.push_back(std::stod(niz[i]));
  }
  cout << "Ocene: ";
  for (int i = 0; i < ocene.size(); i++) i + 1 == ocene.size() ? cout << ocene[i] : cout << ocene[i] << ", ";
  cout << endl;

  int sum = std::accumulate(ocene.begin(), ocene.end(), 0);
  float prosek = (double) sum / ocene.size();

  cout << "Prosek: " << prosek << endl;

  cout << "Uspeh je " << (prosek >= 4.50 ? "odličan" : prosek >= 3.50 ? "vrlodobar" : prosek >= 2.50 ? "dobar" : prosek >= 1.50 ? "dovoljan" : "nedovoljan") << "." << endl;
  return glavniMeni(ime, prezime, odeljenje);
}

void izborUcenika(string ime, string prezime, string odeljenje) { 
  int redniBroj;
  cout << "Unesite redni broj učenika: ";
  cin >> redniBroj;
  string x;
  vector < string > linije;
  bool kreiranoOdeljenje = false;
  ifstream baza(odeljenje + ".txt");
  if (baza.is_open()) {
    while (getline(baza, x)) {
      kreiranoOdeljenje = true;
      linije.push_back(x);
    }
  }
  baza.close();
  if (!kreiranoOdeljenje) {
    cout << "Odeljenje nema učenike." << endl;
    cout << "Bićete preusmereni u glavni meni." << endl;
    return glavniMeni(ime, prezime, odeljenje);
  }
  srand(time(0));
  bool pronadjen = false;
  int uc = -1;
  for (string xx: linije) {
    vector<string> n = split(xx, ',');
    if (std::atoi(n[0].c_str()) == redniBroj) {
      pronadjen = true;
      uc++;
    } else {
      if (!pronadjen) uc++;
    }
  }
  if (!pronadjen) {
    cout << "Taj učenik ne postoji." << endl;
    cout << "Bićete preusmereni u glavni meni." << endl;
    return glavniMeni(ime, prezime, odeljenje);
  }
  
  string ucenik = linije[uc];
  vector < string > niz = split(ucenik, ',');

  cout << "Informacije: " << niz[1] << " " << niz[2] << endl;

  vector < double > ocene;
  for (int i = 3; i < niz.size(); i++) {
    ocene.push_back(std::stod(niz[i]));
  }
  cout << "Ocene: ";
  for (int i = 0; i < ocene.size(); i++) i + 1 == ocene.size() ? cout << ocene[i] : cout << ocene[i] << ", ";
  cout << endl;

  int sum = std::accumulate(ocene.begin(), ocene.end(), 0);
  float prosek = (double) sum / ocene.size();

  cout << "Prosek: " << prosek << endl;

  cout << "Uspeh je " << (prosek >= 4.50 ? "odličan" : prosek >= 3.50 ? "vrlodobar" : prosek >= 2.50 ? "dobar" : prosek >= 1.50 ? "dovoljan" : "nedovoljan") << "." << endl;
  return glavniMeni(ime, prezime, odeljenje);
}

void glavniMeni(string ime, string prezime, string odeljenje) {
  cout << "\n====================";
  cout << "eDnevnik v1.0";
  cout << "====================" << endl;
  cout << "Dobro došli, " + ime + " " + prezime + "!" << endl;
  cout << "Vaše odeljenje je " + odeljenje << "." << endl << endl;
  cout << "1 - Upisivanje učenika u odeljenje" << endl;
  cout << "2 - Ispis svih učenika odeljenja" << endl;
  cout << "3 - Upisivanje ocena učeniku" << endl;
  cout << "4 - Upisivanje ocena sa kontrolnog zadatka" << endl;
  cout << "5 - Pregled učenika" << endl;
  cout << "6 - Izbor nasumičnog učenika" << endl;
  cout << "7 - Promena lozinke" << endl;
  cout << "0 - Odjava" << endl << endl;
  cout << "Opcija - ";
  int opcija;
  cin >> opcija;
  if (opcija == 1) return kreiranjeOdeljenja(ime, prezime, odeljenje);
  if (opcija == 2) return ispisUcenika(ime, prezime, odeljenje);
  if (opcija == 3) return upisOcena(ime, prezime, odeljenje);
  if (opcija == 4) return upisKontrolni(ime, prezime, odeljenje);
  if (opcija == 5) return izborUcenika(ime, prezime, odeljenje);
  if (opcija == 6) return izborNasumicnogUcenika(ime, prezime, odeljenje);
  if (opcija == 7) return promenaSifreProfesora(ime, prezime, odeljenje);
  if (opcija == 0) return;
};

void registracijaProfesora() {
  string imeProf, prezimeProf, korisnickoProf, lozinkaProf, oznakaOdeljenja;
  cout << "Unesite korisničko ime: ";
  cin >> korisnickoProf;
  cout << "Unesite lozinku: ";
  cin >> lozinkaProf;
  cout << "Unesite Vaše ime: ";
  cin >> imeProf;
  cout << "Unesite Vaše prezime: ";
  cin >> prezimeProf;
  cout << "Unesite oznaku Vašeg odeljenja: ";
  cin >> oznakaOdeljenja;
  ofstream bazaProfesora;
  bazaProfesora.open("profesori.txt", ios::app);
  bazaProfesora << korisnickoProf << "," << lozinkaProf << "," << imeProf << "," << prezimeProf << "," << oznakaOdeljenja << "\n";
  bazaProfesora.close();
  ofstream kreiranjeodeljenja;
  kreiranjeodeljenja.open(oznakaOdeljenja + ".txt");
  kreiranjeodeljenja.close();
  cout << endl << "Uspešno ste registrovani u sistem." << endl;
  cout << "Bićete preusmereni u meni za ulaz u sistem." << endl;
  pocetniMeni();
};

void prijavaProfesora() {
  string korisnickoProf, lozinkaProf, x;
  int linija = 0;
  cout << "Unesite Vaše korisničko ime: ";
  cin >> korisnickoProf;
  cout << "Unesite Vašu lozinku: ";
  cin >> lozinkaProf;
  string stringzapretrazivanje = korisnickoProf + "," + lozinkaProf;
  ifstream baza("profesori.txt");
  string profIme, profPrezime, profOdeljenje;
  if (baza.is_open()) {
    bool tacnost = false;
    while (getline(baza, x)) {
      if (x.find(stringzapretrazivanje, 0) != string::npos) {
        cout << "Uspešno ste se ulogovali!" << endl;
        vector < string > niz = split(x, ',');
        profIme = niz[2];
        profPrezime = niz[3];
        profOdeljenje = niz[4];
        tacnost = true;
        break;
      };
      linija++;
    };
    if (!tacnost) {
      cout << "Uneli ste pogrešno korisničko ime ili lozinku." << endl;
      cout << "Bićete preusmereni u meni za ulaz u sistem." << endl;
    } else {
      glavniMeni(profIme, profPrezime, profOdeljenje);
    }
    baza.close();
    pocetniMeni();
  };
};

void prijavaRoditelja() {
  string korisnickoRoditelj, lozinkaRoditelj, x;
  int linija = 0;
  cout << "Unesite Vaše korisničko ime: ";
  cin >> korisnickoRoditelj;
  cout << "Unesite Vašu lozinku: ";
  cin >> lozinkaRoditelj;
  ifstream baza("roditelji.txt");
  if (baza.is_open()) {
    bool tacnost = false;
    while (getline(baza, x)) {
      vector < string > niz = split(x, ',');
      if (niz[2] == korisnickoRoditelj && niz[3] == lozinkaRoditelj) {
        cout << "Uspešno ste se ulogovali!" << endl;
        meniRoditelj(niz[0], niz[1], niz[2]);
        tacnost = true;
        break;
      };
      linija++;
    };
    if (!tacnost) {
      cout << "Uneli ste pogrešno korisničko ime ili lozinku." << endl;
      cout << "Bićete preusmereni u meni za ulaz u sistem." << endl;
    };
    baza.close();
    pocetniMeni();
  };
};

void pocetniMeni() {
  cout << "\n====================";
  cout << "eDnevnik v1.0";
  cout << "====================" << endl;
  cout << "Dobro došli u elektronski dnevnik." << endl;
  cout << "Autor projekta Veljko Dragićević II7" << endl << endl;
  cout << "Odaberite opciju za ulaz u sistem:" << endl;
  cout << "1 - Registracija novog profesora" << endl;
  cout << "2 - Prijava postojećim podacima" << endl;
  cout << "3 - Prijava na roditeljski nalog" << endl;
  cout << "0 - Kraj rada" << endl << endl;
  cout << "Opcija - ";
  int opcija;
  cin >> opcija;
  if (opcija == 1) return registracijaProfesora();
  if (opcija == 2) return prijavaProfesora();
  if (opcija == 3) return prijavaRoditelja();
};

int main() {
  pocetniMeni();
};
