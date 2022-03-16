
/*             UNISCESUMAR
   MAPA - ALGORÍTMOS E LÓGICA DE PROGRAMAÇÃO II - 52/2021
      Academico: Cristine Siqueira Dias RA - 21072066-5
   Resumo da Questão. 
1 – Função para Cadastrar Projetos: linha 33 função prototipada para cadastro 
linhas 116 à 154 bloco de comandos para a função cadastro.
2 – Rotinas de Impressão, sendo:
linhas 34 à 38, funções prototipadas para impressão dos projetos
linhas 164 à 310 blocos de comandos para as funções de impressão 
3 – Menu linhas 67 à 107.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

#define MAX 5 //constante

//declaração do registro para cadastro
typedef struct cadastro{ 
	int codigo;
	char titulo[50];
	char nome[39];
	char descricao[1000];
	int ano;
	int statu;
	char dataLim[10];
	char cliente[30];
	int entrega;
}dados_projetos;
				
int ordem = 0;//var global 

//funções prototipadas
void cadProjeto (dados_projetos cad[MAX]);
void listaProjeto (dados_projetos cad[MAX]);
void statuprojeto (dados_projetos cad[MAX]);
void codProjeto (dados_projetos cad[MAX]);
void clienteProjeto (dados_projetos cad[MAX]);
void tituloProjeto (dados_projetos cad[MAX]);
//função para evitar repetição de código
void listaStatus(){
	printf("\n\t\t1 - À fazer.");
	printf(" 2 - Em andamento.");
	printf(" 3 - Concluido.\n\t\t");
}

void menuStatus(){
	printf("\n\t\tMenu do Status de andamento:");
}

void listaEntrega(){
	printf("\n\t\t1 - Não entrege.");
	printf(" t2 - Entrege.");
	printf(" t3 - Cancelado");
	printf(" t4 - projeto teste.\n\t\t");
}

void menuEntrega(){
printf("\n\t\tMenu do Status de entrega:");
}
//execução do código	
int main(){
	setlocale(LC_ALL, "Portuguese");// permitir a forma de escrita em portugues
	dados_projetos cad[MAX];
	int opcao; //variavel que recebe a opção escolhida
	
	system("cls");
// menu 
	do{
//opções de escolha
		system("cls");
		printf("\t\t****************************************************");
		printf("\n\t\t GERENCIAMENTO DE PROJETO ");
		printf("\n\t\t****************************************************");
		printf("\n\t\t << Escolha uma opção do menu: ");
		printf("\n\t\t 1 - Cadastro");
		printf("\n\t\t 2 - Todos os projetos");
		printf("\n\t\t 3 - Busca por status");
		printf("\n\t\t 4 - Busca por código");
		printf("\n\t\t 5 - Busca por cliente");
		printf("\n\t\t 6 - Busca por titulo do projeto");
		printf("\n\t\t 7 - Sair\n\t\t");
		scanf("%d", &opcao);
//execução da escolha		
		switch (opcao){
		
		case 1:
			cadProjeto(cad);//chamando a função caso a opcao seja 1
			break;
		case 2:
			listaProjeto(cad);//chamando a função caso a opcao seja 2
			break;
		case 3:
			statuprojeto(cad);//chamando a função caso a opcao seja 3
			break;
		case 4:
			codProjeto(cad);//chamando a função caso a opcao sejade 4
			break;
		case 5:
			clienteProjeto(cad);//chamando a função caso a opcao seja 5
			break;
		case 6:
			tituloProjeto(cad);//chamando a função caso a opcao seja 6
			break;
		default:
			printf("\n\t\tOpção não encontrada!\n\t\t");//indica uma falla, opção não esta na lista
			system("pause"); 	
		}	
	}while(opcao!=7);
	return 0;	
					
}
//função para realizar o cadastro 
void cadProjeto (dados_projetos cad[MAX]){
		system("cls");
		printf("\t\t***************************************");
		printf("\n\t\t\t\tCADASTRAR");
		printf("\n\t\t***************************************");
		
		char resp = 's';//variavel de controle
				//condição para realizar o cadastro até o limite estabelecido ou a resposta seja diferente de 's'	
		while(resp == 's' && ordem <= MAX){
			ordem++;
			printf("\n\t\tCódigo: %d ", ordem);
			cad[ordem].codigo = ordem;//o codigo é agregado aoutomaticamente e sequencial
			printf("\n\t\tInforme o Titulo: ");
			fflush(stdin);
			gets(cad[ordem].titulo);
			printf("\n\t\tInforme o Gerente Responsável: ");
			fflush(stdin);
			gets(cad[ordem].nome);	
			printf("\n\t\tDescrição do projeto: ");
			fflush(stdin);
			gets(cad[ordem].descricao);
			printf("\n\t\tInforme o ano: ");
			fflush(stdin);
			scanf("%d", &cad[ordem].ano);	
			printf("\n\t\tInforme o status do projeto:\n\t\tDigite: " );
			listaStatus();
			fflush(stdin);
			scanf("%d", &cad[ordem].statu);
			printf("\n\t\tInforme a data máxima de entrega (xx/xx/xxxx): ");
			fflush(stdin);
			gets(cad[ordem].dataLim);
			printf("\n\t\tInforme o nome do cliente: ");
			fflush(stdin);
			gets(cad[ordem].cliente);
			printf("\n\t\tInforme o status de entrega:\n\t\tDigite:");
			listaEntrega();
			fflush(stdin);
			scanf("%d", &cad[ordem].entrega);	
			//condição que possibilita continuar cadastrando ou não
				if(ordem < MAX){
					printf("\n\n\t\tDeseja cadastrar novo Projeto? [s] Sim [n] Não: ");
					fflush(stdin);
					scanf("%c", &resp); 
				}else{
					printf("\n\t\tSua base de Dados já chegou ao limite!!!\n");
					resp = 'n';
			}
		}
	}
//função para apresentar todos os cadastro já feitos 
void listaProjeto (dados_projetos cad[MAX]){
	system("cls");
	printf("\t\t ***************************************");
	printf("\n\t\t\t\tLISTA DOS PROJETOS ");
	printf("\n\t\t ***************************************\n");

	int lista =1;// var local
	menuStatus();
	listaStatus();
	menuEntrega();
	listaEntrega();
				//condição que exibe a lista dos projetos cadastrados
	if(ordem >= 1){
		while(lista <= ordem){
			
			printf("\n\t\t codigo: %d\n\t\t Titulo: %s\n\t\t Gerente Responsável: %s\n\t\t Descrição: %s\n\t\t Ano: %d\n\t\t Status: %d\n\t\t Data máxima da entrega: %s\n\t\t Cliente: %s\n\t\t Situação de entrega: %d\n\t\t",cad[lista].codigo,cad[lista].titulo,cad[lista].nome,cad[lista].descricao,cad[lista].ano,cad[lista].statu,cad[lista].dataLim,cad[lista].cliente,cad[lista].entrega);
			lista++;
		}
			
			
	}else{
		printf("\n\t\t Sem Registros Cadastrados \n\t\t");
	}	
	system("Pause");
}
//função que realiza a busca por codigo
void codProjeto(dados_projetos cad[MAX]){
	system("cls");
	int buscaCodigo, achou,i;
	printf("\t\t ***************************************");
	printf("\n\t\t\t\tBUSCAR POR CÓDIGO ");
	printf("\n\t\t ***************************************");
	printf("\n\t\t Entre com o código: ");
	scanf("%d", &buscaCodigo);
	achou = 0;
	i = 0;
	menuStatus();
	listaStatus();
	menuEntrega();
	listaEntrega();
	while((achou == 0) && (i <= ordem)){//o bloco de comando só será executado qdo as 2 condições forem satisfeita
		 		// faz a comparação 
		if(buscaCodigo == cad[i].codigo){
			printf("\n\t\t codigo: %d\n\t\t Titulo: %s\n\t\t Gerente Responsável: %s\n\t\t Descrição: %s\n\t\t Ano: %d\n\t\t Status: %d\n\t\t Data máxima da entrega: %s\n\t\t Cliente: %s\n\t\t Situação de entrega: %d\n\t\t",cad[i].codigo, cad[i].titulo,cad[i].nome,cad[i].descricao,cad[i].ano,cad[i].statu,cad[i].dataLim,cad[i].cliente,cad[i].entrega);
			achou = 1;
			system("Pause");
		}
		i++;
	}
		if(achou == 0 ){//caso o codigo não esteja na lista de projetos
			printf("\n\t\t Registro não encontrado com o código %d \n\t\t", buscaCodigo);
			system("Pause");
		}
	}
//função que realiza a busca por andamento do projeto
void statuprojeto(dados_projetos cad[MAX]){
	system("cls");
	int buscaStatus, achou,i;
	printf("\t\t***************************************");
	printf("\n\t\t\t\tBUSCAR POR STATUS ");
	printf("\n\t\t***************************************");
	printf("\n\t\tEntre com o status:\n\t\t Digite:\n\t\t1 - projeto não iniciado\n\t\t2 - Projeto em andamento\n\t\t3 - Projeto concluido \n\t\t");
	scanf("%d", &buscaStatus);
	achou = 0;
	i = 0;
	menuStatus();
	listaStatus();
	menuEntrega();
	listaEntrega();
	while((achou == 0) && (i <= ordem)){
		if(buscaStatus == cad[i].codigo){
			printf("\n\t\t-codigo: %d\n\t\t-Titulo: %s\n\t\t-Gerente Responsável: %s\n\t\t-Descrição: %s\n\t\t-Ano: %d\n\t\t-Status: %d\n\t\t-Data máxima da entrega: %s\n\t\t-Cliente: %s\n\t\t-Situação de entrega: %d\n\t\t",cad[i].codigo, cad[i].titulo,cad[i].nome,cad[i].descricao,cad[i].ano,cad[i].statu,cad[i].dataLim,cad[i].cliente,cad[i].entrega);
			achou = 1;
			system("Pause");
		}
		i++;
	}
		if(achou == 0 ){
			printf("\n\t\t Registro não encontrado com o código %d \n\t\t", buscaStatus);
			system("Pause");
		}
		
		
}
//função que realiza a busca por nome do cliente
void clienteProjeto (dados_projetos cad[MAX]){
	system("cls");
	char buscaCliente[30];
	int achou, i;
	printf("\t\t ***************************************");
	printf("\n\t\t\t\tBUSCA POR NOME DE CLIENTE ");
	printf("\n\t\t ***************************************");
	printf("\n\t\t Entre com o nome do cliente (idêntico ao digitado): ");
	fflush(stdin);
	gets(buscaCliente);
	achou = 0;
	i = 0;
	menuStatus();
	listaStatus();
	menuEntrega();
	listaEntrega();
	while((achou == 0) && (i < MAX)){
		if(strcmp(cad[i].cliente,buscaCliente)==0){
			printf("\n\t\t codigo: %d\n\t\t Titulo: %s\n\t\t Gerente Responsável: %s\n\t\t Descrição: %s\n\t\t Ano: %d\n\t\t Status: %d\n\t\t Data máxima da entrega: %s\n\t\t Cliente: %s\n\t\t Situação de entrega: %d\n\t\t",cad[i].codigo, cad[i].titulo,cad[i].nome,cad[i].descricao,cad[i].ano,cad[i].statu,cad[i].dataLim,cad[i].cliente,cad[i].entrega);
			
			system("Pause");
		}
		i++;
	}
	if(achou == 0 ){
		printf("\n\t\t Registro não encontrado com o nome %s \n\t\t", buscaCliente);
		system("Pause");
	}
}
//função que realiza a busca por nome do projeto
void tituloProjeto (dados_projetos cad[MAX]){

	system("cls");
	char buscaTitulo[30];
	int achou, i;
	printf("\t\t ***************************************");
	printf("\n\t\t\t\tBUSCA POR TITULO DO PROJETO ");
	printf("\n\t\t ***************************************");
	printf("\n\t\tEntre com o nome do projeto(idêntico ao digitado): ");
	fflush(stdin);
	gets(buscaTitulo);
	achou = 0;
	i = 0;
	menuStatus();
	listaStatus();
	menuEntrega();
	listaEntrega();
	while((achou == 0) && (i < MAX)){
		if(strcmp(cad[i].titulo,buscaTitulo)==0){
			printf("\n\t\t codigo: %d\n\t\t Titulo: %s\n\t\t Gerente Responsável: %s\n\t\t Descrição: %s\n\t\t Ano: %d\n\t\t Status: %d\n\t\t Data máxima da entrega: %s\n\t\t Cliente: %s\n\t\t Situação de entrega: %d\n\t\t", cad[i].codigo, cad[i].titulo,cad[i].nome,cad[i].descricao,cad[i].ano,cad[i].statu,cad[i].dataLim,cad[i].cliente,cad[i].entrega);
			achou = 1;
			system("Pause");
		}
		i++;
	}

	if(achou == 0 ){
		printf("\n\t\t Registro não encontrado com o nome %s \n\t\t", buscaTitulo);
		system("Pause");
	}
}

