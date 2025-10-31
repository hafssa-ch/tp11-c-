
#include <iostream>
using namespace std;

class Paiement {
public:
    virtual void effectuerPaiement(double montant) const = 0; // méthode virtuelle pure
    virtual ~Paiement() {} // destructeur virtuel
};

class PaiementCarte : public Paiement {
public:
    void effectuerPaiement(double montant) const override {
        cout << "Paiement de " << montant << " DH par carte bancaire." << endl;
    }
};

class PaiementEspece : public Paiement {
public:
    void effectuerPaiement(double montant) const override {
        cout << "Paiement de " << montant << " DH en espèces." << endl;
    }
};

int main() {
    int n;
    cout << "Combien de paiements voulez-vous simuler ? ";
    cin >> n;

    Paiement** paiements = new Paiement*[n];

    for (int i = 0; i < n; i++) {
        int choix;
        double montant;

        cout << "\nPaiement " << i + 1 << " :\n";
        cout << "1. Carte bancaire\n2. Espèces\nVotre choix : ";
        cin >> choix;
        cout << "Montant à payer : ";
        cin >> montant;

        if (choix == 1) {
            paiements[i] = new PaiementCarte();
        } else if (choix == 2) {
            paiements[i] = new PaiementEspece();
        } else {
            cout << "Choix invalide. Paiement par carte par défaut." << endl;
            paiements[i] = new PaiementCarte();
        }

        paiements[i]->effectuerPaiement(montant);
    }

    for (int i = 0; i < n; i++) {
        delete paiements[i];
    }
    delete[] paiements;

    return 0;
}
