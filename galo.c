#include <stdio.h>
#include <stdlib.h>
#include "galo.h"

void limpar(char v[3][3]) {/*funçao que vai meter um " " em todas as posiçoes do vetor*/
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            v[i][j] = ' ';


}

void desenhar(char v[3][3]) {/*desenha o tabuleiro de jogo*/
    int i;
    printf("\n\n");
    for (i = 0; i <= 2; i++) {
        printf("\t\t\t\t\t");
        printf("%c | %c | %c", v[i][0], v[i][1], v[i][2]);
        if (i < 2) printf("\n\t\t\t\t\t----------\n");

    }
    printf("\n\n\n\n");
}

int vitoria(char v[3][3], char ch) {/*apos cada jogada verifica se o jogador venceu*/
    int c, l, d1, d2, i;




    d1 = (v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[0][0] == ch); /*verifica as diagonais*/
    d2 = (v[0][2] == v[1][1] && v[1][1] == v[2][0] && v[0][2] == ch);

    for (i = 0; i <= 2; i++) {
        c = (v[0][i] == v[1][i] && v[1][i] == v[2][i] && v[1][i] == ch); /*verifica as colunas*/
        l = (v[i][0] == v[i][1] && v[i][1] == v[i][2] && v[i][1] == ch); /*verifica as linhas*/

        if (c) return 1;
        if (l) return 1;
    }
    if (!c && !l && d1 || d2) return 1;
    else return 0;
    /*se um jogador venceu retorna 1(verdadeiro) se nao retorna 0(falso)*/
}

void jogar(char v[3][3]) {/*funçao que permite que o jogador insira as coordenadas da posiçao onde quer jogar e verifica se é uma jogada valida*/


    int x, y;
    char ch = 'o';
    int njogadas = 0;

    while (1) {
        system("cls"); /*limpa a consola*/
        desenhar(v);
        printf("insira a linha");
        scanf("%d", &x);
        printf("insira a coluna");
        scanf("%d", &y);

        if (x > 3 || y > 3 || x < 1 || y < 1) {/*verifica se as coordenadas inseridas sao validas(1, 2 ou 3)*/
            printf("\n\n valores invalidos\n\n");
            continue;
        }
        x--;
        y--;

        if (v[x][y] == ' ') {/*verifica se a posiçao esta livre*/
            if (njogadas % 2 == 0) ch = 'o'; /*alterna de '0' para 'x' conforme o valor de njogadas*/
            else ch = 'x';
            v[x][y] = ch;
            njogadas++;
            if (vitoria(v, ch)) {/*se a funçao vitoria retornar um valor verdadeiro quer dizer que temos um vencedor*/
                printf("ganhou o jogador '%c'", ch);
                break;
            }
        } else printf("posicao ocupada\n");
        if (njogadas == 9) {/*se chegar as 9 jogadas o jogo termina empatado*/
            printf("\n\nempate\n\n");
            break;
        }

    }
    desenhar(v);
    menu(); /*apos o jogo acabar permite voltar a jogar, consultar as regras ou sair*/

}

void menu() {/*permite que o utilizador escolha entre jogar, consultar as regras ou sair*/
    int op;
    char v[3][3];
    printf("\nJogo do Galo");
    printf("\nMenu");
    printf("\n1-Jogar");
    printf("\n2-Regras");
    printf("\n3-Sair\n");
    scanf("%d", &op);

    switch (op) {
        case 1:
        {
            system("cls");
            limpar(v);
            jogar(v);
            break;
        }
        case 2:
        {
            system("cls");
            printf("\n- O objectivo do Jogo do Galo e colocar tres elementos alinhados em qualquer direcao: horizontal, vertical ou diagonal \ne impedir que o adversario o faca.\n");
            printf("\n- Cada jogador joga a vez, pondo o seu sinal (circulo ou cruz) na casa que escolher.\n");
            printf("\n- Para escolher a casa onde quer jogar deve inserir as coordenadas 1, 2 ou 3 tanto para a linha como para a coluna");
            printf("\n- Como estrategia deve-se tentar ir colocando os tres elementos de modo a poder ganhar e, ao mesmo tempo, impedir o \nadversario de alinhar os seus.\n");
            printf("\n- O jogo termina com a vitoria de um dos jogadores ou com um empate.\n");

            menu(v);
            break;
        }
        case 3:break;
    }
}
