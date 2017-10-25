#include<iostream>
using namespace std;
class Profesional{
  protected:
    string certificado;//codigo de su certificado
    int graduado;//ano que se graduo
  public:
    Profesional(string mycertificado, int mygraduado)//constructor
      : certificado(mycertificado),graduado(mygraduado){}
      virtual void mostrar(){//virtual ayuda a eliminar el problema diamante en funciones
        cout<<certificado<<" "<<graduado<<endl;//salida de datos
      }
      virtual void rellenar(){
        cin>>certificado>>graduado;//entrada de datos
      }
};
class Ingeniero: public Profesional{
  protected:
    string codigo_ingeniero;//numero de ingeniero
  public:
    Ingeniero(string mycertificado, int mygraduado, string mycodigo_ingeniero)//constructor
      :Profesional(mycertificado,mygraduado), codigo_ingeniero(mycodigo_ingeniero){}
    virtual void mostrar(){
      cout<<certificado<<" "<<graduado<<" "<<codigo_ingeniero<<endl;//salida de datos
    }
    virtual void rellenar(){
      cin>>certificado>>graduado>>codigo_ingeniero;//entrada de datos
    }
  
    
};
class medico: public Profesional{
  protected:
  string codigo_medico;//numero de medico
  public:
    medico(string mycertificado, int mygraduado, string mycodigo_medico)//constructor
    :Profesional(mycertificado,mygraduado), codigo_medico(mycodigo_medico){}
    virtual void mostrar(){
      cout<<certificado<<" "<<graduado<<" "<<codigo_medico<<endl;
    }
    virtual void rellenar(){
      cin>>certificado>>graduado>>codigo_medico;//entrada de datos
    }
};
class medicoIngeniero: public virtual Ingeniero,public medico{
  public:
    medicoIngeniero(string mycertificado, int mygraduado, string mycodigo_medico, string mycodigo_ingeniero)//constructor
      :Ingeniero(mycertificado,mygraduado,mycodigo_ingeniero),medico(mycertificado,mygraduado,mycodigo_medico){}
    void mostrar(){//salida de datos
        cout<<Ingeniero::certificado<<" "<<Ingeniero::graduado<<" "<<codigo_ingeniero<<" "<<codigo_medico<<endl;
    }
    void rellenar(){//entrada de datos
      cin>>Ingeniero::certificado>>Ingeniero::graduado>>codigo_ingeniero>>codigo_medico;
    }
};

int main(){
  medicoIngeniero a("dfsd1",2,"3fdsfd","4sfds");
  a.mostrar();
}
