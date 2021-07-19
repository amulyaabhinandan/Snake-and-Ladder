//Snake and Ladder Game in C++
//Developed by Amulya Abhinandan

#include <iostream>

using namespace std;

int random(int l){
    srand(time_t(l));
    return (1+rand() % 6);
}
int random2(int l){
    srand(time_t(1));
    return (1+rand()%l);
    
}

int main()
{
    int i=0,pos,k,c,v,snakes,ladders;
    char p;
    int x[]={0,38,-1,-1,14,-1,-1,-1,-1,31,-1,
            -1,-1,-1,-1,-1,-1,6,-1,-1,-1,
            42,-1,-1,-1,-1,-1,-1,84,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            67,-1,-1,34,-1,-1,-1,-1,-1,-1,
            -1,19,-1,60,-1,-1,-1,-1,-1,-1,
            -1,91,-1,-1,-1,-1,-1,-1,-1,99,
            -1,-1,-1,-1,-1,-1,36,-1,-1,-1,
            -1,-1,73,-1,75,-1,-1,79,-1,100};
    
    cout<<"Enter y if you want to play "<<endl;
    cin>>p;
    v=0;
    while(p=='y'){
        i=0;
        snakes=0;
        ladders=0;
        pos=0;
        while(x[pos]!=100){
            cout<<"Enter any number from 1-6 to try your luck "<<endl;
            cout<<"Enter 9 if you want to exit game from the middle ";
            cin>>c;
            if(c==9)
                break;
            if(pos>96)
                k=random2(100-pos);
            else
                k=random(c);
            v=v+k;
            i++;
            
            if(x[v]==-1){
                cout<<"Normal Movement"<<endl;
            }
            else if(x[v]>0 && x[v]<100){
                v=x[v];
                if(v<pos){
                    cout<<"Bitten by Snakes!!!"<<endl;
                    snakes++;
                }
                else{
                    cout<<"Lucky! Got a Ladder"<<endl;
                    ladders++;
                }
                
            }
            else if(x[v]==100){
                cout<<"You won!"<<endl;
                break;
            }
            pos=v;
            cout<<"Your position is="<<pos<<endl;
            
        }
        cout<<"Your moves="<<i<<endl;
        cout<<"Total snakes="<<snakes<<endl;
        cout<<"Total Ladders="<<ladders<<endl;
        cout<<"If you want to play again enter y and anything else to exit"<<endl;
        cin>>p;
    }
    return 0;
}