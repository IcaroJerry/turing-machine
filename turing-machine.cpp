#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#define PRETO 0
#define AZUL 1
#define VERDE 2
#define VERDEA 3
#define VERMELHO 4
#define ROXO 5
#define AMARELO 6
#define BRANCO 7
#define NEGRITO 8
#define AZULC 9
#define VERDEC 10//A
#define AZULCC 11//B
#define VERMELHOC 12//C
#define LILAS 13//D
#define AMARELOC 14//E
#define BRANCOB 15//F
#define TM 49 // TOTAL DE TRANSIÇÕES


int inc,h,direcao;
int i=0,j=0,cursor=0,finalizador=0,linha=0;
int k=1; // posição na fita
int fita1=0,parada=0,sinal=0;
int cont1=0,cont2=0,cont3=0,insert=0;
char cabecote[30],estado1[10],escrito1,novoestado[10],estadoatual[10],fita[30]={'>'};
char esc1,opc1,opcao1;
char nome[10];//nome do arquivo


void inserirdados(void); //FUNCAO MOTORA
void insriralfabetofita(void); //FUNCAO MOTORA
void estadoeposicaoinicial(void); //FUNCAO MOTORA
void maquinadeturing(void); //FUNCAO MOTORA
void menu(void); //FUNCAO MOTORA

void menu_2(void); //APRESENTAÇÃO
void menu_1(void); //APRESENTAÇÃO

void logo_ifba(void); //APRESENTAÇÃO
void animacao_titulo(void); //APRESENTAÇÃO
void apresentacao_apple(void); //APRESENTAÇÃO
void tutorial(void); //APRESENTAÇÃO

void arquivo(void); ////FUNCAO MOTORA
void abre_arquivo(void); //FUNCAO MOTORA


typedef struct{
               char estado[10];
               char lido;
               char escrito;
               char direcao;
               char novo_estado[10];
               }ftransicao[50];

ftransicao programa;



void maquina_menu() // MENU DA MAQUINA DE TURING
{


      system("cls");// LIMPAR E ABRIR O MENU DA MAQUINA
      system("color 3f");// FUNDO AZUL

      HANDLE hConsole;
      hConsole = GetStdHandle (STD_OUTPUT_HANDLE);


     menu_2(); // IMPRIME MENU SECUNDARIO

     scanf("%c", &esc1);
     fflush(stdin);
//------------------------------------------FIM MENU--DA--MAQUINA--------------------------------------

     switch (esc1){
                     case '1':{
                            cont1++; // MARCA QUANTAS VEZES ESSA OPCAO FOI ABERTA

                            if (cont1!=1) // CASO JA TENHA ABERTO ANTES - VERIFICA SE DEVE SER ABERTO NOVAMENTE
                            {linha=0;
                            printf("\n\t# Os Dados j\xA0 foram inseridos!\n\tDeseja inser\xA1-los novamente?\n\n\t1-SIM\n\t2-N\xC7O\n\n");
                            printf("> Op\x87\xC6o: ");
                            scanf("%c",&opc1);
                            fflush(stdin);

                            while((opc1!='1')&&(opc1!='2'))  // VERIFICA SE OPCAO ESTA CERTA
                              {
                                        printf("\r\t# Op\x87\xC6o inv\xA0lida! Digite novamente.\n");
                                        printf("> Op\x87\xC6o: ");
                                        scanf("%c",&opc1);
                                        fflush(stdin);
                               }
                                                        if(opc1=='1')
                                                        {
                                                        linha=0;
                                                        inserirdados();

                                                        }

                                                        if(opc1=='2')
                                                        {
                                                        cont1--; // CASO NAO SEJA ABERTO NOVAMENTE VOLTA O VALOR ANTERIOR
                                                        maquina_menu();

                                                        }
                            }

                            else // ABRE SE FOR A PRIMEIRA VEZ
                            {

                            inserirdados();
                            break;
                            }

                            }

                     case '2':{
                            cont2++; // MARCA QUANTAS VEZES ESSA OPCAO FOI ABERTA

                            if (cont2!=1) // CASO JA TENHA ABERTO ANTES - VERIFICA SE DEVE SER ABERTO NOVAMENTE
                            {
                                         printf("\n\t# O Alfabeto j\xA0 foi inserido!\n\tDeseja inser\xA1-lo novamente?\n\n\t");
                                         printf("1-SIM\n\t2-N\xC7O\n\n");
                                         printf("> Op\x87\xC6o: ");
                                         scanf("%c",&opc1);
                                         fflush(stdin);

                             while((opc1!='1')&&(opc1!='2'))
                              {
                                        printf("\r\t# Op\x87\xC6o inv\xA0lida! Digite novamente.\n");
                                        printf("> Op\x87\xC6o: ");
                                        scanf("%c",&opc1);
                                        fflush(stdin);
                               } // VERIFICA SE OPCAO ESTA CERTA

                                                        if(opc1=='1')
                                                        {
                                                        insriralfabetofita();

                                                        }

                                                        if(opc1=='2')
                                                        {
                                                        cont2--;     // CASO NAO SEJA ABERTO NOVAMENTE VOLTA O VALOR ANTERIOR
                                                        maquina_menu();

                                                        }
                            }

                            else // ABRE PELA PRIMEIRA VEZ
                            {

                            insriralfabetofita();
                            break;}

                            }



                     case '3':{

                     if (cont2<1)
                     {printf("\n\t# O Alfabeto da fita ainda n\xC6o foi inserido!\n\t  Por favor digite-os primeiro.\n\n\t");
                      system ("pause");
                      return maquina_menu();}

                     else
                     {
                             cont3++; // MARCA QUANTAS VEZES ESSA OPCAO FOI ABERTA

                             if (cont3!=1) // CASO JA TENHA ABERTO ANTES - VERIFICA SE DEVE SER ABERTO NOVAMENTE
                            {
                                         printf("\n\t# Os dados j\xA0 foram inseridos!\n\tDeseja inser\xA1-los novamente?\n\n\t");
                                         printf("1-SIM\n\t2-N\xC7O\n\n");
                                         printf("> Op\x87\xC6o: ");
                                         scanf("%c",&opc1);
                                         fflush(stdin);

                              while((opc1!='1')&&(opc1!='2'))  // VERIFICA SE OPCAO ESTA CERTA
                              {
                                        printf("\r\t# Op\x87\xC6o inv\xA0lida! Digite novamente.\n");
                                        printf("> Op\x87\xC6o: ");
                                        scanf("%c",&opc1);
                                        fflush(stdin);
                               }

                                                        if(opc1=='1')
                                                        {
                                                        estadoeposicaoinicial();
                                                        break;
                                                        }
                                                        if(opc1=='2')
                                                        {
                                                        cont3--;  // CASO NAO SEJA ABERTO NOVAMENTE VOLTA O VALOR ANTERIOR
                                                        maquina_menu();
                                                        break;
                                                        }
                            }

                            else // ABRE PELA PRIMEIRA VEZ
                             {
                             estadoeposicaoinicial(); // ABRE PELA PRIMEIRA VEZ
                             break;}

                            }
                            }

                     case '4':{
                     //-------------------VERIFICADOR DOS MENUS PREENCHIDOS E MOSTRA QUAIS FALTAM ----------
                            if ((cont1==0)&&(cont2>=1)&&(cont3>=1))
                            {printf("\n\t#Falta inserir os Dados!\n\tPor favor preencha-os primeiro antes de Executar!\n\n\t");
                            system ("pause");
                            return maquina_menu();}

                            if ((cont1>=1)&&(cont2==0)&&(cont3>=1))
                            {printf("\n\t#Falta inserir o Alfabeto!\n\tPor favor preencha-os primeiro antes de Executar!\n\n\t");
                            system ("pause");
                            return maquina_menu();}

                            if ((cont1>=1)&&(cont2>=1)&&(cont3==0))
                            {printf("\n\t#Falta inserir os Estados!\n\tPor favor preencha-os primeiro antes de Executar!\n\n\t");
                            system ("pause");
                            return maquina_menu();}

                            if ((cont1>=1)&&(cont2==0)&&(cont3==0))
                            {printf("\n\t#Falta inserir os Estados e o Alfabeto da fita!\n\t");
                            printf("Por favor preencha-os primeiro antes de Executar!\n\n\t");
                            system ("pause");
                            return maquina_menu();}

                            if ((cont1==0)&&(cont2>=1)&&(cont3==0))
                            {printf("\n\t#Falta inserir os Dados e os Estados da fita!\n\t");
                            printf("Por favor preencha-os primeiro antes de Executar!\n\n\t");
                            system ("pause");
                            return maquina_menu();}


                            if ((cont1==0)&&(cont2==0)&&(cont3>=1))
                            {printf("\n\t#Falta inserir os Dados e o alfabeto da fita!\n\t");
                            printf("Por favor preencha-os primeiro antes de Executar!\n\n\t");
                            system ("pause");
                            return maquina_menu();}


                            if ((cont1==0)&&(cont2==0)&&(cont3==0))
                            {printf("\n\t#Falta inserir os itens necess\xA0rios para EXECUTAR");
                            printf(" a m\xA0quina!\n\n\tPorfavor preencha-os primeiro antes de Executar!\n\n\n\t");
                            system ("pause");
                            return maquina_menu();}
                            //------------FIM VERIFICADOR-------------------------------------


                            //--------SÓ PERMITE O USUARIO EXECUTAR A MAQUINA SE ANTES TIVER FEITO TODAS OUTROS PASSOS -----
                            if ((cont1>=1)&&(cont2>=1)&&(cont3>=1))
                            {maquinadeturing();}

                     case '5': return menu();

                     case '6': {
                          // ZERA OS DADOS BASICOS DA MAQUINA, FORÇANDO O USUARIO PREENCHE-LOS NOVAMENTE
                          printf("\n\n\n*****TEM CERTEZA QUE DESEJA ZERAR OS DADOS DA FITA?!******\n\n");
                          printf("\t# Digite 1 para SIM ou qualquer outro numero para N\xC7O:  ");
                          scanf("%c",&opcao1); //  VERIFICA SE DEVE EXECUTAR A AÇÃO
                          fflush(stdin);

                          if(opcao1=='1')
                          {
                          insert=0;

                          cont1=0;
                          cont2=0;
                          cont3=0;

                          i=0;
                          j=0;
                          cursor=0;
                          finalizador=0;
                          linha=0;
                          k=1;
						  fita1=0;

                          printf("\n\n\t CARREGANDO...");
                          Sleep(1000);
                          maquina_menu();
                          break;
                          }

                          if(opcao1!='1') // VOLTA AO MENU SEM ZERAR OS CONTADORES
                          {
                          maquina_menu();
                          break;
                          }

                           }

                     default: { printf("\t\t\t*** Op\x87\xC6o Inv\xA0lida ***");
                               Sleep(1500);//APAGAR A FRASE AUTOMATICAMENTE
                               maquina_menu();
                              }
                     }
}
}


void inserirdados()//inserir daddos na MT.
{

    for(i=0;i<=TM;i++){
                        // -------------- ENTRA NO MENU DE INSERÇÃO DE DADOS --------
             if(i<TM)
             {
                        system("cls");

                        printf("\n\n******************INSERIR DADOS*********************************\n");
						
						printf("--------------------------------------TRANSI\x80\xC7O %d --\n\n",i+1);

                        printf("\n---->> ATEN\x80\xC7O: Os espa\x87os s\xC6o usados para diferenciar os estados !!!\n");
                        printf("---->> Os S\xA1mbolos lidos e escritos devem conter apenas um caracter!!!\n");
                        printf("------>> MAX DE TRANSI\x80\xC7O  -  50!!!\n");
                        printf("\n\n\tDigite os seguintes dados:\n");


                        printf("\n\tEstado: ");
                        scanf ("%s",programa[i].estado);
                        fflush(stdin);

                        linha++;

                        printf("\n\tS\xA1mbolo lido: "); scanf ("%s",&programa[i].lido);
                        fflush(stdin);

                        printf("\n\tS\xA1mbolo escrito: "); scanf("%s",&programa[i].escrito);
                        fflush(stdin);

                        printf("\n\tDire\x87\xC6o [0- NULO | 1 - Direita | 2 - Esquerda]: ");
                        scanf("%c",&programa[i].direcao);
                        fflush(stdin);
                        // IMPEDE ENTRAR UM VALOR DIFERENTE DAS OPCOES DEFINIDAS
                        while((programa[i].direcao!='1')&&(programa[i].direcao!='0')&&(programa[i].direcao!='2'))
                        {
                          printf("\tOpcao inv\xA0lida! <aguarde>");
                          Sleep(1500);
                          printf("\r\t#  Dire\x87\xC6o [0- NULO | 1 - Direita | 2 - Esquerda]: ");
                          scanf("%s",&programa[i].direcao);
                          fflush(stdin);
                                         }
                        printf("\n\tNovo estado: "); scanf("%s",programa[i].novo_estado);
                        fflush(stdin);
			 		    linha++;

                     	printf("\n\n\t\t*** DIGITE:\n\n\t\t1- Finalizar.\n\t\t> Qualquer n\xA3mero para continuar...");
                        printf("\n\n\t\t# Op\x87\xC6o: ");
						scanf("%d",&finalizador);
						fflush(stdin);
                        if(finalizador==1)
                           {
                                        finalizador=0;
                                        arquivo();
                                        maquina_menu();
                                           }


                      }
           
           else
           {system("cls");
                    system("color 0C");
                    printf("\a");               
                                   printf("\n\n\n\n\n\n\n\n\n\t\t***************************   EXCEDEU LIMITE ! ! ! ");
                                   printf("  ****************************** ");
                   for(i=0;i<7;i++)
                   {
                      if((i%2)==0)
                      {system("color 0C");   Sleep(100);
                                             
                      }
                      else
                       {   system("color FC");  Sleep(100);
                       printf("\a");    
                       }
                   }
                 Sleep(600);  
                 maquina_menu();             
                }
               }
}



void insriralfabetofita()
{
           // -------- ENTRA NO MENU DE INSERÇÃO DO ALFABETO DA FITA ---


                        system("cls");
                        printf("\n\n*****************ALFABETO DA FITA*********************************\n");

                        printf("\n\t>> ATEN\x80\xC7O: Digite apenas um caracter por vez para declarar o alfabeto da fita!!!\n\n");
                        printf("------>> MAX DE  SIMBOLO -  30!!!\n");
                        k=1;

         printf("\n\n\t# Digite o  alfabeto da fita, finalizando com o s\xA1mbolo '<'.\n\n");

         finalizador=0;
         
         
         do{ //laço para armazenar o alfabeto da fita
	     printf("\n  > Elemento %d da fita: ",k);
	     scanf("%s",&fita[k]);
	     fflush(stdin);

		 k++;
	     
         if(k>=30)
           {system("cls");
                    system("color 0C");
                    printf("\a");               
                                   printf("\n\n\n\n\n\n\n\n\n\t\t***************************   EXCEDEU LIMITE ! ! ! ");
                                   printf("  ****************************** ");
                   for(i=0;i<7;i++)
                   {
                      if((i%2)==0)
                      {system("color 0C");   Sleep(100);
                                             
                      }
                      else
                       {   system("color FC");  Sleep(100);
                       printf("\a");    
                       }
                   }
                 Sleep(600);  
                 maquina_menu();             
                }
         
         }while(fita[k-1]!='<');
	     fita1=k;//armazena a posição do vetor onde se encontra o símbolo de parada
         k=0;
         maquina_menu();
         
         
}


void estadoeposicaoinicial()
{

     // ---------------- APRESENTA OS DADOS PRESENTE NA FITA ----- INSERE A POSIÇÃO INICIAL

    printf("\n\n*************VIZUALIZE SUA M\xB5QUINA*********************************\n\n\n");
    printf("     # Os dados inseridos s\xC6o:\n\n");

    if(cont1==0) // APRESENTA A MENSAGEM CASO NAO HAJA DADOS INSERIDOS AINDA
    {
    printf("\t > > > DADOS N\xC7O FORAM INSERIDOS --\n\n\n");
    }

    else // APRESENTA OS DADOS PRESENTE NA FITA
    {
    printf("\t___________________________________________________ \n");

    for(i=0;i<=(linha-1)/2;i++){ // imprime a matriz para facilitar a inserção do estado inicial com base nos estados inseridos


               if(programa[i].direcao=='1') // IMPRIME O NOME DA DIRECAO REFERENTE AO NOME
               {
               printf("\t|  %s\t\t %c    %c  DIRT\t %s\t\t   |\n",programa[i].estado,programa[i].lido,programa[i].escrito,programa[i].novo_estado);
               }

               if(programa[i].direcao=='0')
               {
               printf("\t|  %s\t\t %c    %c  NULO\t %s\t\t   |\n",programa[i].estado,programa[i].lido,programa[i].escrito,programa[i].novo_estado);
               }

               if(programa[i].direcao=='2')
               {
               printf("\t|  %s\t\t %c    %c  ESQR\t %s\t\t   |\n",programa[i].estado,programa[i].lido,programa[i].escrito,programa[i].novo_estado);
               }


                                               printf("\t|                                                  |\n");

                                              }

	                       printf("\t|__________________________________________________|\n\n");
              }

    if(cont2>0) // APRESENTA OS DADOS DA FITA CASO ELA ESTA PREENCHIDA
    {

    printf("\t[ ");

    for(i=0;i<=fita1;i++){  // imprime a fita para que o usuário possa vizualizar as posições e determinar a posição inicial
						    printf("%c ",fita[i]);
	                     }
    printf("]  <-- FITA--\n\n");
    }

    else // CASO ESTEJA VAZIA APRESENTA A MENSAGEM
    {printf("\n\n\t[ F I T A   V A Z I A ]");}

    printf("\n\n\tDigite:\n\n\t  O estado inicial: ");
    scanf("%s",&estadoatual); // o usuário digita o estado inicial e a posição do cabeçote na fita
    fflush(stdin);
    printf("\n\t  A posi\x87\xC6o do cabecote da fita na M\xA0quina de Turing: ");
    scanf("%d",&k);
    fflush(stdin);

    maquina_menu();

}

void maquinadeturing()
{
    system("cls");
    printf("\n\n--------------------------------------------------------------\n*************** EXECUTA A M\xB5QUINA DE TURING");
    printf(" ******\n\n\n\t");
    printf("# 1- EXECUTAR AUTOM\xB5TICO\n\t# 2- EXECUTAR MANUALMENTE\n\n\t > Op\x87\xC6o: ");
    scanf("%c",&esc1);
    fflush(stdin);

    while((esc1!='1')&&(esc1!='2'))
    { printf("\n\t> OP\x80\xC7O INV\xB5LIDA! DIGITE NOVAMENTE: ");
      scanf("%c",&esc1);
      fflush(stdin);
                            }

    if(esc1=='1')
    {
    system("cls");
    printf("\n\n--------------------------------------------------------------\n*************** EXECUTA A M\xB5QUINA DE TURING");
    printf(" ******\n\n\n\t");

    do{

		 for(i=0;i<=linha-1;i++){
             sinal=0;
             // armazena os dados inseridos na matriz em variáveis

               for(j=0;j<=linha-1;j++)
                {
                if((strcmp(estadoatual,programa[j].estado)==0)&&(programa[j].lido==fita[k]))
                sinal++;
                }

                for(inc=0;inc<=fita1-1;inc++)
                {// imprime as modificações feitas pela função de transição na fita
                printf(" %c",fita[inc]);
                }

				for(h=0;h<=fita1-1;h++){   // este bloco abaixo dá a falsa noção de movimento da mudança dos
                cabecote[h]='_';   //  números da fita e movimento do cabeçote
                }

                printf("\n\t");
				for(h=0;h<=fita1-1;h++){
				cabecote[k]='\x18';          // sincronização da posição do cabeçote com a posição
   				printf("_%c",cabecote[h]); // da fita na posição k. A interogação é o ponteiro do cabeçote
   																			                          }
                          printf("\n");
                          printf("\r\n");
						  Sleep(300);	                              // Sleep introduz um delay antes de apagar as informações da tela
						  system("cls");							 // causando a impressão de movimento do cabeçote e mudança do

     	       printf("\n\n--------------------------------------------------------------\n*************** EXECUTA A M\xB5QUINA DE TURING");
               printf(" ******\n\n\n\t");																							//  valor da fita

                 if(sinal>0){
                if((strcmp(estadoatual,programa[i].estado)==0)&&(programa[i].lido==fita[k])){ //realiza a função de transição da maquina de turing

				strcpy(estadoatual,programa[i].novo_estado);
				fita[k]=programa[i].escrito;

                if(programa[i].direcao=='1')
				k++;

                if(programa[i].direcao=='2')
				k--;

                if(k<0){
                        k++;
                        parada=1;
                      }
                if(k>(fita1-1)){
                                 k=fita1-1;
                                 parada=1;
                                 }

                                          }
                                }

                          }

              if(sinal==0){
                           parada=1;
                           break;
                          }

    }while(parada!=1);// condição de parada
   // por causa do comando  system cls perderemos o valor final da fita e do cabeçote então repetimos este trecho do código acima para garantir que as informações
   // fiquem disponíveis ao usuário.

    for(inc=0;inc<=fita1-1;inc++){// imprime o resultado da computação final feita pela maquina de turing
                                   printf(" %c",fita[inc]);
                                  }

    printf("\n\t");
    for(h=0;h<=fita1-1;h++){// imprime a posição final do cabeçote
							cabecote[k]='\x18';
   							printf("_%c",cabecote[h]);
   						    }


    printf("\n\n DIGITE QUALQUER TECLA PARA VOLTAR AO MENU ANTERIOR!");
    parada=0;
    system("pause>null");
    fflush(stdin);
    return maquina_menu();
}

    if(esc1=='2')
    {
    
    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
    printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");

    do{

		 for(i=0;i<=linha-1;i++){
             sinal=0;
             // armazena os dados inseridos na matriz em variáveis

               for(j=0;j<=linha-1;j++)
                {
                if((strcmp(estadoatual,programa[j].estado)==0)&&(programa[j].lido==fita[k]))
                sinal++;
                }

                for(inc=0;inc<=fita1-1;inc++)
                {// imprime as modificações feitas pela função de transição na fita
                printf(" %c",fita[inc]);
                }

				for(h=0;h<=fita1-1;h++){   // este bloco abaixo dá a falsa noção de movimento da mudança dos
                cabecote[h]='_';   //  números da fita e movimento do cabeçote
                }

                printf("\n\t");
				for(h=0;h<=fita1-1;h++){
				cabecote[k]='\x18';          // sincronização da posição do cabeçote com a posição
   				printf("_%c",cabecote[h]); // da fita na posição k. A interogação é o ponteiro do cabeçote
   																			                          }
                          printf("\n");
                          printf("\r\n");
						  system("pause>null");
                          system("cls");							 // causando a impressão de movimento do cabeçote e mudança do

              printf("\n\n--------------------------------------------------------------\n***************");
              printf(" EXECUTA A M\xB5QUINA DE TURING");
              printf(" ******\n\n\n\t");																							//  valor da fita

                 if(sinal>0){
                if((strcmp(estadoatual,programa[i].estado)==0)&&(programa[i].lido==fita[k])){ //realiza a função de transição da maquina de turing

				strcpy(estadoatual,programa[i].novo_estado);
				fita[k]=programa[i].escrito;

                if(programa[i].direcao=='1')
				k++;

                if(programa[i].direcao=='2')
				k--;

                if(k<0){
                        k++;
                        parada=1;
                      }
                if(k>(fita1-1)){
                                 k=fita1-1;
                                 parada=1;
                                 }

                                          }
                                }

                          }

              if(sinal==0){
                           parada=1;
                           break;
                          }

    }while(parada!=1);// condição de parada
   // por causa do comando  system cls perderemos o valor final da fita e do cabeçote então repetimos este trecho do código acima para garantir que as informações
   // fiquem disponíveis ao usuário.

    for(inc=0;inc<=fita1-1;inc++){// imprime o resultado da computação final feita pela maquina de turing
                                   printf(" %c",fita[inc]);
                                  }

    printf("\n\t");
    for(h=0;h<=fita1-1;h++){// imprime a posição final do cabeçote
							cabecote[k]='\x18';
   							printf("_%c",cabecote[h]);
   						    }


    printf("\n\n DIGITE QUALQUER TECLA PARA VOLTAR AO MENU ANTERIOR!");
    parada=0;
    system("pause>null");
    fflush(stdin);
    return maquina_menu();
}
   }

void menu()      //-------------------------MENU---PRINCIPAL------------------------------
{
      system("cls");
      system("color 2f");//FUNDO VERDE


      HANDLE hConsole;
      hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

     menu_1();//IMPRIME MENU PRINCIPAL

     scanf("%c", &opcao1);
     fflush(stdin);

//------------------------------------------FIM MENU-----------------------------------------------------------------

     switch (opcao1){

      case '1': {maquina_menu();}

      case '2': {tutorial();}
      
      case '3':{abre_arquivo();}

      case '4': system("cls");
           {  system("color 0f");

           animacao_titulo();



      //-----------------INFORMACAO MAQUINA DE TURING ----------------

      SetConsoleTextAttribute(hConsole, BRANCOB);
      printf("\n\n\n\tO funcionamento da m\xA0quina baseia-se no conceito de processamento \nmec\x83nico correspondente");
      printf("a um m\x82todo ou algoritmo. \nAo definir um conjuntos finito de instru\x87%ces, a m\xA0quina poderia interpretar \n",228);
      printf("e executar de forma mec\x83nica qualquer opera\x87\xC6o matem\xA0tica, \n");
      printf("possibilitando a exist\x88ncia de v\xA0rias ''m\xA0quinas de Turing''. \n");

      Sleep(500);
      printf("\n\n** [LER MAIS]- Pressione qualquer tecla**\n");
      system("pause>null");
      fflush(stdin);
      printf("\nUma m\xA0quina de Turing eh uma 7-upla, \n(Q, $, @, &, qo, qaceita, qrejeita), \nonde Q, $, @ s\xC6o ");
      printf("todos conjuntos finitos, e:\n1. Q \x82 o conjunto de estados,\n2. $ \x82 o alfabeto de entrada sem o s\xA1mbolo");
      printf(" em branco [ ],\n3. @ eh o alfabeto de fita,\n4. &: Q x @ -> Q x @ x {E, D} eh a fun\x87\xC6o de transi\x87\xC6o,\n5.");
      printf(" qo E('pertence a') Q \x82 o estado inicial,\n6. qaceita  E('pertence a') Q \x82 o estado de aceita\x87\xC6o e,\n");
      printf("7. qrejeita  E('pertence a') Q \x82 o estado de rejei\x87\xC6o, onde qaceita !=  qrejeita.\n\n");
      //----------------- FIM INFORMACAO  ----------------


      printf("\n\n**Digite 1 para sair ou qualquer outro n\xA3mero para voltar ao menu anterior**\n- ");
      scanf("%c", &opcao1);
      fflush(stdin);

      if(opcao1=='1')
      {exit(1);}

      else
      {return menu();}
      system("pause>null");              }


      case '5':
           printf("\n\n\n\t\tO B R I G A D O !\n");
           Sleep(600);
           exit(1);  // FECHA O PROGRAMA

      case '6':{
      system("cls");
      system("color 02");


      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
      printf("\t\t\a - Informa\x87%ces:\n\n\n",228);

      printf("\n# Trabalho Interdisciplinar - 1o semestre\n");
      printf("\t\t\t\t 2012.2");

      printf("\n\n\n\n\t>>> M\xB5QUINA DE TURING - Alan Turing<<<");

      printf("\nCurso:\n# An\xA0lise e Desenvolvimento de Sistemas - Gradua\x87\xC6o Tecnol\xA2gica \n\n");
      printf("\n# Apresentado as disciplinas de:\n\n\t[Introdu\x87\xC6o a L\xA2gica de Programa\x87\xC6o]\n\t");
      printf("[Arquitetura de Computadores e Software B\xA0sico]\n\t[Introdu\x87\xC6o a computa\x87\xC6o]\n");
      printf("\n# Integrantes:\n\n\t- Bruno Ara\xA3jo\n\t- Carla Franco\n\t- %caro Jerry\n\t- Marcondes Texeira\n");
      printf("\t- Rodrigo Brito\n",214);

      logo_ifba();


      printf("\nDigite 1 para sair ou  qualquer tecla para voltar ao menu anterior:");
      scanf("%c", &opcao1);
      fflush(stdin);

      if(opcao1=='1')
      {exit(1);}

      else
      {return menu();} // Voltar para o menu

      break;}



     default:{ printf("\t\t\t*** Op\x87\xC6o Inv\xA0lida ***");
     Sleep(1500);
     menu();
     break;}
     }


system("pause>null");}



main(){

      printf("aguarde...");
      Sleep(3200);
      system("cls");

      apresentacao_apple();// ABRE APRESENTACAO DA MACA
      //---------------------------------------------FIM - INTRODUCAO----------------------
       menu();// ABRE O MENU PRIMARIO
      }



      void menu_2()
      {
         printf("\n\n\n\n\n-----------------------------------------");
         printf(" M\xB5QUINA DE TURING - V. 8008.2 -------------------------------------------\n");

         printf("\n\t\t\t\t\t\t------- BEM VINDO! -------\n");

         printf("\n\t\t\t\t\t_______________________________________\n");
         printf("\t\t\t\t\t|          #  MENU  M. TURING  #       |\n");
         printf("\t\t\t\t\t|______________________________________|");
         printf("\n\t\t\t\t\t| [1] Dados\t      | [2] Fita       |");
         printf("\n\t\t\t\t\t| [3] Posi\x87\xC6o\t      | [4] Executar   |");
         printf("\n\t\t\t\t\t| [5] Voltar ao Menu  | [6] Zerar dados|");
         printf("\n\t\t\t\t\t|______________________________________|");

         printf("\n\n\t\t\t\t** Para acessar um menu, digite um n\xA3mero correspondente **");
         printf("\n\t\t\t\t.............................................................\n\t\t\t\t #Op\x87\xC6o:  ");
           }

    void menu_1()
    {
         printf("\n\n\n\n\n-----------------------------------------");
         printf(" M\xB5QUINA DE TURING - V. 8008.2 -------------------------------------------\n");

     printf("\n\t\t\t\t\t\t  ------- BEM VINDO! -------\n");

     printf("\n\t\t\t\t\t_______________________________________\n");
     printf("\t\t\t\t\t|            #    MENU     #           |\n");
     printf("\t\t\t\t\t|______________________________________|");
     printf("\n\t\t\t\t\t| [1] Exe M\xA0quina | [2] Tutorial       |");
     printf("\n\t\t\t\t\t| [3] Arquivo\t  | [4] Ajuda          |");
     printf("\n\t\t\t\t\t| [5] Sair\t  | [6] Info.          |");
     printf("\n\t\t\t\t\t|______________________________________|");

     printf("\n\n\t\t\t\t** Para acessar um menu, digite um n\xA3mero correspondente **");
     printf("\n\t\t\t\t.............................................................\n\t\t\t\t #Op\x87\xC6o:  ");
         }

    void logo_ifba()

    {
      HANDLE hConsole;
      hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
      // ------------LOGO IFBA
      printf("\n------------------------------------------------------------------\n\n");

      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
      printf("   ,ri:");
      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      printf("     , ,     , , ,\n");
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
      printf("  s92X2S,");
      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      printf("  r;ris  ,sirir;s\n");
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
      printf(",SM2X2XS@:");
      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      printf(" 2rss,  rssrsrss,\n");
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
      printf(":MHXsS29M2");
      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      printf(" srsr2  :2rs;sr2\n");
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
      printf(" i@9M9MGG");
      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      printf("  rHs22, r22s2sHs,\n");
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
      printf("   i,:,:");
      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      printf("       ,   , , , , \n");

      printf(" ,: , ,,  r,:,:,,                                      \n ss2rsrX  22r2sX:  ");
      printf("                                    \n :2rsrss  2rs;ssi                      ");
      printf("                \n rssrsrS  ssrsrH:                                         ");
      printf("                                                    \n irriris  rriris, :2rsrsr2");
      printf("                             \n i2rsrss  Hrsrssi rssrsrss                        ");
      printf("     \n rrsrsr5  ssrsr2, :2rsrsr2                             \n :2rsrss, Hrsrssi");
      printf(" rs2s2s5s,\n");
      printf(" :sirisr  sirirrs\n rssrsrH  ssrsr2r\n :2rs;ss  2rs;srs\n rs2s2s9  25s2sSs\n");

      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
      printf("\n\nInstituto Federal de Educacao, Ciencias e Tecnologia\n");
      SetConsoleTextAttribute(hConsole,  FOREGROUND_GREEN | FOREGROUND_INTENSITY);
      printf("\nBAHIA\n");
      SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
      printf("\t CAMPUS SALVADOR\n");
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
      // ------------LOGO IFBA
         }

      void animacao_titulo() // Animacao Titulo "Turing Machine"-------------------------------------
      {

       HANDLE hConsole;
      hConsole = GetStdHandle (STD_OUTPUT_HANDLE);


       // Uma sequencia de printf na tela seguida de system apresenta ao usuario uma breve animaçao de uma maquina de Turing
       printf("\n\n\n");
       printf("\t\t\t|X||X||X||X||X||X||X||X||X||X||X||X||X||X|");
       printf("\n\t\t\t /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       SetConsoleTextAttribute(hConsole, LILAS);
       printf("\t\t\t[T]|X||X||X||X||X||X||X||X||X||X||X||X||X|");
       printf("\n\t\t\t /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       SetConsoleTextAttribute(hConsole, VERDEC);
       printf("\t\t\t|T||X||X||X||X||X||X||X||X||X||X||X||X||X|");
       printf("\n\t\t\t    /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       printf("\t\t\t|T|[U]|X||X||X||X||X||X||X||X||X||X||X||X|");
        printf("\n\t\t\t    /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       SetConsoleTextAttribute(hConsole, AZULC);
       printf("\t\t\t|T||U||X||X||X||X||X||X||X||X||X||X||X||X|");
       printf("\n\t\t\t       /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       printf("\t\t\t|T||U|[R]|X||X||X||X||X||X||X||X||X||X||X|");
       printf("\n\t\t\t       /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       SetConsoleTextAttribute(hConsole, AMARELOC);
       printf("\t\t\t|T||U||R||X||X||X||X||X||X||X||X||X||X||X|");
       printf("\n\t\t\t          /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       printf("\t\t\t|T||U||R|[I]|X||X||X||X||X||X||X||X||X||X|");
       printf("\n\t\t\t          /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       SetConsoleTextAttribute(hConsole, VERDEC);
       printf("\t\t\t|T||U||R||I||X||X||X||X||X||X||X||X||X||X|");
       printf("\n\t\t\t             /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       printf("\t\t\t|T||U||R||I|[N]|X||X||X||X||X||X||X||X||X|");
       printf("\n\t\t\t             /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       SetConsoleTextAttribute(hConsole, VERMELHOC);
       printf("\t\t\t|T||U||R||I||N||X||X||X||X||X||X||X||X||X|");
       printf("\n\t\t\t                /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       printf("\t\t\t|T||U||R||I||N|[G]|X||X||X||X||X||X||X||X|");
       printf("\n\t\t\t                /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       SetConsoleTextAttribute(hConsole, AMARELOC);
       printf("\t\t\t|T||U||R||I||N||G||X||X||X||X||X||X||X||X|");
       printf("\n\t\t\t                   /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       printf("\t\t\t|T||U||R||I||N||G|[ ]|X||X||X||X||X||X||X|");
       printf("\n\t\t\t                   /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       SetConsoleTextAttribute(hConsole, AZULC);
       printf("\t\t\t|T||U||R||I||N||G|| ||X||X||X||X||X||X||X|");
       printf("\n\t\t\t                      /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       printf("\t\t\t|T||U||R||I||N||G|| |[M]|X||X||X||X||X||X|");
       printf("\n\t\t\t                      /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       SetConsoleTextAttribute(hConsole, VERDEA);
       printf("\t\t\t|T||U||R||I||N||G|| ||M||X||X||X||X||X||X|");
       printf("\n\t\t\t                         /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       printf("\t\t\t|T||U||R||I||N||G|| ||M|[A]|X||X||X||X||X|");
       printf("\n\t\t\t                         /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       SetConsoleTextAttribute(hConsole, BRANCO);
       printf("\t\t\t|T||U||R||I||N||G|| ||M||A||X||X||X||X||X|");
       printf("\n\t\t\t                           /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       printf("\t\t\t|T||U||R||I||N||G|| ||M||A|[C]|X||X||X||X|");
       printf("\n\t\t\t                           /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       SetConsoleTextAttribute(hConsole, ROXO );
       printf("\t\t\t|T||U||R||I||N||G|| ||M||A||C||X||X||X||X|");
       printf("\n\t\t\t                               /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       printf("\t\t\t|T||U||R||I||N||G|| ||M||A||C|[H]|X||X||X|");
       printf("\n\t\t\t                               /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       SetConsoleTextAttribute(hConsole, AMARELOC);
       printf("\t\t\t|T||U||R||I||N||G|| ||M||A||C||H||X||X||X|");
       printf("\n\t\t\t                                  /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       printf("\t\t\t|T||U||R||I||N||G|| ||M||A||C||H|[I]|X||X|");
       printf("\n\t\t\t                                  /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       SetConsoleTextAttribute(hConsole, VERMELHOC);
       printf("\t\t\t|T||U||R||I||N||G|| ||M||A||C||H||I||X||X|");
       printf("\n\t\t\t                                     /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       printf("\t\t\t|T||U||R||I||N||G|| ||M||A||C||H||I|[N]|X|");
       printf("\n\t\t\t                                     /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
              SetConsoleTextAttribute(hConsole, AZULC);
       printf("\t\t\t|T||U||R||I||N||G|| ||M||A||C||H||I||N||X|");
       printf("\n\t\t\t                                        /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       printf("\t\t\t|T||U||R|[I][N||G|| ||M||A||C||H||I||N|[E]");
       printf("\n\t\t\t                                        /\\");
       Sleep(100);
       system("cls");

       printf("\n\n\n");
       SetConsoleTextAttribute(hConsole, BRANCOB);
       printf("\t\t\t T  U  R  I  N  G     M  A  C  H  I  N  E ");
       Sleep(500);

       // FIM Animacao "Turing Machine"-------------------------------------


                       }

      void apresentacao_apple()
      {
      HANDLE hConsole;
      hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

       //---------------------------------------------INICIO - INTRODUCAO----------------------
      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN| FOREGROUND_INTENSITY);
      printf("\n\n\t\t\t                                               101                    \n\t\t\t");
      printf("                                          ");
      printf("10000001                    \n\t\t\t                                       10000001001                    \n\t\t\t                 ");
      printf("                    100010111000                     \n\t\t\t                                    000011101000                ");
      printf("      \n\t\t\t                                   000011101000                       \n\t\t\t                                  10011");
      printf("1100000                        \n\t\t\t                                  0001000001                          \n\t\t\t              ");
      printf("                   100000001                            \n\t\t\t                                  111\n\t\t\t");
      SetConsoleTextAttribute(hConsole,  FOREGROUND_RED| FOREGROUND_INTENSITY);
      printf("                 111111                      11000111                 \n\t\t\t            10000000000000011          10000000");
      printf("000000000011           \n\t\t\t         1000000000110000000000000100000000000101010000000000         \n\t\t\t       000010111011111");
      printf("111101000000000100010111111111110101000001      \n\t\t\t     000001111111111111111101111111111111111111111111110111000001    ");
      printf(" \n\t\t\t    0001011111011111011111111111111111111111111111111111110001        \n\t\t\t   00011111111111011111111111111101110111111");
      printf("1111111011111001          \n\t\t\t  000111111111111111110111110111111111111111011111111111001           \n\t\t\t 100101111111111111");
      printf("11111101111111111111111111111111110100             \n\t\t\t 00111111101011111110111110111011111011111111111111111001          ");
      printf("   \n\t\t\t10111110111111111111101111111111111111111111111111111100              \n\t\t\t0101111111111111111111111111111111111111111");
      printf("1111111111100              \n\t\t\t");

      printf("11111111111111101110111111111110111111111111111111101100              \n\t\t\t011111110111111111111111111101110111111111111111");
      printf("11110100              \n\t\t\t01111111111111111110111011111111111111111111111111111000              \n\t\t\t100111111111111111111111");
      printf("010111011101111111110111111101100             \n\t\t\t 000111111111111111111111111111111111011111110101111111001            \n\t\t\t");
      printf(" 1011111111111111111111111111111011111111111111111111111000           \n\t\t\t  0011101111111111111110111111111111111011111111");
      printf("1011111110001         \n\t\t\t  0001011111011101111111111111111111011111111111011111111100001       \n\t\t\t   001111111111111111111");
      printf("111111111111111110111111111111111010000001  \n\t\t\t");
      printf("    000101111111011111111111011111111111111111111111011111111100001   \n\t\t\t    000011111111111011101011111111111010111111111");
      printf("11111101111111000    \n\t\t\t     000111111111111111111111111111111111111111111011111110111000     \n\t\t\t      000011111111111110111");
      printf("1111111111011111111111111111111111000      \n\t\t\t       10001110111111111111101111111110111111111111111111110001       \n\t\t\t      ");
      printf("   0001111111111111111111111111111111111111111111110000         \n\t\t\t          0001111111111111011111111111111101111111111111");
      printf("0000          \n\t\t\t           100001011111011111010100010101111101111111110001           \n\t\t\t             000000111010100000000");
      printf("00000000000101111100000             \n\t\t\t               1000000000000001        1100000000000000               \n\t\t\t            ");
      printf("      11000111                  11110011\n\n\n");
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

      printf("      - PRESSIONE QUALQUER TECLA PARA INICIAR:\n\n\t\t\t");
      printf("\r----------------------------------------------------------------------------------------------------------------------------\n\t\t\t\t\t****************  M\xB5QUINA DE TURING");
      printf("   ****************\n\n\t\t\t-A. Bruno  -F. Carla  -J. Icaro  -T. Marcondes  -B. Rodrigo \r");
      Sleep(1500);
      system("pause>null");
      system("cls");

      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN| FOREGROUND_INTENSITY);
      printf("\n\n\t\t\t                                             1101\n\t\t\t                                        110101000\n\t\t\t               ");
      printf("                       1000001010                      \n\t\t\t                                    110101010100\n\t\t\t              ");
      printf("                     1001010101011\n\t\t\t                                  000101010100\n\t\t\t                                 1101");
      printf("01010001\n\t\t\t                                 1010100000\n\t\t\t                                 0101000\n\t\t\t                        ");
      printf("         11\n\t\t\t");
      SetConsoleTextAttribute(hConsole,  FOREGROUND_RED| FOREGROUND_INTENSITY);
      printf("                 111111                      11000111                 \n\t\t\t            10000000000000011          1000000000");
      printf("0000000011           \n\t\t\t         1000000000110000000000000100000000000101010000000000         \n\t\t\t       0000101110111111111");
      printf("01000000000100010111111111110101000001      \n\t\t\t     000001111111111111111101111111111111111111111111110111000001     \n\t\t\t   ");
      printf(" 0001011111011111011111111111111111111111111111111111110001        \n\t\t\t   0001111111111101111111111111110111011111111111110");
      printf("11111001          \n\t\t\t  000111111111111111110111110111111111111111011111111111001           \n\t\t\t 1001011111111111111111110111");
      printf("1111111111111111111111110100             \n\t\t\t 00111111101011111110111110111011111011111111111111111001             \n\t\t\t101111");
      printf("10111111111111101111111111111111111111111111111100              \n\t\t\t0101111111111111111111111111111111111111111111111111110");
      printf("0              \n\t\t\t");

      printf("11111111111111101110111111111110111111111111111111101100              \n\t\t\t01111111011111111111111111110111011111111111111111");
      printf("110100              \n\t\t\t01111111111111111110111011111111111111111111111111111000              \n\t\t\t1001111111111111111111110101");
      printf("11011101111111110111111101100             \n\t\t\t 000111111111111111111111111111111111011111110101111111001            \n\t\t\t 10111");
      printf("11111111111111111111111111011111111111111111111111000           \n\t\t\t  001110111111111111111011111111111111101111111110111111");
      printf("10001         \n\t\t\t  0001011111011101111111111111111111011111111111011111111100001       \n\t\t\t   0011111111111111111111111111111");
      printf("11111110111111111111111010000001  \n\t\t\t");

      printf("    000101111111011111111111011111111111111111111111011111111100001   \n\t\t\t    0000111111111110111010111111111110101111111111");
      printf("1111101111111000    \n\t\t\t     000111111111111111111111111111111111111111111011111110111000     \n\t\t\t      0000111111111111101111");
      printf("111111111011111111111111111111111000      \n\t\t\t       10001110111111111111101111111110111111111111111111110001       \n\t\t\t      ");
      printf("   0001111111111111111111111111111111111111111111110000         \n\t\t\t          0001111111111111011111111111111101111111111111");
      printf("0000          \n\t\t\t           100001011111011111010100010101111101111111110001           \n\t\t\t             000000111010100000000");
      printf("00000000000101111100000             \n\t\t\t               1000000000000001        1100000000000000               \n\t\t\t            ");
      printf("      11000111                  11110011   \n\t\t\t");

      Sleep(800);
      system("cls");

      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN| FOREGROUND_INTENSITY);
      printf("\n\n\t\t\t                                             1101\n\t\t\t                                        110101000\n\t\t\t                ");
      printf("                      1000001010                      \n\t\t\t                                    110101010100\n\t\t\t                ");
      printf("                   1001010101011\n\t\t\t                                  000101010100\n\t\t\t                                 1101010");
      printf("10001\n\t\t\t                                 1010100000\n\t\t\t                                 0101000\n\t\t\t                           ");
      printf("      11\n\t\t\t");
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
      printf("                11111111                   1111000111\n\t\t\t           100000101000100011        111000000010100000001\n\t\t\t      ");
      printf("   000101010101010101010001010100010101010101010100000\n\t\t\t      100001010101010101000111111111010001010101010101010101011\n\t\t\t");
      printf("     000101010101010101010     111     000101010101010101010101\n\t\t\t    000101010101010100  11111100001 11  0101010101010101");
      printf("0001\n\t\t\t  10101010101010101001 0101110001  11011 01010101010101010\n\t\t\t  010101010101010101110100111       11001 0101010101010");
      printf("10\n\t\t\t 100101010101010101  01               101 10101010101000\n\t\t\t1001010101010101010                   1101 001010101010\n\t\t\t");

      printf("11111111111111101110111111111110111111111111111111101100              \n\t\t\t0111111101111111111111111111011101111111111111111");
      printf("1110100              \n\t\t\t01111111111111111110111011111111111111111111111111111000              \n\t\t\t100111111111111111111111010");
      printf("111011101111111110111111101100             \n\t\t\t 000111111111111111111111111111111111011111110101111111001            \n\t\t\t 101");
      printf("1111111111111111111111111111011111111111111111111111000           \n\t\t\t  001110111111111111111011111111111111101111111110111");
      printf("11110001         \n\t\t\t  0001011111011101111111111111111111011111111111011111111100001       \n\t\t\t   0011111111111111111111111111");
      printf("11111111110111111111111111010000001  \n\t\t\t");

      printf("    000101111111011111111111011111111111111111111111011111111100001   \n\t\t\t    0000111111111110111010111111111110101111111111");
      printf("1111101111111000    \n\t\t\t     000111111111111111111111111111111111111111111011111110111000     \n\t\t\t      0000111111111111101111");
      printf("111111111011111111111111111111111000      \n\t\t\t       10001110111111111111101111111110111111111111111111110001       \n\t\t\t      ");
      printf("   0001111111111111111111111111111111111111111111110000         \n\t\t\t          0001111111111111011111111111111101111111111111");
      printf("0000          \n\t\t\t           100001011111011111010100010101111101111111110001           \n\t\t\t             000000111010100000000");
      printf("00000000000101111100000             \n\t\t\t               1000000000000001        1100000000000000               \n\t\t\t           ");
      printf("       11000111                  11110011   \n\t\t\t");
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
      printf("\n\t\t\tLOADING...");
      Sleep(1000);
      system("cls");

      SetConsoleTextAttribute(hConsole,  FOREGROUND_GREEN| FOREGROUND_INTENSITY);
      printf("\n\n\t\t\t                                             1101\n\t\t\t                                        110101000\n\t\t\t                ");
      printf("                      1000001010                      \n\t\t\t                                    110101010100\n\t\t\t                ");
      printf("                   1001010101011\n\t\t\t                                  000101010100\n\t\t\t                                 1101010");
      printf("10001\n\t\t\t                                 1010100000\n\t\t\t                                 0101000\n\t\t\t                            ");
      printf("     11\n\t\t\t");
      SetConsoleTextAttribute(hConsole,  FOREGROUND_RED| FOREGROUND_INTENSITY);
      printf("                11111111                   1111000111\n\t\t\t           100000101000100011        111000000010100000001\n\t\t\t        ");
      printf(" 000101010101010101010001010100010101010101010100000\n\t\t\t      100001010101010101000111111111010001010101010101010101011\n\t\t\t    ");
      printf(" 000101010101010101010     111     000101010101010101010101\n\t\t\t    000101010101010100  11111100001 11  01010101010101010001\n\t\t\t ");
      printf(" 10101010101010101001 0101110001  11011 01010101010101010\n\t\t\t  010101010101010101110100111       11001 010101010101010\n\t\t\t 10010");
      printf("1010101010101  01               101 10101010101000\n\t\t\t1001010101010101010                   1101 001010101010\n\t\t\t");

      printf("1010101010101010100                  1 111  10101010101               \n\t\t\t01010101010101010100          11011111110    1010101");
      printf("010\n\t\t\t10101010101010101000 110101   111011   111 1 1101010101\n\t\t\t01010101010101010101  11111           111 1  1010101010\n\t\t\t1010");
      printf("1010101010101010                   11   101010101011\n\t\t\t110101010101010101001      1111       111  1010101010100\n\t\t\t 0101010101");
      printf("01010101001     1 1       1 111 00010101010101\n\t\t\t 1010101010101010101001   1   1111    111  1010101010101001\n\t\t\t  001010101010");
      printf("1010101001 1 1 111    11 110 11010101010101011\n\t\t\t  1001010101010101010101  1        11101011  100010101010100011\n\t\t\t   1001010");
      printf("10101010101010   1     110101011 1   110101010101010101\n\t\t\t");

      printf("    000101111111011111111111011111111111111111111111011111111100001   \n\t\t\t    0000111111111110111010111111111110101111111111");
      printf("1111101111111000    \n\t\t\t     000111111111111111111111111111111111111111111011111110111000     \n\t\t\t      0000111111111111101111");
      printf("111111111011111111111111111111111000      \n\t\t\t       10001110111111111111101111111110111111111111111111110001       \n\t\t\t      ");
      printf("   0001111111111111111111111111111111111111111111110000         \n\t\t\t          0001111111111111011111111111111101111111111111");
      printf("0000          \n\t\t\t           100001011111011111010100010101111101111111110001           \n\t\t\t             000000111010100000000");
      printf("00000000000101111100000             \n\t\t\t               1000000000000001        1100000000000000               \n\t\t\t            ");
      printf("      11000111                  11110011   \n\t\t\t");
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
      printf("\n\t\t\tLOADING...");


      Sleep(800);
      system("cls");

      SetConsoleTextAttribute(hConsole,  FOREGROUND_GREEN| FOREGROUND_INTENSITY);
      printf("\n\n\t\t\t                                             1101\n\t\t\t                                        110101000\n\t\t\t               ");
      printf("                       1000001010                      \n\t\t\t                                    110101010100\n\t\t\t              ");
      printf("                     1001010101011\n\t\t\t                                  000101010100\n\t\t\t                                 1101");
      printf("01010001\n\t\t\t                                 1010100000\n\t\t\t                                 0101000\n\t\t\t                        ");
      printf("         11\n\t\t\t");
      SetConsoleTextAttribute(hConsole,  FOREGROUND_RED| FOREGROUND_INTENSITY);
      printf("                11111111                   1111000111\n\t\t\t           100000101000100011        111000000010100000001\n\t\t\t       ");
      printf("  000101010101010101010001010100010101010101010100000\n\t\t\t      100001010101010101000111111111010001010101010101010101011\n\t\t\t  ");
      printf("   000101010101010101010     111     000101010101010101010101\n\t\t\t    000101010101010100  11111100001 11  0101010101010101000");
      printf("1\n\t\t\t  10101010101010101001 0101110001  11011 01010101010101010\n\t\t\t  010101010101010101110100111       11001 010101010101010\n\t\t\t");
      printf(" 100101010101010101  01               101 10101010101000\n\t\t\t1001010101010101010                   1101 001010101010\n\t\t\t");

      printf("1010101010101010100                  1 111  10101010101               \n\t\t\t01010101010101010100          11011111110    101010");
      printf("1010\n\t\t\t10101010101010101000 110101   111011   111 1 1101010101\n\t\t\t01010101010101010101  11111           111 1  1010101010\n\t\t\t101");
      printf("01010101010101010                   11   101010101011\n\t\t\t110101010101010101001      1111       111  1010101010100\n\t\t\t 010101010");
      printf("101010101001     1 1       1 111 00010101010101\n\t\t\t 1010101010101010101001   1   1111    111  1010101010101001\n\t\t\t  00101010101");
      printf("01010101001 1 1 111    11 110 11010101010101011\n\t\t\t  1001010101010101010101  1        11101011  100010101010100011\n\t\t\t   100101");
      printf("010101010101010   1     110101011 1   110101010101010101\n\t\t\t");

      printf("    010101010101010101010   01000101011 1 1 1      10101010101010     \n\t\t\t    101010101010101000001  011111011 1   1        ");
      printf("  101010101010\n\t\t\t     101010101010100111   01111     1 1 1  1        11010101000\n\t\t\t      1010101010011      1111111 1 1 1 1 ");
      printf("           1000101010\n\t\t\t        00010101    1 1 111 111 1 1   1   1         000101010\n\t\t\t         010101  1 111 111 111   1  ");
      printf(" 1 1 1 1       100101011\n\t\t\t          1101          1 1 1             11      100101001\n\t\t\t            1001 1   1 11111 1 1 11");
      printf("1 1   11  111101010001\n\t\t\t             101010101010100000001010001010001000001000\n\t\t\t               1100000100011             ");
      printf("110000000001\n\t\t\t                    1\n\t\t\t");

      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
      printf("\n\t\t\t# CARREGADO!\n");
      printf("     -PRESSIONE QUALQUER TECLA PARA CONTINUAR:\n\n\a\r\r\r");
      printf("\r---------------------------------------------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t****************  M\xB5QUINA DE TURING  *");
      printf("***************\n\n\t\t\t-A. Bruno  -F. Carla  -J. Icaro  -T. Marcondes  -B. Rodrigo \r");
      Sleep(1500);

      system("pause>null");
      fflush(stdin);


           }
 void tutorial()
     {   system("cls");
         menu_1();
         printf("\n\n\t >> TUTORIAL AUTOM\xB5TICO - M\xB5QUINA DE TURING!\n\n\t *** AGUARDE AS INSTRU\x80%cES***",228);
         Sleep(3200);

         system("cls");
         menu_1();
         printf("\n\n\t >>> Op\x87\xC6o:  <Digite 1>\n\n\t *** Voc\x88 ir\xA0 entrar no Menu para Executar a M\xA0quina.\n\n\t# ");
         system("pause");

         system("cls");
         menu_1();
         printf(" 1\n\n\t");
         system("pause");

         system("cls");
         system("color 3f");// FUNDO AZUL
         menu_2();
         printf("\n\n\t >> MENU DA M\xB5QUINA DE TURING!\n\n\t  ** Neste Menu encontramos os passos que devemos preencher\n");
         printf("\t   para executar a m\xA0quina...\n\n\n\t#");
         system("pause");

         system("cls");
         system("color 3f");// FUNDO AZUL
         menu_2();
         printf("\n\n\t >> Para executar a M\xA0quina voc\x88 deve primeiro preencher as\n\t   > Op\x87%ces 1, 2 e 3\n",228);
         printf("\t    Nesta ordem!\n\n\t");
         system("pause");

         system("cls");
         menu_2();
         printf("\n\n\t >>> Op\x87\xC6o:  <Digite 1>\n\n\t Primeiro preencha os dados de transi\x87\xC6o ");
         printf("da M\xA0quina.\n\n\t# ");
         system("pause");

         system("cls");
         menu_2();
         printf(" 1\n\n\t");
         system("pause");

         system("cls");
         printf("\n\n******************INSERIR DADOS*********************************\n");
		 printf("--------------------------------------TRANSI\x80\xC7O 01--\n\n\n");
         printf("\t>>>Neste Menu s\xC6o inseridos as transi\x87%ces da m\xA0quinas,\n\t ou seja:",228);
         printf("\n\n\tOs dados necess\xA0rios para executar a transi\x87\xC6o,");
         printf(" a qual, no exemplo, substituir\xA0 o digito '0' por digito '1'.\n\tUtilizando apenas dois estados: QUE e WIL.\n\n\t# ");
         system("pause");

         system("cls");
         printf("\n\n******************INSERIR DADOS*********************************\n");
		 printf("--------------------------------------TRANSI\x80\xC7O 01--\n\n\n");
                        printf("\n\tEstado: "); Sleep(300); printf("QUE");
                        Sleep(500);
                        printf("\n\tS\xA1mbolo lido: "); Sleep(300); printf(">");
                        Sleep(500);
                        printf("\n\tS\xA1mbolo escrito: "); Sleep(300); printf(">");
                        Sleep(500);
                        printf("\n\tDire\x87\xC6o [0- NULO | 1 - Direita | 2 - Esquerda]: "); Sleep(300); printf("1");
                        Sleep(500);
                        printf("\n\tNovo Estado: "); Sleep(300); printf("QUE");
                        Sleep(500);

         printf("\n\n\n\t>>> Os dados devem ser inseridos nos seus locais devidos.\n\t    ");
         printf("A propria m\xA0quina explica o que deve ser feito.\n\n\t#");
         system("pause");

         system("cls");
         printf("\n\n******************INSERIR DADOS*********************************\n");
		 printf("--------------------------------------TRANSI\x80\xC7O 02--\n\n\n");
                        printf("\n\tEstado: "); Sleep(300); printf("QUE");
                        Sleep(500);
                        printf("\n\tS\xA1mbolo lido: "); Sleep(300); printf("0");
                        Sleep(500);
                        printf("\n\tS\xA1mbolo escrito: "); Sleep(300); printf("1");
                        Sleep(500);
                        printf("\n\tDire\x87\xC6o [0- NULO | 1 - Direita | 2 - Esquerda]: "); Sleep(300); printf("1");
                        Sleep(500);
                        printf("\n\tNovo Estado: "); Sleep(300); printf("QUE");
                        Sleep(500);

         printf("\n\n\n\t#");
         system("pause");

         system("cls");
         printf("\n\n******************INSERIR DADOS*********************************\n");
		 printf("--------------------------------------TRANSI\x80\xC7O 03--\n\n\n");
                        printf("\n\tEstado: "); Sleep(300); printf("QUE");
                        Sleep(500);
                        printf("\n\tS\xA1mbolo lido: "); Sleep(300); printf("1");
                        Sleep(500);
                        printf("\n\tS\xA1mbolo escrito: "); Sleep(300); printf("0");
                        Sleep(500);
                        printf("\n\tDire\x87\xC6o [0- NULO | 1 - Direita | 2 - Esquerda]: "); Sleep(300); printf("1");
                        Sleep(500);
                        printf("\n\tNovo Estado: "); Sleep(300); printf("QUE");
                        Sleep(500);

         printf("\n\n\n\t#");
         system("pause");


         system("cls");
         printf("\n\n******************INSERIR DADOS*********************************\n");
		 printf("--------------------------------------TRANSI\x80\xC7O 04--\n\n\n");
                        printf("\n\tEstado: "); Sleep(300); printf("QUE");
                        Sleep(500);
                        printf("\n\tS\xA1mbolo lido: "); Sleep(300); printf("<");
                        Sleep(500);
                        printf("\n\tS\xA1mbolo escrito: "); Sleep(300); printf("<");
                        Sleep(500);
                        printf("\n\tDire\x87\xC6o [0- NULO | 1 - Direita | 2 - Esquerda]: ");Sleep(300); printf("1");
                        Sleep(500);
                        printf("\n\tNovo Estado: "); Sleep(300); printf("WIL");
                        Sleep(500);

         printf("\n\n\n\t#");
         system("pause");

         system("cls");
         printf("\n\n******************INSERIR DADOS*********************************\n");
		 printf("--------------------------------------TRANSI\x80\xC7O 04--\n\n\n");
                        printf("\n\tEstado: "); Sleep(300); printf("WIL");
                        Sleep(500);
                        printf("\n\tS\xA1mbolo lido: "); Sleep(300); printf("<");
                        Sleep(500);
                        printf("\n\tS\xA1mbolo escrito: "); Sleep(300); printf("<");
                        Sleep(500);
                        printf("\n\tDire\x87\xC6o [0- NULO | 1 - Direita | 2 - Esquerda]: "); Sleep(300); printf("0");
                        Sleep(500);
                        printf("\n\tNovo Estado: "); Sleep(300); printf("WIL");
                        Sleep(500);

         printf("\n\n\n\t>>> Terminando de inserir os dados de transi\x87\xC6o, digite op\x87\xC6o 1. \n\n\t# ");
         system("pause");

         system("cls");
         menu_2();

         printf("\n\n\t>>> Digite <Op\x87\xC6o: 2>\n\n\tPreencha os dados da fita!\n\n\t#");
         system("pause");

         system("cls");
         menu_2();

         printf("2\n\n\t# ");
         system("pause");
         system("cls");

         printf("\n\n*****************ALFABETO DA FITA*********************************\n");

         printf("\n\t>> ATEN\x80\xC7O: Cada elemento da fita \x82 composto por um caracter!!!\n\n");



         printf("\n\n\t# Digite o  alfabeto da fita, finalizando com o s\xA1mbolo '<'.\n\n");

         printf("\n  > Elemento 1 da fita: ");  Sleep(300);  printf("1");
         Sleep(500);
         printf("\n  > Elemento 2 da fita: ");  Sleep(300);  printf("0");
         Sleep(500);
         printf("\n  > Elemento 3 da fita: ");   Sleep(300); printf("1");
         Sleep(500);
         printf("\n  > Elemento 4 da fita: ");  Sleep(300);  printf("0");
         Sleep(500);
         printf("\n  > Elemento 5 da fita: ");  Sleep(300);  printf("1");
         Sleep(500);
         printf("\n  > Elemento 6 da fita: ");  Sleep(300);  printf("0");
         Sleep(500);
         printf("\n  > Elemento 7 da fita: ");  Sleep(300);  printf("0");
         Sleep(500);
         printf("\n  > Elemento 8 da fita: ");  Sleep(300);  printf("<");

         printf("\n\n\t#  Preencho a fita com os digitos '0' e '1', dos quais foram inseridos\n");
         printf("\t   fun\x87%ces de transi\x87%ces anteriormente para eles.\n\t   O n\xA3mero de elementos da fita n\xC6o altera a m\xA0quina.\n",228,228);
         printf("\t  Digitando o simbolo '<' finaliza este menu.\n\n\t# ");
         system("pause");

         system("cls");
         menu_2();
         printf("\n\n\t>>> Digite <Op\x87\xC6o: 3>\n\n\t**Defina o estado inicial\n\t  e a posi\x87\xC6o do cabecote");
         printf(" da m\xA0quina!\n\n\t *Neste Menu voc\x88 tamb\x82m ir\xA0 vizualizar\n\tos dados j\xA0 preenchidos.\n\n\t#");
         system("pause");

         system("cls");
         menu_2();
         printf("3\n\n\t# ");
         system("pause");
         system("cls");

    printf("\n\n*************VIZUALIZE SUA M\xB5QUINA*********************************\n\n\n");
    printf("     # Os dados inseridos s\xC6o:\n\n");
    Sleep(300);

    printf("\t___________________________________________________ \n");

    printf("\t|  QUE\t\t >    >  DIRT\t QUE\t\t   |\n");
    printf("\t|                                                  |\n");
    printf("\t|  QUE\t\t 1    0  DIRT\t QUE\t\t   |\n");
    printf("\t|                                                  |\n");
    printf("\t|  QUE\t\t 0    1  DIRT\t QUE\t\t   |\n");
    printf("\t|                                                  |\n");
    printf("\t|  QUE\t\t <    <  DIRT\t WIL\t\t   |\n");
    printf("\t|                                                  |\n");
    printf("\t|  WIL\t\t <    <  NULO\t WIL\t\t   |\n");
    printf("\t|                                                  |\n");
    printf("\t|__________________________________________________|\n\n");

    printf("\t[ > 1 0 1 0 1 0 0 < ");
    printf("]  <-- FITA--\n\n");

    Sleep(500);
    printf("\n\n\tDigite:\n\n\t  O estado inicial: "); Sleep(500); printf("QUE");
    printf("\n\t  A posi\x87\xC6o do cabecote da fita na M\xA0quina de Turing: "); Sleep(500); printf("0");

    printf("\n\n\t#");
    system("pause");


    system("cls");
    menu_2();
    printf("\n\n\t>>> Digite <Op\x87\xC6o: 4>\n\n\t**Executar a M\xA0quina!\n\t  **Nesta op\x87\xC6o voc\x88 ver\xA0");
    printf(" os dados sendo executados,\n\n\t segundo os dados j\xA0 preenchidos.\n\n\t#");
    system("pause");

         system("cls");
         menu_2();
         printf("4\n\n\t# ");
         system("pause");

    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
    printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("# 1- EXECUTAR AUTOM\xB5TICO\n\t# 2- EXECUTAR MANUALMENTE\n\n\t > Op\x87\xC6o: ");
    printf("\n\n\t>>> Digite <Op\x87\xC6o: 1>\n\n\t#");
    system("pause");

    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
      printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("# 1- EXECUTAR AUTOM\xB5TICO\n\t# 2- EXECUTAR MANUALMENTE\n\n\t > Op\x87\xC6o: ");
    printf("1\n\n\t#");
    system("pause");

    system("cls");//ponteiro no '>'
    printf("\n\n--------------------------------------------------------------\n");
      printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("> 1 0 1 0 1 0 0 <");
    printf("\n\t\x18_________________");
    Sleep(500);

    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
      printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("> 1 0 1 0 1 0 0 <");//ponteiro no um
    printf("\n\t__\x18_______________"); //2
    Sleep(500);

    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
      printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("> 0 0 1 0 1 0 0 <");//troca o numero
    printf("\n\t__\x18_______________");//2
    Sleep(500);

    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
      printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("> 0 0 1 0 1 0 0 <");//ponteiro no 0
    printf("\n\t____\x18_____________");//4
    Sleep(500);

    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
      printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("> 0 1 1 0 1 0 0 <");//troca o numero
    printf("\n\t____\x18______________");//4
    Sleep(500);

    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
      printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("> 0 1 1 0 1 0 0 <");//ponteiro no 1
    printf("\n\t______\x18____________");//6
    Sleep(500);

    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
      printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("> 0 1 0 0 1 0 0 <");//troca numero
    printf("\n\t______\x18____________");//6
    Sleep(500);

    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
      printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("> 0 1 0 1 1 0 0 <");
    printf("\n\t________\x18__________");//8
    Sleep(500);

    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
      printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("> 0 1 0 1 1 0 0 <");
    printf("\n\t________\x18__________");//8
    Sleep(500);

    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
      printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("> 0 1 0 1 0 0 0 <");
    printf("\n\t__________\x18________");//10
    Sleep(500);

    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
      printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("> 0 1 0 1 0 0 0 <");
    printf("\n\t__________\x18________");//10
    Sleep(500);

    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
      printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("> 0 1 0 1 0 1 0 <");
    printf("\n\t____________\x18______");//12
    Sleep(500);

    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
      printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("> 0 1 0 1 0 1 0 <");
    printf("\n\t____________\x18______");//12
    Sleep(500);

    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
      printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("> 0 1 0 1 0 1 1 <");
    printf("\n\t______________\x18____");//14
    Sleep(500);

    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
      printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("> 0 1 0 1 0 1 1 <");
    printf("\n\t______________\x18____");//14
    Sleep(500);

    system("cls");
    printf("\n\n--------------------------------------------------------------\n");
      printf("*************** EXECUTA A M\xB5QUINA DE TURING ******\n\n\n\t");
    printf("> 0 1 0 1 0 1 1 <");
    printf("\n\t________________\x18__");//16
    Sleep(700);

    printf("\n\n\n\t#");
    system("pause");
    system("cls");
    
    printf("\n\n\n\n\n\t\t\t * * *  F  I  M  !  * * * ");
    Sleep(1700);
    insert=0;
         return menu();
          }


void arquivo()
{

FILE *ponteiro; // ponteiro para arquivo
char lido1,escrito1,estado_novo_arquivo[10],estado_arquivo[10];
char selecao;

printf("\n\t #Deseja salvar os estados?\n");
printf("\nOp\x87\xC6o 1-SIM 2-N\xC7O\n # ");
scanf("%s",&selecao);
while((selecao!='1')&&(selecao!='2')){
                                      puts("\nOP\x80\xC7O INV\xB5LIDA.");
                                      printf("\nDeseja salvar?\n");
                                      printf("\nOp\x87\xC6o 1-SIM 2-N\xC7O\n");
                                      scanf("%s",&selecao);

                                      }

if(selecao=='2'){
                 fflush(stdin);
                 memset(nome,' ',10);//limpa o nome do arquivo aberto anteriormente
                 return maquina_menu();
                 }


printf("\n\n\t*** Digite um nome para o arquivo para leitura o qual dever possuir a extens\xC6o .txt.\n \t >> Nome: ");
scanf("%s",nome);//usuário define o nome do arquivo
ponteiro=fopen(nome,"w");// abre arquivo para gravar em modo texto 


 for(i=0;i<=(linha-1)/2;i++){ // copia as transições para variavéis
                     strcpy(estado_arquivo,programa[i].estado);
                     lido1=programa[i].lido;
                     escrito1=programa[i].escrito;
                     strcpy(estado_novo_arquivo,programa[i].novo_estado);
 //Bloca abaixo salva as transições em arquivo
               fprintf(ponteiro,"\t___________________________________________________ \n");
               if(programa[i].direcao=='1') // IMPRIME O NOME DA DIRECAO REFERENTE AO NOME
               {
               fprintf(ponteiro,"\t|  %s\t\t %c    %c  DIRT\t %s\t\t   |\n",estado_arquivo,lido1,escrito1,estado_novo_arquivo);
               }

               if(programa[i].direcao=='0')
               {
               fprintf(ponteiro,"\t|  %s\t\t %c    %c  NULO\t %s\t\t   |\n",estado_arquivo,lido1,escrito1,estado_novo_arquivo);
               }

               if(programa[i].direcao=='2')
               {
               fprintf(ponteiro,"\t|  %s\t\t %c    %c  ESQR\t %s\t\t   |\n",estado_arquivo,lido1,escrito1,estado_novo_arquivo);
               }


                                               printf("\t|                                                  |\n");

                                              }

	                       fprintf(ponteiro,"\t|__________________________________________________|\n\n");

fclose(ponteiro);
fflush(stdin);
return maquina_menu();
}

void abre_arquivo()
{
    char opcao;
    char esc;
    
    FILE *ponteiro;
    char caracter;
    printf("\n\n\t***Deseja visualizar as transi\x87%ces salvas ?\n",228);
    printf("\n\tOp\x87%ces-> 1-SIM ou qualquer caracter para N\xC7O.   # ",228);
    scanf("%c",&opcao);
    if(opcao=='1'){
    printf("\t #Digite o nome do arquivo:  ",228);               
    scanf("%s",nome);
    ponteiro=fopen(nome,"r");
    
    if(!ponteiro){ system("cls");//exibe mensagem de erro se o usuário resolver vizualizar transição não salva
                   
                   system("color 0C");
                    printf("\a");               
                                   printf("\n\n\n\n\n\n\n\n\n\t\t***************************   ARQUIVO INEXISTENTE ");
                                   printf("  ****************************** ");
                   for(i=0;i<7;i++)
                   {
                      if((i%2)==0)
                      {system("color 0C");   Sleep(100);
                                             
                      }
                      else
                       {   system("color FC");  Sleep(100);
                       printf("\a");    
                       }
                   }
                                   Sleep(1000);
                                   fflush(stdin);
                                   
                                  
                  fflush(stdin);                
                  return menu();
                 }
    system("cls");
    printf("\n\n\n");
    while((caracter=getc(ponteiro))!=EOF){
                                          printf("%c",caracter);
    }
    fclose(ponteiro);
    
    
   }
    printf("\n\n\t *** Digite:\n\n\t1-Delete   ou qualquer tecla para voltar ao menu anterior.\n\n\t# ");
    fflush(stdin);
    scanf("%c",&esc);
    fflush(stdin);
    
    if(esc=='1')
    {
    remove(nome);
    printf("\n\n\t ***** ");
    system("pause");
    fflush(stdin);
    menu();
    }
    
    else
    {
    printf("\n\n\t ***** ");
    system("pause");
    fflush(stdin);
    menu();
    }
}
