# beecrowd 1205 - Cerco a Leningrado

## Enunciado

A cidade de São Petersburgo mudou de nome depois da revolção russa em 1914 para Petrogrado. Após a morte de Lênin, em homenagem ao grande líder o nome da cidade mudou novamente para Leningrado em 1924, e assim permaneceu até o fim da União Soviética. Em 1991, a cidade voltou a ter o nome antigo. Durante a segunda guerra mundial a cidade de Leningrado sofreu um cerco das tropas alemãs que durou cerca de 900 dias. Foi uma época terrível, de muita fome e perdas humanas, que terminou em 27 de janeiro de 1944 com a vitória dos soviéticos. É considerada uma das vitórias mais custosas da história em termos de vidas humanas perdidas.

No auge da ofensiva alemã, no ano de 1942, vários atiradores de elite foram espalhados pela cidade, inclusive, em alguns pontos estratégicos da cidade mais de um atirador aguardavam soldados inimigos. A espionagem russa tinha informações detalhadas das habilidades desses atiradores, mas seus esconderijos eram excelentes, tornando a tarefa de um soldado soviético que desejasse cruzar a cidade extremamente difícil. Os soldados soviéticos eram bem treinados, mas com o passar do tempo e a continuação do cerco à cidade, os melhores soldados foram sendo dizimados, uma vez que se errassem o alvo na primeira tentativa certamente eram mortos pelos soldados alemães na tocaia.

Sabendo a probabilidade de um soldado em matar um atirador alemão e sabendo também o número de balas que ele tinha à sua disposição, desejamos saber a probabilidade desse soldado conseguir chegar a um ponto estratégico de destino, partindo de um ponto estratégico de origem. O soldado, sendo muito experiente, sempre usava um caminho que maximizava a probabilidade de sucesso. Note que o soldado deve matar todos os atiradores presentes no caminho usado, inclusive os que estiverem nos pontos estratégicos de origem e destino.

## Entrada

A entrada é composta por diversas instâncias e termina com final de arquivo (EOF). A primeira linha de cada instância contém 3 inteiros, **N** (2 ≤ **N** ≤ 1000), **M**, e **K** (0 ≤ **K** ≤ 1000) e a probabilidade **P** (0 ≤ **P** ≤ 1) do soldado matar um atirador. Os inteiros **N**, **M**, e **K** representam respectivamente os números de pontos estratégicos, estradas ligando pontos estratégicos e balas carregadas pelo soldado soviético. Os pontos estratégicos são numerados de 1 a **N**.

Cada uma das próximas **M** linhas contém um par de inteiros **i** e **j** indicando que existe uma estrada ligando o ponto **i** ao **j**. Em seguida tem uma linha contendo um inteiro **A** (0 ≤ **A** ≤ 2000), correspondendo ao número de atiradores na cidade, seguido por **A** inteiros indicando a posição de cada atirador. A última linha de cada instância contém dois inteiros indicando o ponto de partida e o destino do soldado.

## Saída 

Para cada instância imprima uma linha contendo a probabilidade de sucesso do soldado soviético. A probabilidade deve ser impressa com 3 casas decimais.

**Obs**: Exemplos de entrada e saída podem ser encontrados em [in.txt](./in.txt) e [ans.txt](./ans.txt), respectivamente.

## Solução

Para calcular a probabilidade de sucesso do soldado soviético foi utilizado o algoritmo de Dijkstra (Adaptado de [Edson Alves](https://github.com/edsomjr/TEP/blob/master/Grafos/slides/dijkstra/dijkstra.pdf)). O peso das arestas foi definido de acordo com a quantidade de atiradores em cada ponto estratégico e assim foi possível obter o caminho com o menor número de atiradores. 

Com isso, nos casos em que o caminho entre os 2 pontos estratégicos existe e o soldado possui balas suficientes (**K**) para matar todos os atiradores, a probabilidade foi calculada elevando a probabilidade do soldado matar um atirador (**P**) à quantidade de atiradores no menor caminho.
