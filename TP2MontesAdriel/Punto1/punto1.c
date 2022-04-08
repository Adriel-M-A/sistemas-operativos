#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/*
   1a) Que hace?
   Espera que se ingrese la señal correspondiente para ser ejecutada por el manejador, en este caso la señal es de 
   interrupcion "ctrl + c". Una vez que el ingreso de esta señal llega a la cantidad de veces requerida, finaliza 
   la ejecución del programa y vuelve al shell normalmente.

   1b1) 

   1b2) si, el manejador se pierde al terminar el programa

   1b3) Esposiblle capturar el SIGKILL mediante kill -9
*/

int cant = 0;
void manejador(int num) {
   printf("Recibí señal\n");
   cant++;
   if (cant == 3) {
      printf("Finalizo mi ejecución\n");
      exit(1);
   }
}

int main(void) {
   signal(2, manejador);
   while (1);
}