#include <stdio.h>


void celsius(float temp){
    float kelvin, fahrenheit;
    
    fahrenheit = (temp * 9/5) + 32;
    kelvin = temp + 273.15;

    printf("%.2f° Celsius e %.2f° Fahrenheit e %.2f° Kelvin\n", temp, fahrenheit, kelvin);
}

void fahrenheit(float temp){
    float kelvin, celsius;

    kelvin = (temp - 32) * 5/9 + 273.15;
    celsius = (temp - 32) * 5/9;

    printf("%.2f° Fahrenheit e %.2f° Celsius e %.2f° Kelvin\n", temp, celsius, kelvin);

}

void kelvin(float temp) {
    float celsius, fahrenheit;

    celsius = temp - 273.15;
    fahrenheit = (temp - 273.15) * 9/5 + 32;

    printf("%.2f° Kelvin e %.2f° Celsius e %.2f° Fahrenheit\n", temp, celsius, fahrenheit);
}

int main()
{   
    int medida;
    float temp;
    float convertedTemp;

    printf("Escolha a unidade de medida da temperatura a ser inserida:\n(1- Celsius) (2- Fahrenheit) (3- Kelvin) ");
    scanf("%d", &medida);
    printf("Agora digite o valor da temperatura: ");
    scanf("%f", &temp);

    if (medida == 1) {
        celsius(temp);
    } else if (medida == 2) {
        fahrenheit(temp);
    } else if (medida == 3) {
        kelvin(temp);
    } else {
        printf("Escolha entre 1, 2 ou 3.\n");
    }

    return 0;
}
