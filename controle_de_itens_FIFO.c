#include <stdio.h>

int quantidade = 0;
char atendimentos[1][20];
int opcao;
int tamanho = 0;

/*Mensagem de inicio do programa, boas vindas*/
void mensagem_inicio(){
  printf("\n Ola, seja bem vindo(a) ao meu programa! :) \n");
}
/*Mensagem de exclusao de um item*/
void mensagem_exclusao(){
  printf("\n Item exluido com sucesso! \n");
}

/*Mensagem de item atendido*/
void mensagem_atender(){
  printf("\n Item atendido com sucesso! :D \n");
}

/*Padrao de cabeçalho da lista de itens */
void cabecalho_lista(){
  printf("\n Lista de itens \n");
  printf("--------------------------------- \n");
}

/*Padrão de rodape da lista*/
void rodape_lista(){
  printf("--------------------------------- \n");
}

/*Mensagem de item adicionado com sucesso*/
void mensagem_sucesso(){
  printf("\n Item adicionado com sucesso! :D \n");
}

/*Mensagem de lista vazia*/
void mensagem_vazio(){
  printf("\n A lista esta vazia :( \n");
}

/*Mensagem de opção inválida*/
void mensagem_invalida(){
  printf("\n Opcao invalida :( \n");
}

/*Mensagem de lista com o limite de 20 itens*/
void lista_cheia(){
  printf("Voce atingiu o limite de inputs de 20 itens, atenda ou exlua um item para continuar :( \n");
}

/*Exibir a lista de opções para o usuário escolher uma*/
void opcoes(){
  printf("\n Escolha uma opcao: \n");
  printf("1 - Adicionar item: \n");
  printf("2 - Atender item: \n");
  printf("3 - Excluir item: \n");
  printf("4 - Listar itens: \n");

  scanf("%i", &opcao);
}

/*Adicionar um item na lista*/
void adicionar(){
  if (tamanho < 20)
  {
    quantidade = quantidade + 1;
    atendimentos[0][tamanho] = quantidade;
    tamanho = tamanho + 1;
    mensagem_sucesso();
  }
  else
  {
    lista_cheia();
  }
}

/*Atender um item da lista em ordem FIFO*/
void atender(){
  if (tamanho > 0)
  {
    tamanho = tamanho - 1;
    atendimentos[0][0] = 0;
    int contador = 1;
    for (int i = 0; i < tamanho; i++)
    {
      atendimentos[0][i] = atendimentos[0][contador];
      contador = contador + 1;
    }
    mensagem_atender();
  }
  else
  {
    mensagem_vazio();
  }
}

/*Exluir o ultimo item da lista*/
void excluir(){
  if (tamanho > 0)
  {
    tamanho = tamanho - 1;
    atendimentos[0][tamanho] = 0;
    mensagem_exclusao();
  }
  else
  {
    mensagem_vazio();
  }
}

/*Listar os itens da lista*/
void listar(){
  if (tamanho > 0)
  {
    cabecalho_lista();
    for (int i = 0; i < tamanho; i++)
    {
      printf("%d \n", atendimentos[0][i]);
    }
    rodape_lista();
  }
  else
  {
    mensagem_vazio();
  }
}

/*Função principal do programa*/
int main()
{
  int infinito = 1000;

  /*Exibir mensagem de boas vindas*/
  mensagem_inicio();

  /*Rodar o programa infinitamente*/
  for (int qtd = 0; qtd <= infinito; qtd++)
  {

    /*Exibir as opções para o usuário*/
    opcoes();

    /*Verificar a opção informada pelo usuário*/
    switch (opcao)
    {
    case 1:
      adicionar();
      break;

    case 2:
      atender();
      break;

    case 3:
      excluir();
      break;

    case 4:
      listar();
      break;

    default:
      mensagem_invalida();
      break;
    }
    infinito = infinito + 1;
  }
  return 0;
}