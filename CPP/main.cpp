
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Empleado {
    string cedula;
    string nombre;
    int tipoEmpleado; // 1 - Operario, 2 - Técnico, 3 - Profesional
    double horasLaboradas;
    double precioHora;
    double salarioOrdinario;
    double aumento;
    double salarioBruto;
    double deduccionCCSS;
    double salarioNeto;
};

void calcularSalarios(Empleado &empleado) {
    //  Salario Ordinario
    empleado.salarioOrdinario = empleado.horasLaboradas * empleado.precioHora;

    //  Aumento Salarial 
    switch (empleado.tipoEmpleado) {
        case 1: // Operario
            empleado.aumento = empleado.salarioOrdinario * 0.15;
            break;
        case 2: // Técnico
            empleado.aumento = empleado.salarioOrdinario * 0.10;
            break;
        case 3: // Profesional
            empleado.aumento = empleado.salarioOrdinario * 0.05;
            break;
        default:
            empleado.aumento = 0.0;
            break;
    }

    // Salario Bruto
    empleado.salarioBruto = empleado.salarioOrdinario + empleado.aumento;

    //  deducciones de CCSS
    empleado.deduccionCCSS = empleado.salarioBruto * 0.0917;

    //  Salario Neto
    empleado.salarioNeto = empleado.salarioBruto - empleado.deduccionCCSS;
}

void mostrarEmpleado(const Empleado &empleado) {
    cout << "Cédula: " << empleado.cedula << endl;
    cout << "Nombre: " << empleado.nombre << endl;
    cout << "Tipo de Empleado: " << (empleado.tipoEmpleado == 1 ? "Operario" : empleado.tipoEmpleado == 2 ? "Técnico" : "Profesional") << endl;
    cout << "Salario por Hora: " << empleado.precioHora << endl;
    cout << "Cantidad de Horas Laboradas: " << empleado.horasLaboradas << endl;
    cout << "Salario Ordinario: " << empleado.salarioOrdinario << endl;
    cout << "Aumento: " << empleado.aumento << endl;
    cout << "Salario Bruto: " << empleado.salarioBruto << endl;
    cout << "Deducción CCSS: " << empleado.deduccionCCSS << endl;
    cout << "Salario Neto: " << empleado.salarioNeto << endl;
    cout << "---------------------------------------------" << endl;
}

int main() {
    vector<Empleado> empleados;
    int cantOperarios = 0, cantTecnicos = 0, cantProfesionales = 0;
    double acumSalarioOperarios = 0.0, acumSalarioTecnicos = 0.0, acumSalarioProfesionales = 0.0;
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        Empleado empleado;
        cout << "Ingrese la cédula del empleado: ";
        cin >> empleado.cedula;
        cin.ignore();
        cout << "Ingrese el nombre del empleado: ";
        getline(cin, empleado.nombre);
        cout << "Ingrese el tipo de empleado (1-Operario, 2-Técnico, 3-Profesional): ";
        cin >> empleado.tipoEmpleado;
        cout << "Ingrese la cantidad de horas laboradas: ";
        cin >> empleado.horasLaboradas;
        cout << "Ingrese el precio por hora: ";
        cin >> empleado.precioHora;

        //  salarios
        calcularSalarios(empleado);

        // Guardar el empleado en el vector
        empleados.push_back(empleado);

        // estadísticas
        if (empleado.tipoEmpleado == 1) {
            cantOperarios++;
            acumSalarioOperarios += empleado.salarioNeto;
        } else if (empleado.tipoEmpleado == 2) {
            cantTecnicos++;
            acumSalarioTecnicos += empleado.salarioNeto;
        } else if (empleado.tipoEmpleado == 3) {
            cantProfesionales++;
            acumSalarioProfesionales += empleado.salarioNeto;
        }

        // datos del empleado
        mostrarEmpleado(empleado);

        cout << "¿Desea ingresar otro empleado? (s/n): ";
        cin >> continuar;
    }

    // Estadísticas finales
    cout << "---------------------------------------------" << endl;
    cout << "Estadísticas Finales:" << endl;
    cout << "Cantidad de Operarios: " << cantOperarios << endl;
    cout << "Cantidad de Técnicos: " << cantTecnicos << endl;
    cout << "Cantidad de Profesionales: " << cantProfesionales << endl;

    cout << "Acumulado de Salario Neto por Operarios: " << acumSalarioOperarios << endl;
    cout << "Acumulado de Salario Neto por Técnicos: " << acumSalarioTecnicos << endl;
    cout << "Acumulado de Salario Neto por Profesionales: " << acumSalarioProfesionales << endl;

    if (cantOperarios > 0)
        cout << "Promedio de Salario Neto por Operarios: " << acumSalarioOperarios / cantOperarios << endl;
    if (cantTecnicos > 0)
        cout << "Promedio de Salario Neto por Técnicos: " << acumSalarioTecnicos / cantTecnicos << endl;
    if (cantProfesionales > 0)
        cout << "Promedio de Salario Neto por Profesionales: " << acumSalarioProfesionales / cantProfesionales << endl;

    return 0;
}

