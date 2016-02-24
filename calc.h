
class Data
{
    private:
        int value;
    public:
        Data();
        Data(int v);
        Data operator+(const Data & d) const;
        Data operator-(const Data & d) const;
        Data operator*(const Data & d) const;
        Data operator/(const Data & d) const;
        void display();
        
};
