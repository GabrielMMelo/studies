
# Permissions

Juntamente com a `authentication` e o `throttling`, a `permission` determina se
uma requisição deve ser permitida ou negada.

## Uso
Para limitar o acesso a uma determinada `View` (ou `ViewSet`), basta explicitar
as `permissions` que esta deverá verificar:

``` python
from rest_framework import viewsets
from rest_framework.permissions import IsAuthenticated

class ExampleViewSet(viewsets.ModelViewSet):
    permission_classes = (IsAuthenticated,)
```

## Permissões customizadas

É necessário realizar a sobrescrita da classe `BasePermission` e implementar
pelo menos um dos dois métodos abaixo, retornando, obrigatoriamente, `True` ou 
`False`:

```
.has_permission(self, request, view)
```

```
.has_object_permission(self, request, view, obj)
```

Para verificar se uma requisição é de leitura ou escrita, utiliza-se a tupla 
SAFE_METHODS (que contém `('GET', 'HEAD', 'OPTIONS')`):

```python
def has_permission(self, request, view):
    if request.method in permissions.SAFE_METHODS:
        # Check permissions for read-only request
```




> https://www.django-rest-framework.org/api-guide/permissions/
