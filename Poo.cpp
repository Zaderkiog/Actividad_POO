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
     
     El puntero de organizacion, este SI crea una copia de esa organizacion y ya no trabaja con el espacio
     de memoria*/
    Nomina(const vector<Empleado*> &_empleados, Organizacion* _origanizacion): Empleados(_empleados), organizacion(_origanizacion) {}
   
    void CalcularValor(){
      if (Empleados.empty()) {
        cout << "No hay empleados registrados en la nomina" << endl;
        return;
    }

    double total = 0.0;
    for (Empleado* e : Empleados) {
        total += e->CalcularSalario();
    }

    cout << "El valor total de nomina es: " << total << endl;
    }
    void listarTodos(){
      if(Empleados.empty()){
        cout << "Esta vacio." << endl;
        return;
      } else {
        for(Empleado* e : Empleados) {
          e->MostrarInfo();
      }
      }

    }
    void EmpleadodelMes(vector<Empleado*>& empleados){
      if (empleados.empty()) {
        cout << "No hay empleados para seleccionar el empleado del mes." << endl;
        return;
    }

    Empleado* empleadoDelMes = empleados[0];  
    double mejorDesempeno = empleadoDelMes->CalcularSalario();  

    for (Empleado* e : empleados) {
        double desempeño = e->CalcularSalario();  
        if (desempeño > mejorDesempeno) {
            mejorDesempeno = desempeño;
            empleadoDelMes = e;
        }
    }

    cout << "El empleado del mes es: " << endl;
    empleadoDelMes->MostrarInfo();  
    }
    void EmpleadoMasCostoso(vector<Empleado*>& empleados){
      if (empleados.empty()){
        cout<<"No hay empleados " << endl;
        return;
    } 

    Empleado* masCostoso = empleados[0];
    double mayorSalario = masCostoso->CalcularSalario();

    for (Empleado* e : empleados) {
       double salario = e->CalcularSalario();
       if(salario > mayorSalario){
           mayorSalario = salario;
           masCostoso = e;
       }
    }

    cout << "El empleado mas costoso es: " << endl;
    masCostoso->MostrarInfo();
    cout << "Salario: " << mayorSalario;
    }
   };
   

class Fecha {
   private:
   int dia;
   int mes;
   int anio;
   public:
   Fecha() : dia(1), mes(1), anio(2000) {} 
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
   Contratista(string _nombre, int _base, long _identificacion, int _salud): Empleado(_nombre, _base, _identificacion){
    this->salud = _salud;
   }

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
    // Comentario pa' no olvidar
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
    int base, salud, pension, liquidacion, opc, opc2, dia, mes, anio, vacaciones, censatias, transporte;
    long identi, numIdenti;

do{
  system("clear");
  system("cls");
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
        system("clear");
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

            
            empleados.push_back(new Temporal(nombre, base, identi, Fecha(dia, mes, anio), salud, pension, liquidacion));
            organizacion = new Organizacion(nameOrganizacion, nullptr, numIdenti);
            nomina = new Nomina(empleados, organizacion);
            system("pause");
            break;
        case 2:
           cout << "===== Contratista =====" << endl;
           cout << "Ingrese el nombre del empleado: ";
           cin >> nombre;
           cout << "Ingrese el sueldo del empleado: ";
           cin >> base;
           cout << "Ingrese la identificacion del empleado: ";
           cin >> identi;
           cout << "Ingrese la salud del empleado: ";
           cin >> salud;
           cout << "===== Organizacion =====" << endl;
           cout << "Ingrese el nombre de la organizacio: ";
           cin >> nameOrganizacion;
           cout << "Ingrese el numero de identificacion tributario: ";
           cin >> numIdenti;

           empleados.push_back(new Contratista(nombre, base, identi, salud));
           organizacion = new Organizacion(nameOrganizacion, nullptr, numIdenti);
           nomina = new Nomina(empleados, organizacion);
           system("pause");
           break;
        case 3:
          cout << "===== Planta =====" << endl;
          cout << "Ingrese el nombre del empleado: ";
          cin >> nombre;
          cout << "Ingrese el sueldo del emleado: ";
          cin >> base;
          cout << "Ingrese el numero de identificacion del empleado: ";
          cin >> identi;
          cout << "Ingrese las vacaciones del empleado: ";
          cin >> vacaciones;
          cout << "Ingrese la censatias del empleado: ";
          cin >> censatias;
          cout << "Ingrese la salud del empleado: ";
          cin >> salud;
          cout << "Ingrese la pension del empleado: ";
          cin >> pension;
          cout << "Ingrese el transporte del empleado: ";
          cin >> transporte;
          cout << "===== Organizacion =====" << endl;
          cout << "Ingrese el nombre de la organizacion: ";
          cin >> nameOrganizacion;
          cout << "Ingrese la identifiacion tributaria: ";
          cin >> numIdenti;


          empleados.push_back(new Planta(nombre, base, identi, vacaciones, censatias, salud, pension, transporte));
          organizacion = new Organizacion(nameOrganizacion, nullptr, numIdenti);
          nomina = new Nomina(empleados, organizacion);
          system("pause");
          break;
        case 4:
        cout << "===== Contratista =====" << endl;
        cout << "Ingrese el nombre del empleado: ";
        cin >> nombre;
        cout << "Ingrese el sueldo del empleado: ";
        cin >> base;
        cout << "Ingrese la identificacion del empleado: ";
        cin >> identi;
        cout << "Ingrese la salud del empleado: ";
        cin >> salud;
        cout << "===== Organizacion =====" << endl;
        cout << "Ingrese el nombre de la organizacion: ";
        cin >> nameOrganizacion;
        cout << "Ingrese el numero de identificacion tributario: ";
        cin >> numIdenti;


        empleados.push_back(new Practicante(nombre, base, identi, salud));
        organizacion = new Organizacion(nameOrganizacion, nullptr, numIdenti);
        nomina = new Nomina(empleados, organizacion);
        system("pause");
        break;
        case 5:
            break;
        default:
           cout << "Opcion no valida." << endl;
           system("pause");
            break;
        }
        break;
    case 2:
        cout << "Ha seleccionado eliminar empleado" << endl;
        for (Empleado* e: empleados) delete e;
        delete nomina;
        delete organizacion;
        cout << "Empleados eliminados exitosamente" << endl;
        system("pause");
        break;
    case 3:
        cout << "Ha seleccionado calcular la nomina de los empleados" << endl;
        nomina->CalcularValor();
        system("pause");
        break;
    case 4:
        cout << "Ha seleccionado mostrar organizacion y a todos los empleados" << endl;
        nomina->listarTodos();
        system("pause");
        break;
    case 6:
        cout << "Ha seleccionado ver cual es el empleado mas costoso" << endl;
        nomina->EmpleadoMasCostoso(empleados);
        system("pause");
        break;
    case 7:
        break;
    default:
        cout << "Opcion no valida." << endl;
        system("pause");
        break;
}
} while (opc != 7);
}