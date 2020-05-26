/*  Dumea Alexandru-Gabriel 144
    Compiled on Microsoft Visual Studio Community 2019 Version 16.5.3
    Tutore Laborator: Miriam Costan
*/


#include <iostream>
#include <exception>
#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

#define TOTAL_BACTERII 1000000000
#define TOTAL_FUNGI 1.5 * 1000000
#define TOTAL_VIRUSURI 100000000

class MyException : public std::exception
{
    const char* exceptie;
public:
    MyException(const char* exceptie) : exceptie(exceptie) {}

    const char* what() const noexcept
    {
        return exceptie;
    }
};

class Masca
{
private:
    string tip_protectie;
    string model;

public:
    Masca() : tip_protectie(""), model("") {}
    Masca(string tip_protectie, string model="") : tip_protectie(tip_protectie), model(model) {}
    Masca(const Masca& other) : tip_protectie(other.tip_protectie), model(other.model) {}
    virtual ~Masca() { tip_protectie = ""; }

    string getTipProtectie() const { return tip_protectie; }
    void setTipProtectie(string tip) { tip_protectie = tip; }

    string getModel() const { return model; }
    void setModel(string model) { this->model = model; }

    virtual void afisareMasca(std::ostream& out) const;
    virtual void citireMasca(std::istream& in);

    Masca& operator=(const Masca& other);
    friend std::istream& operator>>(std::istream& in, Masca& masca);
    friend std::ostream& operator<<(std::ostream& out, const Masca& masca);
};

class MascaChirurgicala : public Masca
{
private:
    string culoare;
    int nrPliuri;

public:
    MascaChirurgicala() : Masca(), culoare(""), nrPliuri(0) {}
    MascaChirurgicala(string tip_protectie, string culoare, int nrPliuri)
        : Masca(tip_protectie), culoare(culoare), nrPliuri(nrPliuri) {}
    MascaChirurgicala(const MascaChirurgicala& other) 
        : Masca(other), culoare(other.culoare), nrPliuri(other.nrPliuri) {}

    ~MascaChirurgicala() { culoare = ""; nrPliuri = 0; }

    string getCuloare() const { return culoare; }
    int getNrPliuri() const { return nrPliuri; }

    void setCuloare(string c) { culoare = c; }
    void setCuloare(int nr) { nrPliuri = nr; }

    void afisareMasca(std::ostream& out) const;
    void citireMasca(std::istream& in);

    MascaChirurgicala& operator=(const MascaChirurgicala& other);
    friend std::istream& operator>>(std::istream& in, MascaChirurgicala& masca);
    friend std::ostream& operator<<(std::ostream& out, const MascaChirurgicala& masca);
};

class MascaPolicarbonat : public Masca
{
private:
    string tip_prindere;

public:
    MascaPolicarbonat() : Masca(), tip_prindere("") {}
    MascaPolicarbonat(string tip_prindere)
        : Masca("ffp0"), tip_prindere(tip_prindere) {}
    MascaPolicarbonat(const MascaPolicarbonat& other)
        : Masca(other), tip_prindere(other.tip_prindere) {}
    ~MascaPolicarbonat() { tip_prindere = ""; }

    string getTipPrindere() const { return tip_prindere; }
    void setTipPrindere(string tip) { tip_prindere = tip; }

    void afisareMasca(std::ostream& out) const;
    void citireMasca(std::istream& in);

    MascaPolicarbonat& operator=(const MascaPolicarbonat& other);
    friend std::istream& operator>>(std::istream& in, MascaPolicarbonat& masca);
    friend std::ostream& operator<<(std::ostream& out, const MascaPolicarbonat& masca);
};

class Dezinfectant
{
protected:
    int nrSpeciiUcise;
    std::vector<string> ingrediente;
    std::vector<string> suprafete;

public:
    Dezinfectant() : nrSpeciiUcise(0), ingrediente(std::vector<string>()), suprafete(std::vector<string>()) {}
    Dezinfectant(int nrSpeciiUcise, std::vector<string> ingrediente, std::vector<string> suprafete)
        : nrSpeciiUcise(nrSpeciiUcise), ingrediente(ingrediente), suprafete(suprafete) {}
    Dezinfectant(const Dezinfectant& other);
    virtual ~Dezinfectant();

    virtual long eficienta() = 0;
    virtual void afisareDezinfectant(std::ostream& out) const;

    Dezinfectant& operator=(const Dezinfectant& other);
    friend std::istream& operator>>(std::istream& in, Dezinfectant& dezinfectant);
    friend std::ostream& operator<<(std::ostream& out, const Dezinfectant& dezinfectant);
};

class DezinfectantBacterii : virtual public Dezinfectant
{
private:

public:
    DezinfectantBacterii() : Dezinfectant() {}
    DezinfectantBacterii(int nrSpeciiUcise, std::vector<string> ingrediente, std::vector<string> suprafete)
        : Dezinfectant(nrSpeciiUcise, ingrediente, suprafete) {}
    DezinfectantBacterii(const DezinfectantBacterii& other) : Dezinfectant(other) {}
    ~DezinfectantBacterii() {}

    long eficienta();
    void afisareDezinfectant(std::ostream& out) const;

    DezinfectantBacterii& operator=(const DezinfectantBacterii& other);
    friend std::istream& operator>>(std::istream& in, DezinfectantBacterii& dezinfectant);
    friend std::ostream& operator<<(std::ostream& out, const DezinfectantBacterii& dezinfectant);
};

class DezinfectantFungi : virtual public Dezinfectant
{
private:


public:
    DezinfectantFungi() : Dezinfectant() {}
    DezinfectantFungi(int nrSpeciiUcise, std::vector<string> ingrediente, std::vector<string> suprafete)
        : Dezinfectant(nrSpeciiUcise, ingrediente, suprafete) {}
    DezinfectantFungi(const Dezinfectant& other) : Dezinfectant(other) {}
    ~DezinfectantFungi() {}

    long eficienta();
    void afisareDezinfectant(std::ostream& out) const;

    DezinfectantFungi& operator=(const DezinfectantFungi& other);
    friend std::istream& operator>>(std::istream& in, DezinfectantFungi& dezinfectant);
    friend std::ostream& operator<<(std::ostream& out, const DezinfectantFungi& dezinfectant);
};

class DezinfectantVirusuri : virtual public Dezinfectant
{
private:

public:
    DezinfectantVirusuri() : Dezinfectant() {}
    DezinfectantVirusuri(int nrSpeciiUcise, std::vector<string> ingrediente, std::vector<string> suprafete)
        : Dezinfectant(nrSpeciiUcise, ingrediente, suprafete) {}
    DezinfectantVirusuri(const Dezinfectant& other) : Dezinfectant() {}
    ~DezinfectantVirusuri() {}

    long eficienta();
    void afisareDezinfectant(std::ostream&) const;

    DezinfectantVirusuri& operator=(const DezinfectantVirusuri& other);
    friend std::istream& operator>>(std::istream& in, DezinfectantVirusuri& dezinfectant);
    friend std::ostream& operator<<(std::ostream& out, const DezinfectantVirusuri& dezinfectant);
};


// mostenire diamant
class DezinfectantUniversal : public DezinfectantBacterii,
                              public DezinfectantFungi,
                              public DezinfectantVirusuri
{
private:

public:
    DezinfectantUniversal() : DezinfectantBacterii(), DezinfectantFungi(), DezinfectantVirusuri() {}
    DezinfectantUniversal(int nrSpeciiUcise, std::vector<string> ingrediente, std::vector<string> suprafete)
        : DezinfectantBacterii(nrSpeciiUcise, ingrediente, suprafete),
          DezinfectantFungi(nrSpeciiUcise, ingrediente, suprafete),
          DezinfectantVirusuri(nrSpeciiUcise, ingrediente, suprafete) {}

    long eficienta();
    void afisareDezinfectant(std::ostream&) const;

    DezinfectantUniversal& operator=(const DezinfectantUniversal& other);
    friend std::istream& operator>>(std::istream& in, DezinfectantUniversal& dezinfectant);
    friend std::ostream& operator<<(std::ostream& out, const DezinfectantUniversal& dezinfectant);
};


// Masca
void Masca::afisareMasca(std::ostream& out) const
{
    out << "\n\n" << typeid(*this).name() << '\n'; //afisam tipul mastii
    out << "Tip Protectie: " << tip_protectie << '\n';
}

void Masca::citireMasca(std::istream& in)
{
    in >> tip_protectie;
}

Masca& Masca::operator=(const Masca& other)
{
    tip_protectie = other.tip_protectie;
    return *this;
}

std::istream& operator>>(std::istream& in, Masca& masca)
{
    masca.citireMasca(in); //este necesar sa apelam functii virtuale pentru late-binding la operatorii friend
    return in;
}

std::ostream& operator<<(std::ostream& out, const Masca& masca)
{
    masca.afisareMasca(out);
    return out;
}

// Masca Chirurgicala
void MascaChirurgicala::afisareMasca(std::ostream& out) const
{
    Masca::afisareMasca(out);
    out << "Culoare: " << culoare << '\n';
    out << "Nr Pliuri: " << nrPliuri << '\n';
}

void MascaChirurgicala::citireMasca(std::istream& in)
{
    Masca::citireMasca(in);
    in >> culoare;

    try {
        in >> nrPliuri;
        if (nrPliuri < 0)
            throw MyException("Numar invalid de pliuri!\n");
    }
    catch (const std::exception& e) {
        std::cout << e.what();
        std::cout << "Incercati din nou: ";
        in >> nrPliuri;
    }
}

MascaChirurgicala& MascaChirurgicala::operator=(const MascaChirurgicala& other)
{
    Masca::operator=(other);
    culoare = other.culoare;
    nrPliuri = other.nrPliuri;

    return *this;
}

std::istream& operator>>(std::istream& in, MascaChirurgicala& masca)
{
    masca.citireMasca(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const MascaChirurgicala& masca)
{
    masca.afisareMasca(out);
    return out;
}


// Masca Policarbonat
void MascaPolicarbonat::afisareMasca(std::ostream& out) const
{
    Masca::afisareMasca(out);
    out << "Tip Prindere: " << tip_prindere << '\n';
}

void MascaPolicarbonat::citireMasca(std::istream& in)
{
    Masca::citireMasca(in);
    in >> tip_prindere;
}

MascaPolicarbonat& MascaPolicarbonat::operator=(const MascaPolicarbonat& other)
{
    Masca::operator=(other);
    tip_prindere = other.tip_prindere;

    return *this;
}

std::istream& operator>>(std::istream& in, MascaPolicarbonat& masca)
{
    masca.citireMasca(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const MascaPolicarbonat& masca)
{
    masca.afisareMasca(out);
    return out;
}

// --------------------

// Dezinfectant
Dezinfectant::Dezinfectant(const Dezinfectant& other)
{
    nrSpeciiUcise = other.nrSpeciiUcise;
    ingrediente = other.ingrediente;
    suprafete = other.suprafete;
}

Dezinfectant::~Dezinfectant()
{
    nrSpeciiUcise = 0;
    ingrediente.clear();
    suprafete.clear();
}


void Dezinfectant::afisareDezinfectant(std::ostream& out) const
{
    out << "Nr Specii Ucise: " << nrSpeciiUcise << '\n';
    out << "Ingrediente: ";
    for (auto it : ingrediente)
        out << it << ' ';

    out << "\nSuprafete: ";
    for (auto it : suprafete)
        out << it << ' ';

    out << '\n';
}

Dezinfectant& Dezinfectant::operator=(const Dezinfectant& other)
{
    nrSpeciiUcise = other.nrSpeciiUcise;
    ingrediente = other.ingrediente;
    suprafete = other.suprafete;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Dezinfectant& dezinfectant)
{
    dezinfectant.afisareDezinfectant(out);
    return out;
}

// Dezinfectant Bacterii

long DezinfectantBacterii::eficienta()
{
    return Dezinfectant::nrSpeciiUcise / TOTAL_BACTERII;
}

void DezinfectantBacterii::afisareDezinfectant(std::ostream& out) const
{
    out << "Dezinfectant Bacterii\n";
    Dezinfectant::afisareDezinfectant(out);
}

DezinfectantBacterii& DezinfectantBacterii::operator=(const DezinfectantBacterii& other)
{
    Dezinfectant::operator=(other);
    return *this;
}


std::ostream& operator<<(std::ostream& out, const DezinfectantBacterii& dezinfectant)
{
    dezinfectant.afisareDezinfectant(out);
    return out;
}

// Dezinfectant Fungi

long DezinfectantFungi::eficienta()
{
    return Dezinfectant::nrSpeciiUcise / TOTAL_FUNGI;
}

void DezinfectantFungi::afisareDezinfectant(std::ostream& out) const
{
    out << "Dezinfectant Fungi\n";
    Dezinfectant::afisareDezinfectant(out);
}

DezinfectantFungi& DezinfectantFungi::operator=(const DezinfectantFungi& other)
{
    Dezinfectant::operator=(other);
    return *this;
}


std::ostream& operator<<(std::ostream& out, const DezinfectantFungi& dezinfectant)
{
    dezinfectant.afisareDezinfectant(out);
    return out;
}

// Dezinfectant Virusuri
long DezinfectantVirusuri::eficienta()
{
    return Dezinfectant::nrSpeciiUcise / TOTAL_VIRUSURI;
}

void DezinfectantVirusuri::afisareDezinfectant(std::ostream& out) const
{
    out << "Dezinfectant Virusuri\n";
    Dezinfectant::afisareDezinfectant(out);
}

DezinfectantVirusuri& DezinfectantVirusuri::operator=(const DezinfectantVirusuri& other)
{
    Dezinfectant::operator=(other);
    return *this;
}


std::ostream& operator<<(std::ostream& out, const DezinfectantVirusuri& dezinfectant)
{
    dezinfectant.afisareDezinfectant(out);
    return out;
}


// Dezinfectant universal

long DezinfectantUniversal::eficienta()
{
    return (DezinfectantBacterii::nrSpeciiUcise +
        DezinfectantFungi::nrSpeciiUcise +
        DezinfectantVirusuri::nrSpeciiUcise) 
        / (TOTAL_BACTERII + TOTAL_FUNGI + TOTAL_VIRUSURI);
}

void DezinfectantUniversal::afisareDezinfectant(ostream& out) const
{
    out << "\n\nDEZINFECTANT UNIVERSAL:\n";
    DezinfectantBacterii::afisareDezinfectant(out);
    DezinfectantFungi::afisareDezinfectant(out);
    DezinfectantVirusuri::afisareDezinfectant(out);
}

DezinfectantUniversal& DezinfectantUniversal::operator=(const DezinfectantUniversal& other)
{
    DezinfectantBacterii::operator=(other);
    DezinfectantFungi::operator=(other);
    DezinfectantVirusuri::operator=(other);
    return *this;
}

std::ostream& operator<<(std::ostream& out, const DezinfectantUniversal& dezinfectant)
{
    dezinfectant.afisareDezinfectant(out);
    return out;
}


// -----------------------------
// ACHIZITIE

class Achizitie
{
    string data;
    string nume;
    int total_comanda;
    std::vector<Masca*> masti;
    std::vector<Dezinfectant*> dezinfectanti;


public:
    Achizitie() : data(""), nume(""), total_comanda(0), masti(std::vector<Masca*>()), dezinfectanti(std::vector<Dezinfectant*>()) {}
    Achizitie(string data, string nume) : data(data), nume(nume), total_comanda(0), masti(std::vector<Masca*>()), dezinfectanti(std::vector<Dezinfectant*>()) {}
    Achizitie(const Achizitie& other);
    ~Achizitie();

    Achizitie& operator+=(MascaChirurgicala masca);
    Achizitie& operator+=(MascaPolicarbonat masca);
    Achizitie& operator+=(Dezinfectant* dez);

    Achizitie& operator<(Achizitie* achizitie);
    Achizitie& operator==(Achizitie* achizitie); //nu am mai avut timp pt astea
    Achizitie& operator>(Achizitie* achizitie);

    Achizitie& operator=(const Achizitie& other);
    friend std::ostream& operator<<(std::ostream& out, const Achizitie& achizitie);
};

Achizitie::Achizitie(const Achizitie& other) : data(other.data), nume(other.nume), total_comanda(other.total_comanda)
{
    for (auto it : other.masti)
        masti.push_back(it);

    for (auto it : other.dezinfectanti)
        dezinfectanti.push_back(it);
}

Achizitie::~Achizitie()
{
    for (int i = 0; i < masti.size(); ++i)
        delete masti[i];

    for (int i = 0; i < dezinfectanti.size(); ++i)
        delete dezinfectanti[i];

    data = "";
    nume = "";
    total_comanda = 0;
}

Achizitie& Achizitie::operator+=(MascaChirurgicala masca)
{
    int pret = 0;
    if (masca.getTipProtectie() == "ffp1")
        pret = 5;
    else if (masca.getTipProtectie() == "ffp2")
        pret = 10;
    else if (masca.getTipProtectie() == "ffp3")
        pret = 15;

    if (masca.getModel() != "")
        pret += 0.5 * pret;

    total_comanda += pret;
    masti.push_back(new MascaChirurgicala(masca));
    return *this;
}

Achizitie& Achizitie::operator+=(MascaPolicarbonat masca)
{
    int pret = 20;
    total_comanda += pret;
    masti.push_back(new MascaPolicarbonat(masca));
    return *this;
}

Achizitie& Achizitie::operator+=(Dezinfectant* dez)
{
    int pret = 0;
    
    if (dez->eficienta() < 90)
        pret = 10;
    else if (dez->eficienta() < 95)
        pret = 20;
    else if (dez->eficienta() < 97.5)
        pret = 30;
    else if (dez->eficienta() < 99)
        pret = 40;
    else if (dez->eficienta() < 99.99)
        pret = 50;

    total_comanda += pret;
    dezinfectanti.push_back(dez);
    return *this;
}

Achizitie& Achizitie::operator=(const Achizitie& other)
{
    data = other.data;
    nume = other.nume;
    total_comanda = other.total_comanda;
    masti = other.masti; //avem o relatie de egalitate, daca unul se modifica se va modifica si celalalta
    dezinfectanti = other.dezinfectanti;

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Achizitie& achizitie)
{
    out << "\n\n";
    out << achizitie.nume << '\n' << "Total Comanda: " << achizitie.total_comanda << "\nData: " << achizitie.data << '\n';
    return out;
}



int main()
{
    Dezinfectant* d1 = new DezinfectantBacterii(100000000, 
        std::vector<string>({ "sulfati non - ionici", "sulfati cationici", "parfumuri", "Linalool", "Metilpropanol butilpentil" }),
        std::vector<string>({ "lemn", "sticla", "metal", "ceramica", "marmura" })
        );

    std::cout << *d1;

    MascaChirurgicala mc1("ffp2", "verde", 55);
    std::cout << mc1;

    MascaPolicarbonat* mp3 = new MascaPolicarbonat("elastic");
    std::cout << *mp3;

    Achizitie* a1 = new Achizitie("26.05.2020", "Plush Bio SRL");
    *a1 += mc1;
    std::cout << *a1;
    
    *a1 += *mp3;
    std::cout << *a1;
    return 0;
}
