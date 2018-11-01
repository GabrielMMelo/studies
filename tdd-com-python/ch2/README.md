# Estendendo nosso teste funcional usando unittest

## Testes funcionais
Os testes funcionais têm como objetivo averiguar a aplicação por uma visão do usuário. Para isso, é descrita uma *User story* (História do usuário) com foco em narrar a experiência de um usuário com uma funcionalidade específica do sistema e como este se comporta.

> Os teste funcionais também podem ser referenciados como _testes de aceitação_ ou _testes fim a fim_.

## `_functional_tests.py_`
```python
from selenium import webdriver

# Eduardo recebe um link para acessar uma lista de presentes online para o chá de bebe do seu amigo, João. A empresa que gere a lista é a Recrear.
browser = webdriver.Firefox()
browser.get('http://localhost:8000')


# Ao acessar o link, ele encontra o nome da empresa (bem como a logo).
assert 'Recrear' in browser.title

# Após o Cabaçalho da página, um texto motivacional instrui Eduardo sobre o objetivo e funcionamento da página.

# Eduardo vê uma lista de presentes, com foto, preço e quantidade necessária restante para cada um.

# Eduardo escolhe seu presente clicando em 'comprar'. Ao realizar o clique, ele é direcionado para a página de pagamento da pagseguro.

# Após o pagamento, ele retorna a página que agradece a compra.

browser.quit()
```

> Sobre comentários: **Faça-o somente em casos necessários.** Um **bom código** é legível por si só. Ao comentar demasiadamente, é potencializado o risco de inconsistência entre comentários e código, uma vez que podemos, facilmente, nos esquecer de alterar um comentário quando o fazemos no código-fonte.


## Módulo `unittest`

Este módulo surge como uma boa alternativa para melhora na exibição e log dos tests realizados.

O código passado utilizando este módulo ficaria como o seguinte:

```python
from selenium import webdriver
import unittest

class NewVisitorTest(unittest.TestCase):
    def setUp(self):
        self.browser = webdriver.Firefox()

    def tearDown(self):
        self.browser.quit()

    def test_can_buy_a_product(self):
        # Eduardo recebe um link para acessar uma lista de presentes online para o chá de bebe do seu amigo, João. A empresa que gere a lista é a Recrear.
        self.browser.get('http://localhost:8000')

        # Ao acessar o link, ele encontra o nome da empresa (bem como a logo).
        self.assertIn('Recrear', self.browser.title)
        self.fail('finish the test!')

        # Após o Cabaçalho da página, um texto motivacional instrui Eduardo sobre o objetivo e funcionamento da página.

        # Eduardo vê uma lista de presentes, com foto, preço e quantidade necessária restante para cada um.

        # Eduardo escolhe seu presente clicando em 'comprar'. Ao realizar o clique, ele é direcionado para a página de pagamento da pagseguro.

        # Após o pagamento, ele retorna a página que agradece a compra.

if __name__ == "__main__":
    unittest.main(warnings='ignore')
```

> Qualquer método iniciado com "_test_" será executado pelo `test runner`.
