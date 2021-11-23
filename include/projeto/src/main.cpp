#include "../header/geral.hpp"
#include <map>
using namespace std;

map <char, bool> chute;

///verifica se o usuario venceu o jogo
bool gan (string palavra) {
  ///se ainda existe alguma letra da palavra com chave false a função retorna falso
  for (char letra : palavra) {
    if (!chute[letra])
      return true;
  }
  return false;
}

void imprime_plat (string segredo) {
  ///imprime apenas as chaves (letras) que tem correspondente true (as que ja foram acertadas)
  for (char letra : segredo)  {
      if (chute[letra])  {
        cout << letra;
      }
      else 
        cout << "_";
        cout << " ";
    }
    
  cout << endl;
}

int main() {
  ///cria objeto user
  usuario user;
  ///validacao de arquivos e interface
  msg_final_validacao(arquivo_palavra(), arquivo_score());
  if (!arquivo_score && !arquivo_palavra)
    return 0;
  
  user.setnome();
  menu();  ///menu de escolha
  int dif;
  dificuldade();/// escolha de dificuldade
  cin >> dif;
  user.setdif(dif);
  
  string segredo = escolha_palavra(freq_mediaa(),dif); ///selecionando a palavra secreta
  segredo = makeUpper(segredo); ///transformando em maiusculo
  user.setpalavra(segredo);

  bool nao_ganhou = true; /// jogo comeca aqui
  int pontos = 0, erros = 0;
  
  abertura();

  while (nao_ganhou && !perdeu(&erros))  {
    char palpite;
  
    imprime_plat(segredo);

   ///recebe palpite
    cout << "Seu palpite: "; cin >> palpite;
   
   ///atualiza o map do chute
    if (palpite_certo(segredo, palpite)) 
      chute[palpite] = true;
    
    ///verifica se o jogador ganhou com o atual chute
    nao_ganhou = gan(segredo);

    ///marca os pontos e verifica se perdeu
    score(palpite_certo(segredo, palpite), &erros, &pontos);
    resposta(palpite_certo(segredo, palpite), palpite);   
  }
  msg_resultado(nao_ganhou, segredo, pontos); /// exibe mensagens de vitoria ou derrota
  user.setpont(pontos);

  ofstream file;  ///gera novo arquivo de score com desemprenho atual do jogador
  file.open("novo_score.txt");
  file << user.getdif() << ";" << user.getnome() << ";" << user.getpalavra() << ";"<<user.getpont();
  file.close();
  
  return 0;
} 