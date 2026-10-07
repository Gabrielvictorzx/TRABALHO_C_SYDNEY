#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "Portuguese");
    
    int qtd_equipe, qtd_jogos;
    int opcao = 0;
    int registro_completo = 0;
    int vitorias, derrotas, empate, pontos, equipe;
    int qtd_excelente, qtd_boa, qtd_regular, qtd_ruim;
    int total_vitorias, total_empates, total_derrotas, soma_pontos;
    int maior_pontuacao, equipe_maior, empate_maior;
    int menor_pontuacao, equipe_menor, empate_menor;

    printf("\nDigite a quantidade de equipes (3-10): ");
    scanf("%d", &qtd_equipe);
    
    while (qtd_equipe < 3 || qtd_equipe > 10) {
        printf("\nErro: Opção inválida, selecione de 3 a 10: ");
        scanf("%d", &qtd_equipe);
    }
    
    printf("\nDigite a quantidade de jogos por equipe (1-10): ");
    scanf("%d", &qtd_jogos);
    
    while (qtd_jogos < 1 || qtd_jogos > 10) {
        printf("\nErro: Opção inválida, selecione de 1 a 10: ");
        scanf("%d", &qtd_jogos);
    }
    
    while (opcao != 5) {
        printf("\n==== MENU ====\n");
        printf("\n 1 - Registrar resultados do campeonato.");
        printf("\n 2 - Mostrar resumo do campeonato.");
        printf("\n 3 - Mostrar regulamento.");
        printf("\n 4 - Simular campanha de uma equipe.");
        printf("\n 5 - Encerrar sistema.\n");
        printf("\n Escolha uma opção (1-5): ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                registro_completo = 0;
                total_vitorias = 0;
                total_empates = 0;
                total_derrotas = 0;
                soma_pontos = 0;
                qtd_excelente = 0;
                qtd_boa = 0;
                qtd_regular = 0;
                qtd_ruim = 0;
                maior_pontuacao = 0;
                equipe_maior = 0;
                empate_maior = 0;
                menor_pontuacao = 0;
                equipe_menor = 0;
                empate_menor = 0;
                
                for (equipe = 1; equipe <= qtd_equipe; equipe++) {
                    printf("\nEquipe %d:", equipe);
                    printf("\nVitórias: ");
                    scanf("%d", &vitorias);
                    printf("Empates: ");
                    scanf("%d", &empate);
                    printf("Derrotas: ");
                    scanf("%d", &derrotas);
                    
                    while (vitorias < 0 || empate < 0 || derrotas < 0 || (vitorias + empate + derrotas != qtd_jogos)) {
                        printf("\nValores inválidos, nenhum pode ser negativo e a soma deve ser %d.", qtd_jogos);
                        printf("\nVitorias: ");
                        scanf("%d", &vitorias);
                        printf("Empates: ");
                        scanf("%d", &empate);
                        printf("Derrotas: ");
                        scanf("%d", &derrotas);
                    }
                    
                    pontos = vitorias * 3 + empate * 1;
                    printf("\nPontuação da equipe %d: %d pontos.\n", equipe, pontos);
                    
                    if (pontos >= 15) {
                        printf("Situação: Excelente campanha.\n");
                    } else if (pontos >= 10) {
                        printf("Situação: Boa campanha.\n");
                    } else if (pontos >= 5) {
                        printf("Situação: Campanha regular.\n");
                    } else {
                        printf("Situação: Campanha ruim.\n");
                    }
                }

                total_vitorias += vitorias;
                total_empates += empate;
                total_derrotas += derrotas;
                soma_pontos += pontos;

                if (equipe == 1){
                    maior_pontuacao = pontos;
                    equipe_maior = equipe;
                    empate_maior = 1;

                    menor_pontuacao = pontos;
                    equipe_menor = equipe;
                    empate_menor = 1;
                } else {
                    if (pontos > maior_pontuacao){
                        maior_pontuacao = pontos;
                        equipe_maior = equipe;
                        empate_maior = 1;
                    } else if (pontos == maior_pontuacao){
                        empate_maior++;
                    }

                    if (pontos < menor_pontuacao){
                        menor_pontuacao = pontos;
                        equipe_menor = equipe;
                        empate_menor = 1;
                    } else if (pontos == menor_pontuacao){
                        empate_menor++;
                    }
                }

                registro_completo = 1;
                printf("\n Registro concluido com sucesso!.\n");
                break; 
                
            case 5:
                printf("\nEncerrando o sistema...\n");
                break;
                
            default:
                if (opcao != 5) {
                    printf("\nOpção inválida!\n");
                }
        }
    }
    return 0;
}