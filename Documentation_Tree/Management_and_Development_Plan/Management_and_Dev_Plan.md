<!-- Table of contents -->

# Inhalt

1. [Ausgangslage](#ausgangslage)
-  [Zeitplan](#zeitplan)
-  [Ressourcen](#ressourcen)
- [Budget](#)
- [Kommunikationsplan](#)
2. [Projektziele](#projektziele)
3. [Chancen und Risiken](#chancen-und-risiken)
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

![Bild aus dem Pitch Kostenvoranschlag](/Documentation_Tree/Engineering_Folder/images/Cost_Estimation.PNG)

Die genaue Kostenverteliung der Hardware lässt sich dem unten stehenden Bild entnehmen. Rechnungen und Zeichnungen sind in dem ``Engineering_Folder`` enthalten.

![BOM aus dem Excel Sheet](/Documentation_Tree/Engineering_Folder/images/BOM.PNG)

Man sieht nun hevorragend den Vergleich zwischen den eigentlichen Kosten und den Anfangs erwarteten Kosten. Die erwarteten Kosten liegen deutlich über den tatsächlichen Kosten, da benötigtes Werkzeug wie ein Lötkolben o.ä. für den ersten Kostenvoranschlag mit gerechnet wurden. Dies wurde als Vorsichtsmaßnahme gemacht, um mögliche Steigerungen des Budgets ausschließen zu können. Darüberhinaus wurde eine andere Komponente für die Matrizen verwendet, als ursprünglich geplant war.

Für die Berechnung der Kosten der Erstellung der Software wurde ein Tool von dem Stakeholder zur Verfügung gestellt. In diesem wurden mit der Anzahl und den Typen der Requirements, eine Rechnung für die Dauer und die Kosten erstellt. Weitere wichtige Einflussfaktoren waren die Programmsprache, die Anzahl von Codezeilen und das Level der sicherheitstechnischen Relevanz für die Nutzer. Nach Eingabe der für uns erwarteten Parameter ergab sich eine Entwicklungszeit von zwei Monaten. Außerdem würden sich laut den Berechnungen für eine Serienentwicklung, Kosten in Höhe von 1.134.600 Euro ergeben.

## Kommunikationsplan
Für die Kommunikation wurde weniger über einen festen Zeitplan geregelt (wie oben beschrieben), sondern mehr über enge Absprachen im Team. Durch die Abgabe der "Weekly Reports" war es notwendig mindestens den wöchentlichen Status zu kommunizieren. Durch diverse Treffen an den Wochenenden und täglichen Kontakt waren Absprachen sehr leicht zu treffen. Als vorteilhaft hat sich in dem Zuammenhang auch die Teamgröße herausgestellt. Da es nur drei Teammitglieder gibt, konnten Entscheidungen schnell getroffen werden und zur allgemeinen Zufriedenheit umgesetzt werden.

# Projektziele

Unsere Vision war es ein Retro-Gefühl. Außerdem wollten wir für ein angenehmes Spielerlebnis eine Steuerung mithilfe von SNES-Controllern. Diese sollten das Retro-Gefühl verstärken. Weitere wichtige Aspekte für das Projekt waren ein portables Design, austauschbare Controller, die Spielbarkeit an jedem Ort mithilfe einer Batterie, die Original Tetris Musik, sowie einen 2-Spieler-Modus. Diese und weitere Aspekte der Spiellogik, die weitestgehend auf dem Originalspiel basieren, wurden in messbare Requirements formuliert und festgehalten.

Das wichtigste Ziel war das Spiel mit den gewünschten Anforderungen innerhalb des gegebenen Zeitraums zu realisieren. Für den Erfolg dessen, wurden Teilziele und Meilensteine festgelegt.

## Erstes Teilziel
Im ersten Teilziel wurden grundlegende Anforderungen formuliert. Dies sollte den Rahmen des Projekts genau definieren. Details wie eine Materialliste, die Anforderungen und die Rollenvergabe sollten hier klar definiert werden. Diese Vorbereitungen sollten mit dem Pitch, also der offiziellen Projektvorstellung geklärt sein.

## Zweites Teilziel
Der zweite zentrale Punkt für ein erfolgreiches Projekt war die Beschaffung der benötigten Komponenten. Hierfür sollten Angebote verglichen werden und mögliche "Worst-Case" Szenarien bedacht werden. Für diese Fälle sollten ausweichende Pläne erstellt werden. Es sollte bei erfolgreichem Abschluss des ersten Teilziels zu einer schnellen Umsetzung des zweiten kommen. Die Komponenten sollten schnell beschafft und anschließend auf Funktion geprüft werden.

## Drittes Teilziel
Das dritte Teilziel umfasst die gesamte Entwicklung des eigentlichen Produkts. Die Erstellung der Software, sowie die Verbindung der einzelnen Komponenten. Vorallem die Erstellung der Software wurde dann in weitere Ziele unterteilt.

## Viertes Teilziel
Das vierte Teilziel beschreibt die Finalisierung des Projekts. Hier sollten die Tests zur Abdeckung der Requirements durchgeführt werden. Außerdem zählt zu der Finalisierung das Schreiben der Projektdokumentation.

# Chancen und Risiken

Grundsätzlich sind die Risiken bei unserem Projekt von keiner größeren Relevanz, da es insgesamt kein Projekt ist, bei dem Menschenleben bedroht oder gefährdet sind.

Ein Risiko bezieht sich auf die Möglichkeit eines negativen oder unerwünschten Ergebnisses oder Ereignisses, das aufgrund von Unsicherheiten eintritt. Mögliche unerwünschten Ereignisse wurden sich im Vorfeld wohl überlegt. 

Hauptrisiken haben wir in den Lieferzeiten, möglichen Entwicklungsproblemen, Hardwarelimitierungen und dem Umfang gesehen. Einige der eben genannten Risiken lassen sich auf den Faktor Zeit zurückführen, der anfangs ein zentraler Aspekt gewesen ist. Bei zu großem Umfang lässt sich das Produkt nicht fertigstellen und einige Requirements wären damit nicht berücksichtigt. Des Weiteren waren wir uns unsicher in der Spielbarkeit der Endanwendung. Bei nicht-implementieren der Controller aufgrund diverser Probleme, würde eine Ansteuerung der gesamten Spiellogik alternativlos.

 Im Hinblick auf eine Kommerzialisierung bestehen definitiv Risiken mit der Lizensierung der Spiellogik und der Musik. Außerdem stellt sich da das Risiko, dass man an den Kunden vorbei entwickelt und somit keine Nachfrage generieren kann. Da dieses Projekt nicht dafür ausgelegt wurde, reichen jedoch Einzelnachweise für die Quellen und eine mögliche nicht vorhandene Nachfrage benötigt keine genauere Betrachtung. 

Es gibt verschiendene Möglichkeiten bestehende Risiken zu verringern. Eine Strategie ist die Risikovermeidung. Dies beinhaltet, Entscheidungen zu treffen, die dazu führen, dass das Risiko vollständig vermieden wird. Eine vollständige Risikovermeidung haben wir bei der Hardwarelimitierung vorgenommen. Für die Stromversorgung entschieden wir uns im ersten Prototypen gegen eine Batterieversorgung und für eine feste Stromversorgung durch einen Netzstecker. Außerdem wählten wir als Mikrocontroller einen Arduino MEGA und keinen Arduino UNO, sodass mögliche Speicherplatzrisiken unwirksam wurden.

Bei der Risikominderung hingegen werden Maßnahmen ergriffen, um die Wahrscheinlichkeit des Eintretens eines Risikos oder die Auswirkungen eines Risikos zu verringern. Dies haben wir im Bezug auf Lieferengpässe getan, indem wir uns Ersatzlieferanten gesucht haben.
Eine weitere Möglichkeit ist die Risikoübertragung. Dies beinhaltet, das Risiko auf eine andere Partei zu übertragen, z.B. durch Versicherungen. In unserem Falle war jedoch kein Risiko so groß, dass wir die Verantwortung dafür abgeben mussten.
Wenn vorangegangene Methoden nicht helfen, dann gibt es die Risikoakzeptanz. Manchmal ist es am besten, das Risiko zu akzeptieren, wenn die Kosten für die Minderung des Risikos die potenziellen Vorteile übersteigen. Dies war bei uns der Fall in dem Umfang des gesamten Projekts, wobei auch hier Vorkehrungen zur Minimierung getroffen worden sind.

Eine Chance bezieht sich auf eine günstige oder vorteilhafte Umstand, Situation oder Gelegenheit, die zu einem positiven Ergebnis führen kann.

Bei den Chancen sehen wir, dass es ein Spiel ist, welches auf breite Akzeptanz trifft. Das Original gehört zu den meistverkauften Spielen der Zeitgeschichte. Wir gehen bewusst in die 'Retro' Richtung, da bei den sich schnell ändernden Voraussetzungen heutzutage etwas ewig währendes einen Halt gibt. Es ist ein Retro-Spielzeug, mit dem Millionen Menschen gespielt haben. Bei einer Kommerzialisierung würde man wahrscheinlich auf breite Akzeptanz stoßen, da die Spiellogik bereits bekannt ist und lediglich neu definiert wurde.

Außerdem sieht unser Produkt einen Zwei-Spieler-Modus vor, der ein absolutes Alleinstellungsmerkmal darstellt. Ein weiterer herausragender Aspekt ist die einfache Steuerung, die mit SNES-Controllern realisiert wird. Auch hier sieht man wieder den Retro-Faktor durch Nutzen dieser Controller, die bereits seit Jahrzehnten auf dem Markt sind. Wir begreifen dies als Vorteil, da es im Gesamtpaket aufeinander abgestimmt ist und etwas völlig konträres in der heutigen Unterhaltungsindustrie darstellt.

Eine ausführliche Risikoanalyse und der Veränderung dessen finden Sie im ``Engineering_Folder``.

# Projektverlauf und Meilensteine

Wie bereits beschrieben wurde das Projekt in vier Projektphasen unterteilt. Diese wurden vor Beginn festgelegt. Anhand des Zeitplans (siehe oben) orientierte sich der weitere Verlauf des Projekts.


### 1. Projektbeginn
Das Projekt hat mit der Idee, eine Art des Klassikers Tetris zu entwickeln, begonnen. Nach einer rudimentären Beschreibung der Funktionen und der Genehmigung des Projekts durch Studiengangsleiter und Dozenten, ging es an die Vorbereitung für den Pitch. Dafür wurden einige Marktanalysen durchgeführt. Außerdem wurden Risiken und mögliche Chancen gegeneinander abgewogen. Eine Reihe von Spezifizierungen wurde in Requirements verankert. Außerdem wurde eine Materialliste angelegt und eine Kalkulation der Kosten durchgeführt. Anschließend wurde durch den Pitch am 07.12.2023 die erste Phase des Projekts abgeschlossen. Somit galt auch das erste Teilziel als erfolgreich abgeschlossen.

### 2. Entwicklung
Schritte: Umreißen Sie den geplanten Projektverlauf.
Meilensteine: Definieren Sie wichtige Zwischenziele und deren Zeitpunkte.

### 3. Realisierung

### 4. Finalisierung
Das Projekt wurde im vorgegeben Zeitrahmen vollständig fertiggestellt. Hervorzuheben ist, dass alle Requirements erfüllt worden sind, ohne diese inhaltlich abzuändern. Mit anderen Worten haben wir den von uns vorgenommenen Scope vollständig umsetzen können.