#include <iostream> // std::cout, std::endl
#include <cmath> //exp, std::abs, pow
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;


double g = 32.17;
double s0 = 300;
double m = 0.25;
double k = 0.1;

//Definimos la función
inline double f(double t) { return s0 - (m*g*t)/k + ((pow(m, 2.0)*g)/pow(k, 2))*(1 - exp( (-k*t)/m )); }

//Derivada de la función
inline double df(double t) { return -m*g*(1/k)*(exp((k*t)/m) - 1)*exp( (-k*t)/(m) ) ; }

/*
p0: Aproximación inicial
TOL: tolerancia
Nmax: número máximo de iteraciones
*/
void newton(double p0,double TOL,double Nmax){

	double p;
	for(int i=0; i < Nmax; i++){
		p = p0 - f(p0)/df(p0);		
		cout << i << setprecision(20) << "\t" << p0 << 	"\t" << p << "\t" << abs(p0 - p) << endl;		
		if(abs(p - p0) < TOL)	break;
		p0 = p;				
	}

} 
	
int main(){	
	// Invocamos el método según los datos del problema
	newton(5, pow(10, -15), 40);
	cout << f(6.0037263087587833255) << endl;
	return 0;
}
