# Thermal Ice - Embedded Temperature Control System

Sistema compatto di monitoraggio e controllo termico a circuito chiuso realizzato con microcontrollore **Arduino Nano (ATmega328P)**, sensore analogico di temperatura (NTC) e stadio di attuazione con relè per il pilotaggio di carichi di raffreddamento.

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
Simulazione su Wokwi
Apri la Command Palette di VS Code (Ctrl + Shift + P o F1).

Digita ed esegui:

Plaintext
Wokwi: Start Simulator
Clicca sul corpo del sensore NTC per variare la temperatura e osservare l'intervento del relè (LED1) e del LED di stato a bordo (L / pin 13).

📄 Autore e Licenza
Autore: Marwa Laklaa

Progetto distribuito sotto licenza CC BY-NC 4.0 . Consulta il file LICENSE per maggiori dettagli.

