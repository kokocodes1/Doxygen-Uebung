Befehl zum Kompilieren: gcc main.c mergesort.c

Auszug aus Präsentation:

Um Doxygen-Konfigurationsdatei anzulegen in der Kommandozeile eingeben:
doxygen -g
Um Dokumentation zu erstellen, wenn Konfigurationsdatei existiert: 
doxygen
HTML-Dokumentation öffnen: in diesem Ordner html/index.html

Doxygen erkennt mehrzeilige Kommentare, wenn sie dieses Format haben:/*! text */
Das ist nur eine Möglichkeit, siehe Doxygen-Handbuch
Damit eine Datei dokumentiert wird, muss an ihren Anfang ein mehrzeiliger Doxygen-Kommentar, der Folgendes enthält: 
@file Dateiname
Außerdem
Kurze Dateibeschreibung:
@brief Beschreibung
Lange Dateibeschreibung: weiterer Text im Kommentar

Um eine Funktion zu dokumentieren, muss vor die Funktion ein Doxygen-Kommentar
Um die Eigenschaften einer Funktion zu dokumentieren, gibt es:
- Kurzbeschreibung: @brief
- Parameter dokumentieren: @param name beschreibung
  Nach @param kann [in] oder [out] stehen
- Rückgabewert dokumentieren: @return wert
- Weiterer Text für lange Beschreibung

Pullt den Ordner (getan)
Kommentiert jede Sourcecode-Datei mit @file
Kommentiert jede Funktion mit @brief, @param und ggf. @return
Schaut euch die HTML-Dokumentation an