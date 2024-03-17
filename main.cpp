#include "login/231511096.h"
#include "security/231511069.h"
#include "input_output/231511084.h"
using namespace std;

int main()
{
    int c;
    string user,tes;
     // Variable untuk menandai apakah pengguna telah login atau belum
    
    // Tampilkan pesan selamat datang hanya jika pengguna belum login
    
    do
    {
        bool loggedIn = false;
        if (!loggedIn) 
        {
            cout << "\t============================================================\n";
            cout << "\t|                   SELAMAT DATANG DI                      |\n";
            cout << "\t|                APLIKASI SAVE DATA SISWA                  |\n";
            cout << "\t============================================================\n";
        }

        cout << "\t___________________________ MENU ___________________________\n";
        cout << "\t Pilihan:" << endl;
        cout << "\t 1. Login" << endl;
        cout << "\t 2. Registrasi" << endl;
        cout << "\t 3. Lupa Password" << endl;
        cout << "\t 4. Keluar" << endl;
        cout << "\t Pilih opsi: ";
        cin >> c;
        cout << endl;

        switch (c) 
        {
            case 1:
                user = login();
                if (user != " ")
                {
                    pilihan(user);                  
                }
                else
                {
                    return main();
                    break;
                }               
                break;

            case 2:
                registrasi();
                break;
            case 3:
                lupaPassword();
                break;
            default:
                system("cls");
                cout << "\t\n\n----------Terimakasih----------\n" << endl;
        }
    } while (c != 4);
}
