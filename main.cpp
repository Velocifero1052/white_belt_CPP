
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::invalid_argument;
using std::to_string;
using std::map;
using std::set;
using std::setfill;
using std::setw;
using std::stringstream;
using std::stoi;

class Date {
public:

    Date(){
        year = 0;
        month = 0;
        day = 0;
    }

    Date(int year, int month, int day){
        this->year = year;
        if(!(month >= 1 && month <= 12)) {
            string error_message = "Month value is invalid: " + to_string(month);
            throw std::invalid_argument(error_message);
        }
        this->month = month;
        if(!(day >= 1 && day <= 31)){
            string error_message = "Day value is invalid: " + to_string(day);
            throw invalid_argument(error_message);
        }
        this->day = day;
    }

    int GetYear() const{
        return year;
    }

    int GetMonth() const{
        return month;
    }

    int GetDay() const{
        return day;
    }

    bool operator==(const Date& rhs) const{
        return this->year == rhs.GetYear() && this->month == rhs.GetMonth() && this->day == rhs.GetDay();
    }

    bool operator<(const Date& rhs) const {
        return this->year < rhs.GetYear()
                || this->year == rhs.GetYear() && this->month < rhs.GetMonth()
                    || this->year == rhs.GetYear() && this->month == rhs.GetMonth() && this->day < rhs.GetDay();
    }

    friend std::ostream& operator<<(std::ostream& stream, const Date& date) {
        stream << setw(4) << setfill('0') << date.GetYear() << "-" <<
            setw(2) << setfill('0') << date.GetMonth() << "-" <<
            setw(2) << setfill('0') << date.GetDay();
        return stream;
    }

    friend std::istream& operator>>(std::istream& stream, Date& date) {

        string string_buffer;
        stream >> string_buffer;
        stringstream ss(string_buffer);

        ss >> date.year;
        if ((char)ss.peek() != '-')
            throw std::domain_error("Wrong date format: " + string_buffer);
        ss.ignore(1);
        if(ss.eof()){
            throw std::domain_error("Wrong date format: " + string_buffer);
        }
        ss >> date.month;

        if ((char)ss.peek() != '-')
            throw std::domain_error("Wrong date format: " + string_buffer);

        ss.ignore(1);

        if(string_buffer.find('-', string_buffer.length() - 1) == string_buffer.length() - 1){
            throw std::domain_error("Wrong date format: " + string_buffer);
        }

        ss >> date.day;

        if(!ss.eof())
            throw std::domain_error("Wrong date format: " + string_buffer);

        auto new_date = Date(date.year, date.month, date.day);
        date = new_date;

        return stream;
    }
private:
    int year;
    int month;
    int day;
};

class Database {
public:
    void AddEvent(const Date& date, const string& event){
        if(db.count(date) == 0)
            db[date] = set<string>();
        db[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event){

        if(db.count(date) != 0){
            auto events = db[date];
            if(events.count(event) == 0)
                return false;
            else{
                events.erase(event);
                db[date] = events;
                return true;
            }
        }
        return false;
    }
    int DeleteDate(const Date& date){
        if(db.count(date) == 0)
            return 0;
        size_t number_of_events = db[date].size();
        db.erase(date);
        return (int)number_of_events;
    }

    int Find(const Date& date) const{
        return (int)db.count(date);
    }

    void Print() const{
        for(const auto& [key, value]: db){
            for(const auto& event: value){
                cout << key << " " << event << '\n';
            }
        }
    }
    set<string>& getEvents(Date& date){
        return db[date];
    }
private:
    map<Date, set<string>> db;
};

int main() {
    Database db;

    string line;
    while (getline(cin, line)) {

        size_t number_of_arguments = std::count(line.begin(), line.end(), ' ') + 1;
        stringstream ss = stringstream(line);
        string command;

        ss >> command;

        if (command == "Add") {
            Date date;
            string event;
            try {
                ss >> date;
                ss >> event;
            }catch(const std::invalid_argument& exception){
                cout << exception.what() << '\n';
                return 0;
            }catch(const std::domain_error& exception){
                cout << exception.what() << '\n';
                return 0;
            }
            db.AddEvent(date, event);
        } else if(command == "Find") {
            Date date;
            try {
                ss >> date;
            }catch(const std::invalid_argument& exception){
                cout << exception.what() << '\n';
            }catch(const std::domain_error& exception){
                cout << exception.what() << '\n';
                return 0;
            }
            int number_of_events = db.Find(date);
            if(number_of_events != 0){
                for(const string& event : db.getEvents(date)){
                    cout << event << '\n';
                }
            }
        } else if(command == "Print") {
            db.Print();
        } else if(command == "Del") {
            Date date;
            if(number_of_arguments == 2){

                  try{
                      ss >> date;
                      int number_of_deleted_events = db.DeleteDate(date);
                      cout << "Deleted " << number_of_deleted_events << " events\n";
                  }catch(const std::invalid_argument& exception){
                      cout << exception.what() << '\n';
                      return 0;
                  }catch(const std::domain_error& exception){
                      cout << exception.what() << '\n';
                      return 0;
                  }
            }else{
                string event;
                try {
                    ss >> date >> event;
                }catch(const std::invalid_argument& exception){
                    cout << exception.what() << '\n';
                    return 0;
                }catch(const std::domain_error& exception){
                    cout << exception.what() << '\n';
                    return 0;
                }

                bool is_deleted = db.DeleteEvent(date, event);

                if(is_deleted){
                    cout << "Deleted successfully\n";
                }else{
                    cout << "Event not found\n";
                }

            }
        } else if (command.empty()) {
            continue;
        } else {
            cout << "Unknown command: " << command << '\n';
        }

    }

    return 0;
}

