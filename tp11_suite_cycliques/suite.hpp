#ifndef SUITE
#define SUITE

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

typedef pair<double, double> pdd;

template <typename T> class Suite {
    public:
        Suite(){}
        Suite(T const & etat) : etat_init(etat), etat(etat), n_iter(0) {}; 

        Suite<T>& operator++() {
            change_etat (); 
            ++n_iter; 
            return *this;
        }

        Suite<T>& operator+=(int k) {
            while (k--){
                this -> operator++();
            }
            return *this;
        };

        virtual void change_etat() = 0;

        T get_etat() const { 
            return etat;
        }

        unsigned get_n() const {
            return n_iter; 
        }

        void reinit() { 
            etat = etat_init; 
            n_iter = 0; 
        }

        virtual void print(ostream& os)  = 0;

        friend ostream& operator<<(ostream& os, Suite<T>& s){
            s.print(os);
            return os;
        }

        int cycle() {
            list<T> hist;
            auto it = hist.begin();
            do {
                hist.push_back(this -> etat);
                this -> operator++();
                it = find(hist.begin(), hist.end(), this -> etat);
                // cout << "cycled!" << endl;
            } while (it == hist.end());
            cout << "steps of iterations before cycle: " << n_iter << endl;
            return distance(it, hist.end());
        }

    protected: 
        T const etat_init; 
        T etat;
        unsigned n_iter;
};

class Lucas: public Suite<pdd>{
    double P, Q;
    public:
        Lucas(const pdd& pd): Suite<pair<double, double>>({0.0, 1.0}){
            P = pd.first; Q = pd.second;
        }

        void change_etat() override {
            double next = etat.second * P - etat.first * Q;
            etat.first = etat.second;
            etat.second = next;
        }

        void print(ostream& os) override {
            os << etat.first << " " << etat.second;
        }
};

class Logistique: public Suite<double>{
    double mu;
    public:
        Logistique(const double& mu_, const double& x0): Suite<double>(x0), mu(mu_){}

        void change_etat() override{
            etat = mu * etat * (1 - etat);
        }

        void print(ostream& os){ os << etat;}
};


// Solitaire bulgare
class Jeu: public Suite<list<int>>{
    private:
        void change_etat() override {
            list<int> newstate;
            int sum = 0;
            for (auto v: etat){
                if (v > 0) sum ++;
                --v;
                if (v) newstate.push_back(v);
            }
            if (sum) newstate.push_back(sum);
            etat = move(newstate);
            // for (auto v: newstate) cout << v << endl;
        }

        Jeu(const list<int>& data): Suite<list<int>>(data){}

    public:
        Jeu(const int& n){
            list<int> _etat;
            for (int i = 0; i < n; i++){
                _etat.push_back(1);
            }
            etat = _etat;
            n_iter = 0;
        }

        void print(ostream& os) override {
            int cnt = 0;
            for (auto& v: etat){
                if (cnt++ < etat.size() - 1) 
                    os << v << " - ";
                else os << v;
            }
        }
};

#endif