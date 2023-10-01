#include "arquivo.hpp"
#include <map>
#include <iostream>

void imprime_palavra(std::string palavraSecreta, std::map<char, bool> chutou) {
	for (char letra : palavraSecreta) {
		if (chutou[letra]) {
			std::cout << letra << " ";
		}
		else {
			std::cout << "_ ";
		}
	}
}

bool letra_existe(char chute, std::string palavraSecreta) {
	for (char letra : palavraSecreta) {
		if (chute == letra) {
			return true;
		}
	}
	return false;
}

void chute(std::string palavraSecreta, std::vector<char>* chutes_errados, std::map<char, bool>* chutou) {
	std::cout << "Digite um chute: " << std::endl;
	std::cout << std::endl;
	std::cout << "Chutes errados: ";
	for (char chute : *chutes_errados) {
		std::cout << chute << " ";
	}
	std::cout << std::endl;

	char chute;
	std::cin >> chute;


	if (letra_existe(chute, palavraSecreta)) {
		(*chutou)[chute] = true;
		std::cout << "Voce acertou, sua letra está na palavra!" << std::endl;
		std::cout << std::endl;
	}
	else {
		std::cout << "Voce errou! seu chute nao esta na palavra." << std::endl;
		chutes_errados -> push_back(chute);
		std::cout << std::endl;
	}
}

std::string sorteia_palavra() {
	std::vector<std::string> palavras = le_arquivo();

	srand(time(NULL));
	int indice_sorteado = rand() % (palavras.size());
	return palavras[indice_sorteado];
}

