#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 5

struct livros //estrutura para os livros
{
	char titulo[100];
	char categoria[30];
	char autores[100];
	char editora[30];
	char usuarios_relacionados[n][100]; //criando um vetor de strings -> são 5 strings e cada strng com 100 posições cada
	int ano;
	int quantidade;
	int emprestimos;
};

struct usuarios //estrutura para os usuários
{
	char nome[100];
	char prontuario[10];
	char endereco[150];
	char CEP[10];
	char telefone[15];
	char livros_emprestados[n][100]; //criando um vetor de strings -> são 5 strings e cada string com 100 posições
	int emprestimos;
};

// VARIÁVEIS GLOBAIS //

 struct livros book[n];
 struct usuarios user[n];
 
// LEITURA E GRAVAÇÃO DE ARQUIVOS //

// PARA USUARIOS // == OBS: O SISTEMA NÃO CONSEGUE LER OS ARQUIVOS

void LEITURA(int posicao)
{
	int k; //Contador 01
	
	// Iniciando Arquivos //	
	FILE *arquivo1;
	FILE *arquivo2;
	FILE *arquivo3;
	FILE *arquivo4;
	FILE *arquivo5;
	arquivo1 = fopen("USUnome.txt", "r");
	arquivo2 = fopen("USUprontuario.txt", "r");
	arquivo3 = fopen("USUendereco.txt", "r");
	arquivo4 = fopen("USUcep.txt", "r");
	arquivo5 = fopen("USUtelefone.txt", "r");
	k = 0;
	
	
	for(k=0;k<=posicao;k++)
	{
		fscanf(arquivo1,"%s",user[k].nome);
		fscanf(arquivo2,"%s",user[k].prontuario);
		fscanf(arquivo3,"%s",user[k].endereco);
		fscanf(arquivo4,"%s",user[k].CEP);
		fscanf(arquivo5,"%s",user[k].telefone);
	}
	fclose(arquivo1);
	fclose(arquivo2);
	fclose(arquivo3);
	fclose(arquivo4);
	fclose(arquivo5);
}

void GRAVACAO(struct usuarios cadastro[], int posicao)
{
	int k; //Contador 01
	
	// Iniciando Arquivos //
	FILE *arquivo1;
	FILE *arquivo2;
	FILE *arquivo3;
	FILE *arquivo4;
	FILE *arquivo5;
	FILE *arquivo6;
	arquivo1 = fopen("USUnome.txt", "w");
	arquivo2 = fopen("USUprontuario.txt", "w");
	arquivo3 = fopen("USUendereco.txt", "w");
	arquivo4 = fopen("USUcep.txt", "w");
	arquivo5 = fopen("USUtelefone.txt", "w");
	arquivo6 = fopen("USUquantidade.txt", "w");
	k = 0;
	for(k=0;k<=posicao;k++)
	{
		fprintf(arquivo1,"%s \n",user[k].nome);
		fprintf(arquivo2,"%s \n",user[k].prontuario);
		fprintf(arquivo3,"%s \n",user[k].endereco);
		fprintf(arquivo4,"%s \n",user[k].CEP);
		fprintf(arquivo5,"%s \n",user[k].telefone);
	}
	fprintf(arquivo6,"%d",posicao);
	fflush(arquivo1);
	fflush(arquivo2);
	fflush(arquivo3);
	fflush(arquivo4);
	fflush(arquivo5);
	fflush(arquivo6);
	
	fclose(arquivo1);
	fclose(arquivo2);
	fclose(arquivo3);
	fclose(arquivo4);
	fclose(arquivo5);
	fclose(arquivo6);
	
}

/////////////////////////////////////////////////////////////////////


int tela_inicial()
{
	char senha[100];
	
	system("clear"); //limpando tela
	printf("\n================================================================\n");
	printf("\n|   Sistema Bibliotecario do Instituto Federal de Educacao,    |\n");
	printf("|          Ciencia e Tecnologia do Estado de Sao Paulo         |\n");
	printf("\n================================================================\n");
	printf("\n===| DIGITE SUA SENHA PARA ACESSAR OS COMANDOS DE ADMINISTRACAO |===\n");
	printf("\n===|         APERTE ENTER PARA REALIZAR EMPRESTIMOS             |===\n");
	printf("\n===|   DIGITE A LETRA 's' PARA SAIR DO SISTEMA BIBLIOTECARIO    |===\n");
	printf("\n================================================================\n");
	printf("\n\n ===> DIGITE SUA OPCAO: ");         
	scanf("%[^\n]s",senha); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	
	if(!strcmp(senha, "obelisco"))
	{
		return 0;
	}
	else if(!strcmp(senha, "s"))
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

int tela_cadastro()
{
	int escolha;
	system("clear"); //limpando tela
	printf("\n================================================================\n");
	printf("\n|   Sistema Bibliotecario do Instituto Federal de Educacao,    |\n");
	printf("|          Ciencia e Tecnologia do Estado de Sao Paulo         |\n");
	printf("\n================================================================\n");
	printf("\n         =|= SELECIONE UMA DAS OPCOES ABAIXO =|=\n");
	printf("\n===| 1 |='Cadastrar Usuario'=");
	printf("\n===| 2 |='Cadastrar Livro'=");
	printf("\n===| 3 |='Alterar a Quantidade de um Livro'=");
	printf("\n===| 4 |='Sair Deste Menu'=\n");
	printf("\n================================================================\n");
	printf("\n\n ===> DIGITE SUA OPCAO: "); 
	scanf("%d",&escolha);
	__fpurge(stdin); //limpando buffer (linux)
	return escolha;
}

int tela_emprestimo()
{
	int escolha;
	int verifica;
	system("clear"); //limpando tela
	printf("\n================================================================\n");
	printf("\n|   Sistema Bibliotecario do Instituto Federal de Educacao,    |\n");
	printf("|          Ciencia e Tecnologia do Estado de Sao Paulo         |\n");
	printf("\n================================================================\n");
	printf("\n         =|= SELECIONE UMA DAS OPCOES ABAIXO =|=\n");
	printf("\n===| 1 |='Realizar Emprestimo de Livros'=");
	printf("\n===| 2 |='Realizar Devolucao de Livros'=");
	printf("\n===| 3 |='Listar Todos Os Usuarios Cadastrados'=");
	printf("\n===| 4 |='Listar Todos Os Livros Cadastrados'=");
	printf("\n===| 5 |='Pesquisar Usuario'=");
	printf("\n===| 6 |='Pesquisar Livro'=");
	printf("\n===| 7 |='Sair Deste Menu'=");
	printf("\n================================================================\n");
	printf("\n\n ===> DIGITE SUA OPCAO: ");
	scanf("%d",&escolha);
	__fpurge(stdin); //limpando buffer (linux)
	while(verifica == 0) //não deixa passar se foi digitado letra
	{
		printf("\n====ENTRADA INVALIDA - DIGITE A OPÇÃO CORRETA! ===\n");
		verifica = scanf("%d",&escolha); //verifica se foi digitado número ou letra
		__fpurge(stdin); //limpando buffer (linux)
	}
	return escolha;
}

void cadastro_usuario(struct usuarios user[], int posicao)
{
	system("clear"); //limpando tela
	printf("\n================================================================\n");
	printf("\n|   Sistema Bibliotecario do Instituto Federal de Educacao,    |\n");
	printf("|          Ciencia e Tecnologia do Estado de Sao Paulo         |\n");
	printf("\n================================================================\n");
	printf("\n             ===== CADASTRO DE USUARIOS ===== \n");
	printf("\n================================================================\n");
	printf("\n            =|= Complete as Informacoes Abaixo =|=");	
	
	printf("\n\n===|NOME DO USUARIO: ");
	scanf("%[^\n]s",user[posicao].nome); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	
	
	printf("\n\n===|PRONTUARIO DO USUARIO: ");
	scanf("%[^\n]s",user[posicao].prontuario); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	
	
	printf("\n\n===|ENDERECO DO USUARIO: ");
	scanf("%[^\n]s",user[posicao].endereco); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux);
	
	
	printf("\n\n===|CEP DO USUARIO: ");
	scanf("%[^\n]s",user[posicao].CEP); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux);

	
	printf("\n\n===|TELEFONE DO USUARIO: ");
	scanf("%[^\n]s",user[posicao].telefone); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	system("clear"); //limpando tela
	
}

void cadastro_livro(struct livros book[], int posicao)
{
	int verifica = 0;
	system("clear"); //limpando tela
	printf("\n================================================================\n");
	printf("\n|   Sistema Bibliotecario do Instituto Federal de Educacao,    |\n");
	printf("|          Ciencia e Tecnologia do Estado de Sao Paulo         |\n");
	printf("\n================================================================\n");
	printf("\n             ===== CADASTRO DE LIVROS ===== \n");
	printf("\n================================================================\n");
	printf("\n            =|= Complete as Informacoes Abaixo =|=");	
	
	printf("\n\n===|NOME DO LIVRO: ");
	scanf("%[^\n]s",book[posicao].titulo); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)

	
	printf("\n\n===|CATEGORIA DO LIVRO: ");
	scanf("%[^\n]s",book[posicao].categoria); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)

	
	printf("\n\n===|NOME DOS AUTORES DO LIVRO: ");
	scanf("%[^\n]s",book[posicao].autores); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)

	
	printf("\n\n===|NOME DA EDITORA DO LIVRO: ");
	scanf("%[^\n]s",book[posicao].editora); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)

	
	printf("\n\n===|ANO DE PUBLICACAO DO LIVRO: ");
	verifica = scanf("%d",&book[posicao].ano);
	__fpurge(stdin); //limpando buffer (linux)

	
	while(verifica == 0) //não deixa passar se foi digitado letra
	{
		printf("\n====ENTRADA INVALIDA - DIGITE EM NUMEROS ===\n");
		verifica = scanf("%d",&book[posicao].ano); //verifica se foi digitado número ou letra
		__fpurge(stdin); //limpando buffer (linux)
	}
	system("clear"); //limpando tela
	
	printf("\n\n===|QUANTIDADE DE LIVROS DISPONIVEIS NO ACERVO: ");
	verifica = scanf("%d",&book[posicao].quantidade);
	__fpurge(stdin); //limpando buffer (linux)
	while(verifica == 0) //não deixa passar se foi digitado letra
	{
		printf("\n====ENTRADA INVALIDA - DIGITE A QUANTIDADE EM NUMEROS ===\n");
		verifica = scanf("%d",&book[posicao].quantidade); //verifica se foi digitado número ou letra
		__fpurge(stdin); //limpando buffer (linux)
	}
	system("clear"); //limpando tela
}

void buscar_usuario(struct usuarios user[], int posicao)
{
	system("clear"); //limpando tela
	int i;
	int j;
	int verificador = 1;
	char continuar;
	char buscar_nome[100];
	
	printf("\n================================================================\n");
	printf("\n|   Sistema Bibliotecario do Instituto Federal de Educacao,    |\n");
	printf("|          Ciencia e Tecnologia do Estado de Sao Paulo         |\n");
	printf("\n================================================================\n");
	printf("\n             ===== PESQUISA POR USUARIOS ===== \n");
	printf("\n================================================================\n");
	printf("\n===|DIGITE O NOME A SER PESQUISADO|: ");	
	scanf("%[^\n]s",buscar_nome); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	printf("\n================================================================\n");
	
	for(i = 0;i < posicao;i++)
	{
		if(!strcmp(user[i].nome, buscar_nome)) //como a função strcmp retorna 1 se os nomes forem iguais, é preciso negar para que entre no IF
		{
			printf("\n== Nome ==: | %s |\n", user[i].nome);
			printf("\n== Prontuário ==: | %s |\n", user[i].prontuario);
			printf("\n== Endereço ==: | %s |\n", user[i].endereco);
			printf("\n== CEP ==: | %s | \n", user[i].CEP);
			printf("\n== Telefone ==: | %s |\n", user[i].telefone);
			printf("\n=|= Livros emprestados =|=: ");
			for(j = 0;j < user[i].emprestimos;j++)
			{
				printf("       \n| %s |", user[i].livros_emprestados[j]);
			}
			verificador = 0;
		}
	}
	if(verificador == 1)
	{
		printf("\n=== O USUARIO | %s | -> NAO FOI ENCONTRADO! ===\n",buscar_nome);
	}
	printf("\n================================================================\n");
	printf("\nPressione ENTER para continuar\n");
	printf("\n================================================================\n");
	scanf("%c",&continuar);
	__fpurge(stdin); //limpando buffer (linux)
}

void listar_usuarios(struct usuarios user[], int posicao)
{
	int i;
	char continuar;
	
	system("clear");
	printf("\n================================================================\n");
	printf("\n|   Sistema Bibliotecario do Instituto Federal de Educacao,    |\n");
	printf("|          Ciencia e Tecnologia do Estado de Sao Paulo         |\n");
	printf("\n================================================================\n");
	printf("\n          ===== LISTA DE USUARIOS CADASTRADOS ===== \n");
	printf("\n================================================================\n\n");
	
	for(i = 0;i < posicao;i++)
	{
		printf("===| %s |===\n", user[i].nome);
	}
	printf("\n================================================================\n");
	printf("\nPressione ENTER para continuar\n");
	printf("\n================================================================\n");
	scanf("%c",&continuar);
	__fpurge(stdin); //limpando buffer (linux)
}

void listar_livros(struct livros book[], int posicao)
{
	int i;
	char continuar;
	
	system("clear");
	printf("\n================================================================\n");
	printf("\n|   Sistema Bibliotecario do Instituto Federal de Educacao,    |\n");
	printf("|          Ciencia e Tecnologia do Estado de Sao Paulo         |\n");
	printf("\n================================================================\n");
	printf("\n          ===== LISTA DE LIVROS CADASTRADOS ===== \n");
	printf("\n================================================================\n\n");
	
	for(i = 0;i < posicao;i++)
	{
		printf("===| %s |===\n", book[i].titulo);
	}
	
	printf("\n================================================================\n");
	printf("\nPressione ENTER para continuar\n");
	printf("\n================================================================\n");
	scanf("%c",&continuar);
	__fpurge(stdin); //limpando buffer (linux)
}

void buscar_livro(struct livros book[], int posicao)
{
	system("clear"); //limpando tela
	int i;
	int j;
	int verificador = 1;
	char continuar;
	char buscar_titulo[100];
	
	printf("\n================================================================\n");
	printf("\n|   Sistema Bibliotecario do Instituto Federal de Educacao,    |\n");
	printf("|          Ciencia e Tecnologia do Estado de Sao Paulo         |\n");
	printf("\n================================================================\n");
	printf("\n             ===== PESQUISA POR LIVROS ===== \n");
	printf("\n================================================================\n");
	printf("\n===|DIGITE O NOME DO LIVRO A SER PESQUISADO|: ");
	scanf("%[^\n]s",buscar_titulo); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	
	for(i = 0;i < posicao;i++)
	{
		if(!strcmp(book[i].titulo, buscar_titulo))//como a função strcmp retorna 1 se os títulos forem iguais, é preciso negar para que entre no IF
		{
			printf("\n\n=== Título ===: | %s| \n", book[i].titulo);
			printf("\n=== Categoria ===: | %s |\n", book[i].categoria);
			printf("\n=== Autores ===: | %s |\n", book[i].autores);
			printf("\n=== Editora ===: | %s |\n", book[i].editora);
			printf("\n=== Ano ===: | %d |\n", book[i].ano);
			printf("\n=== Quantidade ===: | %d |\n", book[i].quantidade);
			printf("\n=|= Usuarios Relacionados =|=:\n ");
			for(j = 0;j < book[i].emprestimos;j++)
			{
				printf("      | %s |\n", book[i].usuarios_relacionados[j]);
			}
			verificador = 0;
		}
	}
	if(verificador == 1)
	{
		printf("\n=== O LIVRO | %s | -> NAO FOI ENCONTRADO! ===\n",buscar_titulo);
	}
	
	printf("\n================================================================\n");
	printf("\nPressione ENTER para continuar\n");
	printf("\n================================================================\n");
	scanf("%c",&continuar);
	__fpurge(stdin); //limpando buffer (linux)
}

void realizar_devolucao(struct usuarios user[], struct livros book[], int posicao_user, int posicao_book)
{
	int i;
	int j;
	int k;
	int verificador = 0;
	int posicao_usuario;
	int posicao_livro;
	char usuario[100];
	char livro[100];
	char continuar;
	
	system("clear");// Limpando Tela
	printf("\n================================================================\n");
	printf("\n|   Sistema Bibliotecario do Instituto Federal de Educacao,    |\n");
	printf("|          Ciencia e Tecnologia do Estado de Sao Paulo         |\n");
	printf("\n================================================================\n");
	printf("\n             ===== DEVOLUCAO DE LIVROS ===== \n");
	printf("\n================================================================\n");
	printf("\n===|DIGITE O NOME DO USUARIO|: ");
	scanf("%[^\n]s",usuario); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	
	printf("\n===|DIGITE O NOME DO LIVRO|: ");
	scanf("%[^\n]s",livro); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	
	for(i = 0;i < posicao_user;i++) //parte usuário
	{
		if(!strcmp(user[i].nome, usuario))
		{
			for(j = 0;j < user[i].emprestimos;j++)
			{
				if(!strcmp(user[i].livros_emprestados[j], livro))
				{
					if(user[i].emprestimos != 1)
					{
						for(k = (j+1);k <= (user[i].emprestimos - 1);k++)
						{
							strcpy(user[i].livros_emprestados[j], user[i].livros_emprestados[k]);
							j++;
						}
						strcpy(user[i].livros_emprestados[j], "\0");
						user[i].emprestimos--;
						verificador++;
					}
					else
					{
						strcpy(user[i].livros_emprestados[j], "\0");
						user[i].emprestimos--;
						verificador++;
					}
				}
			}
		}
	}
	
	for(i = 0;i < posicao_book;i++) //parte livro
	{
		if(!strcmp(book[i].titulo, livro))
		{
			for(j = 0;j < book[i].emprestimos;j++)
			{
				if(!strcmp(book[i].usuarios_relacionados[j], usuario))
				{
					if(book[i].emprestimos != 1)
					{
						for(k = (j+1);k <= (book[i].emprestimos - 1);k++)
						{
							strcpy(book[i].usuarios_relacionados[j], book[i].usuarios_relacionados[k]);
							j++;
						}
						strcpy(book[i].usuarios_relacionados[j], "\0");
						book[i].emprestimos--;
						verificador++;
					}
					else
					{
						strcpy(book[i].usuarios_relacionados[j], "\0");
						book[i].emprestimos--;
						verificador++;
					}
				}
			}
		}
	}
	
	if(verificador != 2)
	{
		system("clear"); //limpando tela
		printf("\n=== ERRO AO FAZER A DEVOLUCAO! ===\n");
	}
	else
	{
		system("clear"); //limpando tela
		printf("\n=== DEVOLUCAO REALIZADA COM SUCESSO! ===\n");
	}
	
	printf("\n================================================================\n");
	printf("\nPressione ENTER para continuar\n");
	printf("\n================================================================\n");
	scanf("%c",&continuar);
	__fpurge(stdin); //limpando buffer (linux)
}

void alterar_quantidade(struct livros book[], int posicao)
{
	system("clear"); //limpando tela
	int i;
	int j;
	int quantidade;
	int verificador = 1;
	char continuar;
	char buscar_titulo[100];
	
	printf("\n================================================================\n");
	printf("\n|   Sistema Bibliotecario do Instituto Federal de Educacao,    |\n");
	printf("|          Ciencia e Tecnologia do Estado de Sao Paulo         |\n");
	printf("\n================================================================\n");
	printf("\n        ===== ALTERACAO DA QUANTIDADE DOS LIVROS ===== \n");
	printf("\n================================================================\n");
	printf("\n===|DIGITE O NOME DO LIVRO|: ");	
	scanf("%[^\n]s",buscar_titulo); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	
	for(i = 0;i < posicao;i++)
	{
		if(!strcmp(book[i].titulo, buscar_titulo))//como a função strcmp retorna 1 se os títulos forem iguais, é preciso negar para que entre no IF
		{
			printf("\n===|DIGITE A QUANTIDADE DE LIVROS A SEREM ADICIONADOS|: ");
			scanf("%d",&quantidade);
			__fpurge(stdin); //limpando buffer (linux)
			
			book[i].quantidade = (book[i].quantidade + quantidade);
			
			printf("\n================================================================\n");
			printf("\nValor Alterado com Sucesso!\n");
			printf("\n================================================================\n");
			verificador = 0;
		}
	}
	
	if(verificador == 1)
	{
		printf("\n=== O LIVRO | %s | -> NAO FOI ENCONTRADO! ===\n",buscar_titulo);
	}
	
	printf("\n================================================================\n");
	printf("\nPressione ENTER para continuar\n");
	printf("\n================================================================\n");
	scanf("%c",&continuar);
	__fpurge(stdin); //limpando buffer (linux)
}

void realizar_emprestimo(struct usuarios user[], struct livros book[], int posicao_user, int posicao_book)
{
	system("clear"); //limpando tela
	int i;
	int j;
	int posicao_usuario;
	int posicao_livro;
	int confirma = 0;
	int validador = 0;
	char continuar;
	char buscar_usuario[100];
	char buscar_livro[100];
	
	printf("\n================================================================\n");
	printf("\n|   Sistema Bibliotecario do Instituto Federal de Educacao,    |\n");
	printf("|          Ciencia e Tecnologia do Estado de Sao Paulo         |\n");
	printf("\n================================================================\n");
	printf("\n            ===== EMPRESTIMOS DOS LIVROS ===== \n");
	printf("\n================================================================\n");
	
	printf("\n===|DIGITE O NOME DO USUARIO|: ");
	scanf("%[^\n]s",buscar_usuario); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	system("clear"); //limpando tela
	
	printf("\n===|DIGITE O NOME DO LIVRO: ");
	scanf("%[^\n]s",buscar_livro); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando tela
	system("clear"); //limpando tela
	
	

	
	
	for(i = 0;i < posicao_book;i++) //verificando se existe o livro
	{
		if(!strcmp(book[i].titulo, buscar_livro))
		{
			confirma++;
			posicao_livro = i;
		}
	}

	for(i = 0;i < posicao_user;i++) //verificando se existe o usuário
	{
		if(!strcmp(user[i].nome, buscar_usuario))
		{
			confirma++;
			posicao_usuario = i;
		}
	}
	
	if(confirma == 2) //somente verifica se existir o usuário e o livro
	{
		for(j = 0;j < 5;j++) //verificação que confirma se o usuário já possui o livro emprestado, para não emprestar 2x ao mesmo usuário
		{
			if(!strcmp(user[posicao_usuario].livros_emprestados[j], buscar_livro))
			{
				validador = 1;
			}
		}
	}

	if((confirma == 2) && (validador != 1)) //só irá realizar o empréstimo se existir o livro e o usuário, e o usuário não pode ter esse livro já emprestado
	{
		if((user[posicao_usuario].emprestimos < 5) && (book[posicao_livro].emprestimos < book[posicao_livro].quantidade))
		{
			strcpy(user[posicao_usuario].livros_emprestados[user[posicao_usuario].emprestimos], buscar_livro); //fazendo a cópia para as informações do usuário
			strcpy(book[posicao_livro].usuarios_relacionados[book[posicao_livro].emprestimos], buscar_usuario); //fazendo a cópia para as informações do livro
			user[posicao_usuario].emprestimos++; //atualizando a quantidade de livros que o usuário pegou emprestado
			book[posicao_livro].emprestimos++; //atualizando a quantidade de livros disponíveis
			system("clear"); //limpando tela
			printf("\n================================================================\n");
			printf("\nEmprestimo Realizado Com Sucesso!\n");
			printf("\n================================================================\n");
		}
		else
		{
			system("clear"); //limpando tela
			printf("\n================================================================\n");
			printf("\nNao e Mais Possivel Realizar o Emprestimo!\n");
			printf("\n================================================================\n");
		}
	}
	else
	{
		system("clear"); //limpando tela
		printf("\n================================================================\n");
		printf("\nNao Foi Possivel Realizar o Empretimo!\n");
		printf("\n================================================================\n");
	}

	printf("\n================================================================\n");
	printf("\nPressione ENTER para continuar\n");
	printf("\n================================================================\n");
	scanf("%c",&continuar);
	__fpurge(stdin); //limpando buffer (linux)
}

int main(int argc, char *argv[])
{
	
	
	int quantidade_usuario = 0;
	int quantidade_livro = 0;
	int escolha_usuario;
	int escolha_cadastro;
	int escolha_emprestimo;
	
	
	char sair_inicio = 'n';
	char sair_programa = 'n';
	char continuar;
	
	// LEITURA DOS ARQUIVOS DE USUARIOS //
	
	FILE *arquivo6;
	arquivo6 = fopen("USUquantidade.txt", "a+");
	while(!feof(arquivo6))
	{
		fscanf(arquivo6,"%d",&quantidade_usuario);
	}
	//user = LEITURA(quantidade_usuario);
	
	//////////////////////////////////////
	
	
	while(sair_programa != 's')
	{
		sair_inicio = 'n'; //zerando a variável para poder voltar a fazer cadastros e/ou empréstimos
		escolha_usuario = tela_inicial();
		
		if(escolha_usuario != 2)
		{
			while(sair_inicio != 's')
			{
				switch(escolha_usuario)
				{
					case 0:
						escolha_cadastro = tela_cadastro();
			
						while(escolha_cadastro != 4)
						{
							switch(escolha_cadastro)
							{
								case 1:
									if(quantidade_usuario < n)
									{
										cadastro_usuario(user, quantidade_usuario);
										quantidade_usuario++;
									}
									else
									{
										system("clear"); //limpando tela
										printf("\n================================================================\n");
										printf("\nNao E Possivel Fazer Mais Cadastros\n");
										printf("\n================================================================\n");
										printf("\n================================================================\n");
										printf("\nPressione ENTER para continuar\n");
										printf("\n================================================================\n");
										scanf("%c",&continuar);
										__fpurge(stdin); //limpando buffer (linux)
									}
									break;
								case 2:
									if(quantidade_livro < n)
									{
										cadastro_livro(book, quantidade_livro);
										quantidade_livro++;
									}
									else
									{
										system("clear"); //limpando tela
										printf("\n================================================================\n");
										printf("\nNao E Possivel Fazer Mais Cadastros\n");
										printf("\n================================================================\n");
										printf("\n================================================================\n");
										printf("\nPressione ENTER para continuar\n");
										printf("\n================================================================\n");
										scanf("%c",&continuar);
										__fpurge(stdin); //limpando buffer (linux)
									}
									break;
								case 3:
									alterar_quantidade(book, quantidade_livro);
									break;
								default:
									system("clear"); //limpando tela
									printf("\n================================================================\n");
									printf("\nEscolha Invalida!\n");
									printf("\n================================================================\n");
									printf("\n================================================================\n");
									printf("\nPressione ENTER para continuar\n");
									printf("\n================================================================\n");
									scanf("%c",&continuar);
									__fpurge(stdin); //limpando buffer (linux)
									break;
							}
							escolha_cadastro = tela_cadastro();
						}
						break;
					case 1:
						escolha_emprestimo = tela_emprestimo();
						
						while(escolha_emprestimo != 7)
						{
							switch(escolha_emprestimo)
							{
								case 1:
									realizar_emprestimo(user, book, quantidade_usuario, quantidade_livro);
									break;
								case 2:
									realizar_devolucao(user, book, quantidade_usuario, quantidade_livro);
									break;
								case 3:
									listar_usuarios(user, quantidade_usuario);
									break;
								case 4:
									listar_livros(book, quantidade_livro);
									break;
								case 5:
									buscar_usuario(user, quantidade_usuario);
									break;
								case 6:
									buscar_livro(book, quantidade_livro);
									break;
								default:
									system("clear"); //limpando tela
									printf("\n================================================================\n");
									printf("\nEscolha Invalida!\n");
									printf("\n================================================================\n");
									printf("\n================================================================\n");
									printf("\nPressione ENTER para continuar\n");
									printf("\n================================================================\n");
									scanf("%c",&continuar);
									__fpurge(stdin); //limpando buffer (linux)
									break;
							}
							
							escolha_emprestimo = tela_emprestimo();
						}
						break;
		
				}
				system("clear");
				printf("\n================================================================\n");
				printf("\nDeseja Sair Para Tela Inicial?:\n");
				printf("\n================================================================\n");
				printf("===> (s/n): "); 
				scanf("%c",&sair_inicio);
				__fpurge(stdin); //limpando buffer (linux)
			}
		}
		else
		{
			sair_programa = 's';
		}
	}
	
	GRAVACAO(user,quantidade_usuario);
	system("clear");
	return 0;
}
