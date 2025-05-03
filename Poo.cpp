#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Organizacion {

};

class Nomina {
 private:
 vector<Empleado*> Empleados;
 Organizacion* organizacion;
 public:
 Nomina(const vector<Empleado*> &_empleados, Organizacion* _origanizacion): Empleados(_empleados), organizacion(_origanizacion) {}
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

int main(){
    return 0;
}