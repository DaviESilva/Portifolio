/* PROJETO INTEGRADO MULTIDISCIPLINAR - UNIVERSIDADE PAULISTA II SEMESTRE */

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Ususários já Cadastrados no sistema:

//Usuário 1
const char usuario1[80] = "admin";
const char senha1[80] = "admin";

//Cupom para aplicar desconto de 50% em todos os produtos
const char promo1[30] = "blackfriday";
int promoApl;


//Variáveis Globais
int logado;

int pedidosFeitos;
float totalGanho;

char fRelatorio[1000];
char fREInicial[200];


//Pedidos
typedef struct 
{
			char prato[300];
			char clienteNome[50];
			char clienteEnd[50];
			char clienteTel[50];
			float valorPedido;
			int Vago; 	//0 = vazio / 1 = ocupado
} PedidoType;

 PedidoType pedido[5]; 

//Clientes		
typedef struct 
{
			char Nome[50];   
			char End[50];
			char Tel[50];
			int Vago; 	//0 = vazio / 1 = ocupado
} ClienteStr;

 ClienteStr cliente[5]; 

//Estoque
typedef struct 
{
			char produto[50];   
			int quantidade;
			char unidade[30];
			
			unsigned int Vago; 	//0 = vazio / 1 = ocupado
} EstoqueType;

 EstoqueType estoque[7]; 

//SAC
typedef struct 
{
			char mensagem[350];   
		
			unsigned int Vago; 	//0 = vazio / 1 = ocupado
} elogios;

 elogios SAC[4]; 


 //funcionários já pré cadastrados
     char nome1[50] = "Davi E. Silva";
     char cpf1[50] = "101.666.420-69";
	 char tel1[50] = "(11) 94002-8922";
     
     
     char nome2[50] = "Branda Tchimpolo";
     char cpf2[50] = "159753268-XX";
	 char tel2[50] = "(11) 85296-3147";
	 
	 char nome3[50] = "Gustavo Chancha";
	 char cpf3[50] = "123-456-789-XX" ;
	 char tel3[50] = "(11) 24895-1324";
     
     //funcionário livre
     		char nome4[50] = " ";
			char cpf4[50] = " ";
			char tel4[50] = " ";
			

//produtos a serem usados
	    char FrangoCatupiry [50] = "Pizza de Frango e Catupiry \nValor = R$25,00\n";
        char Mussarela [50] = "Pizza de Mussarela \nValor = R$22,00\n";
        char Calabresa [50] = "Pizza de Calabresa \nValor = R$20,00\n";
	    char CocaCola [50] = "Coca-Cola  \nValor = R$10,00\n";
        char Dolly [50] = "Dolly Guaraná  \nValor = R$6,00\n";
        char Fanta [50] = "Fanta Laranja \nValor = R$8,00\n";

			
//Funções a serem usadas:
//Cores a serem usadas nos textos
void amarelo();
void vermelho();
void verde();
void azul();
void azulV();
void lilas();

//Funções
void cabecalho();

void login();

int menu();


void Pedido();

void clientes();

void promo();

void Estoque();
void ListarEstoque();

void produtos();
void listarProdutos();

void funcionario();
void ListarFuncionario();

void Relatorio();
void MostrarRelatorio();

void sac();

FILE *ponteiro; //Criação de arquivo para guardar os relatórios

//FUNÇÃO PRINCIPAL ***(MAIN)***
int main()
{
setlocale(LC_ALL, "Portuguese"); //Declaração de linguagem

//Clientes 
//clientes já pré-cadastrados no sistema
			strcpy(cliente[0].Nome, "Branda");
			strcpy(cliente[0].End, "Rua Angola, 69 - Bairro da Mata | SP");
			strcpy(cliente[0].Tel, "(11) 97070-7070");
			cliente[0].Vago = 1;   
			
			strcpy(cliente[1].Nome, "Pietro");   //cliente 2
			strcpy(cliente[1].End, "Rua Augusta, 69 - Bela vista SP");
			strcpy(cliente[1].Tel, "(11) 4002-8922");
			cliente[1].Vago = 1;

//Produtos do estoque
			
		

			strcpy(estoque[0].produto , "Coca-Cola");
			estoque[0].quantidade = 20;
			strcpy(estoque[0].unidade, "Garrafas");
			estoque[0].Vago = 1;
			
			strcpy(estoque[1].produto, "Dolly");
			estoque[1].quantidade = 15;
			strcpy(estoque[1].unidade, "Garrafas");
			estoque[1].Vago = 1;
			
			strcpy(estoque[2].produto, "Fanta");
			estoque[2].quantidade = 10;
			strcpy(estoque[2].unidade, "Garrafas");
			estoque[2].Vago = 1;
			
			strcpy(estoque[3].produto, "Frango");
			estoque[3].quantidade = 2000;
			strcpy(estoque[3].unidade, "Gramas");
			estoque[3].Vago = 1;
			
			strcpy(estoque[4].produto, "Catupiry");
			estoque[4].quantidade = 1000;
			strcpy(estoque[4].unidade, "Gramas");
			estoque[4].Vago = 1;
			
			strcpy(estoque[5].produto, "Mussarela");
			estoque[5].quantidade = 6000;
			strcpy(estoque[5].unidade, "Gramas");
			estoque[5].Vago = 1;
			
			strcpy(estoque[6].produto, "Calabresa");
			estoque[6].quantidade = 5000;
			strcpy(estoque[6].unidade, "Gramas");
			estoque[6].Vago = 1;

	strcpy(fREInicial, "Coca-Cola\n20 Garrafas\n\nDolly\n15 Garrafas\n\nFanta\n10 Garrafas\n\nFrango\n2000 Gramas\n\n");
	strcat(fREInicial, "Catupiry\n1000 Gramas\n\nMussarela\n6000 Gramas\n\nCalabresa\n5000 Gramas\n");
	
 system("cls"); //limpa a tela
cabecalho();  //Exibe o cabeçalho na tela

			
login();
if (logado==1)
 {
 	menu();
 }

	return 0;
}
//FIM DA FUNÇÃO PRINCIPAL ***(MAIN)***

void amarelo(void){
system("color E"); //Declaração de cor Amarela para melhor visualizção pelo usuário
return;
}

void vermelho(void){
 system("color FC"); //Declaração de cor Vermelha para melhor visualizção pelo usuário
 return;
}

void verde(void){
 system("color A"); //Declaração de cor Verde para melhor visualizção pelo usuário
 return;
}

void azul(void){
 system("color B"); //Declaração de cor Azul para melhor visualizção pelo usuário
 return;
}

void azulV(void){
 system("color 1B"); //Declaração de cor Verde-água claro e fundo Azul para melhor visualizção pelo usuário
 return;
}

void lilas(void){
system("color 0D"); //Declaração de cor Lilás para melhor visualizção pelo usuário
return;
}

void cabecalho(){
verde();

system("title PIM UNIP - Pizzaria Los Hermanos");
printf("----------------------------------------------\n");
printf("     Projeto Integrado Multidisciplinar\n");
printf("   Projeto para controle de uma pizzaria\n");
printf("----------------------------------------------\n");

printf("\nBoas vindas a pizzaria dos Los Hermanos!!!\n\n\n");
printf("Por favor prossiga para a tela de login!\n\n");
system("pause");
system("cls");
return;
}

void login(){
char usuario[80] = "zerado";  //váriaveis de login começão sem conexão
char senha[80] = "zerado";  //váriaveis de login começão sem conexão
logado=0; //garante que o usuário começe deslogado

 do {
  	
  
  printf("\nInforme o login");
  printf("\n\nLogin: ");
  gets(usuario);
  
  printf("\nInforme a senha");
  printf("\n\nSenha: ");
  gets(senha);  
  
 system("cls"); //limpa a tela
 
 if (!strcmp(usuario,usuario1) == 0 || !strcmp(senha,senha1)== 0); //Verifica se você errou uma das senha cadastradas e pede para tentar novamente
 {
 logado=0;
 	vermelho(); //cor vermelha
 printf("\nUsuário ou senha inválidos!!!");
 printf("\nPor favor tente novamente\n");
 }
 
}
while (!strcmp(usuario,usuario1) == 0 || !strcmp(senha,senha1)== 0);  //Mantem o usuário nesse laço enquanto não logar com sucesso
	azul(); //cor azul
 system("cls"); //limpa a tela
printf("\nUsuário logado com sucesso");
printf("\nSeja bem vindo: %s \n", usuario); //exibe uma mensagem de boas vindas e coloca o nome do usuário nela
logado=1;

return;
}

int menu(){ 
	int Opcao; //Variável para escolha de opção do menu principal
	  do
    {
    	system("cls");
    		amarelo();
		printf("\n --- Menu Principal --- \n");
    	printf("Por favor selecione uma opção:\n\n");
        	
		printf("1 - Pedidos\n"); 
        printf("2 - Clientes\n");
        printf("3 - Promoções\n");
        printf("4 - Estoque\n");
        printf("5 - Produtos\n");
        printf("6 - Funcionários\n"); 
        printf("7 - Relatórios\n");
        printf("8 - Elogios e Reclamações\n");
		printf("9 - Sair\n\n");
       
	
        scanf("%d", &Opcao);
        getchar();
        if (Opcao == 1)
        {
           	  system("cls"); // Limpa a Tela
           	  verde();
		
            Pedido();
            
        }
        else if (Opcao == 2)
        {
              clientes();
        }
                
        else if (Opcao == 3)
        {
        	   system("cls"); // Limpa a Tela
        	   azul();
            printf("Você selecionou a opção 3 - Promoções\n");
            promo();
            
        }
        else if (Opcao == 4)
        {
        	   system("cls"); // Limpa a Tela
        	azulV();
            printf("Você selecionou a opção 4 - Estoque\n");
         	Estoque();
        }
        else if (Opcao == 5)
        {
       
	        	system("cls"); // Limpa a Tela
	           	verde();
            printf("Você selecionou a opção 5 - Produtos\n");
            produtos();
          
        }
        else if (Opcao == 6)
        {
        	   system("cls"); // Limpa a Tela
        	   verde();
            printf("Você selecionou a opção 6 - Funcionários\n");
            funcionario();
            
        }
        else if (Opcao == 7)
        {
        	   system("cls"); // Limpa a Tela
        	   lilas();
            printf("Você selecionou a opção 7 - Relatórios\n");
            Relatorio();
        }
        else if (Opcao == 8)  // SAC
        {
        	   system("cls"); // Limpa a Tela
        	   verde();
        	   sac();
            
          
        }
        else if (Opcao == 9)  //SAIR
        {
        	   system("cls"); // Limpa a Tela
        	   vermelho();
            printf("Você selecionou a opção 9 - Sair\n\n");
            system("pause");
            system("exit");
            
        }
        else{
        	vermelho();
            printf("\nOpção invalida!!! Por favor pressione enter para voltar ao menu principal\n");
            getchar();
            system("cls");
        }
        }    while (Opcao != 9 );
}

void clientes(){
	azul();
	system("cls"); // Limpa a Tela
			int OpcaoCliente;			
				
		    do{
            printf("Você selecionou a opção 2 - Clientes\n");
          	printf("Por favor selecione uma opção:\n\n");
           
		    printf("1 - Listar todos os clientes\n");
            printf("2 - Novo Cliente\n");
            printf("3 - Excluir Cliente\n");
            printf("4 - Editar Cliente\n");
            printf("5 - Voltar ao menu principal\n");
           
		    scanf("%d", &OpcaoCliente);
            getchar();
                 
                if(OpcaoCliente == 1){
                	
                system("cls");
                printf("Exibindo todos os Clientes cadastrados no sistema:\n\n");    	
				printf("-------------------------------\n");
				
				int i;
				
				for (i=0; i<6; i++){
			
					if(cliente[i].Vago == 1){
			
				printf("\nCliente %i \n",i);
                printf("  \n%s \n\n %s \n\n %s \n\n", cliente[i].Nome, cliente[i].End, cliente[i].Tel);
            	printf("-------------------------------\n");
            
            		}
            		
				}
				system("pause");
				system("cls");
				
                }
                else if(OpcaoCliente == 2){
                system("cls");
                printf("Procurando locais para armazenar o novo cliente...\n\n");
                
                int i;
				for (i=0; i<8; i++){
					if(cliente[i].Vago == 0){
						
					printf("Insira os dados para o novo cliente.\n ");
					printf("\nNome: ");
					gets(cliente[i].Nome);
					
					printf("\nEndereço: ");
					gets(cliente[i].End);
					
					printf("\nTelefone: ");
					gets(cliente[i].Tel);
					
					cliente[i].Vago = 1;
					printf("Cliente cadastrado com sucesso no sistema!\n\n");
					break;
					}
					
					else if(i == 7){
					vermelho();
					printf("\nNenhum Cliente vago disponível no momento!!!\nÉ necessária a exclusão de um cliente.");
					system("pause");
					}
					          	}	
				}
                else if(OpcaoCliente == 3){
                   system("cls");
				   int OpcaoExcluir;
				   
				   printf("Por favor escolha um cliente para excluir: \n");	 
				     int i;
				
				for (i=0; i<6; i++)
				{
			
					if(cliente[i].Vago == 1)
					{
			
				printf("\nCliente %i \n",i);
                printf("  \n%s \n", cliente[i].Nome);
                printf("-------------------------------\n");
            		}
        		}
        			
        			printf("\nCliente: ");
				   scanf("%i", &OpcaoExcluir);
				   if(cliente[OpcaoExcluir].Vago == 0)
						{
							printf("Opcao Inválida!\nVoltando ao menu \n\n");
							system("pause");
				
						}
				   else 
				   {
				   system("cls");
				   amarelo();
				   printf("\nO cliente %s foi excluido com sucesso!!!\n\n", cliente[OpcaoExcluir].Nome);
				   strcpy(cliente[OpcaoExcluir].Nome, " ");
				   strcpy(cliente[OpcaoExcluir].End, " ");
				   strcpy(cliente[OpcaoExcluir].Tel, " ");
				   cliente[OpcaoExcluir].Vago = 0;				   
				   }
                }
                else if(OpcaoCliente == 4){  //EDITAR
                system("cls");
                int OpcaoEditar,OpcaoEditar2;
                
                    printf("Por favor escolha um cliente para editar: \n");	 
				
				int i; //EXIBIÇÃO DOS CLIENTES
				
				for (i=0; i<6; i++)
				{
			
					if(cliente[i].Vago == 1)
					{
			
				printf("\nCliente %i \n",i);
                printf("  \n%s \n", cliente[i].Nome);
                printf("-------------------------------\n");
            		}
        		}
        		
        		scanf("%i", &OpcaoEditar);
					if (cliente[OpcaoEditar].Vago == 0){   //se o cliente é valido
						printf("Opcao Inválida!\nVoltando ao menu \n\n");
						system("pause");
				}
				else
				{
        		system("cls");
        		   printf("Cliente %s selecionado", cliente[OpcaoEditar].Nome);
                   printf("Por favor selecione uma opção que desja editar:\n\n");
           
		   	      printf("1 - Nome do cliente\n");
          		  printf("2 - Endereço do Cliente\n");
          		  printf("3 - Telefone do Cliente\n");
          		scanf("%i", &OpcaoEditar2);
          		system("cls");
          		
          		if (OpcaoEditar2 == 1)
				  {
				  	printf("Insira o novo Nome\n");
				  	printf("Nome: ");
				  	gets(cliente[i].Nome);
				  	
					printf("\n\nDado alterado com sucesso!!!\n");
					system("pause");
          		  }
          		else if (OpcaoEditar2 == 2)
				  {
				  	printf("Insira o novo Endereço\n");
				  	printf("Endereço: ");
				  	scanf("%s", &cliente[i].Nome);
				  	
				  	printf("\n\nDado alterado com sucesso!!!\n");
				  	system("pause");
          		  }
          		
				else if (OpcaoEditar2 == 2)
				  {
				  	printf("Insira o novo Telefone\n");
				  	printf("Telefone: ");
				  	scanf("%s", &cliente[i].Nome);
				  	
				   	printf("\n\nDado alterado com sucesso!!!\n");
				   	system("pause");
          		  }
          		else
				  {
          			printf("Opcao Inválida!\nVoltando ao menu \n\n");
				  }
				}
			       		
                }
                else if(OpcaoCliente == 5){
                	system("cls");
                    printf("Você selecionou voltar ao menu principal, pressione ENTER para continuar");
                    getchar();
                    system("cls");
                }
                else if(OpcaoCliente > 5 || OpcaoCliente < 1)
				{
                system("cls");
                vermelho();
                    printf("Opcao Inválida!\nVoltando ao menu \n\n");
                    
                system("pause");
				}
				    
    }while(OpcaoCliente =!5 || OpcaoCliente > 5 || OpcaoCliente < 0 || OpcaoCliente == 0);
	
}

void promo()
{
	char cupom[30];
	printf("\n\nInsira o seu cupom: \n");
	scanf("%s", &cupom);
	
	
	if (!strcmp(cupom,promo1) == 1) //Verifica se você errou o cupom
 {
 	system("cls");
	printf("\n_________ ***** Parabéns!!! ***** _________\n Seu cupom foi aplicado com sucesso.\n Agora você possui 50%% de desconto em nossa pizzaria!!!\n\n");
 	
	 							promoApl = 1;
	 system("pause");
 	
 		strcpy(FrangoCatupiry, "Pizza de Frango e Catupiry \nValor = R$12,50\n");
       	strcpy(Mussarela, "Pizza de Mussarela \nValor = R$11,00\n");
        strcpy(Calabresa, "Pizza de Calabresa \nValor = R$10,00\n");
	    strcpy(CocaCola, "Coca-Cola  \nValor = R$5,00\n");
        strcpy(Dolly, "Dolly Guaraná  \nValor = R$3,00\n");
       	strcpy(Fanta, "Fanta Laranja \nValor = R$4,00\n");

 }
 	else if (!strcmp(cupom,promo1) == 0)
 	{
  	system("cls");
 	vermelho(); //cor vermelha
 printf("\nCódigo utilizado inválido!!!\n");
 system("pause");
 	}
}

void produtos(){
    system("cls");
	verde();
	int opcaoProduto;  
       
       
	   do{
            printf("Você selecionou a opção 5 - Produtos\n");
          	printf("Por favor selecione uma opção:\n\n");
           
		    printf("1 - Listar todos os produtos \n");
            printf("2 - Listar sómente bebidas\n");
            printf("3 - Listar pizzas\n");
            printf("4 - Voltar ao menu principal\n");
           
		    scanf("%d", &opcaoProduto);
            getchar();
            
                if     (opcaoProduto == 1){
                	
                	listarProdutos();
                	system("pause");
                }
                
                else if(opcaoProduto == 2){
               		system("cls");
			    printf("%s\n", CocaCola);
       			printf("%s\n", Dolly);
          		printf("%s\n\n\n", Fanta);
          			system("pause"); // faz o usuario apertar uma tecla pra continuar
       				system("cls");
                               
                }
                else if(opcaoProduto == 3){
            		system("cls");
				printf("%s\n", FrangoCatupiry);
            	printf("%s\n", Mussarela);
     		 	printf("%s\n\n\n", Calabresa);
                 	system("pause"); // faz o usuario apertar uma tecla pra continuar
       				system("cls");	   
                }
                else if(opcaoProduto == 4){
                	system("cls");
                    printf("Você selecionou voltar ao menu principal, pressione ENTER para continuar");
                    getchar();
                    system("cls");
                }
                else
                    printf("Opcao Inválida\n\n");
    }while(opcaoProduto =!4 || opcaoProduto > 4 || opcaoProduto < 0 || opcaoProduto == 0);
	
}

void listarProdutos()
{
                	
                	system("cls");
                printf("1 - %s\n", CocaCola);
       			printf("2 - %s\n", Dolly);
          		printf("3 - %s\n", Fanta);
           		printf("4 - %s\n", FrangoCatupiry);
            	printf("5 - %s\n", Mussarela);
     		 	printf("6 - %s\n\n\n", Calabresa);
     		      // faz o usuario apertar uma tecla pra continuar
     		        
}

void funcionario ()
{
     system("cls"); // Limpa a Tela
     
    
			
			int OpcaoFuncionario;
			

            do{

            printf("Você selecionou a opção 6 - Funcionários\n");
          	printf("Por favor selecione uma opção:\n\n");

		    printf("1 - Listar Funcionários\n");
            printf("2 - Adicionar funcionário\n");
			printf("3 - Excluir funcionário\n");
            printf("4 - Editar Funcionário\n");
            printf("5 - Voltar ao menu principal\n\n");
            scanf("%d", &OpcaoFuncionario);
            getchar();
                 
				 
				 if(OpcaoFuncionario == 1)
				 {
				 	
                  system("cls");
                  printf("Funcionários: \n\n");
                  
                 	ListarFuncionario(); 	
				 }
                
                    else if(OpcaoFuncionario == 2){
                                 
                  
                   	system ("cls");
                 	printf("Você selecionou adicionar um novo funcinário!\n");
                 	
                 	printf("Insira o CPF: \n");
                 	scanf("%s",&cpf4);
                 	printf("CPF: %s\n\n",cpf4);

                 	printf("Insira o Nome: \n");
                 	scanf("%s",&nome4);
                 	printf("Nome: %s\n\n",nome4);
                 	
                 	printf("Insira o Telefone: \n");
                 	scanf("%s",&tel4);
                 	printf("Telefone: %s",tel4);
                 	
					system("cls");
					
					printf("\nFuncionário criado: \n \n");
					printf("\nNome: %s\n",nome4);
					printf("CPF: %s\n",cpf4);
					printf("Telefone: %s\n\n",tel4);
					
					printf("Pressione ENTER para continuar\n");
                    system("pause");
                    system("cls");
                
            }
                else if(OpcaoFuncionario == 3)
				{
                   int opcExcluir;
       				 ListarFuncionario();
					char resposta = 'o';
					printf("\nSelecione um funcionario para excluir ou tecle 5 para excluir todos\n");
        		scanf("%d",&opcExcluir);
    

            if(opcExcluir == 1){
               printf ("\nDeseja realmente excluir o funcionario? (S/N)\n");
               getchar();
                scanf("%c", &resposta);
                resposta = toupper(resposta);

                if(resposta == 'S'){
                	
                			strcpy(nome1," ");
                			strcpy(tel1, " ");
                			strcpy(cpf1, " ");
                	
						system("cls");
						printf("Funcionario 1 excluido com sucesso!\n");
						system("pause");	
                	printf("Pressione qualquer tecla para continuar");
				}


			}
					else if(opcExcluir == 2)
				{
				printf ("\nDeseja realmente excluir o funcionario? (S/N)\n");
                getchar();
                scanf("%c", &resposta);
                resposta = toupper(resposta);

                if(resposta == 'S')
				{
                	
                			strcpy(nome2 , " ");
                			strcpy(tel2 , " ");
                			strcpy(cpf2 , " ");
                	
						system("cls");
						printf("Funcionario 2 excluido com sucesso!\n");
						system("pause");	
                	printf("Pressione qualquer tecla para continuar");
	
					}

				}
				else if(opcExcluir == 3){
					printf ("\nDeseja realmente excluir o funcionario? (S/N)\n");
                	getchar();
                	scanf("%c", &resposta);
                	resposta = toupper(resposta);

                if(resposta == 'S'){
                	
                			strcpy(nome3 , " ");
                			strcpy(tel3 , " ");
                			strcpy(cpf3 , " ");
                	
						system("cls");
						printf("Funcionario 3 excluido com sucesso!\n");
						system("pause");	
                	printf("Pressione qualquer tecla para continuar");
	
	
					}

					}
					else if(opcExcluir == 4){
	
				printf ("\nDeseja realmente excluir o funcionario? (S/N)\n");
               getchar();
                scanf("%c", &resposta);
                resposta = toupper(resposta);

                if(resposta == 'S'){
                	
                			strcpy(nome4 , " ");
                			strcpy(tel4 , " ");
                			strcpy(cpf4 , " ");
                	
						system("cls");
						printf("Funcionario 4 excluido com sucesso!\n");
						system("pause");	
                	printf("Pressione qualquer tecla para continuar");
	
						}
               }
                else if(opcExcluir == 5){
	
					printf ("\nDeseja realmente excluir todos os Funcionarios? (S/N)\n");
					getchar();
    	            scanf("%c", &resposta);
                resposta = toupper(resposta);
               
			    if(resposta == 'S'){
                	
                			strcpy(nome1 , " ");
                			strcpy(tel1 , " ");
                			strcpy(cpf1 , " ");
                			strcpy(nome2 , " ");
                			strcpy(tel2 , " ");
                			strcpy(cpf2 , " ");
                			strcpy(nome3 , " ");
                			strcpy(tel3 , " ");
                			strcpy(cpf3, " ");
                			strcpy(nome4, " ");
                			strcpy(tel4 , " ");
                			strcpy(cpf4 , " ");
                	
						system("cls");
						printf("Todos os funcionários excluidos com sucesso!\n");
						system("pause");	
                	printf("Pressione qualquer tecla para continuar");
					}
                
                }
                
           			 }
                else if(OpcaoFuncionario == 4)
				{
                
                system("cls"); // Limpa a Tela
                
                int editarFuncionario;
				                       
                  ListarFuncionario();
                  
				  	printf("Qual funcionário deseja editar? \n");
				  		scanf("%i", &editarFuncionario);

				  if (editarFuncionario == 1) {

                
                 	printf("################ Você selecionou funcionario 1 ################\n");
                 	printf("Insira o CPF: \n");
                 	scanf("%s",&cpf1);
                 	printf("CPF: %s\n\n",cpf1);

                 	printf("2-Insira o Nome: \n");
                 	scanf("%s",&nome1);            	
                 	printf("3-Nome: %s\n\n",nome1);
                 	
					printf("3-Insira o Telefone: ");
                 	scanf("%s",&tel1);
                 	printf("4-Telefone: %s",tel1);
				  }
					if (editarFuncionario==2){
			
					printf("################ Você selecionou funcionario 2 ################\n");
                 	printf("Insira o CPF: \n");
                 	scanf("%s",&cpf2);
                 	printf("CPF: %s\n\n",cpf2);
                 	
					printf("2-Insira o Nome: \n");
                 	scanf("%s",&nome2);
                 	printf("3-Nome: %s\n\n",nome2);
                 	
					printf("3-Insira o Telefone: ");
                 	scanf("%s",&tel2);
                 	printf("4-Telefone: %s",tel2);
					}
						if (editarFuncionario==3){

					printf("################ Você selecionou funcionario 3 ################\n");
                 	printf("Insira o CPF: \n");
                 	scanf("%s",&cpf3);
                 	printf("CPF: %i\n\n",cpf3);
                 
				 	printf("2-Insira o Nome: \n");
                 	scanf("%s",&nome3);
                 	printf("3-Nome: %s\n\n",nome3);
                 	
					 printf("3-Insira o Telefone: \n");
                 	scanf("%s",&tel3);
                 	printf("4-Telefone: %s",tel3);
					}
					
					if (editarFuncionario==4){

					printf("################ Você selecionou funcionario 4 ################\n");
                 	printf("Insira o CPF: \n");
                 	scanf("%s",&cpf4);
                 	printf("CPF: %s\n\n",cpf4);

                 	printf("2-Insira o Nome: \n");
                 	scanf("%s",&nome4);
                 	printf("3-Nome: %s\n\n",nome4);
                 	
					 printf("3-Insira o Telefone: \n");
                 	scanf("%s",&tel4);
                 	printf("4-Telefone: %s",tel4);
					}
                }

                else if(OpcaoFuncionario == 5){
                	system("cls");
                    printf("Você selecionou voltar ao menu principal\n\nPressione ENTER para continuar");
                    getchar();
                    system("cls");
                }
                else {
                    printf("Opcao Inválida\n\n");
					}
				}
        while(OpcaoFuncionario =!5 || OpcaoFuncionario > 5 || OpcaoFuncionario < 0 || OpcaoFuncionario == 0);
}

void ListarFuncionario(){
                 
            system("cls");
            
			printf("       Funcionarios: \n\n");	 
				  //funcionário 1
                  if (nome1 == " " && tel1 == " " && cpf1 == " ")   {}															    	
			else{
                  printf("Nome: %s\n",nome1);
                  printf("Telefone: %s\n",tel1);
                  printf("CPF: %s\n\n\n",cpf1);
                }
                  
                  //funcionário 2
                  if (nome2 == " " && tel2 == " " && cpf2 == " "){	
              }
              else{
                  printf("Nome: %s\n",nome2);
                  printf("Telefone: %s\n",tel2);
                  printf("CPF: %s\n\n\n",cpf2);
                  }
                  
                  //funcionário 3
                  if (nome3 == " " && tel3 == " " && cpf3 == " "){
			}
			else{
                  printf("Nome: %s\n",nome3);
                  printf("Telefone: %s\n",tel3);
                  printf("CPF: %s\n\n\n",cpf3);	
            	}
            	
				   //funcionário 4  Criado pelo usuário
				  if (nome4 == " " && tel4 == " " && cpf4 == " "){	
			}
				 else{
				  printf("Nome: %s\n",nome4);
                  printf("Telefone: %s\n",tel4);
                  printf("CPF: %s\n\n\n",cpf4);	
              						}
              	       
				  printf("Pressione ENTER para continuar\n");
                  getchar(); 
                }
            

void Pedido(){
  system ("cls");		// limpar tela
  int OpcaoPedido, OpcaoPedido2, OpcaoEditar, OpcaoEditar2, prato, ClientePedido, excluir;
  char resposta, resposta2, resposta3, respostaExcl, respostaConcluir;
  resposta3 = 's';
  
  
  do
    {
      printf("Você selecionou a opção 1 - Pedidos\n");
      printf ("Escolha uma opção: \n\n");

      printf ("1 - Listar pedidos \n");
      printf ("2 - Adicionar pedido \n");
      printf ("3 - Editar pedido \n");
      printf ("4 - Deletar pedido \n");
      printf ("5 - Concluir pedido \n");
      printf ("6 - Voltar ao menu \n");
      scanf ("%d", &OpcaoPedido);
      getchar ();

      if (OpcaoPedido == 1)
	{ 
		system ("cls");
	  printf("Listando os pedidos\n"); 
	  
	 system("cls");
                printf("Exibindo todos os pedidos cadastrados no sistema:\n\n");    	
				printf("-------------------------------\n");
				
				int i;  //Verificação se o pedido é vago
				
				for (i=0; i<6; i++){
			
					if(pedido[i].Vago == 1){
			
				printf("\nPedido %i \n",i);
                printf("  \n %s \n %s \n%s \n%s \n\n",pedido[i].prato, pedido[i].clienteNome, pedido[i].clienteEnd, pedido[i].clienteTel);
                printf("Valor: %.2f\n\n",pedido[i].valorPedido);
            	printf("-------------------------------\n");
            
            		}
            		
				}
	  getchar ();
	  system ("cls");
	}

    else if (OpcaoPedido == 2)
	{
	  
	  printf("Você gostaria de adicionar um novo pedido? (S/N)\n");
	  scanf("%c", &resposta);
	  if (resposta == 'S' || resposta == 's')
	  {
	  system("cls");
	  
	  int i;
				
				for (i=0; i<6; i++)
				{
			
					if(pedido[i].Vago == 0)
					{
	  	
	
	  printf ("Informe o novo pedido \n");
	  
	  listarProdutos();
	  printf("Pedido: ");
	  
	  scanf("%i", &prato);
	  
	  			if (prato == 1)
				{
	  				strcpy(pedido[i].prato,CocaCola);
	  				
	  				estoque[0].quantidade -= 1;  
	  				  if (promoApl == 1)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 5;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 10;
					  }
					 
					
	  			}
	  			else if (prato == 2)
				{
				  	strcpy(pedido[i].prato,Dolly);
				  	estoque[1].quantidade -= 1;  
				  	if (promoApl == 1)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 3;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 6;
					  }
				}
				else if (prato == 3)
				{
					strcpy(pedido[i].prato,Fanta);
					estoque[2].quantidade -= 1;  
					if (promoApl == 1)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 4;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 8;
					  }
				}
				else if (prato == 4)
				{
				  	strcpy(pedido[i].prato,FrangoCatupiry);
				  	estoque[3].quantidade -= 200;  
				  	estoque[4].quantidade -= 100;  
				  	if (promoApl == 1)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 12,5;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 25;
					  }
				}
				else if (prato == 5)
				{
				  	strcpy(pedido[i].prato,Mussarela);
				  	estoque[5].quantidade -= 500;  
				  	if (promoApl == 1)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 11;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 22;
					  }
				}
				else if (prato == 6)
				{
				  	strcpy(pedido[i].prato,Calabresa);
				  	estoque[0].quantidade -= 500;  
				  	if (promoApl == 1)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 10;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 20;
					  }
				}
				
				else if (prato > 6 || prato < 1)
				{
				vermelho();
				printf("Opção Inválida!!!\n\n\n");
				system("pause");
				system("cls");
				}
	

		do {
		system("cls");
		printf("Gostaria de adicionar mais um prato ao pedido?\n (S/N)\n");
		getchar ();
		scanf("%c", &resposta3);
				if (resposta3 == 'S' || resposta3 == 's')
			{
				printf ("\nInforme o próximo prato \n");
	  
	  listarProdutos();
	  printf("Prato: ");
	  scanf("%i", &prato);
	  
	  			if (prato == 1)
				{
					strcat(pedido[i].prato, "\n");
	  				strcat(pedido[i].prato,CocaCola);
	  				estoque[0].quantidade -= 1;  
	  				if (promoApl == 1)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 5;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 10;
					  }
	  			}
	  			else if (prato == 2)
				{
					strcat(pedido[i].prato, "\n");
				  	strcat(pedido[i].prato,Dolly);
				  	estoque[1].quantidade -= 1;  
				  	if (promoApl == 1)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 3;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 6;
					  }
				}
				else if (prato == 3)
				{
					strcat(pedido[i].prato, "\n");
					strcat(pedido[i].prato,Fanta);
					estoque[2].quantidade -= 1;  
					if (promoApl == 1)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 4;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 8;
					  }
				}
				else if (prato == 4)
				{
					strcat(pedido[i].prato, "\n");
				  	strcat(pedido[i].prato,FrangoCatupiry);
				  	estoque[3].quantidade -= 200;  
				  	estoque[4].quantidade -= 100; 
				  	if (promoApl == 1)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 12,5;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 25;
					  }
				}
				else if (prato == 5)
				{
					strcat(pedido[i].prato, "\n");
				  	strcat(pedido[i].prato,Mussarela);
				  	estoque[5].quantidade -= 500;  
				  	if (promoApl == 1)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 11;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 22;
					  }
				}
				else if (prato == 6)
				{
					strcat(pedido[i].prato, "\n");
				  	strcat(pedido[i].prato,Calabresa);
				  	estoque[6].quantidade -= 500;  
				  	if (promoApl == 1)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 10;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[i].valorPedido = pedido[i].valorPedido + 20;
					  }
				}
				
				else if (prato > 6 || prato < 1)
				{
				vermelho();
				printf("Opção Inválida!!!\n\n\n");
				system("pause");
				system("cls");
				}
			}
		}
			while (resposta3 == 'S' || resposta3 == 's');
	
	
	  printf("O cliente já é cadastrado?\n (S/N)\n");
        getchar ();
	  scanf("%c", &resposta2);
 	  if (resposta2 == 'S' || resposta2 == 's')
	   {
	   	system("cls");
 	  	printf("Escolha qual dos clientes fez o pedido:\n\n");
		
		printf("-------------------------------\n");
				
				int j;
				
				for (j=0; j<6; j++)
				{
			
					if(cliente[j].Vago == 1)
					{
			
				printf("\nCliente %i \n",j);
                printf("  \n%s \n\n %s \n\n %s \n\n", cliente[j].Nome, cliente[j].End, cliente[j].Tel);
            	printf("-------------------------------\n");
            		}
            	}
            	
        printf("\n Cliente: ");
        getchar ();
	  scanf("%i", &ClientePedido);
	  
	  if (cliente[ClientePedido].Vago == 1)
	  	{
	  
	  strcpy(pedido[i].clienteNome, cliente[ClientePedido].Nome);
	  strcpy(pedido[i].clienteEnd, cliente[ClientePedido].End);
	  strcpy(pedido[i].clienteTel, cliente[ClientePedido].Tel);
	  printf("\nCliente adicionado ao pedido com sucesso!!\n\n");
	 		pedido[i].Vago = 1;
	 	
		  
	  system("pause");
		}
		else if (cliente[ClientePedido].Vago == 0)
		{
			system("cls");
			vermelho();
			printf("\nCliente escolhido inválido!!\n\n");
			system("pause");
			
		}
		
	   }
		else if (resposta2 == 'N' || resposta2 == 'n')
		{
			printf("Informe o Nome do cliente\nNome: ");
			scanf("%s", &pedido[i].clienteNome);
			printf("%s", pedido[i].clienteNome);
						
			printf("\nInforme o Endereço do cliente\nEndereço: ");
			scanf("%s", &pedido[i].clienteEnd);
			printf("%s", pedido[i].clienteEnd);
			
			
			printf("\nInforme o Telefone do cliente\nTelefone: ");
			scanf("%s", &pedido[i].clienteTel);
			printf("%s", pedido[i].clienteTel);
		 
		 pedido[i].Vago = 1;
		}
		break;
					}
					else
					{
					printf("Nenhum pedido disponivel no momento!!!\nPor favor apague um para continuar!\n\n\n");
					}


	  			}
	  }
	  else 
	  system ("cls");
	  printf("Voltando ao menu!\n");
	  getchar ();
	        system ("cls");

	}
	
	else if (OpcaoPedido == 3)
	{
	 system("cls");
	  printf ("Selecione um pedido para editá-lo \n");	
				printf("-------------------------------\n");
				
				int i;  //Verificação se o pedido é vago
				
				for (i=0; i<6; i++){
			
					if(pedido[i].Vago == 1){
			
				printf("\nPedido %i \n",i);
                printf("  \n %s \n %s \n%s \n%s \n\n",pedido[i].prato, pedido[i].clienteNome, pedido[i].clienteEnd, pedido[i].clienteTel);
            	printf("-------------------------------\n");
            
            		}
            		
				}
	printf("\n\nPedido: ");
 
	  scanf("%i", &OpcaoEditar);	
	   
	  system ("cls");
	  printf("Escolha o que deseja editar: \n");
	  printf("\n1 - Prato");
	  printf("\n2 - Nome do Cliente");
	  printf("\n3 - Endereço");
	  printf("\n4 - Telefone");
	  printf("\n5 - Cancelar\n\n");
	  getchar ();
	  scanf("%i", &OpcaoEditar2);
	  
	 do {
	 	
	 if (OpcaoEditar2 == 1)
	  {
	  	
	  		printf("\nEscolha o novo prato que ficará no pedido\n");
	  		
	  		listarProdutos();
	  		printf("\n\nPrato: ");
			  scanf("%i", &prato);
			  
			  
			  pedido[OpcaoEditar].valorPedido = 0;
			  strcpy(pedido[OpcaoEditar].prato, " ");
			  	  
	  			if (prato == 1)
				{
	  				strcpy(pedido[OpcaoEditar].prato,CocaCola);
	  				estoque[0].quantidade -= 1;  
	  				if (promoApl == 1)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 5;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 10;
					  }
	  			}
	  			else if (prato == 2)
				{
				  	strcpy(pedido[OpcaoEditar].prato,Dolly);
				  	estoque[1].quantidade -= 1;  
				  	if (promoApl == 1)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 3;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 6;
					  }
				}
				else if (prato == 3)
				{
					strcpy(pedido[OpcaoEditar].prato,Fanta);
					estoque[2].quantidade -= 1;  
					if (promoApl == 1)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 4;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 8;
					  }
				}
				else if (prato == 4)
				{
				  	strcpy(pedido[OpcaoEditar].prato,FrangoCatupiry);
				  	estoque[3].quantidade -= 200;  
				  	estoque[4].quantidade -= 100; 
				  	if (promoApl == 1)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 12,5;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 25;
					  }
				}
				else if (prato == 5)
				{
				  	strcpy(pedido[OpcaoEditar].prato,Mussarela);
				  	estoque[5].quantidade -= 500;  
				  	if (promoApl == 1)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 11;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 22;
					  }
				}
				else if (prato == 6)
				{
				  	strcpy(pedido[OpcaoEditar].prato,Calabresa);
				  	estoque[6].quantidade -= 500;  
				  	if (promoApl == 1)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 10;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 20;
					  }
				}
				
				else if (prato > 6 || prato < 1)
				{
				vermelho();
				printf("Opção Inválida!!!\n\n\n");
				system("pause");
				system("cls");
				}
	
		resposta3 = 's';
		
		do {
		system("cls");
		printf("Gostaria de adicionar mais um prato ao pedido?\n (S/N)\n");
		getchar ();
		
	  	scanf("%c", &resposta3);
				if (resposta3 == 'S' || resposta3 == 's')
			{
				printf ("\nInforme o próximo prato \n");
	  
	  listarProdutos();
	  printf("Prato: ");
	  scanf("%i", &prato);
	  
	  			if (prato == 1)
				{
					strcat(pedido[OpcaoEditar].prato, "\n");
	  				strcat(pedido[OpcaoEditar].prato,CocaCola);
	  				estoque[0].quantidade -= 1;  
					  if (promoApl == 1)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 5;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 10;
					  }
					  
	  			}
	  			else if (prato == 2)
				{
					strcat(pedido[OpcaoEditar].prato, "\n");
				  	strcat(pedido[OpcaoEditar].prato,Dolly);
				  	estoque[1].quantidade -= 1;  
				  	if (promoApl == 1)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 3;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 6;
					  }
				}
				else if (prato == 3)
				{
					strcat(pedido[OpcaoEditar].prato, "\n");
					strcat(pedido[OpcaoEditar].prato,Fanta);
					estoque[2].quantidade -= 1;  
					if (promoApl == 1)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 4;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 8;
					  }
				}
				else if (prato == 4)
				{
					strcat(pedido[OpcaoEditar].prato, "\n");
				  	strcat(pedido[OpcaoEditar].prato,FrangoCatupiry);
				  	estoque[3].quantidade -= 200;  
				  	estoque[4].quantidade -= 100; 
				  	if (promoApl == 1)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 12,5;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 25;
					  }
				}
				else if (prato == 5)
				{
					strcat(pedido[OpcaoEditar].prato, "\n");
				  	strcat(pedido[OpcaoEditar].prato,Mussarela);
				  	estoque[6].quantidade -= 500;  
				  	if (promoApl == 1)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 11;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 22;
					  }
				}
				else if (prato == 6)
				{
					strcat(pedido[OpcaoEditar].prato, "\n");
				  	strcat(pedido[OpcaoEditar].prato,Calabresa);
				  	estoque[6].quantidade -= 500;  
				  	
				  	if (promoApl == 1)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 10;
					  }
					  else if (promoApl == 0)
					  {
					  pedido[OpcaoEditar].valorPedido = pedido[OpcaoEditar].valorPedido + 20;
					  }
				}
				
				else if (prato > 6 || prato < 1)
				{
				vermelho();
				printf("Opção Inválida!!!\n\n\n");
				system("pause");
				system("cls");
				}
			}
		}
			while (resposta3 == 'S' || resposta3 == 's');
	  	
	  		
	  }
	 else if (OpcaoEditar2 == 2)
	  {
	  		printf("\nInforme o novo nome que ficará no pedido\n");
	  		printf("Nome: ");
	  		scanf("%s", &pedido[OpcaoEditar].clienteNome);
	  		break;
	  }
	   else if (OpcaoEditar2 == 3)
	  {
	  		printf("\nInforme o novo endereço que ficará no pedido\n");
	  		printf("Endereço: ");
	  		scanf("%s", &pedido[OpcaoEditar].clienteEnd);
	  		break;
	  }
	   else if (OpcaoEditar2 == 4)
	  {
	  		printf("\nInforme o novo telefone que ficará no pedido\n");
	  		printf("Telefone: ");
	  		scanf("%s", &pedido[OpcaoEditar].clienteTel);
	  		break;
	  }
	   else if (OpcaoEditar2 == 5)
	  {
	  	system("cls");
	  	azul();
	  	printf("Voltando ao menu\n\n");
	  	system("pause");
	  }
	  
	}
	while (OpcaoEditar2 > 0 && OpcaoEditar2 < 5);
	        system ("cls");

	}
    else if (OpcaoPedido == 4)
	{
		
		system("cls");
		printf("\nSelecione um pedido para excluir: \n\n");
		printf("-------------------------------\n");
				
				int i;  //Verificação se o pedido é vago
				
				for (i=0; i<6; i++){
			
					if(pedido[i].Vago == 1){
			
				printf("\nPedido %i \n",i);
                printf("  \n %s \n %s \n%s \n%s \n\n",pedido[i].prato, pedido[i].clienteNome, pedido[i].clienteEnd, pedido[i].clienteTel);
            	printf("-------------------------------\n");
            
            		}
            		
				}
				
	printf("\n\nPedido: ");
	scanf("%i", &excluir);
	
	  printf ("\nDeseja realmente excluir o pedido? (S/N)\n");
	  getchar();
	  scanf("%c", &respostaExcl);
	  
	   
	    if(respostaExcl == 'S' || respostaExcl == 's')
		{
	        strcpy(pedido[excluir].prato, " ");
	        strcpy(pedido[excluir].clienteNome, " ");
	        strcpy(pedido[excluir].clienteEnd, " ");
	        strcpy(pedido[excluir].clienteTel, " ");
	        pedido[excluir].Vago = 0;
	        
			system("cls");
			azul();   
	        printf("\nPedido excluido com Sucesso!!\n");
	        system("pause");
	    }
	    else if (respostaExcl == 'N' || respostaExcl == 'n')
		{
			azul();
			printf("\n\nVoltando ao menu!\n\n");
			system("pause");
	    }
	}
 		else if (OpcaoPedido == 5)
	{
	 	system("cls");
 			 //Listando pedidos
		printf("-------------------------------\n");
				int pedidosM = 0;  //verifica quantos pedidos existem
				int i;  //Verificação se o pedido é vago
				
				for (i=0; i<6; i++){
			
					if(pedido[i].Vago == 1){
			
				printf("\nPedido %i \n",i);
                printf("  \n %s \n %s \n%s \n%s \n\n",pedido[i].prato, pedido[i].clienteNome, pedido[i].clienteEnd, pedido[i].clienteTel);
            	printf("-------------------------------\n");
            	
            	pedidosM = pedidosM + 1;
            		}  		
            		
				}
				if (pedidosM < 1 )
				{
					vermelho();
					system("cls");
					printf("Não existem pedidos cadastrado no sistema agora!!!\n\n");
					system("pause");
				}
				
				if (pedidosM > 0 )
				
		{
		
			printf ("Selecione um pedido para concluir \n");
			scanf("%i", &OpcaoPedido2);
			
			
		printf ("\nDeseja realmente concluir o pedido? (S/N)\n");
	  getchar();
	  scanf("%c", &respostaConcluir);
	  
	   
	    if(respostaConcluir == 'S' || respostaConcluir == 's')
		{
			strcpy(pedido[OpcaoPedido2].prato, " ");
	        strcpy(pedido[OpcaoPedido2].clienteNome, " ");
	        strcpy(pedido[OpcaoPedido2].clienteEnd, " ");
	        strcpy(pedido[OpcaoPedido2].clienteTel, " ");
	        
			totalGanho = totalGanho + pedido[OpcaoPedido2].valorPedido;
			pedidosFeitos = pedidosFeitos + 1;
			
			pedido[OpcaoPedido2].Vago = 0;
			pedido[OpcaoPedido2].valorPedido = 0;
	        
			system("cls");
			azul();   
	        printf("\nPedido concluido com Sucesso!!\n");
	        
			system("pause");
	        
	    }
	    else if (respostaConcluir == 'N' || respostaConcluir == 'n')
		{
			azul();
			printf("\n\nVoltando ao menu!\n\n");
			system("pause");
	    }
		
	 		getchar ();
	        system ("cls");
		}
	}
	  
	else if(OpcaoPedido == 6){
                	system("cls");
                    printf("Você selecionou voltar ao menu principal, pressione ENTER para continuar");
                    getchar();
                    system("cls");
                }
    
    
    else{
                    printf("Opção Inválida!\nVoltando ao menu \n\n");
                    
                system("pause");
				system("cls");    
				}
	}
    while(OpcaoPedido =!6 || OpcaoPedido > 6 || OpcaoPedido < 0 );
}

void Estoque()
{
	
	int OpcaoEstoque, OpcaoEstoque2, add, OpcaoRetirar, less;
	
	
		printf("Por favor selecione uma opção:\n\n");

		    printf("1 - Listar Estoque\n");
            printf("2 - Adicionar ao Estoque\n");
			printf("3 - Retirar do Estoque\n");
            printf("4 - Voltar ao menu principal\n\n");
            scanf("%d", &OpcaoEstoque);
            getchar();
                 
				 
			do
			{
				 if(OpcaoEstoque == 1)
				 {
				 	
                 	system("cls");
                  ListarEstoque();
                  
                  
                  	system("pause");
                 	menu();
				 }
                else if(OpcaoEstoque == 2)
				{
                	system("cls");
					     
					ListarEstoque();
					
					printf("Escolha que produto gostaria de adicionar ao estoque:\n");     
					scanf("%i",&OpcaoEstoque2);
					
					printf("\nDiga quantas %s de %s gostaria de adicionar:\n", estoque[OpcaoEstoque2].unidade, estoque[OpcaoEstoque2].produto);
				 	scanf("%i",&add);
				 estoque[OpcaoEstoque2].quantidade = estoque[OpcaoEstoque2].quantidade + add;
				 
				 	printf("\nProduto adicionado ao estoque com sucesso!!\n\n");
					system("pause");
					menu();
				}
				else if(OpcaoEstoque == 3)
				{
                	system("cls");                
                	
					ListarEstoque();
					
					printf("Escolha que produto gostaria de retirar do estoque:\n");     
					scanf("%i",&OpcaoRetirar);
					
					printf("\nDiga quantas %s de %s gostaria de retirar:\n", estoque[OpcaoRetirar].unidade, estoque[OpcaoRetirar].produto);
				 	scanf("%i",&less);
				 estoque[OpcaoRetirar].quantidade = estoque[OpcaoRetirar].quantidade - less;
				 
				 printf("\nProduto retirado do estoque com sucesso!!\n\n");
					system("pause");
				 
				}
				else if(OpcaoEstoque == 4)
				{
					
					printf("\n\nVoltando ao menu!\n\n");
                 	system("cls");         
					menu();      
				}
				
				else
				{
					system("cls"); 
					vermelho();
				printf("Opção Inválida, Voltando ao menu!!!\n\n");
				system("pause");
				menu();
				}
			}while(OpcaoEstoque =! 4 || OpcaoEstoque < 4 || OpcaoEstoque > 0 );
}

void ListarEstoque()
{
	int k;
	printf("Exibindo todo o estoque cadastrados no sistema:\n\n");    	
				printf("---------------------------------\n");
				
				
				
				for (k=0; k<7; k++){
			
					if(estoque[k].Vago == 1)
					{
			
				printf("\nProduto %d: %s ",k, estoque[k].produto);
                printf("\nQuantidade: %i ", estoque[k].quantidade);
                printf("%s \n", estoque[k].unidade);
            	printf("---------------------------------\n");
            
            		}
            		
				}
				printf("\n\n");
}

void Relatorio()
{
	int OpcaoRelatorio;
	char resposta;
	
			printf("\n1 - Mostrar o relatório\n");
            printf("2 - Salvar Relatório\n");
		
            printf("3 - Voltar ao menu principal\n\n");
            scanf("%d", &OpcaoRelatorio);
            getchar();
            
            do{
            
			if(OpcaoRelatorio == 1)
				{
				MostrarRelatorio();
				}
			else if(OpcaoRelatorio == 2)
				{
				ponteiro = fopen("Relatorio.txt","w");
				
					if (ponteiro == NULL)
					{
						printf("ERRO! O arquivo não foi aberto!\n");
					}
					else
					{
						printf("O arquivo foi aberto com sucesso! \n\n");
					}
				
					fprintf(ponteiro, "%s", fRelatorio); //Printf para arquivos
					fclose (ponteiro);
					
				system("cls");
				printf("O relatório foi salvo com sucesso em um documento de texto, no mesmo local do programa!!\n\n");
				
				printf("Gostaria de visuáliza-lo por aqui? \n(S/N)\n");
				scanf("%c",&resposta);
				
				if (resposta == 'S' || resposta == 's')
				{
					MostrarRelatorio();
				}
				else
				{
					system("cls");
					printf("Voltando ao menu\n\n");
					system("pause");
					menu();
				}
				}
			else if(OpcaoRelatorio == 3)
				{
					
					printf("\n\nVoltando ao menu!\n\n");
                 	system("cls");         
					menu();      
				}
			else
				{
					system("cls"); 
					vermelho();
				printf("Opção Inválida, Voltando ao menu!!!\n\n");
				system("pause");
				menu();
				}
			}while(OpcaoRelatorio =! 3 || OpcaoRelatorio < 3 || OpcaoRelatorio > 0 );
}

void MostrarRelatorio()
{
	
	system("cls");
	//INÍCIO DA CRIAÇÃO DO RELATÓRIO
	
	strcpy(fRelatorio, "Relatório Diário da pizzaria Los Hermanos\n\n");
	strcat(fRelatorio, "-------------------------------------------------\n\n");
	
	strcat(fRelatorio, "Exibição do estoque ao iniciar o dia:\n\n");	 
	strcat(fRelatorio, fREInicial);

		

		
	//Fim da criação do relatório, Inicialização da impressão
	
	printf(fRelatorio);
	
	printf("\nExibição do estoque atual:\n\n");
		 
	ListarEstoque();
	
	printf("Pedidos realizados: %i", pedidosFeitos);
	printf("\nTotal Ganho: R$%.2f\n\n", totalGanho);
	
	system("pause");
	menu();
}

void sac(){
	system("cls");
	printf("Você selecionou a opção 8 - Elogios e Reclamações\n");
	int OpcaoSac;
	printf("\nEcolha uma opção:\n\n");
           
		   	      printf("1 - Mostrar todas as opiniões\n");
          		  printf("2 - Registrar nova opinião\n");
          		  printf("3 - Voltar ao menu\n");
          		scanf("%i", &OpcaoSac);
          		system("cls");
          		
          		if (OpcaoSac == 1)
				  {
				  	system("cls");
				  	  printf("Exibindo todas as opiniões:\n\n");    	
				printf("-------------------------------\n");
				
				int i;
				
				for (i=0; i<6; i++){
			
					if(SAC[i].Vago == 1){
			
				printf("\nOpinião %i \n",i);
                printf("  \n%s \n\n", SAC[i].mensagem);
            	printf("-------------------------------\n");
            
            		system("pause");
            		}

            		
				}
          	      }
          	      
          		if (OpcaoSac == 2)
				  {
				  	system("cls");
				  	printf("Escreva sua nova opinião \n \n");
				  	
				  	
				  	
					  int i;
				for (i=0; i<5; i++){
					if(SAC[i].Vago == 0){
						printf("Mensagem: ");
						
				  	gets(SAC[i].mensagem);
				  	getchar();
				  	printf("\n\nOpinião registrada com sucesso");
				  	break;
				  }
          	      }
          	  }
          		if (OpcaoSac == 3)
				  {
				  	system("cls");
				  	printf("Voltando ao menu principal\n\n");
				  	system("pause");
          		  }
	
}


/* FIM DA PROGRAMAÇÃO */
