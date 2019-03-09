
# Branching usando Git/Github

Este documento apresenta uma proposta de um _workflow_ para _branching_  padrão para os projetos
de software desenvolvidos.


## Branches Principais

Existirão duas branches principais, paralelas e com ciclo de vida **infinito**: `master` e `develop` (antiga `staging` ou `homologacao`) 

### Branch `master`
A branch `master` representa código em produção, onde seu `HEAD` reflete para o ponto em que o 
servidor de produção está rodando. É a primeira branch criada no projeto. 

> Todo commit na `master` constitui uma nova release.

Deverão ser utilizadas ferramentas para realização automática do deploy ao servidor de produção,
ao atualizar a `master`.


### Branch `develop`
É a branch que representa o estado das últimas alterações para uma nova `release`.

É nessa branch que devem ser executados os testes de CI.

O objetivo é que quando esta branch alcança um estado estável e está pronta para se tornarem uma release,
as alterações deverão ser mescladas (`merge`) com a `master`, por meio adequados, tratados a seguir.

## Branches de Apoio

Cada uma das branches a baixo, possui um propósito definido distinto e ambas possuem ciclo de 
vida **finito**. Todas elas possuem uma branch de origem (de onde serão iniciadas) e um destino
(onde serão mescladas).

### Branch de features
|Branch  |  `features` |
|--|--|
|Origem  |  `develop` |
|Destino  |  `develop` |
|Convenção de nome  |  Qualquer um, exceto `master`, `develop`, `release-*` ou `hotfix-*` |

#### 1. Criando uma branch de feature

Deve ser ramificada da branch `develop`:
```
git checkout -b nova-feature develop
```

#### 2. Incorporando um feature finalizada

Features que sejam finalizadas, deverão serem incorporadas na branch `develop`
através de um pull request, porém antes de o fazer, é necessário que haja uma limpeza 
dos commits e do histórico.

#### 2.1 Limpando o histórico e preparando o `PR`

#### 2.1.1 `Squash` suas alterações
Muitas vezes, enchemos nossa branch de trabalho com um grande número de pequenos 
commits não importantes ao projeto em si (e.g _"Corrigida identação"_, _"Removido debug"_, etc.).
Esses commits prejudicam o review do pull request e podem ser agrupados em um só commit, 
melhorando a legibilidade do projeto.

Para isso, utilizamos um `rebase` interativo.

#### 2.1.2 Rebase interativo
Este comando permite a limpeza de commits (junção de commits) de forma interativa.

Para executá-lo, para ter em mente uma quantidade de commits passados desejados a serem avaliados. 
Por exemplo, se você deseja revisar os 6 último commits:

```
git rebase -i HEAD~6
```

Esse comando abrirá um editor com os 6 commits, em ordem contrária. Como o disposto abaixo:

```
pick 12de42a Adicionada nova feature X
pick 17dc92g Corrigido PEP8 
pick 84gh17s Remoção de depuração 
pick 91jc32j Merge from origin/develop 
pick 44nc12s Adicionado comentário no arquivo Y
pick 19kk21a Correções do review
```

Existem 3 comandos para nos ajudar a escolher o que/como manter:

- `pick`: usado para manter um commit, da maneira que está atualmente;
- `squash`: usado para dar um `amend` (juntar o commit com o próximo), perguntando pelo nome do novo commit;
- `fixup`: usado para dar um `amend`, sem perguntar pelo nome do novo commit.

Desta forma, se modificando o arquivo aberto da seguinte maneira:

```
pick 12de42a Adicionada nova feature X
fixup 17dc92g Corrigido PEP8 
fixup 84gh17s Remoção de depuração 
pick 91jc32j Merge from origin/develop 
squash 44nc12s Adicionado comentário no arquivo Y
pick 19kk21a Correções do review
```

Teremos o seguinte resultado final:

```
73tr46s - Correções do review
90al28h - Melhoria na legibilidade e entendimento da feature
65nf79m - Adicionada nova feature X
```


#### 2.1.3 Faça um `rebase`
Na maioria dos casos, pessoas trabalharão, em paralelo, em features diferentes, mas que podem 
alterar linhas de código em comum, gerando **conflitos**. 

Por exemplo, um dev **X** inicia o trabalho em uma feature **A** e outro dev **Y** trabalha em uma
feature **B**. Suponha que o dev **X** tenha submetido um pull request que foi aprovado
e mesclado na `develop` antes do dev **Y**. Se eles trabalharam em algum trecho de código
em comum, então a branch da feature **B** possui conflitos agora, impedindo o dev **Y** de 
realizar o merge da sua feature quando finalizá-la. 

Uma forma de resolver esses conflitos é utilizando o `rebase`. O `rebase` é uma 
estratégia de incorporação de código diferente do `merge` e que, dentre suas aplicações,
fornece uma resolução de conflitos mais limpa, commit por commit, facilitando sua solução e aumentando a legibilidade. 
O `rebase` gera um histórico linear da projeto, uma vez que os commits são incorporados um a um
na branch base (para qual vamos realizar o `rebase`), e não todos de uma vez, como no `merge`.

Para realizar um rebase estando na sua branch de feature baseado na branch `develop`:

```
git rebase origin/develop
git push -f origin nova_feature
```

A resolução de conflitos, caso existam, será solicitada um a um.

Repare o `-f` no push realizado após o `rebase`. É o mesmo que `--force` e é necessário
pois sua branch remota ainda não possuirá as referências para o conteúdo atualizado com o
`rebase`.


> Verificar as referências para mais informações.


#### 3. Deletando a branch de feature

Após a limpeza do histórico, aprovação do pull request e a mesclagem do código da 
branch de feature na `develop`, a primeira não fará mais sentido e deverá ser excluída.

O processo pode ser feito pela própria interface do _GitHub_ após a confirmação do merge.


### Branch de releases
|Branch  |  `releases` |
|--|--|
|Origem  |  `develop` |
|Destino  |  `develop` **e** `master` |
|Convenção de nome  |  `release-*` |

As features de releases existem para permitir um estado limpo para a preparação para
uma nova release. Nela são preparadas os metadados (número da versão, build dates, etc.) 
e corrigidos **pequenos bugs**. Fazendo isso nesta branch, liberamos a `develop` para continuar
recebendo novas features para o próximo release.

O momento ideal para a criação de uma branch de release é quando o estado da `develop`
reflete um estado quisto para uma nova release, ou seja,  quando todas as features esperadas foram
mescladas na `develop`.

> **Não devem ser desenvolvidas novas features dentro das branches de release!**

#### Criando uma branch de release
As features de release são criadas a partir da `develop`:

```
git checkout -b release-1.2 develop
./bump-version.sh 1.2
git commit -a -m "Bumped número da versão para 1.2"
```

O script `bump-version.sh` representa uma atualização de arquivos para a nova 
versão do projeto. Pode ser feito manualmente, mas é quisto que haja um script para
automatização do mesmo.

#### Incorporando uma branch de release

Quando a branch de release está pronta para ser lançada, o primeiro passo é mesclá-la com a `master`, através de um pull request.
Lembre-se de sempre prezar pelo histórico limpo em qualquer branch. Portanto os passos realizados para incorporação de código nas
branches de feature devem aqui também serem assumidos.

Após isso, no commit gerado no `master`, deve ser adicionado uma tag para facilitar a identificação do mesmo
posteriormente. Finalmente, as alterações realizadas (correção de pequenos bugs) devem voltar para a `develop` através de um
pull request.

Desta forma, após submeter, aprovar e mesclar o PR na `master`, faça:
```
git checkout master
git tag -a 1.2
```

### Branch de hotfix
|Branch  |  `hotfixes` |
|--|--|
|Origem  |  `master` |
|Destino  |  `develop` **e** `master` |
|Convenção de nome  |  `hotfix-*` |


Parecidas com as branches de release, as branches de hotfixes agem para preparar código para uma
nova release de produção. O principal ponto que as diferem e faz com que haja a necessidade da criação da última, 
é seu caráter urgencial. 

Essas branches são usadas para correção de bugs severos/críticos que devam ser corrigidos imediatamente.

O principal ponto é que essas branches permitem que demais membros continuem a trabalhar na `develop` normalmente e
que outra pessoa trabalhe na correção do erro.


#### Criando uma branch de hotfix
Estas branches devem ser criadas a partir da última versão da `master`:

```
git checkout -b hotfix-1.2.1 master
./bump-version.sh 1.2.1
git commit -a -m "Bumped número da versão para 1.2.1"
```

Não deve ser esquecida a atualização, novamente, do número da versão nos arquivos.

#### Incorporando uma branch de hotfix
Quando finalizada a branch de hotfix deve ser retornada para a master, através de um pull request,
assim como nas branches de release: 

```
git checkout master
git tag -a 1.2.1
```

Após isso, o código deve ser mesclado também à `develop` para garantir que o bug não se perdure.
Claro, utilizando um pull request **limpo** para tal.

**ATENÇÃO**: Uma única exceção a esse caso é quando uma branch de release da versão atual do sistema ainda existe. Neste 
caso, o código deve voltar para ela, ao invés de voltar para a `develop`. 

> Nesta exceção, o código retornará para a `develop` quando a branch de release for finalizada.


## Referências

- https://git-scm.com/book/pt-br/v1/Ramifica%C3%A7%C3%A3o-Branching-no-Git-Rebasing

- https://medium.com/vtex-lab/por-que-voc%C3%AA-deveria-usar-git-rebase-d75b41e900f2

- https://nvie.com/posts/a-successful-git-branching-model/

- https://github.com/mockito/mockito/wiki/Using-git-to-prepare-your-PR-to-have-a-clean-history

- https://github.com/edx/edx-platform/wiki/How-to-Rebase-a-Pull-Request
