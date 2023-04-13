
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

using std::find_if;
using std::vector;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::map;
using std::prev;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        years_to_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        years_to_lastnames[year] = last_name;
    }
    string GetFullName(int year) {

        auto name_search_res =  find_if(years_to_names.rbegin(), years_to_names.rend(), [year](const std::pair<int, string>& entry)-> bool {
            return entry.first <= year;
        });
        auto lastname_search_res =  find_if(years_to_lastnames.rbegin(), years_to_lastnames.rend(), [year](const std::pair<int, string>& entry)-> bool {
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
    map<int, string> years_to_names;
    map<int, string> years_to_lastnames;
};


int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}

