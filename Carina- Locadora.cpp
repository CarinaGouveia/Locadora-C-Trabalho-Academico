#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAM 2000

struct reg_Filmes{
int codigo;
char filme[200];	
char situacao[200];
char genero[200];
	
};
int main(){
struct reg_Filmes Filmes[TAM];
int i,op,contador=0,buscaCod,n,cot,cot2,cot3,cot4,x,cot5;
int aux[200];
char nome[200];

     for (i=0; i<contador; i++)
     {
     	 aux[i]=0; 
	 }
       do {

    printf("\n___________Sistema ______________");
    printf("\n|                               |");
    printf("\n| 1- Cadastrar Filmes           |");
    printf("\n| 2- Relatorio todos os filmes  |");
    printf("\n| 3- Locacao                    |");
    printf("\n| 4- Devolucao                  |");
    printf("\n| 5- consultar filmes           |");
    printf("\n| 6- consultar por genero       |");
    printf("\n| 0- sair                       |");
    printf("\n|_______________________________|\n\n");
    printf("\nOpcao: ");
    fflush(stdin); scanf("%d",&op);
    
    switch (op)
      {
      	case 1 : // CADASTRO okkkkkkk
      	 cot5=0;
		 if (contador<TAM)
	     	{	
	           printf("\nDigite Codigo do filme: ");
               scanf("%d",&x);
               cot5=0;
               for (i=0; i<contador; i++)
                {
                 if (x == Filmes[i].codigo)
                { 
               printf("\n|codigo indisponivel");
               cot5=1;
			    }
                }
	       		if(cot5==0)
	      		 { 
		   			Filmes[contador].codigo=x;
	       			printf("\nDigite o nome do filme : ");
           			fflush(stdin); gets(Filmes[contador].filme);
           			printf("\nDigite o genero do filme : ");
          			 fflush(stdin); gets (Filmes[contador].genero);
		  			 strcpy( Filmes[contador].situacao, "Disponivel");  
		   	   	 }
		         contador++;
		     
     	    }
     	   
         else
		 {  
          printf("\nIMPOSSIVEM REALIZAR NOVOS CADASTROS");
         }
         break;
       
         case 2: 
         	
          printf("\n______________Relatorio de Todos os filmes_________________ ");
          printf("\n|                                                          |");
          printf("\n|filme    |      genero      |       situacao    |   codigo|");
		  for (i=0; i<contador; i++)
		  {
		   printf("\n %-15s %-19s %-15s %i ",Filmes[i].filme,Filmes[i].genero,Filmes[i].situacao,Filmes[i].codigo);    
          }
			   
		  break;
		   
		  case 3: 
		  printf("\n ______________Locacao____________ ");
          printf("\n|                                 |");
          printf("\n|Insira  o codigo do filme        |\n");
          
          scanf("%i",&n);
		  cot=0;
          for (i=0; i<contador; i++)
		  {  if (n == Filmes[i].codigo)
		     { 
		        if (aux[i]==1)
		          {
		        	 printf("indisponivel");
				  } 
		     
                if (aux[i]==0)
		       	  {	
            		 printf("LOCACAO REALIZADA CM SUCESSO");
             		 strcpy( Filmes[i].situacao, "Alugado");
             		 aux[i]=1;
		    	  }   
		    	 cot=1; 
			 }
			        
           }
                 if (cot==0)
                 {
                 	   printf("Codigo nao cadastrado\n");
				 }
          break;

          case 4: 
            	 printf("\n _________Devolucao________ ");
          printf("\n|                                 |");
          printf("\n|Insira  o codigo do filme        |\n");
          scanf("%d",&n);  
          cot2=0;    
         for (i=0; i<contador; i++)
		  {  
		     if (n == Filmes[i].codigo)
		       { 
		         if (aux[i]==0)
		       	  {	
            		printf("Esse filme nao consta para devolucao");
		          } 
		         
		        if (aux[i]==1)
		          {
		        	 printf("devolucao feita com sucesso");
		        	 strcpy( Filmes[i].situacao, "Disponivel");
		        	 aux[i]=0;
				  } 
				   cot2=1; 
			    } 
		  }
              if (cot2==0)
                 {
                 	printf("Codigo nao cadastrado\n");
				 }
           
            break;

            case 5: 
          printf("\n____________________Consulta de  filmes___________________");
          printf("\n|                                                         |");
          printf("\n| digite o codigo do filme                                |\n");
          scanf("%d",&n);
          cot4=0;
          for (i=0; i<contador; i++)
           {
             if (n == Filmes[i].codigo)
             { 
               printf("\n|filme    |      genero      |       situacao   |   codigo|");
               printf("\n %-15s %-19s %-15s %i ",Filmes[i].filme,Filmes[i].genero,Filmes[i].situacao,Filmes[i].codigo); 
               cot4=1;
			 }
             
	       }
	       if(cot4==0)
	       { printf("\n codigo nao cadastrado ");
		   }
         
            break;
            
           case 6: 
          printf("\n____________________Consulta por genero___________________");
          printf("\n|                                                         |");
          printf("\n| digite o genero do filme                                |\n");
          fflush(stdin);
		  scanf("%s",nome);
		  cot3=0;
		  printf("\n|filme    |      genero      |       situacao   |   codigo|");
          for (i=0; i<contador; i++)
           {
             if(strcmp(Filmes[i].genero, nome)==0)
             	{
                  printf("\n %-15s %-19s %-15s %i ",Filmes[i].filme,Filmes[i].genero,Filmes[i].situacao,Filmes[i].codigo); 
                  cot3=1;
				}
				
	       }
	         if(cot3==0)
	          { printf("\nNada consta");
			  }
            break;
         

    }//swicth
 }while(op!=0);
}//fim
