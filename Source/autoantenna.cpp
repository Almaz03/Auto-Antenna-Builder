#include <iostream>
#include <string>
#include <vector>

#include "classes.h"
#include "initialization.h"
#include "import_data.h"
#include "export_data.h"

int main() {
    // Output informational messages
    std::cout << "Automatic creating antenna tool v1.4.2a built by VID:612939 on 17/04/2023" << std::endl;
    std::cout << "This tool not creating antennas for Control position" << std::endl;
    std::cout << "\n!!!This tool can be used only by HQ ATC Staff!!!\n" << std::endl;
    std::cout << "If you want add ATC position which is exclude in initial data " << std::endl
              << "add name of ATC position to Output->atc.txt file, save file and restart tool\n" << std::endl;
    std::cout << "For any questions contact aoa3@ivao.aero\n" << std::endl;

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
    fill_is_CTR(settings);
    fill_up_elevation(settings);
    std::cout << "\nImporting Data" << std::endl;
    std::ifstream airports("..\\Data\\Airports.txt");
    fill_data_from_airac_file(atc, airports);
    std::ifstream atc_file("..\\Data\\atc.txt");
    std::cout << "Importing ATC Positions" << std::endl;
    fill_atc_position_name_from_file(atc, atc_file);
    std::cout << "Exporting all Data to " << settings.get_country() << ".csv file\n" << std::endl;
    std::vector<std::string> final_data;
    export_data_to_file(atc, settings, final_data);
    std::cout << "Final data is built:\n" << std::endl;
    for (std::string &data: final_data) {
        std::cout << data << std::endl;
    }
    std::cout << "\nAll DONE!" << std::endl << "Press Enter to exit." << std::endl;
    system("pause"); // Wait for user to press Enter before exiting

    return 0;
}
