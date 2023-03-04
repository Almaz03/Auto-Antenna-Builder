#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Data {
    string icao;
    string airport_name;
    double coordinates[2];
    int elevation;
    string *atc;
};

int check_airportsdata() {
    return 0;
}

string enters(string line) {
    //Checking double enters from lines

    for (int i = 0; i < line.size(); i++) {
        if (i == 0 and line[i] == ' ') {
            line = line.erase(i, 1);
        }
        if (i == line.size() - 1 and line[i] == ' ') {
            line = line.erase(i, 1);
        }
        if (line[i] == ' ' and line[i + 1] == ' ') {
            line = line.erase(i, 1);
        }
    }
    return line;
}

string lowercase(string line) {
    //Checking lowercase input lines from terminal

    for (int i = 0; i < line.size(); i++) {
        if (islower(line[i])) line[i] = toupper(line[i]);
    }
    return line;
}

string firsttouppercase(string line) {
    line[0] = toupper(line[0]);
    for (int i = 1; i < line.size(); i++) {
        line[i] = tolower(line[i]);
    }
    return line;
}

int create_coordinates_for_center(bool flag) {

    if (flag) {
        int size = 1;
        ifstream fs("..\\Data\\Airports.txt");
        while (true) {
            string v;
            getline(fs, v);
            if (!fs.eof())
                size++;
            else
                break;
        }

        fstream airports;
        airports.open("..\\Data\\Airports.txt");

        string *initial_airport_data, *airport_data;
        int size_of_true_lines = 0;
        initial_airport_data = new string[size];
        string tmp_icao_1;
        cin.ignore();
        for (int i = 0; i < size; i++) {
            getline(airports, initial_airport_data[i]);
        }
        airports.close();
        for (int i = 0; i < size; i++) {
            if (initial_airport_data[i][0] == 'A') {
                size_of_true_lines++;
            }
        }
        airport_data = new string[size_of_true_lines];
        for (int i = 0, j = 0; j < size; j++) {
            if (initial_airport_data[j][0] == 'A') {
                airport_data[i] = initial_airport_data[j];
                i++;
            }
        }


        ofstream output("..\\Data\\airportsdata.txt");
        for (int i = 0; i < size_of_true_lines; i++) {
            output << airport_data[i] << endl;
        }
    } else flag = false;
    return 0;
}

int main() {


    //Inputing all values from terminal
    cout << "Automatic creating antenna tool v1.2 built by VID:612939 on 03/03/2023" << endl;
    cout << "This tool not creating antennas for Control position" << endl;
    cout << "\n!!!This tool can be used only by HQ ATC Staff!!!\n" << endl;


    cout << "If you want add ATC position which is exclude in initial data " << endl <<
         "add name of ATC position to Output->atc.txt file, save file and restart tool\n" << endl;

    cout << "Did you updated AIRAC cycle? Press 1 - is YES, 0 - is NO (If this is your first start of tool - press 1):"
         << endl;
    bool airac;
    cin >> airac;


    if (airac) {
        create_coordinates_for_center(airac);
    } else cin.ignore();;


    string country;

    cout << "Enter country code (ex: KG): " << endl;
    getline(cin, country);
    country = enters(country);
    country = lowercase(country);

    string fir;
    cout << "Enter FIR code (ex: UCFM): " << endl;
    getline(cin, fir);
    fir = enters(fir);
    fir = lowercase(fir);

    cout << "Enter ICAO codes of airports separated by space (ex: UUDD UUWW UUEE):" << endl;
    string icaos;
    getline(cin, icaos);
    icaos = enters(icaos);
    icaos = lowercase(icaos);
    cout << "Do you want set to all ATC position same power? Press 1 - is YES, 0 - is NO" << endl;

    int power_d, power_g, power_t, power_a, power_at, power;
    bool power_check, power_standard_value;
    cin >> power_check;


    if (!power_check) {
        cout
                << "Do you want to use standard values for power (DEL - 5, GND - 5, TWR - 10, APP - 20, ATIS - 20)? " <<
                endl << "Press 1 - is YES, 0 - is NO"
                << endl;
        cin >> power_standard_value;

    }

    if (!power_check and !power_standard_value) {
        cout << "Enter power of delivery position: " << endl;
        cin >> power_d;
        cout << "Enter power of ground position: " << endl;
        cin >> power_g;
        cout << "Enter power of tower position: " << endl;
        cin >> power_t;
        cout << "Enter power of approach position: " << endl;
        cin >> power_a;
        cout << "Enter power of ATIS: " << endl;
        cin >> power_at;
        if (power_d < 1 or power_g < 1 or power_t < 1 or power_a < 1 or power_at < 1 or power_d > 50 or power_g > 50 or
            power_t > 50 or power_a > 50 or power_at > 50) {
            cout << "Power can not be less then 0 or greater then 50, restart program" << endl;
            cout << "Press any key to exit" << endl;
            system("pause");
            exit(0);
        }
    }
    if (power_standard_value) {
        power_d = 5;
        power_g = 5;
        power_t = 10;
        power_a = 20;
        power_at = 20;

    }
    if (power_check) {
        cout << "Enter power: " << endl;
        cin >> power;
        power_d = power, power_g = power, power_t = power;
        power_a = power, power_at = power;
        if (power < 1 or power > 50) {
            cout << "Power can not be less then 0 or greater then 50, restart program" << endl;
            cout << "Press any key to exit" << endl;
            system("pause");
            exit(0);
        }
    }

    cout << "Do you want set to all ATC position same PPM? Press 1 - is YES, 0 - is NO" << endl;
    int ppm_d, ppm_g, ppm_t, ppm_a, ppm_at, ppm;
    bool ppm_check, ppm_standard_value;
    cin >> ppm_check;


    if (!ppm_check) {
        cout << "Do you want to set a standard value of PPM (PPM - 2)? Press 1 - is YES, 0 - is NO" << endl;
        cin >> ppm_standard_value;
    }

    if (!ppm_check and !ppm_standard_value) {
        cout << "Enter PPM of delivery position: " << endl;
        cin >> ppm_d;
        cout << "Enter PPM of ground position: " << endl;
        cin >> ppm_g;
        cout << "Enter PPM of tower position: " << endl;
        cin >> ppm_t;
        cout << "Enter PPM of approach position: " << endl;
        cin >> ppm_a;
        cout << "Enter PPM of ATIS position: " << endl;
        cin >> ppm_at;
        if (ppm_d < 1 or ppm_g < 1 or ppm_t < 1 or ppm_a < 1 or ppm_at < 1 or ppm_d > 5 or ppm_g > 5 or ppm_t > 5 or
            ppm_a > 5 or ppm_at > 5) {
            cout << "PPM can not be less then 0 or greater then 5, restart program" << endl;
            cout << "Press any key to exit" << endl;
            system("pause");
            exit(0);
        }

    }
    if (!ppm_standard_value) {
        ppm = 2;
        ppm_d = ppm, ppm_g = ppm, ppm_t = ppm;
        ppm_a = ppm, ppm_at = ppm;
    }
    if (ppm_check) {
        cout << "Enter PPM: " << endl;
        cin >> ppm;
        ppm_d = ppm, ppm_g = ppm, ppm_t = ppm;
        ppm_a = ppm, ppm_at = ppm;
        if (ppm < 1 or ppm > 5) {
            cout << "PPM can not be less then 1 or greater then 5, restart program" << endl;
            cout << "Press any key to exit" << endl;
            system("pause");
            exit(0);
        }
    }

    int up_elevation;

    cout << "Enter how much feet you would like to add to elevation: " << endl;
    cin >> up_elevation;

    if (up_elevation < 0 or up_elevation > 500) {

        cout << "Press any key to exit" << endl;
        system("pause");
        exit(0);

    }

    bool is_control;
    cout << "Do you want add " + fir + "_CTR position to all antenna? Press 1 - is YES, 0 - is NO" << endl;
    cin >> is_control;

    //counting how many airports will be
    int number_of_airports = 1;
    for (char i: icaos) {
        if (i == ' ') number_of_airports++;

    }

    Data *data;
    data = new Data[number_of_airports];

    //Inputing to srtuct ICAO codes
    string tmp_icao_0;
    for (int i = 0, j = 0; i < icaos.size(); i++) {

        if (icaos[i] != ' ')
            tmp_icao_0 += icaos[i];
        if (icaos[i] == ' ' or i == icaos.size() - 1) {
            data[j].icao = tmp_icao_0;
            tmp_icao_0 = {};
            j++;
        }
    }

    int size = 1, atc_size = 1;
    ifstream fs("..\\Data\\airportsdata.txt");
    while (true) {
        string v;
        getline(fs, v);
        if (!fs.eof())
            size++;
        else
            break;
    }
    ifstream fa("..\\Data\\atc.txt");
    while (true) {
        string d;
        getline(fa, d);
        if (!fa.eof())
            atc_size++;
        else
            break;
    }


    fstream airports, atcs;
    airports.open("..\\Data\\airportsdata.txt");
    atcs.open("..\\Data\\atc.txt");

    string *initial_airport_data, *initial_atc_data;
    initial_airport_data = new string[size];
    initial_atc_data = new string[atc_size];
    string tmp_icao_1;
    cin.ignore();
    for (int i = 0; i < size; i++) {
        getline(airports, initial_airport_data[i]);
    }
    for (int i = 0; i < atc_size; i++) {
        getline(atcs, initial_atc_data[i]);
    }
    airports.close();
    atcs.close();

    string *airport_data;
    airport_data = new string[number_of_airports];
    cout << "Initializating" << endl;
    //inserting airport data
    for (int i = 0; i < number_of_airports; i++) {
        bool flag;
        for (int j = 0; j < size; j++) {
            int count = 0;

            for (int k = 0; k < initial_airport_data[j].size(); k++) {
                if (initial_airport_data[j][k] == ',') count++;
                if (count == 1 and initial_airport_data[j][k] != ',') {
                    tmp_icao_1 += initial_airport_data[j][k];
                }
                if (count == 2) {
                    for (int z = 0; z < 4; z++) {
                        if (z == 0) flag = true;
                        if (data[i].icao[z] == tmp_icao_1[z] and flag) {
                            flag = true;
                        } else flag = false;
                    }
                    if (flag) airport_data[i] = initial_airport_data[j];
                    tmp_icao_1 = {};

                }

            }
        }
    }

    cout << "Creating data from AIRAC cycle with " + to_string(size) + " lines" << endl;
    //inputing to struct ICAO code, airport name, coordinates and elevation.
    for (int i = 0; i < number_of_airports; i++) {
        int count = 0;
        string tmp_icao = {}, tmp_name = {}, tmp_lat = {}, tmp_long = {}, tmp_elevation = {};
        for (int j = 0; j < airport_data[i].size(); j++) {
            if (airport_data[i][j] == ',') count++;
            if (count == 1 and airport_data[i][j] != ',') {
                tmp_icao += airport_data[i][j];
            }
            if (count == 2 and airport_data[i][j] != ',') {
                tmp_name += airport_data[i][j];
                data[i].icao = tmp_icao;
            }
            if (count == 3 and airport_data[i][j] != ',') {
                tmp_lat += airport_data[i][j];
                data[i].airport_name = tmp_name;
            }
            if (count == 4 and airport_data[i][j] != ',') {
                tmp_long += airport_data[i][j];
                data[i].coordinates[0] = stod(tmp_lat);

            }
            if (count == 5 and airport_data[i][j] != ',') {
                tmp_elevation += airport_data[i][j];
                data[i].coordinates[1] = stod(tmp_long);

            }
            if (count == 6 and airport_data[i][j] != ',') {
                data[i].elevation = stoi(tmp_elevation);
            }
        }
    }

    for (int i = 0; i < number_of_airports; i++) {
        data[i].airport_name = firsttouppercase(data[i].airport_name);
    }

    cout << "Adding to data ATC positions with " + to_string(atc_size) + " lines" << endl;

    int *atc_per_icao, **atc_per_icao_i, founded_atc_size;
    atc_per_icao = new int[number_of_airports];
    atc_per_icao_i = new int *[number_of_airports];

    //inputing to struct ATC positions
    for (int i = 0; i < number_of_airports; i++) {
        founded_atc_size = 0;
        bool flag;
        for (int j = 0; j < atc_size; j++) {
            for (int k = 0; k < 4; k++) {
                if (k == 0) flag = true;
                if (data[i].icao[k] == initial_atc_data[j][k] and flag) {
                    flag = true;
                } else flag = false;
            }
            if (flag) {
                founded_atc_size++;
            }
        }

        atc_per_icao[i] = founded_atc_size;
        atc_per_icao_i[i] = new int[atc_per_icao[i]];
        data[i].atc = new string[atc_per_icao[i]];

        int z = 0;
        for (int j = 0; j < atc_size; j++) {
            for (int k = 0; k < 4; k++) {
                if (k == 0) flag = true;
                if (data[i].icao[k] == initial_atc_data[j][k] and flag) {
                    flag = true;
                } else flag = false;
            }
            if (flag and z <= atc_per_icao[i]) {
                data[i].atc[z] = initial_atc_data[j];
                z++;
            }
        }
    }

    int amount_of_atc = 2;
    for (int i = 0; i < number_of_airports; i++) {
        amount_of_atc += atc_per_icao[i];
    }

    cout << "Adding final information to data" << endl;

    string *final_data;
    final_data = new string[amount_of_atc];
    int number_of_final_data = 1;
    final_data[0] = "identifier,name,latitude,longitude,elevation,power,ppm,atc_positions,subcenters";

    if (is_control) {
        for (int i = 0; i < number_of_airports; i++) {
            string tmp_atc = {};
            for (int j = 0; j < atc_per_icao[i]; j++) {
                tmp_atc = data[i].atc[j];
                if (tmp_atc[tmp_atc.size() - 1] == 'L') {
                    final_data[number_of_final_data] =
                            country + "-" + data[i].airport_name + "-AD-" + to_string(power_d) + "W," +
                            country + "-" + data[i].icao + "-Delivery-Antenna," +
                            to_string(data[i].coordinates[0]) +
                            "," + to_string(data[i].coordinates[1]) + "," +
                            to_string(up_elevation + data[i].elevation) +
                            +"," + to_string(power_d) + "," + to_string(ppm_d) + "," + data[i].atc[j] + "," + fir +
                            "_CTR";
                    number_of_final_data++;
                }
                if (tmp_atc[tmp_atc.size() - 1] == 'D') {
                    final_data[number_of_final_data] =
                            country + "-" + data[i].airport_name + "-AD-" + to_string(power_g) + "W," +
                            country + "-" + data[i].icao + "-Ground-Antenna," +
                            to_string(data[i].coordinates[0]) +
                            "," + to_string(data[i].coordinates[1]) + "," +
                            to_string(up_elevation + data[i].elevation) +
                            +"," + to_string(power_g) + "," + to_string(ppm_g) + "," + data[i].atc[j] + "," + fir +
                            "_CTR";
                    number_of_final_data++;
                }
                if (tmp_atc[tmp_atc.size() - 1] == 'R') {
                    final_data[number_of_final_data] =
                            country + "-" + data[i].airport_name + "-AD-" + to_string(power_t) + "W," +
                            country + "-" + data[i].icao + "-Tower-Antenna," +
                            to_string(data[i].coordinates[0]) +
                            "," + to_string(data[i].coordinates[1]) + "," +
                            to_string(up_elevation + data[i].elevation) +
                            +"," + to_string(power_t) + "," + to_string(ppm_t) + "," + data[i].atc[j] + "," + fir +
                            "_CTR";
                    number_of_final_data++;
                }
                if (tmp_atc[tmp_atc.size() - 1] == 'P') {
                    final_data[number_of_final_data] =
                            country + "-" + data[i].airport_name + "-TMA-" + to_string(power_a) + "W," +
                            country + "-" + data[i].icao + "-Approach-Antenna," +
                            to_string(data[i].coordinates[0]) +
                            "," + to_string(data[i].coordinates[1]) + "," +
                            to_string(up_elevation + data[i].elevation) +
                            +"," + to_string(power_a) + "," + to_string(ppm_a) + "," + data[i].atc[j] + "," + fir +
                            "_CTR";
                    number_of_final_data++;
                }
                if (tmp_atc[tmp_atc.size() - 1] == 'S') {
                    final_data[number_of_final_data] =
                            country + "-" + data[i].airport_name + "-AD-" + to_string(power_at) + "W," +
                            country + "-" + data[i].icao + "-ATIS-Antenna," +
                            to_string(data[i].coordinates[0]) +
                            "," + to_string(data[i].coordinates[1]) + "," +
                            to_string(up_elevation + data[i].elevation) +
                            +"," + to_string(power_at) + "," + to_string(ppm_at) + "," + data[i].atc[j] + "," + fir +
                            "_CTR";
                    number_of_final_data++;
                }
                tmp_atc = {};
            }
        }
    } else {
        for (int i = 0; i < number_of_airports; i++) {
            string tmp_atc = {};
            for (int j = 0; j < atc_per_icao[i]; j++) {
                tmp_atc = data[i].atc[j];
                if (tmp_atc[tmp_atc.size() - 1] == 'L') {
                    final_data[number_of_final_data] =
                            country + "-" + data[i].airport_name + "-AD-" + to_string(power_d) + "W," +
                            country + "-" + data[i].icao + "-Delivery-Antenna," +
                            to_string(data[i].coordinates[0]) +
                            "," + to_string(data[i].coordinates[1]) + "," +
                            to_string(up_elevation + data[i].elevation) +
                            +"," + to_string(power_d) + "," + to_string(ppm_d) + "," + data[i].atc[j] + ",";
                    number_of_final_data++;
                }
                if (tmp_atc[tmp_atc.size() - 1] == 'D') {
                    final_data[number_of_final_data] =
                            country + "-" + data[i].airport_name + "-AD-" + to_string(power_g) + "W," +
                            country + "-" + data[i].icao + "-Ground-Antenna," +
                            to_string(data[i].coordinates[0]) +
                            "," + to_string(data[i].coordinates[1]) + "," +
                            to_string(up_elevation + data[i].elevation) +
                            +"," + to_string(power_g) + "," + to_string(ppm_g) + "," + data[i].atc[j] + ",";
                    number_of_final_data++;
                }
                if (tmp_atc[tmp_atc.size() - 1] == 'R') {
                    final_data[number_of_final_data] =
                            country + "-" + data[i].airport_name + "-AD-" + to_string(power_t) + "W," +
                            country + "-" + data[i].icao + "-Tower-Antenna," +
                            to_string(data[i].coordinates[0]) +
                            "," + to_string(data[i].coordinates[1]) + "," +
                            to_string(up_elevation + data[i].elevation) +
                            +"," + to_string(power_t) + "," + to_string(ppm_t) + "," + data[i].atc[j] + ",";
                    number_of_final_data++;
                }
                if (tmp_atc[tmp_atc.size() - 1] == 'P') {
                    final_data[number_of_final_data] =
                            country + "-" + data[i].airport_name + "-TMA-" + to_string(power_a) + "W," +
                            country + "-" + data[i].icao + "-Approach-Antenna," +
                            to_string(data[i].coordinates[0]) +
                            "," + to_string(data[i].coordinates[1]) + "," +
                            to_string(up_elevation + data[i].elevation) +
                            +"," + to_string(power_a) + "," + to_string(ppm_a) + "," + data[i].atc[j] + ",";
                    number_of_final_data++;
                }
                if (tmp_atc[tmp_atc.size() - 1] == 'S') {
                    final_data[number_of_final_data] =
                            country + "-" + data[i].airport_name + "-AD-" + to_string(power_at) + "W," +
                            country + "-" + data[i].icao + "-ATIS-Antenna," +
                            to_string(data[i].coordinates[0]) +
                            "," + to_string(data[i].coordinates[1]) + "," +
                            to_string(up_elevation + data[i].elevation) +
                            +"," + to_string(power_at) + "," + to_string(ppm_at) + "," + data[i].atc[j] + ",";
                    number_of_final_data++;
                }
                tmp_atc = {};
            }
        }
    }

    ofstream output("..\\Output\\" + country + ".csv");
    for (int i = 0; i < amount_of_atc; i++) {
        output << final_data[i] << endl;
    }
    output.close();

    cout << country + ".csv file is created on Output folder" << endl;
    cout << "\nData rewrited successfully with " + to_string(number_of_airports) + " airports and "
            + to_string(amount_of_atc - 2) + " ATC positions: \n" << endl;
    for (int i = 0; i < amount_of_atc; i++) {
        cout << final_data[i] << endl;
    }
    cout << "\n" << country + ".csv file is created on Output folder" << endl;

    cout << "\nPress enter to exit" << endl;
    system("pause");
    exit(0);

    delete[] airport_data;
    delete[] data;
    delete[] atc_per_icao;
    for (int i = 0; i < number_of_airports; i++) {
        delete[] atc_per_icao_i[i];
    }
    delete[] atc_per_icao_i;
    delete[] initial_atc_data;
    delete[] initial_airport_data;
    delete[] final_data;
}
