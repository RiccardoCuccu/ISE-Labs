# ISE Lab 6
Laboratorio 6 del corso **Integrazione di Sistemi Embedded** del corso magistrale in Embedde System (Ingegneria Elettronica) del Politecnico di Torino, anno accademico 2018/2019.<br/>

## Esercizio 1
Lo scopo dell'esercitazione è quello di prendere domestichezza con il linguaggio di scripting **Python** utilizzandolo per la simulazione automatica mediante
**Ngspice** di circuiti analogici.<br/>
Ngspice è un simulatore mixed-level/mixed-signal di circuiti. 
È un software open source disponibile per diverse piattaforme e basato su tre software packages: Spice3f5, Xspice and Cider1b1.<br/>
Durante il laboratorio verranno descritte e analizzate due linee di trasmissione, una basata sul modello semplificato interno al software e una basata sul circuito equivalente a parametri concentrati.<br/>
Dal punto di vista metodologico, sarà necessario creare uno script python in grado di generare una netlist Ngspice al fine di simulare il comportamento delle due linee di trasmissione. I risultati dovranno essere raccolti e confrontati verificandone il comportamento asintotico delle due simulazioni.

### Introduzione
La differenza fondamentale tra un circuito a parametri concentrati ed uno a parametri distribuiti è legata al rapporto tra le dimensioni del circuito e la lunghezza d'onda `λ` dei segnali elettrici in esso circolanti. Dato un circuito unidimensionale - posto lungo l'asse cartesiano `z` - di lunghezza `L`, esso è considerato a parametri concentrati se `λ >> L`, altrimenti è da trattare con un modello a parametri distribuiti. Nel primo caso è ragionevole supporre che una variazione di un segnale elettrico in un determinato istante tempo-reale `t` sia percepita da tutto il circuito nello stesso istante, nell'altro essa è percepita differentemente da punti diversi del circuito, pertanto le grandezze elettriche dipenderanno non solo dal tempo `t` ma anche dalla posizione `z`.<br/>
Un'importante conseguenza della distinzione di cui sopra riguarda la metodologia di analisi di un circuito: se vale il modello a parametri concentrati, è ammessa l'analisi delle grandezze elettriche attraverso l'applicazione delle leggi di Kirchhoff, altrimenti sarà necessario ricorrere alle equazioni di Maxwell.<br/>
Una linea di trasmissione è di solito schematizzata con due fili conduttivi separati da un materiale dielettrico. Supponendo che una linea di trasmissione sia senza perdite ohmiche nei conduttori e nel dielettrico, essa può essere scomposta in segmenti di lunghezza `Δz`, ciascuno descritto da un circuito a parametri concentrati, dove `L` e `C` sono l'induttanza e la capacità per unità di lunghezza rispettivamente.
Le equazioni caratteristiche delle linee di trasmissione non sono nient'altro che le equazioni differenziali ottenute scomponendo la linea in segmenti di lunghezza infinitesima ![dz=\lim_{\Delta z\to\0} \Delta z](https://render.githubusercontent.com/render/math?math=%5Ctextstyle+dz%3D%5Clim_%7B%5CDelta+z%5Cto%5C0%7D+%5CDelta+z).

![\begin{align*}
\begin{cases}
\frac{\partial v(z,t)}{\partial z} = -L \frac{\partial  i(z,t)}{\partial t} \\ 
\frac{\partial i(z,t)}{\partial z} = -C \frac{\partial  v(z,t)}{\partial t}
\end{cases}
\end{align*}](https://render.githubusercontent.com/render/math?math=%5Cdisplaystyle+%5Cbegin%7Balign%2A%7D%0A%5Cbegin%7Bcases%7D%0A%5Cfrac%7B%5Cpartial+v%28z%2Ct%29%7D%7B%5Cpartial+z%7D+%3D+-L+%5Cfrac%7B%5Cpartial++i%28z%2Ct%29%7D%7B%5Cpartial+t%7D+%5C%5C+%0A%5Cfrac%7B%5Cpartial+i%28z%2Ct%29%7D%7B%5Cpartial+z%7D+%3D+-C+%5Cfrac%7B%5Cpartial++v%28z%2Ct%29%7D%7B%5Cpartial+t%7D%0A%5Cend%7Bcases%7D%0A%5Cend%7Balign%2A%7D)

Le soluzioni generali delle equazioni di una generica linea di trasmissione sono:

![\begin{align*}
\begin{cases}
V(z,t)=V^+(z-vt)+V^-(z+vt) \\ 
I(z,t)=\frac{V^+}{Z_0}(z-vt)+\frac{V^-}{Z_0}(z+vt)
\end{cases}
\end{align*}
](https://render.githubusercontent.com/render/math?math=%5Cdisplaystyle+%5Cbegin%7Balign%2A%7D%0A%5Cbegin%7Bcases%7D%0AV%28z%2Ct%29%3DV%5E%2B%28z-vt%29%2BV%5E-%28z%2Bvt%29+%5C%5C+%0AI%28z%2Ct%29%3D%5Cfrac%7BV%5E%2B%7D%7BZ_0%7D%28z-vt%29%2B%5Cfrac%7BV%5E-%7D%7BZ_0%7D%28z%2Bvt%29%0A%5Cend%7Bcases%7D%0A%5Cend%7Balign%2A%7D%0A)

dove gli apici `+` e `-` si riferiscono alle onde incidente e riflessa - le quali si muovono lungo la linea con velocità di propagazione v in direzione `+z` e `-z` rispettivamente - nell'istante temporale `t` e Z<sub>0</sub> è chiamata impedenza caratteristica di valore



[//]: # (https://tex-image-link-generator.herokuapp.com/)
