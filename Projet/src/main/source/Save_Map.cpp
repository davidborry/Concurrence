//
// Created by Thomas Gillot on 03/10/2016.
//

# include <iostream>
# include "../include/Save_Map.h"
# include <vector>
# include <fstream>
# include "../include/Entity.h"


using namespace std;


void create_backup_file(int x, int y) {
    ofstream file("backupCord.txt", ios::out | ios::app);;

    if (file) {
        file <<  x << "," << y << "\n" << endl;
        file.close();

    } else
        cerr << "File opening error" << endl;
}


void read_backup_file() {
    ifstream my_file("backupCord.txt", ios::in);

    if(my_file){
        string file_line;
        while(getline(my_file,file_line)){
            cout << file_line<<endl;
        }
        my_file.close();
    }else
        cerr << "File opening error" << endl;


}