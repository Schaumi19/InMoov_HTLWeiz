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

  * Servo Konvertierung
    * Servo Aufschrauben
    * Aufpassen dass das Getriebe nicht Zerfällt
    * Hauptplatine Auslöten
    * Poti entfernen
    * Endanschlag entfernen
    * zusammenbauen
  
* Sicherheitsmaßnahmen
  * Notaus
  * Fehlererkennung
  * Drosselung der Hoverboard Motoren in den VESCs

* Verpacken
  * sad
  * asdsafg
  * sad



## InMoov Board
* Schaltung
* Vesc(Vedder Electric Speed Controller) config
  * Spannungsversorgung einschalten
  * VESC mit USB-C zu USB-A Kabel mit PC verbinden
  * im lokalen Repository auf \InMoovBoard\VESC gehen und vesc_tool_3.00.exe starten
  * nun kann entweder die bestehende Config vom VESC gelesen werden oder mittels Motor Wizard(Setup Motor FOC) der Motor neu ausgemessen und eingestellt werden.
  * Im Wizard kann nun für den Motor Large Outrunner, für den Akku Lead-Acid mit 12 Zellen in Serie, für die Übersetzung direct Drive und den Rad Durchmesser 165mm eingestellt werden.
  * Nun können mit Run detection(no CAN) der Motor getestet werden.
* Precharge
  * Durch die große Kapazität von den VESC Kondensatoren fließt ein sehr großer Einschaltstrom, welcher die Kontakt von Schaltern und Relais verbrennt.
    Daher wurde eine Precharge Schaltung entwickelt und umgesetzt.
    Diese läd die Kondensatoren über einen Widerstand vor um den maximalen Strom zu reduzieren.

* RGB stripe
  * Der RGB stripe besteht aus WS2812B Pixeln. Diese können einzeln mit dem verbauten Arduino nano angesteuert werden.

## Software 
### Gesamt Installation:
* Git installieren
* Arduino installieren
* Python installieren

* Git Repository clonen
* Alle 3 Aktuator-Boards Programmieren
* Alle 3 Aktuator-Boards Konfigurieren



* PC software
  * Git
      siehe HowToGit.pdf

  * Arduino
    * Install
      * Linux:
        * Terminal: sudo apt-get install arduino
      * Windows:
        * Lade von https://www.arduino.cc/en/software die Legacy IDE (1.8.X)(das x steht für eine beliebige Nummer) deinem Betriebssystem entsprechend herunter.
        * Installiere die IDE und bejahe alle Treiber Abfragen und stimme der Admin abfrage zu
  
  * Programmieren eines Aktuator-Boards
    * Hochladen des Programms
      * gehe in dein lokales InMoov-Repository 
      * gehe in den AktuatorCode Ordner
      * öffne AktuatorCode.ino mit der Arduino IDE 1.8.x (das x steht für eine beliebige Nummer)
      * schließe spätestens jetzt den Arduino an
      * wähle in der Registerkarte unter Tools/
        * Board Arduino-Nano aus
        * Prozessor Atmega328P(old Bootloader) aus
        * wähle den richtigen USB-Port aus
      * klicke links oben auf Upload (2.Knopf von links)
        * falls das Uploaden nicht funktionieren sollte, versuche als Prozessor Atmega328P auszuwählen
  * Python
    * Install
      * Linux:
        * Terminal: sudo apt-get install python3.8
      * Windows:
        * Gehe zu "https://www.python.org/downloads/" und klicke auf "Download Python"
        * Auf "Install Now" klicken und die benötigten Rechte erteilen

  * Konfigurieren des Aktuator-Boards
    * gehe in dein lokales InMoov-Repository 
    * gehe in den ActuatorConfigTool Ordner
    * öffne ein neues Terminal
    * Installieren der Librarys
      * gib "pip install tk" ein
      * gib "pip install pyserial" ein
    * Anschließen eines Aktuator Boards mittels Mini-USB zu USB-A Kabel
    * Starte den InMoov
    * gib "python ActuatorConfigTool_UI.py" ein
    * Wenn die Config am Aktuator-Board weiter verwendet werden soll auf Load klicken,
      *  sonst auf Save und nach dem Speichern den Arduino mittels Reset Taste am Arduino zurücksetzten
    * Nun können einzelne Aktuatoren durch an-harken aktiviert werden
    * Mit dem DirektionTest wird die Motorrichtung selbstständig erkannt
    * Anschließend kann der Aktuator manuell mit + und - verfahren werden
    * Die Richtung kann mit REV umgedreht werden
    * und die Endanschläge mit SetMin/SetMax gesetzt werden
    * Abschließend muss der Aktuator noch der Richtigen Position(Schulter(L/R)/Hüfte) zugeordnet werden.
    * Außerdem ist es möglich in den anderen Feldern erweiterte Einstellungen wie Geschwindigkeit oder Deadzone einzustellen
    * Mit Save wird die Config am Arduino gespeichert