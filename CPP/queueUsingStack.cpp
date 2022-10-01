/*-----------------CODED BY ROCKHOPPER130-----------------*/
#include <bits/stdc++.h>
#include <numeric>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define REP(i, j, k) FOR(i, j, k, 1)
typedef std::vector<int> VI;
typedef std::vector<std::string> VS;
typedef std::vector<VI> VVI;

using namespace std;

///*------------------------FUNCTIONS-----------------------*///


void move(std::vector<int>* v, std::vector<int>* w){

    int l;

    while(l!=0){
        l = (*v).size();
        (*w).push_back(((*v)[l-1]));
        (*v).pop_back();
        l--;
    }

}

void move_back(std::vector<int>* v, std::vector<int>* w){

    int l;

    while(l!=0){
        l = (*w).size();
        (*v).push_back(((*w)[l-1]));
        (*w).pop_back();
        l--;
    }

}

void push(std::vector<int>* v){
   
    cout << "Enter the number you want to insert: ";
    int x;
    cin >>x;
    cout << "\n";
   
    (*v).push_back(x);
   
    int l = (*v).size();
    cout << "Vector is : \n";
    REP(i,0,l){
        cout << (*v)[i] << " ";
    }
   
    cout << "\n\n";
   
}

void pop(std::vector<int>* v, std::vector<int>* w){
   
    move(v,w);
    (*w).pop_back();
    int l = (*w).size();
    if(l==0){
        cout << "queue is now empty!";
    }
    else{
        move_back(v,w);
        cout<<"\n";
        REP(i,0,l){
            cout << (*v)[i] << " ";
        }
    }

    cout<<"\n\n";

}

///*--------------------CODE BEGINS HERE--------------------*///

int32_t main() {
ios::sync_with_stdio(0);
cin.tie(0);


    VI stack;
    VI temp;
    int flag = 0;
    cout<<"\n";

    do{

    printf("1) Insert number\n");
    printf("2) Remove number\n");
    printf("3) Exit \n");
    printf("\nChoice: ");


    int x;
            cin >> x;
            cout << "\n";
        
            switch(x){
            
                    case 1 : push(&stack);
                            break;
                        
                    case 2 : pop(&stack,&temp) ;
                            break;
                        
                    case 3 : flag = 1;
                            break;
                        
                    default : return 1;
            }

    }while(flag == 0);


return 0;
}
