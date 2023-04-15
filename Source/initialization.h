#ifndef AUTOANTENNA_INITIALIZATION_H
#define AUTOANTENNA_INITIALIZATION_H
const short MAX_POWER = 50;
const short MIN_POWER = 1;
const short DEFAULT_DEL_POWER = 3;
const short DEFAULT_GND_POWER = 3;
const short DEFAULT_TWR_POWER = 5;
const short DEFAULT_APP_POWER = 10;
const short DEFAULT_ATIS_POWER = 2;
const short MIN_PPM = 1;
const short MAX_PPM = 5;
const short DEFAULT_PPM = 2;
const short YES = 1;
const short NO = 0;
const short MAX_ELEVATION = 500;
const short MIN_ELEVATION = 0;

void fill_country(Settings &settings);

void fill_fir(Settings &settings);

void fill_ICAO(std::vector<ATC> &atc);

void fill_power(Settings &settings);

void fill_ppm(Settings &settings);

void fill_is_CTR(Settings &settings);

void is_correct_password();

void fill_up_elevation(Settings &settings);

#endif// AUTOANTENNA_INITIALIZATION_H
