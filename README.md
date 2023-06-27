<h1 align="center"> Concord </h1>

<div align="center">

<h4>⭐ Esté projeto é uma simulaçao do aplicativo Discord em C++ para o trabalho da disciplina de Linguagem de Programação. ⭐️</h4>
  <img height="65" src="./assets/cpp.png">&nbsp;&nbsp;&nbsp;&nbsp;<img src="https://img.icons8.com/cute-clipart/64/null/services.png"/><a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<img height= "50" src= "https://assets-global.website-files.com/6257adef93867e50d84d30e2/636e0a6a49cf127bf92de1e2_icon_clyde_blurple_RGB.png">
</a>
</div>

## Identificação do estudante
- Nome: Arthur Ferreira de Holanda
- Matrícula: 20220039547

## Descrição do programa

O código em C++ apresenta uma implementação básica de um sistema de chat em um servidor. Ele é dividido em várias classes, cada uma responsável por um aspecto específico do sistema.

## Compilando

Este projeto pode ser compilado com o CMake. 

Para compilar este projeto com o CMake, siga estas etapas (a partir da pasta raiz):

1. `cmake -S source -B build`: solicita ao CMake que crie o diretório de compilação e gere o Makefile Unix com base no script encontrado em source/CMakeLists.txt, no nível atual.
2. `cmake --build build`: inicia o processo de compilação que cria os dois alvos (executáveis) dentro de build.

O executável é criado dentro do diretório `build` que caso não tenha sido criada antes, é criada no momento do comando `cmake -S source -B build`.

Para executar os testes, você tem duas opções:

1. Acesse o diretório `build` com o comando cd build e execute os testes com `./Concord`.
2. Execute os testes diretamente com o comando `./build/Concord` a partir da pasta raiz do projeto.

O diretorio contem um script de teste, caso queira o testar, use `./build/Concord < script.txt` na pasta raiz do projeto.
## Comandos

Caso precise de ajuda quando executando, você pode usar o comando `help` que fornece a lista de comandos inteira.

### Deslogados

Esses comandos podem ser executados caso o usuário não esteja logado.

- `quit` sai do sistema.
- `create-user <email> <senha> <nome>` cria um usuário. Apenas o nome pode ter
espaços. Dois usuários não podem ter o mesmo email.
- `login <email> <senha>` faz login em um usuário já criado.

### Logados

Esses comandos só podem ser executados caso o usuário esteja logado.

- `disconnect` desconecta o usuário logado.
- `create-server <nome>` cria um servidor.
- `list-servers` lista todos os servidores criados.
- `enter-server <nome> [codigo]` entra no servidor especificado. O código só
é necessário caso o servidor tenha um. O dono do servidor pode entrar sem
utilizar o código.

### Dono do servidor

Esses comandos só podem ser executados caso você seja o dono do servidor.

- `set-server-desc <nome> "<descrição>"` altera a descrição do servidor.
- `set-server-invite-code <nome> [codigo]` altera o código de convite do 
servidor.
- `remove-server <nome>` remove o servidor.

### Dentro de um servidor

Esses comandos só podem ser executados dentro de um servidor.

- `leave-server` sai do servidor.
- `list-participants` lista os participantes do servidor.

