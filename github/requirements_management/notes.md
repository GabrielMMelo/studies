# Gerenciamento de requisitos de projeto pelo Github seguindo uma metodologia ágil

Este resumo foi baseado no artigo "Requirements management in GitHub with a 
lean approach", disponível em  "https://pdfs.semanticscholar.org/6798/d5be638f26dcba07f5c23ea1a075c9557300.pdf"
que apresenta um _guideline_ sobre aplicação de gerenciamento de requisitos
por uma abordagem _lean_ utilizando o GitHub.

Todo o disposto aqui segue a _guideline_ proposta e apresenta seu workflow,
aspectos positivos e negativos.

# Issues, tasks e requisitos para a _guideline_
As **issues** consistem em um conceito de alto nível, podendo representar um 
requisito do sistema ou uma tarefa (_task_).

- Tarefa (_task_): Um item concreto que deve ser implementado para que seja
satisfeito um requisito do sistema.

- Requisitos: Representam objetivos, regras de negócios e requisitos do usuário
para o software. Os requisitos são mais abstratos, quando comparados às _tasks_.

Ambos podem ser divididos em **principal** e **subnível**.

- Subnível: Usado quando um requisito ou tarefa é demasiado grande, fazendo
que haja sentido fragmentá-lo em subcomponentes.

É adotado um máximo de 4 níveis de profundidade de uma issue: requisito ->
subrequisito -> task -> subtask

Pontos positivos e negativos em utilizar subtask:

Positivos: As informações então acessíveis aos olhos, sem esforço.

Negativos: Despendimento de tempo (mais tempo gasto com a criação da subtask
do que com seu desenvolvimento)


# Passos para criação de uma issue

Primeiramente, a tarefa de criação de issues deve ser uma atribuição de todo
o time. Os **requisitos** devem ser adicionados por um grupo específico do
time que mantém o contato e representação do cliente, porém as **tasks** 
devem envolver todos. Isso porque desenvolvedores experientes podem ter 
meios soluções mais limpas e otimizadas de se resolver uma tarefa. Além disso,
a participação de desenvolvedores no processo, ajuda no espírito de equipe e 
os mantém mais próximo do projeto.

No decorrer do projeto, novos requisitos serão adicionados, modificados, 
cancelados e rejeitados.

A criação consiste em **7 passos**:

## 1 Decida o o título da issue.

Deverá ser incluída uma referência diferente
para requisitos e _tasks_ (e.g "R1.1" para um subrequisito e "T2" para uma 
_task_)

## 2 Definição da descrição da Issue.

Muita informação pode desviar a atenção 
do ponto principal, porém informações insuficientes estigam o leitor a adivinhar
algo e errar - _quase sempre_. Uma boa estratégia é anexar documentos, links e
imagens que possam auxiliar na compreensão de _tasks_ e utilizar a **Wiki** do
GitHub para documentar os requisitos.

A descrição pode se dividir em 4 partes:

- Sumário: explicação da issue em poucas palavras;

- Informação: Conteúdo consistido em informações relevantes, sendo essas,
preferencialmente, em links;

- Lista de tasks: é utilizada quando a _task_ envolve passos para a conclusão;

- Referencias: Se a _task_ é fragmentada em subtasks, então devem existir suas
referências (link para issue). Um problema identificado é que não é possível
estabelecer hierarquias entre issues, então a ligação é feita por links 
absolutos e _labels_.

## 3 Adicione as _labels_.

As _labels_ deverão ser divididas em 3 categorias, com
cores distintas entre si:

- Tipo da issue (Requisito, subrequisito, _task_, subtask);

- Prioridade (baixo, médio e alto); **MUITO IMPORTANTE PARA METODOLOGIAS ÁGEIS**

- _Miscellaneous_: outras informações interessantes para serem filtradas.

## 4 Atribuição de responsável(is)

## 5 Atribua um _Milestone_.

## 6 Publique a issue.

## 7 Atualize as referências de outras issues. Por exemplo, se a issue criada 
é filha de outra issue, então esta última deve ser atualizada com a referencia
para a nova.
