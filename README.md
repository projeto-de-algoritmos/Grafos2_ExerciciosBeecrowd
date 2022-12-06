# Exercícios Beecrowd

**Número da Lista**: 15<br>
**Conteúdo da Disciplina**: Grafos 2<br>

## Alunos
|Matrícula | Aluno |
| -- | -- |
| 18/0033034 | Hérick Ferreira de Souza Portugues |
| 18/0114093 | Lucas Ursulino Boaventura |

## Sobre 
Para o projeto foram realizados exercícios no juíz online beecrowd, utilizando os algoritmos Dijkstra, Floyd-Warshall e PRIM. Na pasta de cada exercício é possível encontrar a descrição dos problemas, o código e a explicação da solução.

Os exercício resolvidos foram:

- [1148 - Países em Guerra](https://www.beecrowd.com.br/judge/pt/problems/view/1148)
- [1205 - Cerco a Leningrado](https://www.beecrowd.com.br/judge/pt/problems/view/1205)
- [1152 - Estradas Escuras](https://www.beecrowd.com.br/judge/pt/problems/view/1152)

## Screenshots
![](https://cdn.discordapp.com/attachments/1020837143792341075/1049514399850823710/Screenshot_from_2022-12-05_23-31-51.png)
![](https://cdn.discordapp.com/attachments/1020837143792341075/1049514400790351923/Screenshot_from_2022-12-05_23-32-27.png)
![](https://cdn.discordapp.com/attachments/1020837143792341075/1049514401113309214/Screenshot_from_2022-12-05_23-32-31.png)

## Instalação 
**Linguagem**: C++<br>

**Pré-Requisito**: Compilador GCC

## Uso 

### 1. Entre na pasta do exercício

```bash
cd beecrowd_{numero}
```

### 2. Compile o programa

```bash
g++ main.cpp -o main -std=c++17 -O2 -lm
```

### 3. Para rodar utilizando o arquivo de entrada existente na pasta, use:

```bash
./main < in.txt > out.txt
```

### 4. Para comparar o resultado (out.txt) com a saída esperada (ans.txt), basta rodar:

```bash
diff ans.txt out.txt
```

É esperado que não apareça nada no terminal, indicando que os arquivos são idênticos
