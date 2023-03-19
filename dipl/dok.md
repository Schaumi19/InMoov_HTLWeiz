# Doku

## Wahl der Programmiersprachen
  Die Wahl der Programmiersprache hängt von verschiedenen Faktoren ab, wie z.B. dem Anwendungsbereich, der verfügbaren Hardware, der benötigten Leistung und der Erfahrung des Entwicklers. Im Allgemeinen ist die Wahl von C++ für Arduino und Python für den PC auf die folgenden Faktoren zurückzuführen:

    Hardware-Beschränkungen: Arduino-Boards sind in der Regel mit begrenzten Ressourcen wie Speicherplatz, RAM und CPU-Geschwindigkeit ausgestattet. C++ ist eine effiziente Programmiersprache, die eng mit der Hardware des Systems verbunden ist und die Möglichkeit bietet, Hardware-Peripheriegeräte wie Sensoren und Aktoren direkt zu steuern. Python ist im Vergleich dazu eine interpretierte Sprache und erfordert mehr Ressourcen, um auf der Hardware ausgeführt zu werden.

    Echtzeit-Verarbeitung: Arduino-Boards werden oft für Anwendungen verwendet, die eine Echtzeit-Verarbeitung von Sensor- oder Aktordaten erfordern, wie z.B. die Steuerung von Robotern oder die Überwachung von Umweltbedingungen. C++ bietet eine bessere Echtzeit-Performance als Python und ist daher besser geeignet für solche Anwendungen.

    Datenanalyse und -verarbeitung: Python ist eine leicht zu erlernende und benutzerfreundliche Programmiersprache, die sich gut für Datenanalyse und -verarbeitung eignet. Python hat auch eine große Anzahl von Bibliotheken für Datenanalyse, die es Entwicklern ermöglichen, schnell und einfach komplexe Datenanalysen durchzuführen. In Anwendungen, bei denen es um Datenanalyse oder -verarbeitung geht, ist Python oft die bevorzugte Sprache.

  Insgesamt hängt die Wahl der Programmiersprache von vielen Faktoren ab, und es gibt oft keine "richtige" oder "falsche" Antwort. Die Wahl der Programmiersprache hängt davon ab, welche Anforderungen die Anwendung hat und welche Sprache am besten geeignet ist, um diese Anforderungen zu erfüllen.

## UART
  UART steht für "Universal Asynchronous Receiver/Transmitter" und ist ein hardwarebasiertes Kommunikationsprotokoll, das in der seriellen Datenübertragung verwendet wird. Es ermöglicht die bidirektionale serielle Kommunikation zwischen einem Mikrocontroller oder einem anderen elektronischen Gerät und einem Computer oder einem anderen Gerät.

  UART wird häufig in der Elektronikindustrie für die Übertragung von Daten zwischen Geräten verwendet, insbesondere für die Übertragung von Text- und binären Daten über kurze bis mittlere Entfernungen. Das Protokoll ist besonders nützlich für Anwendungen, die eine einfache, zuverlässige und kostengünstige Kommunikation erfordern, wie z.B. die Übertragung von Sensordaten oder die Steuerung von Motoren und anderen Aktoren.

  UART ist auch bekannt für seine einfache Implementierung und flexible Konfiguration. Die meisten Mikrocontroller verfügen über integrierte UART-Module, die es Entwicklern ermöglichen, serielle Kommunikation mit nur wenigen Codezeilen zu implementieren.

## I2C
  I2C steht für "Inter-Integrated Circuit" und ist ein serieller Kommunikationsbus, der hauptsächlich in der Elektronikindustrie verwendet wird. Es ermöglicht die bidirektionale serielle Kommunikation zwischen einem Master-Gerät (z.B. einem Mikrocontroller) und mehreren Slave-Geräten (z.B. Sensoren, Aktoren, EEPROMs usw.), die alle über denselben Bus verbunden sind.

  I2C wurde von Philips Semiconductors (heute NXP Semiconductors) entwickelt und wird oft als eine einfache und kostengünstige Möglichkeit zur Übertragung von Daten zwischen integrierten Schaltkreisen angesehen. Es ist besonders nützlich für Anwendungen, die eine geringe Anzahl von Pins und Verbindungen erfordern, da es nur zwei Signalleitungen benötigt: eine für die Datenübertragung (SDA) und eine für die Taktübertragung (SCL).

  I2C ist auch bekannt für seine Flexibilität und seine Fähigkeit, eine Vielzahl von Geräten mit unterschiedlichen Adressen und Funktionen auf demselben Bus zu unterstützen. Dies wird durch die Verwendung von Adressen ermöglicht, die jedem Slave-Gerät zugeordnet werden, um die Datenübertragung an das entsprechende Gerät zu steuern.

  Insgesamt ist I2C ein häufig verwendetes Protokoll in der Elektronikindustrie, da es eine einfache, effiziente und flexible Möglichkeit zur Übertragung von Daten zwischen Geräten bietet.

## Aktuator Code
  Der sogenannte Aktuator Code ist das C++ Programm welches auf den Arduino's in den Schultern und im Torso verwendet wird.
  Er ist dafür verantwortlich die 4 Motoren so anzusteuern, dass sich die Aktuatoren mit der richtigen Geschwindigkeit zur richtigen Position bewegen und diese halten.
  Verwendung: Egal für welche der 3 Positionen der Arduino gedacht ist kann er immer mit dem selben geflashed(flashen -> übertragen vom Programm auf Mikrocontroller) werden. Die entgültige Position wird erst beim Konfigurieren mit dem AktuatorConfigTool[Link] festgelegt.
  Kompatibilität: Verwendet werden kann das Programm mit 3 verschiedenen Arduino Nano's: dem normalen Arduino Nano, dem Arduino Nano mit altem Boot-loader und dem neuen Arduino Nano Every.
  Kommunikation: Der Aktuator Code verfügt über Zwei verschiedene Steuerungsmöglichkeiten: I2C und UART(Serial).
  Außerdem können Nachrichten welche über UART empfangen wurden, über I2C an die anderen Arduino's weitergeleitet werden.
  Da die im Arduino Core integrierte wire Bibliothek, welche für die I2C Kommunikation verantwortlich ist, einen Fehler hat wurde eine eigene Funktion fürs Senden von Nachrichten über I2C entwickelt.
  Funktionsweise: Wenn eine neue Nachricht über UART empfangen wird wird als erstes entschieden um welchen Typ von Nachricht es sich handelt. Wenn erkannt wurde, dass es eine neue Aktuator Position für einen der eigenen 4 Aktuatoren ist, wird anhand den mit dem Config Tool[Link] eingestellten Parametern die zu bewegende Richtung und Leistung ermittelt. Ist Angular-Speed-Control aktiviert, wird laufend die Leistung nachgeregelt, um sanftes anfahren und abbremsen zu ermöglichen.
  Wenn die gewünschte Position erreicht wurde wird gestoppt, falls sich allerdings danach der Winkel mehr als die Deadzone verändert wird nachgeregelt. Die Deadzone ist nötig um nicht ins schwingen zu geraten, was einerseits schlecht aussieht und andererseits auch schlecht für den Stromverbrauch und die Hardware ist.
  Fehlererkennung: Um große Schäden an der Mechanik zu vermeiden, wurden drei verschiedene Arten der Fehlererkennung implementiert.
  Da alle Fehler auf ein Hardware Problem hindeuten, können durch einen Fehler deaktivierte Aktuatoren nur durch einen Reset am Arduino wieder in betrieb genommen werden.
  Hat mindestens einer der vier Aktuatoren mindestens einen der drei Fehler leuchtet die Error LED.
  1. OutOfRange Error: Ein empfangener Sensor-wert, welcher nicht im Konfigurierten Spektrum ist, führt unwiderruflich zum sofortigen halt des Aktuators. 
  2. Time Error: Benötigt ein Aktuator ungewöhnlich lange um eine Position zu erreichen, führt dies ebenfalls zum unwiderruflich sofortigen halt des Aktuators.
  3. Dir Error: Bewegt sich ein Aktuator in die Falsche Richtung, führt dies ebenfalls zum unwiderruflich sofortigen halt des Aktuators.
  Angular-Speed-Control: Wie oben schon beschrien ist dieser Teil des Programms für die sanfte Regelung verantwortlich. Dies wird mit einer Art von PI-Regler[Link] erziehlt

## PI-Regler
  Ein PI-Regler ist ein Regelalgorithmus, der häufig in der Regelungstechnik eingesetzt wird. Der Name "PI-Regler" leitet sich aus der Kombination der beiden Begriffe "proportional" und "integral" ab, da der Algorithmus aus beiden Komponenten besteht.

  Die proportional-anteilige Komponente des PI-Reglers basiert auf dem Fehler zwischen dem gewünschten Wert (Sollwert) und dem aktuellen Wert (Istwert) eines Prozesses, der geregelt werden soll. Der Regler multipliziert den Fehler mit einem Proportionalitätsfaktor und gibt die resultierende Steuergröße an den Prozess aus. Diese Komponente sorgt dafür, dass der Prozess schneller auf Änderungen des Sollwertes reagiert und eine höhere Genauigkeit erreicht.

  Die integral-anteilige Komponente des PI-Reglers basiert auf der Summe aller vergangenen Fehlerwerte und multipliziert sie mit einem Integrationsfaktor. Diese Komponente sorgt dafür, dass der Regler einen stabilen Zustand erreicht und den Fehler langfristig beseitigt, der aufgrund von Systemverzögerungen oder anderen Ursachen nicht durch die proportional-anteilige Komponente beseitigt werden konnte.

  Zusammen arbeiten die beiden Komponenten des PI-Reglers, um eine schnelle Reaktion auf kurzfristige Fehler und eine stabile Regelung langfristiger Fehler zu erreichen. Der PI-Regler ist ein weit verbreiteter Regleralgorithmus in der Regelungstechnik und wird oft in Anwendungen wie der Temperaturregelung, der Regelung von Motorgeschwindigkeiten und anderen Anwendungen eingesetzt, in denen eine präzise Steuerung erforderlich ist.

## AktuatorConfigTool
  Bis vor kurzem musste für jede Änderung an der Hardware eine Person mit Programmier-Kenntnissen den Aktuator Code etwas verändern um die nötigen Werte für diese Hardware Veränderung zu erhalten. Danach mussten diese neuen Werte einprogrammiert und auf den Arduino geflashed werden.
  Dies ist mit dem AktuatorConfigTool Geschichte, hiermit ist es möglich Aktuatoren manuell, also ohne Fehlererkennungen und Begrenzungen bewegen zu können. Dies ermöglicht ganz andere Möglichkeiten, beispielsweise ist keine externe Spannungsquelle mehr nötig um defekte Aktuatoren wieder in eine Valide Position zu verfahren.
  Außerdem ist es nun möglich ganz einfach weiche(Software) Endanschläge zu setzten und zu ändern, Geschwindigkeiten, Deadzones, Fehlerschwellenwerte und vieles mehr einzustellen und die Positionierung der AktuatorPlatine(L,R,M) Festzulegen.



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
  * Über USB lässt sich der Arduino in 3 verschiedene States(off, Rainbow, Color-wipe) versetzten, außerdem können Parameter wie z.B. Color-wipe Farbe oder Rainbow Speed mitgegeben werden.
  * Diese Funktionalität ist auch über I2C also über die anderen Arduino fernsteuerbar.

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