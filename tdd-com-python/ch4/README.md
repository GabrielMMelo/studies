# O que estamos fazendo com todos esses testes? (E a refatoração)

Os testes nos garantem um `placeholder`, um estado seguro de nossa aplicação que incrementa aos poucos (também de forma segura). 

Outro ponto substancial do desenvolvimento direcionado por testes é que não precisamos saber exatamente onde paramos de trabalhar, **basta executarmos os testes!**

**REFATORAÇÃO**: melhorar o nosso código sem que seja alterada sua funcionalidade.

> É importante que a refatoração não inclua, nem remova, funcionalidades atuais.

## Não teste constantes! Use templates.
Ao invés de utilizarmos strings HTML (que se assemelham à constantes) para asserção, usaremos **templates**. Desta forma, verificaremos se a página renderizada é igual ao template esperado.

Utilizaremos o `Django Test Client` para isso.

O código dos nossos testes unitários (`core/tests.py`) ficaria da seguinte forma:

```python

from django.test import TestCase

class IndexPageTest(TestCase):
    def test_index_page_returns_correct_html(self):
        response = self.client.get('/')
        self.assertTemplateUsed(response, 'core/base.html')
```

> **IMPORTANTÍSSIMO**: ao refatorar, trabalhe no código ou nos testes. Nunca modifique ambos ao mesmo tempo!
