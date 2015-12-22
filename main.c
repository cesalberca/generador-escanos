#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *ficheroImportado;
FILE *ficheroHtml;

#define MAX_PROVINCIAS 51
#define MAX_PARTIDOS 6

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

struct Provincia provincias[MAX_PROVINCIAS];
// Ya que los votos son recogidos en forma de caracter, éstos han de ser pasados a long para poder operar con ellos. Los guardamos en un array de long.
long arrayVotos[MAX_PROVINCIAS][MAX_PARTIDOS];
long arrayTemp[MAX_PROVINCIAS][MAX_PARTIDOS];
int arrayNombres[MAX_PROVINCIAS][MAX_PARTIDOS];


void menu();
void inicializacionDiputados();
void inicializarNombresArray();
void importarFichero();
void rellenarVotosProvincias();
void dhondt();
void test();
void generarHtml();

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

  int opcion;

  do {
    menu();
    scanf("%i", &opcion);

    while (opcion < 1 || opcion > 4) {
      puts("Opcion incorrecta");
      scanf("%i", &opcion);
    }

    switch (opcion) {
      case 1:
        inicializacionDiputados();
        inicializarNombresArray();
        importarFichero();
        rellenarVotosProvincias();
        dhondt();
        break;
      case 2:
        generarHtml();
        break;
      case 3:
        test();
        break;
      case 4:
        puts("Gracias por usar nuestro programa");
        break;
    }
  } while(opcion != 4);
}

void menu() {
  puts("1. Importar archivo");
  puts("2. Exportar archivo");
  puts("3. Escribir en consola (Test)");
  puts("4. Salir");
}

void test() {
  // Test 1 Madrid
  printf("%s\n", provincias[0].nombre);
  int i;
  for (i = 0; i < MAX_PARTIDOS; i++) {
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

  // Test 2 Murcia
  printf("%s\n", provincias[MAX_PARTIDOS].nombre);
  for (i = 0; i < MAX_PARTIDOS; i++) {
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
  for (i = 0; i < MAX_PROVINCIAS; i++) {
    int j;
    for (j = 0; j < MAX_PARTIDOS; j++) {
      // Inicializamos los diputados de cada partido a 0.
      provincias[i].diputadosArray[j] = 0;
    }
  }
}

void inicializarNombresArray() {
  int i;
  for (i = 0; i < MAX_PROVINCIAS; i++) {
    int j;
    for (j = 0; j < MAX_PARTIDOS; j++) {
      arrayNombres[i][j] = j + 1;
    }
  }
}

void importarFichero() {
  char nombre[200];
  char linea1[100],
       linea2[100],
       linea3[100],
       linea4[100],
       linea5[100],
       linea6[100],
       linea7[100],
       linea8[100],
       linea9[100],
       linea10[100],
       linea11[100],
       linea12[100],
       linea13[100];
  int eofReturn = 0;

  puts("Introduce el nombre del archivo txt a importar:");
  scanf("%s", nombre);
  // Concatenamos el nombre con .txt
  strcat(nombre, ".txt");

  ficheroImportado = fopen(nombre, "r");

  do {
    eofReturn = fscanf(ficheroImportado, "%s", linea1);
    // Leemos de 13 en 13 líneas hasta que se termine el archivo.
    fscanf(ficheroImportado, "%s", linea2);
    fscanf(ficheroImportado, "%s", linea3);
    fscanf(ficheroImportado, "%s", linea4);
    fscanf(ficheroImportado, "%s", linea5);
    fscanf(ficheroImportado, "%s", linea6);
    fscanf(ficheroImportado, "%s", linea7);
    fscanf(ficheroImportado, "%s", linea8);
    fscanf(ficheroImportado, "%s", linea9);
    fscanf(ficheroImportado, "%s", linea10);
    fscanf(ficheroImportado, "%s", linea11);
    fscanf(ficheroImportado, "%s", linea12);
    fscanf(ficheroImportado, "%s", linea13);

    int i;
    for (i = 0; i < MAX_PROVINCIAS; i++) {
      if (strcmp(linea1, provincias[i].nombre) == 0) {
        // Rellenamos cada posición del array de estructuras con los datos importados.
        strcpy(provincias[i].votosPP, linea3);
        strcpy(provincias[i].votosPsoe, linea5);
        strcpy(provincias[i].votosIu, linea7);
        strcpy(provincias[i].votosUpyd, linea9);
        strcpy(provincias[i].votosPodemos, linea11);
        strcpy(provincias[i].votosCiudadanos, linea13);
      }
    }
  } while((eofReturn != EOF));

  fclose(ficheroImportado);
}

void rellenarVotosProvincias() {
  int i;
  for (i = 0; i < MAX_PROVINCIAS; i++) {
    // Llenamos el array con los votos importados en la estructura.
    arrayVotos[i][0] = atol(provincias[i].votosPP);
    arrayVotos[i][1] = atol(provincias[i].votosPsoe);
    arrayVotos[i][2] = atol(provincias[i].votosIu);
    arrayVotos[i][3] = atol(provincias[i].votosUpyd);
    arrayVotos[i][4] = atol(provincias[i].votosPodemos);
    arrayVotos[i][5] = atol(provincias[i].votosCiudadanos);

    arrayTemp[i][0] = arrayVotos[i][0];
    arrayTemp[i][1] = arrayVotos[i][1];
    arrayTemp[i][2] = arrayVotos[i][2];
    arrayTemp[i][3] = arrayVotos[i][3];
    arrayTemp[i][4] = arrayVotos[i][4];
    arrayTemp[i][5] = arrayVotos[i][5];
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
  long cocientes[MAX_PARTIDOS];
  long divisores[MAX_PARTIDOS];

  for (i = 0; i < MAX_PROVINCIAS; i++) {
    // Recorremos todo el array de estructuras reordenando los votos junto con los nombres de los partidos.
    // for (j = 0; j < MAX_PARTIDOS; j++) {
    //   for (k = 1 + j; k < MAX_PARTIDOS; k++) {
    //     if (arrayTemp[i][j] < arrayTemp[i][k]) {
    //       temp1 = arrayTemp[i][k];
    //       temp2 = arrayNombres[i][k];
    //
    //       arrayTemp[i][k] = arrayTemp[i][j];
    //       arrayNombres[i][k] = arrayNombres[i][j];
    //
    //       arrayTemp[i][j] = temp1;
    //       arrayNombres[i][j] = temp2;
    //     }
    //   }
    // }

    // Dhondt se encargará de hacer las operaciones pertinentes. Es importante tenerlo dentro de esta función ya que vamos a machacar constantemente los nombres de los partidos. Lo ejecutamos dentro del for ya que vamos a ir rellenando los diputados posición a posición.
    for (l = 0; l < MAX_PARTIDOS; l++) {
      divisores[l] = 1;
    }

    for (m = 0; m < provincias[i].diputados; m++) {
      cocientes[0] = arrayVotos[i][0] / divisores[0];
      cocientes[1] = arrayVotos[i][1] / divisores[1];
      cocientes[2] = arrayVotos[i][2] / divisores[2];
      cocientes[3] = arrayVotos[i][3] / divisores[3];
      cocientes[4] = arrayVotos[i][4] / divisores[4];
      cocientes[5] = arrayVotos[i][5] / divisores[5];

      for (n = 0; n < MAX_PARTIDOS; n++) {
        if (cocientes[n] > mayor) {
          mayor = n;
        }
      }
      // printf("%ld\n",cocientes[0]);
      provincias[i].diputadosArray[mayor] += 1;
      divisores[mayor] += 1;
      mayor = 0;
    }
  }
}

void generarHtml() {
  char nombre[100];

  printf("Introduce el nombre del archivo a exportar. No hace falta poner la extension\n");
  scanf("%s", nombre);
  strcat(nombre, ".html");
  ficheroHtml = fopen(nombre, "w");

  fputs("<!doctype html>\n", ficheroHtml);
  fputs("<html>\n", ficheroHtml);
  fputs("\t<head>\n", ficheroHtml);
  fputs("\t\t<meta charset='utf-8'>\n", ficheroHtml);
  fputs("\t\t<meta http-equiv='x-ua-compatible' content='ie-edge'>\n", ficheroHtml);
  fputs("\t\t<title>Práctica Programación | Adrían de la Gala y César Alberca</title>\n", ficheroHtml);
  fputs("\t\t<meta name='description' content='Tablas con diputados por partido y por comunidad según la ley de Dhont.'>\n", ficheroHtml);
  fputs("\t\t<meta name='viewport' content='width=device-width, initial-scale=1'>\n\n", ficheroHtml);
  fputs("\t\t<link rel='stylesheet' href='styles.css", ficheroHtml);
  fputs("'/>\n", ficheroHtml);
  fputs("\t</head>\n", ficheroHtml);
  fputs("\t<body>\n", ficheroHtml);
  fputs("\t\t<div>\n", ficheroHtml);

  int i;
  for (i = 0; i < MAX_PROVINCIAS; i++) {
    fputs("\t\t\t\t<table rules='all' border='1'>\n", ficheroHtml);
    fputs("\t\t\t\t\t<tr>\n", ficheroHtml);
    fputs("\t\t\t\t\t\t<th colspan='2' align='center'>", ficheroHtml);
    // Nombre de cada provincia
    fprintf(ficheroHtml, "%s", provincias[i].nombre);
    fputs("</th>\n", ficheroHtml);
    fputs("\t\t\t\t\t</tr>\n", ficheroHtml);

    int j;
    for (j = 0; j < MAX_PARTIDOS; j++) {
      if (provincias[i].diputadosArray[j] != 0) {
        fputs("\t\t\t\t\t<tr>\n", ficheroHtml);
        fputs("\t\t\t\t\t\t<td>", ficheroHtml);
        // Nombre del partido
        switch (arrayNombres[i][j]) {
          case 1:
            fputs("PP", ficheroHtml);
          break;
          case 2:
            fputs("PSOE", ficheroHtml);
          break;
          case 3:
            fputs("IU", ficheroHtml);
          break;
          case 4:
            fputs("UPYD", ficheroHtml);
          break;
          case 5:
            fputs("Podemos", ficheroHtml);
          break;
          case 6:
            fputs("Ciudadanos", ficheroHtml);
          break;
        }
        fputs("</td>\n", ficheroHtml);

        fputs("\t\t\t\t\t\t<td>", ficheroHtml);
        // Número de diputados
        fprintf(ficheroHtml, "%i", provincias[i].diputadosArray[j]);
        fputs("</td>\n", ficheroHtml);
        fputs("\t\t\t\t\t</tr>\n", ficheroHtml);
      }
    }
    fputs("\t\t\t\t</table>\n", ficheroHtml);
  }
  fputs("\t\t</div>\n", ficheroHtml);
  fputs("\t</body>\n", ficheroHtml);
  fputs("</html>\n", ficheroHtml);

  fclose(ficheroHtml);
}
