#include <iostream>
#include <string>
#include <vector>
using namespace std;


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

    virtual ~Empleado(){}
};

class Nomina;

class Organizacion {
    private:
      string name;
      Nomina* nomina;
      int nit;
    public:
    Organizacion(string _name, Nomina* _nomina, int _nit){}

    void setNomina(Nomina* _nomina) {
        nomina = _nomina;
    }
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



class Temporal: public Empleado {
  private:
   Fecha fechaFinalizacion;
   int salud;
   int pension;
   int liquidacion;
  public:
  Temporal(string _nombre, int _base, int _identificacion, Fecha _fechaFinalizacion, int _salud, int _pension, int _liquidacion): Empleado(_nombre, _base, _identificacion){
    this->salud = _salud;
    this->pension = _pension;
    this->liquidacion = _liquidacion;
  }

  void CalcularSalario() override {
     cout << base + salud + pension + liquidacion << endl;
  }

  void MostrarInfo() override{}
};

class Contratista: public Empleado {
  private:
    int salud;
  public:
   Contratista(string _nombre, int _base, int _identificacion, int _salud): Empleado(_nombre, _base, _identificacion){}

   void CalcularSalario() override {
     cout << base - salud << endl;
   }

   void MostrarInfo() override{}
};

class Planta: public Empleado {
  private:
   int vacaciones;
   int cesantias;
   int salud;
   int pension;
   int transporte;
  public:
  Planta(string _nombre, int _base, int _identificacion, int _vacaciones, int _cesantias, int _salud, int _pension, int _transporte): Empleado(_nombre, _base, _identificacion){
    // El motivo del This es asignar el valor del parametro del constructor al parametro de la clase
    this->vacaciones = _vacaciones;
    this->cesantias = _cesantias;
    this->salud = _salud;
    this->pension = _pension;
    this->transporte = _transporte;
  }

  void CalcularSalario() override {
     cout << "Total: " << cesantias + (vacaciones * (base/30)) + salud + pension + transporte << endl;
  }

  void MostrarInfo() override {}
};

class Practicante: public Empleado {
   private:
      int salud;
   public:
   Practicante(string _name, int _base, int _identificacion, int _salud): Empleado(_name, _base, _identificacion){
     this->salud = _salud;
   }

   void CalcularSalario() override {
     cout << "Total: " <<   base  - (base *0.1)  + salud << endl;
   }

   void MostrarInfo() override {}
};

int main(){
    int opc;

    cout << "================================================" << endl;
    cout << "1. Crear empleado" << endl;
    cout << "2. Eliminar empleado" << endl;
    cout << "3. Calcular nomina de los empleados" << endl;
    cout << "4. Mostrar organizacion y todos los empleados" << endl;
    cout << "5. Empleado del mes" << endl;
    cout << "6. Empleado mas costoso" << endl;
    cout << "=================================================" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opc;

    switch (opc)
    {
    case 1:
        int opc2;
        cout << "Ha seleccionado crear empleado" << endl;
        cout << "Que empleado desea crear: " << endl;
        cout << "1. Temporal" << endl;
        cout << "2. Contratista" << endl;
        cout << "3. Planta" << endl;
        cout << "4. Practicante" << endl;
        cout << "Seleccion alguna opcion: ";
        cin >> opc2;
         
        switch (opc2)
        {
        case 1:
            
            break;
        
        default:
            break;
        }
    
    default:
        break;
    }
    return 0;
}