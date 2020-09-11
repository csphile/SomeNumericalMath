

template <typename T> class Suite {
    public:
        Suite(T const & etat) : etat_init(etat), etat(etat), n_iter(0) {}; 
        Suite<T>& operator++() {
            change_etat (); 
            ++n_iter; 
            return *this;
        };
        virtual void change_etat () = 0;
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
    protected:
        T const etat_init; 
        T etat;
        unsigned n_iter;
};