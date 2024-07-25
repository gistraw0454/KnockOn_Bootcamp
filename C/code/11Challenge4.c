#include <stdio.h>

typedef struct Complex{
  int real;
  int imagin; 
}Complex;

Complex add(Complex a, Complex b){
    Complex Result = {a.real + b.real,a.imagin + b.imagin};
    return Result;
}

Complex sub(Complex a, Complex b){
    Complex Result = {a.real - b.real,a.imagin - b.imagin};
    return Result;
}

Complex mul(Complex a, Complex b){
    Complex Result;
    if (a.imagin*b.imagin>0){
        Result.real = a.real*b.real - a.imagin*b.imagin;
    }
    else Result.real = a.real*b.real + a.imagin*b.imagin;
    Result.imagin = a.real*b.imagin + a.imagin*b.real;
    return Result;
}

int main(){

    Complex a = {1,1};
    Complex b = {2,2};
    Complex Result[3] = {add(a,b),sub(a,b),mul(a,b)};
    for (int i=0; i<3 ; i++){
        printf("%d+%di\n",Result[i].real,Result[i].imagin);
    }


}