#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void generateHTML5();
void generateCSS3();
int iteratio=0;

int main(){
    system("chcp 65001");
    generateHTML5();
    generateCSS3();
    getchar();
    getchar();
    return 0;
}
void generateHTML5(){
    int iterator=200;
    string title;
    cout<<"Podaj tytuł: "; getline(cin,title);
    fstream HTML;
    HTML.open("index.html", ios::out);
    HTML<<"<!DOCTYPE HTML>"<<endl;
    HTML<<"<html>"<<endl;
    HTML<<"     <head>"<<endl;
    HTML<<"         <title>"<<title<<"</title>"<<endl;
    HTML<<"         <link rel='stylesheet' href='style.css'>"<<endl;
    HTML<<"     </head>"<<endl;
    HTML<<"     <body>"<<endl;
    HTML<<"         <div class='container'>"<<endl;
    for(int i=0; i<5; i++){
        HTML<<"             <div class='h"<<iterator<<"'>"<<iterator<<"</div>"<<endl;
        iterator+=50;
    }
    HTML<<"         </div>"<<endl;
    HTML<<"     </body>"<<endl;
    HTML<<"</html>"<<endl;
    HTML.close();
}
void generateCSS3(){
    string width="width: 15%;\n";
    int height[5];
    string color[5];
    int i=0;
    int iterator=200;
    for(iterator; iterator<=400; iterator+=50){
        height[i]=iterator;
        switch(iterator){
            case 200: color[i]="red"; break;
            case 250: color[i]="greenyellow"; break;
            case 300: color[i]="deepskyblue"; break;
            case 350: color[i]="darkorchid"; break;
            case 400: color[i]="yellow"; break;
        }
        i++;
    }
    fstream CSS;
    CSS.open("style.css", ios::out);
    CSS<<"div.container {\n padding: 15px 0px 15px;\n background-color: #333333;\n min-height: 700px;\n border: 25px groove rgb(0, 255, 204);\n display: flex;\n align-items: end; \n justify-content: space-evenly;\n}\n";
    for(int i=0; i<5; i++){
        CSS<<"div.h"<<height[i]<<"{\n"<<" background-color: "<<color[i]<<";\n"<<" "<<width<<" height: "<<height[i]<<"px;\n color: #444; \n font-size: 30px;\n font-family: sans-serif;\n display: flex;\n align-items: end;\n justify-content: center;\n}\n";
    }
    CSS.close();
}