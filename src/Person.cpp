//
// Created by Legion on 4/13/2023.
//

#include <string>
#include <map>
#include <algorithm>

class Person {
public:
    void ChangeFirstName(int year, const std::string& first_name) {
        years_to_names[year] = first_name;
    }
    void ChangeLastName(int year, const std::string& last_name) {
        years_to_lastnames[year] = last_name;
    }
    std::string GetFullName(int year) {

        auto name_search_res =  find_if(years_to_names.rbegin(), years_to_names.rend(), [year](const std::pair<int, std::string>& entry)-> bool {
            return entry.first <= year;
        });
        auto lastname_search_res =  find_if(years_to_lastnames.rbegin(), years_to_lastnames.rend(), [year](const std::pair<int, std::string>& entry)-> bool {
            return entry.first <= year;
        });

        bool name_found = name_search_res != years_to_names.rend();
        bool lastname_found = lastname_search_res != years_to_lastnames.rend();

        if(name_found && lastname_found){
            return name_search_res->second + " " + lastname_search_res->second;
        }else if(name_found){
            return name_search_res->second + " with unknown last name";
        }else if(lastname_found){
            return lastname_search_res->second + " with unknown first name";
        }else {
            return "Incognito";
        }
    }
private:
    std::map<int, std::string> years_to_names;
    std::map<int, std::string> years_to_lastnames;
};