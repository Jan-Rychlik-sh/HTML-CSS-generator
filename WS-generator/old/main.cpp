#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void generator();
void divCreator();
void semanticCreator();
void tableCreator();
void more();

int iteration = 0;

int main() {
    // Podaj tytuł strony
    string title;
    cout << "Podaj tytuł witryny: ";
    getline(cin, title);

    // Zapisz podstawowe wartości do pliku i twórz stronę
    ofstream plik("index.html");
    plik << "<!DOCTYPE html>\n";
    plik << "<html>\n";
    plik << "<head>\n";
    plik << "<link rel='stylesheet' href='style.css'>\n";
    plik << "<title>" << title << "</title>\n";
    plik << "</head>\n";
    plik << "<body>\n";
    generator();
    plik << "</body>\n";
    plik << "</html>\n";
    plik.close();
    
    return 0;
}

void generator() {
    for (;;) {
        int choice;
        cout << "Co chcesz zamieścić na stronie:\n";
        cout << "Menu:\n";
        cout << "1. Chcę divy!\n";
        cout << "2. Chcę semantyczne znaczniki\n";
        cout << "3. Chcę PB2 Tabelkę\n";
        cout << "Twój wybór: ";

        if (cin >> choice) {
            switch (choice) {
                case 1: divCreator(); break;
                case 2: semanticCreator(); break;
                case 3: tableCreator(); break;
                default: cout << "Nieprawidłowy wybór.\n";
            }
        } else {
            cout << "To nie jest liczba!";
            cin.clear();
            cin.ignore();
        }
    }
}

void divCreator() {
    string BGcolor, height, width, font, display, color, border, content;

    cout << "\nZaczynamy tworzenie divów! (Wpisz 'auto', aby pominąć wartość)\n";
    ofstream CSS("style.css", ios::out | ios::app);
    CSS << "div.div" << iteration << " {\n";
    cout << "Jaki kolor tła diva: ";
    cin >> BGcolor;
    if (BGcolor != "auto") { CSS << "background-color: " << BGcolor << ";\n"; }
    cout << "Wysokość: ";
    cin >> height;
    if (height != "auto") { CSS << "height: " << height << ";\n"; }
    cout << "Szerokość: ";
    cin >> width;
    if (width != "auto") { CSS << "width: " << width << ";\n"; }
    cout << "Rozmiar czcionki: ";
    cin >> font;
    if (font != "auto") { CSS << "font-size: " << font << ";\n"; }
    cout << "Display: ";
    cin >> display;
    if (display != "auto") { CSS << "display: " << display << ";\n"; }
    cout << "Kolor czcionki: ";
    cin >> color;
    if (color != "auto") { CSS << "color: " << color << ";\n"; }
    cout << "Ramka: ";
    cin >> border;
    if (border != "auto") { CSS << "border: " << border << ";\n"; }
    ofstream HTML("index.html", ios::out | ios::app);
    HTML << "<div class='div" << iteration << "'>\n";
    cout << "Zawartość: ";
    cin.ignore();
    getline(cin, content);
    if (content != "auto") { HTML << content; }
    HTML << "\n</div>\n";
    HTML.close();
    CSS << "}\n";
    CSS.close();
    more();
}

void semanticCreator() {
    cout << "W budowie";
}

void tableCreator() {
    cout << "W budowie";
}

void more() {
    cout << "\nCoś jeszcze? (Wpisz 'tak' jeśli tak, 'nie' jeśli nie): ";
    string jeszcze;
    getline(cin, jeszcze);
    transform(jeszcze.begin(), jeszcze.end(), jeszcze.begin(), ::tolower);
    if (jeszcze == "tak") {
        iteration++;
        generator();
    } else {
        exit(0);
    }
}
