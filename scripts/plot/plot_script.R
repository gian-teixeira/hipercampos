#Script em R para tratamento de dados gerados por um algoritmo com o objetivo
#de analisar sua complexidade dados data frames com o número de entradas e
#tempos de execução calculados de formas diferentes

#Instala pacotes necessários
install.packages("rstudioapi")
install.packages("extrafont")
install.packages("ggplot2")
library(rstudioapi)
library(extrafont)
library(ggplot2)

data_frame_name <- c()

#CONFIGURAÇÕES:
#=============================================================================
#Defina o nome dos arquivo sa ser lido, a fonte a ser usada, a resolução do
#gráfico ao final, a cor da curva de regreção, a cor dos pontos
#a equação a ser comparada e o tamanho da fonte dos eixos
data_frame_name[1] <- "compute_system_time"
data_frame_name[2] <- "compute_user_time"
data_frame_name[3] <- "io_time"
data_frame_name[4] <- "total_day_time"
data_frame_name[5] <- "total_system_time"
data_frame_name[6] <- "total_user_time"
fonte <- "Libre Baskerville"
Resolucao <- 4000
line_color <- "black"
point_color <- "#899499"
equacao = function(x){(3*x*x) - (3*x)}
tamanho_fonte <- 20
#=============================================================================

#Utiliza o diretório padrão
setwd(dirname(rstudioapi::getActiveDocumentContext()$path))
setwd("../../time/output")

#Importa fontes a serem usadas nos gráficos
font_import(paths="./fonts")

#define o tema dos gráficos
theme_set(theme(panel.grid.major=element_blank(), panel.grid.minor=element_blank(),
                panel.background=element_blank(), axis.line=element_line(colour="black"),
                text=element_text(size=tamanho_fonte, family=fonte)))


for(i in 1:length(data_frame_name)){
  #Importa o Dataframe a ser usado no gráfico
  in_file_name <- paste(data_frame_name[i], ".csv", sep="")
  dados <- read.csv2(in_file_name, header=FALSE, sep=";", dec=".")

  #cria e salva gráfico de tempo de computação
  ggplot(dados, aes(V1,V2)) + xlab("Entradas(n)") + ylab("Tempo(ms)") +
    geom_point(color=point_color) + geom_smooth(method="loess", color=line_color, se=FALSE,linewidth=1)
  out_file_name <- paste(data_frame_name[i], ".png", sep="")
  ggsave(out_file_name, path="./plots", width=Resolucao, height=Resolucao, units="px")
}

#Cria o gráfico de x^2-x (Função de complexidade do algorítmo implementado)
ggplot(data.frame(x=c(1,max(dados$V1))), aes(x=x)) + 
  stat_function(fun=equacao,linewidth=1)
ggsave("funcao.png", path="./plots", width=Resolucao, height=Resolucao, units="px")