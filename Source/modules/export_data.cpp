#include <fstream>
#include <algorithm>
#include "../export_data.h"

void export_data_to_file(std::vector<ATC> &atcs, Settings &settings) {
    std::vector<std::string> final_data;
    const std::string country = settings.get_country();
    const std::string filename = "..//Output//" + country + ".csv"; // define the filename and path
    std::ofstream outfile(filename);
    if (!outfile) {
        throw std::runtime_error("Failed to open file");
    }
    // Write header
    outfile << "identifier,name,latitude,longitude,elevation,power,ppm,atc_positions,subcenters" << std::endl;

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
    const bool del_is_CTR = settings.get_del_is_CTR();
    const bool gnd_is_CTR = settings.get_gnd_is_CTR();
    const bool twr_is_CTR = settings.get_twr_is_CTR();
    const bool app_is_CTR = settings.get_app_is_CTR();
    const bool atis_is_CTR = settings.get_atis_is_CTR();

// Write data for each ATC
    for (const ATC &atc: atcs) {
        const std::string airport_name = atc.get_airport_name();
        const double latitude = atc.get_latitude();
        const double longitude = atc.get_longitude();
        const int elevation = atc.get_elevation() + settings.get_up_elevation();
        const std::string icao = atc.get_ICAO();
        // Get ATC position data
        const std::vector<std::string> &atc_position_name = atc.get_atc_position_name();

        // Write data for each ATC position
        for (const std::string &position_name: atc_position_name) {
            std::string position = position_name;
            std::transform(position.begin(), position.end(), position.begin(), ::toupper);

            int power = 0;
            int ppm = 0;

            if (position.find("DEL") != std::string::npos) {
                power = del_power;
                ppm = del_ppm;
            } else if (position.find("GND") != std::string::npos) {
                power = gnd_power;
                ppm = gnd_ppm;
            } else if (position.find("TWR") != std::string::npos) {
                power = twr_power;
                ppm = twr_ppm;
            } else if (position.find("APP") != std::string::npos) {
                power = app_power;
                ppm = app_ppm;
            } else if (position.find("ATIS") != std::string::npos) {
                power = atis_power;
                ppm = atis_ppm;
            }
            if (position.find("APP"))
                final_data.push_back(
                        country + "-" + airport_name + "-TMA-" + std::to_string(power) + "W," + country + "-" + icao
                        + "-Approach-Antenna-" + std::to_string(power) + "W," + std::to_string(latitude) + "," +
                        std::to_string(longitude) + ","
                        + std::to_string(elevation) + "," + std::to_string(power) + "," + std::to_string(ppm) + "," +
                        icao + position + ",");
            else if (position.find("ATIS"))
                final_data.push_back(
                        country + "-" + airport_name + "-ATIS-" + std::to_string(power) + "W," + country + "-" + icao
                        + "-ATIS-Antenna-" + std::to_string(power) + "W," + std::to_string(latitude) + "," +
                        std::to_string(longitude) + ","
                        + std::to_string(elevation) + "," + std::to_string(power) + "," + std::to_string(ppm) + "," +
                        icao + position + ",");
            else if (position.find("TWR-"))
                final_data.push_back(
                        country + "-" + airport_name + "-AD-" + std::to_string(power) + "W," + country + "-" + icao
                        + "-Tower-Antenna-" + std::to_string(power) + "W," + std::to_string(latitude) + "," +
                        std::to_string(longitude) + ","
                        + std::to_string(elevation) + "," + std::to_string(power) + "," + std::to_string(ppm) + "," +
                        icao + position + ",");
            else if (position.find("GND"))
                final_data.push_back(
                        country + "-" + airport_name + "-AD-" + std::to_string(power) + "W," + country + "-" + icao
                        + "-Ground-Antenna-" + std::to_string(power) + "W," + std::to_string(latitude) + "," +
                        std::to_string(longitude) + ","
                        + std::to_string(elevation) + "," + std::to_string(power) + "," + std::to_string(ppm) + "," +
                        icao + position + ",");
            else if (position.find("DEL"))
                final_data.push_back(
                        country + "-" + airport_name + "-AD-" + std::to_string(power) + "W," + "," + country + "-" +
                        icao
                        + "-Delivery-Antenna-" + std::to_string(power) + "W," + std::to_string(latitude) + "," + "," +
                        std::to_string(longitude) + ","
                        + std::to_string(elevation) + "," + std::to_string(power) + "," + std::to_string(ppm) + "," +
                        icao + position + ",");
        }
    }
    for (std::string &data: final_data) {
        if (data.find("DEL") != std::string::npos && del_is_CTR) {
            data.append(FIR);
        } else if (data.find("GND") != std::string::npos && gnd_is_CTR) {
            data.append(FIR);

        } else if (data.find("TWR") != std::string::npos && twr_is_CTR) {
            data.append(FIR);
        } else if (data.find("APP") != std::string::npos && app_is_CTR) {
            data.append(FIR);
        } else if (data.find("ATIS") != std::string::npos && atis_is_CTR) {
            data.append(FIR);
        }
    }
    for (std::string &data: final_data) {
        outfile << data << std::endl;
    }

    outfile.close();
}