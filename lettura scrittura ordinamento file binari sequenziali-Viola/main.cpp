#include <iostream>
#include <fstream>
#define DIM 20


using namespace std;
const string DATABASE= "serie_a.dat";int n=0;

struct Squadra
{
    string nome;
    int punti;
    string capocannoniere;
    int gol;
}squadre[DIM];




void input()
{int a;

    fstream miofile;
    miofile.open(DATABASE.c_str(),ios::app | ios::binary);

    do{
        fflush(stdin);
        cout << "Inserisci squadra:";
       getline(cin,squadre[n].nome);
       cout << "Inserisci punti:";
       cin>>squadre[n].punti;
       fflush(stdin);
       cout << "Inserisci capocannoniere:";
       getline(cin,squadre[n].capocannoniere);
       cout << "Inserisci numero goal:";
       cin>>squadre[n].gol;
       n++;

   if(n!=DIM)
    {
        cout<<"Premere 1 per inserire la prossima squadra, altrimenti 0: ";
        cin>>a;
    }
    else
        a=0;

    }while(a==1);

    if(!miofile)

       cout<<"Errore nel apertura del file!"<<endl;

    else
    {
        for(int c=0;c<n;c++)
            miofile.write((char*)&squadre,sizeof(squadre));
            //miofile<<"Squadra:"<<squadre[c].nome<<";"<<"Punti:"<<squadre[c].punti<<";"<<"Capocannoniere:"<<squadre[c].capocannoniere<<";"<<"Goal:"<<squadre[c].gol<<";"<<endl;
    }

miofile.close();
}

void classifica()
{string tempstring;int tempint;

     for(int j=0; j<=n; j++)
         for(int k=j+1 ; k<n; k++)
            if(squadre[j].punti<squadre[k].punti)
            {
                tempint=squadre[j].punti;
                squadre[j].punti=squadre[k].punti;
                squadre[k].punti=tempint;

                tempstring=squadre[j].nome;
                squadre[j].nome=squadre[k].nome;
                squadre[k].nome=tempstring;

                tempint=squadre[j].gol;
                squadre[j].gol=squadre[k].gol;
                squadre[k].gol=tempint;

                tempstring=squadre[j].capocannoniere;
                squadre[j].capocannoniere=squadre[k].capocannoniere;
                squadre[k].capocannoniere=tempstring;
            }
cout<<"\t\t CLASSIFICA SERIE A"<<endl;

                for(int a=0;a<n;a++)
                    {
                        cout<<squadre[a].punti<<"   ";
                        cout<<squadre[a].nome<<endl;
                    }
}

void capocannonieri()
{string tempstring;int tempint;

     for(int j=0; j<=n; j++)
         for(int k=j+1 ; k<n; k++)
            if(squadre[j].gol<squadre[k].gol)
            {
                tempint=squadre[j].punti;
                squadre[j].punti=squadre[k].punti;
                squadre[k].punti=tempint;

                tempstring=squadre[j].nome;
                squadre[j].nome=squadre[k].nome;
                squadre[k].nome=tempstring;

                tempint=squadre[j].gol;
                squadre[j].gol=squadre[k].gol;
                squadre[k].gol=tempint;

                tempstring=squadre[j].capocannoniere;
                squadre[j].capocannoniere=squadre[k].capocannoniere;
                squadre[k].capocannoniere=tempstring;
            }
cout<<"\t\t CLASSIFICA MARCATORI SERIE A"<<endl;
                for(int a=0;a<n;a++)
                    {
                        cout<<squadre[a].gol<<"   ";
                        cout<<squadre[a].capocannoniere<<"   ";
                        cout<<squadre[a].nome<<endl;
                    }

}

void lettura()
{string stringa;
int a=0;

    fstream miofile;
    miofile.open(DATABASE.c_str(),ios::in | ios::binary);
    if(!miofile)
        cout<<"Errore nell'apertura del file";
    else
    {
     cout<<"\t\t\tSTAMPA DI TUTTE LE SQUADRE"<<endl;
        while(miofile.read((char*)&squadre,sizeof(squadre)))
        {
            cout<<"Nome:"<<squadre[a].nome<<endl<<"Punti: "<<squadre[a].punti<<endl
            <<"Capocannoniere: "<<squadre[a].capocannoniere<<endl<<"Gol: "<<squadre[a].gol<<endl;
        a++;
        }

    }
    miofile.close();
    fflush(stdin);
}


int main()
{int scelta;

    do{
    cout << "1.Inserisci la squadra" << endl;
    cout << "2.Classifica delle squadre" << endl;
    cout << "3.Classifica dei marcatori" << endl;
    cout << "4.Leggi" << endl;
    cout << "5.Esci" << endl;
    cin>>scelta;
    switch(scelta)
    {
        case 1:input();
                    break;

        case 2:classifica();
                    break;

        case 3:capocannonieri();
                break;

        case 4: lettura();
                    break;

        case 5:cout << "Grazie e buona giornata!" << endl;
                break;
    }

    }while(scelta!=5);
    return 0;
}
