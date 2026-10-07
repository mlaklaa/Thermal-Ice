# Thermal Ice - Embedded Temperature Control System

Sistema compatto di monitoraggio e controllo termico a circuito chiuso realizzato con microcontrollore **Arduino Nano (ATmega328P)**, sensore analogico di temperatura (NTC) e stadio di attuazione con relè per il pilotaggio di carichi di raffreddamento.

##  Il Problema e l'Idea (Background)

Il progetto nasce da un'esigenza pratica quotidiana: il surriscaldamento degli smartphone (in particolare iPhone) durante l'uso intenso o la ricarica rapida, fenomeno che attiva le protezioni termiche di sistema interrompendo la ricarica della batteria finché il dispositivo non torna a una temperatura normale.

L'idea alla base di **Thermal Ice** è il prototipo per una **cover intelligente/docking station attiva** in grado di monitorare costantemente la temperatura dello chassis del telefono e avviare automaticamente un flusso d'aria di raffreddamento solo quando necessario, preservando la salute della batteria e garantendo la continuità della ricarica.
Le soglie di 26°C e 24°C sono state scelte come valori dimostrativi per la simulazione, ma possono essere facilmente ricalibrate a 32–35°C per l'uso su smartphone reale.

##  Ulteriori Ambiti di Applicazione

Sebbene concepito come prototipo per il raffreddamento attivo di smartphone e docking station, l'architettura a circuito chiuso è modulare e facilmente estendibile ad altri scenari:
* **Micro-server e apparati di rete:** Raffreddamento on-demand per Raspberry Pi, NAS o cabinet per modem/switch di rete.
* **Mobili multimediali e audio/video:** Estrazione termica automatica per armadietti chiusi contenenti console o sintoamplificatori.
* **Monitoraggio pacchi batteria:** Protezione termica per celle al litio durante cicli di ricarica ad alta potenza.
* **Incubatori o mini-serre:** Regolazione termica per ambienti controllati (mediante ventola di ricircolo o elemento riscaldante).

https://github.com/user-attachments/assets/000096b2-89ce-4159-8a7f-facddce9eca9


---

##  Funzionamento e Logica di Controllo

Il dispositivo esegue la lettura continua del potenziale analogico fornito dal partitore del sensore NTC, converte il dato grezzo ADC in gradi Celsius tramite l'equazione basata sul coefficiente Beta e comanda l'uscita digitale.

Per prevenire repentine oscillazioni di commutazione (*chattering*) in prossimità della temperatura critica, è implementata una logica a **isteresi**:
* **Soglia di accensione ($T_{ON}$):** $\ge 26.0^\circ\text{C}$ $\rightarrow$ Attivazione raffreddamento (`RELAY_PIN` su `HIGH`).
* **Soglia di spegnimento ($T_{OFF}$):** $\le 24.0^\circ\text{C}$ $\rightarrow$ Disattivazione raffreddamento (`RELAY_PIN` su `LOW`).

---

##  Hardware e Componenti

* **Microcontrollore:** Arduino Nano (ATmega328P)
* **Sensore:** Modulo termistore NTC (Beta = 3950)
* **Attuatore:** Modulo relè 5V (simulazione stadio ventola/carico induttivo)
* **Ambiente di sviluppo:** PlatformIO (VS Code)
* **Piattaforma di simulazione:** Wokwi Simulator

---

##  Schema dei Collegamenti (Pinout)

| Dispositivo | Pin Modulo | Pin Arduino Nano | Funzione |
|---|---|---|---|
| **Sensore NTC** | VCC | 5V | Alimentazione (+5V) |
| | GND | GND | Riferimento di massa |
| | OUT | A0 | Ingresso analogico ADC |
| **Modulo Relè** | VCC | 5V | Alimentazione modulo |
| | GND | GND | Riferimento di massa |
| | IN | D2 | Segnale di trigger digitale |

---

##  Compilazione e Simulazione

### Compilazione con PlatformIO
Nel terminale del progetto:
```bash
pio run
```

Simulazione su Wokwi
Apri la Command Palette di VS Code (Ctrl + Shift + P o F1).

Digita ed esegui:

Wokwi: Start Simulator
Clicca sul corpo del sensore NTC per variare la temperatura e osservare l'intervento del relè (LED1) e del LED di stato a bordo (L / pin 13).

📄 Autore e Licenza
Autore: Marwa Laklaa

Progetto distribuito sotto licenza CC BY-NC 4.0 . Consulta il file LICENSE per maggiori dettagli.

