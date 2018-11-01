# Configurando o Django com um teste funcional

## Obedeça ao Testing Goat! Não faça nada até ter um teste.

~ Baby steps: small, incremental code changes, driven by the tests ~

> Historicamente, uma aplicação quase _default_ quando é ensinado o TDD é a manipulação de números romanos. Um exemplo disso pode ser acessado [aqui](https://github.com/hjwp/tdd-roman-numeral-calculator)

### Primeiro passo: Preparação do ambiente
0- Criar virtualenv

1- Instalar o `Firefox` 

2- Instalar o `Geckodriver` 
> É o driver que nos permite controlar, remotamente, o Firefox por meio do selenium

3- Instalar o `Selenium` 
```
pip install selenium
```

4- Instalar o `Django` 
```
pip install Django
```

### Criando o primeiro teste funcional

1- `_functional_tests.py_`
```python
from selenium import webdriver

browser = webdriver.Firefox()
browser.get('http://localhost:8000')

assert 'Django' in browser.title
```

### Falhe e depois faça o teste passar!
