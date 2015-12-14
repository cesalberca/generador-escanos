#include <stdio.h>
#include <string.h>

FILE *txtFile;

struct Provincia {
  char nombre[100];
  int diputados;
};

struct Partido {
  char nombre[100];
};

struct Provincia provincias[51];

void importTxt();

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

  importTxt();
}

void importTxt() {
  char fileName[200];
  char line[300];
  int eofReturn = 0;

  puts("Introduce el nombre del archivo txt a importar:");
  scanf("%s", fileName);
  strcat(fileName, ".txt");

  txtFile = fopen(fileName, "r");

  do {
    eofReturn = fscanf(txtFile, "%s", line);
    if ((strcmp(line, "#") != 0)) {
      printf("Provincia %s\n", line);
    }
  } while((eofReturn != EOF));

  fclose(txtFile);
}
