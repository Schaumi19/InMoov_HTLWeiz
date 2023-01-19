## Doku Platinen neu entwicklung
#### Gründe:
* SMD Pullup wiederstände bei den eingängen fehlen
* USB-Micro Buchsen haben einen sehr großen verschleiß und dadurch werden sie versehendlich ausgesteckt
* USB Buchsen haben keine verriegelung
* Die vielen USB Leitungen sind unübersichtlich stören
* Es werden aktuell sehr viele Strom und USB Leitungen gebraucht
* Leitungs qerschnitte zu groß

#### Lösung:
* Molex 4 Pin Anschluss auf jeder Platine
* Leitungen mit angemessenen Leitungsquerschnitten --> erhöhte flexibilität
* Datenleitungen werden mit verlegt, daher ist ein Betrieb über USB und I2C möglich
* Die 4 Leitungen werden mit Kabel schläuchen zusammengefasst
* Platine hat keine Unnötig Reduntanten Poti Eingänge
* Platinen Lokation über Jumper änderbar --> Kein nerviges Umprogrammieren





## Motoren:
* Es werden Widerstände In serie mit eingelötet um die Leistung zu begrenzen --> Motortreiber werden nicht kaputt
* 