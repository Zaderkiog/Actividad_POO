#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Organizacion {
 private:
   string name;
   Nomina nomina;
   int nit;
};

class Nomina {
 private:
 vector<Empleado*> Empleados;
 Organizacion* organizacion;
 public:
 /* & : El parametro de _empleados es una referencia constante a un vector de punteros a Empleado
  Evita copiar el vector y garantiza que no se modificara dentro del constructor.
  &_empleados referencia a un espacio de memoria de X empleado (Por ejemplo Empleado("Juan")), el apuntador toma ese espacio de memoria referenciado
  para evitar trabajar con una copia de empleado y asi trabajar con el espacio de memoria. Los empleados solo se
  podran leer mas no modificar. 
  
  Referente al puntero de organizacion, este SI crea una copia de esa organizacon y ya no trabaja con el espacio
  de memoria*/
 Nomina(const vector<Empleado*> &_empleados, Organizacion* _origanizacion): Empleados(_empleados), organizacion(_origanizacion) {}

 void CalcularValor(){}
 void listarTodos(){}
 void EmpleadodelMes(){}
 void EmpleadoMasCostoso(){}
};

class Fecha {
   private:
   int dia;
   int mes;
   int anio;
};

class Empleado {
    protected:
    string nombre;
    int base;
    long identificacion;
    public:
    Empleado(string _nombre, int _base, long _identificacion): nombre(_nombre), base(_base), identificacion(_identificacion){}

    virtual void CalcularSalario() {
        
    }

    virtual void MostrarInfo(){
        cout << "..." << endl;
    }
};

class Temporal: public Empleado {
  private:
   Fecha fechaFinalizacion;
   int salud;
   int pension;
   int liquidacion;
  public:
  Temporal(string _nombre, int _base, int _identificacion, Fecha _fechaFinalizacion, int _salud, int _pension, int _liquidacion): Empleado(_nombre, _base, _identificacion){}

  void CalcularSalario() override {
     cout << base + salud + pension + liquidacion << endl;
  }
};

class Contratista: public Empleado {
  private:
    int salud;
  public:
   Contratista(string _nombre, int _base, int _identificacion, int _salud): Empleado(_nombre, _base, _identificacion){}
};

class Planta: public Empleado {
  private:
   int vacaciones;
   int cesantias;
   int salud;
   int pension;
   int transporte;
  public:
  Planta(string _nombre, int _base, int _identificacion, int _vaciones, int _cesantias, int _salud, int _pension, int _transporte): Empleado(_nombre, _base, _identificacion){}
};

class Practicante: public Empleado {
   
};

int main(){
    return 0;
}