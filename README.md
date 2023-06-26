# Concord

Project making a Discord app using C++ at the college subject "Programing Language". 

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

## Compilação e execução
1. Certifique-se de ter um compilador C++ instalado no seu sistema.
2. Abra um terminal e navegue até o diretório onde o arquivo `nome-do-arquivo.cpp` está localizado.
3. Compile o programa usando o seguinte comando:
        g++ -o nome-do-executavel nome-do-arquivo.cpp
        g++ main.cpp -o programa

Certifique-se de substituir `nome-do-executavel` pelo nome que você deseja dar ao arquivo executável e `nome-do-arquivo.cpp` pelo nome real do arquivo do programa.

4. Após a compilação bem-sucedida, execute o programa com o seguinte comando:
        ./nome-do-executavel
        ./programa

## Roteiro de entradas e comandos
Aqui está um exemplo de roteiro para executar o programa e destacar suas funcionalidades:

1. Execute o programa seguindo as instruções acima.
2. Na tela do programa, você será solicitado a fornecer [informações ou dados específicos que o programa requer].
3. Digite as informações solicitadas e pressione Enter.
4. O programa irá [descreva o que o programa fará com base nas informações fornecidas].
5. Observe os resultados na tela e siga as instruções adicionais, se houver.
6. Repita os passos 2 a 5 para explorar outras funcionalidades do programa.
7. Para encerrar o programa, siga as instruções fornecidas ou pressione Ctrl + C no terminal.

## Notas adicionais
[Adicione qualquer informação adicional relevante sobre o programa, como requisitos de sistema, bibliotecas externas usadas, etc.]