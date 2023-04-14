#include <iostream>
#include <string>
#include <vector>

#include "classes.h"
#include "initialization.h"
#include "import_data.h"
#include "export_data.h"

int main() {
    // Output informational messages
    std::cout << "Automatic creating antenna tool v1.4.0a built by VID:612939 on 08/04/2023" << std::endl;
    std::cout << "This tool not creating antennas for Control position" << std::endl;
    std::cout << "\n!!!This tool can be used only by HQ ATC Staff!!!\n" << std::endl;

    std::cout << "If you want add ATC position which is exclude in initial data " << std::endl
              << "add name of ATC position to Output->atc.txt file, save file and restart tool\n" << std::endl;

    // Initialize settings and ATC array
    Settings settings;
    std::vector<ATC> atc;

    // Check password
    //is_correct_password();

    // Input information from the console
    fill_country(settings);
    fill_fir(settings);
    fill_ICAO(atc);
    fill_power(settings);
    fill_ppm(settings);
    fill_up_elevation(settings);

    std::ifstream airports("..\\Data\\Airports.txt");
    fill_data_from_airac_file(atc, airports);
    std::ifstream atc_file("..\\Data\\atc.txt");
    fill_atc_position_name_from_file(atc, atc_file);
    exportDataToFile(atc,settings);

    return 0;
}
