#ifndef ARQ_H
#define ARQ_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>


bool eh_valido (std::string palavra, int freq)  {
  if (palavra.length() < 4)
    return false;
  if (freq <=0 ) 
    return false; 
  for (int i=0; i<palavra.length();i++){
    if (0 > int(palavra[i]))
      return false;
  }
    
    
  return true;
}

bool arquivo_palavra ()  {
  
  std::fstream fonte_palavras;
  fonte_palavras.open("fonte.txt");

  std::string palavra_escolhida;
  int freq;
  bool valido_palavra = true;

  while (!fonte_palavras.eof() && valido_palavra)  {
    fonte_palavras >> palavra_escolhida;
    fonte_palavras >> freq;
    valido_palavra = eh_valido(palavra_escolhida, freq);
  }
  fonte_palavras.close();
  if (valido_palavra)
    return true;
  
  return false;
}


bool arquivo_score () {
    std::ifstream file;
    file.open("score.txt");
  
    std::string linha;

    while (!file.eof()) {
      int colum = 0;
      getline(file, linha);
      
      for (char c : linha)  {
        if (int(c) == 59 ) 
          ++colum;
      }

    if (colum == 4) 
      return false;
    
  

    if (3>colum)
      return false;
    
  }

  return true;
}

void msg_final_validacao (bool valido_palavra, bool valido_score) {
  std::cout << ">>> Verificando arquivos, por favor aguarde..." <<std::endl;

  std::cout<<"----------------------------------------------"<<std::endl;
  if (valido_palavra && valido_score)
    std::cout<<">>> Arquivos OK"<<std::endl;

  else if (!valido_palavra && !valido_score){
    std::cout<<">>> Arquivo de palavras inválido"<<std::endl;
    std::cout<<">>> Arquivo de scores inválido"<<std::endl;
  }

  else if (!valido_palavra)
    std::cout<<">>> Arquivo de palavras inválido"<<std::endl;
  else
    std::cout<<">>> Arquivo de scores inválido"<<std::endl;

  std::cout<<"----------------------------------------------\n"<<std::endl;


}


#endif