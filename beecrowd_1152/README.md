# beecrowd 1152 - Estradas Escuras

## Enunciado

Nestes dias se pensa muito em economia, mesmo em Byteland. Para reduzir custos operacionais, o governo de Byteland decidiu otimizar a iluminação das estradas. Até agora, todas as rotas eram iluminadas durante toda noite, o que custava 1 Dólar Byteland por metro a cada dia. Para economizar, eles decidiram não iluminar mais todas as estradas e desligar a iluminação de algumas delas. Para ter certeza que os habitantes de Byteland continuem a se sentirem seguros, eles querem otimizar o sistema de tal forma que após desligar a iluminação de algumas estradas à noite, sempre existirá algum caminho iluminado de qualquer junção de Byteland para qualquer outra junção.

Qual é a quantidade máxima de dinheiro que o governo de Byteland pode economizar, sem fazer os seus habitantes sentirem-se inseguros?

## Entrada

A entrada contém vários casos de teste. Cada caso de teste inicia com dois números **m** (1 ≤ **m** ≤ 200000) e **n** (**m**-1 ≤ **n** ≤ 200000), que são o número de junções de Byteland e o número de estradas em Byteland, respectivamente. Seguem **n** conjuntos de três valores inteiros, **x**, **y** e **z**, especificando qual será a estrada bidirecional entre **x** e **y** com **z** metros (0 ≤ **x**, **y** < **m** e **x** ≠ **y**).

A entrada termina com **m**=**n**=0. O grafo especificado em cada caso de teste é conectado. O tamanho total de todas as estradas em cada caso de teste é menor do que 2^31.

## Saída 

Para cada caso de teste imprima uma linha contendo a máxima quantidade diária de dólares de Byteland que o governo pode economizar.

**Obs**: Exemplos de entrada e saída podem ser encontrados em [in.txt](./in.txt) e [ans.txt](./ans.txt), respectivamente.

## Solução

Para resolver o exercício foi utilizado o algoritmo de PRIM (Adaptado de [Edson Alves](https://github.com/edsomjr/TEP/blob/master/Grafos/slides/prim/prim.pdf)) para encontrar a Árvore Geradora Mínima (caminho iluminado mais curto em que fosse possível ir de qualquer junção de Byteland para qualquer outra). Por fim, para encontrar o valor que o governo irá economizar, bastou subtrair o valor total que o governo paga atualmente (comprimento de todas as estradas somadas) pelo valor encontrado pelo algoritmo de PRIM.
