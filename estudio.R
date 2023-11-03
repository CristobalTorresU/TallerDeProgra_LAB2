library(ggplot2)
library(gridExtra)
library(ggpubr)

# tiempoInicial: Lo que demora el algoritmo base
# tiempoBreak: Lo que demora cuando se le agrega un break estrategico
# timepoIgual1: Cuando ademas del break se pregunta si el minimo es 1

setwd("/home/diggy/Documents/Universidad/5to Semestre/Taller de Programación/Lab2/Observaciones/")
datos = read.csv("obs2.csv")

# Plot
p <- ggplot(datos, aes(x=nodos, y=tiempo, color=optimizacion)) + 
  geom_point(size=4, alpha=0.7, show.legend = TRUE) + ylab("Tiempo (s)") + xlab("Nodos")

p