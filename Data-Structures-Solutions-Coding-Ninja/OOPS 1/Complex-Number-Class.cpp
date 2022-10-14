// Complex Number Class
class ComplexNumbers {
    // Complete this class
    int real;
    int imag;
    public:
    ComplexNumbers(int real,int imaginary){
        this->real=real;
        this->imag=imaginary;
    }
    void plus(ComplexNumbers const &c2){
        this->real=this->real+c2.real;
        this->imag=this->imag+c2.imag;
    }
    void multiply(ComplexNumbers const &c2){
        int newReal=real*c2.real-imag*c2.imag;
        int newImag=real*c2.imag+c2.real*imag;
        real=newReal;
        imag=newImag;
    }
    void print(){
        cout<<real<<" + i"<<imag<<endl;
    }
    
};