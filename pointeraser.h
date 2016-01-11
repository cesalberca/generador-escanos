/************************************************************************************
PointEraser es una micro-librería que contiene una única función
dedicada a eliminar puntos de cadenas de caracteres con dígitos numéricos que 
contienen el punto como separador de millares.

Versión 1.0.
Fernando Paniagua, 2015.
(www.fernandopaniagua.com)

Esta librería se puede usar, copiar, modificar y redistribuir con libertad, siempre 
y cuando la obra derivada mantenga estos mismos derechos (lo que se conoce como 
copyleft). Y hablando de otra cosa... no tiene ninguna garantía. Si la usas es bajo 
tu propia responsabilidad.
                                  
             @@@@@@@@;            
           @@@@@@@@@@@@`          
          @@@@      '@@@#         
         @@@          @@@+        
        @@@     :;`    '@@        
       +@@    @@@@@@+   @@@       
       @@.  `@@@@@@@@@   @@.      
      .@@   @@@@  '@@@;  #@@      
      @@@  #@@#     @@@   @@      
      @@:           @@@   @@      
      @@`           .@@`  @@      
      @@.           '@@   @@      
      @@+  @@@      @@@   @@      
      :@@   @@@.   @@@@  :@@      
       @@   @@@@@@@@@@   @@'      
       @@@   #@@@@@@@   :@@       
        @@#    +@@@`    @@'       
        :@@@           @@@        
         +@@@`       @@@@         
          .@@@@@#+@@@@@@          
            @@@@@@@@@@            
               '@@#,              



"¡No me preocupes con los detalles, muchacho! ¡Sólo ayudame a encontrar los planos!"
Dr. Fred Edison.

************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Elimina el carácter punto (.) de una cadena y
convierte el resto a una variable de tipo long.

Parámetros de entrada: puntero a una cadena (debe contener dígitos numéricos y puntos).
Retorno: un long con el valor de la cadena sin los puntos.
*/
long getCifraSinPuntos(char *cadenaConPuntos){
	int i=0;//Iterador del array de origen
	int iArrayDestino=0;//Iterador del array de destino
	char sCifraSP[100];//Array de char con la cifra Sin Puntos
	long lCifra;//Cifra destino

	for (i=0;i<strlen(cadenaConPuntos);i++){
		if (cadenaConPuntos[i]!='.') {
			sCifraSP[iArrayDestino]=cadenaConPuntos[i];
			iArrayDestino++;
		}
	}
	lCifra = strtol(sCifraSP,NULL,10);
	return lCifra;
}

