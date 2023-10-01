#include "arquivo.hpp"
#include <map>
#include <iostream>

bool acertou(std::string palavraSecreta, std::map<char, bool> chutou) {
	for (char letra : palavraSecreta) {
		if (!chutou[letra]) {
			return false;
		}
	}
	return true;
}

bool enforcou(std::vector<char> chutes_errados) {
	return chutes_errados.size() > 5;
}

void validar_resultado(bool acertou, bool enforcou, std::string palavraSecreta) {

	if (acertou) {
		std::cout << "Parabens vc ganhou!!" << std::endl;
		std::cout << "Voce deseja adicionar uma nova palavra ao banco? (S/N)" << std::endl;
		char resposta;
		std::cin >> resposta;

		if (resposta == 'S') {
			bool palavraValida = false;
			while (!palavraValida) {
				std::cout << "Digite a palavra. A palavra deve ter no minimo 4 letras! ";
				std::string palavra;
				std::cin >> palavra;
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
	else if (enforcou) {
		std::cout << "Voce foi enforcado! Tente novamente.";
		std::cout << "A palavra secreta era: " << palavraSecreta << std::endl;
	}

	std::cout << "Fim de Jogo!" << std::endl;
}