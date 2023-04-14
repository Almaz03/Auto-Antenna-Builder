#include <string>
#include <vector>
#include "../classes.h"
#include "../functions.h"

void Settings::set_up_elevation(short elevation) {
    up_elevation = elevation;
//check_up_elevation();
}

short Settings::get_up_elevation() const {
    return up_elevation;
}

void Settings::set_FIR(std::string FIR) {
    FIR = enters(FIR); // remove any leading/trailing white spaces
    this->FIR = FIR;
    this->FIR += "_CTR"; // add "_CTR" to the end of FIR
}

void Settings::set_country(std::string country) {
    country = enters(country); // remove any leading/trailing white spaces
    country = firsttouppercase(country); // capitalize first letter of each word
    this->country = country;
}

void Settings::set_same_ppm(short ppm) {
    atc_data.atis.ppm = ppm;
    atc_data.app.ppm = ppm;
    atc_data.twr.ppm = ppm;
    atc_data.gnd.ppm = ppm;
    atc_data.del.ppm = ppm;
//check_ppm();
}

void Settings::set_same_power(short power) {
    atc_data.atis.power = power;
    atc_data.app.power = power;
    atc_data.twr.power = power;
    atc_data.gnd.power = power;
    atc_data.del.power = power;
//check_power();
}

void Settings::set_power(short del, short gnd, short twr, short app, short atis) {
    atc_data.del.power = del;
    atc_data.gnd.power = gnd;
    atc_data.twr.power = twr;
    atc_data.app.power = app;
    atc_data.atis.power = atis;
//check_power();
}

void Settings::set_ppm(short del, short gnd, short twr, short app, short atis) {
    atc_data.del.ppm = del;
    atc_data.gnd.ppm = gnd;
    atc_data.twr.ppm = twr;
    atc_data.app.ppm = app;
    atc_data.atis.ppm = atis;
//check_ppm();
}

std::string Settings::get_FIR() const{
    return FIR;
}

std::string Settings::get_country() const{
    return country;
}

int Settings::get_del_ppm() const { return atc_data.del.ppm; }

int Settings::get_gnd_ppm() const { return atc_data.gnd.ppm; }

int Settings::get_twr_ppm() const { return atc_data.twr.ppm; }

int Settings::get_app_ppm() const { return atc_data.app.ppm; }

int Settings::get_atis_ppm() const { return atc_data.atis.ppm; }

int Settings::get_del_power() const { return atc_data.del.power; }

int Settings::get_gnd_power() const { return atc_data.gnd.power; }

int Settings::get_twr_power() const { return atc_data.twr.power; }

int Settings::get_app_power() const { return atc_data.app.power; }

int Settings::get_atis_power() const { return atc_data.atis.power; }

void ATC::set_ICAO(std::string ICAO) {
    ICAO = enters(ICAO); // remove any leading/trailing white spaces
    this->ICAO = ICAO;
}

void ATC::set_airport_name(std::string airport_name) {
    airport_name = enters(airport_name); // remove any leading/trailing white spaces
    this->airport_name = airport_name;
}

void ATC::set_coordinates(double longitude, double latitude) {
    coordinates.longitude = longitude;
    coordinates.latitude = latitude;
}

void ATC::set_elevation(int elevation) {
    this->elevation = elevation;
}

void ATC::add_atc_position_name(const std::string &name) {
    atc_position_name.push_back(name);
}

std::string ATC::get_ICAO() const{
    return ICAO;
}

std::string ATC::get_airport_name() const{
    return airport_name;
}

double ATC::get_latitude() const {
    return coordinates.latitude;
}

double ATC::get_longitude() const {
    return coordinates.longitude;
}

int ATC::get_elevation() const {
    return elevation;
}

std::vector<std::string> ATC::get_atc_position_name() const {
    return atc_position_name;
}
