#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../classes.h"
#include "../initialization.h"

// Function to fill the country information in the settings
void fill_country(Settings &settings) {
    std::string country;
    std::cout << "Enter country code (ex: KG): " << std::endl;
    std::getline(std::cin, country);

    while (country.empty()) {
        std::cout << "Invalid input. Please enter a valid country code: " << std::endl;
        std::getline(std::cin, country);
    }

    settings.set_country(country);
}

// Function to fill the FIR information in the settings
void fill_fir(Settings &settings) {
    std::string fir;
    std::cout << "Enter FIR code (ex: UCFM): " << std::endl;
    std::getline(std::cin, fir);

    while (fir.empty()) {
        std::cout << "Invalid input. Please enter a valid FIR code: " << std::endl;
        std::getline(std::cin, fir);
    }

    settings.set_FIR(fir);
}

// Function to fill the ICAO information for the ATC positions
void fill_ICAO(std::vector<ATC> &atc) {
    std::cout << "Enter ICAO codes of airports separated by space (ex: UUDD UUWW UUEE):" << std::endl;
    std::string icaos;
    std::getline(std::cin, icaos);
    std::istringstream iss(icaos);
    std::string line;
    while (iss >> line) {
        ATC new_atc;
        new_atc.set_ICAO(line);
        atc.push_back(new_atc);
    }
}

// Function to fill in the power information for the ATC positions
void fill_power(Settings &settings) {
    std::cout << "Do you want to set the same power for all positions? Enter 1 for Yes, 0 for No:" << std::endl;
    short same_power;
    std::cin >> same_power;

    if (same_power == 1) {
        std::cout << "!!!Maximum power value is " << MAX_POWER << " and minimum power value is " << MIN_POWER << "!!!"
                  << std::endl;
        std::cout << "Enter the value of power:" << std::endl;
        short value;
        std::cin >> value;
        if (value > MAX_POWER) {
            value = MAX_POWER;
            std::cout << "You exceed maximum value of power. Value of power is set to " << MAX_POWER << std::endl;
        } else if (value < MIN_POWER) {
            value = MIN_POWER;
            std::cout << "You exceed minimum value of power. Value of power is set to " << MIN_POWER << std::endl;
        }
        settings.set_same_power(value); // Set the same power for all positions
    } else if (same_power == 0) {
        std::cout
                << "Do you want to set default power? Enter 1 for Yes, 0 for No. Default power is " << DEFAULT_APP_POWER
                << " for APP, " << DEFAULT_ATIS_POWER << " for ATIS, " << DEFAULT_TWR_POWER << " for TWR, "
                << DEFAULT_GND_POWER << " for GND, " << DEFAULT_DEL_POWER << " for DEL:"
                << std::endl;
        short default_power;
        std::cin >> default_power;
        if (default_power == 1) {
            settings.set_power(DEFAULT_DEL_POWER, DEFAULT_GND_POWER, DEFAULT_TWR_POWER, DEFAULT_APP_POWER,
                               DEFAULT_ATIS_POWER); // Set default power for all positions
        } else if (default_power == 0) {
            std::cout << "!!!Maximum power value is " << MAX_POWER << " and minimum power value is " << MIN_POWER
                      << "!!!" << std::endl;
            std::cout << "Enter the power of the Delivery position:" << std::endl;
            short del;
            std::cin >> del;
            if (del > MAX_POWER) {
                del = MAX_POWER;
                std::cout << "You exceed maximum power of del position. Value of power is set to " << MAX_POWER
                          << std::endl;
            } else if (del < MIN_POWER) {
                del = MIN_POWER;
                std::cout << "You exceed minimum power of del position. Value of power is set to " << MIN_POWER
                          << std::endl;
            }
            std::cout << "Enter the power of the Ground position:" << std::endl;
            short gnd;
            std::cin >> gnd;
            if (gnd > MAX_POWER) {
                gnd = MAX_POWER;
                std::cout << "You exceed maximum power of gnd position. Value of power is set to " << MAX_POWER
                          << std::endl;
            } else if (gnd < MIN_POWER) {
                gnd = MIN_POWER;
                std::cout << "You exceed minimum power of gnd position. Value of power is set to " << MIN_POWER
                          << std::endl;
            }
            std::cout << "Enter the power of the Tower position:" << std::endl;
            short twr;
            std::cin >> twr;
            if (twr > MAX_POWER) {
                twr = MAX_POWER;
                std::cout << "You exceed maximum power of twr position. Value of power is set to " << MAX_POWER
                          << std::endl;
            } else if (gnd < MIN_POWER) {
                twr = MIN_POWER;
                std::cout << "You exceed minimum power of twr position. Value of power is set to " << MIN_POWER
                          << std::endl;
            }
            std::cout << "Enter the power of the Approach position:" << std::endl;
            short app;
            std::cin >> app;
            if (app > MAX_POWER) {
                app = MAX_POWER;
                std::cout << "You exceed maximum power of app position. Value of power is set to " << MAX_POWER
                          << std::endl;
            } else if (app < MIN_POWER) {
                app = MIN_POWER;
                std::cout << "You exceed minimum power of app position. Value of power is set to " << MIN_POWER
                          << std::endl;
            }
            std::cout << "Enter the power of the ATIS position:" << std::endl;
            short atis;
            std::cin >> atis;
            if (atis > MAX_POWER) {
                atis = MAX_POWER;
                std::cout << "You exceed maximum power of atis position. Value of power is set to " << MAX_POWER
                          << std::endl;
            } else if (gnd < MIN_POWER) {
                atis = MIN_POWER;
                std::cout << "You exceed minimum power of atis position. Value of power is set to " << MIN_POWER
                          << std::endl;
            }
            settings.set_power(del, gnd, twr, app, atis); // Set power for each position
        } else {
            std::cout << "Something went wrong. Please restart the tool." << std::endl;
            std::cout << "Press Enter to exit." << std::endl;
            system("pause");
            exit(0);// Wait for user to press Enter before exiting
        }
    } else {
        std::cout << "Something went wrong. Please restart the tool." << std::endl;
        std::cout << "Press Enter to exit." << std::endl;
        system("pause");
        exit(0);// Wait for user to press Enter before exiting
    }
}

void fill_ppm(Settings &settings) {
    std::cout << "Do you want to set the same ppm for all positions? Enter 1 for Yes, 0 for No:" << std::endl;
    short same_ppm;
    std::cin >> same_ppm;

    if (same_ppm == 1) {
        std::cout << "!!!Maximum ppm value is " << MAX_PPM << " and minimum ppm value is " << MIN_PPM << "!!!"
                  << std::endl;
        std::cout << "Enter the value of ppm:" << std::endl;
        short value;
        std::cin >> value;
        if (value > MAX_PPM) {
            value = MAX_PPM;
            std::cout << "You exceeded maximum value of ppm. Value of ppm is set to " << MAX_PPM << std::endl;
        } else if (value < MIN_PPM) {
            value = MIN_PPM;
            std::cout << "You exceeded minimum value of ppm. Value of ppm is set to " << MIN_PPM << std::endl;
        }
        settings.set_same_ppm(value); // Set the same ppm for all positions
    } else if (same_ppm == 0) {
        std::cout << "Do you want to set default ppm (is " << DEFAULT_PPM << ")? Enter 1 for Yes, 0 for No:"
                  << std::endl;
        short default_ppm;
        std::cin >> default_ppm;
        if (default_ppm == 1) {
            settings.set_same_ppm(DEFAULT_PPM); // Set default ppm for all positions
        } else if (default_ppm == 0) {
            std::cout << "!!!Maximum ppm value is " << MAX_PPM << " and minimum ppm value is " << MIN_PPM << "!!!"
                      << std::endl;
            std::cout << "Enter the ppm of the Delivery position:" << std::endl;
            short del;
            std::cin >> del;
            if (del > MAX_PPM) {
                del = MAX_PPM;
                std::cout << "You exceeded maximum ppm value of del. Value of ppm is set to " << MAX_PPM << std::endl;
            } else if (del < MIN_PPM) {
                del = MIN_PPM;
                std::cout << "You exceeded minimum ppm value of del. Value of ppm is set to " << MIN_PPM << std::endl;
            }
            std::cout << "Enter the ppm of the Ground position:" << std::endl;
            short gnd;
            std::cin >> gnd;
            if (gnd > MAX_PPM) {
                gnd = MAX_PPM;
                std::cout << "You exceeded maximum ppm value of gnd. Value of ppm is set to " << MAX_PPM << std::endl;
            } else if (gnd < MIN_PPM) {
                gnd = MIN_PPM;
                std::cout << "You exceeded minimum ppm value of gnd. Value of ppm is set to " << MIN_PPM << std::endl;
            }
            std::cout << "Enter the ppm of the Tower position:" << std::endl;
            short twr;
            std::cin >> twr;
            if (twr > MAX_PPM) {
                twr = MAX_PPM;
                std::cout << "You exceeded maximum ppm value of twr. Value of ppm is set to " << MAX_PPM << std::endl;
            } else if (twr < MIN_PPM) {
                twr = MIN_PPM;
                std::cout << "You exceeded minimum ppm value of twr. Value of ppm is set to " << MIN_PPM << std::endl;
            }
            std::cout << "Enter the ppm of the Approach position:" << std::endl;
            short app;
            std::cin >> app;
            if (app > MAX_PPM) {
                app = MAX_PPM;
                std::cout << "You exceeded maximum ppm value of app. Value of ppm is set to " << MAX_PPM << std::endl;
            } else if (app < MIN_PPM) {
                app = MIN_PPM;
                std::cout << "You exceeded minimum ppm value of app. Value of ppm is set to " << MIN_PPM << std::endl;
            }
            std::cout << "Enter the ppm of the ATIS position:" << std::endl;
            short atis;
            std::cin >> atis;
            if (atis > MAX_PPM) {
                atis = MAX_PPM;
                std::cout << "You exceeded maximum ppm value of atis. Value of ppm is set to " << MAX_PPM << std::endl;
            } else if (atis < MIN_PPM) {
                atis = MIN_PPM;
                std::cout << "You exceeded minimum ppm value of atis. Value of ppm is set to " << MIN_PPM << std::endl;
            }
            settings.set_ppm(del, gnd, twr, app, atis); // Set ppm for each position
        } else {
            std::cout << "Something went wrong. Please restart the tool." << std::endl;
            std::cout << "Press Enter to exit." << std::endl;
            system("pause");
            exit(0);// Wait for user to press Enter before exiting
        }
    } else {
        std::cout << "Something went wrong. Please restart the tool." << std::endl;
        std::cout << "Press Enter to exit." << std::endl;
        system("pause");
        exit(0);// Wait for user to press Enter before exiting
    }
}

void fill_is_CTR(Settings &settings) {

    std::cout << "Do you want to set CTR position to all antennas? Enter 1 for Yes, 0 for No:" << std::endl;
    short default_is_CTR;
    std::cin >> default_is_CTR;
    if (default_is_CTR == YES) {
        settings.set_is_CTR(YES, YES, YES, YES, YES); // Set default is_CTR for all positions
    } else if (default_is_CTR == NO) {
        std::cout << "Do you want to set CTR to Delivery position? Enter 1 for Yes, 0 for No:" << std::endl;
        short del;
        std::cin >> del;
        if (del > YES) {
            del = YES;
            std::cout << "Wrong value, set " << YES << " as default." << std::endl;
        } else if (del < NO) {
            del = NO;
            std::cout << "Wrong value, set " << NO << " as default." << std::endl;
        }
        std::cout << "Do you want to set CTR to Ground position:" << std::endl;
        short gnd;
        std::cin >> gnd;
        if (gnd > YES) {
            gnd = YES;
            std::cout << "Wrong value, set " << YES << " as default." << std::endl;
        } else if (gnd < NO) {
            gnd = NO;
            std::cout << "Wrong value, set " << NO << " as default." << std::endl;
        }
        std::cout << "Do you want to set CTR to Tower position:" << std::endl;
        short twr;
        std::cin >> twr;
        if (twr > YES) {
            twr = YES;
            std::cout << "Wrong value, set " << YES << " as default." << std::endl;
        } else if (twr < NO) {
            twr = NO;
            std::cout << "Wrong value, set " << NO << " as default." << std::endl;
        }
        std::cout << "Do you want to set CTR to Approach position:" << std::endl;
        short app;
        std::cin >> app;
        if (app > YES) {
            app = YES;
            std::cout << "Wrong value, set " << YES << " as default." << std::endl;
        } else if (app < NO) {
            app = NO;
            std::cout << "Wrong value, set " << NO << " as default." << std::endl;
        }
        std::cout << "Do you want to set CTR to ATIS position:" << std::endl;
        short atis;
        std::cin >> atis;
        if (atis > YES) {
            atis = YES;
            std::cout << "Wrong value, set " << YES << " as default." << std::endl;
        } else if (atis < NO) {
            atis = NO;
            std::cout << "Wrong value, set " << NO << " as default." << std::endl;
        }
        settings.set_is_CTR(del, gnd, twr, app, atis); // Set is_CTR for each position
    } else {
        std::cout << "Something went wrong. Please restart the tool." << std::endl;
        std::cout << "Press Enter to exit." << std::endl;
        system("pause");
        exit(0);// Wait for user to press Enter before exiting
    }
}

void fill_up_elevation(Settings &settings) {
    short up_elevation;
    std::cout << "Enter how much feet you would like to add to elevation: " << std::endl;
    std::cin >> up_elevation;
    if (up_elevation > MAX_ELEVATION) {
        up_elevation = MAX_ELEVATION;
        std::cout << "You exceeded maximum value of elevation. Value of elevation is set to " << MAX_ELEVATION
                  << std::endl;
    } else if (up_elevation < MIN_ELEVATION) {
        up_elevation = MIN_ELEVATION;
        std::cout << "You exceeded minimum value of elevation. Value of elevation is set to " << MAX_ELEVATION
                  << std::endl;

    }
    settings.set_up_elevation(up_elevation);
}

void is_correct_password() {
    std::string password, correct_password = "test";
    bool pas_flag = true;
    int flag = 1;

    while (true) {
        std::cout << "Enter password:" << std::endl;
        std::getline(std::cin, password);

        if (password.size() != correct_password.size()) {
            // Wrong password
            std::cout << "Password is wrong" << std::endl;
            std::cout << "Do you want to enter password again? Press 1 - if YES, 0 - if NO:" << std::endl;
            std::cin >> flag;
            std::cin.ignore();

            if (flag == 0) {
                // Exit program
                std::cout << "Press Enter to exit:" << std::endl;
                system("pause");
                exit(0);
            }
        } else {
            // Check if password is correct
            for (int i = 0; i < password.size(); i++) {
                if (i == 0) pas_flag = true;
                if (password[i] == correct_password[i] and pas_flag) {
                    pas_flag = true;
                } else {
                    pas_flag = false;
                    break;
                }
            }

            if (pas_flag) {
                // Correct password
                std::cout << "Password is correct\n" << std::endl;
                break;
            } else {
                // Wrong password
                std::cout << "Password is wrong" << std::endl;
                std::cout << "Do you want to enter password again? Press 1 - if YES, 0 - if NO:" << std::endl;
                std::cin >> flag;
                std::cin.ignore();

                if (flag == 0) {
                    // Exit program
                    std::cout << "Press Enter to exit:" << std::endl;
                    system("pause");
                    exit(0);
                }
            }
        }
    }
}
