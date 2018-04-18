#include <iostream>
using namespace std;

double G;
double M;
double x;
double t;
double v;

//inicializacion de las variables
double derivarx(double x, double v, double t);
double derivarv(double x, double v, double t);
void runge(double *x, double *v, double *t, double dt);

//derivada respecto de x respecto a t
double derivarx(double x, double v, double t){
  return v;
}
//derivada de v respecto a t
double derivarv(double x, double v, double t){
  return (-(G*M)/x*x);
}
//runge kutta de 4 orden
void runge(double xin, double vin, double tin, double dt){


  double kv1;
  double kv2;
  double kv3;
  double kv4;
  double kt1;
  double kt2;
  double kt3;
  double kt4;
  
  kv1 = derivarx(xin, vin, tin);
  kt1 = derivarv(xin, tin, vin);
  kv2 = derivarx(xin + dt/2, vin +kv1* dt/2, tin + kt1 * dt/2);
  kt2 = derivarv(xin + dt/2, vin + kv1* dt/2, tin +kt1* dt/2);
  kv3 = derivarx(xin + dt/2, vin +kv2* dt/2, tin + kt2 *dt/2);
  kt3 = derivarv(xin + dt/2, vin + kv2* dt/2, tin + kt2 *dt/2);
  kv4 = derivarx(xin + dt, vin + kv3* dt, tin + kt3 *dt);
  kt4 = derivarv(xin + dt, vin + kv3* dt, tin + kt3*dt);

  x = xin;
  v = vin;
  t = tin;

  
 }

//main que corre el codigo
int main(){
  G = 10;
  M = 1000;
  double m = 10;
  x= 20;
  double x0 = 0;
  v= 20;
  t = 0;
  double dt = 0.001;
  int i;
  //derivarx(x,v,t);
  //derivarv(x,v,t);
  for(i=0; i< 0.01; ++i){
   
    runge(x, v, t, dt);
     cout << x << " " << v << " " << t << endl;
  }
  return 0;
}
  
  
  
