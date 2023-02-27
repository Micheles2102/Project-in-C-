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
    bool checkWinner(char** board,char player,char computer,bool check){
        if(board[0][0]==player && board[0][1]==player && board[0][2]==player){cout<<"Congratulations,you won."<<endl;return check=true;}    //Se vince il giocatore(potrei metterle tra parentesi e togliermelo in un unica riga)
        if(board[1][0]==player && board[1][1]==player && board[1][2]==player){cout<<"Congratulations,you won."<<endl;return check=true;}
        if(board[2][0]==player && board[2][1]==player && board[2][2]==player){cout<<"Congratulations,you won."<<endl;return check=true;}
        if(board[0][0]==player && board[1][0]==player && board[2][0]==player){cout<<"Congratulations,you won."<<endl;return check=true;}
        if(board[0][1]==player && board[1][1]==player && board[2][1]==player){cout<<"Congratulations,you won."<<endl;return check=true;}
        if(board[0][2]==player && board[1][2]==player && board[2][2]==player){cout<<"Congratulations,you won."<<endl;return check=true;}
        if(board[0][0]==player && board[1][1]==player && board[2][2]==player){cout<<"Congratulations,you won."<<endl;return check=true;}
        if(board[0][2]==player && board[1][1]==player && board[2][0]==player){cout<<"Congratulations,you won."<<endl;return check=true;}

        if(board[0][0]==computer && board[0][1]==computer && board[0][2]==computer){cout<<"I'm sorry you didn't win, try again you will be luckier."<<endl;return check=true;}    //Se vince il Computere(potrei metterle tra parentesi e togliermelo in un unica riga)
        if(board[1][0]==computer && board[1][1]==computer && board[1][2]==computer){cout<<"I'm sorry you didn't win, try again you will be luckier."<<endl;return check=true;}
        if(board[2][0]==computer && board[2][1]==computer && board[2][2]==computer){cout<<"I'm sorry you didn't win, try again you will be luckier."<<endl;return check=true;}
        if(board[0][0]==computer && board[1][0]==computer && board[2][0]==computer){cout<<"I'm sorry you didn't win, try again you will be luckier."<<endl;return check=true;}
        if(board[0][1]==computer && board[1][1]==computer && board[2][1]==computer){cout<<"I'm sorry you didn't win, try again you will be luckier."<<endl;return check=true;}
        if(board[0][2]==computer && board[1][2]==computer && board[2][2]==computer){cout<<"I'm sorry you didn't win, try again you will be luckier."<<endl;return check=true;}
        if(board[0][0]==computer && board[1][1]==computer && board[2][2]==computer){cout<<"I'm sorry you didn't win, try again you will be luckier."<<endl;return check=true;}
        if(board[0][2]==computer && board[1][1]==computer && board[2][0]==computer){cout<<"I'm sorry you didn't win, try again you will be luckier."<<endl;return check=true;}
        
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
        do{
                cout<<" You start; choose between 'o' and 'x'."<<endl;
                cin>>player;
                }while(player!='o' && player!='x');
        if(player=='o'){
            computer='x';
        }
        else{
            computer='o';
        }
        do {
            switch (start)
            {
            case 1:
                playerMove(board,player);
                viewBoard(board,tachometer);
                computerMove(board,computer);
                viewBoard(board,tachometer);
                if(tachometer>=2){
                    GameOver=checkWinner(board,player,computer,GameOver);
                    
                }
                else{
                    if(tachometer==5){
                    checkTie(board,GameOver);
                    }
                    tachometer++;
                }
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
            
        }while(GameOver!=true);
        

        return 0;
    }

    
