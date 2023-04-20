//
// Created by Legion on 4/20/2023.
//
#include <string>
#include <system_error>

std::string AskTimeServer() {
    /* Для тестирования повставляйте сюда код, реализующий различное поведение этой функии:
       * нормальный возврат строкового значения
       * выброс исключения system_error
       * выброс другого исключения с сообщением.
    */
}

class TimeServer {
public:
    std::string GetCurrentTime() {
        /* Реализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в last_fetched_time и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            поля last_fetched_time
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        */
        try{
            std::string res = AskTimeServer();
            last_fetched_time = res;
            return last_fetched_time;
        }catch(std::system_error& system_error){
            return last_fetched_time;
        }
    }

private:
    std::string last_fetched_time = "00:00:00";
};