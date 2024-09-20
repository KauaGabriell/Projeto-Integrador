#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os requisitos e suas prioridades
typedef struct {
    char requisito[100];
    char classificacao[10];
} Requisito;

// Função para classificar a média das dificuldades
void classificar_requisito(Requisito *r, int viabilidade, int prioridade) {
    // Calcular a média das classificações
    float media = (viabilidade + prioridade) / 2.0;

    
    if (media <= 1.5) {
        strcpy(r->classificacao, "Baixa");
    } else if (media <= 2.5) {
        strcpy(r->classificacao, "Media");
    } else {
        strcpy(r->classificacao, "Alta");
    }
}

int main() {
    Requisito requisitos[100]; 
    int viabilidade, prioridade;
    char continuar;
    int contador = 0; // Contador para colocar os requisitos que colocar na seção acima

    do {
        
        printf("Informe o requisito do sistema: ");
        getchar();  
        fgets(requisitos[contador].requisito, 100, stdin);

        // Remover a nova linha no final da string capturada por fgets
        requisitos[contador].requisito[strcspn(requisitos[contador].requisito, "\n")] = 0;

        // Entrada da viabilidade tecnica
        printf("Classifique a viabilidade tecnica (1- Baixa, 2- Media, 3- Alta): ");
        scanf("%d", &viabilidade);

        // Entrada da prioridade de implementacao
        printf("Classifique a prioridade de implementacao (1- Baixa, 2- Media, 3- Alta): ");
        scanf("%d", &prioridade);

        // Classificar o requisito com base nas entradas e calcular a media
        classificar_requisito(&requisitos[contador], viabilidade, prioridade);

        // Perguntar se o usuário deseja continuar
        printf("\nDeseja inserir outro requisito? (S/N): ");
        getchar();  
        scanf("%c", &continuar);

        contador++; // Incrementa o contador de requisitos

    } while (continuar == 'S' || continuar == 's');

    // Exibir todos os requisitos e suas classificações de prioridade
    printf("\nResumo dos requisitos inseridos:\n");
    for (int i = 0; i < contador; i++) {
        printf("Requisito: %s - Prioridade %s\n", requisitos[i].requisito, requisitos[i].classificacao);
    }

    printf("\nEncerrando o programa.\n");

    return 0;
}
