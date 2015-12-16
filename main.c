#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *txtFile;

struct Provincia {
  char nombre[100];
  int diputados;
  char votosPP[100];
  char votosPsoe[100];
  char votosIu[100];
  char votosUpyd[100];
  char votosPodemos[100];
  char votosCiudadanos[100];
  int diputadosArray[6];
};

struct Provincia provincias[51];
// Ya que los votos son recogidos en forma de caracter, éstos han de ser pasados a long para poder operar con ellos. Los guardamos en un array de long.
long arrayVotos[51][6];
long tempArray[51][6];
int arrayNombres[51][6];


void inicializacionDiputados();
void importTxt();
void rellenarVotosProvincias();
void inicializarNombresArray();
void dhondt();
void imprimirVotos();

struct Provincia madrid = {"Madrid", 36};
struct Provincia barcelona = {"Barcelona", 36};
struct Provincia valencia = {"Valencia", 16};
struct Provincia alicante = {"Alicante", 12};
struct Provincia sevilla = {"Sevilla", 12};
struct Provincia malaga = {"Malaga", 10};
struct Provincia murcia = {"Murcia", 10};
struct Provincia cadiz = {"Cadiz", 8};
struct Provincia vizcaya = {"Vizcaya", 8};
struct Provincia laCoruna = {"La Coruna", 8};
struct Provincia palmas = {"Las Palmas", 8};
struct Provincia asturias = {"Asturias", 8};
struct Provincia tenerife = {"Santa Cruz de Tenerife", 7};
struct Provincia zaragoza = {"Zaragoza", 7};
struct Provincia pontevedra = {"Pontevedra", 7};
struct Provincia granada = {"Granada", 7};
struct Provincia tarragona = {"Tarragona", 6};
struct Provincia cordoba = {"Cordoba", 6};
struct Provincia gerona = {"Gerona", 6};
struct Provincia guipuzcoa = {"Guipuzcoa", 6};
struct Provincia toledo = {"Toledo", 6};
struct Provincia almeria = {"Almeria", 6};
struct Provincia badajoz = {"Badajoz", 6};
struct Provincia jaen = {"Jaen", 6};
struct Provincia navarra = {"Navarra", 5};
struct Provincia castellon = {"Castellon", 5};
struct Provincia cantabria = {"Cantabria", 5};
struct Provincia valladolid = {"Valladolid", 5};
struct Provincia ciudadReal = {"Ciudad Real", 5};
struct Provincia huelva = {"Huelva", 5};
struct Provincia leon = {"Leon", 5};
struct Provincia lerida = {"Lerida", 4};
struct Provincia caceres = {"Caceres", 4};
struct Provincia albacete = {"Albacete", 4};
struct Provincia burgos = {"Burgos", 4};
struct Provincia salamanca = {"Salamanca", 4};
struct Provincia lugo = {"Lugo", 4};
struct Provincia orense = {"Orense", 4};
struct Provincia laRioja = {"La Rioja", 4};
struct Provincia alava = {"Alava", 4};
struct Provincia guadalajara = {"Guadalajara", 3};
struct Provincia huesca = {"Huesca", 3};
struct Provincia cuenca = {"Cuenca", 3};
struct Provincia zamora = {"Zamora", 3};
struct Provincia avila = {"Avila", 3};
struct Provincia palencia = {"Palencia", 3};
struct Provincia segovia = {"Segovia", 3};
struct Provincia teruel = {"Teruel", 3};
struct Provincia soria = {"Soria", 2};
struct Provincia ceuta = {"Ceuta", 1};
struct Provincia melilla = {"Melilla", 1};

int main(int argc, char *argv[]) {
  provincias[0] = madrid;
  provincias[1] = barcelona;
  provincias[2] = valencia;
  provincias[3] = alicante;
  provincias[4] = sevilla;
  provincias[5] = malaga;
  provincias[6] = murcia;
  provincias[7] = cadiz;
  provincias[8] = vizcaya;
  provincias[9] = laCoruna;
  provincias[10] = palmas;
  provincias[11] = asturias;
  provincias[12] = tenerife;
  provincias[13] = zaragoza;
  provincias[14] = pontevedra;
  provincias[15] = granada;
  provincias[16] = tarragona;
  provincias[17] = cordoba;
  provincias[18] = gerona;
  provincias[19] = guipuzcoa;
  provincias[20] = toledo;
  provincias[21] = almeria;
  provincias[22] = badajoz;
  provincias[23] = jaen;
  provincias[24] = navarra;
  provincias[25] = castellon;
  provincias[26] = cantabria;
  provincias[27] = valladolid;
  provincias[28] = ciudadReal;
  provincias[29] = huelva;
  provincias[30] = leon;
  provincias[31] = lerida;
  provincias[32] = caceres;
  provincias[33] = albacete;
  provincias[34] = burgos;
  provincias[35] = salamanca;
  provincias[36] = lugo;
  provincias[37] = orense;
  provincias[38] = laRioja;
  provincias[39] = alava;
  provincias[40] = guadalajara;
  provincias[41] = huesca;
  provincias[42] = cuenca;
  provincias[43] = zamora;
  provincias[44] = avila;
  provincias[45] = palencia;
  provincias[46] = segovia;
  provincias[47] = teruel;
  provincias[48] = soria;
  provincias[49] = ceuta;
  provincias[50] = melilla;


  inicializacionDiputados();
  inicializarNombresArray();
  importTxt();
  rellenarVotosProvincias();
  dhondt();
  // imprimirVotos();

  printf("%s\n", provincias[0].nombre);
  int i;
  for (i = 0; i < 6; i++) {
    switch (arrayNombres[0][i]) {
      case 1:
        printf("Diputados pp %i\n", provincias[0].diputadosArray[i]);
      break;
      case 2:
        printf("Diputados psoe %i\n", provincias[0].diputadosArray[i]);
      break;
      case 3:
        printf("Diputados iu %i\n", provincias[0].diputadosArray[i]);
      break;
      case 4:
        printf("Diputados upyd %i\n", provincias[0].diputadosArray[i]);
      break;
      case 5:
        printf("Diputados podemos %i\n", provincias[0].diputadosArray[i]);
      break;
      case 6:
        printf("Diputados Ciudadanos %i\n", provincias[0].diputadosArray[i]);
      break;
    }
  }

  printf("%s\n", provincias[6].nombre);
  for (i = 0; i < 6; i++) {
    switch (arrayNombres[6][i]) {
      case 1:
        printf("Diputados pp %i\n", provincias[6].diputadosArray[i]);
      break;
      case 2:
        printf("Diputados psoe %i\n", provincias[6].diputadosArray[i]);
      break;
      case 3:
        printf("Diputados iu %i\n", provincias[6].diputadosArray[i]);
      break;
      case 4:
        printf("Diputados upyd %i\n", provincias[6].diputadosArray[i]);
      break;
      case 5:
        printf("Diputados podemos %i\n", provincias[6].diputadosArray[i]);
      break;
      case 6:
        printf("Diputados Ciudadanos %i\n", provincias[45].diputadosArray[i]);
      break;
    }
  }
}

void inicializacionDiputados() {
  int i;
  for (i = 0; i < 51; i++) {
    int j;
    for (j = 0; j < 6; j++) {
      // Inicializamos los diputados de cada partido a 0.
      provincias[i].diputadosArray[j] = 0;
    }
  }
}

void importTxt() {
  char fileName[200];

  char line1[100];
  char line2[100];
  char line3[100];
  char line4[100];
  char line5[100];
  char line6[100];
  char line7[100];
  char line8[100];
  char line9[100];
  char line10[100];
  char line11[100];
  char line12[100];
  char line13[100];
  int eofReturn = 0;

  puts("Introduce el nombre del archivo txt a importar:");
  scanf("%s", fileName);
  // Concatenamos el nombre con .txt
  strcat(fileName, ".txt");

  txtFile = fopen(fileName, "r");

  do {
    eofReturn = fscanf(txtFile, "%s", line1);
    // Leemos de 13 en 13 líneas hasta que se termine el archivo.
    fscanf(txtFile, "%s", line2);
    fscanf(txtFile, "%s", line3);
    fscanf(txtFile, "%s", line4);
    fscanf(txtFile, "%s", line5);
    fscanf(txtFile, "%s", line6);
    fscanf(txtFile, "%s", line7);
    fscanf(txtFile, "%s", line8);
    fscanf(txtFile, "%s", line9);
    fscanf(txtFile, "%s", line10);
    fscanf(txtFile, "%s", line11);
    fscanf(txtFile, "%s", line12);
    fscanf(txtFile, "%s", line13);

    int i;
    for (i = 0; i < 51; i++) {
      if (strcmp(line1, provincias[i].nombre) == 0) {
        // Rellenamos cada posición del array de estructuras con los datos importados.
        strcpy(provincias[i].votosPP, line3);
        strcpy(provincias[i].votosPsoe, line5);
        strcpy(provincias[i].votosIu, line7);
        strcpy(provincias[i].votosUpyd, line9);
        strcpy(provincias[i].votosPodemos, line11);
        strcpy(provincias[i].votosCiudadanos, line13);
      }
    }
  } while((eofReturn != EOF));

  fclose(txtFile);
}

void rellenarVotosProvincias() {
  int i;
  for (i = 0; i < 51; i++) {
    // Llenamos el array con los votos importados en la estructura.
    arrayVotos[i][0] = atol(provincias[i].votosPP);
    arrayVotos[i][1] = atol(provincias[i].votosPsoe);
    arrayVotos[i][2] = atol(provincias[i].votosIu);
    arrayVotos[i][3] = atol(provincias[i].votosUpyd);
    arrayVotos[i][4] = atol(provincias[i].votosPodemos);
    arrayVotos[i][5] = atol(provincias[i].votosCiudadanos);

    tempArray[i][0] = arrayVotos[i][0];
    tempArray[i][1] = arrayVotos[i][1];
    tempArray[i][2] = arrayVotos[i][2];
    tempArray[i][3] = arrayVotos[i][3];
    tempArray[i][4] = arrayVotos[i][4];
    tempArray[i][5] = arrayVotos[i][5];
  }
}

void inicializarNombresArray() {
  int i;
  for (i = 0; i < 51; i++) {
    int j;
    for (j = 0; j < 6; j++) {
      arrayNombres[i][j] = j + 1;
    }
  }
}

void dhondt() {
  long temp1;
  int temp2;
  int mayor;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  long cocientes[6];
  long divisores[6];

  for (i = 0; i < 51; i++) {
    // Recorremos todo el array de estructuras reordenando los votos junto con los nombres de los partidos.
    // for (j = 0; j < 6; j++) {
    //   for (k = 1 + j; k < 6; k++) {
    //     if (tempArray[i][j] < tempArray[i][k]) {
    //       temp1 = tempArray[i][k];
    //       temp2 = arrayNombres[i][k];
    //
    //       tempArray[i][k] = tempArray[i][j];
    //       arrayNombres[i][k] = arrayNombres[i][j];
    //
    //       tempArray[i][j] = temp1;
    //       arrayNombres[i][j] = temp2;
    //     }
    //   }
    // }

    // Dhondt se encargará de hacer las operaciones pertinentes. Es importante tenerlo dentro de esta función ya que vamos a machacar constantemente los nombres de los partidos. Lo ejecutamos dentro del for ya que vamos a ir rellenando los diputados posición a posición.
    for (l = 0; l < 6; l++) {
      divisores[l] = 1;
    }

    for (m = 0; m < provincias[i].diputados; m++) {
      cocientes[0] = arrayVotos[i][0] / divisores[0];
      cocientes[1] = arrayVotos[i][1] / divisores[1];
      cocientes[2] = arrayVotos[i][2] / divisores[2];
      cocientes[3] = arrayVotos[i][3] / divisores[3];
      cocientes[4] = arrayVotos[i][4] / divisores[4];
      cocientes[5] = arrayVotos[i][5] / divisores[5];

      for (n = 0; n < 6; n++) {
        if (cocientes[n] > mayor) {
          mayor = n;
        }
      }

      printf("%ld\n",cocientes[0]);
      provincias[i].diputadosArray[mayor] += 1;
      divisores[mayor] += 1;
      mayor = 0;
    }
  }
}

void imprimirVotos() {
  // int i;
  // for (i = 0; i < 51; i++) {
  //   puts(provincias[i].nombre);
  //   int j;
  //   for (j = 0; j < 6; j++) {
  //     // Array votos desordenado
  //     printf("%s: %d\n", arrayNombres[j], arrayVotos[i][j]);
  //   }
  // }
}
