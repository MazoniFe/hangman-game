#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

vector<string> le_arquivo() {
	ifstream arquivo;
	arquivo.open("palavras.txt");

	if (arquivo.is_open()) {
		int quantidade;
		arquivo >> quantidade;

		vector<string> palavras;

		for (int i = 0; i < quantidade; i++) {
			string palavra;
			arquivo >> palavra;
			palavras.push_back(palavra);
		}
		return palavras;
	}
	else {
		cout << "Nao foi possivel acessar o banco de palavras!" << endl;
		exit(0);
	}
}

void salvar_arquivo(vector<string> novaLista) {
	ofstream arquivo;
	arquivo.open("palavras.txt");

	if (arquivo.is_open()) {

		arquivo << novaLista.size() << endl;
		for (string palavra : novaLista) {
			arquivo << palavra << endl;
		}
		arquivo.close();
	}
	else {
		cout << "Falha ao abrir o arquivo de palavras! ";
	}
}
bool letra_existe(char chute) {
	for (char letra : PALAVRA_SECRETA) {
		if (chute == letra) {
			return true;
		}
	}
	return false;
}

bool acertou() {
	for (char letra : PALAVRA_SECRETA) {
		if (!chutou[letra]) {
			return false;
		}
	}
	return true;
}

bool enforcou() {
	return chutes_errados.size() > 5;
}

void imprime_boas_vindas() {
	cout << " **** *** *** *** ****" << endl;
	cout << " *** Jogo da Forca ***" << endl;
	cout << " **** *** *** *** ****" << endl;
	cout << endl;
}

void imprime_palavra() {
	for (char letra : PALAVRA_SECRETA) {
		if (chutou[letra]) {
			cout << letra << " ";
		}
		else {
			cout << "_ ";
		}
	}
}

void chute() {
	cout << "Digite um chute: " << endl;
	cout << endl;
	cout << "Chutes errados: ";
	for (char chute : chutes_errados) {
		cout << chute << " ";
	}
	cout << endl;

	char chute;
	cin >> chute;


	if (letra_existe(chute)) {
		chutou[chute] = true;
		cout << "Voce acertou, sua letra está na palavra!" << endl;
		cout << endl;
	}
	else {
		cout << "Voce errou! seu chute nao esta na palavra." << endl;
		chutes_errados.push_back(chute);
		cout << endl;
	}
}

void adicionar_palavra(string palavra) {

	vector<string> palavras = le_arquivo();
	palavras.push_back(palavra);

	salvar_arquivo(palavras);
}
void validar_resultado() {

	if (acertou()) {
		cout << "Parabens vc ganhou!!" << endl;;
		cout << "Voce deseja adicionar uma nova palavra ao banco? (S/N)" << endl;
		char resposta;
		cin >> resposta;

		if (resposta == 'S') {
			bool palavraValida = false;
			while (!palavraValida) {
				cout << "Digite a palavra. A palavra deve ter no minimo 4 letras! ";
				string palavra;
				cin >> palavra;
				if (palavra.size() >= 4) {
					adicionar_palavra(palavra);
					palavraValida = true;
				}
			}
		}
		else
		{
			exit(0);
		}
	}
	else if (enforcou()) {
		cout << "Voce foi enforcado! Tente novamente.";
		cout << "A palavra secreta era: " << PALAVRA_SECRETA << endl;
	}

	cout << "Fim de Jogo!" << endl;
}

void sorteia_palavra() {
	vector<string> palavras = le_arquivo();

	srand(time(NULL));
	int indice_sorteado = rand() % (palavras.size());
	PALAVRA_SECRETA = palavras[indice_sorteado];
}

int main()
{
	sorteia_palavra();
	while (!acertou() && !enforcou()) {
		system("clear||cls");
		imprime_boas_vindas();
		imprime_palavra();
		chute();
		validar_resultado();
	}
}
