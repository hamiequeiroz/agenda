#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct agenda {
       char nome[30];
       int tel,cel;
       int vazio; 
}x[100];

void menu();
void cadastrar();
void pesquisar();
void exibir();
void zerar();
int verifica_pos();
void alterar();
void ordenar();
void excluir();
int verifica_nome(char y[]);
void estado();
//--------------PRINCIPAL___________________________

int main ()
{
  
    
    menu();
    
    printf("\n\nFinalizadoo\n\n Aperte enter para sair \n\n");
    
    getch();   
    return 0;
}
//-----------zera todos para demonstrar q esta vazia
void zerar() {      //Modo de saber em qual registro falta ser prenchido
int cont;
for (cont=0;cont<=100;cont++)
    x[cont].vazio=0; 
}
//-------------Verificar posicao vazia
int verifica_pos() {             //RETORNA O VALOR DO ULTIMO REGISTRO VAZIO PARA SER PRENCHIDO
int cont=0;
while (cont<=100) {
      if (x[cont].vazio==0)
         return(cont);
      cont++;    
}
return(-1);
}
//------------------excluirrr
void excluir() 
{
     int  cont=0,t;
     char aux[30];
     
     printf("\n\nAgenda Telefonica  Menu Excluir Contato\n Digite o nome do Contato\n");
     scanf("%s",aux);

    while (cont<=100) 
    {
          if (strcmp(x[cont].nome,aux)==0)
          
             if (x[cont].vazio==1) 
               {
                x[cont].vazio=0;
                  printf("\nExclusao feita com sucesso\n");
                              
                  break;
                 }  
               cont++;
          if (cont>100)
               printf("\nNome nao encontrado\n");             
          
     }
}
 //---------------------ORDENARRRRR                    
                     
void ordenar()
{
    int j,k;
    char temp[30];          
              
    for (j=0;j<100;j++ )
     {
      for (k=0;k<99;k++)               
      {
         if (x[k+1].vazio==1) 
         {
        
         if ((strcmp(x[k].nome,x[k+1].nome)) == 1)
         {
              strcpy(temp,x[k+1].nome);
              strcpy(x[k+1].nome,x[k].nome);
              strcpy(x[k].nome,temp);         
                                                                
                                            
                                            
                                            
         }                                
         }                                                      
      
      }
      
     } 
      
              
}

//------------------PESQUISAR

void pesquisar()
{
int cont=0;
char n[30];
printf("\nEntre com o nome\n");
scanf("%s",n);
while(cont<100) {
               
    if (strcmp(x[cont].nome,n)==0) {
      
          printf("\nNome: %s",x[cont].nome);
          printf("\nTelefone: %d",x[cont].tel);
          printf("\nTelefone: %d",x[cont].cel);
          break;
       
    }
    cont++;
    if (cont>100)
       printf("\nNome nao encontrado\n"); 
}                         
}


//__________________________CADASTRAR

int verifica_nome(char y[]) {
int cont=0;
while (cont<=100) {
   if (strcmp(x[cont].nome,y)==0)
      return 0;
   cont++;
}

return 1;
}
void cadastrar()
{  
    int n=0,p,a;
    char aux[30]; 
    int cont=0;
    p=verifica_pos();
         if (p!=-1)
         {
                
                printf("\n Digite o Nome: ");
                
                scanf("%s",aux);
                a=verifica_nome( aux);   
                while(a==0)
                {
                        printf("Nome Ja existente\n");
                        printf("\n Digite o Nome: ");
                        scanf("%s",&aux);
                        a=verifica_nome(aux);
                    
                }
                
               if(a!=0)
                {
                strcpy(x[p].nome,aux);
                printf("\nDigite o telefone residencial: ");
                scanf("%d",&x[p].tel);
                printf("\nDigite o telefone celular: ");
                scanf("%d",&x[p].cel);
                x[p].vazio=1;
                }
         }else
                               printf("\nA agenda esta cheia\n");
                  
                 

}
//----------------------------MENU Principal
void menu()
{
   int op,aux;
   
                                  
   do{
     system("cls");
                   printf(" Autor: Hamie Queiroz Tomas\n\nAgenda Telefonica %c Menu Principal\n", 45);
                   printf(" \n\nOpcoes:\n\n", 45);
                   printf(" 1 %c Inserir Contato\n", 45);
                   printf(" 2 %c Excluir Contato\n", 45);
                   printf(" 3 %c Alterar Contato\n", 45);
                   printf(" 4 %c Pesquisar Contato\n", 45);
                   printf(" 5 %c Exibir Contatos\n", 45);
                   printf(" 6 %c Exibir Estado da Agenda\n", 45);
                   printf(" 7 %c Sair\n", 45);
                                  
                                  
    printf("\n Digite uma opcao:");
    scanf(" %d",&op);
    
    if(op<1  || op>7)
    {
             system("cls");
             printf("**************Opcao invalida!!!****************\n");
             sleep(2000);
    }
    }
    while(op<1  || op>7);
    
    switch(op) 
    {
                      case 1: 
                      {       
                              cadastrar(); 
                              do{
                              system("cls");
                              printf("pressione 0 para Voltar ao Menu Principla: ");
                              scanf("%d",&aux);
                              if(aux==0)
                              menu(); 
                              else
                                  printf("\a");
                                  
                              }while(aux!=0);
                      } 
                      break;
                      case 2:
                             {
                               excluir();
                                do{
                              printf("\n\n ");
                              
                              printf("Pressione 0 para Voltar ao Menu Principal: ");
                              scanf("%d",&aux);
                              if(aux==0)
                              menu(); 
                              else
                                  printf("\a");
                                  system("cls");
                                  
                              }while(aux!=0);
                      }                               
                      break;        
                      case 3:
                           {
                             alterar();                
                             do{
                              printf("\n\n ");
                              
                              printf("Pressione 0 para Voltar ao Menu Principal: ");
                              scanf("%d",&aux);
                              if(aux==0)
                              menu(); 
                              else
                                  printf("\a");
                                  system("cls");
                                  
                              }while(aux!=0);
                      }                 
                       break;                      
                      case 4:
                           {
                           pesquisar();
                           do{
                              printf("\n\n ");
                              
                              printf("Pressione 0 para Voltar ao Menu Principal: ");
                              scanf("%d",&aux);
                              if(aux==0)
                              menu(); 
                              else
                                  printf("\a");
                                  system("cls");
                                  
                              }while(aux!=0);
                      } 
                      break;
                      case 5:
                      {
                             exibir();
                             do{
                              printf("\n\n ");
                              
                              printf("Pressione 0 para Voltar ao Menu Principal: ");
                              scanf("%d",&aux);
                              if(aux==0)
                              menu(); 
                              else
                                  printf("\a");
                                  system("cls");
                                  
                              }while(aux!=0);
                      } 
                      break;
                      case 6:
                      {
                             estado();
                             do{
                              printf("\n\n ");
                              
                              printf("Pressione 0 para Voltar ao Menu Principal: ");
                              scanf("%d",&aux);
                              if(aux==0)
                              menu(); 
                              else
                                  printf("\a");
                                  system("cls");
                                  
                              }while(aux!=0);
                      } 
                      break;
                      case 7:
                      {
                           printf("\nFim do Programa\n");
                      break;    
                      }  
                                               
    }
    
     
                 
}
//-----------------ALTERARR
void alterar()
{
     char n[30],aux[30];
     int cont=0,a;
     printf("\nDigite o nome Que deseja alterar na agenda: "); 
     scanf("%s",n); 
     while(cont<100) {
               
                if (strcmp(x[cont].nome,n)==0) {
      
                printf("\n Digite o Novo Nome: ");
                scanf("%s", &aux);
                a=verifica_nome( aux);   
                while(a==0){
                        printf("Nome Ja existente\n");
                        printf("\n Digite o Novo Nome: ");
                        scanf("%s",&aux);
                        a=verifica_nome(aux);
                    
                }
                strcpy(x[cont].nome,aux);
                printf("\nDigite o telefone residencial: ");
                scanf("%d",&x[cont].tel);
                printf("\nDigite o telefone celular: ");
                scanf("%d",&x[cont].cel);
     
                break;
       
                }
                cont++;
                if (cont>100)
                 printf("\nNome nao encontrado\n"); 
      }      
                
}
//---------------ESTADO DA AGENDA
void estado()
 {
     int cont=0,c=0,v=0;
 
     while (cont<=99) {
        if (x[cont].vazio==1)
                 v++;            
      cont++;    
      }   
      printf("%d pessoas cadastradas na agenda\n\n",v);
      if(v<100)
      printf("Voce ainda pode cadastrar %d pessoas\n\n",100-v);   
      else
           printf("Agenda esta cheia");   
                  
}
//----------------EXIBIR CONTATOS
void exibir()
 {
     int cont=0,p;
     ordenar(); 
    
     while(cont<=100)     
     {
         if(x[cont].vazio==1)
         {
          printf("\n\t | Nome: %s\n",x[cont].nome);
          printf("\t | Telefone: %d\n",x[cont].tel);
          printf("\t | Celular: %d\n",x[cont].cel);                            
         
         }                                 
     cont++;
     } 
                        
}
