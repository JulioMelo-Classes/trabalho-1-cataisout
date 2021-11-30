#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string>
#include <fstream>
#include "classe.hpp"


///verifica se o palpite esta na palavra
bool palpite_certo (std::string palavra, char letra);

///AJUSTA OS ACERTOS DE ACORDO COM OS ERROS
void score (bool palpite_certo, int *erros, int *acertos);

///CONTA ERROS E VERIFICA SE PERDEU 

bool perdeu (int *erros);

void dificuldade();

int freq_mediaa ();

std::string escolha_palavra(int media, int dif);

std::string makeUpper (std::string palavra);

#endif