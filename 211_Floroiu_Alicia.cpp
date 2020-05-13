#include <iostream>

using namespace std;


class Nod
{
protected:
    int info ;
    Nod* next ;
public:
    Nod();
    Nod (int);
    Nod(int info, Nod* next);
    Nod(Nod &nod);
    virtual ~Nod();
    Nod& operator =(Nod& nod);
    int getInfo();
    void setInfo (int info);
    Nod* getNext();
    void setNext (Nod* next);
    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
    friend istream& operator>>(istream&, Nod&);
    friend ostream& operator<<(ostream&, Nod&);

} ;
Nod::Nod()
{
    info = 0;
    next = 0;

}
Nod::Nod(int info)
{
    this ->info = info;
    this ->next = NULL;
}
Nod::Nod(int info, Nod* next)
{
    this->info = info;
    this->next = next;

}
Nod::Nod(Nod &nod)
{
    this->next = nod.next;
    this->info = nod.info;
}
Nod::~Nod()
{

}
Nod& Nod::operator =(Nod &nod)
{
    info = nod.info;
    next = nod.next;
}
int Nod::getInfo()
{
    return info;
}
void Nod::setInfo(int info)
{
    this->info = info;
}
Nod* Nod::getNext()
{
    return next;
}
void Nod::setNext(Nod* next)
{
    this->next = next;
}

void Nod::citire(istream& in)
{
    cout<<"nod = ";
    in>>info;

}
istream& operator>>(istream& in,Nod& nod)
{
    nod.citire(in);
    return in;
}
void Nod::afisare(ostream& out)
{

    out<<"Nodul este: ";
    out<<info;
}
ostream& operator<<(ostream& out,Nod& nod)
{
    nod.afisare(out);
    return out;
}


class Nod_dublu : public Nod
{
private:
    Nod* ante;
public:
    Nod_dublu();
    Nod_dublu(int);
    Nod_dublu(int, Nod*, Nod*);
    Nod_dublu(Nod_dublu& nod);
    Nod_dublu& operator =(Nod_dublu& nod);
    ~Nod_dublu();
    Nod* get_Nod_ante();
    void set_Nod_ante(Nod* ante);
    void citire(istream &in);
    void afisare(ostream& out);
    friend istream& operator>>(istream&, Nod_dublu&);
    friend ostream& operator<<(ostream&, Nod_dublu&);
};
Nod_dublu::Nod_dublu():Nod()
{
    ante = 0;
}
Nod_dublu::Nod_dublu(int info):Nod(info)
{
    this ->ante = NULL;
}
Nod_dublu::Nod_dublu(int info,Nod* next,Nod* ante):Nod(info, next)
{
    this->ante=ante;
}
Nod_dublu::Nod_dublu( Nod_dublu& nod):Nod(nod)
{
    this -> ante = nod.ante;
}
Nod_dublu& Nod_dublu::operator=(Nod_dublu& nod)
{
    Nod::operator=(nod);
    ante = nod.ante;
}
Nod_dublu::~Nod_dublu()
{

}

Nod* Nod_dublu::get_Nod_ante()
{
    return ante;
}
void Nod_dublu::set_Nod_ante(Nod* ante)
{
    this->ante = ante;
}
void Nod_dublu::citire(istream& in)
{
    cout<<"se da un nod dublu: "<<endl;
    Nod::citire(in);

}
istream& operator>>(istream& in, Nod_dublu& nod)
{
    nod.citire(in);
    return in;
}
void Nod_dublu::afisare(ostream& out)
{
    Nod::afisare(out);
}
ostream& operator<<(ostream& out,Nod_dublu& nod)
{
    nod.afisare(out);
    return out;
}
class List
{
protected:

    Nod_dublu* primul  ;
    Nod_dublu* ultimul ;
    static int inserari;

public:
    List();
    List(Nod_dublu* primul,Nod_dublu* ultimul);
    List(const List &lista);
    virtual ~List();
    List& operator =(const List &L);
    static int totalinserari();
    virtual int numar_noduri();
    virtual void inserareFinal(int info);
    virtual void Delete(Nod_dublu* nod);
    virtual void citire(istream &in);
    virtual void afisare(ostream &out,Nod_dublu* element_curent);
    friend istream& operator>>(istream&, List&);
    friend ostream& operator<<(ostream&, List&);

};
int List::inserari;
inline List::List()
{

    this->primul=NULL;
    this->ultimul=NULL;

}

inline List::List(Nod_dublu* primul,Nod_dublu* ultimul)
{

    this->primul = primul;
    this->ultimul = ultimul;

}
inline List::List(const List &lista)
{
    Nod_dublu* nod = lista.primul;
    while(nod!=lista.ultimul)
    {
        inserareFinal(nod->getInfo());
        nod = (Nod_dublu*)nod->getNext();
    }
    inserareFinal(nod->getInfo());
}
inline void List::Delete(Nod_dublu* nod)
{
    nod = primul;
    while(nod != ultimul)
    {
        Nod_dublu* node;
        node = (Nod_dublu*) nod ->getNext();
        delete nod;
        nod = node;
    }
    if(nod == ultimul)
    {
        delete nod;

    }
}
inline List& List::operator=(const List& lista)
{

    Nod_dublu* nod = primul;

    while(nod!=ultimul)
    {
        Delete(nod);
    }

    Delete(nod);

    if(lista.primul == NULL)
    {
        primul = NULL;
        ultimul = NULL;
    }
    else
    {
        nod = lista.primul;
        while(nod!=lista.ultimul)
        {
            inserareFinal(nod->getInfo());
            nod=(Nod_dublu*)nod->getNext();

        }
        inserareFinal(nod->getInfo());

    }


}
inline List::~List()
{
    Nod_dublu* nod = primul;
    while(nod != ultimul)
    {
        Nod_dublu* node;
        node = (Nod_dublu*) nod ->getNext();
        delete nod;
        nod = node;
    }
    if(nod == ultimul)
    {
        delete nod;

    }

}

inline void List :: inserareFinal(int info)
{
    inserari++;
    Nod_dublu* element_final = new Nod_dublu(info);

    if( primul== NULL)
    {
        primul = element_final;
        ultimul = element_final;
    }

    else
    {
        element_final->set_Nod_ante(ultimul);
        ultimul->setNext(element_final);
        ultimul = element_final;

    }

}
inline List::numar_noduri()
{
    int numar = 0;
    Nod_dublu* nod = primul;
    if(primul == NULL)
        return 0;
    while(nod!=ultimul)
    {
        numar++;
        nod= (Nod_dublu*)nod->getNext();
    }
    numar++;
    return numar;

}

inline int List::totalinserari()
{
    return inserari;
}


inline void List::citire(istream& in )
{
        int date;
        in>>date;

        inserareFinal(date);

}
istream& operator>>(istream& in, List& lista)
{
    lista.citire(in);
    return in;
}
inline void List::afisare(ostream& out,Nod_dublu* element_curent)
{
    out<<element_curent->get_Nod_ante()<<" "<<element_curent->getInfo()<<" "<<element_curent->getNext()<<" "<<endl;


}
inline ostream& operator<<(ostream& out, List& lista)
{
    Nod_dublu* nod= lista.primul;
    while(nod!=lista.ultimul)
    {
        lista.afisare(out,nod);
        nod =(Nod_dublu*)nod->getNext();
    }
    lista.afisare(out,nod);
    return out;
}

class Lista_Circulara : public List
{
public:
    Lista_Circulara();
    Lista_Circulara (Nod_dublu* primul,Nod_dublu* ultimul);
    Lista_Circulara (const Lista_Circulara &lista);
    ~Lista_Circulara();
    Lista_Circulara& operator=(const Lista_Circulara & lista);
    void inserareFinal(int info);
    int numar_noduri();
    void Delete(Nod_dublu* nod);
    void citire(istream &in);
    void  Josephus(int m);
    void afisare(ostream &out,Nod_dublu* element_curent);
    friend istream& operator>>(istream&, Lista_Circulara&);
    friend ostream& operator<<(ostream&, Lista_Circulara&);
};
inline Lista_Circulara::Lista_Circulara():List() {}
inline Lista_Circulara::Lista_Circulara(Nod_dublu* primul,Nod_dublu* ultimul):List(primul,ultimul)
{
    ultimul->setNext(primul);
    primul->set_Nod_ante(ultimul);
}
inline Lista_Circulara::Lista_Circulara(const Lista_Circulara &lista):List(lista)
{
    ultimul->setNext(primul);
    primul->set_Nod_ante(ultimul);
}
inline Lista_Circulara::~Lista_Circulara() {}
inline Lista_Circulara& Lista_Circulara ::operator=(const Lista_Circulara& lista)
{
    List::operator=(lista);

}
inline void Lista_Circulara::inserareFinal(int info)
{
    List::inserareFinal(info);
    ultimul->setNext(primul);
    primul->set_Nod_ante(ultimul);

}
inline int Lista_Circulara::numar_noduri()
{
    List::numar_noduri();
}
inline void Lista_Circulara::Delete(Nod_dublu* nod)
{
    List::Delete(nod);
}
inline void Lista_Circulara::Josephus(int m)
{
    Nod_dublu* p = primul;
    Nod_dublu* u = primul;
    while(p->getNext()!=p)
    {
        int nr = 1;
        while( nr != m )
           {
               u=p;
               p = (Nod_dublu*)p->getNext();
               nr++;
            }
            Nod_dublu* t = new Nod_dublu;
            t = (Nod_dublu*)p->getNext();
            u->setNext(t);
            p = (Nod_dublu*)u->getNext();


    }
    cout<<p->getInfo();
}


inline void Lista_Circulara::citire(istream& in)
{
    cout<<"Se da numarul de noduri:";
    int n;
    cin>> n;
    cout<<"Se dau nodurile: ";
    for(int i=0;i<n; i++)
    {
        List::citire(in);
    ultimul->setNext(primul);
    primul->set_Nod_ante(ultimul);
    }
}
inline istream& operator>>(istream& in, Lista_Circulara& lista)
{
    lista.citire(in);
    return in;
}
inline void Lista_Circulara::afisare(ostream& out, Nod_dublu* element_curent)
{
    List::afisare(out,element_curent);
}
inline ostream& operator<<(ostream& out,Lista_Circulara& lista)
{
    Nod_dublu* nod;
    nod = lista.primul;
    while(nod!=lista.ultimul)
    {
        lista.afisare(out,nod);
        nod = (Nod_dublu*)nod->getNext();

    }
    lista.afisare(out,nod);

    return out;
}
void menu_output()
{
    cout<<"\n Floroiu Alicia_211 - Proiect 2 - Nume proiect:  Clasa Lista/ListaCirculara  \n";
    cout<<"\n\t MENIU:";
    cout<<"\n-----------------------------------\n";
    cout<<"\n";
    cout<<"1. Lista dublu inlantuira"<<endl;
    cout<<"2. Lista Circulara"<<endl;
    cout<<"3. Citirea si afisarea a n lista circulare"<<endl;
    cout<<"4. Operatorul = "<<endl;
    cout<<"5. Problema lui Josephus"<<endl;
    cout<<"6. Upcast"<<endl;
    cout<<"7. Downcast"<<endl;
    cout<<"0. Iesire."<<endl;
}

void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;
    menu_output();
    do
    {


        cout<<"\nIntroduceti numarul actiunii:";

        cin>>option;

        if (option==1)
        {   int n,i;
            List L;
            cout<<"Se da numarul de noduri: ";
                cin>>n;
            cout<<"Se dau nodurile: ";
            for(i=0; i<n;i++)
                cin>>L;
            cout<<"Lista dublu inlantuira este: "<<endl;
                cout<<L;
        }

       if (option==2)
        {
             Lista_Circulara LC;

            cin>>LC;
            cout<<"Lista Circulara este:"<<endl;
            cout<<LC;

        }
        if (option==3)
        {
            int n,i, k;
            cout<<"Se da numarul de liste circulare: ";
            cin>>n;
            Lista_Circulara* LC =new Lista_Circulara[n];

            for(i = 0; i<n; i++)
            {
                cin>>LC[i];
            }
            for(int i = 0; i<n; i++)
                {
                cout<<endl;
                cout<<"lista "<<i+1<<" este: "<<endl;
                cout<<LC[i];
                cout<<endl;
                }

        }
        if(option == 4)
        {

            Lista_Circulara L1,L2;

            cin>>L1;
            L2=L1;
                int n =L2.numar_noduri();
                cout<<"Copia listei dublu inlantuira este: "<<endl;
                cout<<L2;
                cout<<"Lista L2 are "<<n<<" noduri";
        }

        if(option == 5)
        {
            int k;
            Lista_Circulara LC;
            cin>>LC;
            cout<<"Se da k = ";
            cin>>k;
            cout<<"<<Soldatul>> ramas in viata este: ";
            LC.Josephus(k);


        }

        if(option == 6)//upcast
        {
            List* L = new Lista_Circulara();
            cin>>*L;
            cout<<*L;
        }
        if(option == 7 )//downcast
        {
           /* int n,p ;
            Lista_Circulara *L = (Lista_Circulara*)new List;
            cout<<"Numar de noduri: ";
            cin>>n;
            cout<<"Nodurile sunt: ";
            for(int i=0;i<n;i++)
                cin>>*L;
            cout<<*L;*/

            List::totalinserari();

        }
        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        if (option<0||option>7)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
    }
    while(option!=0);
}

int main()
{
    menu();


return 0;
}
