void imprime_palavra(std::string palavraSecreta, std::map<char, bool> chutou);
bool letra_existe(char chute, std::string palavraSecreta);
void chute(std::string palavraSecreta, std::vector<char>* chutes_errados, std::map<char, bool>* chutou);
std::string sorteia_palavra();