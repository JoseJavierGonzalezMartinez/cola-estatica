#include <iostream>
#define TAM 50
using namespace std;

class constancia{
private:
    string nombre;
    string nomcar;
    int matap;
    float promedio;
public:
    constancia(){};
    friend ostream & operator<<(ostream &O, constancia &x){
            O<<"\n Nombre: "<<x.nombre<<"\n nombre de la carrera: "<<x.nomcar<<"\n materias aprobadas: "<<x.matap<<"\n promedio: "<<x.promedio<< endl;
            return O;
    }
    friend istream & operator>>(istream &O, constancia &x){
            cout<<"\n inserte nombre: ";
            O>>x.nombre;
            cout<<"\n inserte nombre de la carrera: ";
            O>>x.nomcar;
            cout<<"\n total de materias aprobadas: ";
            O>>x.matap;
            cout<<"\n promedio: ";
            O>>x.promedio;
            return O;
    }
};

//plantillas
template<class T>
class Cola{
private:
    T datos[TAM];
    int ult;
    bool inserta(T , int);
    bool elimina(int);
    T recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;
public:
    Cola():ult(-1){}
    bool vacia()const;
    bool llena()const;
    bool  Queue(T&);
    bool Dequeue();
   // bool emp();
    T Front()const;
};
/*template<class T>
bool Cola::emp(T){
    if(vacia(Front));
    cout<<"la cola esta vacia";
}*/

template<class T>
T Cola<T>::Front()const{
    T x=datos[primero()];
    return x;
}

template<class T>
bool Cola<T>::Dequeue(){
    if(vacia()){
        return false;
    }
    else{
        elimina(primero());
    }
    return true;
}

template<class T>
bool Cola<T>::Queue(T& elem){
    if(llena()){
        return false;
    }
    if(vacia()){
        inserta(elem,0);
    }
    else{
        inserta(elem, ultimo()+1);
    }
    return true;
}

template<class T>
void Cola<T>::imprime()const{
    if(!vacia()){
        for(int i=0; i<=ult; i++){
            constancia x=datos[i];
            cout<<x<<endl;
        }
    }
}

template<class T>
bool Cola<T>::vacia()const{
    return ult==-1;
}

template<class T>
bool Cola<T>::llena()const{
    return ult==TAM-1;
}

template<class T>
bool Cola<T>::inserta(T elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        cout<<"\n No se pudo insertar";
        return false;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

template<class T>
bool Cola<T>::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
        cout<<"\n No se pudo eliminar";
        return false;
    }
    int i=pos;
    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

template<class T>
T Cola<T>::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

template<class T>
int Cola<T>::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}

template<class T>
int Cola<T>::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}

int main()
{
    int o;
    Cola<constancia> MiCola;
    constancia x;
    while(o!=3){
    cout<<"que opcion desea realizar "<<endl;
    cout<<"1.-alta"<<endl<<"2.-mostrar"<<endl<<"3.-salir"<<endl;
    cin>>o;
    switch(o){
    case 1:
    system("cls");
    cout<<"\n AColacion"<<endl;

        cin>>x;
        MiCola.Queue(x);

    break;
    case 2:
    system("cls");
    if(MiCola.vacia()!=true){
    cout<<"\n\n\n DesaColado"<<endl;

        x=MiCola.Front();
        cout<<x<<endl;
        MiCola.Dequeue();
        }

    else;
        cout<<"la cola esta vacia"<<endl;
    break;
    case 3:
    system("cls");
    cout<<"adios"<<endl;
    break;
    default:
        system("cls");
        cout<<"la opcion no esxiste"<<endl;
        break;
    }
    }
    return 0;
}
