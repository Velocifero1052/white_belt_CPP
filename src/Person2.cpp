//
// Created by Legion on 4/17/2023.
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

        auto name_search_res =  find_if(years_to_names.rbegin(), years_to_names.rend(),
                                        [year](const std::pair<int, std::string>& entry)-> bool {
                                            return entry.first <= year;
                                        });
        auto lastname_search_res =  find_if(years_to_lastnames.rbegin(), years_to_lastnames.rend(),
                                            [year](const std::pair<int, std::string>& entry)-> bool {
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
        } else {
            return "Incognito";
        }
    }

    std::string GetFullNameWithHistory(int year) {

        auto name_search_res =  find_if(years_to_names.rbegin(), years_to_names.rend(),
                                        [year](const std::pair<int, std::string>& entry)-> bool {
                                            return entry.first <= year;
                                        });
        auto lastname_search_res =  find_if(years_to_lastnames.rbegin(), years_to_lastnames.rend(),
                                            [year](const std::pair<int, std::string>& entry)-> bool {
                                                return entry.first <= year;
                                            });

        bool name_found = name_search_res != years_to_names.rend();
        bool lastname_found = lastname_search_res != years_to_lastnames.rend();

        auto distance_names = distance(name_search_res, years_to_names.rend());
        auto distance_surnames = distance(lastname_search_res, years_to_lastnames.rend());

        if(name_found && lastname_found){
            std::string history_name;
            if(distance_names > 1) {
                history_name = form_history(name_search_res, years_to_names.rend());
            }
            std::string history_last_name;
            if(distance_surnames > 1){
                history_last_name = form_history(lastname_search_res, years_to_lastnames.rend());
            }
            if(!history_name.empty() && !history_last_name.empty()){
                history_name = " " + history_name + " ";
                history_last_name = " " + history_last_name;
                return name_search_res->second + history_name + lastname_search_res->second + history_last_name;
            }else if(!history_name.empty()){
                history_name = " " + history_name + " ";
                return name_search_res->second + history_name + lastname_search_res->second;
            }else if(!history_last_name.empty()){
                history_last_name = " " + history_last_name;
                return name_search_res->second + " " + lastname_search_res->second + history_last_name;
            }
            else return name_search_res->second + " " + lastname_search_res->second;
        }else if(name_found){
            std::string history;
            if(distance_names > 1){
                history = form_history(name_search_res, years_to_names.rend());
            }
            if(!history.empty()){
                history = " " + history + " ";
                return name_search_res->second + history + "with unknown last name";
            } else {
                return name_search_res->second + " with unknown last name";
            }
        }else if(lastname_found){
            std::string history;
            if(distance_surnames > 1){
                history = form_history(lastname_search_res, years_to_lastnames.rend());
            }
            if(!history.empty()){
                history = " " + history + " ";
                return lastname_search_res->second + history + "with unknown first name";
            }else return lastname_search_res->second + " with unknown first name";
        } else {
            return "Incognito";
        }
    }
private:
    std::map<int, std::string> years_to_names;
    std::map<int, std::string> years_to_lastnames;

    template <typename Iterator>
    std::string form_history(Iterator start, Iterator end){
        std::string history;
        bool first = true;
        std::string currentName = start->second;
        for (auto i = next(start); i != end; i++) {
            if(i->second != currentName) {
                if (first) {
                    history += "(" + i->second;
                    first = false;
                } else {
                    history += ", " + i->second;
                }
                currentName = i->second;
            }
        }
        if(!history.empty())
            history += ")";
        return history;
    }

};
