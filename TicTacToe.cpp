// The code written below represents the famous game of TicTacToe(It was the first time I coded a game). You will play against a computer that
    // has been programmed to respond to your moves randomly, making the game more random and entertaining. 
    //Every time the program is launched, it will change its moves, so play wisely.
   // Ps: The below file was created without implementing classes but only with the management of functions and their calls by the main function.//
    #include <iostream>
    #include <cstdlib>
    #include <ctime>
    using namespace std;
    const int n=3;
    char** drawBoard(int n){
        cout<<" Creation of the game board"<<endl;
        cout<<" *****************************"<<endl;
        char** board=new char*[3];
        for(int i=0; i< n;i++){
            board[i]=new char[3];
            for(int j=0; j< n;j++){
                board[i][j]={'-'};
                if(j==n-1){
                    cout<< "      "<<board[i][j]<<endl;
                }
                else{
                    cout<< "      "<<board[i][j];
                }
            }
        }
        cout<<" *****************************"<<endl;
        return board;
    }
    void playerMove(char** board,char player){
        bool check=true;
        do{
            int a,b;
            cout<<" Please indicate where to play with two integers (the first indicating the row, the second the column): "<<endl;
            cout<<"1)";cin>>a;
            cout<<"2)";cin>>b;
            if(cin.fail()){cerr<<"You have entered an incorrect value, please try again"<<endl;a=3;}
            if((a<=2&&a>=0)&&(b<=2&&b>=0)){
                if(board[a][b]=='-'){
                    board[a][b]=player;
                    check=false;
                }
                else{
                    cout<<" The box you have selected has already been filled or does not fall within the game board. Please enter valid values."<<endl;
                }
            }
            else{
                    cout<<" The box you have selected has already been filled or does not fall within the game board. Please enter valid values."<<endl;
                }
        }while(check);
    }
    void computerMove(char** board,char computer){
        int a,b;
        bool inizializzato=true;
        do{
            a=rand()%3;
            b=rand()%3;
            if(board[a][b]=='-'){
            board[a][b]=computer;
            inizializzato=false;
            }
        }while(inizializzato);
    }
    void checkWinner(char** board,char player,char computer,bool &check){
        int computerwon1=0;
        int computerwon2=0;
        int computerwon3=0;
        int playerwon1=0;
        int playerwon2=0;
        int playerwon3=0;
        int playerwon4=0;
        int computerwon4=0;
        for(int i=0,j=0,k=0,q=0,p=0,t=0,o=n-1,y=0;i<n;j++,k++,p++,t++,o--,y++){       
            if(board[i][j]==player){        //rows
                playerwon1++;
                computerwon1++;
            }
            else{
               playerwon1=0;
                computerwon1=0;
            }
            if(board[k][q]==player){          //columns
                playerwon2++;
                computerwon2++;
            }
            else{
                playerwon2=0;
                computerwon2=0;
            }
            if(board[p][t]==player){    //main diagonal
                playerwon3++;
                computerwon3++;
            }
            else{
                playerwon3=0;
                computerwon3=0;
            }
            if(board[y][o]==player){    //second diagonal
                playerwon4++;
                computerwon4++;
            }
            else{
                playerwon4=0;
                computerwon4=0;
            }
            if(j==n-1){
            p=-1;
            t=-1;
            o=n;
            y=-1;
            k=-1;
            q++;
            j=-1;
            i++;
            }
            if(playerwon1==3 || playerwon2==3 || playerwon3==3|| playerwon4==3){
               cout<< "Congratulations,you won."<<endl; check=true;break;
            }
            if(computerwon1==3 || computerwon2==3|| computerwon3==3|| computerwon4==3){
               cout<< "I'm sorry you didn't win, try again you will be luckier."<<endl; check=true;break;
            }           
        }
    }
    void viewBoard(char** board,int tachometer){
        cout<<" *****************************"<<endl;
        for(int i=0; i< n;i++){
            for(int j=0; j< n;j++){
                if(j==n-1){
                    cout<< "      "<<board[i][j]<<endl;
                }
                else{
                    cout<< "      "<<board[i][j];
                }
            }
        }
        cout<< "                           c.g:"<<tachometer<<endl;
        cout<<" *****************************"<<endl;
    }
    void checkTie(char** board,bool GameOver){
        if(GameOver!=true){
            bool check=false;
            for(int i=0; i<n;i++){
                for(int j=0; j<n;j++){
                    if(board[i][j]!='-'){
                        check=true;
                    }
                    else{
                        check=false;
                    }
                }
            }
            if(check==true){
                cout<<"The game ended in a tie; no one has won"<<endl;
            }
        }
    }
    int main(){
        srand(time(nullptr));
        char** board=drawBoard(n);
        int start=rand()%2;
        char player;
        char computer;
        bool GameOver=false;
        int tachometer=0;
        cout<<" You start; choose between 'o' and 'x'."<<endl;
        cin>>player;
        if(cin.fail()){cout<<"You have entered an incorrect symbol, please try again"<<endl;player='x';}
        if(player!='x' && player!='o'){cerr<<"You did not choose between the two symbols, your symbol was randomly selected by the computer and it will be the letter x."<<endl;player='x';}  
        if(player=='o'){
            computer='x';
        }
        else{
            computer='o';
        }
        while(GameOver==false){
            switch (start)
            {
            case 1:
                playerMove(board,player);
                viewBoard(board,tachometer);
                if(tachometer>=2){
                    checkWinner(board,player,computer,GameOver);
                }
                else{
                    if(tachometer==5){
                    checkTie(board,GameOver);
                    }
                }
                computerMove(board,computer);
                viewBoard(board,tachometer);   
                tachometer++;         
                break;
            case 2:
                computerMove(board,computer);
                viewBoard(board,tachometer);
                playerMove(board,player);
                viewBoard(board,tachometer);
                if(tachometer>=2){
                    checkWinner(board,player,computer,GameOver);
                }
                else{
                    if(tachometer==5){
                    checkTie(board,GameOver);
                    }
                    tachometer++;
                }
                break;
            
            }
            
        }
        return 0;
    }
    

    
