//Autor: João Victor Silva Reis dos Santos
//Universidade Federal de Sergipe
//Aracaju - SE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include "Methods.h"

int main(void){
    setlocale(LC_ALL, "");//para imprimir caracteres especiais

    srand(time(NULL));

    FILE *fp;

    int i, opcao, stop;
    float a,b,c,d,f,L,q,r,s,t,x;
    float interpolacao_1, valor_exato;
    solucao A;
    solucao_matricial W;
                printf("\n\n Escolha uma das op��es abaixo: ");
                printf("\n (1) Executar M�todo de Euler.");
                printf("\n (2) Executar M�todo de Taylor de segunda ordem.");
                printf("\n (3) Executar M�todo de Taylor de quarta ordem.");
                printf("\n (4) Executar M�todo de Euler modificado.");
                printf("\n (5) Executar M�todo do Ponto M�dio.");
                printf("\n (6) M�todo de Euler matricial para P�ndulo Simples.");
                printf("\n (7) Fechar programa.");

                printf("\n\n Digite a op��o que deseja: ");
                scanf("%d",&opcao);

    stop = 0;

   while(stop==0){
        switch(opcao){
            case 1://M�todo de Euler
                    printf("\n Digite a menor extremidade do intervalo: ");
                    scanf("%f",&a);

                    printf("\n Digite a maior extremidade do intervalo: ");
                    scanf("%f",&b);

                    printf("\n Digite a quantidade de partes que deseja dividir o intervalo: ");
                    scanf("%f",&c);

                    printf("\n Digite a condi��o inicial: ");
                    scanf("%f",&d);

                    A = metodo_de_Euler(a,b,c,d);
                    printf("\n M�todo de Euler:");
                    imprimir_solucao(A);

                    {
                    fp = fopen("M�todo de Euler - Dados.txt","w");   		// Arquivo ASCII, para escrita
                    if(!fp){
                        printf( "Erro na abertura do arquivo");
                        exit(0);
                    }
                    fprintf(fp,"Ti\tY(Ti)\tWi\t|Y(Ti) - Wi| (erro)\n");
                    for(i=0;i<A.tamanho;i++){
                        fprintf(fp,"%.4f\t%.4f\t%.4f\t%.4f\n",A.t[i],solucao_exata(A.t[i]),A.w[i],erro_y(solucao_exata(A.t[i]),A.w[i]));
                    }
                    fprintf(fp,"h = %.4f", A.passo);
                    fclose(fp);
                    }

                    setbuf(stdout, 0);
                    opcao = menu_opcoes();
                    break;
            case 2://M�todo de Taylor de segunda ordem
                    printf("\n Digite a menor extremidade do intervalo: ");
                    scanf("%f",&a);

                    printf("\n Digite a maior extremidade do intervalo: ");
                    scanf("%f",&b);

                    printf("\n Digite a quantidade de partes que deseja dividir o intervalo: ");
                    scanf("%f",&c);

                    printf("\n Digite a condi��o inicial: ");
                    scanf("%f",&d);

                    A = metodo_de_Taylor_2a_ordem(a,b,c,d);
                    printf("\n M�todo de Taylor de segunda ordem:");
                    imprimir_solucao(A);

                    {
                    fp = fopen("M�todo de Taylor de segunda ordem - Dados.txt","w");   		// Arquivo ASCII, para escrita
                    if(!fp){
                        printf( "Erro na abertura do arquivo");
                        exit(0);
                    }
                    fprintf(fp,"Ti\tY(Ti)\tWi\t|Y(Ti) - Wi| (erro)\n");
                    for(i=0;i<A.tamanho;i++){
                        fprintf(fp,"%.4f\t%.4f\t%.4f\t%.4f\n",A.t[i],solucao_exata(A.t[i]),A.w[i],erro_y(solucao_exata(A.t[i]),A.w[i]));
                    }
                    fprintf(fp,"h = %.4f", A.passo);
                    fclose(fp);
                    }

                    setbuf(stdout, 0);
                    opcao = menu_opcoes();
                    break;
            case 3://M�todo de Taylor de quarta ordem
                    printf("\n Digite a menor extremidade do intervalo: ");
                    scanf("%f",&a);

                    printf("\n Digite a maior extremidade do intervalo: ");
                    scanf("%f",&b);

                    printf("\n Digite a quantidade de partes que deseja dividir o intervalo: ");
                    scanf("%f",&c);

                    printf("\n Digite a condi��o inicial: ");
                    scanf("%f",&d);

                    A = metodo_de_Taylor_4a_ordem(a,b,c,d);
                    printf("\n M�todo de Taylor de quarta ordem:");
                    imprimir_solucao(A);

                    {
                    fp = fopen("M�todo de Taylor de quarta ordem - Dados.txt","w");   		// Arquivo ASCII, para escrita
                    if(!fp){
                        printf( "Erro na abertura do arquivo");
                        exit(0);
                    }
                    fprintf(fp,"Ti\tY(Ti)\tWi\t|Y(Ti) - Wi| (erro)\n");
                    for(i=0;i<A.tamanho;i++){
                        fprintf(fp,"%.4f\t%.4f\t%.4f\t%.4f\n",A.t[i],solucao_exata(A.t[i]),A.w[i],erro_y(solucao_exata(A.t[i]),A.w[i]));
                    }
                    fprintf(fp,"h = %.4f", A.passo);
                    fclose(fp);
                    }

                    setbuf(stdout, 0);
                    opcao = menu_opcoes();
                    break;
            case 4://M�todo de Euler modificado
                    printf("\n Digite a menor extremidade do intervalo: ");
                    scanf("%f",&a);

                    printf("\n Digite a maior extremidade do intervalo: ");
                    scanf("%f",&b);

                    printf("\n Digite a quantidade de partes que deseja dividir o intervalo: ");
                    scanf("%f",&c);

                    printf("\n Digite a condi��o inicial: ");
                    scanf("%f",&d);

                    A = metodo_de_Euler_modificado(a,b,c,d);
                    printf("\n M�todo de Euler Modificado:");
                    imprimir_solucao(A);

                    {
                    fp = fopen("M�todo de Euler Modificado - Dados.txt","w");   		// Arquivo ASCII, para escrita
                    if(!fp){
                        printf( "Erro na abertura do arquivo");
                        exit(0);
                    }
                    fprintf(fp,"Ti\tY(Ti)\tWi\t|Y(Ti) - Wi| (erro)\n");
                    for(i=0;i<A.tamanho;i++){
                        fprintf(fp,"%.4f\t%.4f\t%.4f\t%.4f\n",A.t[i],solucao_exata(A.t[i]),A.w[i],erro_y(solucao_exata(A.t[i]),A.w[i]));
                    }
                    fprintf(fp,"h = %.4f", A.passo);
                    fclose(fp);
                    }

                    setbuf(stdout, 0);
                    opcao = menu_opcoes();
                    break;
            case 5://M�todo do Ponto M�dio
                    printf("\n Digite a menor extremidade do intervalo: ");
                    scanf("%f",&a);

                    printf("\n Digite a maior extremidade do intervalo: ");
                    scanf("%f",&b);

                    printf("\n Digite a quantidade de partes que deseja dividir o intervalo: ");
                    scanf("%f",&c);

                    printf("\n Digite a condi��o inicial: ");
                    scanf("%f",&d);

                    A = metodo_do_Ponto_Medio(a,b,c,d);
                    printf("\n M�todo do Ponto M�dio:");
                    imprimir_solucao(A);

                    {
                    fp = fopen("M�todo do Ponto M�dio - Dados.txt","w");   		// Arquivo ASCII, para escrita
                    if(!fp){
                        printf( "Erro na abertura do arquivo");
                        exit(0);
                    }
                    fprintf(fp,"Ti\tY(Ti)\tWi\t|Y(Ti) - Wi| (erro)\n");
                    for(i=0;i<A.tamanho;i++){
                        fprintf(fp,"%.4f\t%.4f\t%.4f\t%.4f\n",A.t[i],solucao_exata(A.t[i]),A.w[i],erro_y(solucao_exata(A.t[i]),A.w[i]));
                    }
                    fprintf(fp,"h = %.4f", A.passo);
                    fclose(fp);
                    }

                    setbuf(stdout, 0);
                    opcao = menu_opcoes();
                    break;


            case 6: //M�todo de Euler matricial para P�ndulo Simples
                    printf("\n Digite a menor extremidade do intervalo: ");
                    scanf("%f",&a);

                    printf("\n Digite a maior extremidade do intervalo: ");
                    scanf("%f",&b);

                    printf("\n Digite a quantidade de partes que deseja dividir o intervalo: ");
                    scanf("%f",&c);

                    printf("\n Digite o comprimento do fio: ");
                    scanf("%f",&L);

                    printf("\n Digite a condi��o inicial para X: ");
                    scanf("%f",&d);

                    printf("\n Digite a condi��o inicial para Y: ");
                    scanf("%f",&f);

                    W = metodo_de_Euler_matricial(a,b,c,L,d,f);

                    if(c<10){
                    printf("\n M�todo de Euler matricial para P�ndulo Simples:");
                    imprimir_solucao_matricial(W);
                    }

                    {
                    fp = fopen("M�todo de Euler matricial para P�ndulo Simples - Dados.txt","w");   		// Arquivo ASCII, para escrita
                    if(!fp){
                        printf( "Erro na abertura do arquivo");
                        exit(0);
                    }
                    fprintf(fp,"Ti\tX(Ti)\tY(Ti)\n");
                    for(i=0;i<W.tamanho;i++){
                        fprintf(fp,"%.4f\t%.4f\t%.4f\n",W.t[i],W.sol.entrada[0][i],W.sol.entrada[1][i]);
                    }
                    fprintf(fp,"h = %.4f\n", W.passo);
                    fprintf(fp,"Dados:\nIntervalo: %.2f a %.2f\tN=%.2f\tComprimento do fio: %.2f\tX(%.2f)=%.4f\tY(%.2f)=%.4f", a,b,c,L,a,d,a,f);
                    fclose(fp);
                    printf("\n Arquivo com dados gravado com sucesso!");
                    }
                    setbuf(stdout, 0);
                    opcao = menu_opcoes();
                    break;
            case 7: //Fechar o programa
                stop=1;
                printf(" ");
                system("pause");
                setbuf(stdout, 0);
            break;

            default: //Op��o inv�lida
                printf(" \n Digite uma op��o v�lida para prosseguir!");
                opcao = menu_opcoes();
        }
   }
}
