#ifndef AUTOANTENNA_INITIALIZATION_H
#define AUTOANTENNA_INITIALIZATION_H
void fill_country(Settings &settings);
void fill_fir(Settings &settings);
void fill_ICAO(std::vector<ATC> &atc);
void fill_power(Settings &settings);
void fill_ppm(Settings &settings);
void is_correct_password();
void fill_up_elevation(Settings &settings);
#endif// AUTOANTENNA_INITIALIZATION_H
