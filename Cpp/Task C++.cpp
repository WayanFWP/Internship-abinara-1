#include <iostream>
#include <cmath>

using namespace std;

namespace Trigono{
class calculator{
    public:
        void perhitungan(){
            char pilihan;
            do{
                menu();
                int operatornya;
                int derajat, konversi;

                cout<<"\npilih operator diantara (1-6): ";
                cin>> operatornya;

                 if(operatornya >= 4 && operatornya <=6){
                    cout<<"\nberapa derajat : ";
                    cin>> derajat;
                    konversi = Untuk_Arc(derajat);
                }

                switch(operatornya){
                    case 1:
                        cout<<"\nSin berapa derajat : ";
                        cin>> derajat;
                        fungsiSin(derajat);
                        break;
                    case 2:
                        cout<<"\nCos berapa derajat : ";
                        cin>> derajat;
                        fungsiCos(derajat);
                        break;
                    case 3:
                        cout<<"\nTan berapa derajat : ";
                        cin>> derajat;
                        fungsiTan(derajat);
                        break;
                    case 4:
                        fungsiArcSin(konversi);
                        break;
                    case 5:
                        fungsiArcCos(konversi);
                        break;
                    case 6:
                        fungsiArcTan(konversi);
                        break;
                    default:
                        cout<< "invalid operator";
                    }

                    cout << "\nkalkulasi lagi? (Y/N)" << endl;
                    cin >> pilihan;
            } while(pilihan == 'y' || pilihan == 'Y');
        }

    private:
        void menu(){
            cout<< "<============== kalkulator Trigonometri =============>"<< endl;
            cout << "\t1. sin \t\t2. cos\t\t3. tan\n";
            cout << "\t4. arcsin\t5. arccos\t6. archtan\n";
        }

        void fungsiSin(int derajat){
            if (derajat == 0){
                cout<< "hasil dari sin (0) adalah 0"<< endl ;
            } else if ( derajat == 90){
                cout<< "hasil dari sin (90) adalah 1"<< endl;
            } else {
                cout<< "hasil dari sin ("<< derajat<< ") adalah "<< sin(derajat)<< endl;
            }
        }

        void fungsiCos(int derajat){
            if (derajat ==  0){
                cout<< "hasil dari cos(0) adalah 1"<< endl;
            } else if (derajat == 90){
                cout << "hasil dari cos(90) adalah 0"<< endl;
            } else {
                cout << "hasil dari cos("<< derajat<<") adalah "<< cos(derajat)<< endl;
            }
        }

        void fungsiTan(int derajat){
            if (derajat ==  0){
                cout<< "hasil dari tan(0) adalah 0"<< endl;
            } else if (derajat == 90){
                cout << "hasil dari tan(90) adalah infinite"<< endl;
            } else if(derajat == 45){
                cout<< "hasil dari tan(45) adalah 1"<< endl;
            } else {
                cout << "hasil dari tan("<< derajat << ") adalah "<< tan(derajat)<< endl;
            }
        }

        void fungsiArcSin(float angka){
            cout<< "hasil dari Arcsin("<< angka<<") adalah "<< UntukKeArc(asin(angka))<< endl;
        }
        void fungsiArcCos(float angka){
            cout << "hasil dari ArcCos("<< angka << ") adalah "<< UntukKeArc(acos(angka))<< endl;
        }
        void fungsiArcTan(float angka){
            cout << "hasil dari Arctan("<< angka<< ") adalah "<< UntukKeArc(atan(angka))<< endl;
        }

        double UntukKeArc(int radian){
            return radian * (180 / pi);
        } double Untuk_Arc(int derajat){
            return derajat * (pi / 180);
        }

        const double pi = 3.14159;

    };
}
int main(){
    Trigono::calculator Kalkulator;
    Kalkulator.perhitungan();
    return 0;
}
