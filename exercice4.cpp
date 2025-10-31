
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NoeudFichier {
public:
    virtual int taille() const = 0;
    virtual string nom() const = 0;
    virtual ~NoeudFichier() {}
};

class Fichier : public NoeudFichier {
private:
    string _nom;
    int _taille;
public:
    Fichier(const string& nom, int taille) : _nom(nom), _taille(taille) {}
    int taille() const override { return _taille; }
    string nom() const override { return _nom; }
};

class Dossier : public NoeudFichier {
private:
    string _nom;
    vector<NoeudFichier*> enfants;
public:
    Dossier(const string& nom) : _nom(nom) {}
    void ajouter(NoeudFichier* noeud) { enfants.push_back(noeud); }
    int taille() const override {
        int somme = 0;
        for (const auto& e : enfants)
            somme += e->taille();
        return somme;
    }
    string nom() const override { return _nom; }
    ~Dossier() {
        for (auto& e : enfants) delete e;
    }
};

int main() {
    Dossier* root = new Dossier("root");
    root->ajouter(new Fichier("file1.txt", 100));
    root->ajouter(new Fichier("file2.txt", 200));

    Dossier* sub = new Dossier("subfolder");
    sub->ajouter(new Fichier("file3.txt", 150));
    root->ajouter(sub);

    cout << "Taille totale du dossier " << root->nom() << " : " << root->taille() << " octets" << endl;

    delete root;
    return 0;
}
