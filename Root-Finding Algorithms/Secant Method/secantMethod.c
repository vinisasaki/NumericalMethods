#include <stdio.h>
#include <math.h>

void secantMethod(double (*func)(double), double x0, double x1, double tol){  // isso é uma função que possui um ponteiro para função como um dos parâmetros;
    int i = 0;
    double x2;

    do{
        double f_x0 = func(x0);
        double f_x1 = func(x1);

        x2 = x1 - (func(x1) * (x1 - x0)) / (f_x1 - f_x0);
        i++;
        printf("A raiz aproximada após %d iterações: %.15f\n", i, x2);

        if(fabs(x2 - x1) <= tol){
            break;
        }

        x0 = x1;
        x1 = x2;

    }while(i < 100);      // valor máximo de iterações permitido para o método convergir
    
    printf("A precisão é de %.15f\n", func(x2));

}

double func(double x){   // função a ser calculada a raiz, nesse caso: f(x) = x² - 2
    return x * x - 2;
}

int main(){
    
    double x0 = 0.5;      // estimativas iniciais x0 e x1
    double x1 = 1;
    double tol = 1E-6;    // tolerância (precisão) para o critério de parada do método

    secantMethod(func, x0, x1, tol);

    return 0;
}