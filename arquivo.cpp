#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>

std::vector<std::string> le_arquivo() {
	std::ifstream arquivo;
	arquivo.open("palavras.txt");

	if (arquivo.is_open()) {
		int quantidade;
		arquivo >> quantidade;

		std::vector<std::string> palavras;

		for (int i = 0; i < quantidade; i++) {
			std::string palavra;
			arquivo >> palavra;
			palavras.push_back(palavra);
		}
		return palavras;
	}
	else {
		std::cout << "Nao foi possivel acessar o banco de palavras!" << std::endl;
		exit(0);
	}
}

void salvar_arquivo(std::vector<std::string> novaLista) {
	std::ofstream arquivo;
	arquivo.open("palavras.txt");

	if (arquivo.is_open()) {

		arquivo << novaLista.size() << std::endl;
		for (std::string palavra : novaLista) {
			arquivo << palavra << std::endl;
		}
		arquivo.close();
	}
	else {
		std::cout << "Falha ao abrir o arquivo de palavras! ";
	}
}

void adicionar_palavra(std::string palavra) {

	std::vector<std::string> palavras = le_arquivo();
	palavras.push_back(palavra);

	salvar_arquivo(palavras);
}