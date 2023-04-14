#include <fstream>
#include <algorithm>
#include "../export_data.h"

void exportDataToFile( std::vector<ATC> &atcs, Settings &settings) {
    const std::string country = settings.get_country();
    const std::string filename = "../Output/" + country + ".csv"; // define the filename and path
    std::ofstream outfile(filename);
    if (!outfile) {
        throw std::runtime_error("Failed to open file");
    }
    // Write header
    outfile << "airport_name,latitude,longitude,power,ppm,FIR" << std::endl;

// Get settings data
    const std::string FIR = settings.get_FIR();
    const int del_power = settings.get_del_power();
    const int gnd_power = settings.get_gnd_power();
    const int twr_power = settings.get_twr_power();
    const int app_power = settings.get_app_power();
    const int atis_power = settings.get_atis_power();
    const int del_ppm = settings.get_del_ppm();
    const int gnd_ppm = settings.get_gnd_ppm();
    const int twr_ppm = settings.get_twr_ppm();
    const int app_ppm = settings.get_app_ppm();
    const int atis_ppm = settings.get_atis_ppm();

// Write data for each ATC
    for (const ATC &atc: atcs) {
        const std::string airport_name = country + " " + atc.get_airport_name();
        const double latitude = atc.get_latitude();
        const double longitude = atc.get_longitude();

        // Get ATC position data
        const std::vector<std::string> &atc_position_name = atc.get_atc_position_name();

        // Write data for each ATC position
        for (const std::string &position_name: atc_position_name) {
            std::string position = position_name;
            std::transform(position.begin(), position.end(), position.begin(), ::tolower);

            int power = 0;
            int ppm = 0;

            if (position.find("del") != std::string::npos) {
                power = del_power;
                ppm = del_ppm;
            } else if (position.find("gnd") != std::string::npos) {
                power = gnd_power;
                ppm = gnd_ppm;
            } else if (position.find("twr") != std::string::npos) {
                power = twr_power;
                ppm = twr_ppm;
            } else if (position.find("app") != std::string::npos) {
                power = app_power;
                ppm = app_ppm;
            } else if (position.find("atis") != std::string::npos) {
                power = atis_power;
                ppm = atis_ppm;
            }

            outfile << airport_name << "," << latitude << "," << longitude << ","
                    << power << "," << ppm << "," << FIR << std::endl;
        }
    }

    outfile.close();
}