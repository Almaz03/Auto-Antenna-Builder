#ifndef AUTOANTENNA_IMPORT_DATA_H
#define AUTOANTENNA_IMPORT_DATA_H

#include "classes.h"
#include <fstream>
#include <vector>
#include <string>

void fill_data_from_airac_file(std::vector<ATC> &atc, std::ifstream &file);

void fill_atc_position_name_from_file(std::vector<ATC> &atc, std::ifstream &file);

#endif //AUTOANTENNA_IMPORT_DATA_H