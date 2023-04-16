# Hipercampos :triangular_ruler:

Esse programa foi desenvolvido como um trabalho prático da disciplina de Algoritmos e Estruturas de Dados III da Universidade Federal de São João del-Rei (UFSJ). As especificaçoes detalhadas da atividade estão presentes no arquivo *Especificacoes.pdf*, e a documentação técnica, no arquivo *docs/Hipercampos.pdf*.

## Compilação do programa 

```bash
make
```

## Execução 

Para executar o programa, são necessários dois parâmetros:

- -i : arquivo de entrada
- -o : arquivo de saída

A execução é feita, então, por meio do comando

```bash
./TP1 -i <entrada> -o <saída>
```

### Especificações padrão para os arquivos 

| entrada <img width=100/> | saída <img width=100/> |
| ------------------------ | ---------------------- |
| n x<sub>a</sub> x<sub>b</sub></br>x<sub>1</sub> y<sub>1</sub></br>x<sub>2</sub> y<sub>2</sub></br>...</br> x<sub>n</sub> y<sub>n</sub></br>| m</br></br></br></br></br> |

- n: quantidade de pontos
- x<sub>a</sub>: abcissa da âncora A
- x<sub>b</sub> : abcissa da âncora B
- x<sub>i</sub> y<sub>i</sub> : coordenadas do ponto *i*

> 0 < n < 101
> 
> 0 < x<sub>a</sub> < x<sub>b</sub> < 10<sup>4</sup>
> 
> 0 < x<sub>i</sub> , y<sub>i</sub> < 10<sup>4</sup>

### Medições de tempo 

As medições de tempo são armazenadas no diretório */time/output* em formato *.csv* e são divididas em

- Tempo total de relógio
- Tempo total de usuário
- Tempo total de sistema
- Tempo de usuário da computação
- Tempo de sistema da computação
- Tempo de entrada e saída

## Scripts auxiliares :link:

Para os testes do programa e análise dos dados de monitoramento, foram
criados três scripts: 

- Gerador de pontos      
- Executador de testes   
- Tratador de dados      

> Todos os scripts devem ser executados a partir do diretório raiz do programa.

### Gerador de pontos

Gera, de acordo com a especificação padrão da entrada, **r** arquivos para cada quantidade **Q** pertencente a *{ hop, 2.hop, 3.hop, ..., max }*. Os arquivos são salvos na pasta */time/input*.

```bash
python3 ./scripts/pointGen.py max hop r
```

### Executador de testes

Para cada arquivo de teste presente em */time/input*, executa o programa principal

```bash
python3 ./scripts/runTests.py
```

### Tratador de dados

Os scripts foram escritos em em R, e aconselha-se que sejam executados a partir da IDE RStudio. Os arquivos do diretório *time/output* serão utilizados no
cálculo das curvas de regressão e construção dos gráficos, armazenados na pasta *time/plots*.

```bash
# Caminho do gerador de gráficos simples: ./scripts/plot/single_plots/plot_script.R
# Caminho do gerador de curvas sobrepostas: ./scripts/plot/multiple_plots/plot_script_mult.R
```
