#ifndef AUTOANTENNA_CLASSES_H
#define AUTOANTENNA_CLASSES_H

#include <string>
#include <vector>

class Settings {
private:
    std::string FIR;
    std::string country;
    struct Atc_values {
        int power;
        int ppm;
        bool is_CTR;
    };

    struct Atc_positions {
        Atc_values del;
        Atc_values gnd;
        Atc_values twr;
        Atc_values app;
        Atc_values atis;
    };

    int up_elevation;
    Atc_positions atc_data;

    //void check_ppm();
    //void check_power();
    //void check_up_elevation();
public:
    void set_up_elevation(short elevation = 0);

    void set_FIR(std::string FIR);

    void set_country(std::string country);

    void set_same_ppm(short ppm);

    void set_same_power(short power);

    void set_power(short del, short gnd, short twr, short app, short atis);

    void set_ppm(short del, short gnd, short twr, short app, short atis);

    void set_is_CTR(bool del, bool gnd, bool twr, bool app, bool atis);

    short get_up_elevation() const;

    std::string get_FIR() const;

    std::string get_country() const;

    int get_del_ppm() const;

    int get_gnd_ppm() const;

    int get_twr_ppm() const;

    int get_app_ppm() const;

    int get_atis_ppm() const;

    int get_del_power() const;

    int get_gnd_power() const;

    int get_twr_power() const;

    int get_app_power() const;

    int get_atis_power() const;

    bool get_del_is_CTR() const;

    bool get_gnd_is_CTR() const;

    bool get_twr_is_CTR() const;

    bool get_app_is_CTR() const;

    bool get_atis_is_CTR() const;
};

class ATC {
private:
    std::string ICAO;
    std::string airport_name;
    struct coordinates_of_ARP {
        double latitude;
        double longitude;
    };

    coordinates_of_ARP coordinates;
    int elevation;
    std::vector<std::string> atc_position_name;

    //void check_elevation(Settings &settings);
public:
    void set_ICAO(std::string ICAO);

    void set_airport_name(std::string airport_name);

    void set_coordinates(double longitude, double latitude);

    void set_elevation(int elevation);

    void add_atc_position_name(const std::string &name);

    std::string get_ICAO() const;

    std::string get_airport_name() const;

    double get_latitude() const;

    double get_longitude() const;

    int get_elevation() const;

    std::vector<std::string> get_atc_position_name() const;

    //void set_ATC_position_name(std::vector <std::string> atc_position_name);
};

#endif // AUTOANTENNA_CLASSES_H

