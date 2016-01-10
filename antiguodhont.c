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