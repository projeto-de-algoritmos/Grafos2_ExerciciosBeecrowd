# beecrowd 1148 - Países em Guerra

## Enunciado

No ano 2050, após diversas tentativas da ONU de manter a paz no mundo, explode a terceira guerra mundial. Segredos industriais, comerciais e militares obrigaram todos os países a utilizar serviços de espionagem extremamente sofisticados, de forma que em cada cidade do mundo há ao menos um espião de cada país. Esses espiões precisam se comunicar com outros espiões, com informantes e mesmo com as suas centrais durante as suas ações. Infelizmente não existe uma forma segura de um espião se comunicar em um período de guerra, então as mensagens são sempre enviadas em código para que somente o destinatário consiga ler a mensagem e entender o seu significado.

Os espiões utilizam o unico serviço que funciona no período de guerra, os correios. Cada cidade possui uma agência postal onde as cartas são enviadas. As cartas podem ser enviadas diretamente ao seu destino ou a outras agências postais, até que a carta chegue à agência postal da cidade de destino, se isso for possível.

Uma agência postal na cidade A pode enviar diretamente uma carta impressa para a agência postal da cidade B se houver um acordo de envio de cartas, que determina o tempo, em horas, que uma carta leva para chegar da cidade A à cidade B (e não necessariamente o contrário). Se não houver um acordo entre as agências A e B, a agência A pode tentar enviar a carta a quantas agências for necessário para que a carta chegue ao seu destino, se isso for possível.

Algumas agências são interligadas por meios eletrônicos de comunicação, como satélites e fibras ópticas. Antes da guerra, essas ligações atingiam todas as agências, fazendo com que uma carta fosse enviada de forma instantânea, mas durante o período de hostilidades cada país passou a controlar a comunicação eletrônica e uma agência somente pode enviar uma carta a outra agência por meio eletrônico (ou seja, instantaneamente) se ela estiver no mesmo país. Duas agências, A e B, estão no mesmo país se houver uma forma de uma carta impressa enviada de uma das agências ser entregue na outra agência.

O serviço de espionagem do seu país conseguiu obter o conteúdo de todos os acordos de envios de mensagens existentes no mundo e deseja descobrir o tempo mínimo para se enviar uma carta entre diversos pares de cidades. Você seria capaz de ajudá-lo?

## Entrada

A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém dois inteiros separados por um espaço, N (1 ≤ N ≤ 500) e E (0 ≤ E ≤ N2), indicando o número de cidades (numeradas de 1 a N) e de acordos de envio de mensagens, respectivamente. Seguem-se, então, E linhas, cada uma com três inteiros separados por espaços, X, Y e H (1 ≤ X, Y ≤ N, 1 ≤ H ≤ 1000), indicando que existe um acordo para enviar uma carta impressa da cidade X à cidade Y , e que tal carta será entregue em H horas.

Em seguida, haverá uma linha com um inteiro K (0 ≤ K ≤ 100), o número de consultas. Finalmente, virão K linhas, cada uma representando uma consulta e contendo dois inteiros separados por um espaço, O e D (1 ≤ O, D ≤ N). Você deve determinar o tempo mínimo para se enviar uma carta da cidade O à cidade D. A entrada termina quando N = E = 0.

## Saída 

Para cada caso de teste da entrada seu programa deve produzir K linhas na saída. A I-ésima linha deve conter um inteiro M , o tempo mínimo, em horas, para se enviar uma carta na I-ésima consulta. Se não houver meio de comunicação entre as cidades da consulta, você deve imprimir ”Nao e possivel entregar a carta”(sem acentos).

Imprima uma linha em branco após cada caso de teste.

**Obs**: Exemplos de entrada e saída podem ser encontrados em [in.txt](./in.txt) e [ans.txt](./ans.txt), respectivamente.

## Solução

Um dos pontos principais a se levar em consideração no problema (e que é até um pouco confuso no enunciado) é a caracterização de que duas agências estão na mesma cidade, e assim, o tempo gasto para enviar uma carta entre elas é 0 (zero). Para essa identificação, é necessário considerar que agências **A** e **B** estão na mesma cidade se existe um acordo para envio de mensagens de **A** para **B** e de **B** para **A**. No código, essa identificação foi realizada utilizando a função [find_if](https://cplusplus.com/reference/algorithm/find_if/) do C++, salvando o tempo (custo) como 0 quando o padrão fosse identificado.

Para calcular o tempo mínimo para se enviar uma carta entre as agências foi utilizado o algoritmo de Floyd-Warshall (Adaptado de [Edson Alves](https://github.com/edsomjr/TEP/blob/master/Grafos/slides/floyd-warshall/floyd-warshall.pdf)). A escolha pelo algoritmo se deu pelo fato do problema possuir várias consultas com diferentes origens e destinos e como o algoritmo Floyd-Warshall computa a distância mínima entre todos os vértices do grafo, teria-se um gasto inicial para rodar o algoritmo O(V^3), mas depois todas as consultas seriam O(1).
