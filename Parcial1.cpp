#include <iostream>
#include <iomanip>
using namespace std;

int main () {

	int cliente, plazo, codeudor, plazomax=0;
	float tasa=0, monto, total, interes, limite=0;


	cout << "Ingrese el tipo de cliente: ";
	cout << "\n1.Estudiante\n 2.Empleado\n 3.Pensionado\n 4.Desempleado\n";
	cin >> cliente;

	cout <<"\nIngrese el monto solicitado: ";
	cin >> monto;

	cout << "\nIngrese el plazo (meses): ";
	cin >> plazo;

	cout <<"\n¿Tiene codeudor? (Si=1, No=0): ";
	cin >> codeudor;

	if(monto <=0 || plazo <=0){
		cout << "Error: los datos ingresados son invalidos.";
		return 0;
	}

	switch (cliente){
		case 1: 
			tasa = 0.06;
			limite= (codeudor==1)? 5000000 : 2000000;
			  if(monto <= 2000000){
                        plazomax = 12;}
                 else if(monto <= 4000000){
                     plazomax = 24;}
                       break;
		case 2:
                     tasa = 0.07;
            limite = (codeudor == 1) ? 10000000 : 5000000;

            if(monto <= 5000000)
                plazomax = 24;
            else if(monto <= 10000000)
                plazomax = 48;
            break;
		case 3:
                      tasa = 0.04;
            limite = (codeudor == 1) ? 7000000 : 3000000;

            if(monto <= 3000000)
                plazomax = 24;
            else if(monto <= 7000000)
                plazomax = 36;
            break;
		case 4:
			if(codeudor==0){
				cout << "\nRECHAZADO: desempleado sin codeudor.";
				return 0;
			}

                         tasa = 0.08;
                        limite = 2000000;
                        plazomax = 12;
                         break;
		default:
			cout << "\n Tipo de cliente invalido";
			return 0;
	}


	  if(monto > limite){
        cout << "RECHAZADO: El monto excede el limite permitido.";
        return 0;
    }

	if (plazo > plazomax){
		cout << "\nRECHAZADO: Plazo excede el maximo que esta permitido";
		return 0;
	}
		interes= monto*tasa*plazo;
		total= monto+interes;

		cout << fixed << setprecision(0);

		cout << "\n--- Prestamo Aprobado ---";
		cout << "\n Monto: " << monto;
		cout << "\n Plazo: " << plazo;
		cout << "\n Tasa: " << tasa* 100 << "%";
		cout << "\n Intereses: " << interes;
		cout << "\n Total a pagar: " << total;

		cout << "\n ";

		return 0;

	}

