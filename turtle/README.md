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
