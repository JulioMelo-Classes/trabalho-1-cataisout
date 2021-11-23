#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>


void imprime_score() {

  std::cout<<"\n\t\t\t SCORES\n"<<std::endl;
  std::fstream file;
  file.open("score.txt");

  while (!file.eof()) {
    std::string linha;
    getline(file, linha);
    std::cout<<linha<<std::endl;
      
  }
}

void menu() {
  int escolha = 0;
  std::cout <<"\nDeseja iniciar um novo jogo ou rever os scores?"<< std::endl;
  std::cout <<"1. Ver scores\n2. Jogar" << std::endl;
  std::cout << "Sua escolha: ";
  std::cin >> escolha;
  if (escolha!=1 && escolha!=2) {
    std::cout << "Escolha inválida! Digite uma alternativa válida, por favor.\n";
    menu();
  }

  if (escolha==1) {
    escolha=0;
    imprime_score();
    menu();
  }
  else
    return;
}

  ///imprime mensagem de boas vindas ao jogador
void abertura () {
  std::cout << "\n\n";
  std::cout << "/ \\                             \\." << std::endl;
  std::cout <<"|   |                            |." << std::endl;
  std::cout <<"\\_ |                             |." << std::endl;
  std::cout <<"    |  ->->->->->->->->->->->->  |." << std::endl;
  std::cout <<"    |                            |." << std::endl;
  std::cout <<"    |        BEM-VINDO AO        |." << std::endl;
  std::cout <<"    |                            |." << std::endl;
  std::cout <<"    |            JOGO            |." << std::endl;
  std::cout <<"    |             DA             |." << std::endl;
  std::cout <<"    |            FORCA           |." << std::endl;
  std::cout <<"    |                            |." << std::endl;
  std::cout <<"    |  ->->->->->->->->->->->->  |." << std::endl;
  std::cout <<"    |                            |." << std::endl;
  std::cout <<"    |                            |." << std::endl;
  std::cout <<"    |   _________________________|___" << std::endl;
  std::cout <<"    |  /                            /." << std::endl;
  std::cout <<"    \\_/dc__________________________/." << std::endl;
  std::cout << "\n\n";
  
}

///MENSAGEM EXIBIDA APOS PALPITE 
void resposta (bool acertou, char letra) {
  
  if (acertou)  
    std::cout << "Muito bem! A letra " << letra << " faz parte da palavra!" << std::endl; 

  else
    std::cout << "Meh, nao achei a letra " << letra << " :<" << std::endl;  
  
  std::cout << std::endl;
}

///MENSAGEM DE VIToRIA
void vitoria () {

  std::cout << " \n\n   .''.      .        *''*    :_\\/_:     . " << std::endl;
  std::cout << "      :_\\/_:   _\\(/_  .:.*_\\/_*   : /\\ :  .'.:.'."<< std::endl;
  std::cout << "  .''.: /\\ :   ./)\\   ':'* /\\ * :  '..'.  -=:o:=-"<< std::endl;
  std::cout << ":_\\/_:'.:::.    ' *''*    * '.\\'/.' _\\(/_'.':'.'"<< std::endl;
  std::cout << ": /\\ : :::::     *_\\/_*     -= o =-  /)\\    '  *"<< std::endl;
  std::cout << "  '..'  ':::'     * /\\ *     .'/.\\'.   '"<< std::endl;
  std::cout << "      *            *..*         :"<< std::endl;
  std::cout << "jgs     *"<< std::endl;
  std::cout << " \t\t\t Parabens, voce venceu!!!\n   "<< std::endl;

}

void derrota (std::string palavra) {
  std::cout << "Que pena, voce perdeu :(. Aprenda mais palavras e venha jogar novamente!"<<std::endl;
  std::cout << "A palavra era " << palavra << std::endl;
}
void bonequinho () {
  std::cout<<"\t O\n\t/|\\ \n\t/ \\";
  
  std::cout<<"\n"<<std::endl;
}
void msg_resultado (bool nganhou, std::string palavra,int pontos) {
  if (!nganhou)  {
    vitoria();
  }
  else {
    bonequinho();
    derrota(palavra);
  }
  std::cout << "\nVoce fez " << pontos << " pontos" <<std::endl; 
}


#endif
