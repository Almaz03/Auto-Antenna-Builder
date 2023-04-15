#include "../import_data.h"
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include "../classes.h"
#include "../import_data.h"

// Load data from the airac_file into the ATC vector class
void fill_data_from_airac_file(std::vector<ATC> &atc, std::ifstream &airac_file) {
    std::vector<std::string> atc_data; // Vector to store ATC data
    std::string line;
    while (std::getline(airac_file, line)) { // Read each line of the file
        if (line.size() > 0 && line[0] == 'A') { // Check if the line starts with "A"
            char *ptr = std::strtok(&line[0], ","); // Pointer to the first element of the line
            std::vector<std::string> elements; // Vector to store the elements of the line
            while (ptr != NULL) {
                elements.push_back(ptr); // Add the element to the vector
                ptr = std::strtok(NULL, ","); // Move to the next element
            }
// Save the elements in separate arrays
            std::string icao_code = elements[1]; // Get the ICAO code from the file
            for (int i = 0; i < atc.size(); i++) {
                if (atc[i].get_ICAO() == icao_code) {
                    // Устанавливаем название аэропорта, координаты и высоту над уровнем моря
                    atc[i].set_airport_name(elements[2]);
                    atc[i].set_coordinates(std::stod(elements[3]), std::stod(elements[4]));
                    atc[i].set_elevation(std::stoi(elements[5]));
                }
            }
        }
    }
    airac_file.close(); // Close the file
}

void fill_atc_position_name_from_file(std::vector<ATC> &atc, std::ifstream &file) {
    std::string line;
    while (std::getline(file, line)) {
        if (line.size() > 4) { // Check if the line has at least 5 characters
            std::string icao_code = line.substr(0, 4); // Get the ICAO code from the line
            for (int i = 0; i < atc.size(); i++) {
                if (atc[i].get_ICAO() == icao_code) {
                    atc[i].add_atc_position_name(line.substr(4)); // Add the position name to the ATC object
                }
            }
        }
    }
    file.close(); // Close the file
}