#include <iostream>

using namespace std;
class DoMath {
    int ch;
    string title;

    public: 
    DoMath (){}
    DoMath(int i, string s){
        ch = i;
        title = s;
    }
    void addition(){
        int size;
        float numbers[size];
        float sumTotal = 0;

        cout << endl << "Enter how many numbers you want to add : ";
        cin >> size;
        cout << endl;
        
        int addendSerial = 1;
        for (int i = 0; i < size; i++){
            
            cout << "Give addend No." << addendSerial << " : " ;
            cin >> numbers[i];
            sumTotal += numbers[i];
            addendSerial ++;
        }
        cout << endl << "Total Additon : " << sumTotal << endl << endl ;      
    }



    void subtraction (){
            int size;
            float numbers[size] ;
            float subtractionResult = 0;
            cout << endl << "Enter how many numbers you want to subtract : ";
            cin >> size ;

            int serial = 1;

            for (int i = 0; i < size; i++){

            
                
                if(i == 0){
                    cout << "Give the Minuend : ";
                    cin >> numbers[i] ;
                    subtractionResult = numbers[0] ;
                }
                else if(i > 0){
                    cout << "Give the Subtrahend No." << serial << " : ";
                    cin >> numbers[i] ;
                    subtractionResult -= numbers[i] ;
                    serial ++ ;
                }
                
                
                
            }

            cout << endl << "Total Subtraction : " << subtractionResult << endl ;
        }

        
    char askToContinue (){
        char decision  ;
        cout << "Want to continue (Y/N)? ";
        cin >> decision ;

        do {
            if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize> :: max(), '\n');
            cout << "Invalid input! Please try again." << endl;
        }

        else if(decision == 'Y' || decision == 'y' || decision == 'N' || decision == 'n'){
            return decision;
        }
        else{
            cout << "Wrong input! Please try again." << endl;
        }

        }

        while (decision != 'Y' && decision != 'y' && decision != 'N' && decision != 'n');

        return decision;
        
    }    

    void choosing_system(){

        char option;

        do {
            cout << endl << " Choose anything you want " << endl ;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Temperature Conversion" << endl;
        cout << "6. Area measurement" << endl;
        cout << "To Exit Type E" << endl ;
        cout << endl << "Pick a number : ";
        cin >> option;
        
        char decision = 'Y' ;
        switch(option){

            case '1' :

            addition();

            break;

            case '2' :

            subtraction();

            break;

            default :
            cout << endl << "Invalid input!" << endl << endl;
            break;
        }

        option = askToContinue();
    }

    while (option == 'Y' || option == 'y' && option != 'N' && option != 'n');
}
        

    
};

int main(){
    DoMath dm;

    dm.choosing_system();

    return 0;
}
