# Turtle Graphics Compiler + Debuger
Ein Compiler und Debugger für die Turtle Graphics Lernsprache. 

## Compiler
Der Compiler selbst hält sich größtenteils an die [Aufgabenstellung](https://computerix.info/comp-bau/turtle.pdf). flex wird als Lexer-Generator verwendet und die Input-Datei dafür ist die [turtle.l](./turtle.l). Als Parser-Generator dient bison, wobei die Input-Datei die [turtle.y](./turtle.y) ist. Alle Beispiel-Turtle-Programme werden vom Compiler ohne Probleme ausgeführt (siehe [examples/](./examples/)).

## Debugger
Die Besonderheit dieses Compilers liegt darin, dass zusätzlich eine Debugger Funktionalität implementiert ist.

### Verwendung
Gestartet werden kann der Debugger durch anhängen des `-d` Flags beim Aufruf eines Turtleprogramms. Mittels `help` können anschließend alle verfügbahren Debugger-Befehle aufgelistet werden.

**Funktionalität des Debuggers:**
- Step Over
- Step In
- Step Out
- Zeilenweise Breakpoints
- Ausgeben des Stacktraces
- Ausgeben von Variablen-Werten

### Technische Umsetzung
Bei jeder Evaluierung einer Turtle Expression und Condition, sowie bei jedem Auführen eines Statements wird eine Debugger-Funktion `debug_loop()` aufgerufen. Ist der Debugger aktiv, überprüft diese Funktion, ob sich auf der Zeile des auszuführenden Knotens ein Breakpoint befindet und pausiert die Ausführung des Programms bei Bedarf. Anschließend wird abhängig vom aktuellen Status des Debuggers (Läuft er, Befindet er sich im Stepping Mode, etc...) entweder auf eine Eingabe des Nutzers gewartet, oder die Ausführung des Programms fortgesetzt.

Damit der Debugger den Stacktrace verfolgen kann, werden bei jedem Aufruf und Returnen einer Turtle Routine die Debugger Funktionen `push_stacktrace()`, sowie `pop_stacktrace()` aufgerufen.

## VS-Code Extension
Zusätzlich wurde eine [VS-Code Extension](https://marketplace.visualstudio.com/items?itemName=niklas-simon.turtlescript) für Turtle entwickelt. Die Extension umfasst Syntaxhighlighting, sowie Support für die in VS-Code eingebaute Debugger-Oberfläche. Der Quelltext dafür ist in einem [seperaten Repository](https://github.com/niklas-simon/dhge-turtlescript-vscode) zu finden.

## Build
### Vorbedingungen:
- gcc
- flex
- bison
- Optional: doxygen

### Prozess
```bash
# Repository klonen
git clone https://github.com/niklas-simon/dhge-compilerbau.git

# In das Verzeichnis des Compilers wechseln
cd dhge-compilerbau/turtle

# Abhängig von Windows oder Linux das jeweilige build script ausführen
./build.sh

# Optional: Doxygen Dokumentation generieren
doxygen
```

## Projektverlauf
### Schwierigkeiten
Als besonders schwierig erwies sich das Starten mit dem Projekt. Am hilfreichsten war hierfür der Test mittels Taschenrechner-Anwendung sowie die verfügbaren Folien.  
Insbesondere das Erstellen der `build.sh|build.cmd`, um das Projekt erst zu compilieren, erwieß sich als herausfordernd. 
### Verlauf
Sobald das Projekt compiliert werden konnte musste der zur Verfügung gestellte Code verstanden werden. Dies erwies sich jedoch durch die umfangreich formulierte Aufgabenstellung als recht simpel. Zur Validierung der Implementierung konnten die verfügbaren Beispiele gut verwendet werden.  
Als dann alle Beispiele liefen, stand man vor der Frage: Was nun? Die Implementierung insgesamt war zwar anspruchsvoll, aber spaßig, daher kann man doch sicher noch etwas mehr machen. Somit kam dann die Idee der VSCode-Erweiterung.  
Zunächst war geplant, einfaches Syntax Highlighting zum Laufen zu bekommen. Allein dadurch wird die Entwicklung von turtlescript-Programmen immens erleichtert. Für Syntax Highlighting verwendet vscode sog. Textmate-Grammatiken. Diese kategorisiert bestimmte Tokens (z.B. `if` und `else` als Konditionale oder `@1`-`@9` als globale Variablen) wodurch diese Tokens dann farbig markiert werden können. Die tatsächlich verwendete Farbe hängt dann vom verwendeten Theme ab, wird also üblicherweise nicht direkt in der Grammatik festgelegt.  
Als das Syntax Highlighting fertig war, kam der Gedanke, ein Debugger wäre doch wünschenswert. VSCode bietet dazu ein Protokoll, welches DAP (Debug Adapter Protocol) genannt wird. Wird das Protokoll richtig implementiert, funktioniert die Oberfläche von vscode wie von Zauberhand als Debugger für die jeweilige Sprache. Hier war ebenfalls die größte Hürde, mit dem ganzen anzufangen. Zunächst muss das Protokoll grundlegend verstanden werden. Dann ist die Frage der Umsetzung. Die eigentliche Implementierung war dann, wie schon beim Kernprojekt, nur noch eine Fleißarbeit.
### Fazit
Insgesamt wurde das Projekt als sehr lehrreich empfunden. Unser Verständnis von Lexern, Parsern, Compilern und Interpretern wurde immens erweitert. Aber auch zu lernen, was bei VSCode im Hintergrund abläuft, war sehr interessant.  
Die Erweiterung kann in VSCode über die ID `niklas-simon.turtlescript` oder [im VSCode Extension Marketplace](https://marketplace.visualstudio.com/items?itemName=niklas-simon.turtlescript) gefunden werden.
