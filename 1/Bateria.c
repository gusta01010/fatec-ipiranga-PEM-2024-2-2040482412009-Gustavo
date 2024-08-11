//Gustavo Ribeiro Lima
//ADS - 2º semestre - Tarde 

#include <stdlib.h>
#include <stdio.h>
int main(){
    int notas, cNota=0, lista=0;
    char opt;
    float notaProva, classift=0, notaMin=10, notaMax=0, classif=0;
    float raclog, proj, ingl, agil, javas, ordem =0, notaAtual;
    //int conjunto[10][6] = {{2, 10, 90, 30, 10, 40},{3, 2}};
    //conjunto[1][0] = 9;
    //conjunto[1][2] = 7;
    float conjunto[10][7];
    //limite de 7 questões
                //1 é o limite de conjunto macro
                //5 é o limite de conjunto dentro do conjunto
    //printf("%i", conjunto[1][2]);
                //0 é a prova aplicada
                //5 é a questao respondida
    printf("Digite a qtd. de questões: ");
    scanf("%i", &notas);

    while (notas != 0) {
        while (notas == 2 || notas == 1){
            printf("Digite novamente\nDigite a qtd. de questões: ");
            scanf("%i", &notas);
        }
        if (notas > 2 && opt != 'n'){
            conjunto[lista][cNota] = notas;
            while (cNota != notas){
                cNota = cNota + 1;
                printf("Digite o valor da prova: ");
                scanf("%f", &notaProva);
                conjunto[lista][cNota] = notaProva;
            }
        printf("\nDeseja adicionar mais uma prova? (s/n): ");
        /*
        Não necessário, ⬆ poderia ser reescrito como apenas digite o nº de questões,
        mas devemos também levar em conta a acessibilidade e a navegação do usuário
        no sistema, implementando uma maneira fácil do usuário querer optar pelo
        prosseguimento na aplicação.
        */
        scanf("%s", &opt);
        if (opt == 's'){
            printf("\nDigite a qtd. de questões: ");
            scanf("%i", &notas);
            lista = lista + 1;
            cNota=0;
        }
        else
        {
            for(int i=0; i<=lista; i++) //Classifica as notas após o usuário não aceitar continuar
            {
                notaMin = 10;
                notaMax = 0;
                notaAtual = 0;
                for(int c=0; c<=conjunto[i][0]; c++)
                {
                    if (c == 0){
                        printf("%.0f\n", conjunto[i][c]);
                        c = c+1;
                        }
                    if (conjunto[i][c]>=notaMax)
                        notaMax = conjunto[i][c];
                    if (notaMin >= conjunto[i][c])
                        notaMin = conjunto[i][c];

                    printf("%.1f ", conjunto[i][c]);
                    classift = classift + conjunto[i][c];
                    notaAtual = notaAtual + conjunto[i][c];
                }
                
                classift = classift - (notaMin+notaMax);
                ordem = ordem + 1;
                if (ordem == 1)
                    raclog = notaAtual - (notaMax+notaMin);
                else if (ordem == 2)
                    proj = notaAtual - (notaMax+notaMin);
                else if (ordem == 3)
                    ingl = notaAtual - (notaMax+notaMin);
                else if (ordem == 4)
                    agil = notaAtual - (notaMax+notaMin);
                else if (ordem == 5)
                    javas = notaAtual - (notaMax+notaMin);
                //printf("\nTotal: %.1f", classift);  
                //printf("\n%.1f", notaMin);
                //printf("\n%.1f", notaMax);

                printf("\n");
            }
            notas = 0;
            printf("Nota Raciocinio Logico = %.1f\n", raclog);
            printf("Nota Conceitos de gerenciamento de projetos = %.1f\n", proj);
            printf("Nota Lingua Inglesa = %.1f\n", ingl);
            printf("Nota Conceitos de metodologia agil = %.1f\n", agil);
            printf("Nota Linguagem javascript = %.1f\n", javas);
            printf("\nNota final do candidato: %.1f\n\n", classift); 
            system("pause");
        }
        }
    }
}