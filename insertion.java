import java.util.Random;
import java.io.FileWriter;
import java.io.IOException;

public class insertion {
  static int NUMVET = 1024;
  static int VETSIZE = 100;
  static int LOOP = 1024;

  public static void insertionSort(int array[]) {
    int n = array.length;
    for (int j = 1; j < n; j++) {
      int key = array[j];
      int i = j - 1;
      while ((i > -1) && (array[i] > key)) {
        array[i + 1] = array[i];
        i--;
      }
      array[i + 1] = key;
    }
  }

  public static void main(String[] args) throws IOException {
    int loop_interno;

    try (FileWriter salvar_tempo = new FileWriter("tempos em java.txt")) {
      for (loop_interno = 0; loop_interno < LOOP; loop_interno++) {
        double fim;
        double inicio = System.currentTimeMillis();
        Random gerador = new Random();
        int arr1[] = new int[VETSIZE];
        for (int j = 0; j < NUMVET; j++) {
          for (int i = 0; i < VETSIZE; i++) {
            arr1[i] = gerador.nextInt(101);
          }

          insertionSort(arr1);

          /*for (int i : arr1) {
            System.out.print(i + " ");
          }
          System.out.print("\n");*/
        }
        fim = (System.currentTimeMillis() - inicio) / 1000;
        System.out.println("Tempo de execucao em segundos: " + fim);
        salvar_tempo.write(Double.toString(fim) + "\n");
      }
      salvar_tempo.close();
    }
  }
}