# C

Mano, o que está acontecendo com o printf é uma questão de **tipo de dado**.

Por exemplo, você está utilizando o seguinte trecho de código:

```c
    for (int i = 0; i < tam; i++){
        printf("Nome: %s\n", &alunos[i].nome);
        printf("A matricula eh: %d\n\n", alunos[i].matricula);
    }
```

Bem, vamos analisar o que está acontecendo.

Quando você utiliza:

```c
printf("Nome: %s\n", &alunos[i].nome);
```

você está pedindo para que o console imprima (`printf`) em um formato de _string_ 
(`%s`) o conteúdo de Aluno.nome (`char`).

1. Um `char` representa apenas **um** caractere. Uma `string` nada mais é do 
que um **vetor de `char`**. O `scanf` recebe um endereço de memória, como parâmetro, indicando onde
a informação lida deve ser armazenada. Desta forma, quando utilizamos um `scanf` para receber algum texto: 

```c
scanf("%s", &alunos[i].nome);
```

receberemos uma `string` (por causa do `%s`) que será montada em um vetor (de `char`, pois cada caractere
do nome do aluno será um `char`) iniciado na posição de `alunos[i].nome`.

Observando mais, uma _string_ pode ser declarada da mesma forma:

```c
char str[30] = "seu_texto_aqui";
```


2. E **todo vetor** nada mais é do que um **ponteiro** para o primeiro elemento de uma 
sequência de elementos (_i.e_ o primeiro elemento tem a mesma posição de memória do que o _vetor_,
 propriamente dito). Ou seja, suponha a declaração de um vetor:

```c
int vetor[5]; 
```

A posição de memória de vetor (_i.e._ `&vetor`) é exatamente a mesma de `&vetor[0]`.


### Conclusão

Com isso, sabemos que tentar recuperar a informação de Aluno.nome em formato de `string` (_i.e_ o nome completo), 
implica em acessar a posição de memória que representa o início desse vetor de `char`.

Por isso, é necessário o uso do `&` para quando formos imprimir uma `string` (um vetor de `char`).

Caso não seja usado o `&`, o `printf` tentará imprimir um vetor, no caso de uma entrada _"Vinícius"_, por exemplo, buscando pela posição
de memória _"V"_ (_i.e_ o primeiro caractere da string), o que não faz sentido.

> Na verdade, imagino que, neste caso, o _"V"_ deva ser convertido em um número, pela tabela ASCII. 
 
Para finalizar, façamos um exemplo para ajudar no entendimento. Se utilizarmos um `%c` (formato de `char`), 
ao invés de `%s` e retirarmos o `&`, como o trecho abaixo:

```c
    for (int i = 0; i < tam; i++){
        printf("Nome: %c\n", alunos[i].nome);
        printf("A matricula eh: %d\n\n", alunos[i].matricula);
    }
```

Obteremos apenas o primeiro caractere do nome do aluno (o primeiro char). Caso incluamos 
o `&`, o console imprimirá o número referente à posição de memória daquele caractere.


### Extra 

O **C++** possuí o tipo de dados `string`, por padrão. Não sendo necessária a declaração
de um vetor de `char` para armazenar um texto.

Além disso, ele possui o `cin` e `cout` que são, respectivamente, funções de leitura e escrita
padrão do console na linguagem.
