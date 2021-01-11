#ifndef Tree_h
#define Tree_h


template <typename T>
class Tree {
    public:        
        virtual void traversal() const = 0;
        virtual void insert (const T &data) = 0;
        virtual void remove (const T &data) = 0;
        virtual const T& getMaxValue () const = 0;
        virtual const T& getMinValue () const = 0;

        virtual bool find(const T &data) const=0;

};

#endif