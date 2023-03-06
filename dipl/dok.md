# Doku

## Main
* Aufbau
  1. Auflegen aller Baugruppen am Boden/Tisch
  2. Schutzfolien/polster entfernen. Besondere vorsicht ist bei den Fingern geboten.
  3. InMoov Board Deckel entfernen und gegebenen falls Akkus einbauen.
  4. Board auf Reifen stellen und Gewindestangen einschrauben.
  5. Put on the Foots and Legs
  6. For the next step two persons are needed. Put on the upper body and screw on the two bolts.
  7. Put the ASS in Place
  8. Put on the arms
  9. Put on the hands
  10. Connect all wires
* Inbetriebnahme
  * installation von softwares
  * Erstellen neuer Gesten
  * Erlernen neuer dinge
* Reparatur
  * The InMoov won't power up
    * Make sure the Emergency off is released
    * 
  * Erkennen von der Fehler Ursache
    * The system can't find one ore more parts
      1. Make sure all wires are connected
      2. Make sure the power is on
      3. Check battery voltage
      4. Call Rauber
  * 3D Drucker Aufbau/wichtiges (Rauber)
  * 3D Druck files (Rauber)
  * 3D Printer setup (Rauber)
  * Servo conversion
    * Servo Aufschrauben
    * Aufpassen dass das Getriebe nicht Zerfällt
    * Hauptplatine Auslöten
    * Poti entfernen
    * Endanschlag entfernen
* Sicherheitsmaßnahmen
  * Notaus
  * Fehlererkennung
  * Drosselung der Hoverboard Motoren in den VESCs
* Verpacken
* 



## InMoov Board
* Vesc config
* Schaltung
* Precharge
  * Durch die große Kapazität von den VESC Kondensatoren fließt ein sehr großer einschaltstrom welcher die Kontakt von Schaltern und Relais Verbrennt.
    Daher wurde eine Precharge Schaltung entwickelt und umgesetzt.
* Laderegler(Rauber)
* RGB stripe

## Mechanisch (Rauber)
* Outward Aktuator
* Board Rollen
* Bizeps
* Hände



## Software 
* Motorcontroller board code
* PC software
  * Git
    * Install
      * Windows:
        * Lade von https://git-scm.com/download/win das deinem Betriebssystem entsprechende Programm herunter.
        * Installiere Git
      * Linux: neues Terminal: sudo apt-get install git
    * Clonen des InMoov Repository
      * gehe im Dateiexporer zu deinem gewünschten Speicherort
      * öffne dort ein neues Terminal oder Git-Bash
        * Windows: rechte Maustaste "Git bash here"
          * oder statt des Dateipfads "CMD" eingeben
        * Linux: rechte Maustaste "Terminal hier öffnen"
      * gib "git clone https://github.com/Schaumi19/InMoov_HTLWeiz.git InMoov_HTLWeiz" ein
    * Hochladen
      * Hierfür sind git Kenntnisse und Berechtigungen erforderlich.
  * Arduino
    * Install
      * Lade von https://www.arduino.cc/en/software die Legacy IDE (1.8.X)(das x steht für eine beliebige Nummer) deinem Betriebssystem entsprechend herunter.
      * Installiere die IDE und bejahe alle Treiber Abfragen
  * Programmieren eines Aktuator-Boards
    * Hochladen des Programms
      * gehe in dein lokales InMoov-Repository 
      * gehe in den AktuatorCode Ordner
      * öffne AktuatorCode.ino mit der Arduino IDE 1.8.x (das x steht für eine beliebige Nummer)
      * wähle in der Registerkarte unter Tools/Board Arduino-Nano aus
      * wähle für den Prozessor Atmega328P(old Bootloader) aus
      * schließe spätestens jetzt den Arduino an
      * wähle den richtigen USB-Port aus
      * klicke links oben auf Upload (2.Knopf von links)
        * falls das Uploaden nicht funktionieren sollte versuche als Prozessor Atmega328P auszuwählen
  * Konfigurieren des Aktuator-Boards
    * gehe in dein lokales InMoov-Repository 
    * gehe in den ActuatorConfigTool Ordner
    * öffne ein neues Terminal
    * Installieren der Librarys
      * gib "pip install tkinter" ein
      * gib "pip install pyserial" ein
    * gib "python ActuatorConfigTool_UI.py" ein
* Objekt/Gesture recognition
* 


## Doku Platinen neu Entwicklung

#### Features
* Control up to four motors
* uses angle inputs 
* Uses one Sensor per motor. We use Potentiometers, but it is also possible to use other sensors like hall encoders.
* Voltages Currents
* It has two types error of detection:
  * If the input value is higher/lower than the maximum/minimum value:
    * Detects all wire disconnections on the sensor side
  * Time based error system
    * Detects mechanical defects and wire disconnections on the motor side.

#### New Features
* SMD Pullups so the sensor input has always a fixed value and is not free floating
* Error LED
* Compatible with the new Arduino nano every
* Better Labeling
* Use of a different Connector Molex because USB is messy and not really wear resistant. and doesnt have a lock
* Routed I2C to the Connector
* Platinen Location über Jumper änderbar --> Kein nerviges Umprogrammieren


## Motoren:
* Es werden Widerstände In Serie mit eingelötet um die Leistung zu begrenzen --> Motortreiber werden nicht kaputt
* We use JST XH Connectors for our motors