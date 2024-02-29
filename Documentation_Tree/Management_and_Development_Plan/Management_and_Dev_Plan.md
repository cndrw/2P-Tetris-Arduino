<!-- Table of contents -->

# Inhalt

1. [Ausgangslage](#ausgangslage)
-  [Zeitplan](#zeitplan)
-  [Ressourcen](#ressourcen)
- [Budget](#)
- [Kommunikationsplan](#)
2. [Projektziele](#projektziele)
3. [Risikoanalyse](#risikoanalyse)
4. [Projektverlauf und Meilensteine](#projektverlauf-und-meilensteine)
    - [Projektbeginn](#1-projektbeginn)
    - [Entwicklung](#2-entwicklung)
    - [Realisierung](#3-realisierung)
    - [Finalisierung](#4-finalisierung)
5. [Projektverlauf und Meilensteine](#projektverlauf-und-meilensteine)
6. [Abschluss](#)


# Ausgangslage

Das Projekt Retris wurde im Rahmen der Mikrocomputertechnik Vorlesung geplant und entwickelt. Die Idee war es, den Spieleklassiker Tetris in abgewandelter Form mithilfe eines Mikrocontrollers zu steuern. Des Weiteren überlegten wir uns eine Ansteuerung mit einem SNES-Controller. Das Projekt sollte monetär nicht 100 Euro pro Person übersteigen. Der aktive Entwicklungszeitraum betrug ein Quartal. Das Team besteht aus drei Personen. Das Projekt sollte in Form eines Pitches vorgetragen werden und stellte den offiziellen Projektstart dar. 

Des Weiteren sollten wöchentliche Berichte eingereicht werden, sodass der aktuelle Stand und mögliche Probleme geprüft werden konnten.

Mögliche Risiken zu Beginn des Projekts waren unter anderem ein zu großer Umfang, sowie die Beschaffung aller zur Umsetzung benötigten Komponenten.

## Zeitplan
Eine Zeitplanung ist von extremer Wichtigkeit für den Erfolg von jedem Projekt. Für den Pitch wurde ein rudimentärer Ablaufplan entwickelt. Für mehr Flexibilität wurde auf eine genaue zeitliche Einteilung verzichtet. Des Weiteren erfolgte nach dem unten stehenden Zeitplan kein detaillierterer Plan aufgrund des Umfangs des Gesamtprojekts. Auch in Anbetracht der Zeit, sollte sich das Engangement fokussierter auf die Umsetzung und weniger auf die Steuerung des Projekts richten.

![Schedule](/Documentation_Tree/Engineering_Folder/images/Zeitplan_Retris.PNG)

Für einen besseren Überblick wurde das Projekt in vier Projektphasen unterteilt. Diese erkennt man im Bild unter der Überschrift. Diese wurden stichpunktartig mit den jeweiligen Tätigkeiten beschrieben. Außerdem konnte man bereits festgesetzte Meilensteile entnehmen, welche im Vorfeld wohl überlegt worden sind. Außerdem wurde das Projekt in verschiedene Teilziele gefasst, welche in der Folge noch genauer erklärt werden.

## Ressourcen
Grundsätzlich stand uns unsere  studentischen Kentnisse, welche im Laufe der Vorlesungen gesammelt wurden, zur Verfügung. Wir sind ein Team aus drei Personen, welche aufgrund ihrer verschiedenen Charaktere und Interessen hevorragend in eigene Zuständigkeitsbereiche eingeteilt werden konnte. 

![Projektteam](/Documentation_Tree/Engineering_Folder/images/Projektteam.PNG)

Für Probleme oder Fragen stand uns in erster Linie aber das Internet zur Verfügung. Auch die Unterstützung künstlicher Intelligenz wurde genehmigt. Bei anhaltenden Problemen oder gruppenübergreifenden Themengebieten unterstützte uns unser wichtigster Stakeholder Herr Stingl.

Der finanzielle Rahmen wurde bereits in der Einleitung genannt. Dieser musste nicht vollständig ausgereizt werden. Eine genaue Aufstellung und Zusammensetzung der Kosten folgt im nächsten Kapitel.

## Budget
Die Budgetplanung fand im Zuge der Projektidee statt. Eine erste Kalkulation konnte man dem Pitch bereits entnehmen, indem wir eine Budgetobergrenze festgelegt haben und die Aufteilung in einem Kuchendiagramm festgehalten haben.

![Bild aus dem Pitch Kostenvoranschlag](/Documentation_Tree/Engineering_Folder/images/)

Die genaue Kostenverteliung der Hardware lässt sich dem unten stehenden Bild entnehmen. Rechnungen und Zeichnungen sind in dem ``Engineering_Folder`` enthalten.

![BOM aus dem Excel Sheet](/Documentation_Tree/Engineering_Folder/images/)

Für die Berechnung der Kosten der Erstellung der Software wurde ein Tool von dem Stakeholder zur Verfügung gestellt. In diesem wurden mit der Anzahl und den Typen der Requirements, eine Rechnung für die Dauer und die Kosten erstellt. Weitere wichtige Einflussfaktoren waren die Programmsprache, die Anzahl von Codezeilen und das Level der sicherheitstechnischen Relevanz für die Nutzer. Nach Eingabe der für uns erwarteten Parameter ergab sich eine Entwicklungszeit von zwei Monaten. Außerdem würden sich laut den Berechnungen für eine Serienentwicklung, Kosten in Höhe von 1.134.600 Euro ergeben.

![evtl Bild aus der Seite](/fnmsod) (würde man unter der Vorlesung KostenRBCM finden)

## Kommunikationsplan
Für die Kommunikation wurde weniger über einen festen Zeitplan geregelt (wie oben beschrieben), sondern mehr über enge Absprachen im Team. Durch die Abgabe der "Weekly Reports" war es notwendig mindestens den wöchentlichen Status zu kommunizieren. Durch diverse Treffen an den Wochenenden und täglichen Kontakt waren Absprachen sehr leicht zu treffen. Als vorteilhaft hat sich in dem Zuammenhang auch die Teamgröße herausgestellt. Da es nur drei Teammitglieder gibt, konnten Entscheidungen schnell getroffen werden und zur allgemeinen Zufriedenheit umgesetzt werden.

# Projektziele

Unsere Vision war es ein Retro-Gefühl. Außerdem wollten wir für ein angenehmes Spielerlebnis eine Steuerung mithilfe von SNES-Controllern. Diese sollten das Retro-Gefühl verstärken. Weitere wichtige Aspekte für das Projekt waren ein portables Design, austauschbare Controller, die Spielbarkeit an jedem Ort mithilfe einer Batterie, die Original Tetris Musik, sowie einen 2-Spieler-Modus. Diese und weitere Aspekte der Spiellogik, die weitestgehend auf dem Originalspiel basieren, wurden in messbare Requirements formuliert und festgehalten.

Das wichtigste Ziel war das Spiel mit den gewünschten Anforderungen innerhalb des gegebenen Zeitraums zu realisieren. Für den Erfolg dessen, wurden Teilziele und Meilensteine festgelegt.

## Erstes Teilziel
Als erstes Teilziel wurden grundlegende Anforderungen formuliert. Dies sollte den Rahmen des Projekts genau definieren. Details wie eine Materialliste, die Anforderungen und die Rollenvergabe sollten hier klar definiert werden. Diese Vorbereitungen sollten mit dem Pitch, also der offiziellen Projektvorstellung geklärt sein.

## Zweites Teilziel
Der zweite zentrale Punkt für ein erfolgreiches Projekt war die Beschaffung der benötigten Komponenten. Hierfür sollten Angebote verglichen werden und mögliche "Worst-Case" Szenarien bedacht werden. Für diese Fälle sollten ausweichende Pläne erstellt werden. Es sollte bei erfolgreichem Abschluss des ersten Teilziels zu einer schnellen Umsetzung des zweiten kommen. Die Komponenten sollten schnell beschafft und anschließend auf Funktion geprüft werden.

## Drittes Teilziel
Das dritte Teilziel umfasst die gesamte Entwicklung des eigentlichen Produkts. Die Erstellung der Software, sowie die Verbindung der einzelnen Komponenten. Vorallem die Erstellung der Software wurde dann in weitere Ziele unterteilt.

## Viertes Teilziel
Das vierte Teilziel beschreibt die Finalisierung des Projekts. Hier sollten die Tests zur Abdeckung der Requirements durchgeführt werden. Außerdem zählt zu der Finalisierung das Schreiben der Projektdokumentation.

# Risikoanalyse

Ein Risiko bezieht sich auf die Möglichkeit eines negativen oder unerwünschten Ergebnisses oder Ereignisses, das aufgrund von Unsicherheiten eintritt. Mögliche unerwünschten Ereignisse wurden sich im Vorfeld wohl überlegt. 

Hauptrisiken sehen wir in den Lieferzeiten, Entwicklungsprobleme, Hardwarelimitierungen und der Zeit.  

Verringerung von Risiken durch verschiedene Strategien...


Finanzen und Budget:
Notwendige Investitionen und Zuordnung zu den einzelnen Projektphasen.
Budgetplan: Wie werden die finanziellen Mittel eingesetzt?



# Projektverlauf und Meilensteine

Wie bereits beschrieben wurde das Projekt in vier Projektphasen unterteilt. Diese wurden vor Beginn festgelegt. Anhand des Zeitplans (siehe oben) orientierte sich der weitere Verlauf des Projekts.


### 1. Projektbeginn
Das Projekt hat mit der Idee, eine Art des Klassikers Tetris zu entwickeln, begonnen. Nach einer rudimentären Beschreibung der Funktionen und der Genehmigung des Projekts durch Studiengangsleiter und Dozenten, ging es an die Vorbereitung für den Pitch. Dafür wurden einige Marktanalysen durchgeführt. Außerdem wurden Risiken und mögliche Chancen gegeneinander abgewogen. Eine Reihe von Spezifizierungen wurde in Requirements verankert. Außerdem wurde eine Materialliste angelegt und eine Kalkulation der Kosten durchgeführt. Anschließend wurde durch den Pitch am 07.12.2023 die erste Phase des Projekts abgeschlossen.

### 2. Entwicklung
Schritte: Umreißen Sie den geplanten Projektverlauf.
Meilensteine: Definieren Sie wichtige Zwischenziele und deren Zeitpunkte.

### 3. Realisierung

### 4. Finalisierung
Das Projekt wurde im vorgegeben Zeitrahmen vollständig fertiggestellt. Hervorzuheben ist, dass alle Requirements erfüllt worden sind, ohne diese inhaltlich abzuändern. Mit anderen Worten haben wir den von uns vorgenommenen Scope vollständig umsetzen können.