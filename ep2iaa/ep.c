/*********************************************************************/
/**   ACH2002 - IAA                                                 **/
/**   EACH-USP - Segundo Semestre de 2023                           **/
/**   Prof. Ariane Machado Lima                                     **/
/**                                                                 **/
/**   Segundo Exercicio-Programa                                    **/
/**                                                                 **/
/**   <ANA PAULA BERNARDO DOS SANTOS>          <14785580>           **/
/**                                                                 **/   
/**   <26.12.2023>                                                  **/
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

// --- Número máximo de atualizações --- //

#define MAX 100

// --- Estrutura para armazenar as informações --- //

typedef struct {
    int indice;
    int tempo;
    int instante;
    char letra;
} Atualizacao;

// --- Estrutura de um heap mínimo --- //

typedef struct {
    Atualizacao* cenario [MAX];
    int tamanho; // tamanho do Vetor
    int capacidadeHeap; // tamanho do Heap
} HeapMinimo;

// --- Variáveis Globais --- //

int T; // Tempo de 14 a 20
int C; // Cenário 1 ou 2
int N; // Número de atualizações (ARQUIVO)
int Ntotal = 0; // Número total de atualizações possíveis (RESPOSTA)
int Ntotaldin; // Número total de atualizações dinâmicas (ARQUIVO)
char IouC; // Identificação do Cenário 2
char linha[MAX]; // Identificação da linha de entrada do Cenário 2
Atualizacao cenario1 [MAX]; // Estrutura para o Cenário 1
Atualizacao cenario2 [MAX]; // Estrutura para o Cenário 2
Atualizacao resposta [MAX*2]; // Estrutura para a Resposta

// --- Funções parar ler e guardar a entrada na memória a partir do arquivo txt --- //

void le_Arquivo(char* nomeArquivo, Atualizacao* cenario1, int *numAtualizacoesDinamicas){

    int i, att, tmp; // Variáveis auxiliares

    FILE* file;

    file = fopen(nomeArquivo, "r");

    if (file == NULL) {
        printf("Arquivo nao pode ser aberto.\n");
        exit(1);
    }

    // Valor total N da parte Estática

    fscanf(file, "%d", &N);

    // Leitura do arquivo .txt de entrada

    for(i = 0; i < N; i++){
        att = i + 1;
        fscanf(file, "%d", &tmp);

        cenario1[i].indice = att;
        cenario1[i].tempo = tmp;
    }

    if(C == 2){
        *numAtualizacoesDinamicas = 0;
         while (fgets(linha, sizeof(linha), file) != NULL) {
            
            if (sscanf(linha, "%c %d %d %d", &(cenario2[*numAtualizacoesDinamicas].letra), &(cenario2[*numAtualizacoesDinamicas].instante), &(cenario2[*numAtualizacoesDinamicas].indice), &(cenario2[*numAtualizacoesDinamicas].tempo)) == 4){
                (*numAtualizacoesDinamicas)++; // Incrementa o contador de atualizações dinâmicas
            }
               
            // Verifica se atingiu o limite de 100 atualizações dinâmicas
            if (*numAtualizacoesDinamicas == 100) {
                break;
            }   
        }
    }

    Ntotaldin = *numAtualizacoesDinamicas;

    /*printf("%d \n", Ntotaldin);
    for(int i = 0; i < Ntotaldin; i++){
        printf("%d %d %d \n", cenario2[i].instante, cenario2[i].indice, cenario2[i].tempo);
    }
    printf("\n");*/

    fclose(file);

}

// --- Resolução Estática (ORDENAÇÃO + ALGORITMO GULOSO) --- //

void ordena_Atualizacoes(Atualizacao* cenario1){
    int i, j;
    Atualizacao aux;
    // Implementação de um Bubble Sort
    for(i = 0; i < N; i++){
        for(j=0; j<(N-1-i); j++){
            if(cenario1[j].tempo > cenario1[j+1].tempo){
                aux = cenario1[j];
                cenario1[j] = cenario1 [j+1];
                cenario1[j+1] = aux;
            }
        }    
    }
}

void calcula_Atualizacoes(Atualizacao* resposta){

    int tempoAtual = T;

    for(int i = 0; i < N ;i++){
        if(cenario1[i].tempo > tempoAtual) break;
        tempoAtual = tempoAtual - cenario1[i].tempo;
        resposta[i] = cenario1[i];
        Ntotal++;
    }
}

// --- Resolução Dinâmica (HEAP) --- //

// Função para trocar dois elementos em um heap
void trocar(Atualizacao** a, Atualizacao** b) {
    Atualizacao* temp = *a;
    *a = *b;
    *b = temp;
}

// Função para ajustar um heap mínimo a partir de um nó específico
void refazHeapMin(HeapMinimo* heap, int i) {
    int menor = i;
    int esq = (2 * i) + 1;
    int dir = (2 * i) + 2;

    if (esq < heap->tamanho && heap->cenario[esq]->tempo < heap->cenario[menor]->tempo) {
        menor = esq;
    }

    if (dir < heap->tamanho && heap->cenario[dir]->tempo < heap->cenario[menor]->tempo) {
        menor = dir;
    }

    if (menor != i) {
        trocar(&(heap->cenario[i]), &(heap->cenario[menor]));
        refazHeapMin(heap, menor);
    }
}

// Função para construir um heap mínimo
void constroiHeapMin(HeapMinimo* heap) {
    for (int i = (heap->tamanho / 2) - 1; i >= 0; i--) {
        refazHeapMin(heap, i);
    }
}

// Função para inserir um array de elementos no heap mínimo
void insereArrayHeapMin(HeapMinimo* heap, Atualizacao* cenario1, int N) {
    if (heap->tamanho + N <= heap->capacidadeHeap) {
        for (int i = 0; i < N; i++) {
            heap->cenario[heap->tamanho] = &cenario1[i];
            heap->tamanho++;
        }
        constroiHeapMin(heap);
    } else {
        printf("Erro: Heap cheio, não é possível adicionar mais elementos.\n");
    }
}

// Função para inserir um novo elemento no heap mínimo
void insereHeapMin(HeapMinimo* heap, Atualizacao* novoElemento) {
    if (heap->tamanho < heap->capacidadeHeap) {
        heap->cenario[heap->tamanho] = novoElemento;
        heap->tamanho++;
        constroiHeapMin(heap);
    } else {
        printf("Erro: Heap cheio, não é possível adicionar mais elementos.\n");
    }
}

// Função para extrair o elemento mínimo do heap mínimo
Atualizacao* extraiMin(HeapMinimo* heap) {
    if (heap->tamanho == 0) {
        printf("Erro: Heap vazio, não é possível extrair o mínimo.\n");
        return NULL;
    }

    Atualizacao* minimo = heap->cenario[0];
    heap->cenario[0] = heap->cenario[heap->tamanho - 1];
    heap->tamanho--;
    refazHeapMin(heap, 0);

    return minimo;
}

// --- Funções para Calcular os Cenários 1 e 2 --- //

// Função para realizar o procedimento de algoritmo guloso com as atualizações dinâmicas
int procedimentoGulosoDinamico(int tempoLimite, HeapMinimo* heap, Atualizacao* resposta) {
    int tempoRestante = tempoLimite;
    int numAtualizacoes = 0;

    while (tempoRestante > 0 && heap->tamanho > 0) {
        Atualizacao* minimo = extraiMin(heap);

        if (minimo->tempo <= tempoRestante) {
            tempoRestante -= minimo->tempo;
            resposta[numAtualizacoes] = minimo[numAtualizacoes];
            numAtualizacoes++;
            //printf("Atualização: índice %d, Tempo %d\n", minimo->indice, minimo->tempo);
        }

        free(minimo);
    }

    return numAtualizacoes;
}

// Função para processar as atualizações dinâmicas
void processaAtualizacoesDinamicas(char tipo, int instante, int indice, int tempo, HeapMinimo* heap) {
    Atualizacao* novaAtualizacao = (Atualizacao*)malloc(sizeof(Atualizacao));
    novaAtualizacao->indice = indice;
    novaAtualizacao->tempo = tempo;
    novaAtualizacao->instante = instante;

    if (tipo == 'c') {
        // Atualização de tempo
        // Encontrar e atualizar a instância no heap
        for (int i = 0; i < heap->tamanho; i++) {
            if (heap->cenario[i]->indice == indice) {
                heap->cenario[i]->tempo = tempo;
                break;
            }
        }
    } else if (tipo == 'i') {
        // Adição de uma nova atualização
        insereHeapMin(heap, novaAtualizacao);
    } else {
        printf("Tipo de atualização desconhecido: %c\n", tipo);
    }
}

/* -- Nota para a correção: Infelizmente não tive tempo de terminar e arrumar a lógica para calcular o cenário 2
totalmente certo, mas fiz o meu melhor :( */

// Função para liberar a memória alocada para o heap mínimo
void liberaHeapMin(HeapMinimo* heap) {
    for (int i = 0; i < heap->tamanho; i++) {
        free(heap->cenario[i]);
    }
    heap->tamanho = 0;
    heap->capacidadeHeap = 0;
}

// --- Função que printa na tela a resposta final --- //

int printa_Resposta(Atualizacao* resposta, HeapMinimo* heap){
    int i;

    if(C == 1){
        ordena_Atualizacoes(cenario1);
        calcula_Atualizacoes(resposta);
    } else {
        //Chamar as funções para o Cenário 2
        procedimentoGulosoDinamico(T, heap, resposta);
    }
    
    printf("%d ", Ntotal);
    for(i = 0; i < Ntotal; i++){
        printf("%d ", resposta[i].indice);
    }
    printf("\n");
}

// --- Função que salva a saída em um arquivo txt no mesmo diretório do programa --- //

void salva_Saida(Atualizacao* resposta, HeapMinimo* heap){
  FILE *arquivo;
  FILE *stdout_backup;

  if(C == 1){
    arquivo = fopen("saida1.txt", "w");
    stdout_backup = freopen("saida1.txt", "w", stdout);
  } else {
    arquivo = fopen("saida2.txt", "w");
    stdout_backup = freopen("saida2.txt", "w", stdout);
  }

    printa_Resposta(resposta, heap);
  

  fclose(stdout);
  freopen("/dev/tty", "w", stdout);
  fclose(arquivo);
}

// --- Função principal (Main) --- //

int main(int argc, char* argv[]) {
    
    int i, j; // Variáveis auxiliares.
    int numAtualizacoesDinamicas;

    // Condição que verifica se o usuário digitou os argumentos de entrada do programa corretamente 

    if (argc != 4) {
        printf("Uso: %s <14 a 20> <1 ou 2> <arquivo de entradan.txt>\n>", argv[0]);
        return 1;
    }

    int tempo = atoi(argv[1]);
    T = tempo;
    int c = atoi(argv[2]);
    C = c; 
    char* nomeArquivo = argv[3];

    // Outras condições para verificar se o Tempo (entre 14 a 20) e o Cenário (1 ou 2) estão corretos

    if (T < 13 || T > 20 ){
        printf("Erro: Tempo incorreto.");
    } 

    if( C != 1 && C !=2){
        printf("Erro: Cenário inválido.");
    }
   
    // Função para a leitura da Entrada dos Cenários 1 e 2

    le_Arquivo((char*) nomeArquivo, cenario1, &numAtualizacoesDinamicas);
    
    // Estrutura de Heap para o Cenário 2

    HeapMinimo heap;
    heap.tamanho = 0;
    heap.capacidadeHeap = MAX;

    //Copiando os valores do Cenário 1 
    insereArrayHeapMin(&heap, cenario1, N);
    
    // Chamada da função que executará a saída do programa:

    if(C == 2){
        for (int i = 0; i < Ntotaldin ; i++) {
        processaAtualizacoesDinamicas(cenario2[i].letra, cenario2[i].instante, cenario2[i].indice, cenario2[i].tempo, &heap);
        }

        Ntotal = procedimentoGulosoDinamico(T, &heap, resposta);
    }

    salva_Saida(resposta, &heap);
    
    // Liberando a memória do heap
    liberaHeapMin(&heap);

    return 0;
}