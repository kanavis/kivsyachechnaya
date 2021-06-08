/* Data constraints */
#include <string>

#define WIFI_MAX_SSID_LENGTH 32
#define WIFI_MAX_PASSWORD_LENGTH 64

#define TEMP_MAX 60
#define TEMP_MIN 15

#define HUM_MAX 100
#define HUM_MIN 50


class ValidationError : public std::exception  {
private:
    std::string _error;
public:
    ValidationError(std::string error);
    char const* what();
};


namespace Validation {
    void ssid(std::string ssid);
    void password(std::string ssid);
    void temp(int temp);
    void hum(int hum);    
}
