#include <iostream>
#include <string>
#include <vector>
#include "../classes.h"
#include "../initialization.h"

// Function to fill the country information in the settings
void fill_country(Settings &settings) {
    std::string country;
    std::cout << "Enter country code (ex: KG): " << std::endl;
    std::getline(std::cin, country);
    settings.set_country(country);
}

// Function to fill the FIR information in the settings
void fill_fir(Settings &settings) {
    std::string fir;
    std::cout << "Enter FIR code (ex: UCFM): " << std::endl;
    std::getline(std::cin, fir);
    settings.set_FIR(fir);
}

// Function to fill the ICAO information for the ATC positions
void fill_ICAO(std::vector<ATC> &atc) {
    std::cout << "Enter ICAO codes of airports separated by space (ex: UUDD UUWW UUEE):" << std::endl;
    std::string icaos;
    std::getline(std::cin, icaos);
    std::string line = "";
    for (auto c: icaos) {
        if (c == ' ') {
            ATC new_atc;
            new_atc.set_ICAO(line);
            atc.push_back(new_atc);
            line = "";
        } else {
            line += c;
        }
    }
    if (!line.empty()) {
        ATC new_atc;
        new_atc.set_ICAO(line);
        atc.push_back(new_atc);
    }
}

// Function to fill in the power information for the ATC positions
void fill_power(Settings &settings) {
    std::cout << "Do you want to set the same power for all positions? Enter 1 for Yes, 0 for No." << std::endl;
    short same_power;
    std::cin >> same_power;

    if (same_power == 1) {
        std::cout << "Enter the value of power:" << std::endl;
        short value;
        std::cin >> value;
        settings.set_same_power(value); // Set the same power for all positions
    } else if (same_power == 0) {
        std::cout
                << "Do you want to set default power? Enter 1 for Yes, 0 for No. Default power is 10 for APP and ATIS, 5 for TWR, 3 for GND and DEL."
                << std::endl;
        short default_power;
        std::cin >> default_power;
        if (default_power == 1) {
            settings.set_power(3, 3, 5, 10, 10); // Set default power for all positions
        } else if (default_power == 0) {
            std::cout << "!!!Maximum power value is 50 and minimum power value is 1!!!" << std::endl;
            std::cout << "Enter the power of the Delivery position:" << std::endl;
            short del;
            std::cin >> del;
            std::cout << "Enter the power of the Ground position:" << std::endl;
            short gnd;
            std::cin >> gnd;
            std::cout << "Enter the power of the Tower position:" << std::endl;
            short twr;
            std::cin >> twr;
            std::cout << "Enter the power of the Approach position:" << std::endl;
            short app;
            std::cin >> app;
            std::cout << "Enter the power of the ATIS position:" << std::endl;
            short atis;
            std::cin >> atis;
            settings.set_power(del, gnd, twr, app, atis); // Set power for each position
        } else {
            std::cout << "Something went wrong. Please restart the tool." << std::endl;
            std::cout << "Press Enter to exit." << std::endl;
            system("pause"); // Wait for user to press Enter before exiting
        }
    } else {
        std::cout << "Something went wrong. Please restart the tool." << std::endl;
        std::cout << "Press Enter to exit." << std::endl;
        system("pause"); // Wait for user to press Enter before exiting
    }
}

// This function takes user input to set the power for different ATC positions.
// If the user chooses to set the same power for all positions, the function calls the Settings function to set the same power for all positions.
// If the user chooses to set individual powers for each position, the function prompts the user to enter the power for each position and calls the Settings function to set the power for each position.
// If the user enters an incorrect value, the function displays an error message and prompts the user to restart the tool.

void fill_ppm(Settings& settings) {
    std::cout << "Do you want to set same PPM to all positions? 1/Yes, 0/NO." << std::endl;
    short same_ppm;
    std::cin >> same_ppm;

    if (same_ppm == 1) {
        std::cout << "Enter value of PPM:" << std::endl;
        short value;
        std::cin >> value;
        settings.set_same_ppm(value);
    } else if (same_ppm == 0) {
        std::cout << "Do you want to set default PPM (is 2)? 1/Yes, 0/NO" << std::endl;
        short default_ppm;
        std::cin >> default_ppm;
        if (default_ppm == 1) settings.set_ppm(2, 2, 2, 2, 2);
        else if (default_ppm == 0) {
            std::cout << "!!!Maximum value of PPM is 5 and minimum value of PPM is 1!!!" << std::endl;
            std::cout << "Enter power of Delivery position:" << std::endl;
            short ppm;
            settings.set_same_ppm(ppm);

        } else {
            std::cout << "Something went wrong, restart tool" << std::endl;
            std::cout << "Press Enter to exit" << std::endl;
            system("pause");

        }
    } else {
        std::cout << "Something went wrong, restart tool" << std::endl;
        std::cout << "Press Enter to exit" << std::endl;
        system("pause");
    }
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
                std::exit(0);
            }
        }
        else {
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
                    std::exit(0);
                }
            }
        }
    }
}

void fill_up_elevation(Settings& settings) {
    short up_elevation;
    std::cout << "Enter how much feet you would like to add to elevation: " << std::endl;
    std::cin >> up_elevation;
    settings.set_up_elevation(up_elevation);
}