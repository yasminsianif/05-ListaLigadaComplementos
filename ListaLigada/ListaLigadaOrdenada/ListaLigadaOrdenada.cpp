#include <iostream>//yasmin siani
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}
void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
	}
	else if (posicaoElemento(novo->valor) == NULL)
	{
		if (novo->valor < primeiro->valor)
		{
			novo->prox = primeiro;
			primeiro = novo;
			cout << "Numero adicionado com sucesso\n";
		}
		else {
			NO* aux = primeiro;
			NO* anterior = NULL;
			while (aux != NULL) {
				if (aux->valor > novo->valor) {
					break;
				}
				anterior = aux;
				aux = aux->prox;
			}
			anterior->prox = novo;
			novo->prox = aux;
			cout << "Numero adicionado com sucesso\n";
		}
	}
	else {
		cout << "Numero ja existente na lista\n";
	}

}

void excluirElemento()
{
	int excluir;
	cout << "Digite o valor que deseja excluir: ";
	cin >> excluir;

	if (posicaoElemento(excluir) == NULL) {
		cout << "O elemento nao existe na lista\n";
	}
	else {
		NO* atual = primeiro;
		if (atual->valor == excluir)
		{
			primeiro = atual->prox;
		}
		else {
			NO* anterior = NULL;
			NO* proximo = NULL;
			while (atual != NULL) {
				if (atual->valor == excluir)
				{
					proximo = atual->prox;
					break;
				}
				anterior = atual;
				atual = atual->prox;
			}
			if (anterior != NULL) {
				anterior->prox = atual->prox;
			}
		}
		free(atual);
		cout << "Valor excluido\n";
	}
}

void buscarElemento()
{
	int busca;
	cout << "Digite o valor que deseja buscar: ";
	cin >> busca;

	if (posicaoElemento(busca) == NULL) {
		cout << "O elemento nao existe na lista\n";
	}
	else {
		cout << "O elemento existe na lista\n";
	}
}

NO* posicaoElemento(int numero) 
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor > numero) {
			aux = NULL;
			break;
		}
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
