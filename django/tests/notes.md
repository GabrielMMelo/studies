# Testes

## Boas práticas

1. Se algo pode ser quebrado, isso deve ser testado. Isso inclui models, views,
    forms, templates, validators, etc.
2. Cada teste deve testar *apenas uma* função
3. _Keep it simple_. Você não quer ter testes em cima de outros testes
4. Execute testes sempre que houver um _pull_ ou _push_ no repositório e, em 
    um ambiente de homologação, antes de dar _push_ para produção.
