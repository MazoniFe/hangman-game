#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "arquivo.hpp"
#include "boas_vindas.hpp"
#include "palavras.hpp"
#include "validacao.hpp"


std::string PALAVRA_SECRETA;
std::map<char, bool> chutou;
std::vector<char> chutes_errados;

int main()
{
	PALAVRA_SECRETA = sorteia_palavra();
	while (!acertou(PALAVRA_SECRETA, chutou) && !enforcou(chutes_errados)) {
		system("clear||cls");
		imprime_boas_vindas();
		imprime_palavra(PALAVRA_SECRETA,chutou);
		chute(PALAVRA_SECRETA, &chutes_errados, &chutou);
		validar_resultado(acertou(PALAVRA_SECRETA, chutou), enforcou(chutes_errados), PALAVRA_SECRETA);
	}
}
