//
// Created by albar on 21.09.2017.
//

#include <iostream>

using std::cout;
using std::endl;

int endgame(int clingons, bool base_destroyer) {
    system("CLS");
    cout << "----------------------------------------\n";
    cout << "-Clingons rest: " << clingons << endl;
    if (base_destroyer) {
        cout << "-By the way, you are wanted fugitive now\n for destroying friendly base.\n";
        cout << "-Your own base, for god's sake!\n";
    }
    cout << "-See ya, capt'n!\n";
    cout << "----------------------------------------\n\n\n";
    system("pause");
    return 0;
}

