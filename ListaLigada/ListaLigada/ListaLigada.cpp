
#include <iostream>
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
	NO* novo = (NO*)malloc(sizeof(NO));
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	NO*primeiro = NULL;
	NO* ultimo = NULL;

	if (primeiro == NULL) {
		primeiro = novo;
		ultimo = novo;
	}
	else {
		ultimo->prox = novo;
		ultimo = novo;
	
	}
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

	if (novo != NULL) {
		cout << "Esse elemento já existe na lista. Digite um novo elemento";
	}



	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
	}
	else
	{
		// procura o final da lista
		NO* aux = primeiro;
		while (aux->prox != NULL) {
			aux = aux->prox;
			NO* posicaoElemento();
		}
		aux->prox = novo;
	}
}

void excluirElemento()
{   
	int excluir;
	NO* atual = primeiro;
	NO* anterior = NULL;
	NO* ultimo = NULL;

	cout << "Digite o Valor que deseja excluir";
	cin >> excluir;
	NO* pos = posicaoElemento(excluir);

	if(pos == NULL){
		cout << "numero nao existe";

	}

	while (atual->valor != excluir){

		anterior * atual * ultimo;
		atual = atual->prox;
	}

	if (ultimo->valor == excluir && anterior == NULL ){

		primeiro = ultimo->prox;



	}

	else if(ultimo ->valor == excluir)
	{

		NO* aux = atual;
		anterior->prox = atual->prox;
		free(aux);

		cout << "numero excluido";
	}

}

void buscarElemento()
{ 

	
		int n;
		cout << "Digite o valor que deseja buscar:  ";
		cin >> n;

		if (n <= 0) {
			cout << "valor invalido" << endl;
			return;
		}

		vector<int> v(n);
		cout << "Digite os " << n << " valores:" << endl;
		for (int i = 0; i < n; i++) {
			cout << "  v[" << i << "] = ";
			cin >> v[i];
		}

		int valor;
		cout << "Digite o valor que deseja buscar: ";
		cin >> valor;

		bool encontrado = false;
		int posicao = -1;
		for (int i = 0; i < n; i++) {
			if (v[i] == valor) {
				encontrado = true;
				posicao = i;
				break;
			}
		}

		if (encontrado) {
			cout << "Valor encontrado na posição: " << posicao << endl;
		}
		else {
			cout << "nao existe" << endl;
		}
	}

	int main() {
		buscarElemento();
		return 0;
	}

	
}



// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento não estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}


//void excluirElemento()
//{
	//int excluir;
	//NO* atual = primeiro;
	//NO* anterior = NULL;

	//cout << "Digite o Valor que deseja excluir";
	//cin >> excluir;
	//NO* pos = posicaoElemento(excluir);

	//if (pos == NULL) {
		//cout << "numero nao existe";

	//}

	//while (atual->valor != excluir) {

		//anterior* atual;
		//atual = atual->prox;
	}

	//if (atual->valor == excluir && anterior == NULL) {

		//primeiro = atual->prox;



	}

	//else if (atual->valor == excluir)
	{

		//NO* aux = atual;
		//anterior->prox = atual->prox;
		//free(aux);

		//cout << "numero excluido";
	}

}