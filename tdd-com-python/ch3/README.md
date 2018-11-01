# Testando uma página inicial simples com testes de unidade

## Como testes de unidade se diferem dos testes funcionais?

A principal diferença é que teste funcionais testam o sistema por uma perspectiva externa, quando os testes unitário o faz baseado no ponto de vista do programador

Os **testes funcionais** tem a finalidade de manter a aplicação com funcionalidades corretas, de acordo com as regras de negócio, e garantir que não ocorrerão falhas acidentais.

Os **testes unitários** garantem que o código-fonte escrito seja limpo e livre de bugs.

 O fluxo de trabalho em TDD é dado, basicamente, por:

1 - Escrita de um teste funcional, descrevendo uma nova funcionalidade do **ponto de vista do usuário**;

2 - Escrita de um (ou mais) teste unitário com o objetivo de fazer o teste funcional passar. A ideia é que cada linha do código de produção passe por, pelo menos, um teste unitário.

3 - Após a falha nos testes unitários, é realizada a escrita, na menor quantidade possível, um código de aplicação suficiente para que os façam passar. 

> É cabível iterar sobre os passos _2_ e _3_ algumas vezes de forma a obter um teste funcional com mais avanço.

4 - Execução do teste funcional e escrita dos próximos.

## Testes unitários com Django

É sugerida a utilização de uma versão especial do Django do TestCase. Esta é uma versão expandida e especificada para aplicações Django do unittest.TestCase padrão.

O arquivo de testes unitário de uma App em Django é o `App/tests.py`. Desta forma, o `core/tests.py` poderia ser:

```python

from django.urls import resolve
from django.test import TestCase
from core.views import (
    index
)

class IndexPageTest(TestCase):
    def test_root_url_resolves_to_index_page(self):
        found = resolve('/')
        self.assertEqual(found.func, index)

    def test_index_page_returns_correct_html(self):
        request = HttpRequest()
        response = index(request)
        html = response.content.decode('utf8')
        self.assertTrue(html.startswith('<html>'))
        self.assertIn('<title>Recrear</title>', html)
        self.assertTrue(html.endswith('</html>'))
```



