#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#define MAX 200

struct Rubrica {
	int codiceContatto;
	int n_telefono;
	char nome[30];
	char cognome[50];
	};

void inserimento(Rubrica contatto[], int &indice_contatti, int contatti_da_inserire);
void scriviSuFile(Rubrica contatto[], int indice_contatti);
void leggiDaFile();
int chiediCodice() ;
void cercaContatto(int codice) ;
void stampa(Rubrica elemento);
int menu();
int chiediNumeroContatti();


int main()
{

	Rubrica contatto[MAX];

	int indice_contatti = 0;

	int scelta;

	do
		{
		scelta = menu();
		switch(scelta) {
			case 0: cout<<"Fine Sessione\n";
				break;
			case 1: {
				int contatti_da_inserire = chiediNumeroContatti();
				inserimento(contatto, indice_contatti, contatti_da_inserire);
				scriviSuFile(contatto, indice_contatti);
				break;
				}
			case 2: leggiDaFile();
				break;
			case 3: {
				 int codice_da_trovare = chiediCodice ( );
                cercaContatto ( codice_da_trovare );
				}
				break;
		}
	} while(scelta != 0);

    return 0;
}


void inserimento(Rubrica contatto[], int &indice_contatti, int contatti_da_inserire) {
    char esci;
	Rubrica elemento;
	int contatti_inseribili = MAX - indice_contatti;

	if (contatti_da_inserire <= contatti_inseribili) {
		int i = indice_contatti;
		int j = 1;
		while (i < indice_contatti + contatti_da_inserire)
		{
			cout << "per inserire l'elemento n. " << j <<" premere il tasto \"n\", altrimenti 'q' per terminare : ";
			cin >> esci;
			cout<<endl;

			if (esci == 'n')
			{
				cout << "\nelemento n. " <<j;
				cout << "\nInserisci nome : ";
				cin.ignore();
				cin.getline(elemento.nome, 30);
				cout << "\nInserisci cognome : ";
				cin.getline(elemento.cognome, 50);
				cout << "\nInserisci il numero di telefono : ";
				cin >> elemento.n_telefono;
				elemento.codiceContatto = i+1;
			}
			else
			{
				cout << "inseriti  n. "<< j-1 <<" contatti terminato";
				break;
			}
			contatto[i] = elemento;
			i++;
			j++;
		} indice_contatti = i;

	}
}

void scriviSuFile(Rubrica contatto[], int indice_contatti) {
	fstream f_out("Rubrica.dat", ios::out | ios::binary);

	if(f_out) {
		for(int j=0; j<indice_contatti; j++){
			f_out.write( (char*) &contatto[j], sizeof(contatto[j]) );
		}
		f_out.close();
	}
	else
		cout<<"File Rubrica.dat non creato"<< endl;
}

void leggiDaFile() {
	fstream f_in("Rubrica.dat", ios::in | ios::binary);
	Rubrica elemento;

	if(f_in) {
		while( f_in.read((char*) &elemento, sizeof(elemento)) ) {
			stampa(elemento);
		}
		f_in.close();
	}
	else
		cout<<"il file Rubrica.dat non esiste"<< endl;
}

void stampa(Rubrica elemento) {
		cout << "----------------" << endl;
		cout << "Contatto n. "<< elemento.codiceContatto <<endl;
		cout << "Nome   : " << elemento.nome <<endl;
		cout << "Cognome: " << elemento.cognome <<endl;
		cout << "Numero di telefono : " << elemento.n_telefono <<endl;
}


void cercaContatto(int codice) {
	fstream f_in("Rubrica.dat", ios::in | ios::binary);
	Rubrica elemento;

	if(f_in) {
		while( f_in.read((char*) &elemento, sizeof(elemento)) ) {
			if(elemento.codiceContatto==codice) {
				cout << "Elemento trovato!" << endl;
				stampa(elemento);
				break;
			}

		}
		f_in.close();
	}
	else
		cout<<"il file Rubrica.dat non esiste"<< endl;
}

int menu() {

	char scelta;
    cout << "\nMENU CONTATTI";
    cout << "\n1. Inserimento contatto";
    cout << "\n2. Stampa rubrica";
    cout << "\n3. Ricerca contatto";
    cout << "\n0. ESCI\n";

	// con il seguente ciclo ci assicuriamo che l'utente inserisca
	// un carattere compreso tra '0' e '3'
	do {
		cout<<"inserisci un numero compreso tra 0 e 3\n";
		cin>>scelta;
	} while(scelta <48 || scelta >52);

	// la differenza scelta - '0' sarà un numero intero compreso tra  0 e 8
	return scelta - '0';
}

int chiediNumeroContatti()  {
    int nun_contatti;
	cout << "quanti contatti vuoi inserire? :";
    cin >> nun_contatti;
	cout << endl;
	return nun_contatti;
}

int chiediCodice()
{
     int codice;
     cout <<"Inserire qui il codice del contatto";
     cin>>codice;
     return codice;
}
