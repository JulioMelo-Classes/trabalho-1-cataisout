#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string>
#include <fstream>
#include "classe.hpp"


///verifica se o palpite esta na palavra
bool palpite_certo (std::string palavra, char letra)  {
  for (auto i = 0; i < palavra.size(); i++)  {
    if (letra == palavra[i])  
      return true;
    
  }

  return false;
}

///AJUSTA OS ACERTOS DE ACORDO COM OS ERROS
void score (bool palpite_certo, int *erros, int *acertos)  {
  if (palpite_certo)  {
    ++*acertos;
  }
  else {
    --*acertos;
    ++*erros;
  }
}

///CONTA ERROS E VERIFICA SE PERDEU 

bool perdeu (int *erros)  {
  if (*erros == 6)
    return true;
  
  return false;  
}

void dificuldade() {
  std::cout<<"\nDeseja jogar em que nivel?\n";
  std::cout<<"1. Fácil\n2. Médio\n3. Difícil\n\nSua escolha: ";

}

int freq_mediaa ()  {
  unsigned int freq_media = 0, freq = 0;
  int qtd=0;

  std::fstream fonte_palavras;
  fonte_palavras.open("fonte.txt");

  std::string palavra_escolhida;


  while (!fonte_palavras.eof())  {
    fonte_palavras >> palavra_escolhida;
    fonte_palavras >> freq;
    freq_media = freq_media+freq;
    qtd=qtd+1;
  }

  freq_media=freq_media/qtd;

  return freq_media;
}

std::string escolha_palavra(int media, int dif) {
  std::fstream file;
  file.open("fonte.txt");
  std::string palavra;
  unsigned int freq;
  while(!file.eof()) {
    file >> palavra;
    file >> freq;

    if (dif == 1){
      if (freq > media)
        return palavra;
    }

    else if (dif == 2) {
      if (freq == media || freq+10 > media)
        return palavra;
    }
    else {
      if (freq < media)
        return palavra;
    }
  }

  return palavra;
}

std::string makeUpper (std::string palavra)  {
  for (int i=0; i < palavra.length(); i++)  {
    palavra[i]=toupper(palavra[i]);
  }
  return palavra;
}



#endif