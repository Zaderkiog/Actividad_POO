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

    virtual double CalcularSalario(){
        return 0.0;
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
    Organizacion(string _name, Nomina* _nomina, int _nit): name(_name), nomina(_nomina), nit(_nit){}

    void setNomina(Nomina* _nomina) {
        nomina = _nomina;
    }
   };

class Nomina {
    private:
    vector<Empleado*> Empleados;
    Organizacion* organizacion;
    public:
    // Comentarios por si acaso:
    /* & : El parametro de _empleados es una referencia constante a un vector de punteros a Empleado
     Evita copiar el vector y garantiza que no se modificara dentro del constructor.
     &_empleados referencia a un espacio de memoria de X empleado (Por ejemplo Empleado("Juan")), el apuntador toma ese espacio de memoria referenciado
     para evitar trabajar con una copia de empleado y asi trabajar con el espacio de memoria. Los empleados solo se
     podran leer mas no modificar. 
     
     El puntero de organizacion, este SI crea una copia de esa organizacon y ya no trabaja con el espacio
     de memoria*/
    Nomina(const vector<Empleado*> &_empleados, Organizacion* _origanizacion): Empleados(_empleados), organizacion(_origanizacion) {}
   
    void CalcularValor(){
        double total = 0.0;
        for (Empleado* e : Empleados) {
            total += e->CalcularSalario();
        }

        cout << "El valor total de nomina es: " << total << endl;

        // Elimino la nomina cuando ya las he calculado
    }
    void listarTodos(){
        for(Empleado* e : Empleados) {
            e->MostrarInfo();
        }

    }
    void EmpleadodelMes(){}
    void EmpleadoMasCostoso(){}
   };
   

class Fecha {
   private:
   int dia;
   int mes;
   int anio;
   public:

   Fecha(int _dia, int _mes, int _anio): dia(_dia), mes(_mes), anio(_anio){}
};



class Temporal: public Empleado {
  private:
   Fecha fechaFinalizacion;
   int salud;
   int pension;
   int liquidacion;
  public:
  Temporal(string _nombre, int _base, long _identificacion, Fecha _fechaFinalizacion, int _salud, int _pension, int _liquidacion): Empleado(_nombre, _base, _identificacion){
    this->salud = _salud;
    this->pension = _pension;
    this->liquidacion = _liquidacion;
    this->fechaFinalizacion = _fechaFinalizacion;
  }

  double CalcularSalario() override {
     return  base + salud + pension + liquidacion;
  }

  void MostrarInfo() override{
    cout << "===============" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Base: " << base << endl;
    cout << "Identificacion: " << identificacion << endl;
    cout << "Salud: " << salud << endl;
    cout << "Pension: " << pension << endl;
    cout << "Liquidacion: " << liquidacion << endl;
    cout << "================" << endl;
  }
};

class Contratista: public Empleado {
  private:
    int salud;
  public:
   Contratista(string _nombre, int _base, long _identificacion, int _salud): Empleado(_nombre, _base, _identificacion){}

   double CalcularSalario() override {
     return base - salud;
   }

   void MostrarInfo() override{
      cout << "===============" << endl;
      cout << "Nombre: " << nombre << endl;
      cout << "Base: " << base << endl;
      cout << "Identificacion: " << identificacion << endl;
      cout << "Salud: " << salud << endl;
      cout << "================" << endl;
   }
};

class Planta: public Empleado {
  private:
   int vacaciones;
   int cesantias;
   int salud;
   int pension;
   int transporte;
  public:
  Planta(string _nombre, int _base, long _identificacion, int _vacaciones, int _cesantias, int _salud, int _pension, int _transporte): Empleado(_nombre, _base, _identificacion){
    // El motivo del This es asignar el valor del parametro del constructor al parametro de la clase
    this->vacaciones = _vacaciones;
    this->cesantias = _cesantias;
    this->salud = _salud;
    this->pension = _pension;
    this->transporte = _transporte;
  }

    double CalcularSalario() override {
     return cesantias + (vacaciones * (base/30)) + salud + pension + transporte;
  }

  void MostrarInfo() override {
    cout << "===============" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Base: " << base << endl;
    cout << "Identificacion: " << identificacion << endl;
    cout << "Vacaciones: " << vacaciones << endl;
    cout << "Cesantias: " << cesantias << endl;
    cout << "Salud: " << salud << endl;
    cout << "Pension: " << pension << endl;
    cout << "Transporte: " << transporte << endl;
    cout << "================" << endl;
  }
};

class Practicante: public Empleado {
   private:
      int salud;
   public:
   Practicante(string _name, int _base, long _identificacion, int _salud): Empleado(_name, _base, _identificacion){
     this->salud = _salud;
   }

   double CalcularSalario() override {
     return base  - (base *0.1)  + salud;
   }

   void MostrarInfo() override {
    cout << "===============" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Base: " << base << endl;
    cout << "Identificacion: " << identificacion << endl;
    cout << "Salud: " << salud << endl;
    cout << "================" << endl;
   }
};

int main(){
    vector<Empleado*> empleados;
    Organizacion* organizacion;
    Nomina* nomina;
    
    string nombre, nameOrganizacion;
    int base, salud, pension, liquidacion, opc, opc2, dia, mes, anio;
    long identi, numIdenti;

do{
    cout << "================================================" << endl;
    cout << "1. Crear empleado" << endl;
    cout << "2. Eliminar empleado" << endl;
    cout << "3. Calcular nomina de los empleados" << endl;
    cout << "4. Mostrar organizacion y todos los empleados" << endl;
    cout << "5. Empleado del mes" << endl;
    cout << "6. Empleado mas costoso" << endl;
    cout << "7. Salir" << endl;
    cout << "=================================================" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opc;
    system("cls");

    switch (opc)
    {
    case 1:
        cout << "Ha seleccionado crear empleado" << endl;
        cout << "Que empleado desea crear: " << endl;
        cout << "1. Temporal" << endl;
        cout << "2. Contratista" << endl;
        cout << "3. Planta" << endl;
        cout << "4. Practicante" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccion alguna opcion: ";
        cin >> opc2;
        system("cls");
         
        switch (opc2)
        {
        case 1:
            cout << "====== Temporal =====" << endl;
            cout << "Ingrese el nombre del empleado: ";
            cin >> nombre;
            cout << "Ingrese el sueldo del empleado: ";
            cin >> base;
            cout << "Ingrese la identificacion del empleado: ";
            cin >> identi;
            cout << "Ingrese salud: ";
            cin >> salud;
            cout << "Ingrese la pension del empleado: ";
            cin >> pension;
            cout << "Ingrese la liquidacion el empleado: ";
            cin >> liquidacion;
            cout << "===== Organizacion ====="<< endl;
            cout << "Organizacion a la cual pertenece: ";
            cin >> nameOrganizacion;
            cout << "Ingrese el numero de identicacion tributario: ";
            cin >> numIdenti;
            cout << "===== Fecha de terminacion =====" << endl;
            cout << "Ingrese el dia de terminacion: ";
            cin >> dia;
            cout << "Ingrese el mes de terminacion: ";
            cin >> mes;
            cout << "Ingrese el anio de terminacion: ";
            cin >> anio;

            
            empleados.push_back(new Temporal(nombre, base, identi, salud, Fecha(dia, mes, anio), salud, pension, liquidacion));
            organizacion = new Organizacion(nameOrganizacion, 0, numIdenti);
            nomina = new Nomina(empleados, organizacion);
            organizacion->setNomina(nomina);
            system("pause");
            break;
        case 5:
            break;
        
        default:
           cout << "Opcion no valida." << endl;
           system("pause");
            break;
        }
    case 2:
        cout << "Ha seleccionado eliminar empleado" << endl;
    case 4:
        cout << "Ha seleccionado mostrar organizacion y a todos los empleados";
        nomina->listarTodos();
        
    default:
       cout << "Opcion no valida." << endl;
        break;
    }
}while(opc != 7);
    return 0;
}