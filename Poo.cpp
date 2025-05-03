#include <iostream>
#include <string>
using namespace std;

class Empleado {
    protected:
    string nombre;
    int base;
    private:

    virtual void CalcularSalario() {
        
    }

    virtual void MostrarInfo(){
        cout << "..." << endl;
    }
};

int main(){
    return 0;
}