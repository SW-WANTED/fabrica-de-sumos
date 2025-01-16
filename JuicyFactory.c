#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"
#include "JuicyFactory.h"

// Fun��es Auxiliares
Pacote criarPacote(char tipo, float peso) {
    Pacote pacote = {tipo, peso, 1};
    return pacote;
}

int validarPacote(Pacote pacote, char tipoEsperado) {
    if (pacote.tipo != tipoEsperado) return 0;
    if ((tipoEsperado == 'A' && (pacote.peso >= 198 && pacote.peso <= 202)) 
	   ||
       (tipoEsperado == 'B' && (pacote.peso >= 990 && pacote.peso <= 1020))
	   ) return 1;
	   
    return 0;
}

// Op��o 1: Inser��o manual
void inserirPacoteManual(Fila * filaPA, Fila * filaPB) {
    char tipo;
    float peso;
    
	printf("Tipo de pacote (A | B): ");
    scanf(" %c", &tipo);
    
	printf("Peso do pacote:\nA: [198 - 202]\nB: [990 - 1020] ");
    scanf("%f", &peso);
    
    Pacote novoPacote = criarPacote(tipo, peso);
    
	if (tipo == 'A') {
        enfileirar(filaPA, novoPacote);
        printf("Pacote inserido na fila PA.\n");
    } else if (tipo == 'B') {
        enfileirar(filaPB, novoPacote);
        printf("Pacote inserido na fila PB.\n");
    } else {
        printf("Tipo de pacote inv�lido!\n");
        // TODO: Adicionar uma vari�vel contadora de preju�zos
    }
}

// Op��o 2: Valida��o
void validarFila(Fila * fila, char tipoEsperado) {
    Lista * atual = fila->inicio;
    while (atual != NULL) {
        atual->pacote.valido = validarPacote(atual->pacote, tipoEsperado);
        atual = atual->prox;
    }
    printf("Fila validada para tipo %c.\n", tipoEsperado);
}

// Op��o 3: Processar Fila de Enchimento (simples para demonstra��o)
void processarFilaEnchimento(Fila * filaEnchimento, Fila * filaEmbalamento, int limiteGrupo) {
	int i;
	
    if (filaEnchimento->tamanho < limiteGrupo) {
        printf("Nao ha pacotes suficientes para processar.\n");
        return;
    }

    printf("Processando grupo de %d pacotes.\n", limiteGrupo);
    for (i = 0; i < limiteGrupo; i++) {
        Pacote pacote = desenfileirar(filaEnchimento);
        enfileirar(filaEmbalamento, pacote);
    }

    printf("Grupo de pacotes movido para fila de embalamento.\n");
}

// Op��o 5: Relat�rios
void imprimirRelatorios(Fila* filaPA, Fila* filaPB, int descartadosA, int descartadosB, int processadosA, int processadosB) {
    printf("\n=== Relat�rios ===\n");
    printf("PA Processados: %d\n", processadosA);
    printf("PB Processados: %d\n", processadosB);
    printf("PA Descartados: %d\n", descartadosA);
    printf("PB Descartados: %d\n", descartadosB);
    printf("Lucro e preju�zo: Parte do projecto n�o desenvolvida\n");
}
