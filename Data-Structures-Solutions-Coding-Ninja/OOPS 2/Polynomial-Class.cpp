// Polynomial Class
class Polynomial {
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    // Complete the class
    
    Polynomial(){
        degCoeff=new int[5];
        capacity=5;
        for(int i=0;i<5;i++){
            this->degCoeff[i]=0;
        }
    }
    Polynomial(Polynomial const &p2){
        // delete [] degCoeff;
        this->degCoeff=new int[p2.capacity];
        this->capacity=p2.capacity;
        for(int i=0;i<p2.capacity;i++){
            this->degCoeff[i]=p2.degCoeff[i];
        }
    }
    Polynomial operator=(Polynomial const &p2){
        // delete [] degCoeff;
        this->degCoeff=new int[p2.capacity];
        this->capacity=p2.capacity;
        for(int i=0;i<p2.capacity;i++){
            this->degCoeff[i]=p2.degCoeff[i];
        }
    }
    void doubly(){
        int *newDegCoeff=new int[capacity*2];
        for(int i=0;i<capacity;i++){
            newDegCoeff[i]=this->degCoeff[i];
        }
        for(int i=capacity;i<capacity*2;i++){
            newDegCoeff[i]=0;
        }
        delete [] degCoeff;
        degCoeff=newDegCoeff;
        this->capacity=(this->capacity)*2;
    }
    void setCoefficient(int deg,int coeff){
        while(deg>=capacity){
            doubly();
        }
        this->degCoeff[deg]=coeff;
    }
    Polynomial operator+(Polynomial const &p2){
        Polynomial resultArray;
        bool isFirstMax;
        int minCap;
        int maxCap;
        if(this->capacity>p2.capacity){
            maxCap=this->capacity;
            minCap=p2.capacity;
            isFirstMax=true;
        }
        else{
            maxCap=p2.capacity;
            minCap=this->capacity;
            isFirstMax=false;
        }
        while(resultArray.capacity<maxCap){
            resultArray.doubly();
        }
        for(int i=0;i<minCap;i++){
            resultArray.degCoeff[i]=this->degCoeff[i]+p2.degCoeff[i];
        }
        for(int i=minCap;i<maxCap;i++){
            if(isFirstMax){
                resultArray.degCoeff[i]=this->degCoeff[i];
            }
            else{
                resultArray.degCoeff[i]=(p2.degCoeff[i]);
            }
        }
        return resultArray;
    }
    Polynomial operator-(Polynomial const &p2){
        Polynomial resultArray;
        bool isFirstMax;
        int minCap;
        int maxCap;
        if(this->capacity>p2.capacity){
            maxCap=this->capacity;
            minCap=p2.capacity;
            isFirstMax=true;
        }
        else{
            maxCap=p2.capacity;
            minCap=this->capacity;
            isFirstMax=false;
        }
        while(resultArray.capacity<maxCap){
            resultArray.doubly();
        }
        for(int i=0;i<minCap;i++){
            resultArray.degCoeff[i]=this->degCoeff[i]-p2.degCoeff[i];
        }
        for(int i=minCap;i<maxCap;i++){
            if(isFirstMax){
                resultArray.degCoeff[i]=this->degCoeff[i];
            }
            else{
                resultArray.degCoeff[i]=(p2.degCoeff[i])*-1;
            }
        }
        return resultArray;
        
    }
    Polynomial operator*(Polynomial const &p2){
        Polynomial resultArray;
        while(resultArray.capacity<this->capacity*p2.capacity){
            resultArray.doubly();
        } 
        for(int i=0;i<this->capacity;i++){
            for(int j=0;j<p2.capacity;j++){
               
                resultArray.degCoeff[i+j]=resultArray.degCoeff[i+j]+(this->degCoeff[i]*p2.degCoeff[j]);
            }
        }
        return resultArray;
    }
    void print(){
        for(int i=0;i<this->capacity;i++){
            if(this->degCoeff[i]!=0){
                cout<<this->degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }
    
};

