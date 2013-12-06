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

int tela_inicial()
{
	char senha[100];
	system("clear"); //limpando tela
	printf("Programa do Sistema da Biblioteca\n\n");
	printf("\tPara fazer cadastro digite sua SENHA.\n");
	printf("\tAperte ENTER para realizar empréstimos.\n");
	printf("\tPrecione 's' para SAIR do Programa\n");
	scanf("%[^\n]s",senha); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	
	if(!strcmp(senha, "mac"))
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
	int verifica;
	system("clear"); //limpando tela
	printf("\t1: Cadastrar Usuário\n");
	printf("\t2: Cadastrar Livro\n");
	printf("\t3: Alterar quantidade de um livro\n");
	printf("\t4: Sair\n");
	verifica = scanf("%d",&escolha); //verifica se foi digitado número ou letra
	__fpurge(stdin); //limpando buffer (linux)
	while(verifica == 0) //não deixa passar se foi digitado letra
	{
		printf("Entrada inválida. Digite a opção correta ");
		verifica = scanf("%d",&escolha); //verifica se foi digitado número ou letra
		__fpurge(stdin); //limpando buffer (linux)
	}
	return escolha;
}

int tela_emprestimo()
{
	int escolha;
	int verifica;
	system("clear"); //limpando tela
	printf("\t1: Realizar Empréstimo\n");
	printf("\t2: Realizar Devolução\n");
	printf("\t3: Listar Usuários\n");
	printf("\t4: Listar Livros\n");
	printf("\t5: Pesquisar por um Usuário específico\n");
	printf("\t6: Pesquisar por um Livro específico\n");
	printf("\t7: Sair\n");
	verifica = scanf("%d",&escolha);
	__fpurge(stdin); //limpando buffer (linux)
	while(verifica == 0) //não deixa passar se foi digitado letra
	{
		printf("Entrada inválida. Digite a opção correta ");
		verifica = scanf("%d",&escolha); //verifica se foi digitado número ou letra
		__fpurge(stdin); //limpando buffer (linux)
	}
	return escolha;
}

void cadastro_usuario(struct usuarios user[], int posicao)
{
	system("clear"); //limpando tela
	printf("Nessa sessão será feita o CADASTRO de um novo usuário\n\n");
	
	printf("Digite o NOME do usuário: ");
	scanf("%[^\n]s",user[posicao].nome); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	system("clear"); //limpando tela
	
	printf("Digite o PRONTUÁRIO do usuário: ");
	scanf("%[^\n]s",user[posicao].prontuario); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	system("clear"); //limpando tela
	
	printf("Digite o ENDEREÇO do usuário: ");
	scanf("%[^\n]s",user[posicao].endereco); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux);
	system("clear"); //limpando tela
	
	printf("Digite o CEP do usuário: ");
	scanf("%[^\n]s",user[posicao].CEP); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux);
	system("clear"); //limpando tela
	
	printf("Digite o TELEFONE residencial do usuário: ");
	scanf("%[^\n]s",user[posicao].telefone); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	system("clear"); //limpando tela
}

void cadastro_livro(struct livros book[], int posicao)
{
	int verifica;
	system("clear"); //limpando tela
	printf("Nessa sessão será feita o CADASTRO de um novo livro\n\n");
	
	printf("Digite o TÍTULO do livro: ");
	scanf("%[^\n]s",book[posicao].titulo); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	system("clear"); //limpando tela
	
	printf("Digite a CATEGORIA do livro: ");
	scanf("%[^\n]s",book[posicao].categoria); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	system("clear"); //limpando tela
	
	printf("Digite os AUTORES do livro: ");
	scanf("%[^\n]s",book[posicao].autores); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	system("clear"); //limpando tela
	
	printf("Digite a EDITORA do livro: ");
	scanf("%[^\n]s",book[posicao].editora); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	system("clear"); //limpando tela
	
	printf("Digite o ANO do livro: ");
	verifica = scanf("%d",&book[posicao].ano);
	__fpurge(stdin); //limpando buffer (linux)
	while(verifica == 0) //não deixa passar se foi digitado letra
	{
		printf("Entrada inválida. Digite em números ");
		verifica = scanf("%d",&book[posicao].ano); //verifica se foi digitado número ou letra
		__fpurge(stdin); //limpando buffer (linux)
	}
	system("clear"); //limpando tela
	
	printf("Digite a QUANTIDADE de exemplares deste livro: ");
	verifica = scanf("%d",&book[posicao].quantidade);
	__fpurge(stdin); //limpando buffer (linux)
	while(verifica == 0) //não deixa passar se foi digitado letra
	{
		printf("Entrada inválida. Digite a quantidade em números ");
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
	
	printf("Digite o NOME do USUÁRIO que deseja pesquisar: ");
	scanf("%[^\n]s",buscar_nome); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	
	for(i = 0;i < posicao;i++)
	{
		if(!strcmp(user[i].nome, buscar_nome)) //como a função strcmp retorna 1 se os nomes forem iguais, é preciso negar para que entre no IF
		{
			system("clear"); //limpando tela
			printf("Nome: %s\n", user[i].nome);
			printf("Prontuário: %s\n", user[i].prontuario);
			printf("Endereço: %s\n", user[i].endereco);
			printf("CEP: %s\n", user[i].CEP);
			printf("Telefone: %s\n", user[i].telefone);
			printf("Livros emprestados:\n");
			for(j = 0;j < user[i].emprestimos;j++)
			{
				printf("%s / ", user[i].livros_emprestados[j]);
			}
			printf("\n");
			verificador = 0;
		}
	}
	if(verificador == 1)
	{
		system("clear"); //limpando tela
		printf("USUÁRIO não encontrado");
	}
	
	printf("\nPrecione ENTER para continuar\n");
	scanf("%c",&continuar);
	__fpurge(stdin); //limpando buffer (linux)
}

void listar_usuarios(struct usuarios user[], int posicao)
{
	system("clear"); //limpando tela
	int i;
	char continuar;
	
	printf("Lista de USUÁRIOS cadastrados\n\n");
	
	for(i = 0;i < posicao;i++)
	{
		printf("\t%s\n", user[i].nome);
	}
	
	printf("\nPrecione ENTER para continuar\n");
	scanf("%c",&continuar);
	__fpurge(stdin); //limpando buffer (linux)
}

void listar_livros(struct livros book[], int posicao)
{
	system("clear"); //limpando tela
	int i;
	char continuar;
	
	printf("Lista de LIVROS cadastrados\n\n");
	
	for(i = 0;i < posicao;i++)
	{
		printf("\t%s\n", book[i].titulo);
	}
	
	printf("\nPrecione ENTER para continuar\n");
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
	
	printf("Digite o TÍTULO do LIVRO que deseja pesquisar: ");
	scanf("%[^\n]s",buscar_titulo); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	
	for(i = 0;i < posicao;i++)
	{
		if(!strcmp(book[i].titulo, buscar_titulo))//como a função strcmp retorna 1 se os títulos forem iguais, é preciso negar para que entre no IF
		{
			system("clear"); //limpando tela
			printf("Título: %s\n", book[i].titulo);
			printf("Categoria: %s\n", book[i].categoria);
			printf("Autores: %s\n", book[i].autores);
			printf("Editora: %s\n", book[i].editora);
			printf("Ano: %d\n", book[i].ano);
			printf("Quantidade: %d\n", book[i].quantidade);
			printf("Usuários Relacionados:\n");
			for(j = 0;j < book[i].emprestimos;j++)
			{
				printf("%s / ", book[i].usuarios_relacionados[j]);
			}
			printf("\n");
			verificador = 0;
		}
	}
	if(verificador == 1)
	{
		system("clear"); //limpando tela
		printf("LIVRO não encontrado");
	}
	
	printf("\nPrecione ENTER para continuar\n");
	scanf("%c",&continuar);
	__fpurge(stdin); //limpando buffer (linux)
}

void realizar_devolucao(struct usuarios user[], struct livros book[], int posicao_user, int posicao_book)
{
	system("clear"); //limpando tela
	int i;
	int j;
	int k;
	int verificador = 0;
	int posicao_usuario;
	int posicao_livro;
	char usuario[100];
	char livro[100];
	char continuar;
	
	printf("Digite o NOME do USUÁRIO para fazer a DEVOLUÇÃO: ");
	scanf("%[^\n]s",usuario); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	printf("\n");
	printf("Digite o TÍTULO do LIVRO para fazer a DEVOLUÇÃO: ");
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
		printf("Erro ao fazer a devolução");
	}
	else
	{
		system("clear"); //limpando tela
		printf("Devolução realizada com Sucesso!");
	}
	
	printf("\nPrecione ENTER para continuar\n");
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
	
	printf("Digite o TÍTULO do LIVRO que deseja alterar a QUANTIDADE: ");
	scanf("%[^\n]s",buscar_titulo); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	
	for(i = 0;i < posicao;i++)
	{
		if(!strcmp(book[i].titulo, buscar_titulo))//como a função strcmp retorna 1 se os títulos forem iguais, é preciso negar para que entre no IF
		{
			system("clear"); //limpando tela
			printf("Digite quantos LIVROS serão ADICIONADOS: ");
			scanf("%d",&quantidade);
			__fpurge(stdin); //limpando buffer (linux)
			
			book[i].quantidade = (book[i].quantidade + quantidade);
			
			system("clear"); //limpando tela
			printf("Valor alterado com Sucesso!");
			verificador = 0;
		}
	}
	
	if(verificador == 1)
	{
		system("clear"); //limpando tela
		printf("Livro não encontrado");
	}
	
	printf("\nPrecione ENTER para continuar\n");
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
	
	printf("Digite o NOME do USUÁRIO para a realização do EMPRÉSTIMO: ");
	scanf("%[^\n]s",buscar_usuario); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando buffer (linux)
	printf("\n");
	printf("Digite o TÍTULO do LIVRO para a realização do EMPRÉSTIMO: ");
	scanf("%[^\n]s",buscar_livro); //[^\n] no scanf faz com que leia até chegar em um ENTER
	__fpurge(stdin); //limpando tela
	
	

	
	
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
			printf("Empréstimo realizado com sucesso!");
		}
		else
		{
			system("clear"); //limpando tela
			printf("Não é mais possível fazer empréstimos");
		}
	}
	else
	{
		system("clear"); //limpando tela
		printf("Não foi possível realizar o empréstimo");
	}

	printf("\nPrecione ENTER para continuar\n");
	scanf("%c",&continuar);
	__fpurge(stdin); //limpando buffer (linux)
}

int main(int argc, char *argv[])
{
	struct livros book[n];
	struct usuarios user[n];
	
	
	int quantidade_usuario = 0;
	int quantidade_livro = 0;
	int escolha_usuario;
	int escolha_cadastro;
	int escolha_emprestimo;
	
	
	char sair_inicio = 'n';
	char sair_programa = 'n';
	char continuar;
	
	
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
										printf("Não é possível fazer mais cadastros\n");
										printf("Precione ENTER para continuar");
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
										printf("Não é possível fazer mais cadastros\n");
										printf("Precione ENTER para continuar");
										scanf("%c",&continuar);
										__fpurge(stdin); //limpando buffer (linux)
									}
									break;
								case 3:
									alterar_quantidade(book, quantidade_livro);
									break;
								default:
									system("clear"); //limpando tela
									printf("Escolha Inválida\n");
									printf("Precione ENTER para continuar");
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
									printf("Escolha Inválida\n");
									printf("Precione ENTER para continuar");
									scanf("%c",&continuar);
									__fpurge(stdin); //limpando buffer (linux)
									break;
							}
							
							escolha_emprestimo = tela_emprestimo();
						}
						break;
		
				}
				system("clear");
				printf("\tDeseja sair para a tela inicial? ('s' - SAIR/'n' - NÃO SAIR)\n");
				scanf("%c",&sair_inicio);
				__fpurge(stdin); //limpando buffer (linux)
			}
		}
		else
		{
			sair_programa = 's';
		}
	}
	

	system("clear");
	return 0;
}
