# ISE Lab 6
Laboratorio 6 del corso **Integrazione di Sistemi Embedded** del corso magistrale in Embedde System (Ingegneria Elettronica) del Politecnico di Torino, anno accademico 2018/2019.<br/>

## Esercizio 1
Lo scopo dell'esercitazione è quello di prendere domestichezza con il linguaggio di scripting **Python** utilizzandolo per la simulazione automatica mediante
**Ngspice** di circuiti analogici.<br/>
Ngspice è un simulatore mixed-level/mixed-signal di circuiti. 
È un software open source disponibile per diverse piattaforme e basato su tre software packages: Spice3f5, Xspice and Cider1b1.<br/>
Durante il laboratorio verranno descritte e analizzate due linee di trasmissione, una basata sul modello semplificato interno al software e una basata sul circuito equivalente a parametri concentrati.<br/>
Dal punto di vista metodologico, sarà necessario creare uno script python in grado di generare una netlist Ngspice al fine di simulare il comportamento delle due linee di trasmissione. I risultati dovranno essere raccolti e confrontati verificandone il comportamento asintotico delle due simulazioni.

<p align="center">
  <img src="./fig/flusso.png" width="60%">
</p>

### Introduzione
La differenza fondamentale tra un circuito a parametri concentrati ed uno a parametri distribuiti è legata al rapporto tra le dimensioni del circuito e la lunghezza d'onda `λ` dei segnali elettrici in esso circolanti. Dato un circuito unidimensionale - posto lungo l'asse cartesiano `z` - di lunghezza `L`, esso è considerato a parametri concentrati se `λ >> L`, altrimenti è da trattare con un modello a parametri distribuiti. Nel primo caso è ragionevole supporre che una variazione di un segnale elettrico in un determinato istante tempo-reale `t` sia percepita da tutto il circuito nello stesso istante, nell'altro essa è percepita differentemente da punti diversi del circuito, pertanto le grandezze elettriche dipenderanno non solo dal tempo `t` ma anche dalla posizione `z`.<br/>
Un'importante conseguenza della distinzione di cui sopra riguarda la metodologia di analisi di un circuito: se vale il modello a parametri concentrati, è ammessa l'analisi delle grandezze elettriche attraverso l'applicazione delle leggi di Kirchhoff, altrimenti sarà necessario ricorrere alle equazioni di Maxwell.<br/>
Una linea di trasmissione è di solito schematizzata con due fili conduttivi separati da un materiale dielettrico. Supponendo che una linea di trasmissione sia senza perdite ohmiche nei conduttori e nel dielettrico, essa può essere scomposta in segmenti di lunghezza `Δz`, ciascuno descritto da un circuito a parametri concentrati, dove `L` e `C` sono l'induttanza e la capacità per unità di lunghezza rispettivamente.

<p align="center">
  <img src="./fig/modello_equivalente.png" width="50%">
</p>

Le equazioni caratteristiche delle linee di trasmissione non sono nient'altro che le equazioni differenziali ottenute scomponendo la linea in segmenti di lunghezza infinitesima <img src="https://render.githubusercontent.com/render/math?math=%5Ctextstyle+dz%3D%5Clim_%7B%5CDelta+z%5Cto%5C0%7D+%5CDelta+z" alt="dz=\lim_{\Delta z\to\0} \Delta z">.

<p align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Cdisplaystyle+%5Cbegin%7Bcases%7D%0A%5Cfrac%7B%5Cpartial+v%28z%2Ct%29%7D%7B%5Cpartial+z%7D+%3D+-L+%5Cfrac%7B%5Cpartial++i%28z%2Ct%29%7D%7B%5Cpartial+t%7D+%5C%5C+%0A%5Cfrac%7B%5Cpartial+i%28z%2Ct%29%7D%7B%5Cpartial+z%7D+%3D+-C+%5Cfrac%7B%5Cpartial++v%28z%2Ct%29%7D%7B%5Cpartial+t%7D%0A%5Cend%7Bcases%7D" 
alt="\begin{cases}
\frac{\partial v(z,t)}{\partial z} = -L \frac{\partial  i(z,t)}{\partial t} \\ 
\frac{\partial i(z,t)}{\partial z} = -C \frac{\partial  v(z,t)}{\partial t}
\end{cases}">
</p>

Le soluzioni generali delle equazioni di una generica linea di trasmissione sono:

<p align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Cdisplaystyle+%5Cbegin%7Bcases%7D%0AV%28z%2Ct%29%3DV%5E%2B%28z-vt%29%2BV%5E-%28z%2Bvt%29+%5C%5C+%0AI%28z%2Ct%29%3D%5Cfrac%7BV%5E%2B%7D%7BZ_0%7D%28z-vt%29%2B%5Cfrac%7BV%5E-%7D%7BZ_0%7D%28z%2Bvt%29%0A%5Cend%7Bcases%7D" 
alt="\begin{cases}
V(z,t)=V^+(z-vt)+V^-(z+vt) \\ 
I(z,t)=\frac{V^+}{Z_0}(z-vt)+\frac{V^-}{Z_0}(z+vt)
\end{cases}">
</p>

dove gli apici `+` e `-` si riferiscono alle onde incidente e riflessa - le quali si muovono lungo la linea con velocità di propagazione v in direzione `+z` e `-z` rispettivamente - nell'istante temporale `t` e Z<sub>0</sub> è chiamata impedenza caratteristica di valore

<p align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Cdisplaystyle+Z_0%3D%5Csqrt%7B%5Cfrac%7BL%7D%7BC%7D%7D" 
alt="Z_0=\sqrt{\frac{L}{C}}">
</p>

È possibile dimostrare che la velocità di propagazione tra due punti <img src="https://render.githubusercontent.com/render/math?math=%5Ctextstyle+z_0" alt="z_0"> e <img src="https://render.githubusercontent.com/render/math?math=%5Ctextstyle+z_0%2Bdz" alt="z_0+dz"> è pari a

<p align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Cdisplaystyle+v%3D%5Cfrac%7B1%7D%7B%5Csqrt%7BLC%7D%7D%3D%5Cfrac%7Bdz%7D%7Bdt%7D" 
alt="v=\frac{1}{\sqrt{LC}}=\frac{dz}{dt}">
</p>

e di conseguenza il ritardo di propagazione sarà ottenuto come

<p align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Cdisplaystyle+dt%3D%5Csqrt%7BLC%7Ddz%3D%5Csqrt%7BL+dz+%5Ccdot+C+dz%7D%3D%5Csqrt%7BL%28z%29+C%28z%29%7D" 
alt="dt=\sqrt{LC}dz=\sqrt{L dz \cdot C dz}=\sqrt{L(z) C(z)}">
</p>

Se si considera una linea di lunghezza `L`, il ritardo di propagazione tra le due estremità sarà pari a

<p align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Cdisplaystyle+%5CDelta+t_d+%3D+%5Cint_%7B0%7D%5E%7BL%7D+%5Csqrt%7BL%28z%29+%5Ccdot+C%28z%29%7D" 
alt="\Delta t_d = \int_{0}^{L} \sqrt{L(z) \cdot C(z)}">
</p>

Non essendo possibile simulare su un calcolatore una catena infinita di celle LC di lunghezza infinitesima e risolvere in maniera esatta un calcolo integrale per la stima del ritardo di propagazione, in questa esercitazione si intende simulare una linea di trasmissione costituita da una catena finita di elementi capacitivi ed induttivi a parametri concentrati, pertanto si suppone che ciascun segmento abbia lunghezza finita `Δz` anzichè infinitesima `dz`, una capacità `C = CΔz` ed un'induttanza `L = LΔz` dai cui valori dipende il valore dell'impedenza caratteristica

<p align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Cdisplaystyle+Z_0%3D%5Csqrt%7B%5Cfrac%7BL%7D%7BC%7D%7D%3D%5Csqrt%7B%5Cfrac%7BL+%5CDelta+z%7D%7BC+%5CDelta+z%7D%7D%3D%5Csqrt%7B%5Cfrac%7BL%7D%7BC%7D%7D" 
alt="Z_0=\sqrt{\frac{L}{C}}=\sqrt{\frac{L \Delta z}{C \Delta z}}=\sqrt{\frac{L}{C}}">
</p>

È possibile definire per ciascuna cella LC un ritardo di propagazione <img src="https://render.githubusercontent.com/render/math?math=%5Ctextstyle+t_%7BD_i%7D%3D%5Csqrt%7BL+%5CDelta+z+%5Ccdot+C+%5CDelta+z%7D+%3D+%5Csqrt%7BLC%7D" alt="t_{D_i}=\sqrt{L \Delta z \cdot C \Delta z} = \sqrt{LC}"> e il ritardo complessivo lungo una linea di `N` elementi viene calcolato da una sommatoria anzichè da un integrale:

<p align="center">
<img src=
"https://render.githubusercontent.com/render/math?math=%5Cdisplaystyle+%5CDelta+t_d+%3D+%5Csum_%7Bi%3D0%7D%5E%7BN-1%7D+t_%7BD_i%7D+%3D+N+%5Csqrt%7BLC%7D%0A" 
alt="\Delta t_d = \sum_{i=0}^{N-1} t_{D_i} = N \sqrt{LC}">
</p>

### Generazione della netlist
#### Generazione del sub-circuit
Generare la netlist del subcircuit denominato *subcircuitlc.txt* comprensivo di 10 elementi della catena come rappresentato in figura. Utilizzare come valore di capacità e induttanza C = 0:02 pF e L = 0:05 nH rispettivamente.

<p align="center">
  <img src="./fig/chain.png" width="80%">
</p>

#### Istanza dei sub-circuit
Generare una netlist, considerando un ritardo <img src="https://render.githubusercontent.com/render/math?math=%5Ctextstyle+%5CDelta+t_d" alt="\Delta t_d"> in picosecondi, con risoluzione di 1 ps (p.e. 123 ps o 124 ps sono ammessi a differenza di 123:7 ps).
Il ritardo deve essere inserito dall'utente tramite line di comando.<br/>
Si richiede di massimizzare l'impiego dei sub-circuit. Nel caso in cui il ritardo non fosse ottenibile adoperando unicamente i sub-circuit, istanziare il numero opportuno di celle LC all'interno dello script.

<p align="center">
  <img src="./fig/circuito_netlist.png" width="80%">
</p>

#### Generatore di ingresso
Configurare come generatore di ingresso della netlist, un gradino di tensione con tensione tra 0V e 1V, con un fronte di salita sull'istante temporale pari ad <img src="https://render.githubusercontent.com/render/math?math=%5Ctextstyle+t_%7Bedge%7D%3D%5Cfrac%7B1%7D%7B3%7D+%5CDelta+t_d" alt="t_{edge}=\frac{1}{3} \Delta t_d"> del ritardo di propagazione richiesto. Sia fissato il tempo disalita al valore <img src="https://render.githubusercontent.com/render/math?math=%5Ctextstyle+t_r%3D0.2+ps" alt="t_r=0.2 ps">.<br/>
Collegare in serie al generatore di ingresso una resistenza di valore <img src="https://render.githubusercontent.com/render/math?math=%5Ctextstyle+R_S%3D12.5+%5COmega" alt="R_S=12.5 \Omega">



[//]: # (https://tex-image-link-generator.herokuapp.com/)
