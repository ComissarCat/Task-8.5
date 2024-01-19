#include <iostream>
#include <vector>

using namespace std;

class Passport
{
private:
    string FIO;
    int serial;
    int number;
    string authority;
    int authority_number;
    string address;
public:
    Passport()
    {
        set_FIO("Иванов Иван Иванович");
        set_serial(1488);
        set_number(228228);
        set_authority("ГУ МВД по г. Путинбургу");
        set_authority_number(228228);
        set_address("г. Путинбург, ул. им. Путина, д. 1488, кв. 228");
    }
    friend ostream& operator<<(ostream& out, Passport& passport)
    {
        out << "ФИО: " << passport.FIO << endl;
        out << "Серия, номер: " << passport.serial << " " << passport.number << endl;
        out << "Выдан " << passport.authority << ", код подразделения " << passport.authority_number / 1000 << "-" << passport.authority_number % 1000 << endl;
        out << "Адрес регистрации: " << passport.address;
        return out;
    }
    void set_FIO(string FIO) { this->FIO = FIO; }
    void set_serial(int serial) { this->serial = serial; }
    void set_number(int number) { this->number = number; }
    void set_authority(string authority) { this->authority = authority; }
    void set_authority_number(int authority_number) { this->authority_number = authority_number; }
    void set_address(string address) { this->address = address; }
    string get_FIO() { return FIO; }
    int get_serial() { return serial; }
    int get_number() { return number; }
    string get_authority() { return authority; }
    int get_authority_number() { return authority_number; }
    string get_address() { return address; }
};

class Foreign_passport : public Passport
{
private:
    vector<string> visas;
public:
    Foreign_passport()
    {
        set_FIO("Иванов Иван Иванович");
        set_serial(42);
        set_number(1488228);
        set_authority("ФМС");
        set_authority_number(42228);
        visas.push_back("Узбекистан");
        visas.push_back("Казахстан");
    }
    void set_visas(vector<string> visas) { this->visas = visas; }
    vector<string> get_visas() { return visas; }
    friend ostream& operator<<(ostream& out, Foreign_passport& passport)
    {
        out << "ФИО: " << passport.get_FIO() << endl;
        out << "Серия, номер: " << passport.get_serial() << " " << passport.get_number() << endl;
        out << "Выдан " << passport.get_authority() << ", код подразделения " << passport.get_authority_number() << endl;
        out << "Визы: ";
        for (vector<string>::iterator visa = passport.visas.begin(); visa != passport.visas.end(); visa++)
        {
            out << *visa << "   ";
        }
        return out;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Passport passport;
    cout << passport << endl << endl;
    Foreign_passport foreign_passport;
    cout << foreign_passport << endl << endl;

    return 0;
}