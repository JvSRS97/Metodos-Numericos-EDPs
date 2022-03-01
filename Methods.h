//Autor: Joao Victor Silva Reis dos Santos
//Universidade Federal de Sergipe
//Aracaju - SE
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define pi 3.14159265359
#define e 2.7182818285

/*
Exerc�cios 5.2
1.	a) f(t,y) = t*pow(e,3*t) - 2*y, 0<=t<=1, y(0) = 0, com h=0,5 (h=0,5 => N = 2)
        Solu��o exata: y(t) = (pow(e,-1*2*t)*(pow(e,5*t)*(5*t-1)+1))/25
	b) f(t,y) = 1 + pow(t-y,2), 2<=t<=3, y(2) = 1, com h=0,5 (h=0,5 => N = 2)
        Solu��o exata: y(t) = (pow(t,2)-t-1)/(t-1)
    d) cos(2*t)+sin(3*t), 0<=t<=1, y(0)=1, com h=0,25 (h=0,25 => N = 4)
	Solu��o exata: y(t) = (3*sin(2*t)-2*cos(3*t)+8)/6

2.	a) f(t,y) = pow(e,t-y), 0<=t<=1, y(0) = 1, com h=0,5 (h=0,5 => N = 2)
        Solu��o exata: y(t) = log(pow(e,t)-1+e)
	b) f(t,y) = (1+t)/(1+y), 1<=t<=2, y(1) = 2, com h=0,5 (h=0,5 => N = 2)
        Solu��o exata: y(t) = sqrt(pow(t,2)+2*t+6)-1

9.	f(t,y) = (2*y)/t + pow(t,2)*pow(e,t), 1<=t<=2, y(1)=0
	Solu��o exata: y(t) = pow(t,2)*(pow(e,t)-e)

	a) Usar o m�todo de Euler com h=0,1 (h=0,1 => N = 10) para uma aproxima��o da solu��o e
		compare-a com os valores reais de y.
	b) Use as respostas geradas na parte (a) e a interpola��o linear para encontrar a aproxima��o
		dos seguintes valores de y e compare-os com os valores reais.
		i) y(1,04)	ii) y(1,55)	iii) y(1,97)
---------------------------------------------------------------------------------------------------------
Richard Burden Pg 307 (321 PDF)
Exerc�cios 5.3
(1 e 2 Taylor de segunda ordem)
1.	a) f(t,y) = t*pow(e,3*t) - 2*y, 0<=t<=1, y(0) = 0, com h=0,5 (h=0,5 => N = 2)
       		Solu��o exata: y(t) = (pow(e,-1*2*t)*(pow(e,5*t)*(5*t-1)+1))/25
       		Derivadas: primeira = pow(e,3*t)*(3*t+1) - 2*(t*pow(e,3*t) - 2*y)
                       segunda = 4*(t*pow(e,3*t) - 2*y) + pow(e,3*t)*(3*t+4)
                       terceira = pow(e,3*t)*(19 + 21*t)

    d) f(t,y) = cos(2*t)+sin(3*t), 0<=t<=1, y(0)=1, com h=0,25 (h=0,25 => N = 4)
            Solu��o exata: y(t) = (3*sin(2*t)-2*cos(3*t)+8)/6
       		Derivadas: primeira = 3*cos(3*t) - 2*sin(2*t)
                       segunda = -9*sin(3*t) - 4*cos(2*t)
                       terceira = 8*sin(2*t) - 27*cos(3*t)

2.	a) f(t,y) = pow(e,t-y), 0<=t<=1, y(0) = 1, com h=0,5 (h=0,5 => N = 2)
        	Solu��o exata: y(t) = log(pow(e,t)-1+e)
        		Derivadas:  primeira = -pow(e,t-y)*(pow(e,t-y)-1)
                            segunda = -pow(e,t-y)*(pow(e,y)-2*pow(e,t))*(pow(e,t-y)-1)
                            terceira = -pow(e,t-3*y)*pow(e,2*t)-6*pow(e,y+t)+6*(pow(e,2*t))*(pow(e,t-y)-1)

	b) f(t,y) = (1+t)/(1+y), 1<=t<=2, y(1) = 2, com h=0,5 (h=0,5 => N = 2)
        	Solu��o exata: y(t) = sqrt(pow(t,2)+2*t+6)-1
        		Derivadas:  primeira = ((1+y) - (t+1)*((1+t)/(1+y)))/(pow(1+y,2))
                            segunda = ((3*pow(t,2)+6*t+2)*((1+t)/(1+y))+pow(y,2)*(-((1+t)/(1+y)))-2*y*(((1+t)/(1+y))+(1+t)) - 2*(1+t))/(pow(1+y,4))
                            terceira = (3*(t+1)*(-5*pow(t,2)+3*pow(y,2)+6*y-10*t-2)*((1+t)/(1+y)))/(pow(y+1,6)) - (3*(-3*pow(t,2)+pow(y,2)+2*y-6*t-2))/(pow(y+1,5))

3. Repetir o Exerc�cio 1 usando o m�todo de Taylor de quarta ordem.

4. Repetir o Exerc�cio 2 usando o m�todo de Taylor de quarta ordem.

5. (Taylor de segunda ordem)
	a) f(t,y) = (y/t)-(y/pow(t,2)), 1<=t<=1.2, y(1) = 1, com h=0,1 (h=0,1 => N = 2)
        	Solu��o exata: y(t) = t/(log(t)+1)
        		Derivadas:  primeira = ((t-1)*t*((y/t)-(y/pow(t,2))) - (t-2)*y)/(pow(t,3))
                            segunda = (t*((y/t)-(y/pow(t,2))) - 4*y)/(pow(t,5))
                            terceira = (3*(5*t+2)*y - t*(3*t+1)*((y/t)-(y/pow(t,2))))/(pow(t,7))

	b) f(t,y) = sin(t)+pow(e,-1*t), 0<=t<=1, y(0) = 0, com h=0,5 (h=0,5 => N = 2)
        	Solu��o exata: y(t) = -pow(e,-1*t)-cos(t)+2
       		Derivadas: primeira = cos(t)-pow(e,t)
                       segunda = pow(e,-1*t)-sin(t)
                       terceira = -pow(e,-1*t)-cos(t)

9.	f(t,y) = (2*y)/t + pow(t,2)*pow(e,t), 1<=t<=2, y(1)=0
		Solu��o exata: y(t) = pow(t,2)*(pow(e,t)-e)
       		Derivadas: primeira = (pow(e,t)*(t+2)*pow(t,3)+2*t*((2*y)/t + pow(t,2)*pow(e,t)) - 2*y)/(pow(t,2))
                       segunda = (2*(t*((2*y)/t + pow(t,2)*pow(e,t)) - 2*y))/(pow(t,3)) + pow(e,t)*(t*(t+6)+4)
                       terceira = pow(e,t)*(pow(t,2)+8*t+12)

	a) Usar o m�todo de Taylor de segunda ordem com h=0,1 (h=0,1 => N = 10) para uma aproxima��o da solu��o e
		compare-a com os valores reais de y.
	b) Use as respostas geradas na parte (a) e a interpola��o linear para encontrar a aproxima��o
		dos seguintes valores de y e compare-os com os valores reais.
		i) y(1,04)	ii) y(1,55)	iii) y(1,97)
	c) Usar o m�todo de Taylor de quarta ordem com h=0,1 (h=0,1 => N = 10) para uma aproxima��o da solu��o e
		compare-a com os valores reais de y.
	d) Use as respostas geradas na parte (c) e a interpola��o linear para encontrar a aproxima��o
		dos seguintes valores de y e compare-os com os valores reais.
		i) y(1,04)	ii) y(1,55)	iii) y(1,97)
11. f(t,y) = 1+t*sin(t*y), 0<=t<=2, y(0)=0
		Solu��o exata: y(t) = ?
       		Derivadas: primeira = t*(t*(1+t*sin(t*y))+y)*cos(t*y)+sin(t*y)
---------------------------------------------------------------------------------------------------------
Richard Burden Pg 319 (333 PDF)
Exerc�cios 5.4
(1 a 4 M�todo de Euler modificado)
1.	a) f(t,y) = t*pow(e,3*t) - 2*y, 0<=t<=1, y(0) = 0, com h=0,5 (h=0,5 => N = 2)
       		Solu��o exata: y(t) = (pow(e,-1*2*t)*(pow(e,5*t)*(5*t-1)+1))/25

    d) f(t,y) = cos(2*t)+sin(3*t), 0<=t<=1, y(0)=1, com h=0,25 (h=0,25 => N = 4)
            Solu��o exata: y(t) = (3*sin(2*t)-2*cos(3*t)+8)/6

2.	a) f(t,y) = pow(e,t-y), 0<=t<=1, y(0) = 1, com h=0,5 (h=0,5 => N = 2)
        	Solu��o exata: y(t) = log(pow(e,t)-1+e)

	b) f(t,y) = (1+t)/(1+y), 1<=t<=2, y(1) = 2, com h=0,5 (h=0,5 => N = 2)
        	Solu��o exata: y(t) = sqrt(pow(t,2)+2*t+6)-1

3.	a) f(t,y) = (y/t)-pow(y/t,2), 1<=t<=2, y(1) = 1, com h=0,1 (h=0,1 => N = 10)
        	Solu��o exata: y(t) = t/(1+log(t))

	b) f(t,y) = 1+(y/t)+pow(y/t,2), 1<=t<=3, y(1) = 0, com h=0,2 (h=0,2 => N = 10)
        	Solu��o exata: y(t) = t*tan(log(t))

4.	a) f(t,y) = (2-2*t*y)/(pow(t,2)+1), 0<=t<=1, y(0) = 1, com h=0,1 (h=0,1 => N = 10)
        	Solu��o exata: y(t) = (2*t+1)/(pow(t,2)+1)

	c) f(t,y) = (pow(y,2)+y)/(t), 1<=t<=3, y(1) = -2, com h=0,2 (h=0,2 => N = 10)
        	Solu��o exata: y(t) = (2*t)/(1-2*t)

5. Repetir o exerc�cio 1 usando o m�todo do Ponto M�dio.
6. Repetir o exerc�cio 2 usando o m�todo do Ponto M�dio.
7. Repetir o exerc�cio 3 usando o m�todo do Ponto M�dio.
8. Repetir o exerc�cio 4 usando o m�todo do Ponto M�dio.
---------------------------------------------------------------------------------------------------------
*/
//f(t,y)
float f(float t, float y){//Fun��o f(t,y) = cos(2*t)+sin(3*t), 0<=t<=1, y(0)=1, com h=0,25 (h=0,25 => N = 4)
    float resultado = 0;
    resultado = cos(2*t)+sin(3*t);
return resultado;
}
//------------------
float f_t(float t, float y){//Primeira derivada da fun��o f
    float resultado = 0;
    resultado = 3*cos(3*t) - 2*sin(2*t);
return resultado;
}

float f_tt(float t, float y){//Segunda derivada da fun��o f
    float resultado = 0;
    resultado = -9*sin(3*t) - 4*cos(2*t);
return resultado;
}

float f_ttt(float t, float y){//Terceira derivada da fun��o f
    float resultado = 0;
    resultado = 8*sin(2*t) - 27*cos(3*t);
return resultado;
}
//------------------
float solucao_exata(float t){
    float resultado;
    resultado = (3*sin(2*t)-2*cos(3*t)+8)/6;
return resultado;
}
//------------------
float erro_y(float y_ti, float y_i){
    float resultado;
    resultado = fabs(y_ti - y_i);
return resultado;
}

//Taylor
//---------------
float T_2(float t, float w, float h){
    float resultado;
    resultado = f(t,w)+(h*f_t(t,w))/(2);

return resultado;
}

float T_4(float t, float w, float h){
    float resultado;
    resultado = f(t,w)+(h*f_t(t,w))/(2)+(pow(h,2)*f_tt(t,w))/(6)+(pow(h,3)*f_ttt(t,w))/(24);

return resultado;
}
//---------------

int menu_opcoes(){
    int opcao = 0;
                printf("\n\n ");
                system("pause");
                system("cls");
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

    return opcao;
}

typedef struct{//estrutura solu��o
    float t[150];
    float w[150];
    int tamanho;
    float passo;
}solucao;

void imprimir_solucao(solucao Solucao){
    int i;
    printf("\n\n Tamanho da solu��o: %d; Passo da solu��o: h=%.4f\n",Solucao.tamanho,Solucao.passo);
    for(i=0;i<Solucao.tamanho;i++){
        if(solucao_exata(Solucao.t[i]) == 0)
            printf(" i=0%d: T0%d = %.4f ==> W0%d = %.4f. | Valor exato: %.4f ==> Erro = %.4f.\n", i,i,Solucao.t[i],i,Solucao.w[i], solucao_exata(Solucao.t[i]), erro_y(solucao_exata(Solucao.t[i]),Solucao.w[i]));

        else{
            if(i<10)
                printf(" i=0%d: T0%d = %.4f ==> W0%d = %.4f. | Valor exato: %.4f ==> Erro = %.4f <=> %.2f %%.\n", i,i,Solucao.t[i],i,Solucao.w[i],solucao_exata(Solucao.t[i]), erro_y(solucao_exata(Solucao.t[i]),Solucao.w[i]),erro_y(solucao_exata(Solucao.t[i]),Solucao.w[i])/solucao_exata(Solucao.t[i])*100);
            else
                printf(" i=%d: T%d = %.4f ==> W%d = %.4f. | Valor exato: %.4f ==> Erro = %.4f <=> %.2f %%.\n", i,i,Solucao.t[i],i,Solucao.w[i],solucao_exata(Solucao.t[i]), erro_y(solucao_exata(Solucao.t[i]),Solucao.w[i]),erro_y(solucao_exata(Solucao.t[i]),Solucao.w[i])/solucao_exata(Solucao.t[i])*100);
        }
    }
}

solucao metodo_de_Euler(float intervalo_extremidade_a, float intervalo_extremidade_b, float N_partes, float condicao_inicial){
    solucao Solucao;
    Solucao.tamanho = N_partes+1;
    int i;
    float h;

    //---------------------
    //Passo 1
    //---------------------
    h = (intervalo_extremidade_b - intervalo_extremidade_a)/N_partes;
    Solucao.passo = h;
    Solucao.t[0] = intervalo_extremidade_a;
    Solucao.w[0] = condicao_inicial;

    //---------------------
    //Passo 2
    //---------------------
    for(i=1;i<=N_partes;i++){
        //Passo 3
            Solucao.w[i] = Solucao.w[i-1] + h*f(Solucao.t[i-1],Solucao.w[i-1]);
        //Passo 4
            Solucao.t[i] = Solucao.t[i-1] + h;
    }

return Solucao;
}


solucao metodo_de_Taylor_2a_ordem(float intervalo_extremidade_a, float intervalo_extremidade_b, float N_partes, float condicao_inicial){
    solucao Solucao;
    Solucao.tamanho = N_partes+1;
    int i;
    float h;

    //---------------------
    //Passo 1
    //---------------------
    h = (intervalo_extremidade_b - intervalo_extremidade_a)/N_partes;
    Solucao.passo = h;
    Solucao.t[0] = intervalo_extremidade_a;
    Solucao.w[0] = condicao_inicial;

    //---------------------
    //Passo 2
    //---------------------
    for(i=1;i<=N_partes;i++){
        //Passo 3
            Solucao.w[i] = Solucao.w[i-1] + h*T_2(Solucao.t[i-1],Solucao.w[i-1],h);
        //Passo 4
            Solucao.t[i] = Solucao.t[i-1] + h;
    }

return Solucao;
}


solucao metodo_de_Taylor_4a_ordem(float intervalo_extremidade_a, float intervalo_extremidade_b, float N_partes, float condicao_inicial){
    solucao Solucao;
    Solucao.tamanho = N_partes+1;
    int i;
    float h;

    //---------------------
    //Passo 1
    //---------------------
    h = (intervalo_extremidade_b - intervalo_extremidade_a)/N_partes;
    Solucao.passo = h;
    Solucao.t[0] = intervalo_extremidade_a;
    Solucao.w[0] = condicao_inicial;

    //---------------------
    //Passo 2
    //---------------------
    for(i=1;i<=N_partes;i++){
        //Passo 3
            Solucao.w[i] = Solucao.w[i-1] + h*T_4(Solucao.t[i-1],Solucao.w[i-1],h);
        //Passo 4
            Solucao.t[i] = Solucao.t[i-1] + h;
    }

return Solucao;
}

solucao metodo_de_Euler_modificado(float intervalo_extremidade_a, float intervalo_extremidade_b, float N_partes, float condicao_inicial){
    solucao Solucao;
    Solucao.tamanho = N_partes+1;
    int i;
    float h, aux;

    //---------------------
    //Passo 1
    //---------------------
    h = (intervalo_extremidade_b - intervalo_extremidade_a)/N_partes;
    Solucao.passo = h;
    Solucao.t[0] = intervalo_extremidade_a;
    Solucao.w[0] = condicao_inicial;

    //---------------------
    //Passo 2
    //---------------------
    for(i=1;i<=N_partes;i++){
        //Passo 3
            aux = f(Solucao.t[i-1],Solucao.w[i-1]);
            Solucao.w[i] = Solucao.w[i-1] + (h*(aux+f(Solucao.t[i-1]+h,Solucao.w[i-1]+h*aux)))/(2);
        //Passo 4
            Solucao.t[i] = Solucao.t[i-1] + h;
    }

return Solucao;
}


solucao metodo_do_Ponto_Medio(float intervalo_extremidade_a, float intervalo_extremidade_b, float N_partes, float condicao_inicial){
    solucao Solucao;
    Solucao.tamanho = N_partes+1;
    int i;
    float h, aux;

    //---------------------
    //Passo 1
    //---------------------
    h = (intervalo_extremidade_b - intervalo_extremidade_a)/N_partes;
    Solucao.passo = h;
    Solucao.t[0] = intervalo_extremidade_a;
    Solucao.w[0] = condicao_inicial;

    //---------------------
    //Passo 2
    //---------------------
    for(i=1;i<=N_partes;i++){
        //Passo 3
            aux = f(Solucao.t[i-1],Solucao.w[i-1]);
            Solucao.w[i] = Solucao.w[i-1] + h*f(Solucao.t[i-1]+(h/2),Solucao.w[i-1]+(h*aux)/(2));
        //Passo 4
            Solucao.t[i] = Solucao.t[i-1] + h;
    }

return Solucao;
}

float interpolacao(float x,float x_0, float y_0, float x_1, float y_1){
    float resultado;
    resultado = y_0 + ((y_1-y_0)/(x_1-x_0))*(x-x_0);
return resultado;
}

//---------------------------------------------------------------------------------------------------------------
typedef struct {//estrutura de matriz nxm com entradas reais
  float entrada[251][251];
  int n, m; //n = numero de linhas e m = numero de colunas
  } matriz;

//Fun��o para zerar uma matriz (� preciso definir a ordem da matriz antes de chamar esta fun��o)
//---------------------------------------------------------------------------
 matriz zerar_matriz(matriz A){
	int i,j;
	for(i=0;i<A.n;i++)
		for(j=0;j<A.m;j++)
			A.entrada[i][j]=0;
	return A;
}

//-----------------------------------------------------------------------------------------------

typedef struct{//estrutura solu��o matricial
    matriz sol;
    float t[251];//valor de t
    int tamanho;
    float passo;
}solucao_matricial;


solucao_matricial metodo_de_Euler_matricial(float intervalo_extremidade_a, float intervalo_extremidade_b, float N_partes, float L,float condicao_inicial_x, float condicao_inicial_y){
    solucao_matricial W;
    W.sol.n = 2;
    W.sol.m = 250;
    W.tamanho = N_partes+1;

    int j;
    float h;
    float g;
    g = 9.81;
    W.sol = zerar_matriz(W.sol);


    //---------------------
    //Passo 1
    //---------------------
    h = (intervalo_extremidade_b - intervalo_extremidade_a)/N_partes;
    W.passo = h;

    W.sol.entrada[0][0] = condicao_inicial_x;
    W.sol.entrada[1][0] = condicao_inicial_y;

    W.t[0] = intervalo_extremidade_a;
// x(t0) = condicao_inicial_x, y(t0) = condicao_inicial_y

    //---------------------
    //Passo 2
    //---------------------

        for(j=1;j<=N_partes;j++){
            //passo 3
            W.sol.entrada[0][j] = W.sol.entrada[0][j-1]+h*W.sol.entrada[1][j-1]; //primeira linha da coluna atual (Xi)
            W.sol.entrada[1][j] = W.sol.entrada[1][j-1] - ((g*(h/(L))*sin(W.sol.entrada[0][j-1])));   //segunda linha da coluna atual (Yi)

            //passo 4
            W.t[j] = W.t[j-1]+h;
        }

return W;
}

void imprimir_solucao_matricial(solucao_matricial Solucao){
    int i;
    printf("\n\n Tamanho da solu��o: %d; Passo da solu��o: h=%.4f\n",Solucao.tamanho,Solucao.passo);
    for(i=0;i<Solucao.tamanho;i++){
            if(i<10)
                printf(" i=0%d: T0%d = %.4f ==> X0%d = %.4f e Y0%d = %.4f.\n", i,i,Solucao.t[i],i,Solucao.sol.entrada[0][i],i,Solucao.sol.entrada[1][i]);
            else
                printf(" i=%d: T%d = %.4f ==> X%d = %.4f e Y%d = %.4f.\n", i,i,Solucao.t[i],i,Solucao.sol.entrada[0][i],i,Solucao.sol.entrada[1][i]);
        }
    }
