#include <iostream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Venta {
    int numFactura;
    string cedula;
    string nombre;
    int localidad; // 1: Sol Norte/Sur, 2: Sombra Este/Oeste, 3: Preferencial
    int cantidadEntradas;
    double precioPorEntrada;
    double subtotal;
    double cargosServicios;
    double totalPagar;
};

double obtenerPrecioPorLocalidad(int localidad) {
    switch(localidad) {
        case 1: return 10500.0;  // Sol Norte/Sur
        case 2: return 20500.0;  // Sombra Este/Oeste
        case 3: return 25500.0;  // Preferencial
        default: return 0.0;
    }
}

string obtenerNombreLocalidad(int localidad) {
    switch(localidad) {
        case 1: return "Sol Norte/Sur";
        case 2: return "Sombra Este/Oeste";
        case 3: return "Preferencial";
        default: return "Desconocido";
    }
}

void procesarVenta(Venta &venta) {
    //  precio por entrada según el lugar 
    venta.precioPorEntrada = obtenerPrecioPorLocalidad(venta.localidad);

    //  subtotal
    venta.subtotal = venta.cantidadEntradas * venta.precioPorEntrada;

    // cargos por servicios
    venta.cargosServicios = venta.cantidadEntradas * 1000;

    //  total a pagar
    venta.totalPagar = venta.subtotal + venta.cargosServicios;
}

void mostrarVenta(const Venta &venta) {
    cout << "Número de factura: " << venta.numFactura << endl;
    cout << "Cédula: " << venta.cedula << endl;
    cout << "Nombre del comprador: " << venta.nombre << endl;
    cout << "Localidad: " << obtenerNombreLocalidad(venta.localidad) << endl;
    cout << "Cantidad de entradas: " << venta.cantidadEntradas << endl;
    cout << "Subtotal: " << venta.subtotal << " colones" << endl;
    cout << "Cargos por servicios: " << venta.cargosServicios << " colones" << endl;
    cout << "Total a pagar: " << venta.totalPagar << " colones" << endl;
    cout << "---------------------------------------------" << endl;
}

int main() {
    vector<Venta> ventas;
    int entradasSol = 0, entradasSombra = 0, entradasPreferencial = 0;
    double acumSol = 0.0, acumSombra = 0.0, acumPreferencial = 0.0;
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        Venta venta;
        cout << "Ingrese el número de factura: ";
        cin >> venta.numFactura;
        cin.ignore();
        cout << "Ingrese la cédula del comprador: ";
        getline(cin, venta.cedula);
        cout << "Ingrese el nombre del comprador: ";
        getline(cin, venta.nombre);
        do {
            cout << "Ingrese la localidad (1-Sol Norte/Sur, 2-Sombra Este/Oeste, 3-Preferencial): ";
            cin >> venta.localidad;
        } while (venta.localidad < 1 || venta.localidad > 3);
        
        do {
            cout << "Ingrese la cantidad de entradas (máximo 4): ";
            cin >> venta.cantidadEntradas;
        } while (venta.cantidadEntradas < 1 || venta.cantidadEntradas > 4);

        // Proceso de  la venta
        procesarVenta(venta);

        // Guardar la venta en el vector
        ventas.push_back(venta);

        // Acumular estadísticas
        if (venta.localidad == 1) {
            entradasSol += venta.cantidadEntradas;
            acumSol += venta.subtotal;
        } else if (venta.localidad == 2) {
            entradasSombra += venta.cantidadEntradas;
            acumSombra += venta.subtotal;
        } else if (venta.localidad == 3) {
            entradasPreferencial += venta.cantidadEntradas;
            acumPreferencial += venta.subtotal;
        }

        // Mostrar los datos de la venta
        mostrarVenta(venta);

        cout << "¿Desea ingresar otra venta? (s/n): ";
        cin >> continuar;
    }

    // Estadísticas finales
    cout << "---------------------------------------------" << endl;
    cout << "Estadísticas Finales:" << endl;
    cout << "Cantidad de entradas en Sol Norte/Sur: " << entradasSol << endl;
    cout << "Acumulado en Sol Norte/Sur: " << acumSol << " colones" << endl;
    cout << "Cantidad de entradas en Sombra Este/Oeste: " << entradasSombra << endl;
    cout << "Acumulado en Sombra Este/Oeste: " << acumSombra << " colones" << endl;
    cout << "Cantidad de entradas en Preferencial: " << entradasPreferencial << endl;
    cout << "Acumulado en Preferencial: " << acumPreferencial << " colones" << endl;

    return 0;
}


