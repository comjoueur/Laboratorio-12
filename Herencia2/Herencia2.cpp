#include<iostream>
using namespace std;
class Profesional{
  protected:
    string certificado;//codigo de su certificado
    int graduado;//ano que se graduo
  public:
    Profesional(string mycertificado, int mygraduado)//constructor
      : certificado(mycertificado),graduado(mygraduado){}
      void mostrar1(){//virtual ayuda a eliminar el problema diamante en funciones
        cout<<certificado<<" "<<graduado<<endl;//salida de datos
      }
      void rellenar1(){
        cin>>certificado>>graduado;//entrada de datos
      }
};
class Ingeniero: public Profesional{//caracteristicas de Profesional heredadas en modo publico
  protected:
    string codigo_ingeniero;//numero de ingeniero
  public:
    Ingeniero(string mycertificado, int mygraduado, string mycodigo_ingeniero)//constructor
      :Profesional(mycertificado,mygraduado), codigo_ingeniero(mycodigo_ingeniero){}
    void mostrar(){
      cout<<certificado<<" "<<graduado<<" "<<codigo_ingeniero<<endl;//salida de datos
    }
    void rellenar(){
      cin>>certificado>>graduado>>codigo_ingeniero;//entrada de datos
    }
  
    
};
class Medico: private Profesional{//caracteristicas de Profesional heredadas en modo privado es el de defecto
  protected:
    string codigo_medico;//numero de medico
  public:
    Medico(string mycertificado, int mygraduado, string mycodigo_medico)//constructor
    :Profesional(mycertificado,mygraduado), codigo_medico(mycodigo_medico){}
    void mostrar(){
      cout<<certificado<<" "<<graduado<<" "<<codigo_medico<<endl;
    }
    void rellenar(){
      cin>>certificado>>graduado>>codigo_medico;//entrada de datos
    }
};
class Abogado: protected Profesional{//caracteristicas de Profesional heredas en modo protegido es decir heredadas a este y a sus hijas
  protected:
    string codigo_abogado;
  public:
    Abogado(string mycertificado, int mygraduado, string mycodigo_abogado)//constructor
      :Profesional(mycertificado,mygraduado),codigo_abogado(mycodigo_abogado){}
    void mostrar(){//salida de datos
        cout<<certificado<<" "<<graduado<<" "<<codigo_abogado<<endl;
    }
    void rellenar(){//entrada de datos
      cin>>certificado>>graduado>>codigo_abogado;
    }
};
class Jurado:private Abogado{//caracteristicas de abogado heredadas en modo privado
  private:
    string codigo_jurado;
  public:
    Jurado(string mycertificado,int mygraduado,string mycodigo_abogado,string mycodigo_jurado)
    :Abogado(mycertificado,mygraduado,mycodigo_abogado),codigo_jurado(mycodigo_jurado){}
    void mostrar2(){
      cout<<certificado<<" "<<graduado<<" "<<codigo_abogado<<" "<<codigo_jurado<<endl;
    }
};
int main(){
  Medico a("gdggf",1939,"fj49");
  a.mostrar();
  //a.mostrar1(); no se puede hacer esto
  Jurado b("ckso",1843,"dfdf","sodjs");
  b.mostrar2();
  //b.mostrar1(); no se puede hacer esto
  Ingeniero c("gfgdgfg",1954,"dfdggssdr");
  c.mostrar1();
  c.mostrar();
}
