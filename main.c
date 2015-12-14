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
  int diputadosPP;
  int diputadosPsoe;
  int diputadosIu;
  int diputadosUpyd;
  int diputadosPodemos;
  int diputadosCiudadanos;
};

struct Provincia provincias[51];

void inicializacionDiputados();
void importTxt();
void dhondt();

int main(int argc, char *argv[]) {

  struct Provincia madrid = {"Madrid", 36};
  struct Provincia barcelona = {"Barcelona", 31};
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
  struct Provincia almeria = {"Almeria", 6};*/
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
  importTxt();
  dhondt();


  puts(provincias[0].nombre);
  puts(provincias[0].votosPP);
  puts(provincias[0].votosPsoe);

  puts(provincias[22].nombre);
  puts(provincias[22].votosPP);
  puts(provincias[22].votosPsoe);
}

void inicializacionDiputados() {
  int i;
  for (i = 0; i < 51; i++) {
    provincias[i].diputadosPP = 0;
    provincias[i].diputadosPsoe = 0;
    provincias[i].diputadosIu = 0;
    provincias[i].diputadosUpyd = 0;
    provincias[i].diputadosPodemos = 0;
    provincias[i].diputadosCiudadanos = 0;
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
  strcat(fileName, ".txt");

  txtFile = fopen(fileName, "r");

  do {
    eofReturn = fscanf(txtFile, "%s", line1);
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

void dhondt() {
    char* arrayNombres[] = {"PP", "PSOE", "IU", "UPYD", "Podemos", "Ciudadanos"};
  long arrayVotos[6];
  long temp1;
  char* temp2;

  int i;
  for (i = 0; i < 51; i++) {
    arrayVotos[0] = atol(provincias[i].votosPP);
    arrayVotos[1] = atol(provincias[i].votosPsoe);
    arrayVotos[2] = atol(provincias[i].votosIu);
    arrayVotos[3] = atol(provincias[i].votosUpyd);
    arrayVotos[4] = atol(provincias[i].votosPodemos);
    arrayVotos[5] = atol(provincias[i].votosCiudadanos);

    int j;
    for (j = 0; j < 6; j++) {
      int k;
      for (k = 1 + j; k < 6; k++) {
        if (arrayVotos[j] < arrayVotos[k]) {
          temp1 = arrayVotos;
          strcpy(temp2, arrayNombres);

          arrayVotos[k] = arrayVotos[j];
          strcpy(arrayNombres[j], arrayNombres[k]);

          arrayVotos[j] = temp1;
          strcpy(arrayNombres[j], temp2);
        }
      }
    }
  }
}
