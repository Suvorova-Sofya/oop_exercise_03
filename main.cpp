#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include "figure.h"
#include "five_angles.h"
#include "six_angles.h"
#include "eight_angles.h"

int main() {
    std::vector<figure*> figures;
    char a[14];
    char a1[10];
    while(scanf("%s",a)>0){
        figure *new_figure;
        if(strcmp(a,"five_angles")==0){
            new_figure=new five_angles(std::cin);
        } else if(strcmp(a,"six_angles")==0){
            new_figure=new six_angles(std::cin);
        }else if(strcmp(a,"eight_angles")==0){
            new_figure=new eight_angles(std::cin);
        }
        figures.push_back(new_figure);
        int g;
        g=scanf("%s",a1);
        if(g==0){
            break;
        }
        if(strcmp(a1,"print")==0){
            for (size_t i = 0; i < figures.size(); ++i) {
                figures[i]->print(std::cout);
            }
        }else if(strcmp(a1,"center")==0){
            for (size_t i = 0; i < figures.size(); ++i) {
                point p=figures[i]->center();
                std::cout << p << "\n";
            }
        }else if(strcmp(a1,"square")==0){
            for (size_t i = 0; i < figures.size(); ++i) {
                std::cout << figures[i]->square() << "\n";
            }
        }else if(strcmp(a1,"destroy")==0){
            int id;
            std::cin >> id;
            delete figures[id];
            figures.erase(figures.begin() + id);
        }
    }
    for (size_t i = 0; i < figures.size(); ++i) {
        delete figures[i];
    }
    return 0;
}