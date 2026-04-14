#include <iostream>
using namespace std;

struct Equipo {
    string nombre;
    int pj;
    int pg;
    int pe;
    int pp;
    int gf;
    int gc;
    int dg;
    int puntos;
};

int main() {

    Equipo equipos[18] = {
        {"PSG", 10, 8, 1, 1, 25, 10, 0, 0},
        {"Marseille", 10, 6, 2, 2, 18, 12, 0, 0},
        {"Monaco", 10, 5, 3, 2, 20, 15, 0, 0},
        {"Lille", 10, 5, 2, 3, 14, 11, 0, 0},
        {"Lyon", 10, 4, 3, 3, 16, 14, 0, 0},
        {"Nice", 10, 4, 3, 3, 12, 10, 0, 0},
        {"Lens", 10, 4, 2, 4, 13, 13, 0, 0},
        {"Rennes", 10, 3, 4, 3, 15, 14, 0, 0},
        {"Reims", 10, 3, 3, 4, 11, 12, 0, 0},
        {"Montpellier", 10, 3, 3, 4, 10, 13, 0, 0},
        {"Toulouse", 10, 3, 2, 5, 9, 14, 0, 0},
        {"Strasbourg", 10, 2, 4, 4, 8, 11, 0, 0},
        {"Nantes", 10, 2, 3, 5, 7, 12, 0, 0},
        {"Brest", 10, 2, 3, 5, 6, 13, 0, 0},
        {"Clermont", 10, 2, 2, 6, 9, 16, 0, 0},
        {"Lorient", 10, 2, 2, 6, 8, 17, 0, 0},
        {"Metz", 10, 1, 3, 6, 7, 15, 0, 0},
        {"Le Havre", 10, 1, 2, 7, 6, 18, 0, 0}
    };

    int n = 18;

    for (int i = 0; i < n; i++) {
        equipos[i].puntos = equipos[i].pg * 3 + equipos[i].pe;
        equipos[i].dg = equipos[i].gf - equipos[i].gc;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (equipos[j].puntos < equipos[j + 1].puntos ||
               (equipos[j].puntos == equipos[j + 1].puntos &&
                equipos[j].dg < equipos[j + 1].dg)) {

                Equipo temp = equipos[j];
                equipos[j] = equipos[j + 1];
                equipos[j + 1] = temp;
            }
        }
    }

    cout << "TABLA DE POSICIONES - LIGA FRANCESA\n\n";
    cout << "Pos\tEquipo\t\tPJ\tPG\tPE\tPP\tGF\tGC\tDG\tPts\n";

    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t"
             << equipos[i].nombre << "\t\t"
             << equipos[i].pj << "\t"
             << equipos[i].pg << "\t"
             << equipos[i].pe << "\t"
             << equipos[i].pp << "\t"
             << equipos[i].gf << "\t"
             << equipos[i].gc << "\t"
             << equipos[i].dg << "\t"
             << equipos[i].puntos << "\n";
    }

    return 0;
}
