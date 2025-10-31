
#include <iostream>
#include <cmath>
using namespace std;

class Forme {
public:
    virtual double aire() const = 0; // méthode virtuelle pure
    virtual ~Forme() {} // destructeur virtuel
};

class Cercle : public Forme {
private:
    double rayon;
public:
    Cercle(double r) : rayon(r) {}
    double aire() const override {
        return M_PI * rayon * rayon;
    }
};

class Rectangle : public Forme {
private:
    double longueur;
    double largeur;
public:
    Rectangle(double l, double L) : longueur(l), largeur(L) {}
    double aire() const override {
        return longueur * largeur;
    }
};

int main() {
    int n;
    cout << "Combien de formes voulez-vous créer ? ";
    cin >> n;

    Forme** formes = new Forme*[n];

    for (int i = 0; i < n; i++) {
        int choix;
        cout << "\nForme " << i + 1 << " :\n";
        cout << "1. Cercle\n2. Rectangle\nVotre choix : ";
        cin >> choix;

        if (choix == 1) {
            double r;
            cout << "Rayon : ";
            cin >> r;
            formes[i] = new Cercle(r);
        } else if (choix == 2) {
            double l, L;
            cout << "Longueur : ";
            cin >> l;
            cout << "Largeur : ";
            cin >> L;
            formes[i] = new Rectangle(l, L);
        } else {
            cout << "Choix invalide. Création d’un rectangle par défaut." << endl;
            formes[i] = new Rectangle(1, 1);
        }
    }

    cout << "\n--- Aires des formes ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Forme " << i + 1 << " : " << formes[i]->aire() << endl;
    }

    for (int i = 0; i < n; i++) {
        delete formes[i];
    }
    delete[] formes;

    return 0;
}
