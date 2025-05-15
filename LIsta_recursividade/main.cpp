#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Exercício 1
int fatorial(int n) {
    if (n == 0) return 1;
    return n * fatorial(n - 1);
}

// Exercício 2
int soma(int n) {
    if (n == 0) return 0;
    return n + soma(n - 1);
}

// Exercício 3
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

// Exercício 4
int pot(int base, int expoente) {
    if (expoente == 0) return 1;
    return base * pot(base, expoente - 1);
}

// Exercício 5
int somaDigitos(int n, int soma) {
    if (n == 0) return soma;
    return somaDigitos(n/10, soma + n%10);
}

// Exercício 6
void decimalParaBinario(int n) {
    if (n == 0) return;
    decimalParaBinario(n / 2);
    printf("%d", n % 2);
}

// Exercício 7
int mdc(int a, int b) {
    if (b == 0) return a;
    return mdc(b, a % b);
}

// Exercício 8
int somaArray(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n-1] + somaArray(arr, n-1);
}

// Exercício 9
int maiorElemento(int arr[], int n) {
    if (n == 1) return arr[0];
    int max = maiorElemento(arr, n-1);
    return (arr[n-1] > max) ? arr[n-1] : max;
}

// Exercício 10
int produto(int a, int b) {
    if (b == 0) return 0;
    return a + produto(a, b-1);
}

// Exercício 11
void imprimirInverso(char *str, int index) {
    if (index < 0) return;
    printf("%c", str[index]);
    imprimirInverso(str, index - 1);
}

// Exercício 12
int palindromo(char *str, int inicio, int fim) {
    if (inicio >= fim) return 1;
    if (str[inicio] != str[fim]) return 0;
    return palindromo(str, inicio + 1, fim - 1);
}

// Exercício 13
void imprimirNaturais(int n) {
    if (n == 0) return;
    imprimirNaturais(n-1);
    printf("%d ", n);
}

// Exercício 14
void imprimirImpares(int n) {
    if (n <= 0) return;
    imprimirImpares(n-1);
    if (n % 2 != 0) printf("%d ", n);
}

// Exercício 15
void imprimirDecrescente(int n) {
    if (n == 0) return;
    printf("%d ", n);
    imprimirDecrescente(n-1);
}

// Exercício 16
int somaIntervalo(int a, int b) {
    if (a > b) return 0;
    return a + somaIntervalo(a+1, b);
}

// Exercício 17
int buscaArray(int arr[], int n, int x) {
    if (n == 0) return 0;
    if (arr[n-1] == x) return 1;
    return buscaArray(arr, n-1, x);
}

// Exercício 18
int comprimentoString(char *str) {
    if (*str == '\0') return 0;
    return 1 + comprimentoString(str+1);
}

// Exercício 19
void torreHanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        return;
    }
    torreHanoi(n-1, origem, auxiliar, destino);
    printf("Mover disco %d de %c para %c\n", n, origem, destino);
    torreHanoi(n-1, auxiliar, destino, origem);
}

// Exercício 20
void trocar(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permutar(char *str, int l, int r) {
    if (l == r) printf("%s\n", str);
    else {
        for (int i = l; i <= r; i++) {
            trocar((str+l), (str+i));
            permutar(str, l+1, r);
            trocar((str+l), (str+i));
        }
    }
}

// Exercício 21
void combinacoes(int arr[], int data[], int start, int end, int index, int k) {
    if (index == k) {
        printf("{");
        for (int j = 0; j < k; j++) printf("%d ", data[j]);
        printf("}\n");
        return;
    }
    for (int i = start; i <= end && end-i+1 >= k-index; i++) {
        data[index] = arr[i];
        combinacoes(arr, data, i+1, end, index+1, k);
    }
}

// Exercício 22
void subconjuntos(int arr[], int n, int index, int subset[]) {
    if (index == n) {
        printf("{");
        for (int i = 0; i < n; i++)
            if (subset[i]) printf("%d ", arr[i]);
        printf("}\n");
        return;
    }
    subset[index] = 0;
    subconjuntos(arr, n, index+1, subset);
    subset[index] = 1;
    subconjuntos(arr, n, index+1, subset);
}

// Exercício 23
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

// Exercício 24
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high-1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

// Exercício 25
int buscaBinaria(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return buscaBinaria(arr, l, mid-1, x);

        return buscaBinaria(arr, mid+1, r, x);
    }

    return -1;
}

// Exercício 26
int exponenciacaoRapida(int x, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int temp = exponenciacaoRapida(x, n/2);
        return temp * temp;
    }
    return x * exponenciacaoRapida(x, n-1);
}

// Exercício 27
int caminhosMatriz(int x, int y, int x2, int y2) {
    if (x > x2 || y > y2) return 0;
    if (x == x2 && y == y2) return 1;
    return caminhosMatriz(x+1, y, x2, y2) + caminhosMatriz(x, y+1, x2, y2);
}

// Exercício 28
int seguro(int tab[], int linha, int col, int n) {
    for (int i = 0; i < linha; i++)
        if (tab[i] == col || abs(tab[i] - col) == linha-i) return 0;
    return 1;
}

void resolverRainhas(int tab[], int linha, int n) {
    if (linha == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tab[i] == j) printf("Q ");
                else printf(". ");
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
    for (int col = 0; col < n; col++) {
        if (seguro(tab, linha, col, n)) {
            tab[linha] = col;
            resolverRainhas(tab, linha+1, n);
        }
    }
}

// Exercício 29
int resolverLabirinto(int labirinto[3][4], int x, int y, int solucao[3][4]) {
    if (x == 2 && y == 3 && labirinto[x][y] == 0) {
        solucao[x][y] = 1;
        return 1;
    }
    if (x >= 0 && y >= 0 && x < 3 && y < 4 && labirinto[x][y] == 0) {
        solucao[x][y] = 1;
        if (resolverLabirinto(labirinto, x+1, y, solucao)) return 1;
        if (resolverLabirinto(labirinto, x, y+1, solucao)) return 1;
        solucao[x][y] = 0;
        return 0;
    }
    return 0;
}

// Exercício 30
void gerarParenteses(char *str, int pos, int n, int aberto, int fechado) {
    if (fechado == n) {
        printf("%s\n", str);
        return;
    }
    if (aberto < n) {
        str[pos] = '(';
        gerarParenteses(str, pos+1, n, aberto+1, fechado);
    }
    if (aberto > fechado) {
        str[pos] = ')';
        gerarParenteses(str, pos+1, n, aberto, fechado+1);
    }
}

int main(){
    //EX1
    printf("Fatorial: %d\n", fatorial(5));
    //EX2
    printf("Soma: %d\n", soma(4));
    //EX3
    printf("Fibonacci: %d\n", fibonacci(6));
    //EX4
    printf("Potenciacao: %d\n", pot(2,5));
    //EX5
    printf("Soma de digitos: %d\n", somaDigitos(1234,0));
    //EX6
    printf("Decimal para Binario: ");
    decimalParaBinario(10);
    printf("\n");
    //EX7
    printf("MDC: %d\n", mdc(54,24));
    //EX8
    int arr1[] = {1,2,3,4,5};
    printf("Soma do Array: %d\n", somaArray(arr1, 5));
    //EX9
    printf("Maior Elemento: %d\n", maiorElemento(arr1, 5));
    //EX10
    printf("Produto: %d\n", produto(4,5));
    //EX11
    printf("String Invertida: ");
    imprimirInverso("recursao", 7);
    printf("\n");
    //EX12
    printf("Palindromo: %d\n", palindromo("radar", 0, 4));
    //EX13
    printf("Naturais: ");
    imprimirNaturais(5);
    printf("\n");
    //EX14
    printf("Impares: ");
    imprimirImpares(10);
    printf("\n");
    //EX15
    printf("Decrescente: ");
    imprimirDecrescente(5);
    printf("\n");
    //EX16
    printf("Soma Intervalo: %d\n", somaIntervalo(1,5));
    //EX17
    printf("Busca Array: %d\n", buscaArray(arr1,5,3));
    //EX18
    printf("Comprimento String: %d\n", comprimentoString("recursivo"));
    //EX19
    printf("Torre de Hanoi:\n");
    torreHanoi(2,'A','C','B');
    //EX20
    char str[] = "abc";
    printf("Permutacoes:\n");
    permutar(str, 0, 2);
    //EX21
    int data[2];
    printf("Combinacoes:\n");
    combinacoes(arr1, data, 0, 2, 0, 2);
    //EX22
    int subset[2];
    printf("Subconjuntos:\n");
    subconjuntos(arr1, 2, 0, subset);
    //EX23
    int arr2[] = {5,3,8,1};
    mergeSort(arr2, 0, 3);
    printf("Merge Sort: ");
    for(int i=0;i<4;i++) printf("%d ", arr2[i]);
    printf("\n");
    //EX24
    int arr3[] = {9,2,5,1,7};
    quickSort(arr3, 0, 4);
    printf("Quick Sort: ");
    for(int i=0;i<5;i++) printf("%d ", arr3[i]);
    printf("\n");
    //EX25
    printf("Busca Binaria: %d\n", buscaBinaria(arr3, 0, 4, 5));
    //EX26
    printf("Exponenciacao Rapida: %d\n", exponenciacaoRapida(3,4));
    //EX27
    printf("Caminhos Matriz: %d\n", caminhosMatriz(0,0,2,2));
    //EX28
    int tab[4];
    printf("N-Rainhas:\n");
    resolverRainhas(tab,0,4);
    //EX29
    int labirinto[3][4] = {{0,1,0,0},{0,0,0,1},{1,0,1,0}};
    int solucao[3][4] = {0};
    printf("Labirinto:\n");
    if (resolverLabirinto(labirinto,0,0,solucao)) {
        for(int i=0;i<3;i++){
            for(int j=0;j<4;j++) printf("%d ", solucao[i][j]);
            printf("\n");
        }
    }
    //EX30
    char strp[20];
    printf("Parenteses Validos:\n");
}