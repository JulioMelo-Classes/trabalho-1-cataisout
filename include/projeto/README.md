
# Jogo da forca 
## Como compilar

1. Em projeto, vá até a pasta src (cd src)
2. Digite na linha de comando "g++ main.cpp -o main.exe"
3. Para rodar, basta digitar o seguinte comando "./main.exe"
4. Pronto, agora só basta jogar!







# Markdow - Funcionalidades
- [X] Implementar Classe
- [X] Validação de arquivos score e palavras
- [X] Implementação interface textual
- [X] Execução jogo da Forca
- [ ] Compilação automatizada

# Limitações

* A validação dos arquivos nao funciona para espaços vazios
* Bonequinho enforcado aparece apenas se der game over
* Não atualização do arquivo score, apenas a criação de um novo para a pontuação atual
* A seleção de palavras de acordo com o nível está muitoo superficial e possui falhas


# Avaliação

## Código | Funcionalidades
1. Classe forca 10/10
- Acho que ficou meio distribuido entre as interface.hpp e a classe usuario, mas vou considerar.
- Veja que um bom exemplo onde vc poderia criar uma nova classe era em "interface.hpp", uma classe Interface cairia bem. Da
mesma forma arq.hpp, poderia ser uma classe, tipo Arquivo, com os métodos seriam as funções que vc implementou.
- O nome classe.hpp não é muito bom, como dentro vc implementa a classe Usuario, o melhor nome seria usuario.hpp.

2. Interface textual 10/10
- ficou muito boa

3. Execução completa do jogo 10/15
- Faltou sortear as letras de handcap nos modos fácil e médio
- Da forma como vc implementou, o jogador só joga uma palavra, como conversamos o ideal aqui era vc abrir o arquivo
e guardar todas as palavras em um vector, logo de cara. Assim vc poderia manipular o vector para sortear palavras,
por exemplo.

4. Validação dos arquivos de texto 5/5
- Vc implementou algumas validações então vou considerar. Porém o programa não deveria continuar quando um arquivo inválido
fosse encontrado.

5. Arquivos de teste de validação dos casos de erro 0/5
- A ideia aqui era vc prover arquivos que mostrassem as validações que vc fez.

6. Arquivos de teste de validação dos níveis de dificuldade 1/5
- Vou considerar o arquivo já fornecido como parte deste quesito, mas a ideia era vc construir arquivos de texto
que mostrassem os níveis de dificuldade e permitissem testar o fim de jogo.

7. Observações gerais
- A forma como vc escolheu dividir as funcionalidades ficou muito boa, porém você deveria dividir em hpp / cpp como conversamos
na entrevista.
- Dividi o seu arquivo func.hpp em dois pra vc tentar usar depois como referencia: para compilar o projeto agora vc precisa fazer
`g++ main.cpp func.cpp -o main`.
- A forma de compilação que você está usando não é automática então os includes sempre ficam com base no lugar onde rodamos o compilador,
tipo main.cpp tem que incluir "../header/geral.hpp", essa forma de incluir não é boa, pois depende de onde compilamos o código. O melhor
nesse caso é vc informar ao compilador onde buscar os .hpp e incluir no main apenas "geral.hpp", mas ao invés de fazer isso sugiro
que tente usar uma forma automática de compilação.

## Código | Boas práticas

1. Documentação do código e readme 5/10
- Os códigos não estão documentados seguindo o formato especificado (Doxygen)

2. Organização e indentação 5/10
- Vou considerar que ficou bem organizado embora não tenha sido dividido em classes o principal problema foi não dividir em .hpp e .cpp

3. Compilação automatizada 0/5


