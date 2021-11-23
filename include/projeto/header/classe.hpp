#ifndef CLASSE_H
#define CLASSE_H

#include <iostream>
#include <string>

class usuario {
  private:
    int pontuacao;
    std::string nome, dificuldade, palavra;

  public:
    ///dificuldade
    void setdif (int d) {
      if (d==1)
        dificuldade = "Fácil";
      else if (d==2)
        dificuldade = "Média";
      else
        dificuldade = "Difícil";
    }
    std::string getdif() {
      return dificuldade;
    }
    ///nome
    void setnome(){
      std::cout<<"Qual seu nome? ";
      std::cin >> nome;
    }

    std::string getnome(){
      return nome;
    }
    ///pontuacao
    void setpont (int pont) {
      pontuacao = pont;
    }

    int getpont() {
      return pontuacao;
    }
     ///palavra
    void setpalavra(std::string segredo){
      palavra=segredo;
    }

    std::string getpalavra(){
      return palavra;
    }
    
};

#endif